/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: stream.c
 *
 */

/* Data streams */

#include "stream.h"
#include "stream.inl"
#include "lex.inl"
#include "heap.h"
#include "strings.h"
#include <osbs/osbs.h>
#include <osbs/bfile.h>
#include <osbs/bsocket.h>
#include <osbs/log.h>
#include <sewer/bmem.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

/* Stream state */
#define END_BIT 1
#define CORRUPTION_BIT 2
#define BROKEN_BIT 3
#define WRITE_ENDIAN_BIT 16
#define READ_ENDIAN_BIT 17
#define WRITE_UTF8_BIT 18
#define WRITE_UTF16_BIT 19
#define READ_UTF8_BIT 20
#define READ_UTF16_BIT 21

#define REV_OUT(state) BIT_TEST(state, WRITE_ENDIAN_BIT)
#define REV_IN(state) BIT_TEST(state, READ_ENDIAN_BIT)
#define IS_READ_OK(state) !(BIT_TEST(state, END_BIT) || BIT_TEST(state, CORRUPTION_BIT) || BIT_TEST(state, BROKEN_BIT))
#define IS_WRITE_OK(state) !(BIT_TEST(state, CORRUPTION_BIT) || BIT_TEST(state, BROKEN_BIT))
#define IS_EMPTY(str) ((str)[0] == '\0')
#define DISK_CACHE 2048
#define MEM_CACHE 2048
#define SOCK_WRITE_CACHE 512
#define STD_CACHE 2048
#define PIPE_CACHE 2048
Stream *kSTDIN = NULL;
Stream *kSTDOUT = NULL;
Stream *kSTDERR = NULL;
Stream *kDEVNULL = NULL;

typedef enum i_type_t
{
    i_ekTOMEMORY = 0,
    i_ekFROMMEMORY = 1,
    i_ekTOFILE = 2,
    i_ekFROMFILE = 3,
    i_ekSOCKET = 4,
    i_ekTOSTDOUT = 5,
    i_ekTOSTDERR = 6,
    i_ekFROMSTDIN = 7,

    i_ekDEVNULL = 0xFF
} type_t;

typedef struct i_file_t i_File;
typedef struct i_socket_t i_Socket;
typedef struct i_buffer_t i_Buffer;

struct i_buffer_t
{
    byte_t *data;
    uint32_t size;
    uint32_t woffset;
    uint32_t roffset;
    bool_t dynamic_alloc;
};

struct i_file_t
{
    File *file;
    ferror_t file_err;
};

struct i_socket_t
{
    Socket *socket;
    serror_t sock_err;
};

typedef union i_channel_t
{
    i_File file;
    i_Socket sock;
} i_Channel;

struct _stream_t
{
    type_t type;
    i_Buffer buffer1;
    i_Buffer buffer2;
    i_Buffer textline;
    i_Buffer restore;
    i_Buffer *output;
    i_Buffer *input;
    i_Channel channel;

    LexScn *lex;
    uint32_t col;
    uint32_t row;
    uint32_t state;
    uint64_t read_offset;
    uint64_t write_offset;
    bool_t escapes;
    bool_t spaces;
    bool_t newlines;
    bool_t comments;
};

/*---------------------------------------------------------------------------*/

typedef void (*i_FPtr_cache)(Stream *, const uint32_t size);
static void i_to_mem_fill_cache(Stream *, const uint32_t size);
static void i_from_mem_fill_cache(Stream *, const uint32_t size);
static void i_file_fill_cache(Stream *, const uint32_t size);
static void i_stdin_fill_cache(Stream *, const uint32_t size);

typedef void (*i_FPtr_write)(Stream *, const byte_t *data, const uint32_t size);
static void i_file_write(Stream *, const byte_t *data, const uint32_t size);
static void i_sock_write(Stream *, const byte_t *data, const uint32_t size);
static void i_stdout_write(Stream *, const byte_t *data, const uint32_t size);
static void i_stderr_write(Stream *, const byte_t *data, const uint32_t size);

static const i_FPtr_cache i_FUNC_FILL[] = {
    i_to_mem_fill_cache,   /* i_ekTOMEMORY */
    i_from_mem_fill_cache, /* i_ekFROMMEMORY */
    NULL,                  /* i_ekTOFILE */
    i_file_fill_cache,     /* i_ekFROMFILE */
    NULL,                  /* i_ekSOCKET */
    NULL,                  /* i_ekTOSTDOUT */
    NULL,                  /* i_ekTOSTDERR */
    i_stdin_fill_cache};   /* i_ekFROMSTDIN */

static const i_FPtr_write i_FUNC_WRITE[] = {
    NULL,           /* i_ekTOMEMORY */
    NULL,           /* i_ekFROMMEMORY */
    i_file_write,   /* i_ekTOFILE */
    NULL,           /* i_ekFROMFILE */
    i_sock_write,   /* i_ekSOCKET */
    i_stdout_write, /* i_ekTOSTDOUT */
    i_stderr_write, /* i_ekTOSTDERR */
    NULL};          /* i_ekFROMSTDIN */

/*---------------------------------------------------------------------------*/

static void i_init_buffer(i_Buffer *buffer, const uint32_t size, const char_t *name)
{
    cassert_no_null(buffer);
    buffer->dynamic_alloc = TRUE;
    buffer->size = size;
    if (size > 0)
        buffer->data = heap_malloc(size, name);
    else
        buffer->data = NULL;
    buffer->roffset = 0;
    buffer->woffset = 0;
}

/*---------------------------------------------------------------------------*/

static void i_init_const_buffer(i_Buffer *buffer, const byte_t *data, const uint32_t size)
{
    cassert_no_null(buffer);
    cassert(size > 0);
    buffer->dynamic_alloc = FALSE;
    buffer->size = size;
    buffer->data = (byte_t *)data;
    buffer->roffset = 0;
    buffer->woffset = 0;
}

/*---------------------------------------------------------------------------*/

static void i_remove_buffer(i_Buffer *buffer, const char_t *name)
{
    cassert_no_null(buffer);
    if (buffer->data != NULL)
    {
        if (buffer->dynamic_alloc == TRUE)
            heap_free(&buffer->data, buffer->size, name);
        buffer->size = 0;
        buffer->roffset = 0;
        buffer->woffset = 0;
    }
    else
    {
        cassert(buffer->size == 0);
        cassert(buffer->roffset == 0);
        cassert(buffer->woffset == 0);
    }
}

/*---------------------------------------------------------------------------*/

static Stream *i_create_stream(const type_t type)
{
    Stream *stm = heap_new0(Stream);
    stm->type = type;

    if (type != i_ekDEVNULL)
    {
        i_init_buffer(&stm->textline, 0, "StreamTextLine");
        i_init_buffer(&stm->restore, 0, "StreamRestore");

        stm->state = 0;
        if (type == i_ekSOCKET)
        {
            if (osbs_endian() != ekBIGEND)
            {
                BIT_SET(stm->state, WRITE_ENDIAN_BIT);
                BIT_SET(stm->state, READ_ENDIAN_BIT);
            }
        }
    }

    BIT_SET(stm->state, READ_UTF8_BIT);
    BIT_SET(stm->state, WRITE_UTF8_BIT);
    stm->col = 1;
    stm->row = 1;
    stm->escapes = FALSE;
    stm->spaces = FALSE;
    stm->newlines = FALSE;
    stm->comments = FALSE;
    return stm;
}

