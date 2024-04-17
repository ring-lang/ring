/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: nfa.inl
 *
 */

/* Non-deterministic finite automata */

#include "core.ixx"

__EXTERN_C

NFA *_nfa_string(const char_t *str);

NFA *_nfa_regex(const char_t *regex, const bool_t verbose);

void _nfa_destroy(NFA **nfa);

void _nfa_start(NFA *nfa);

bool_t _nfa_next(NFA *nfa, const uint32_t codepoint);

bool_t _nfa_accept(NFA *nfa);

__END_C
