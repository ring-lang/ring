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
    pcre2_match_data *pcre_md;
    int match;
    PCRE2_SPTR subject;
    PCRE2_SIZE sublen;
    PCRE2_SIZE start_offset;
    PCRE2_SIZE *ovectorp;

    PCRE2_SPTR tpl_name;
    int name_count;
    int name_size;

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
    subject = (PCRE2_SPTR) RING_API_GETSTRING(3);

    pcre = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, 0, &err_code, &err_offset, NULL);

    if (pcre == NULL) {
        RING_API_ERROR("Compilation failed!");
        return;
    }

    pcre_md = pcre2_match_data_from_pattern(pcre, NULL);

    match = pcre2_match(
        pcre2,
        subject,
        sublen,
        0,
        0,
        pcre_md,
        NULL
    );

    if (match == NULL || match < 0) {
        RING_API_ERROR("Match failed!");
        return;
    }

    if (match == PCRE2_ERROR_NOMATCH) {
        RING_API_ERROR("No matches found");
        return;
    }

    ovectorp = pcre2_get_ovector_pointer(pcre_md);

}

int ring_pcre2_parse_options(List *opt_list)
{

}
