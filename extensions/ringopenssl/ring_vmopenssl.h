/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmopenssl_h
#define ring_vmopenssl_h
/* Functions */

RING_API void ringlib_init ( RingState *pRingState ) ;

void ring_vm_openssl_md5_init ( void *pPointer ) ;

void ring_vm_openssl_md5_update ( void *pPointer ) ;

void ring_vm_openssl_md5_final ( void *pPointer ) ;

void ring_vm_openssl_md5 ( void *pPointer ) ;

void ring_vm_openssl_sha1_init ( void *pPointer ) ;

void ring_vm_openssl_sha1_update ( void *pPointer ) ;

void ring_vm_openssl_sha1_final ( void *pPointer ) ;

void ring_vm_openssl_sha1 ( void *pPointer ) ;

void ring_vm_openssl_sha256_init ( void *pPointer ) ;

void ring_vm_openssl_sha256_update ( void *pPointer ) ;

void ring_vm_openssl_sha256_final ( void *pPointer ) ;

void ring_vm_openssl_sha256 ( void *pPointer ) ;

void ring_vm_openssl_sha512_init ( void *pPointer ) ;

void ring_vm_openssl_sha512_update ( void *pPointer ) ;

void ring_vm_openssl_sha512_final ( void *pPointer ) ;

void ring_vm_openssl_sha512 ( void *pPointer ) ;

void ring_vm_openssl_sha384_init ( void *pPointer ) ;

void ring_vm_openssl_sha384_update ( void *pPointer ) ;

void ring_vm_openssl_sha384_final ( void *pPointer ) ;

void ring_vm_openssl_sha384 ( void *pPointer ) ;

void ring_vm_openssl_sha224_init ( void *pPointer ) ;

void ring_vm_openssl_sha224_update ( void *pPointer ) ;

void ring_vm_openssl_sha224_final ( void *pPointer ) ;

void ring_vm_openssl_sha224 ( void *pPointer ) ;

void ring_vm_openssl_encrypt ( void *pPointer ) ;

void ring_vm_openssl_decrypt ( void *pPointer ) ;

void ring_vm_openssl_randbytes ( void *pPointer ) ;
/* Constants */
#define RING_VM_POINTER_OPENSSL "openssl"
#endif
