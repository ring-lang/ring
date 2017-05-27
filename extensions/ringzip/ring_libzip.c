#include "ring.h"

/*
**  Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/

#include "zip.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zip.c"

typedef struct zip_t ZIP_T ;

struct buffer_t {
char *data;
size_t size;
};

static size_t on_extract(void *arg, unsigned long long offset, const void *data,size_t size) {
struct buffer_t *buf = (struct buffer_t *) arg;
buf->data = realloc(buf->data, buf->size + size + 1);
assert(NULL != buf->data);

memcpy(&(buf->data[buf->size]), data, size);
buf->size += size;
buf->data[buf->size] = 0;

return size;
}

void zip_extract_file(const char *cZIPFile,const char *cFile) {
struct buffer_t buf = {0};

struct zip_t *zip = zip_open(cZIPFile, 0, 'r');
assert(zip != NULL);

assert(0 == zip_entry_open(zip, cFile));
assert(0 == zip_entry_extract(zip, on_extract, &buf));

assert(0 == zip_entry_close(zip));
free(buf.data);
buf.data = NULL;
buf.size = 0;

zip_close(zip);
}

int on_extract_entry(const char *filename, void *arg) {
return 0;
}

void zip_extract_allfiles(const char *cFile, const char *cFolder) {
	int arg = 2;
	zip_extract(cFile,cFolder, on_extract_entry, &arg);
}

ZIP_T *zip_openfile(const char *cFile, const char *cMode) {
	return zip_open(cFile, ZIP_DEFAULT_COMPRESSION_LEVEL, cMode[0]);
}

int zip_filescount(ZIP_T *pZip) {
	return mz_zip_reader_get_num_files((mz_zip_archive *) pZip);
}

const char *zip_getfilenamebyindex(ZIP_T *pZip,int index) {
	mz_zip_archive_file_stat info;
	if (!mz_zip_reader_file_stat((mz_zip_archive *) pZip, index-1, &info)) {
// Cannot get information about zip archive;
return NULL;
}	
return info.m_filename ;
}


RING_FUNC(ring_zip_openfile)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(zip_openfile(RING_API_GETSTRING(1),RING_API_GETSTRING(2)),"ZIP_T");
}


RING_FUNC(ring_zip_entry_open)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_open((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_zip_entry_write)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_write((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"),RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_zip_entry_fwrite)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_fwrite((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_zip_entry_read)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_read((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"),(void *) RING_API_GETCPOINTER(2,"void"),(size_t *) RING_API_GETCPOINTER(3,"size_t")));
}


RING_FUNC(ring_zip_entry_fread)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_fread((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_zip_entry_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_close((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T")));
}


RING_FUNC(ring_zip_extract_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	zip_extract_file(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_zip_extract_allfiles)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	zip_extract_allfiles(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_zip_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	zip_close((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"));
}


RING_FUNC(ring_zip_filescount)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_filescount((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T")));
}


RING_FUNC(ring_zip_getfilenamebyindex)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(zip_getfilenamebyindex((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"), (int ) RING_API_GETNUMBER(2)));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("zip_openfile",ring_zip_openfile);
	ring_vm_funcregister("zip_entry_open",ring_zip_entry_open);
	ring_vm_funcregister("zip_entry_write",ring_zip_entry_write);
	ring_vm_funcregister("zip_entry_fwrite",ring_zip_entry_fwrite);
	ring_vm_funcregister("zip_entry_read",ring_zip_entry_read);
	ring_vm_funcregister("zip_entry_fread",ring_zip_entry_fread);
	ring_vm_funcregister("zip_entry_close",ring_zip_entry_close);
	ring_vm_funcregister("zip_extract_file",ring_zip_extract_file);
	ring_vm_funcregister("zip_extract_allfiles",ring_zip_extract_allfiles);
	ring_vm_funcregister("zip_close",ring_zip_close);
	ring_vm_funcregister("zip_filescount",ring_zip_filescount);
	ring_vm_funcregister("zip_getfilenamebyindex",ring_zip_getfilenamebyindex);
}
