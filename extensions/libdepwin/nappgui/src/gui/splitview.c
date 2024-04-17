/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: splitview.c
 *
 */

/* Split view */

#include "splitview.h"
#include "splitview.inl"
#include "component.inl"
#include "gui.inl"
#include "panel.inl"
#include <draw2d/guictx.h>
#include <geom2d/s2d.h>
#include <geom2d/v2d.h>
#include <core/event.h>
#include <core/objh.h>
#include <sewer/bmath.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _splitview_t
{
    GuiComponent component;
    S2Df init_size;
    S2Df expand_size;
    S2Df final_size;
    uint32_t flags;
    bool_t is_dragging;
    real32_t div_pos;
    real32_t div_thick;
    GuiComponent *child1;
    GuiComponent *child2;
    bool_t child1_tabstop;
    bool_t child2_tabstop;
    real32_t chid1_dim[2];
    real32_t chid2_dim[2];
};

/*---------------------------------------------------------------------------*/

static real32_t i_divpos(const uint32_t flags, const real32_t pos, const real32_t size)
{
    /* Proportional mode */
    if (BIT_TEST(flags, ekSPLIT_PROP) == TRUE)
    {
        cassert(pos >= 0 && pos <= 1);
        return bmath_roundf(pos * size);
    }

    cassert(pos > 1);

    /* Fixed left/top size */
    if (BIT_TEST(flags, ekSPLIT_LEFT) == TRUE)
    {
        if (pos < size)
            return pos;
        else
            return size;
    }

    /* Fixed right/bottom size */
    cassert(BIT_TEST(flags, ekSPLIT_RIGHT) == TRUE);
    if (pos < size)
        return size - pos;
    else
        return 0;
}

/*---------------------------------------------------------------------------*/

static void i_frames(const SplitView *split, const S2Df *size, R2Df *rect1, R2Df *rect2, R2Df *rect_track)
{
    cassert_no_null(split);
    cassert_no_null(size);
    cassert_no_null(rect1);
    cassert_no_null(rect2);
    cassert_no_null(rect_track);
    if (split_get_type(split->flags) == ekSPLIT_HORZ)
    {
        real32_t divider_y = i_divpos(split->flags, split->div_pos, size->height);
        rect1->pos = kV2D_ZEROf;
        rect1->size.width = size->width;
        rect1->size.height = divider_y;
        rect2->pos.x = 0;
        rect2->pos.y = rect1->size.height;
        rect2->size.width = size->width;
        rect2->size.height = size->height - rect1->size.height;
        rect_track->pos.x = 0;
        rect_track->pos.y = bmath_roundf(divider_y - .5f * split->div_thick);
        rect_track->size.width = size->width;
        rect_track->size.height = split->div_thick;
    }
    else
    {
        real32_t divider_x = i_divpos(split->flags, split->div_pos, size->width);
        rect1->pos = kV2D_ZEROf;
        rect1->size.width = divider_x;
        rect1->size.height = size->height;
        rect2->pos.x = rect1->size.width;
        rect2->pos.y = 0;
        rect2->size.width = size->width - rect1->size.width;
        rect2->size.height = size->height;
        rect_track->pos.x = bmath_roundf(divider_x - .5f * split->div_thick);
        rect_track->pos.y = 0;
        rect_track->size.width = split->div_thick;
        rect_track->size.height = size->height;
    }
}

/*---------------------------------------------------------------------------*/

static real32_t i_update_divider(const uint32_t flags, const real32_t mouse_pos, const real32_t size)
{
    cassert(size > 0);

    /* Proportional mode */
    if (BIT_TEST(flags, ekSPLIT_PROP) == TRUE)
        return bmath_clampf(mouse_pos / size, 0, 1);

    /* Fixed left/top size */
    if (BIT_TEST(flags, ekSPLIT_LEFT) == TRUE)
        return mouse_pos;

    /* Fixed right/bottom size */
    cassert(BIT_TEST(flags, ekSPLIT_RIGHT) == TRUE);
    return size - mouse_pos;
}

