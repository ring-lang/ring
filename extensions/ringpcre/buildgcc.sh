# TODO
# this should be converted into autotools script

gcc -c -fpic ring_pcre.c pcrelib/pcre2_auto_possess.c pcrelib/pcre2_chartables.c \
    pcrelib/pcre2_compile.c pcrelib/pcre2_config.c pcrelib/pcre2_context.c \
    pcrelib/pcre2_dfa_match.c pcrelib/pcre2_error.c pcrelib/pcre2_find_bracket.c \
     pcrelib/pcre2_jit_compile.c pcrelib/pcre2_maketables.c \
     pcrelib/pcre2_match.c pcrelib/pcre2_match_data.c pcrelib/pcre2_newline.c \
     pcrelib/pcre2_ord2utf.c pcrelib/pcre2_pattern_info.c \
     pcrelib/pcre2_serialize.c pcrelib/pcre2_string_utils.c \
     pcrelib/pcre2_study.c pcrelib/pcre2_substitute.c \
     pcrelib/pcre2_substring.c pcrelib/pcre2_tables.c pcrelib/pcre2_ucd.c \
     pcrelib/pcre2_valid_utf.c pcrelib/pcre2_xclass.c \
     -DHAVE_CONFIG_H -DPCRE2_CODE_UNIT_WIDTH=8 -g -Wall -I.
gcc --shared -o ringpcre2.so *.o
