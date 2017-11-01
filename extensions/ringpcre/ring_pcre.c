/*
Copyright (c) 2013-2017
Mahmoud Fayed <msfclipper@yahoo.com>
Hassan Ahmed <hsn@outlook.hu>
*/

#include "ring.h"
#include "ring_pcre.h"

RING_API void ringlib_init ( RingState *pRingState )
{
	ring_vm_funcregister("pcre_match", ring_pcre_match);
}

void ring_pcre_match(void *pPointer)
{
    pcre2_code *pcre;
    PCRE2_SPTR pattern;
    int options;
    int err_code;
    PCRE2_SIZE err_offset;

    if (RING_API_PARACOUNT != 2) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return;
    }

    if (! RING_API_ISSTRING(1)) {
        RING_API_ERROR("This function excpects the first paratmeter to be a string");
        return;
    }

    if (! RING_API_ISLIST(2)) {
        RING_API_ERROR("This function excpects the second paratmeter to be a list");
        return;
    }

    pattern = (PCRE2_SPTR) RING_API_GETSTRING(1);
    options = ring_pcre2_parse_options(RING_API_GETLIST(2));

    pcre = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, 0, &err_code, &err_offset, NULL);

    if (pcre == NULL) {
        RING_API_ERROR("Compilation failed!");
        return;
    }
}

int ring_pcre2_parse_options(List *opt_list)
{

}
