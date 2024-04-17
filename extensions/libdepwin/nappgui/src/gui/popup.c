/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: popup.c
 *
 */

/* Pop-up button */

#include "popup.h"
#include "popup.inl"
#include "cell.inl"
#include "component.inl"
#include "gui.inl"
#include <draw2d/font.h>
#include <draw2d/guictx.h>
#include <draw2d/image.h>
#include <geom2d/v2d.h>
#include <geom2d/s2d.h>
#include <core/arrpt.h>
#include <core/arrst.h>
#include <core/event.h>
#include <core/objh.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

typedef struct _pelem_t PElem;

struct _pelem_t
{
    ResId resid;
    String *text;
    Image *image;
};

struct _popup_t
{
    GuiComponent component;
    S2Df size;
    ResId ttipid;
    ArrSt(PElem) *elems;
    Listener *OnChange;
};

DeclSt(PElem);

/*---------------------------------------------------------------------------*/

static void i_remove_elem(PElem *elem)
{
    cassert_no_null(elem);
    str_destroy(&elem->text);
    ptr_destopt(image_destroy, &elem->image, Image);
}

/*---------------------------------------------------------------------------*/

void _popup_destroy(PopUp **popup)
{
    cassert_no_null(popup);
    cassert_no_null(*popup);
    _component_destroy_imp(&(*popup)->component);
    listener_destroy(&(*popup)->OnChange);
    arrst_destroy(&(*popup)->elems, i_remove_elem, PElem);
    obj_delete(popup, PopUp);
}

/*---------------------------------------------------------------------------*/

static void i_OnSelectionChange(PopUp *popup, Event *event)
{
    const EvButton *params = event_params(event, EvButton);
    cassert_no_null(popup);

    {
        Cell *cell = _component_cell(&popup->component);
        if (cell != NULL)
            _cell_upd_uint32(cell, params->index);
    }

    if (popup->OnChange != NULL)
    {
        const PElem *elem = arrst_get(popup->elems, params->index, PElem);
        cassert(params->text == NULL);
        ((EvButton *)params)->text = tc(elem->text);
        listener_pass_event(popup->OnChange, event, popup, PopUp);
    }
}

/*---------------------------------------------------------------------------*/

PopUp *popup_create(void)
{
    const GuiCtx *context = guictx_get_current();
    Font *font = _gui_create_default_font();
    PopUp *popup = obj_new0(PopUp);
    void *ositem = context->func_create[ekGUI_TYPE_POPUP](ekPOPUP_FLAG);
    context->func_popup_set_font(ositem, font);
    _component_init(&popup->component, context, PARAM(type, ekGUI_TYPE_POPUP), &ositem);
    popup->elems = arrst_create(PElem);
    context->func_popup_OnChange(popup->component.ositem, obj_listener(popup, i_OnSelectionChange, PopUp));
    font_destroy(&font);
    return popup;
}

/*---------------------------------------------------------------------------*/

void popup_OnSelect(PopUp *popup, Listener *listener)
{
    cassert_no_null(popup);
    listener_update(&popup->OnChange, listener);
}

/*---------------------------------------------------------------------------*/

void popup_tooltip(PopUp *popup, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(popup);
    if (text != NULL)
        ltext = _gui_respack_text(text, &popup->ttipid);
    popup->component.context->func_set_tooltip[ekGUI_TYPE_POPUP](popup->component.ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void popup_add_elem(PopUp *popup, const char_t *text, const Image *image)
{
    const char_t *ltext;
    const Image *limage;
    PElem *elem = NULL;
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_set_elem);
    cassert_no_nullf(popup->component.context->func_popup_list_height);
    elem = arrst_new(popup->elems, PElem);
    ltext = _gui_respack_text(text, &elem->resid);
    limage = _gui_respack_image((ResId)image, NULL);
    elem->image = limage ? image_copy(limage) : NULL;
    elem->text = str_c(ltext);
    popup->component.context->func_popup_set_elem(popup->component.ositem, ekCTRL_OP_ADD, UINT32_MAX, tc(elem->text), elem->image);
    popup->component.context->func_popup_list_height(popup->component.ositem, arrst_size(popup->elems, PElem));
}

/*---------------------------------------------------------------------------*/

void popup_set_elem(PopUp *popup, const uint32_t index, const char_t *text, const Image *image)
{
    PElem *elem = NULL;
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_set_elem);
    elem = arrst_get(popup->elems, index, PElem);
    str_upd(&elem->text, text);
    popup->component.context->func_popup_set_elem(popup->component.ositem, ekCTRL_OP_SET, index, text, image);
}

