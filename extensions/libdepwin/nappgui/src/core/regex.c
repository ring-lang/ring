/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: regex.c
 *
 */

/* Regular expresions */

#include "regex.h"
#include "nfa.inl"
#include <sewer/unicode.h>

/*
RegEx *regex = regex_create("000_OCR_OK_01_.*\\.png");
bool_t ok1 = regex_match(regex, "000_OCR_OK_01_001.png");
bool_t ok2 = regex_match(regex, "000_OCR_OK_01_001spng");
bool_t ok3 = regex_match(regex, "000_OCR_OK_01_003.png");
bool_t ok4 = regex_match(regex, "000_OCR_OK_01_004.png");
bool_t ok5 = regex_match(regex, "000_OCR_OK_01_005.png");
bool_t ok6 = regex_match(regex, "000_OCR_OK_01_006.png");
bool_t ok7 = regex_match(regex, "000_OCR_OK_01_007.png");
bool_t ok8 = regex_match(regex, "000_OCR_OK_01_008.png");
bool_t ok9 = regex_match(regex, "000_OCR_OK_01_009.png");
bool_t okA = regex_match(regex, "001_OCR_OK_01_009.png");
bool_t okB = regex_match(regex, "002_OCR_OK_01_009.png");
bool_t okC = regex_match(regex, "003_OCR_OK_01_009.png");
bool_t okD = regex_match(regex, "004_OCR_OK_01_009.png");
bool_t okE = regex_match(regex, "005_OCR_OK_01_009.png");
bool_t okF = regex_match(regex, "006_OCR_OK_01_009.png");
regex_destroy(&regex);
 */

/*---------------------------------------------------------------------------*/

RegEx *regex_create(const char_t *pattern)
{
    return (RegEx *)_nfa_regex(pattern, FALSE);
}

/*---------------------------------------------------------------------------*/

void regex_destroy(RegEx **regex)
{
    _nfa_destroy((NFA **)regex);
}

/*---------------------------------------------------------------------------*/

bool_t regex_match(const RegEx *regex, const char_t *str)
{
    uint32_t codepoint;
    _nfa_start((NFA *)regex);
    codepoint = unicode_to_u32(str, ekUTF8);
    while (codepoint != 0)
    {
        if (_nfa_next((NFA *)regex, codepoint) == FALSE)
            return FALSE;

        str = unicode_next(str, ekUTF8);
        codepoint = unicode_to_u32(str, ekUTF8);
    }

    return _nfa_accept((NFA *)regex);
}
