/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: lex.inl
 *
 */

/* Lexical scanner */

#include "core.ixx"

__EXTERN_C

LexScn *_lexscn_create(void);

void _lexscn_destroy(LexScn **lex);

void _lexscn_spaces(LexScn *lex, const bool_t activate);

void _lexscn_newlines(LexScn *lex, const bool_t activate);

void _lexscn_escapes(LexScn *lex, const bool_t activate);

void _lexscn_comments(LexScn *lex, const bool_t activate);

ltoken_t _lexscn_token(LexScn *lex, Stream *stm);

uint32_t _lexscn_row(const LexScn *lex);

uint32_t _lexscn_col(const LexScn *lex);

const char_t *_lexscn_lexeme(const LexScn *lex, uint32_t *size);

const char_t *_lexscn_string(const ltoken_t token);

__END_C
