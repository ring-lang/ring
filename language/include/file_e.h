/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_file_extension_h
#define ring_file_extension_h
/* Constants */
#define RING_VM_FILE_BUFFERSIZE "Buffer size must be >= 1"
#define RING_VM_POINTER_FILE "file"
#define RING_VM_POINTER_FILEPOS "filepos"
#define RING_API_BADDIRECTORY "Error, Couldn't open the directory"
#define RING_NUMDATA_SIZE 8
#define RING_PATHTYPE_NOTKNOWN -1
#define RING_PATHTYPE_NOTFOUND 0
#define RING_PATHTYPE_FILE 1
#define RING_PATHTYPE_DIR 2
/* Data */
typedef union NumData {
	int iNumber;
	float fNumber;
	double dNumber;
	char cBytes[RING_NUMDATA_SIZE];
} NumData;
#include <sys/types.h>
#include <sys/stat.h>
#ifdef _WIN32
	/* Windows Only */
	#ifdef _MSC_VER
		#if !defined(S_ISREG) && defined(_S_IFMT) && defined(_S_IFREG)
			#define S_ISREG(m) (((m) & _S_IFMT) == _S_IFREG)
		#endif
		#if !defined(S_ISDIR) && defined(_S_IFMT) && defined(_S_IFDIR)
			#define S_ISDIR(m) (((m) & _S_IFMT) == _S_IFDIR)
		#endif
		#define stat _stat
	#endif
#else
	#if RING_EXTRAFILEFUNCTIONS
		#include <dirent.h>
		#include <unistd.h>
	#endif
#endif

void ring_vm_file_loadfunctions(RingState *pRingState);

void ring_vm_file_fopen(void *pPointer);

void ring_vm_file_fclose(void *pPointer);

void ring_vm_file_fflush(void *pPointer);

void ring_vm_file_freopen(void *pPointer);

void ring_vm_file_tempfile(void *pPointer);

void ring_vm_file_fseek(void *pPointer);

void ring_vm_file_ftell(void *pPointer);

void ring_vm_file_rewind(void *pPointer);

void ring_vm_file_fgetpos(void *pPointer);

void ring_vm_file_fsetpos(void *pPointer);

void ring_vm_file_clearerr(void *pPointer);

void ring_vm_file_feof(void *pPointer);

void ring_vm_file_ferror(void *pPointer);

void ring_vm_file_perror(void *pPointer);

void ring_vm_file_rename(void *pPointer);

void ring_vm_file_remove(void *pPointer);

void ring_vm_file_fgetc(void *pPointer);

void ring_vm_file_fgets(void *pPointer);

void ring_vm_file_fputc(void *pPointer);

void ring_vm_file_fputs(void *pPointer);

void ring_vm_file_ungetc(void *pPointer);

void ring_vm_file_fread(void *pPointer);

void ring_vm_file_fwrite(void *pPointer);

void ring_vm_file_read(void *pPointer);

void ring_vm_file_write(void *pPointer);
/* Number & Bytes */

void ring_vm_file_int2bytes(void *pPointer);

void ring_vm_file_float2bytes(void *pPointer);

void ring_vm_file_double2bytes(void *pPointer);

void ring_vm_file_bytes2int(void *pPointer);

void ring_vm_file_bytes2float(void *pPointer);

void ring_vm_file_bytes2double(void *pPointer);

void ring_vm_file_freefunc(void *pRingState, void *pPointer);
#if RING_EXTRAFILEFUNCTIONS
/* Check File/Dir/Type */

void ring_vm_file_fexists(void *pPointer);

void ring_vm_file_direxists(void *pPointer);

void ring_vm_file_getpathtype(void *pPointer);

void ring_vm_file_getfilesize(void *pPointer);

void ring_vm_file_dir(void *pPointer);

void ring_vm_file_tempname(void *pPointer);
#endif
#endif
