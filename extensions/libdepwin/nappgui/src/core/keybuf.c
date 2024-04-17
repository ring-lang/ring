/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: keybuf.c
 *
 */

/* Keyboard buffer */

#include "keybuf.h"
#include "heap.h"
#include "strings.h"
#include <osbs/log.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

static const char_t *i_STR[] = {
    "",  /*ekKEY_UNDEF = 0*/
    "A", /*ekKEY_A = 1*/
    "S", /*ekKEY_S = 2*/
    "D", /*ekKEY_D = 3*/
    "F", /*ekKEY_F = 4*/
    "H", /*ekKEY_H = 5*/
    "G", /*ekKEY_G = 6*/
    "Z", /*ekKEY_Z = 7*/
    "X", /*ekKEY_X = 8*/
    "C", /*ekKEY_C = 9*/

    "V",        /*ekKEY_V = 10*/
    "[BSLASH]", /*ekKEY_BSLASH = 11*/
    "B",        /*ekKEY_B = 12*/
    "Q",        /*ekKEY_Q = 13*/
    "W",        /*ekKEY_W = 14*/
    "E",        /*ekKEY_E = 15*/
    "R",        /*ekKEY_R = 16*/
    "Y",        /*ekKEY_Y = 17*/
    "T",        /*ekKEY_T = 18*/
    "1",        /*ekKEY_1 = 19*/

    "2", /*ekKEY_2 = 20*/
    "3", /*ekKEY_3 = 21*/
    "4", /*ekKEY_4 = 22*/
    "6", /*ekKEY_6 = 23*/
    "5", /*ekKEY_5 = 24*/
    "9", /*ekKEY_9 = 25*/
    "7", /*ekKEY_7 = 26*/
    "8", /*ekKEY_8 = 27*/
    "0", /*ekKEY_0 = 28*/
    "}", /*ekKEY_RCURLY = 29*/

    "O",        /*ekKEY_O = 30*/
    "U",        /*ekKEY_U = 31*/
    "{",        /*ekKEY_LCURLY = 32*/
    "I",        /*ekKEY_I = 33*/
    "P",        /*ekKEY_P = 34*/
    "[RETURN]", /*ekKEY_RETURN = 35*/
    "L",        /*ekKEY_L = 36*/
    "J",        /*ekKEY_J = 37*/
    ";",        /*ekKEY_SEMICOLON = 38*/
    "K",        /*ekKEY_K = 39*/

    "?",       /*ekKEY_QUEST = 40*/
    ",",       /*ekKEY_COMMA = 41*/
    "-",       /*ekKEY_MINUS = 42*/
    "N",       /*ekKEY_N = 43*/
    "M",       /*ekKEY_M = 44*/
    ".",       /*ekKEY_PERIOD = 45*/
    "[TAB]",   /*ekKEY_TAB = 46*/
    "[SPACE]", /*ekKEY_SPACE = 47*/
    "<>",      /*ekKEY_GTLT = 48*/
    "[BACK]",  /*ekKEY_BACK = 49*/

    "[ESC]",   /*ekKEY_ESCAPE = 50*/
    "F17",     /*ekKEY_F17 = 51*/
    "NUM.",    /*ekKEY_NUMDECIMAL = 52*/
    "NUM*",    /*ekKEY_NUMMULT = 53*/
    "NUM+",    /*ekKEY_NUMADD = 54*/
    "NUMLOCK", /*ekKEY_NUMLOCK = 55*/
    "NUM/",    /*ekKEY_NUMDIV = 56*/
    "NUMRET",  /*ekKEY_NUMRET = 57*/
    "NUM-",    /*ekKEY_NUMMINUS = 58*/
    "F18",     /*ekKEY_F18 = 59*/

    "F19",  /*ekKEY_F19 = 60*/
    "NUM=", /*ekKEY_NUMEQUAL = 61*/
    "NUM0", /*ekKEY_NUM0 = 62*/
    "NUM1", /*ekKEY_NUM1 = 63*/
    "NUM2", /*ekKEY_NUM2 = 64*/
    "NUM3", /*ekKEY_NUM3 = 65*/
    "NUM4", /*ekKEY_NUM4 = 66*/
    "NUM5", /*ekKEY_NUM5 = 67*/
    "NUM6", /*ekKEY_NUM6 = 68*/
    "NUM7", /*ekKEY_NUM7 = 69*/

    "NUM8", /*ekKEY_NUM8 = 70*/
    "NUM9", /*ekKEY_NUM9 = 71*/
    "F5",   /*ekKEY_F5 = 72*/
    "F6",   /*ekKEY_F6 = 73*/
    "F7",   /*ekKEY_F7 = 74*/
    "F3",   /*ekKEY_F3 = 75*/
    "F8",   /*ekKEY_F8 = 76*/
    "F9",   /*ekKEY_F9 = 77*/
    "F11",  /*ekKEY_F11 = 78*/
    "F13",  /*ekKEY_F13 = 79*/

    "F16",      /*ekKEY_F16 = 80*/
    "F14",      /*ekKEY_F14 = 81*/
    "F10",      /*ekKEY_F10 = 82*/
    "F12",      /*ekKEY_F12 = 83*/
    "F15",      /*ekKEY_F15 = 84*/
    "[PGUP]",   /*ekKEY_PAGEUP = 85*/
    "[HOME]",   /*ekKEY_HOME = 86*/
    "[SUPR]",   /*ekKEY_SUPR = 87*/
    "F4",       /*ekKEY_F4 = 88*/
    "[PGDOWN]", /*ekKEY_PAGEDOWN = 89*/

    "F2",       /*ekKEY_F2 = 90*/
    "[END]",    /*ekKEY_END = 91*/
    "F1",       /*ekKEY_F1 = 92*/
    "[LEFT]",   /*ekKEY_LEFT = 93*/
    "[RIGHT]",  /*ekKEY_RIGHT = 94*/
    "[DOWN]",   /*ekKEY_DOWN = 95*/
    "[UP]",     /*ekKEY_UP = 96*/
    "[LSHIFT]", /*ekKEY_LSHIFT = 97 */
    "[RSHIFT]", /*ekKEY_RSHIFT = 98 */
    "[LCTRL]",  /*ekKEY_LCTRL = 99 */
    "[RCTRL]",  /*ekKEY_RCTRL = 100 */
    "[LALT]",   /*ekKEY_LALT = 101 */
    "[RALT]",   /*ekKEY_RALT = 102 */
    "[INS]",    /*ekKEY_INSERT = 103 */
    "¿¡",       /*ekKEY_EXCLAM = 104 */
    "[MENU]",   /*ekKEY_MENU = 105 */
    "[LWIN]",   /*ekKEY_LWIN = 106 */
    "[RWIN]",   /*ekKEY_RWIN = 107 */
    "[CAPS]",   /*ekKEY_CAPS = 108 */
    "Ñ~",       /*ekKEY_TILDE = 109 */
    "^[",       /*ekKEY_GRAVE = 110 */
    "+]"        /*ekKEY_PLUS = 111 */
};

