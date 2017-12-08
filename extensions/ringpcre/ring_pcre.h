/*
Copyright (c) 2013-2017
Mahmoud Fayed <msfclipper@yahoo.com>
Hassan Ahmed <hsn@outlook.hu>
*/

#define PCRE2_CODE_UNIT_WIDTH 8

#include "pcre2lib/pcre2.h"

typedef struct _ring_pcre2_pattern_info {
    PCRE2_SPTR tpl_name;
    uint32_t name_count;
    uint32_t ne_size; /* name entry size */
} RING_PI;

RING_API void ringlib_init(RingState *pRingState);

void ring_pcre_match(void *pPointer);

int ring_pcre2_explain_option(char* option);

int ring_pcre2_parse_options(List *opt_list, int *is_global);

void ring_init_pattern_info(pcre2_code code, RING_PI *in, int *error);
