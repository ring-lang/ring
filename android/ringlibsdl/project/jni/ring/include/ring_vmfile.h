/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmfile_h
#define ring_vmfile_h
/* Functions */

void ring_vm_file_loadfunctions ( RingState *pRingState ) ;

void ring_vm_file_fopen ( void *pPointer ) ;

void ring_vm_file_fclose ( void *pPointer ) ;

void ring_vm_file_fflush ( void *pPointer ) ;

void ring_vm_file_freopen ( void *pPointer ) ;

void ring_vm_file_tempfile ( void *pPointer ) ;

void ring_vm_file_tempname ( void *pPointer ) ;

void ring_vm_file_fseek ( void *pPointer ) ;

void ring_vm_file_ftell ( void *pPointer ) ;

void ring_vm_file_rewind ( void *pPointer ) ;

void ring_vm_file_fgetpos ( void *pPointer ) ;

void ring_vm_file_fsetpos ( void *pPointer ) ;

void ring_vm_file_clearerr ( void *pPointer ) ;

void ring_vm_file_feof ( void *pPointer ) ;

void ring_vm_file_ferror ( void *pPointer ) ;

void ring_vm_file_perror ( void *pPointer ) ;

void ring_vm_file_rename ( void *pPointer ) ;

void ring_vm_file_remove ( void *pPointer ) ;

void ring_vm_file_fgetc ( void *pPointer ) ;

void ring_vm_file_fgets ( void *pPointer ) ;

void ring_vm_file_fputc ( void *pPointer ) ;

void ring_vm_file_fputs ( void *pPointer ) ;

void ring_vm_file_ungetc ( void *pPointer ) ;

void ring_vm_file_fread ( void *pPointer ) ;

void ring_vm_file_fwrite ( void *pPointer ) ;

void ring_vm_file_dir ( void *pPointer ) ;

void ring_vm_file_read ( void *pPointer ) ;

void ring_vm_file_write ( void *pPointer ) ;

void ring_vm_file_fexists ( void *pPointer ) ;
/* Constants */
#define RING_VM_FILE_BUFFERSIZE "Buffer size must be >= 1"
#define RING_VM_POINTER_FILE "file"
#define RING_VM_POINTER_FILEPOS "filepos"
#define RING_API_BADDIRECTORY "Error, Couldn't open the directory"
#endif
