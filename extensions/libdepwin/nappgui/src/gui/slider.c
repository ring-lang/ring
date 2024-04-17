/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: slider.c
 *
 */

/* Slider */

#include "slider.h"
#include "slider.inl"
#include "cell.inl"
#include "component.inl"
#include "gui.inl"
#include <draw2d/guictx.h>
#include <geom2d/s2d.h>
#include <core/event.h>
#include <core/objh.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _slider_t
{
    GuiComponent component;
    real32_t current_pos;
    S2Df size;
    ResId ttipid;
    uint32_t flags;
    gui_size_t knob_size;
    Listener *OnMoved;
};

static const real32_t i_SLIDER_DEFAULT_WIDTH = 100;

/*---------------------------------------------------------------------------*/

void _slider_destroy(Slider **slider)
{
    cassert_no_null(slider);
    cassert_no_null(*slider);
    _component_destroy_imp(&(*slider)->component);
    listener_destroy(&(*slider)->OnMoved);
    obj_delete(slider, Slider);
}

/*---------------------------------------------------------------------------*/

static void i_OnSliderMoved(Slider *slider, Event *e)
{
    const EvSlider *p = event_params(e, EvSlider);
    cassert_no_null(slider);
    cassert_no_null(slider->component.context);
    cassert(event_sender_imp(e, NULL) == slider->component.ositem);
    cassert(event_type(e) == ekGUI_EVENT_SLIDER);
    cassert(p->incr == 0);
    cassert(p->step == UINT32_MAX);

    if (p->pos != slider->current_pos)
    {
        ((EvSlider *)p)->incr = p->pos - slider->current_pos;
        slider->current_pos = p->pos;
    }

    {
        Cell *cell = _component_cell(&slider->component);
        if (cell != NULL)
            _cell_upd_norm_real32(cell, p->pos);
    }

    if (slider->OnMoved != NULL)
        listener_pass_event(slider->OnMoved, e, slider, Slider);
}

/*---------------------------------------------------------------------------*/

static Slider *i_create(const uint32_t flags, const gui_size_t knob_size)
{
    const GuiCtx *context = guictx_get_current();
    void *ositem = NULL;
    Slider *slider = NULL;
    cassert_no_null(context);
    slider = obj_new0(Slider);
    ositem = context->func_create[ekGUI_TYPE_SLIDER](flags);
    _component_init(&slider->component, context, ekGUI_TYPE_SLIDER, &ositem);
    slider->current_pos = 0;
    slider->size = s2df(-1, -1);
    slider->flags = flags;
    slider->knob_size = knob_size;
    slider->OnMoved = NULL;
    context->func_slider_OnMoved(slider->component.ositem, obj_listener(slider, i_OnSliderMoved, Slider));
    return slider;
}

/*---------------------------------------------------------------------------*/

Slider *slider_create(void)
{
    return i_create(ekSLIDER_HORZ, ekGUI_SIZE_REGULAR);
}

/*---------------------------------------------------------------------------*/

Slider *slider_vertical(void)
{
    return i_create(ekSLIDER_VERT, ekGUI_SIZE_REGULAR);
}

/*---------------------------------------------------------------------------*/

void slider_OnMoved(Slider *slider, Listener *listener)
{
    cassert_no_null(slider);
    listener_update(&slider->OnMoved, listener);
}

/*---------------------------------------------------------------------------*/

void slider_tooltip(Slider *slider, const char_t *text)
{
    const char_t *ltext = NULL;
    cassert_no_null(slider);
    if (text != NULL)
        ltext = _gui_respack_text(text, &slider->ttipid);
    slider->component.context->func_set_tooltip[ekGUI_TYPE_SLIDER](slider->component.ositem, ltext);
}

/*---------------------------------------------------------------------------*/

void slider_steps(Slider *slider, const uint32_t steps)
{
    cassert_no_null(slider);
    cassert(steps > 1);
    slider->component.context->func_slider_set_tickmarks(slider->component.ositem, steps, FALSE);
}

/*---------------------------------------------------------------------------*/

void slider_value(Slider *slider, const real32_t value)
{
    real32_t v = value;
    cassert_no_null(slider);
    cassert_no_null(slider->component.context);
    cassert_no_nullf(slider->component.context->func_slider_set_position);

    if (v < 0.f)
        v = 0.f;
    else if (v > 1.f)
        v = 1.f;

    slider->current_pos = v;
    slider->component.context->func_slider_set_position(slider->component.ositem, v);
}

/*---------------------------------------------------------------------------*/

real32_t slider_get_value(const Slider *slider)
{
    cassert_no_null(slider);
    return slider->current_pos;
}

/*---------------------------------------------------------------------------*/

void _slider_dimension(Slider *slider, const uint32_t i, real32_t *dim0, real32_t *dim1)
{
    cassert_no_null(slider);
    cassert_no_null(dim0);
    cassert_no_null(dim1);

    if (slider->size.width < 0)
    {
        cassert_no_nullf(slider->component.context->func_slider_bounds);
        slider->component.context->func_slider_bounds(slider->component.ositem, i_SLIDER_DEFAULT_WIDTH, slider->knob_size, &slider->size.width, &slider->size.height);
    }

    if (i == 0)
    {
        *dim0 = slider->size.width;
    }
    else
    {
        cassert(i == 1);
        *dim1 = slider->size.height;
    }
}

/*---------------------------------------------------------------------------*/

bool_t _slider_is_horizontal(const Slider *slider)
{
    cassert_no_null(slider);
    return (bool_t)(slider_get_type(slider->flags) == ekSLIDER_HORZ);
}

/*---------------------------------------------------------------------------*/

void _slider_real32(Slider *slider, const real32_t value)
{
    cassert_no_null(slider);
    cassert(value >= 0.f && value <= 1.f);
    slider->current_pos = value;
    slider->component.context->func_slider_set_position(slider->component.ositem, value);
}

/*---------------------------------------------------------------------------*/

/*
void slider_set_tickmarks(Slider *slider, const uint32_t num_tickmarks, const bool_t tickmarks_at_left_top);
void slider_set_tickmarks(Slider *slider, const uint32_t num_tickmarks, const bool_t tickmarks_at_left_top)
{
    cassert_no_null(slider);
    cassert_no_null(slider->component.context);
    cassert_no_nullf(slider->component.context->func_slider_set_tickmarks);
    slider->component.context->func_slider_set_tickmarks(slider->component.ositem, num_tickmarks, tickmarks_at_left_top);
}*/
