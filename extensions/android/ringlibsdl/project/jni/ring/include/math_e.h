/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_math_extension_h
#define ring_math_extension_h
#define RING_VM_DECIMALSLIMIT 90

void ring_vm_math_loadfunctions(RingState *pRingState);

void ring_vm_math_sin(void *pPointer);

void ring_vm_math_cos(void *pPointer);

void ring_vm_math_tan(void *pPointer);

void ring_vm_math_asin(void *pPointer);

void ring_vm_math_acos(void *pPointer);

void ring_vm_math_atan(void *pPointer);

void ring_vm_math_atan2(void *pPointer);

void ring_vm_math_sinh(void *pPointer);

void ring_vm_math_cosh(void *pPointer);

void ring_vm_math_tanh(void *pPointer);

void ring_vm_math_exp(void *pPointer);

void ring_vm_math_log(void *pPointer);

void ring_vm_math_log10(void *pPointer);

void ring_vm_math_ceil(void *pPointer);

void ring_vm_math_floor(void *pPointer);

void ring_vm_math_fabs(void *pPointer);

void ring_vm_math_pow(void *pPointer);

void ring_vm_math_sqrt(void *pPointer);

void ring_vm_math_unsigned(void *pPointer);

void ring_vm_math_decimals(void *pPointer);

void ring_vm_math_murmur3hash(void *pPointer);

void ring_vm_math_random(void *pPointer);

void ring_vm_math_srandom(void *pPointer);

void ring_vm_math_checkoverflow(void *pPointer);
#endif