/*---------------------------------------------------------------------------*/

static void i_resize_children(SplitView *split, const R2Df *r1, const R2Df *r2, const R2Df *rtrack)
{
    cassert_no_null(split);
    cassert_no_null(r1);
    cassert_no_null(r2);
    cassert_no_null(rtrack);

    if (split->child1 != NULL && split->child2 != NULL)
    {
        if (r1->size.width > 0 && r1->size.height > 0)
        {
            _component_set_frame(split->child1, &r1->pos, &r1->size);
            _component_visible(split->child1, TRUE);
        }
        else
        {
            _component_visible(split->child1, FALSE);
        }

        if (r2->size.width > 0 && r2->size.height > 0)
        {
            _component_set_frame(split->child2, &r2->pos, &r2->size);
            _component_visible(split->child2, TRUE);
        }
        else
        {
            _component_visible(split->child2, FALSE);
        }

        split->component.context->func_split_track_area(split->component.ositem, rtrack->pos.x, rtrack->pos.y, rtrack->size.width, rtrack->size.height);
    }
    else if (split->child1 != NULL)
    {
        _component_set_frame(split->child1, &kV2D_ZEROf, &r1->size);
        cassert(r2->size.width == 0);
        cassert(r2->size.height == 0);
        split->component.context->func_split_track_area(split->component.ositem, 0, 0, 0, 0);
    }
}

/*---------------------------------------------------------------------------*/

static void i_OnDrag(SplitView *split, Event *e)
{
    const EvMouse *params = event_params(e, EvMouse);
    cassert_no_null(split);
    cassert(event_type(e) == ekGUI_EVENT_DRAG);
    cassert(params->button == ekGUI_MOUSE_LEFT);
    if (split->is_dragging == TRUE)
    {
        real32_t mouse_pos = 0, size = 0;
        R2Df r1, r2, rtrack;

        if (split_get_type(split->flags) == ekSPLIT_HORZ)
        {
            mouse_pos = params->y;
            size = split->final_size.height;
        }
        else
        {
            mouse_pos = params->x;
            size = split->final_size.width;
        }

        split->div_pos = i_update_divider(split->flags, mouse_pos, size);

        i_frames(split, &split->final_size, &r1, &r2, &rtrack);
        i_resize_children(split, &r1, &r2, &rtrack);

        if (split->child1 != NULL)
        {
            real32_t dim0 = 0, dim1 = 0, fsize0 = 0, fsize1 = 0;
            _component_dimension(split->child1, 0, &dim0, &dim1);
            _component_dimension(split->child1, 1, &dim0, &dim1);
            _component_expand(split->child1, 0, dim0, r1.size.width, &fsize0);
            _component_expand(split->child1, 1, dim1, r1.size.height, &fsize1);
            _component_locate(split->child1);
        }

        if (split->child2 != NULL)
        {
            real32_t dim0 = 0, dim1 = 0, fsize0 = 0, fsize1 = 0;
            _component_dimension(split->child2, 0, &dim0, &dim1);
            _component_dimension(split->child2, 1, &dim0, &dim1);
            _component_expand(split->child2, 0, dim0, r2.size.width, &fsize0);
            _component_expand(split->child2, 1, dim1, r2.size.height, &fsize1);
            _component_locate(split->child2);
        }
    }
    else
    {
        split->is_dragging = TRUE;
    }
}

/*---------------------------------------------------------------------------*/

static SplitView *i_create(const uint32_t flags)
{
    const GuiCtx *context = guictx_get_current();
    void *ositem = context->func_create[ekGUI_TYPE_SPLITVIEW](flags);
    SplitView *split = obj_new0(SplitView);
    _component_init(&split->component, context, ekGUI_TYPE_SPLITVIEW, &ositem);
    split->init_size = s2df(128, 128);
    split->expand_size = kS2D_ZEROf;
    split->final_size = kS2D_ZEROf;
    split->flags = flags;
    split->is_dragging = FALSE;
    split->div_pos = .5f;
    split->div_thick = 10;
    context->func_split_OnDrag(split->component.ositem, obj_listener(split, i_OnDrag, SplitView));
    BIT_SET(split->flags, ekSPLIT_PROP);
    return split;
}

