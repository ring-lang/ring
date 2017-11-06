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
    List *retval, *tmp_retval;

    RING_PI pi;
    int pi_error;

    pcre2_code *code;
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

    code = pcre2_compile(pattern, PCRE2_ZERO_TERMINATED, 0, &err_code, &err_offset, NULL);

    if (code == NULL) {
        RING_API_ERROR("Compilation failed!");
        return;
    }

    pcre_md = pcre2_match_data_create_from_pattern(code, NULL);

    match = pcre2_match(
        code,
        subject,
        sublen,
        0,
        0,
        pcre_md,
        NULL
    );

    if (match < 0) {
        RING_API_ERROR("Match failed!");
        return;
    }

    if (match == PCRE2_ERROR_NOMATCH) {
        RING_API_ERROR("No matches found");
        return;
    }

    ovectorp = pcre2_get_ovector_pointer(pcre_md);

    PCRE2_SPTR tmp_ptr;

    ring_init_pattern_info(code, &pi, &pi_error);

    tmp_ptr = pi.tpl_name;
    name_count = pi.name_count;

    for (int i = 0; i < name_count; i++) {
        int n = (tmp_ptr[0] << 8) | tmp_ptr[1];
        
        tmp_ptr += pi.ne_size;
    }

}

void ring_init_pattern_info(pcre2_code code, RING_PI *in, int *error)
{
    int name_count;
    if (pcre2_pattern_info(code, PCRE2_INFO_NAMECOUNT, &name_count) != PCRE2_ERROR_NULL) {
        if (name_count > 0) {
            in->name_count = name_count;

            (void)pcre2_pattern_info(code, PCRE2_INFO_NAMETABLE, &(in->tpl_name));

            (void)pcre2_pattern_info(code, PCRE2_INFO_NAMEENTRYSIZE, &(in->ne_size));
        }
    }
}

int ring_pcre2_parse_options(List *opt_list)
{

}