/*---------------------------------------------------------------------------*/

static void i_close_channel(i_Channel *channel, const type_t type)
{
    switch (type)
    {
    case i_ekTOFILE:
    case i_ekFROMFILE:
        bfile_close(&channel->file.file);
        break;

    case i_ekSOCKET:
        bsocket_close(&channel->sock.socket);
        break;

    case i_ekFROMMEMORY:
    case i_ekTOMEMORY:
    case i_ekTOSTDOUT:
    case i_ekTOSTDERR:
    case i_ekFROMSTDIN:
    case i_ekDEVNULL:
        break;

        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void stm_close(Stream **stm)
{
    cassert_no_null(stm);
    cassert_no_null(*stm);
    stm_flush(*stm);
    i_remove_buffer(&(*stm)->buffer1, "StreamBuffer1");
    i_remove_buffer(&(*stm)->buffer2, "StreamBuffer2");
    i_remove_buffer(&(*stm)->textline, "StreamTextLine");
    i_remove_buffer(&(*stm)->restore, "StreamRestore");
    i_close_channel(&(*stm)->channel, (*stm)->type);
    ptr_destopt(_lexscn_destroy, &(*stm)->lex, LexScn);
    heap_delete(stm, Stream);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_next_pow2(const uint32_t value)
{
    register uint32_t v = value;
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}

/*---------------------------------------------------------------------------*/

Stream *stm_from_block(const byte_t *data, const uint32_t size)
{
    Stream *stm = i_create_stream(i_ekFROMMEMORY);
    i_init_const_buffer(&stm->buffer1, data, size);
    stm->input = &stm->buffer1;
    stm->input->woffset = size;
    return stm;
}

/*---------------------------------------------------------------------------*/

Stream *stm_memory(const uint32_t size)
{
    Stream *stm = i_create_stream(i_ekTOMEMORY);
    uint32_t lsize = i_next_pow2(size);
    i_init_buffer(&stm->buffer1, lsize, "StreamBuffer1");
    stm->output = &stm->buffer1;
    stm->input = &stm->buffer1;
    return stm;
}

/*---------------------------------------------------------------------------*/

Stream *stm_from_file(const char_t *pathname, ferror_t *error)
{
    ferror_t lerror;
    File *file = bfile_open(pathname, ekREAD, &lerror);
    ptr_assign(error, lerror);
    if (file != NULL)
    {
        Stream *stm = i_create_stream(i_ekFROMFILE);
        i_init_buffer(&stm->buffer1, DISK_CACHE, "StreamBuffer1");
        stm->input = &stm->buffer1;
        stm->channel.file.file = file;
        stm->channel.file.file_err = ekFOK;
        return stm;
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

static Stream *i_to_file(File *file, const ferror_t lerror, ferror_t *error)
{
    ptr_assign(error, lerror);
    if (file != NULL)
    {
        Stream *stm = i_create_stream(i_ekTOFILE);
        i_init_buffer(&stm->buffer1, DISK_CACHE, "StreamBuffer1");
        stm->output = &stm->buffer1;
        stm->channel.file.file = file;
        stm->channel.file.file_err = ekFOK;
        return stm;
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

Stream *stm_to_file(const char_t *pathname, ferror_t *error)
{
    ferror_t lerror;
    File *file = bfile_create(pathname, &lerror);
    return i_to_file(file, lerror, error);
}

/*---------------------------------------------------------------------------*/

Stream *stm_append_file(const char_t *pathname, ferror_t *error)
{
    ferror_t lerror;
    File *file = bfile_open(pathname, ekAPPEND, &lerror);
    return i_to_file(file, lerror, error);
}

/*---------------------------------------------------------------------------*/

Stream *stm_socket(Socket *socket)
{
    if (socket != NULL)
    {
        Stream *stm = i_create_stream(i_ekSOCKET);
        i_init_buffer(&stm->buffer1, SOCK_WRITE_CACHE, "StreamBuffer1");
        i_init_buffer(&stm->buffer2, 0, "StreamBuffer2");
        stm->output = &stm->buffer1;
        stm->input = NULL;
        stm->channel.sock.socket = socket;
        stm->channel.sock.sock_err = ekSOK;
        return stm;
    }
    else
    {
        return NULL;
    }
}

/*---------------------------------------------------------------------------*/

static Stream *i_stdout(void)
{
    Stream *stm = i_create_stream(i_ekTOSTDOUT);
    i_init_buffer(&stm->buffer1, STD_CACHE, "StreamBuffer1");
    stm->output = &stm->buffer1;
    return stm;
}

/*---------------------------------------------------------------------------*/

static Stream *i_stderr(void)
{
    Stream *stm = i_create_stream(i_ekTOSTDERR);
    i_init_buffer(&stm->buffer1, STD_CACHE, "StreamBuffer1");
    stm->output = &stm->buffer1;
    return stm;
}

/*---------------------------------------------------------------------------*/

static Stream *i_stdin(void)
{
    Stream *stm = i_create_stream(i_ekFROMSTDIN);
    i_init_buffer(&stm->buffer1, STD_CACHE, "StreamBuffer1");
    stm->input = &stm->buffer1;
    return stm;
}

/*---------------------------------------------------------------------------*/

static Stream *i_devnull(void)
{
    return i_create_stream(i_ekDEVNULL);
}

/*---------------------------------------------------------------------------*/

endian_t stm_get_write_endian(const Stream *stm)
{
    endian_t endian = osbs_endian();
    cassert_no_null(stm);
    if (BIT_TEST(stm->state, WRITE_ENDIAN_BIT) == TRUE)
    {
        if (endian == ekBIGEND)
            endian = ekLITEND;
        else
            endian = ekBIGEND;
    }

    return endian;
}

/*---------------------------------------------------------------------------*/

endian_t stm_get_read_endian(const Stream *stm)
{
    endian_t endian = osbs_endian();
    cassert_no_null(stm);
    if (BIT_TEST(stm->state, READ_ENDIAN_BIT) == TRUE)
    {
        if (endian == ekBIGEND)
            endian = ekLITEND;
        else
            endian = ekBIGEND;
    }

    return endian;
}

/*---------------------------------------------------------------------------*/

void stm_set_write_endian(Stream *stm, const endian_t endian)
{
    cassert_no_null(stm);
    if (osbs_endian() == endian)
        BIT_CLEAR(stm->state, WRITE_ENDIAN_BIT);
    else
        BIT_SET(stm->state, WRITE_ENDIAN_BIT);
}

/*---------------------------------------------------------------------------*/

void stm_set_read_endian(Stream *stm, const endian_t endian)
{
    cassert_no_null(stm);
    if (osbs_endian() == endian)
        BIT_CLEAR(stm->state, READ_ENDIAN_BIT);
    else
        BIT_SET(stm->state, READ_ENDIAN_BIT);
}

/*---------------------------------------------------------------------------*/

unicode_t stm_get_write_utf(const Stream *stm)
{
    cassert_no_null(stm);
    if (BIT_TEST(stm->state, WRITE_UTF8_BIT) == TRUE)
        return ekUTF8;
    if (BIT_TEST(stm->state, WRITE_UTF16_BIT) == TRUE)
        return ekUTF16;
    return ekUTF32;
}

/*---------------------------------------------------------------------------*/

unicode_t stm_get_read_utf(const Stream *stm)
{
    cassert_no_null(stm);
    if (BIT_TEST(stm->state, READ_UTF8_BIT) == TRUE)
        return ekUTF8;
    if (BIT_TEST(stm->state, READ_UTF16_BIT) == TRUE)
        return ekUTF16;
    return ekUTF32;
}

/*---------------------------------------------------------------------------*/

void stm_set_write_utf(Stream *stm, const unicode_t format)
{
    cassert_no_null(stm);
    switch (format)
    {
    case ekUTF8:
        BIT_SET(stm->state, WRITE_UTF8_BIT);
        BIT_CLEAR(stm->state, WRITE_UTF16_BIT);
        break;
    case ekUTF16:
        BIT_CLEAR(stm->state, WRITE_UTF8_BIT);
        BIT_SET(stm->state, WRITE_UTF16_BIT);
        break;
    case ekUTF32:
        BIT_CLEAR(stm->state, WRITE_UTF8_BIT);
        BIT_CLEAR(stm->state, WRITE_UTF16_BIT);
        break;
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void stm_set_read_utf(Stream *stm, const unicode_t format)
{
    cassert_no_null(stm);
    switch (format)
    {
    case ekUTF8:
        BIT_SET(stm->state, READ_UTF8_BIT);
        BIT_CLEAR(stm->state, READ_UTF16_BIT);
        break;
    case ekUTF16:
        BIT_CLEAR(stm->state, READ_UTF8_BIT);
        BIT_SET(stm->state, READ_UTF16_BIT);
        break;
    case ekUTF32:
        BIT_CLEAR(stm->state, READ_UTF8_BIT);
        BIT_CLEAR(stm->state, READ_UTF16_BIT);
        break;
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

bool_t stm_is_memory(const Stream *stm)
{
    cassert_no_null(stm);
    return (bool_t)(stm->type == i_ekTOMEMORY || stm->type == i_ekFROMMEMORY);
}

/*---------------------------------------------------------------------------*/

uint64_t stm_bytes_written(const Stream *stm)
{
    cassert_no_null(stm);
    return stm->write_offset;
}

/*---------------------------------------------------------------------------*/

uint64_t stm_bytes_readed(const Stream *stm)
{
    cassert_no_null(stm);
    return stm->read_offset;
}

/*---------------------------------------------------------------------------*/

uint32_t stm_col(const Stream *stm)
{
    cassert_no_null(stm);
    return stm->col;
}

/*---------------------------------------------------------------------------*/

uint32_t stm_row(const Stream *stm)
{
    cassert_no_null(stm);
    return stm->row;
}

/*---------------------------------------------------------------------------*/

uint32_t stm_token_col(const Stream *stm)
{
    cassert_no_null(stm);
    return _lexscn_col(stm->lex);
}

/*---------------------------------------------------------------------------*/

uint32_t stm_token_row(const Stream *stm)
{
    cassert_no_null(stm);
    return _lexscn_row(stm->lex);
}

/*---------------------------------------------------------------------------*/

const char_t *stm_token_lexeme(const Stream *stm, uint32_t *size)
{
    cassert_no_null(stm);
    return _lexscn_lexeme(stm->lex, size);
}

/*---------------------------------------------------------------------------*/

void stm_token_escapes(Stream *stm, const bool_t active_escapes)
{
    cassert_no_null(stm);
    stm->escapes = active_escapes;
    if (stm->lex != NULL)
        _lexscn_escapes(stm->lex, stm->escapes);
}

/*---------------------------------------------------------------------------*/

void stm_token_spaces(Stream *stm, const bool_t active_spaces)
{
    cassert_no_null(stm);
    stm->spaces = active_spaces;
    if (stm->lex != NULL)
        _lexscn_spaces(stm->lex, stm->spaces);
}

/*---------------------------------------------------------------------------*/

void stm_token_comments(Stream *stm, const bool_t active_comments)
{
    cassert_no_null(stm);
    stm->comments = active_comments;
    if (stm->lex != NULL)
        _lexscn_comments(stm->lex, stm->comments);
}

/*---------------------------------------------------------------------------*/

sstate_t stm_state(const Stream *stm)
{
    cassert_no_null(stm);
    if (BIT_TEST(stm->state, CORRUPTION_BIT) == TRUE)
        return ekSTCORRUPT;
    if (BIT_TEST(stm->state, BROKEN_BIT) == TRUE)
        return ekSTBROKEN;
    if (BIT_TEST(stm->state, END_BIT) == TRUE)
        return ekSTEND;
    return ekSTOK;
}

/*---------------------------------------------------------------------------*/

ferror_t stm_file_err(const Stream *stm)
{
    cassert_no_null(stm);
    cassert(stm->type == i_ekTOFILE || stm->type == i_ekFROMFILE);
    return stm->channel.file.file_err;
}

/*---------------------------------------------------------------------------*/

serror_t stm_sock_err(const Stream *stm)
{
    cassert_no_null(stm);
    cassert(stm->type == i_ekSOCKET);
    return stm->channel.sock.sock_err;
}

/*---------------------------------------------------------------------------*/

void stm_corrupt(Stream *stm)
{
    cassert_no_null(stm);
    BIT_SET(stm->state, CORRUPTION_BIT);
}

/*---------------------------------------------------------------------------*/

String *stm_str(const Stream *stm)
{
    uint32_t s = stm_buffer_size(stm);
    const byte_t *b = stm_buffer(stm);
    return str_cn((const char_t *)b, s);
}

/*---------------------------------------------------------------------------*/

const byte_t *stm_buffer(const Stream *stm)
{
    cassert_no_null(stm);
    cassert(stm->type == i_ekTOMEMORY || stm->type == i_ekFROMMEMORY);
    cassert(stm->buffer1.woffset >= stm->buffer1.roffset);
    if (stm->buffer1.woffset > stm->buffer1.roffset)
        return stm->buffer1.data + stm->buffer1.roffset;
    else
        return (const byte_t *)"";
}

/*---------------------------------------------------------------------------*/

uint32_t stm_buffer_size(const Stream *stm)
{
    cassert_no_null(stm);
    cassert(stm->type == i_ekTOMEMORY);
    cassert(stm->buffer1.woffset >= stm->buffer1.roffset);
    return stm->buffer1.woffset - stm->buffer1.roffset;
}

/*---------------------------------------------------------------------------*/

static void i_file_write(Stream *stm, const byte_t *data, const uint32_t size)
{
    uint32_t num_written = 0;
    cassert_no_null(stm);
    cassert(stm->type == i_ekTOFILE);
    if (bfile_write(stm->channel.file.file, data, size, &num_written, &stm->channel.file.file_err) == TRUE)
    {
        if ((uint32_t)num_written != size)
            BIT_SET(stm->state, BROKEN_BIT);
    }
    else
    {
        BIT_SET(stm->state, BROKEN_BIT);
    }
}

/*---------------------------------------------------------------------------*/

static void i_sock_write(Stream *stm, const byte_t *data, const uint32_t size)
{
    uint32_t num_written = 0;
    cassert_no_null(stm);
    cassert(stm->type == i_ekSOCKET);
    if (bsocket_write(stm->channel.sock.socket, data, size, &num_written, &stm->channel.sock.sock_err) == TRUE)
    {
        if ((uint32_t)num_written != size)
            BIT_SET(stm->state, BROKEN_BIT);
    }
    else
    {
        BIT_SET(stm->state, BROKEN_BIT);
    }
}

/*---------------------------------------------------------------------------*/

static void i_stdout_write(Stream *stm, const byte_t *data, const uint32_t size)
{
    uint32_t num_written = 0;
    cassert_no_null(stm);
    cassert_unref(stm->type == i_ekTOSTDOUT, stm);
    if (bstd_write(data, size, &num_written) == TRUE)
    {
        if (num_written != size)
            BIT_SET(stm->state, BROKEN_BIT);
    }
    else
    {
        BIT_SET(stm->state, BROKEN_BIT);
    }
}

/*---------------------------------------------------------------------------*/

static void i_stderr_write(Stream *stm, const byte_t *data, const uint32_t size)
{
    uint32_t num_written = 0;
    cassert_no_null(stm);
    cassert_unref(stm->type == i_ekTOSTDERR, stm);
    if (bstd_ewrite(data, size, &num_written) == TRUE)
    {
        if (num_written != size)
            BIT_SET(stm->state, BROKEN_BIT);
    }
    else
    {
        BIT_SET(stm->state, BROKEN_BIT);
    }
}

/*---------------------------------------------------------------------------*/

static void i_grow_buffer(i_Buffer *output, const uint32_t size, const uint32_t grow_size, const char_t *memname)
{
    register uint32_t current_datasize, reqsize;
    cassert_no_null(output);
    cassert(size > 0);
    cassert(output->woffset + size > output->size);

    current_datasize = output->woffset - output->roffset;
    reqsize = current_datasize + size;

    /* Not enough buffer size */
    if (reqsize > output->size)
    {
        register uint32_t new_size = output->size > 0 ? 2 * output->size : grow_size;
        byte_t *data = NULL;

        while (reqsize > new_size)
            new_size *= 2;

        data = heap_malloc(new_size, memname);

        /* Exists non-readed data in buffer, we have to preserve */
        if (output->data != NULL)
        {
            const byte_t *sdata = output->data + output->roffset;
            byte_t *ddata = data;
            register uint32_t i;
            for (i = 0; i < current_datasize; ++i, ++sdata, ++ddata)
                *ddata = *sdata;

            heap_free(&output->data, output->size, memname);
        }
        else
        {
            cassert(output->size == 0);
            cassert(current_datasize == 0);
        }

        output->data = data;
        output->size = new_size;
    }
    /* We can reuse the existing buffer move data in. */
    else
    {
        const byte_t *sdata = output->data + output->roffset;
        byte_t *ddata = output->data;
        register uint32_t i;
        for (i = 0; i < current_datasize; ++i, ++sdata, ++ddata)
            *ddata = *sdata;
    }

    output->roffset = 0;
    output->woffset = current_datasize;
}

/*---------------------------------------------------------------------------*/

static void i_need_buffer_space(Stream *stm, i_Buffer *output, const uint32_t size)
{
    cassert_no_null(stm);
    cassert(output->woffset + size > output->size);
    if (stm->type == i_ekTOMEMORY)
    {
        i_grow_buffer(output, size, MEM_CACHE, "StreamBuffer1");
    }
    else if (stm->type == i_ekSOCKET)
    {
        /* Sockets all allways write cache-flushed */
        cassert(output->woffset == 0);
    }
    else
    {
        /* For channel buffers --> flush to free space in cache */
        cassert_no_nullf(i_FUNC_WRITE[stm->type]);
        cassert(output->roffset == 0);
        i_FUNC_WRITE[stm->type](stm, output->data, output->woffset);
        output->woffset = 0;
    }
}

/*---------------------------------------------------------------------------*/

static void i_write(Stream *stm, const byte_t *data, const uint32_t size, const bool_t reverse)
{
    register i_Buffer *output;
    cassert_no_null(stm);
    cassert(size > 0);

    if (!IS_WRITE_OK(stm->state))
        return;

    output = stm->output;
    if (output != NULL)
    {
        /* No space in buffer */
        if (output->woffset + size > output->size)
            i_need_buffer_space(stm, stm->output, size);

        /* No space in buffer after request
        So big for cache --> Direct writting to channel */
        if (output->woffset + size > output->size)
        {
            cassert(reverse == FALSE); /* So big for endianness */
            cassert_no_nullf(i_FUNC_WRITE[stm->type]);
            cassert(output->roffset == 0);
            cassert(output->woffset == 0); /* Has been flushed */
            i_FUNC_WRITE[stm->type](stm, data, size);
        }
        /* Write in cache */
        else
        {
            byte_t *dest = output->data + output->woffset;
            bmem_copy(dest, data, size);
            output->woffset += size;
            if (reverse == TRUE)
            {
                if (size == 2)
                {
                    bmem_rev2(dest);
                }
                else if (size == 4)
                {
                    bmem_rev4(dest);
                }
                else if (size == 8)
                {
                    bmem_rev8(dest);
                }
                else
                {
                    /* Ups! reverse no endianness?? */
                    cassert(size <= 8);
                    bmem_rev(dest, size);
                }
            }

            /* For sockets --> flush cache allways */
            if (stm->type == i_ekSOCKET)
            {
                cassert_no_nullf(i_FUNC_WRITE[stm->type]);
                cassert(output->roffset == 0);
                i_FUNC_WRITE[stm->type](stm, output->data, output->woffset);
                output->woffset = 0;
            }
        }

        stm->write_offset += size;
        BIT_CLEAR(stm->state, END_BIT);
    }
    else
    {
        log_printf("Trying to write in a read-only stream.");
        BIT_SET(stm->state, CORRUPTION_BIT);
    }
}

/*---------------------------------------------------------------------------*/

void stm_write(Stream *stm, const byte_t *data, const uint32_t size)
{
    cassert_no_null(stm);
    if (stm->type != i_ekDEVNULL)
    {
        if (size > 0)
            i_write(stm, data, size, FALSE);
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_utf16(Stream *stm, const char_t *str)
{
    uint32_t codepoint = unicode_to_u32(str, ekUTF8);
    cassert_no_null(stm);
    while (IS_WRITE_OK(stm->state) && codepoint != 0)
    {
        char_t utf16[4];
        uint32_t bytes;
        bytes = unicode_to_char(codepoint, utf16, ekUTF16);
        if (bytes == 2)
        {
            i_write(stm, (const byte_t *)utf16, 2, BIT_TEST(stm->state, WRITE_ENDIAN_BIT));
        }
        else
        {
            cassert(bytes == 4);
            i_write(stm, (const byte_t *)utf16, 2, BIT_TEST(stm->state, WRITE_ENDIAN_BIT));
            i_write(stm, (const byte_t *)utf16 + 2, 2, BIT_TEST(stm->state, WRITE_ENDIAN_BIT));
        }

        str = unicode_next(str, ekUTF8);
        codepoint = unicode_to_u32(str, ekUTF8);
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_utf32(Stream *stm, const char_t *str)
{
    uint32_t codepoint = unicode_to_u32(str, ekUTF8);
    cassert_no_null(stm);
    while (IS_WRITE_OK(stm->state) && codepoint != 0)
    {
        i_write(stm, (const byte_t *)&codepoint, 4, BIT_TEST(stm->state, WRITE_ENDIAN_BIT));
        str = unicode_next(str, ekUTF8);
        codepoint = unicode_to_u32(str, ekUTF8);
    }
}

/*---------------------------------------------------------------------------*/

void stm_write_char(Stream *stm, const uint32_t codepoint)
{
    cassert_no_null(stm);
    if (stm->type == i_ekDEVNULL)
        return;

    if (codepoint != 0)
    {
        char_t str[6];
        uint32_t n;
        cassert_no_null(stm);
        if (BIT_TEST(stm->state, WRITE_UTF8_BIT) == TRUE)
            n = unicode_to_char(codepoint, str, ekUTF8);
        else if (BIT_TEST(stm->state, WRITE_UTF16_BIT) == TRUE)
            n = unicode_to_char(codepoint, str, ekUTF16);
        else
            n = unicode_to_char(codepoint, str, ekUTF32);
        str[n] = '\0';
        stm_writef(stm, str);
    }
    else
    {
        if (BIT_TEST(stm->state, WRITE_UTF8_BIT) == TRUE)
            stm_write_u8(stm, 0);
        else if (BIT_TEST(stm->state, WRITE_UTF16_BIT) == TRUE)
            stm_write_u16(stm, 0);
        else
            stm_write_u32(stm, 0);
    }
}

/*---------------------------------------------------------------------------*/

uint32_t stm_printf(Stream *stm, const char_t *format, ...)
{
    cassert_no_null(stm);
    if (stm->type == i_ekDEVNULL)
        return 0;

    if (stm->output != NULL)
    {
        char_t *data_alloc = NULL;
        char_t *data = NULL;
        uint32_t length;

        cassert_no_null(format);

        /* Memory requeriments */
        {
            va_list args;
            va_start(args, format);
            length = 1 + bstd_vsprintf(NULL, 0, format, args);
            va_end(args);
        }

        /* Nothing to write */
        if (length == 1)
            return 0;

        /* Temporal buffer */
        if (length < stm->textline.size)
        {
            data = (char_t *)stm->textline.data;
        }
        else
        {
            data_alloc = (char_t *)heap_malloc(length, "StreamPrintf");
            data = data_alloc;
        }

        /* Printf */
        {
            register uint32_t clength;
            va_list args;
            va_start(args, format);
            clength = bstd_vsprintf(data, length, format, args);
            va_end(args);
            cassert_unref(clength + 1 == length, clength);
        }

        cassert(data[length - 1] == '\0');

        if (BIT_TEST(stm->state, WRITE_UTF8_BIT) == TRUE)
            i_write(stm, (const byte_t *)data, length - 1, FALSE);
        else if (BIT_TEST(stm->state, WRITE_UTF16_BIT) == TRUE)
            i_write_utf16(stm, data);
        else
            i_write_utf32(stm, data);

        if (data_alloc != NULL)
            heap_free((byte_t **)&data_alloc, length, "StreamPrintf");

        return length - 1;
    }
    else
    {
        log_printf("Trying to write in a read-only stream.");
        BIT_SET(stm->state, CORRUPTION_BIT);
        return 0;
    }
}

/*---------------------------------------------------------------------------*/

uint32_t stm_writef(Stream *stm, const char_t *str)
{
    cassert_no_null(stm);
    if (stm->type == i_ekDEVNULL)
        return 0;

    if (stm->output != NULL)
    {
        uint32_t size = str_len_c(str);
        if (size > 0)
        {
            if (BIT_TEST(stm->state, WRITE_UTF8_BIT) == TRUE)
                i_write(stm, (const byte_t *)str, size, FALSE);
            else if (BIT_TEST(stm->state, WRITE_UTF16_BIT) == TRUE)
                i_write_utf16(stm, str);
            else
                i_write_utf32(stm, str);
        }

        return size;
    }
    else
    {
        log_printf("Trying to write in a read-only stream.");
        BIT_SET(stm->state, CORRUPTION_BIT);
        return 0;
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_binary(Stream *stm, const byte_t *value, const uint32_t size)
{
    cassert_no_null(stm);
    if (stm->type == i_ekDEVNULL)
        return;

    if (stm->output != NULL)
    {
        i_write(stm, value, size, (bool_t)(size > 1 && BIT_TEST(stm->state, WRITE_ENDIAN_BIT)));
    }
    else
    {
        log_printf("Trying to write in a read-only stream.");
        BIT_SET(stm->state, CORRUPTION_BIT);
    }
}

/*---------------------------------------------------------------------------*/

void stm_write_bool(Stream *stm, const bool_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_i8(Stream *stm, const int8_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_i16(Stream *stm, const int16_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_i32(Stream *stm, const int32_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_i64(Stream *stm, const int64_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_u8(Stream *stm, const uint8_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_u16(Stream *stm, const uint16_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_u32(Stream *stm, const uint32_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_u64(Stream *stm, const uint64_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_r32(Stream *stm, const real32_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

void stm_write_r64(Stream *stm, const real64_t value)
{
    i_write_binary(stm, (const byte_t *)&value, sizeof(value));
}

/*---------------------------------------------------------------------------*/

static void i_from_mem_fill_cache(Stream *stm, const uint32_t size)
{
    cassert_no_null(stm);
    cassert(stm->type == i_ekFROMMEMORY);
    cassert_no_null(stm->input);
    cassert(stm->output == NULL);
    cassert(stm->input->roffset == stm->input->woffset);
    unref(size);
    BIT_SET(stm->state, END_BIT);
}

/*---------------------------------------------------------------------------*/

static void i_to_mem_fill_cache(Stream *stm, const uint32_t size)
{
    cassert_no_null(stm);
    cassert(stm->type == i_ekTOMEMORY);
    cassert_no_null(stm->input);
    cassert_no_null(stm->output);
    cassert(stm->input->roffset == stm->output->woffset);
    unref(size);
    BIT_SET(stm->state, END_BIT);
}

/*---------------------------------------------------------------------------*/

static void i_file_fill_cache(Stream *stm, const uint32_t size)
{
    i_Buffer *input;
    uint32_t nreaded;
    cassert_no_null(stm);
    cassert(stm->type == i_ekFROMFILE);
    input = stm->input;
    cassert_no_null(input);
    cassert(input->woffset == input->roffset);
    unref(size);
    if (bfile_read(stm->channel.file.file, input->data, input->size, &nreaded, &stm->channel.file.file_err) == TRUE)
    {
        input->woffset = nreaded;
        input->roffset = 0;
        if (nreaded == 0)
            BIT_SET(stm->state, END_BIT);
    }
    else
    {
        input->woffset = 0;
        input->roffset = 0;
        BIT_SET(stm->state, BROKEN_BIT);
    }
}

/*---------------------------------------------------------------------------*/

static void i_read_from_socket(Stream *stm, byte_t *data, const uint32_t size)
{
    uint32_t nreaded;
    cassert_no_null(stm);
    cassert(stm->type == i_ekSOCKET);
    cassert(stm->input == NULL);

    if (bsocket_read(stm->channel.sock.socket, data, size, &nreaded, &stm->channel.sock.sock_err) == TRUE)
    {
        if (nreaded == 0)
            BIT_SET(stm->state, END_BIT);
    }
    else
    {
        BIT_SET(stm->state, BROKEN_BIT);
    }
}

/*---------------------------------------------------------------------------*/

static void i_stdin_fill_cache(Stream *stm, const uint32_t size)
{
    i_Buffer *input;
    uint32_t nreaded;
    register uint32_t rsize = size;
    cassert_no_null(stm);
    cassert(stm->type == i_ekFROMSTDIN);
    input = stm->input;
    cassert_no_null(input);
    cassert(input->woffset == input->roffset);
    if (input->size < rsize)
        rsize = input->size;

    if (bstd_read(input->data, rsize, &nreaded) == TRUE)
    {
        input->woffset = (uint32_t)nreaded;
        input->roffset = 0;
        if (nreaded == 0)
            BIT_SET(stm->state, END_BIT);
    }
    else
    {
        input->woffset = 0;
        input->roffset = 0;
        BIT_SET(stm->state, BROKEN_BIT);
    }
}

/*---------------------------------------------------------------------------*/

static uint32_t i_read(Stream *stm, byte_t *data, const uint32_t size, const bool_t reverse)
{
    uint32_t readed = 0;
    cassert_no_null(stm);
    cassert(stm->type != i_ekDEVNULL);

    if (!IS_READ_OK(stm->state))
        return 0;

    /* Read first from restore cache */
    if (stm->restore.woffset > stm->restore.roffset)
    {
        register uint32_t read_restore = stm->restore.woffset - stm->restore.roffset;
        register byte_t *src = stm->restore.data + stm->restore.roffset;
        if (read_restore > size)
            read_restore = size;

        /* data = NULL for jump */
        if (data != NULL)
            bmem_copy(data, src, read_restore);

        readed += read_restore;
        stm->restore.roffset += read_restore;
    }

    /* Sockets doesn't use cache */
    if (stm->type == i_ekSOCKET)
    {
        register uint32_t remain = size - readed;

        if (data != NULL)
        {
            i_read_from_socket(stm, data + readed, remain);
        }
        /* Jump socket data */
        else
        {
            byte_t waste[512];
            uint32_t i, n = remain / sizeof32(waste);
            uint32_t last = remain % sizeof32(waste);

            for (i = 0; i < n; ++i)
                i_read_from_socket(stm, waste, sizeof(waste));

            if (last > 0)
                i_read_from_socket(stm, waste, last);
        }

        readed += remain;
    }
    else
    {
        i_Buffer *input = stm->input;
        if (input == NULL)
        {
            log_printf("Trying to read in a write-only stream.");
            BIT_SET(stm->state, CORRUPTION_BIT);
            return 0;
        }

        /* Fill data buffer */
        /* readed = 0 -- readed already from 'restore' buffer */
        for (; readed < size;)
        {
            register uint32_t remain = size - readed;
            uint32_t available = input->woffset - input->roffset;

            /* Fill the read cache */
            if (available == 0)
            {
                cassert_no_nullf(i_FUNC_FILL[stm->type]);
                i_FUNC_FILL[stm->type](stm, remain);
                available = input->woffset - input->roffset;
                if (available == 0)
                    break;
            }

            if (remain < available)
                available = remain;

            /* data = NULL for jump */
            if (data != NULL)
                bmem_copy(data + readed, input->data + input->roffset, available);

            input->roffset += available;
            readed += available;
        }
    }

    if (data != NULL && reverse == TRUE)
    {
        if (size == 2)
        {
            bmem_rev2(data);
        }
        else if (size == 4)
        {
            bmem_rev4(data);
        }
        else if (size == 8)
        {
            bmem_rev8(data);
        }
        else
        {
            cassert(size <= 8);
            bmem_rev(data, size);
        }
    }

    stm->read_offset += readed;
    return readed;
}

/*---------------------------------------------------------------------------*/

uint32_t stm_read(Stream *stm, byte_t *data, const uint32_t size)
{
    cassert_no_null(stm);
    return i_read(stm, data, size, FALSE);
}

/*---------------------------------------------------------------------------*/

void stm_skip(Stream *stm, const uint32_t size)
{
    i_read(stm, NULL, size, FALSE);
}

/*---------------------------------------------------------------------------*/

void stm_skip_bom(Stream *stm)
{
    uint32_t pcol = stm_col(stm);
    uint32_t prow = stm_row(stm);
    uint32_t code = stm_read_char(stm);

    while (code == 0xFEFF)
    {
        pcol = stm_col(stm);
        prow = stm_row(stm);
        code = stm_read_char(stm);
    }

    {
        char_t data[5];
        uint32_t size;
        size = unicode_to_char(code, data, ekUTF8);
        cassert(size >= 1 && size <= 4);
        _stm_restore(stm, (const byte_t *)data, size);
        _stm_restore_col(stm, pcol);
        _stm_restore_row(stm, prow);
    }
}

/*---------------------------------------------------------------------------*/

void stm_skip_token(Stream *stm, const ltoken_t token)
{
    ltoken_t tok = stm_read_token(stm);
    if (tok != token)
        stm_corrupt(stm);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_read_utf8(Stream *stm)
{
    byte_t value0 = 0;

    i_read(stm, &value0, 1, FALSE);

    /* One byte UTF-8 0xxx xxxx */
    if (__TRUE_EXPECTED((value0 & 0x7F) == value0))
    {
        cassert((uint32_t)value0 <= 0x007F);
        return (uint32_t)value0;
    }

    /* Two bytes UTF-8 110x xxxx 10xx xxxx */
    else if (__TRUE_EXPECTED((value0 & 0xE0) == 0xC0))
    {
        byte_t value1 = 0;
        uint32_t code;
        i_read(stm, &value1, 1, FALSE);
        code = ((uint32_t)(value0 & 0x1F) << 6) | (uint32_t)(value1 & 0x3F);
        cassert(code >= 0x0080 && code <= 0x07FF);
        return code;
    }

    /* Three bytes UTF-8 1110 xxxx 10xx xxxx 10xx xxxx */
    else if (__TRUE_EXPECTED((value0 & 0xF0) == 0xE0))
    {
        byte_t value1[2] = {0, 0};
        uint32_t code;
        i_read(stm, value1, 2, FALSE);
        code = ((uint32_t)(value0 & 0x0F) << 12) | ((uint32_t)(value1[0] & 0x3F) << 6) | (uint32_t)(value1[1] & 0x3F);
        cassert(code >= 0x0800 && code <= 0xFFFF);
        return code;
    }

    /* Four bytes UTF-8 1111 0xxx 10xx xxxx 10xx xxxx 10xx xxxx */
    else if (__TRUE_EXPECTED((value0 & 0xF8) == 0xF0))
    {
        byte_t value1[3] = {0, 0, 0};
        uint32_t code;
        i_read(stm, value1, 3, FALSE);
        code = ((uint32_t)(value0 & 0x07) << 18) | ((uint32_t)(value1[0] & 0x3F) << 12) | ((uint32_t)(value1[1] & 0x3F) << 6) | (uint32_t)(value1[2] & 0x3F);
        cassert(code >= 0x010000 && code <= 0x1FFFFF);
        return code;
    }

    /* Unknown codepoint */
    else
    {
        return UINT32_MAX;
    }
}

/*---------------------------------------------------------------------------*/

static uint32_t i_read_utf16(Stream *stm)
{
    uint16_t value0 = 0;
    i_read(stm, (byte_t *)&value0, 2, BIT_TEST(stm->state, READ_ENDIAN_BIT));

    /* Subrogate pairs */
    if (value0 >= 0xD800 && value0 <= 0xDBFF)
    {
        uint16_t value1 = 0;
        i_read(stm, (byte_t *)&value1, 2, BIT_TEST(stm->state, READ_ENDIAN_BIT));
        cassert(value1 >= 0xDC00 && value1 <= 0xDFFF);
        return ((uint32_t)value0 << 10) + (uint32_t)value1 - 0x35FDC00;
    }
    else
    {
        return (uint32_t)value0;
    }
}

/*---------------------------------------------------------------------------*/

static void i_char_to_cache(Stream *stm, const uint32_t code)
{
    i_Buffer *line;
    cassert_no_null(stm);
    line = &stm->textline;
    if (line->roffset + 4 > line->size)
    {
        if (line->size == 0)
        {
            line->data = heap_malloc(256, "StreamTextLine");
            line->size = 256;
        }
        else
        {
            line->data = heap_realloc(line->data, line->size, line->size * 2, "StreamTextLine");
            line->size *= 2;
        }
    }

    line->roffset += unicode_to_char(code, (char_t *)(line->data + line->roffset), ekUTF8);
}

/*---------------------------------------------------------------------------*/

uint32_t stm_read_char(Stream *stm)
{
    uint32_t code = 0;
    cassert_no_null(stm);
    if (!IS_READ_OK(stm->state))
        return 0;

    if (BIT_TEST(stm->state, READ_UTF8_BIT) == TRUE)
        code = i_read_utf8(stm);
    else if (BIT_TEST(stm->state, READ_UTF16_BIT) == TRUE)
        code = i_read_utf16(stm);
    else
        i_read(stm, (byte_t *)&code, 4, BIT_TEST(stm->state, READ_ENDIAN_BIT));

    if (unicode_valid(code) == TRUE)
    {
        if (code == '\n')
        {
            stm->row += 1;
            stm->col = 1;
        }
        else
        {
            stm->col += 1;
        }

        return code;
    }
    else
    {
        /* BIT_SET(stm->state, CORRUPTION_BIT); */
        return UINT32_MAX;
    }
}

/*---------------------------------------------------------------------------*/

const char_t *stm_read_chars(Stream *stm, const uint32_t n)
{
    i_Buffer *line;
    register uint32_t i;
    cassert_no_null(stm);
    if (!IS_READ_OK(stm->state))
        return "";

    line = &stm->textline;
    line->roffset = 0;
    for (i = 0; i < n; ++i)
    {
        uint32_t code = stm_read_char(stm);
        i_char_to_cache(stm, code);
    }

    i_char_to_cache(stm, 0);
    return (const char_t *)line->data;
}

/*---------------------------------------------------------------------------*/

const char_t *stm_read_line(Stream *stm)
{
    i_Buffer *line;
    uint32_t code = 0;
    cassert_no_null(stm);
    if (!IS_READ_OK(stm->state))
        return NULL;

    line = &stm->textline;
    line->roffset = 0;
    code = stm_read_char(stm);
    while (code != '\n' && code != 0)
    {
        if (unicode_valid(code))
            i_char_to_cache(stm, code);
        code = stm_read_char(stm);
    }

    /* Avoid '\r' */
    if (line->roffset > 0)
    {
        if (line->data[line->roffset - 1] == '\r')
            line->roffset -= 1;
    }

    i_char_to_cache(stm, 0);

    if (!IS_READ_OK(stm->state))
    {
        if (line->roffset == 1)
            return NULL;
    }

    return (const char_t *)line->data;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_skip_spaces(Stream *stm)
{
    uint32_t code = 0;
    cassert_no_null(stm);
    code = stm_read_char(stm);
    while (unicode_isspace(code) == TRUE)
        code = stm_read_char(stm);
    return code;
}

/*---------------------------------------------------------------------------*/

const char_t *stm_read_trim(Stream *stm)
{
    i_Buffer *line;
    uint32_t code = 0;
    cassert_no_null(stm);
    if (!IS_READ_OK(stm->state))
        return "";

    line = &stm->textline;
    line->roffset = 0;
    code = i_skip_spaces(stm);
    cassert(unicode_isspace(code) == FALSE);
    while (unicode_isspace(code) == FALSE && code != 0)
    {
        i_char_to_cache(stm, code);
        code = stm_read_char(stm);
    }

    i_char_to_cache(stm, 0);
    return (const char_t *)line->data;
}

/*---------------------------------------------------------------------------*/

ltoken_t stm_read_token(Stream *stm)
{
    cassert_no_null(stm);
    if (stm->lex == NULL)
    {
        stm->lex = _lexscn_create();
        _lexscn_escapes(stm->lex, stm->escapes);
        _lexscn_spaces(stm->lex, stm->spaces);
        _lexscn_comments(stm->lex, stm->comments);
    }

    return _lexscn_token(stm->lex, stm);
}

/*---------------------------------------------------------------------------*/

static int64_t i_read_i64(Stream *stm)
{
    bool_t minus = FALSE;
    ltoken_t tok = stm_read_token(stm);

    if (tok == ekTMINUS)
    {
        minus = TRUE;
        tok = stm_read_token(stm);
    }

    if (tok == ekTINTEGER)
    {
        int64_t number = str_to_i64(stm_token_lexeme(stm, NULL), 10, NULL);

        if (minus == TRUE)
            return -number;
        else
            return number;
    }

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

static uint64_t i_read_u64(Stream *stm)
{
    ltoken_t tok = stm_read_token(stm);

    if (tok == ekTINTEGER)
        return str_to_u64(stm_token_lexeme(stm, NULL), 10, NULL);

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

static real64_t i_read_r64(Stream *stm)
{
    bool_t minus = FALSE;
    ltoken_t tok = stm_read_token(stm);

    if (tok == ekTMINUS)
    {
        minus = TRUE;
        tok = stm_read_token(stm);
    }

    if (tok == ekTINTEGER || tok == ekTREAL)
    {
        real64_t number = str_to_r64(stm_token_lexeme(stm, NULL), NULL);

        if (minus == TRUE)
            return -number;
        else
            return number;
    }

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

int8_t stm_read_i8_tok(Stream *stm)
{
    int64_t v = i_read_i64(stm);
    if (v >= INT8_MIN && v <= INT8_MAX)
        return (int8_t)v;

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

int16_t stm_read_i16_tok(Stream *stm)
{
    int64_t v = i_read_i64(stm);
    if (v >= INT16_MIN && v <= INT16_MAX)
        return (int16_t)v;

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

int32_t stm_read_i32_tok(Stream *stm)
{
    int64_t v = i_read_i64(stm);
    if (v >= INT32_MIN && v <= INT32_MAX)
        return (int32_t)v;

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

int64_t stm_read_i64_tok(Stream *stm)
{
    return i_read_i64(stm);
}

/*---------------------------------------------------------------------------*/

uint8_t stm_read_u8_tok(Stream *stm)
{
    uint64_t v = i_read_u64(stm);
    if (v <= UINT8_MAX)
        return (uint8_t)v;

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

uint16_t stm_read_u16_tok(Stream *stm)
{
    uint64_t v = i_read_u64(stm);
    if (v <= UINT16_MAX)
        return (uint16_t)v;

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

uint32_t stm_read_u32_tok(Stream *stm)
{
    uint64_t v = i_read_u64(stm);
    if (v <= UINT32_MAX)
        return (uint32_t)v;

    stm_corrupt(stm);
    return 0;
}

/*---------------------------------------------------------------------------*/

uint64_t stm_read_u64_tok(Stream *stm)
{
    return i_read_u64(stm);
}

/*---------------------------------------------------------------------------*/

real32_t stm_read_r32_tok(Stream *stm)
{
    return (real32_t)i_read_r64(stm);
}

/*---------------------------------------------------------------------------*/

real64_t stm_read_r64_tok(Stream *stm)
{
    return i_read_r64(stm);
}

/*---------------------------------------------------------------------------*/

bool_t stm_read_bool(Stream *stm)
{
    bool_t v = FALSE;
    i_read(stm, (byte_t *)&v, sizeof(bool_t), FALSE);
    if (v != 0 && v != 1)
    {
        log_printf("Error reading boolean.");
        v = FALSE;
    }

    return v;
}

/*---------------------------------------------------------------------------*/

int8_t stm_read_i8(Stream *stm)
{
    int8_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(int8_t), FALSE);
    return v;
}

/*---------------------------------------------------------------------------*/

int16_t stm_read_i16(Stream *stm)
{
    int16_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(int16_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

int32_t stm_read_i32(Stream *stm)
{
    int32_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(int32_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

int64_t stm_read_i64(Stream *stm)
{
    int64_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(int64_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

uint8_t stm_read_u8(Stream *stm)
{
    uint8_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(uint8_t), FALSE);
    return v;
}

/*---------------------------------------------------------------------------*/

uint16_t stm_read_u16(Stream *stm)
{
    uint16_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(uint16_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

uint32_t stm_read_u32(Stream *stm)
{
    uint32_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(uint32_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

uint64_t stm_read_u64(Stream *stm)
{
    uint64_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(uint64_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

real32_t stm_read_r32(Stream *stm)
{
    real32_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(real32_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

real64_t stm_read_r64(Stream *stm)
{
    real64_t v = 0;
    i_read(stm, (byte_t *)&v, sizeof(real64_t), BIT_TEST(stm->state, READ_ENDIAN_BIT));
    return v;
}

/*---------------------------------------------------------------------------*/

void stm_flush(Stream *stm)
{
    cassert_no_null(stm);

    if (stm->type == i_ekDEVNULL)
        return;

    if (i_FUNC_WRITE[stm->type] != NULL)
    {
        i_Buffer *output = stm->output;
        cassert_no_null(output);
        cassert(output->roffset == 0);
        if (output->woffset > 0)
        {
            i_FUNC_WRITE[stm->type](stm, output->data, output->woffset);
            output->woffset = 0;
        }
    }
}

/*---------------------------------------------------------------------------*/

void stm_pipe(Stream *from, Stream *to, const uint32_t n)
{
    byte_t cache[PIPE_CACHE];
    uint32_t i = 0, ln, r;
    ln = n / PIPE_CACHE;
    r = n % PIPE_CACHE;

    cassert_no_null(from);
    cassert_no_null(to);

    for (i = 0; i < ln; ++i)
    {
        i_read(from, cache, PIPE_CACHE, FALSE);
        i_write(to, cache, PIPE_CACHE, FALSE);
    }

    if (r > 0)
    {
        i_read(from, cache, r, FALSE);
        i_write(to, cache, r, FALSE);
    }
}

/*---------------------------------------------------------------------------*/

void _stm_start(void)
{
    cassert(kSTDIN == NULL);
    cassert(kSTDOUT == NULL);
    cassert(kSTDERR == NULL);
    cassert(kDEVNULL == NULL);
    kSTDIN = i_stdin();
    kSTDOUT = i_stdout();
    kSTDERR = i_stderr();
    kDEVNULL = i_devnull();
}

/*---------------------------------------------------------------------------*/

void _stm_finish(void)
{
    stm_close(&kSTDIN);
    stm_close(&kSTDOUT);
    stm_close(&kSTDERR);
    stm_close(&kDEVNULL);
}

/*---------------------------------------------------------------------------*/

void _stm_restore(Stream *stm, const byte_t *data, const uint32_t size)
{
    byte_t *dest = NULL;
    cassert_no_null(stm);

    /* No space in buffer */
    if (stm->restore.woffset + size > stm->restore.size)
        i_grow_buffer(&stm->restore, size, 64, "StreamRestore");

    dest = stm->restore.data + stm->restore.woffset;
    bmem_copy(dest, data, size);
    stm->restore.woffset += size;
}

/*---------------------------------------------------------------------------*/

void _stm_restore_col(Stream *stm, const uint32_t col)
{
    cassert_no_null(stm);
    stm->col = col;
}

/*---------------------------------------------------------------------------*/

void _stm_restore_row(Stream *stm, const uint32_t row)
{
    cassert_no_null(stm);
    stm->row = row;
}