/*---------------------------------------------------------------------------*/

SplitView *splitview_horizontal(void)
{
    return i_create(ekSPLIT_HORZ);
}

/*---------------------------------------------------------------------------*/

SplitView *splitview_vertical(void)
{
    return i_create(ekSPLIT_VERT);
}

/*---------------------------------------------------------------------------*/

static void i_add_child(SplitView *split, GuiComponent *component, const bool_t tabstop)
{
    cassert_no_null(split);
    cassert_no_null(component);
    if (split->child1 == NULL)
    {
        split->child1 = component;
        split->child1_tabstop = tabstop;
    }
    else
    {
        cassert(split->child2 == NULL);
        split->child2 = component;
        split->child2_tabstop = tabstop;
    }

    split->component.context->func_split_attach_control(split->component.ositem, component->ositem);
}

/*---------------------------------------------------------------------------*/

void splitview_size(SplitView *split, const S2Df size)
{
    cassert_no_null(split);
    split->init_size = size;
}

/*---------------------------------------------------------------------------*/

void splitview_view(SplitView *split, View *view, const bool_t tabstop)
{
    i_add_child(split, (GuiComponent *)view, tabstop);
}

/*---------------------------------------------------------------------------*/

void splitview_text(SplitView *split, TextView *view, const bool_t tabstop)
{
    i_add_child(split, (GuiComponent *)view, tabstop);
}

/*---------------------------------------------------------------------------*/

void splitview_split(SplitView *split, SplitView *child)
{
    i_add_child(split, (GuiComponent *)child, TRUE);
}

/*---------------------------------------------------------------------------*/

void splitview_panel(SplitView *split, Panel *panel)
{
    i_add_child(split, (GuiComponent *)panel, TRUE);
}

/*---------------------------------------------------------------------------*/

void splitview_pos(SplitView *split, const real32_t pos)
{
    cassert_no_null(split);
    BIT_CLEAR(split->flags, ekSPLIT_PROP);
    BIT_CLEAR(split->flags, ekSPLIT_LEFT);
    BIT_CLEAR(split->flags, ekSPLIT_RIGHT);
    if (pos >= 0 && pos <= 1)
    {
        BIT_SET(split->flags, ekSPLIT_PROP);
        split->div_pos = pos;
    }
    else if (pos > 0)
    {
        BIT_SET(split->flags, ekSPLIT_LEFT);
        split->div_pos = pos;
    }
    else
    {
        BIT_SET(split->flags, ekSPLIT_RIGHT);
        split->div_pos = -pos;
    }
}

/*---------------------------------------------------------------------------*/

void _splitview_destroy(SplitView **split)
{
    cassert_no_null(split);
    cassert_no_null(*split);
    if ((*split)->child1 != NULL)
    {
        (*split)->component.context->func_split_detach_control((*split)->component.ositem, (*split)->child1->ositem);
        _component_destroy(&(*split)->child1);

        if ((*split)->child2 != NULL)
        {
            (*split)->component.context->func_split_detach_control((*split)->component.ositem, (*split)->child2->ositem);
            _component_destroy(&(*split)->child2);
        }
    }
    else
    {
        cassert((*split)->child2 == NULL);
    }

    _component_destroy_imp(&(*split)->component);
    obj_delete(split, SplitView);
}

/*---------------------------------------------------------------------------*/

