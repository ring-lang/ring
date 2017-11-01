/*
Copyright (c) 2013-2017
Mahmoud Fayed <msfclipper@yahoo.com>
Hassan Ahmed <hsn@outlook.hu>
*/


#define PCRE2_CODE_UNIT_WIDTH 8;

#include "pcre2lib/pcre2.h"
#include "pcre2lib/pcre2_internal.h"

RING_API void ringlib_init(RingState *pRingState);

void ring_pcre_match(void *pPointer);

int ring_pcre2_parse_options(List *opt_list);
