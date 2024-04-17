/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oswindow.c
 *
 */

/* Operating System native window */

#include "oswindow.inl"
#include "oscontrol.inl"
#include "osbutton.inl"
#include <core/arrpt.h>
#include <core/arrst.h>
#include <core/event.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

OSButton *oswindow_apply_default_button(OSWindow *window, OSButton *button)
{
    OSButton *effective = NULL;
    const ArrPt(OSControl) *controls = oswindow_get_all_controls(window);
    arrpt_foreach_const(control, controls, OSControl)
        {
            cassert_no_null(control);
            if (oscontrol_type(control) == ekGUI_TYPE_BUTTON)
            {
                OSButton *nbutton = OSButtonPtr(control);
                bool_t is_default = (bool_t)(nbutton == button);
                osbutton_set_default(OSButtonPtr(control), is_default);
                if (is_default == TRUE)
                {
                    cassert(effective == NULL);
                    effective = nbutton;
                }
            }
        }
    arrpt_end()

    return effective;
}

/*---------------------------------------------------------------------------*/

static void i_remove_hotkey(OSHotKey *hotkey)
{
    listener_destroy(&hotkey->listener);
}

/*---------------------------------------------------------------------------*/

void oswindow_hotkey_destroy(ArrSt(OSHotKey) **hotkeys)
{
    cassert_no_null(hotkeys);
    arrst_destopt(hotkeys, i_remove_hotkey, OSHotKey);
}

/*---------------------------------------------------------------------------*/

void oswindow_hotkey_set(ArrSt(OSHotKey) **hotkeys, const vkey_t key, const uint32_t modifiers, Listener *listener)
{
    cassert_no_null(hotkeys);
    if (key != ENUM_MAX(vkey_t))
    {
        bool_t exists = FALSE;
        uint32_t remove = UINT32_MAX;

        if (*hotkeys == NULL && listener != NULL)
            *hotkeys = arrst_create(OSHotKey);

        /* Update the hotkey(if exists) */
        arrst_foreach(hotkey, *hotkeys, OSHotKey)
            if (hotkey->key == key && hotkey->modifiers == modifiers)
            {
                exists = TRUE;
                if (listener != NULL)
                    listener_update(&hotkey->listener, listener);
                else
                    remove = hotkey_i;
                break;
            }
        arrst_end()

        if (exists == FALSE)
        {
            /* Adds a new hotkey */
            if (listener != NULL)
            {
                OSHotKey *hotkey = arrst_new(*hotkeys, OSHotKey);
                hotkey->key = key;
                hotkey->modifiers = modifiers;
                hotkey->listener = listener;
            }
        }
        else
        {
            if (remove != UINT32_MAX)
                arrst_delete(*hotkeys, remove, i_remove_hotkey, OSHotKey);
        }
    }
    else
    {
        /* Clear all the hotkeys */
        arrst_destopt(hotkeys, i_remove_hotkey, OSHotKey);
    }
}

/*---------------------------------------------------------------------------*/

bool_t oswindow_hotkey_process(OSWindow *window, ArrSt(OSHotKey) *hotkeys, const vkey_t key, const uint32_t modifiers)
{
    if (hotkeys != NULL)
    {
        arrst_foreach(hotkey, hotkeys, OSHotKey)
            if (key == hotkey->key && modifiers == hotkey->modifiers)
            {
                EvKey params;
                cassert_no_null(hotkey->listener);
                params.key = hotkey->key;
                params.modifiers = hotkey->modifiers;
                listener_event(hotkey->listener, ekGUI_EVENT_KEYDOWN, window, &params, NULL, OSWindow, EvKey, void);
                return TRUE;
            }
        arrst_end()
    }

    return FALSE;
}