void _splitview_dimension(SplitView *split, const uint32_t di, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(split);
    cassert_no_null(dim0);
    cassert_no_null(dim1);

    if (split->child1 != NULL)
        _component_dimension(split->child1, di, &split->chid1_dim[0], &split->chid1_dim[1]);
    else
        split->chid1_dim[di] = 0;

    if (split->child2 != NULL)
        _component_dimension(split->child2, di, &split->chid2_dim[0], &split->chid2_dim[1]);
    else
        split->chid2_dim[di] = 0;

    if (di == 0)
    {
        *dim0 = split->init_size.width;
    }
    else
    {
        cassert(di == 1);
        *dim1 = split->init_size.height;
    }
}

/*---------------------------------------------------------------------------*/

void _splitview_expand(SplitView *split, const uint32_t di, const real32_t current_size, const real32_t required_size, real32_t *final_size)
{
    R2Df r1, r2, rtrack;
    cassert_no_null(split);
    cassert_no_null(final_size);
    unref(current_size);

    if (di == 0)
    {
        split->expand_size.width = required_size;
    }
    else
    {
        cassert(di == 1);
        split->expand_size.height = required_size;

        i_frames(split, &split->expand_size, &r1, &r2, &rtrack);

        if (split->child1 != NULL)
        {
            if (r1.size.width > 0 && r1.size.height > 0)
            {
                real32_t fsize1 = 0, fsize2 = 0;
                _component_expand(split->child1, 0, split->chid1_dim[0], r1.size.width, &fsize1);
                _component_expand(split->child1, 1, split->chid1_dim[1], r1.size.height, &fsize2);
            }
        }

        if (split->child2 != NULL)
        {
            if (r2.size.width > 0 && r2.size.height > 0)
            {
                real32_t fsize1 = 0, fsize2 = 0;
                _component_expand(split->child2, 0, split->chid2_dim[0], r2.size.width, &fsize1);
                _component_expand(split->child2, 1, split->chid2_dim[1], r2.size.height, &fsize2);
            }
        }
    }

    *final_size = required_size;
}

/*---------------------------------------------------------------------------*/

void _splitview_taborder(const SplitView *split, Window *window)
{
    cassert_no_null(split);
    if (split->child1 != NULL && split->child1_tabstop == TRUE)
        _component_taborder(split->child1, window);
    if (split->child2 != NULL && split->child2_tabstop == TRUE)
        _component_taborder(split->child2, window);
}

/*---------------------------------------------------------------------------*/

void _splitview_OnResize(SplitView *split, const S2Df *size)
{
    R2Df r1, r2, rtrack;
    cassert_no_null(split);
    cassert_no_null(size);
    i_frames(split, size, &r1, &r2, &rtrack);
    i_resize_children(split, &r1, &r2, &rtrack);
    split->final_size = *size;
}

/*---------------------------------------------------------------------------*/

static void i_accum_panels(const SplitView *split, uint32_t *num_panels, Panel **panels)
{
    cassert_no_null(split);
    cassert_no_null(num_panels);
    cassert_no_null(panels);

    if (split->child1 != NULL)
    {
        if (split->child1->type == ekGUI_TYPE_PANEL)
        {
            panels[*num_panels] = (Panel *)split->child1;
            *num_panels += 1;
            cassert(*num_panels < GUI_COMPONENT_MAX_PANELS);
        }
        else if (split->child1->type == ekGUI_TYPE_SPLITVIEW)
        {
            i_accum_panels((SplitView *)split->child1, num_panels, panels);
        }
    }

    if (split->child2 != NULL)
    {
        if (split->child2->type == ekGUI_TYPE_PANEL)
        {
            panels[*num_panels] = (Panel *)split->child2;
            *num_panels += 1;
            cassert(*num_panels < GUI_COMPONENT_MAX_PANELS);
        }
        else if (split->child2->type == ekGUI_TYPE_SPLITVIEW)
        {
            i_accum_panels((SplitView *)split->child2, num_panels, panels);
        }
    }
}

/*---------------------------------------------------------------------------*/

void _splitview_panels(const SplitView *split, uint32_t *num_panels, Panel **panels)
{
    *num_panels = 0;
    i_accum_panels(split, num_panels, panels);
}
