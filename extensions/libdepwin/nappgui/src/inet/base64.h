/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: base64.h
 * https://nappgui.com/en/inet/base64.html
 *
 */

/* Base64 encoding */

#include "inet.hxx"

uint32_t b64_encoded_size(const uint32_t data_size);

uint32_t b64_decoded_size(const uint32_t encoded_size);

uint32_t b64_encode(const byte_t *data, const uint32_t size, char_t *base64, const uint32_t esize);

uint32_t b64_decode(const char_t *base64, const uint32_t size, byte_t *data);