/*---------------------------------------------------------------------------*/

void popup_clear(PopUp *popup)
{
    register uint32_t i, n;
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_set_elem);
    n = arrst_size(popup->elems, PElem);
    arrst_clear(popup->elems, i_remove_elem, PElem);
    for (i = 0; i < n; ++i)
        popup->component.context->func_popup_set_elem(popup->component.ositem, ekCTRL_OP_DEL, 0, NULL, NULL);
}

/*---------------------------------------------------------------------------*/

uint32_t popup_count(const PopUp *popup)
{
    cassert_no_null(popup);
    return arrst_size(popup->elems, PElem);
}

/*---------------------------------------------------------------------------*/

void popup_list_height(PopUp *popup, const uint32_t num_elems)
{
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_list_height);
    popup->component.context->func_popup_list_height(popup->component.ositem, num_elems);
}

/*---------------------------------------------------------------------------*/

/*
void popup_set_font(PopUp *popup, const Font *font);
void popup_set_font(PopUp *popup, const Font *font)
{
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_set_font);
    popup->component.context->func_popup_set_font(popup->component.ositem, font, _gui_font_family(font));
}*/

/*---------------------------------------------------------------------------*/

void popup_selected(PopUp *popup, const uint32_t index)
{
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_set_selected);
    popup->component.context->func_popup_set_selected(popup->component.ositem, index);
}

/*---------------------------------------------------------------------------*/

uint32_t _popup_size(const PopUp *popup)
{
    cassert_no_null(popup);
    return arrst_size(popup->elems, PElem);
}

/*---------------------------------------------------------------------------*/

void _popup_list_height(PopUp *popup, const uint32_t elems)
{
    popup_list_height(popup, elems);
}

/*---------------------------------------------------------------------------*/

void _popup_uint32(PopUp *popup, const uint32_t value)
{
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_set_selected);

    if (value < arrst_size(popup->elems, PElem))
        popup->component.context->func_popup_set_selected(popup->component.ositem, value);
    else
        popup->component.context->func_popup_set_selected(popup->component.ositem, UINT32_MAX);
}

/*---------------------------------------------------------------------------*/

void _popup_add_enum_item(PopUp *popup, const char_t *text)
{
    PElem *elem = NULL;
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_set_elem);
    elem = arrst_new(popup->elems, PElem);
    elem->text = str_c(text);
    elem->image = NULL;
    popup->component.context->func_popup_set_elem(popup->component.ositem, ekCTRL_OP_ADD, UINT32_MAX, tc(elem->text), elem->image);
}

/*---------------------------------------------------------------------------*/

uint32_t popup_get_selected(const PopUp *popup)
{
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_get_selected);
    return popup->component.context->func_popup_get_selected(popup->component.ositem);
}

/*---------------------------------------------------------------------------*/

const char_t *popup_get_text(const PopUp *popup, const uint32_t index)
{
    const PElem *elem = NULL;
    cassert_no_null(popup);
    elem = arrst_get_const(popup->elems, index, PElem);
    return tc(elem->text);
}

/*---------------------------------------------------------------------------*/

void _popup_dimension(PopUp *popup, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(popup);
    cassert_no_null(popup->component.context);
    cassert_no_nullf(popup->component.context->func_popup_bounds);
    cassert_no_null(dim0);
    cassert_no_null(dim1);

    if (i == 0)
    {
        popup->size = kS2D_ZEROf;

        if (arrst_size(popup->elems, PElem) > 0)
        {
            arrst_foreach(elem, popup->elems, PElem)
                real32_t width, height;
                popup->component.context->func_popup_bounds(popup->component.ositem, tc(elem->text), &width, &height);
                if (width > popup->size.width)
                    popup->size.width = width;
                if (height > popup->size.height)
                    popup->size.height = height;
            arrst_end()
        }
        else
        {
            popup->component.context->func_popup_bounds(popup->component.ositem, "    ", &popup->size.width, &popup->size.height);
        }

        *dim0 = popup->size.width;
    }
    else
    {
        cassert(i == 1);
        *dim1 = popup->size.height;
    }
}

/*---------------------------------------------------------------------------*/

void _popup_locale(PopUp *popup)
{
    cassert_no_null(popup);
    arrst_foreach(elem, popup->elems, PElem)
        const char_t *text = _gui_respack_text(elem->resid, NULL);
        str_upd(&elem->text, text);
        popup->component.context->func_popup_set_elem(popup->component.ositem, ekCTRL_OP_SET, elem_i, text, elem->image);
    arrst_end()
}