struct _keybuf_t
{
    bool_t pressed[kKEY_MAX];
};

/*---------------------------------------------------------------------------*/

KeyBuf *keybuf_create(void)
{
    return heap_new0(KeyBuf);
}

/*---------------------------------------------------------------------------*/

void keybuf_destroy(KeyBuf **buffer)
{
    heap_delete(buffer, KeyBuf);
}

/*---------------------------------------------------------------------------*/

void keybuf_OnUp(KeyBuf *buffer, const vkey_t key)
{
    cassert_no_null(buffer);
    cassert(key < kKEY_MAX);
    buffer->pressed[key] = FALSE;
}

/*---------------------------------------------------------------------------*/

void keybuf_OnDown(KeyBuf *buffer, const vkey_t key)
{
    cassert_no_null(buffer);
    cassert(key < kKEY_MAX);
    buffer->pressed[key] = TRUE;
}

/*---------------------------------------------------------------------------*/

void keybuf_clear(KeyBuf *buffer)
{
    cassert_no_null(buffer);
    bmem_set1((byte_t *)buffer->pressed, sizeof(buffer->pressed), 0);
}

/*---------------------------------------------------------------------------*/

bool_t keybuf_pressed(const KeyBuf *buffer, const vkey_t key)
{
    cassert_no_null(buffer);
    cassert(key < kKEY_MAX);
    return buffer->pressed[key];
}

/*---------------------------------------------------------------------------*/

const char_t *keybuf_str(const vkey_t key)
{
    cassert(key < kKEY_MAX);
    if ((size_t)key < sizeof(i_STR))
        return i_STR[key];
    return "*-*";
}

/*---------------------------------------------------------------------------*/

void keybuf_dump(const KeyBuf *buffer)
{
    String *str = NULL;
    uint32_t i;
    cassert_no_null(buffer);
    for (i = 0; i < kKEY_MAX; ++i)
    {
        if (buffer->pressed[i] == TRUE)
        {
            if (str != NULL)
                str_cat(&str, " ");
            str_cat(&str, keybuf_str((vkey_t)i));
        }
    }

    if (str != NULL)
    {
        log_printf("%s", tc(str));
        str_destroy(&str);
    }
}
