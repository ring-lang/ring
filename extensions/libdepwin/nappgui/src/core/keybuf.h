/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: keybuf.h
 * https://nappgui.com/en/core/keybuf.html
 *
 */

/* Keyboard buffer */

#include "core.hxx"

__EXTERN_C

_core_api KeyBuf *keybuf_create(void);

_core_api void keybuf_destroy(KeyBuf **buffer);

_core_api void keybuf_OnUp(KeyBuf *buffer, const vkey_t key);

_core_api void keybuf_OnDown(KeyBuf *buffer, const vkey_t key);

_core_api void keybuf_clear(KeyBuf *buffer);

_core_api bool_t keybuf_pressed(const KeyBuf *buffer, const vkey_t key);

_core_api const char_t *keybuf_str(const vkey_t key);

_core_api void keybuf_dump(const KeyBuf *buffer);

__END_C
