/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: inet.ixx
 *
 */

/* inet library */

#ifndef __INET_IXX__
#define __INET_IXX__

#include "inet.hxx"

typedef struct _oshttp_t OSHttp;
typedef struct _field_t Field;

struct _field_t
{
    String *name;
    String *value;
};

DeclSt(Field);

#endif
