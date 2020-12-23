/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmopenssl_h
#define ring_vmopenssl_h
/* Functions */

RING_API void ringlib_init ( RingState *pRingState ) ;

void ring_vm_openssl_md5 ( void *pPointer ) ;

void ring_vm_openssl_sha1 ( void *pPointer ) ;

void ring_vm_openssl_sha256 ( void *pPointer ) ;

void ring_vm_openssl_sha512 ( void *pPointer ) ;

void ring_vm_openssl_sha384 ( void *pPointer ) ;

void ring_vm_openssl_sha224 ( void *pPointer ) ;

void ring_vm_openssl_encrypt ( void *pPointer ) ;

void ring_vm_openssl_decrypt ( void *pPointer ) ;

void ring_vm_openssl_randbytes ( void *pPointer ) ;
/* Constants */
#define RING_VM_POINTER_OPENSSL "openssl"
#endif
