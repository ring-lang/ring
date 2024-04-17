/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: gbind.c
 *
 */

/* Gui data binding */

#include "gbind.inl"
#include "cell.h"
#include "cell.inl"
#include "component.inl"
#include "button.inl"
#include "view.inl"
#include "edit.inl"
#include "label.inl"
#include "layout.h"
#include "layout.inl"
#include "panel.inl"
#include "popup.inl"
#include "slider.inl"
#include <core/arrpt.h>
#include <core/dbindh.h>
#include <core/event.h>
#include <core/strings.h>
#include <sewer/bmath.h>
#include <sewer/bmem.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>

ArrStFuncs(Cell);

/*---------------------------------------------------------------------------*/

static void i_set_bool(GuiComponent *component, const bool_t value)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_BUTTON:
        _button_bool((Button *)component, value);
        break;

    case ekGUI_TYPE_LABEL:
        _label_text((Label *)component, value ? "True" : "False");
        break;

    case ekGUI_TYPE_SLIDER:
        _slider_real32((Slider *)component, value ? 1.f : 0.f);
        break;

    case ekGUI_TYPE_POPUP:
    case ekGUI_TYPE_EDITBOX:
    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
        break;

    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_CUSTOMVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_enum(GuiComponent *component, const DBind *dbind, const enum_t value)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_POPUP:
    {
        uint32_t index = dbind_enum_index(dbind, value);
        _popup_uint32((PopUp *)component, index);
        break;
    }

    case ekGUI_TYPE_BUTTON:
    {
        uint32_t index = dbind_enum_index(dbind, value);
        _button_uint32((Button *)component, index);
        break;
    }

    case ekGUI_TYPE_LABEL:
    {
        uint32_t index = dbind_enum_index(dbind, value);
        const char_t *text = dbind_enum_alias(dbind, index);
        _label_text((Label *)component, text);
        break;
    }

    case ekGUI_TYPE_SLIDER:
    {
        uint32_t index = dbind_enum_index(dbind, value);
        uint32_t size = dbind_enum_count(dbind);
        real32_t norm = (real32_t)index / (size - 1);
        _slider_real32((Slider *)component, norm);
        break;
    }

    case ekGUI_TYPE_CUSTOMVIEW:
    {
        uint32_t index = dbind_enum_index(dbind, value);
        _view_uint32((View *)component, index);
        break;
    }

    case ekGUI_TYPE_EDITBOX:
    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
        break;

    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_integer(GuiComponent *component, const int64_t value, const int64_t min, const int64_t max)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_LABEL:
    {
        char_t msg[64];
        bstd_sprintf(msg, 64, "%" PRId64, value);
        _label_text((Label *)component, msg);
        break;
    }

    case ekGUI_TYPE_BUTTON:
        _button_uint32((Button *)component, value >= 0 ? (uint32_t)value : 0);
        break;

    case ekGUI_TYPE_POPUP:
        _popup_uint32((PopUp *)component, (uint32_t)value);
        break;

    case ekGUI_TYPE_CUSTOMVIEW:
        _view_uint32((View *)component, (uint32_t)value);
        break;

    case ekGUI_TYPE_SLIDER:
    {
        real64_t range = (real64_t)max - (real64_t)min;
        real32_t norm = (real32_t)(((real64_t)value - (real64_t)min) / range);
        cassert(value >= min);
        _slider_real32((Slider *)component, norm);
        break;
    }

    case ekGUI_TYPE_EDITBOX:
    {
        char_t msg[64];
        bstd_sprintf(msg, 64, "%" PRId64, value);
        _edit_text((Edit *)component, msg);
        break;
    }

    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
        break;

    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_real(GuiComponent *component, const real64_t value, const real64_t min, const real64_t max, const char_t *format)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_LABEL:
    {
        if (value != REAL32_MAX && value != REAL64_MAX)
        {
            char_t msg[64];
            bstd_sprintf(msg, 64, format, value);
            _label_text((Label *)component, msg);
        }
        else
        {
            _label_text((Label *)component, "");
        }
        break;
    }

    case ekGUI_TYPE_EDITBOX:
    {
        if (value != REAL32_MAX && value != REAL64_MAX)
        {
            char_t msg[64];
            bstd_sprintf(msg, 64, format, value);
            _edit_text((Edit *)component, msg);
        }
        else
        {
            _edit_text((Edit *)component, "");
        }
        break;
    }

    case ekGUI_TYPE_SLIDER:
    {
        if (value != REAL32_MAX && value != REAL64_MAX)
        {
            real64_t norm = bmath_clampd((value - min) / (max - min), 0, 1);
            _slider_real32((Slider *)component, (real32_t)norm);
        }
        else
        {
            _slider_real32((Slider *)component, .5f);
        }
        break;
    }

    case ekGUI_TYPE_BUTTON:
    case ekGUI_TYPE_POPUP:
    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
        break;

    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_CUSTOMVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_string(GuiComponent *component, const char_t *str)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_LABEL:
        _label_text((Label *)component, str);
        break;

    case ekGUI_TYPE_EDITBOX:
        _edit_text((Edit *)component, str);
        break;

    case ekGUI_TYPE_BUTTON:
    case ekGUI_TYPE_POPUP:
    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_SLIDER:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
        break;

    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_CUSTOMVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_image(GuiComponent *component, const Image *image)
{
    cassert_no_null(component);
    switch (component->type)
    {
    case ekGUI_TYPE_CUSTOMVIEW:
        _view_image((View *)component, image);
        break;

    case ekGUI_TYPE_LABEL:
    case ekGUI_TYPE_BUTTON:
    case ekGUI_TYPE_POPUP:
    case ekGUI_TYPE_EDITBOX:
    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_SLIDER:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
        break;

    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_set_empty(Cell *cell, const DBind *dbind)
{
    GuiComponent *component = _cell_component(cell);
    switch (component->type)
    {
    case ekGUI_TYPE_EDITBOX:
        _edit_text((Edit *)component, "");
        break;

    case ekGUI_TYPE_CUSTOMVIEW:
        _view_empty((View *)component);
        break;

    case ekGUI_TYPE_LABEL:
        _label_text((Label *)component, "");
        break;

    case ekGUI_TYPE_BUTTON:
    case ekGUI_TYPE_POPUP:
    case ekGUI_TYPE_COMBOBOX:
    case ekGUI_TYPE_SLIDER:
    case ekGUI_TYPE_UPDOWN:
    case ekGUI_TYPE_PROGRESS:
        break;

    case ekGUI_TYPE_TEXTVIEW:
    case ekGUI_TYPE_TABLEVIEW:
    case ekGUI_TYPE_TREEVIEW:
    case ekGUI_TYPE_BOXVIEW:
    case ekGUI_TYPE_SPLITVIEW:
    case ekGUI_TYPE_PANEL:
    case ekGUI_TYPE_LINE:
    case ekGUI_TYPE_HEADER:
    case ekGUI_TYPE_WINDOW:
    case ekGUI_TYPE_TOOLBAR:
        cassert_default();
    }

    switch (dbind_type(dbind))
    {
    case ekDTYPE_OBJECT_OPAQUE:
        if (str_equ_c(dbind_subtype(dbind), "Image") == TRUE)
        {
            const Image *image = (const Image *)dbind_opaque_default(dbind);
            i_set_image(component, image);
        }
        break;

    case ekDTYPE_BOOL:
    case ekDTYPE_INT8:
    case ekDTYPE_INT16:
    case ekDTYPE_INT32:
    case ekDTYPE_INT64:
    case ekDTYPE_UINT8:
    case ekDTYPE_UINT16:
    case ekDTYPE_UINT32:
    case ekDTYPE_UINT64:
    case ekDTYPE_REAL32:
    case ekDTYPE_REAL64:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_UNKNOWN:
    default:
        break;
    }

    cell_enabled(cell, FALSE);
}

/*---------------------------------------------------------------------------*/

static void i_set_empty_cells(ArrPt(Cell) *cells, const DBind *dbind)
{
    register uint32_t i, n = arrpt_size(cells, Cell);
    for (i = 0; i < n; ++i)
    {
        Cell *cell = arrpt_get(cells, i, Cell);
        i_set_empty(cell, dbind);
    }
}

/*---------------------------------------------------------------------------*/

void gbind_upd_component(Cell *cell, const StBind *stbind, const DBind *dbind, void *obj)
{
    cassert_unref(dbind_get_stbind(dbind) == stbind, stbind);
    if (obj != NULL)
    {
        dtype_t mtype = dbind_type(dbind);
        uint16_t offset = dbind_offset(dbind);
        uint16_t msize = dbind_sizeof(dbind);
        const char_t *subtype = dbind_subtype(dbind);
        void *mdata = (void *)((byte_t *)obj + offset);
        GuiComponent *component = _cell_component(cell);
        cassert(component->type != ekGUI_TYPE_PANEL);

        switch (mtype)
        {
        case ekDTYPE_BOOL:
            cassert_unref(msize == sizeof(bool_t), msize);
            i_set_bool(component, *((bool_t *)mdata));
            break;

        case ekDTYPE_ENUM:
            cassert_unref(msize == sizeof(enum_t), msize);
            i_set_enum(component, dbind, *((enum_t *)mdata));
            break;

        case ekDTYPE_INT8:
        {
            int8_t min, max;
            cassert_unref(msize == sizeof(int8_t), msize);
            dbind_int8_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((int8_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_INT16:
        {
            int16_t min, max;
            cassert_unref(msize == sizeof(int16_t), msize);
            dbind_int16_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((int16_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_INT32:
        {
            int32_t min, max;
            cassert_unref(msize == sizeof(int32_t), msize);
            dbind_int32_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((int32_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_INT64:
        {
            int64_t min, max;
            cassert_unref(msize == sizeof(int64_t), msize);
            dbind_int64_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((int64_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_UINT8:
        {
            uint8_t min, max;
            cassert_unref(msize == sizeof(uint8_t), msize);
            dbind_uint8_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((uint8_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_UINT16:
        {
            uint16_t min, max;
            cassert_unref(msize == sizeof(uint16_t), msize);
            dbind_uint16_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((uint16_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_UINT32:
        {
            uint32_t min, max;
            cassert_unref(msize == sizeof(uint32_t), msize);
            dbind_uint32_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((uint32_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_UINT64:
        {
            uint64_t min, max;
            cassert_unref(msize == sizeof(uint64_t), msize);
            dbind_uint64_range(dbind, &min, &max);
            i_set_integer(component, (int64_t) * ((uint64_t *)mdata), (int64_t)min, (int64_t)max);
            break;
        }

        case ekDTYPE_REAL32:
        {
            real32_t min, max;
            real32_t *v = (real32_t *)mdata;
            cassert_unref(msize == sizeof(real32_t), msize);
            dbind_real32_range(dbind, &min, &max);
            *v = dbind_real32(dbind, *v);
            i_set_real(component, (real64_t)*v, (real64_t)min, (real64_t)max, dbind_real32_format(dbind));
            break;
        }

        case ekDTYPE_REAL64:
        {
            real64_t min, max;
            real64_t *v = (real64_t *)mdata;
            cassert_unref(msize == sizeof(real64_t), msize);
            dbind_real64_range(dbind, &min, &max);
            *v = dbind_real64(dbind, *v);
            i_set_real(component, *v, min, max, dbind_real64_format(dbind));
            break;
        }

        case ekDTYPE_STRING_PTR:
            cassert_unref(msize == sizeof(String *), msize);
            i_set_string(component, tc(*((String **)mdata)));
            break;

        case ekDTYPE_OBJECT_OPAQUE:
            if (str_equ_c(subtype, "Image") == TRUE)
                i_set_image(component, *((Image **)mdata));
            break;

        case ekDTYPE_STRING:
        case ekDTYPE_ARRAY:
        case ekDTYPE_ARRPTR:
        case ekDTYPE_OBJECT:
        case ekDTYPE_OBJECT_PTR:
        case ekDTYPE_UNKNOWN:
            cassert_default();
        }

        cell_enabled(cell, TRUE);
    }
    else
    {
        i_set_empty(cell, dbind);
    }
}

/*---------------------------------------------------------------------------*/

void gbind_upd_layout(Layout *layout, const StBind *stbind, const DBind *dbind, void *obj)
{
    cassert_unref(dbind_get_stbind(dbind) == stbind, stbind);
    if (obj != NULL)
    {
        dtype_t mtype = dbind_type(dbind);
        uint16_t offset = dbind_offset(dbind);
        const char_t *subtype = dbind_subtype(dbind);
        void *mdata = (void *)((byte_t *)obj + offset);

        switch (mtype)
        {
        case ekDTYPE_OBJECT:
            layout_dbind_obj_imp(layout, mdata, subtype);
            break;

        case ekDTYPE_OBJECT_PTR:
            layout_dbind_obj_imp(layout, *(void **)mdata, subtype);
            break;

        case ekDTYPE_BOOL:
        case ekDTYPE_ENUM:
        case ekDTYPE_INT8:
        case ekDTYPE_INT16:
        case ekDTYPE_INT32:
        case ekDTYPE_INT64:
        case ekDTYPE_UINT8:
        case ekDTYPE_UINT16:
        case ekDTYPE_UINT32:
        case ekDTYPE_UINT64:
        case ekDTYPE_REAL32:
        case ekDTYPE_REAL64:
        {
            ArrPt(Cell) *cells = _layout_cells(layout);
            uint32_t i, n = arrpt_size(cells, Cell);
            for (i = 0; i < n; ++i)
            {
                Cell *cell = arrpt_get(cells, i, Cell);
                gbind_upd_component(cell, stbind, dbind, obj);
            }
            break;
        }

        case ekDTYPE_STRING:
        case ekDTYPE_STRING_PTR:
        case ekDTYPE_ARRAY:
        case ekDTYPE_ARRPTR:
        case ekDTYPE_UNKNOWN:
        case ekDTYPE_OBJECT_OPAQUE:
            cassert_default();
        }
    }
    else
    {
        ArrPt(Cell) *cells = _layout_cells(layout);
        i_set_empty_cells(cells, dbind);
    }
}

/*---------------------------------------------------------------------------*/

static __INLINE bool_t i_on_change(void *obj_edit, const char_t *objtype_edit, const uint16_t offset_edit, const uint16_t size_edit, Layout *notif_layout)
{
    EvBind params;
    bool_t ok = TRUE;
    void *obj_notif = NULL;
    const char_t *objtype_notif = NULL;
    Listener *listener = NULL;
    _layout_notif(notif_layout, &obj_notif, &objtype_notif, &listener);
    params.obj_notify = obj_notif;
    params.obj_edit = (byte_t *)obj_edit;
    params.objtype_notif = objtype_notif;
    params.objtype_edit = objtype_edit;
    params.offset_edit = offset_edit;
    params.size_edit = size_edit;
    listener_event_imp(listener, ekGUI_EVENT_OBJCHANGE, notif_layout, &params, &ok, "Layout", "EvBind", "bool_t");
    return ok;
}

/*---------------------------------------------------------------------------*/

/* Update an object with the result of an edit */
static bool_t i_upd_value(const byte_t *value, void *obj, const char_t *objtype, const uint16_t size, const uint16_t moffset, Layout *notif_layout)
{
    /* Area of memory that will change */
    byte_t *data = (byte_t *)obj + moffset;

    /* The change will affect only a atomic (basic) type */
    cassert(size <= 16);

    /* Has memory really changed? If not, we save the process. */
    if (bmem_cmp(data, value, size) != 0)
    {
        /* The change should be notified */
        if (notif_layout != NULL)
        {
            byte_t cache[16];

            bmem_copy(cache, data, size);
            bmem_copy(data, value, size);

            if (i_on_change(obj, objtype, moffset, size, notif_layout) == TRUE)
            {
                return TRUE;
            }
            else
            {
                bmem_copy(data, cache, size);
                return FALSE;
            }
        }
        else
        {
            bmem_copy(data, value, size);
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_upd_str(const char_t *value, void *obj, const char_t *objtype, const uint16_t size, const uint16_t moffset, Layout *notif_layout)
{
    /* Area of memory that will change */
    String **data = (String **)((byte_t *)obj + moffset);

    /* The change will affect only a atomic String* */
    cassert(size == sizeof(String *));

    /* Has memory really changed? If not, we save the process. */
    if (str_equ(*data, value) == FALSE)
    {
        /* The change should be notified */
        if (notif_layout != NULL)
        {
            String *cache = str_copy(*data);
            str_upd(data, value);

            if (i_on_change(obj, objtype, moffset, size, notif_layout) == TRUE)
            {
                str_destroy(&cache);
                return TRUE;
            }
            else
            {
                str_upd(data, tc(cache));
                str_destroy(&cache);
                return FALSE;
            }
        }
        else
        {
            str_upd(data, value);
            return TRUE;
        }
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

void gbind_upd_bool(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, bool_t value)
{
    gbind_upd_uint32(layout, dbind, obj, layout_notif, (uint32_t)value);
}

/*---------------------------------------------------------------------------*/

void gbind_upd_uint32(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, uint32_t value)
{
    uint16_t offset = dbind_offset(dbind);
    dtype_t mtype = dbind_type(dbind);
    const StBind *stbind = dbind_get_stbind(dbind);
    const char_t *objtype = dbind_stbind_type(stbind);
    bool_t updated = FALSE;

    /* Update the object data */
    switch (mtype)
    {
    case ekDTYPE_BOOL:
    {
        bool_t v = value == 0 ? FALSE : TRUE;
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(bool_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT8:
    {
        int8_t v = dbind_int8(dbind, (int8_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT16:
    {
        int16_t v = dbind_int16(dbind, (int16_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT32:
    {
        int32_t v = dbind_int32(dbind, (int32_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT64:
    {
        int64_t v = dbind_int64(dbind, (int64_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT8:
    {
        uint8_t v = dbind_uint8(dbind, (uint8_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT16:
    {
        uint16_t v = dbind_uint16(dbind, (uint16_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT32:
    {
        uint32_t v = dbind_uint32(dbind, (uint32_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT64:
    {
        uint64_t v = dbind_uint64(dbind, (uint64_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_REAL32:
    {
        real32_t v = dbind_real32(dbind, (real32_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_REAL64:
    {
        real64_t v = dbind_real64(dbind, (real64_t)value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_ENUM:
    {
        enum_t v = dbind_enum_value(dbind, value);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(enum_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_STRING_PTR:
    {
        char_t text[64];
        bstd_sprintf(text, sizeof(text), "%u", value);
        updated = i_upd_str(text, obj, objtype, sizeof(String *), offset, layout_notif);
        break;
    }

    case ekDTYPE_STRING:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }

    /* Update all controls related with this member */
    if (updated == TRUE)
        _layout_dbind_update(layout, dbind);
}

/*---------------------------------------------------------------------------*/

#define i_from_norm(min, max, value, type) \
    (type)((real64_t)min + ((real64_t)value * ((real64_t)max - (real64_t)min)))

/*---------------------------------------------------------------------------*/

void gbind_upd_norm_real32(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, const real32_t value)
{
    uint16_t offset = dbind_offset(dbind);
    dtype_t mtype = dbind_type(dbind);
    const StBind *stbind = dbind_get_stbind(dbind);
    const char_t *objtype = dbind_stbind_type(stbind);
    bool_t updated = FALSE;
    cassert(value >= 0 && value <= 1);

    /* Update the object data */
    switch (mtype)
    {
    case ekDTYPE_BOOL:
    {
        bool_t v = value >= .5f ? TRUE : FALSE;
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(bool_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_REAL32:
    {
        real32_t min, max, v;
        dbind_real32_range(dbind, &min, &max);
        v = (real32_t)(min + value * (max - min));
        v = dbind_real32(dbind, v);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_REAL64:
    {
        real64_t min, max, v;
        dbind_real64_range(dbind, &min, &max);
        v = (real64_t)(min + value * (max - min));
        v = dbind_real64(dbind, v);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT8:
    {
        int8_t min, max, v;
        dbind_int8_range(dbind, &min, &max);
        v = i_from_norm(min, max, value, int8_t);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT16:
    {
        int16_t min, max, v;
        dbind_int16_range(dbind, &min, &max);
        v = i_from_norm(min, max, value, int16_t);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT32:
    {
        int32_t min, max, v;
        dbind_int32_range(dbind, &min, &max);
        v = i_from_norm(min, max, value, int32_t);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT64:
    {
        int64_t min, max, v;
        dbind_int64_range(dbind, &min, &max);
        if (value > .9999)
            v = max;
        else
            v = i_from_norm(min, max, value, int64_t);

        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT8:
    {
        uint8_t min, max, v;
        dbind_uint8_range(dbind, &min, &max);
        v = i_from_norm(min, max, value, uint8_t);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT16:
    {
        uint16_t min, max, v;
        dbind_uint16_range(dbind, &min, &max);
        v = i_from_norm(min, max, value, uint16_t);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT32:
    {
        uint32_t min, max, v;
        dbind_uint32_range(dbind, &min, &max);
        v = i_from_norm(min, max, value, uint32_t);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT64:
    {
        uint64_t min, max, v;
        dbind_uint64_range(dbind, &min, &max);
        v = i_from_norm(min, max, value, uint64_t);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_ENUM:
    {
        uint32_t esize = dbind_enum_count(dbind);
        uint32_t index = (uint32_t)bmath_roundf(value * (esize - 1));
        enum_t v = dbind_enum_value(dbind, index);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(enum_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_STRING_PTR:
    {
        char_t text[64];
        bstd_sprintf(text, sizeof(text), "%f", value);
        updated = i_upd_str(text, obj, objtype, sizeof(String *), offset, layout_notif);
        break;
    }

    case ekDTYPE_STRING:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }

    /* Update all controls related with this member */
    if (updated == TRUE)
        _layout_dbind_update(layout, dbind);
}

/*---------------------------------------------------------------------------*/

void gbind_upd_string(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, const char_t *str)
{
    uint16_t offset = dbind_offset(dbind);
    dtype_t mtype = dbind_type(dbind);
    const StBind *stbind = dbind_get_stbind(dbind);
    const char_t *objtype = dbind_stbind_type(stbind);
    const byte_t *mdata = (byte_t *)obj + offset;
    bool_t updated = FALSE;

    /* Update the object data */
    switch (mtype)
    {

    case ekDTYPE_STRING_PTR:
        updated = i_upd_str(str, obj, objtype, sizeof(String *), offset, layout_notif);
        break;

    case ekDTYPE_REAL32:
    {
        real32_t v = dbind_string_to_real32(dbind, *((real32_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_REAL64:
    {
        real64_t v = dbind_string_to_real64(dbind, *((real64_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT8:
    {
        int8_t v = dbind_string_to_int8(dbind, *((int8_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT16:
    {
        int16_t v = dbind_string_to_int16(dbind, *((int16_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT32:
    {
        int32_t v = dbind_string_to_int32(dbind, *((int32_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT64:
    {
        int64_t v = dbind_string_to_int64(dbind, *((int64_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT8:
    {
        uint8_t v = dbind_string_to_uint8(dbind, *((uint8_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT16:
    {
        uint16_t v = dbind_string_to_uint16(dbind, *((uint16_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT32:
    {
        uint32_t v = dbind_string_to_uint32(dbind, *((uint32_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT64:
    {
        uint64_t v = dbind_string_to_uint64(dbind, *((uint64_t *)mdata), str);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_BOOL:
    case ekDTYPE_ENUM:
        break;

    case ekDTYPE_STRING:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
    default:
        break;
    }

    /* Update all controls related with this member */
    if (updated == TRUE)
        _layout_dbind_update(layout, dbind);
}

/*---------------------------------------------------------------------------*/

void gbind_upd_image(Layout *layout, const DBind *dbind, void *objbind, const Image *image)
{
    byte_t *mdata = (byte_t *)(objbind) + dbind_offset(dbind);
    dtype_t mtype = dbind_type(dbind);

    /* Update the object data */
    switch (mtype)
    {
    case ekDTYPE_OBJECT_OPAQUE:
    {
        const StBind *stbind = dbind_stbind(dbind_subtype(dbind));
        cassert(str_equ_c(dbind_subtype(dbind), "Image") == TRUE);
        dbind_stbind_opaque_upd(stbind, (void *)image, (void **)mdata);
        break;
    }

    case ekDTYPE_BOOL:
    case ekDTYPE_INT8:
    case ekDTYPE_INT16:
    case ekDTYPE_INT32:
    case ekDTYPE_INT64:
    case ekDTYPE_UINT8:
    case ekDTYPE_UINT16:
    case ekDTYPE_UINT32:
    case ekDTYPE_UINT64:
    case ekDTYPE_REAL32:
    case ekDTYPE_REAL64:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING_PTR:
        break;

    case ekDTYPE_STRING:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }

    /* Update all controls related with this member */
    /* Decoment if more imgview with same image */
    /* _layout_dbind_update(layout, dbind); */
    unref(layout);
}

/*---------------------------------------------------------------------------*/

void gbind_upd_increment(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, const bool_t pos)
{
    uint16_t offset = dbind_offset(dbind);
    dtype_t mtype = dbind_type(dbind);
    const StBind *stbind = dbind_get_stbind(dbind);
    const char_t *objtype = dbind_stbind_type(stbind);
    byte_t *mdata = (byte_t *)(obj) + offset;
    bool_t updated = FALSE;

    /* Update the object data */
    switch (mtype)
    {
    case ekDTYPE_BOOL:
    {
        bool_t v = !*((bool_t *)mdata);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(bool_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_REAL32:
    {
        real32_t v = dbind_incr_real32(dbind, *((real32_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_REAL64:
    {
        real64_t v = dbind_incr_real64(dbind, *((real64_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(real64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT8:
    {
        int8_t v = dbind_incr_int8(dbind, *((int8_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT16:
    {
        int16_t v = dbind_incr_int16(dbind, *((int16_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT32:
    {
        int32_t v = dbind_incr_int32(dbind, *((int32_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_INT64:
    {
        int64_t v = dbind_incr_int64(dbind, *((int64_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(int64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT8:
    {
        uint8_t v = dbind_incr_uint8(dbind, *((uint8_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint8_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT16:
    {
        uint16_t v = dbind_incr_uint16(dbind, *((uint16_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint16_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT32:
    {
        uint32_t v = dbind_incr_uint32(dbind, *((uint32_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint32_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_UINT64:
    {
        uint64_t v = dbind_incr_uint64(dbind, *((uint64_t *)mdata), pos);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(uint64_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_ENUM:
    {
        uint32_t index = dbind_enum_index(dbind, *((enum_t *)mdata));
        uint32_t size = dbind_enum_count(dbind);
        enum_t v;

        if (pos == TRUE)
        {
            if (index == size - 1)
                index = 0;
            else
                index++;
        }
        else
        {
            if (index == 0)
                index = size - 1;
            else
                index--;
        }

        v = dbind_enum_value(dbind, index);
        updated = i_upd_value((byte_t *)&v, obj, objtype, sizeof(enum_t), offset, layout_notif);
        break;
    }

    case ekDTYPE_STRING_PTR:
        break;

    case ekDTYPE_STRING:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }

    /* Update all controls related with this member */
    if (updated == TRUE)
        _layout_dbind_update(layout, dbind);
}

/*---------------------------------------------------------------------------*/

bool_t gbind_modify_data(const void *obj, const char_t *type, const uint16_t size, const char_t *mname, const char_t *mtype, const uint16_t moffset, const uint16_t msize, const EvBind *evbind)
{
    /* We extract the memory area that is expected to have been modified */
    const byte_t *memblock = NULL;
    uint32_t memsize = 0;
    const StBind *stbind = dbind_stbind(type);
    uint32_t i, n = dbind_stbind_count(stbind);
    cassert_unref(dbind_stbind_sizeof(stbind) == size, size);
    cassert_no_null(evbind);

    for (i = 0; i < n; ++i)
    {
        const DBind *dbind = dbind_stbind_member(stbind, i);
        uint16_t offset = dbind_offset(dbind);
        dtype_t dtype = dbind_type(dbind);
        const char_t *subtype = dbind_subtype(dbind);
        if (offset == moffset)
        {
            cassert_unref(str_equ_c(dbind_name(dbind), mname) == TRUE, mname);
            switch (dtype)
            {
            case ekDTYPE_BOOL:
            case ekDTYPE_INT8:
            case ekDTYPE_INT16:
            case ekDTYPE_INT32:
            case ekDTYPE_INT64:
            case ekDTYPE_UINT8:
            case ekDTYPE_UINT16:
            case ekDTYPE_UINT32:
            case ekDTYPE_UINT64:
            case ekDTYPE_REAL32:
            case ekDTYPE_REAL64:
            case ekDTYPE_ENUM:
                memblock = (const byte_t *)obj + offset;
                memsize = msize;
                break;

            case ekDTYPE_OBJECT:
                memblock = (const byte_t *)obj + offset;
                cassert(dbind_stbind_sizeof(dbind_stbind(subtype)) == msize);
                cassert_unref(str_equ_c(mtype, subtype) == TRUE, mtype);
                memsize = msize;
                break;

            case ekDTYPE_OBJECT_PTR:
            {
                const StBind *ostbind = dbind_stbind(subtype);
                memblock = *(const byte_t **)(((const byte_t *)obj + offset));
                cassert(sizeofptr == msize);
                cassert_unref(str_equ_cn(mtype, subtype, str_len_c(subtype)) == TRUE, mtype);
                memsize = dbind_stbind_sizeof(ostbind);
                break;
            }

            case ekDTYPE_STRING_PTR:
                memblock = (const byte_t *)obj + offset;
                cassert(sizeofptr == msize);
                cassert_unref(str_equ_c(mtype, "String*") == TRUE, mtype);
                memsize = msize;
                break;

            case ekDTYPE_STRING:
            case ekDTYPE_ARRAY:
            case ekDTYPE_ARRPTR:
            case ekDTYPE_OBJECT_OPAQUE:
            case ekDTYPE_UNKNOWN:
                cassert_default();
            }

            break;
        }
    }

    if (memblock != NULL)
    {
        const byte_t *memblock2 = (byte_t *)evbind->obj_edit + evbind->offset_edit;
        return bmem_overlaps(memblock, memblock2, memsize, evbind->size_edit);
    }

    return FALSE;
}
