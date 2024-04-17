/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: stream.h
 * https://nappgui.com/en/core/stream.html
 *
 */

/* Data streams */

#include "core.hxx"

__EXTERN_C

_core_api Stream *stm_from_block(const byte_t *data, const uint32_t size);

_core_api Stream *stm_memory(const uint32_t size);

_core_api Stream *stm_from_file(const char_t *pathname, ferror_t *error);

_core_api Stream *stm_to_file(const char_t *pathname, ferror_t *error);

_core_api Stream *stm_append_file(const char_t *pathname, ferror_t *error);

_core_api Stream *stm_socket(Socket *socket);

_core_api void stm_close(Stream **stm);

_core_api endian_t stm_get_write_endian(const Stream *stm);

_core_api endian_t stm_get_read_endian(const Stream *stm);

_core_api void stm_set_write_endian(Stream *stm, const endian_t endian);

_core_api void stm_set_read_endian(Stream *stm, const endian_t endian);

_core_api unicode_t stm_get_write_utf(const Stream *stm);

_core_api unicode_t stm_get_read_utf(const Stream *stm);

_core_api void stm_set_write_utf(Stream *stm, const unicode_t format);

_core_api void stm_set_read_utf(Stream *stm, const unicode_t format);

_core_api bool_t stm_is_memory(const Stream *stm);

_core_api uint64_t stm_bytes_written(const Stream *stm);

_core_api uint64_t stm_bytes_readed(const Stream *stm);

_core_api uint32_t stm_col(const Stream *stm);

_core_api uint32_t stm_row(const Stream *stm);

_core_api uint32_t stm_token_col(const Stream *stm);

_core_api uint32_t stm_token_row(const Stream *stm);

_core_api const char_t *stm_token_lexeme(const Stream *stm, uint32_t *size);

_core_api void stm_token_escapes(Stream *stm, const bool_t active_escapes);

_core_api void stm_token_spaces(Stream *stm, const bool_t active_spaces);

_core_api void stm_token_comments(Stream *stm, const bool_t active_comments);

_core_api sstate_t stm_state(const Stream *stm);

_core_api ferror_t stm_file_err(const Stream *stm);

_core_api serror_t stm_sock_err(const Stream *stm);

_core_api void stm_corrupt(Stream *stm);

_core_api String *stm_str(const Stream *stm);

_core_api const byte_t *stm_buffer(const Stream *stm);

_core_api uint32_t stm_buffer_size(const Stream *stm);

_core_api void stm_write(Stream *stm, const byte_t *data, const uint32_t size);

_core_api void stm_write_char(Stream *stm, const uint32_t codepoint);

_core_api uint32_t stm_printf(Stream *stm, const char_t *format, ...) __PRINTF(2, 3);

_core_api uint32_t stm_writef(Stream *stm, const char_t *str);

_core_api void stm_write_bool(Stream *stm, const bool_t value);

_core_api void stm_write_i8(Stream *stm, const int8_t value);

_core_api void stm_write_i16(Stream *stm, const int16_t value);

_core_api void stm_write_i32(Stream *stm, const int32_t value);

_core_api void stm_write_i64(Stream *stm, const int64_t value);

_core_api void stm_write_u8(Stream *stm, const uint8_t value);

_core_api void stm_write_u16(Stream *stm, const uint16_t value);

_core_api void stm_write_u32(Stream *stm, const uint32_t value);

_core_api void stm_write_u64(Stream *stm, const uint64_t value);

_core_api void stm_write_r32(Stream *stm, const real32_t value);

_core_api void stm_write_r64(Stream *stm, const real64_t value);

_core_api uint32_t stm_read(Stream *stm, byte_t *data, const uint32_t size);

_core_api uint32_t stm_read_char(Stream *stm);

_core_api const char_t *stm_read_chars(Stream *stm, const uint32_t n);

_core_api const char_t *stm_read_line(Stream *stm);

_core_api const char_t *stm_read_trim(Stream *stm);

_core_api ltoken_t stm_read_token(Stream *stm);

_core_api int8_t stm_read_i8_tok(Stream *stm);

_core_api int16_t stm_read_i16_tok(Stream *stm);

_core_api int32_t stm_read_i32_tok(Stream *stm);

_core_api int64_t stm_read_i64_tok(Stream *stm);

_core_api uint8_t stm_read_u8_tok(Stream *stm);

_core_api uint16_t stm_read_u16_tok(Stream *stm);

_core_api uint32_t stm_read_u32_tok(Stream *stm);

_core_api uint64_t stm_read_u64_tok(Stream *stm);

_core_api real32_t stm_read_r32_tok(Stream *stm);

_core_api real64_t stm_read_r64_tok(Stream *stm);

_core_api bool_t stm_read_bool(Stream *stm);

_core_api int8_t stm_read_i8(Stream *stm);

_core_api int16_t stm_read_i16(Stream *stm);

_core_api int32_t stm_read_i32(Stream *stm);

_core_api int64_t stm_read_i64(Stream *stm);

_core_api uint8_t stm_read_u8(Stream *stm);

_core_api uint16_t stm_read_u16(Stream *stm);

_core_api uint32_t stm_read_u32(Stream *stm);

_core_api uint64_t stm_read_u64(Stream *stm);

_core_api real32_t stm_read_r32(Stream *stm);

_core_api real64_t stm_read_r64(Stream *stm);

_core_api void stm_skip(Stream *stm, const uint32_t size);

_core_api void stm_skip_bom(Stream *stm);

_core_api void stm_skip_token(Stream *stm, const ltoken_t token);

_core_api void stm_flush(Stream *stm);

_core_api void stm_pipe(Stream *from, Stream *to, const uint32_t n);

_core_api extern Stream *kSTDIN;

_core_api extern Stream *kSTDOUT;

_core_api extern Stream *kSTDERR;

_core_api extern Stream *kDEVNULL;

__END_C

#define stm_write_enum(stm, value, type) \
    stm_write_i32(stm, (int32_t)value)

#define stm_read_enum(stm, type) \
    (type) stm_read_i32(stm)

#define stm_lines(line, stm) \
    { \
        const char_t *line = stm_read_line(stm); \
        while (line != NULL) \
        {

#define stm_next(line, stm) \
    line = stm_read_line(stm); \
    unref(line); \
    } \
    }
