/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osscrolls.c
 *
 */

/* Scrollbars management in control */

#include "osscrolls.inl"
#include "osscroll.inl"
#include "oscontrol.inl"
#include <core/event.h>
#include <core/heap.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _osscrolls_t
{
    OSControl *control;
    Listener *OnScroll;
    OSScroll *hscroll;
    OSScroll *vscroll;
    bool_t hvisible;
    bool_t vvisible;
    uint32_t view_width;
    uint32_t view_height;
    uint32_t content_width;
    uint32_t content_height;
    uint32_t line_width;
    uint32_t line_height;
};

/*---------------------------------------------------------------------------*/

OSScrolls *osscrolls_create(OSControl *control, const bool_t horizontal, const bool_t vertical)
{
    OSScrolls *scroll = heap_new0(OSScrolls);
    cassert_no_null(control);
    cassert(horizontal == TRUE || vertical == TRUE);
    scroll->control = control;

    if (horizontal == TRUE)
        scroll->hscroll = osscroll_horizontal(control);

    if (vertical == TRUE)
        scroll->vscroll = osscroll_vertical(control);

    scroll->hvisible = TRUE;
    scroll->vvisible = TRUE;
    return scroll;
}

/*---------------------------------------------------------------------------*/

void osscrolls_destroy(OSScrolls **scroll)
{
    cassert_no_null(scroll);
    cassert_no_null(*scroll);

    if ((*scroll)->hscroll != NULL)
        osscroll_destroy(&(*scroll)->hscroll, (*scroll)->control);

    if ((*scroll)->vscroll != NULL)
        osscroll_destroy(&(*scroll)->vscroll, (*scroll)->control);

    listener_destroy(&(*scroll)->OnScroll);
    heap_delete(scroll, OSScrolls);
}

/*---------------------------------------------------------------------------*/

void osscrolls_OnScroll(OSScrolls *scroll, Listener *listener)
{
    cassert_no_null(scroll);
    listener_update(&scroll->OnScroll, listener);
}

/*---------------------------------------------------------------------------*/

void osscrolls_visible_area(OSScrolls *scroll, uint32_t *x, uint32_t *y, uint32_t *width, uint32_t *height, uint32_t *total_width, uint32_t *total_height)
{
    cassert_no_null(scroll);
    if (scroll->hscroll != NULL)
    {
        uint32_t pos = osscroll_pos(scroll->hscroll);
        ptr_assign(x, pos);
        ptr_assign(total_width, scroll->content_width);
    }
    else
    {
        ptr_assign(x, 0);
        ptr_assign(total_width, scroll->view_width);
    }

    if (scroll->vscroll != NULL)
    {
        uint32_t pos = osscroll_pos(scroll->vscroll);
        ptr_assign(y, pos);
        ptr_assign(total_height, scroll->content_height);
    }
    else
    {
        ptr_assign(y, 0);
        ptr_assign(total_height, scroll->view_height);
    }

    ptr_assign(width, scroll->view_width);
    ptr_assign(height, scroll->view_height);
}

/*---------------------------------------------------------------------------*/

uint32_t osscrolls_x_pos(const OSScrolls *scroll)
{
    cassert_no_null(scroll);
    if (scroll->hscroll != NULL)
        return osscroll_pos(scroll->hscroll);
    return 0;
}

/*---------------------------------------------------------------------------*/

uint32_t osscrolls_y_pos(const OSScrolls *scroll)
{
    cassert_no_null(scroll);
    if (scroll->vscroll != NULL)
        return osscroll_pos(scroll->vscroll);
    return 0;
}

/*---------------------------------------------------------------------------*/

uint32_t osscrolls_bar_width(const OSScrolls *scroll, const bool_t check_if_visible)
{
    if (check_if_visible == TRUE)
    {
        cassert_no_null(scroll);
        if (scroll->vscroll != NULL)
        {
            if (scroll->vvisible == TRUE && scroll->content_height > scroll->view_height)
                return osscroll_bar_width(scroll->vscroll);
        }

        return 0;
    }
    else
    {
        return osscroll_bar_width(scroll->vscroll);
    }
}

/*---------------------------------------------------------------------------*/

uint32_t osscrolls_bar_height(const OSScrolls *scroll, const bool_t check_if_visible)
{
    if (check_if_visible == TRUE)
    {
        cassert_no_null(scroll);
        if (scroll->hscroll != NULL)
        {
            if (scroll->hvisible == TRUE && scroll->content_width > scroll->view_width)
                return osscroll_bar_height(scroll->hscroll);
        }

        return 0;
    }
    else
    {
        return osscroll_bar_height(scroll->hscroll);
    }
}

/*---------------------------------------------------------------------------*/

bool_t osscrolls_event(OSScrolls *scroll, const gui_orient_t orient, const gui_scroll_t event, const bool_t update_children)
{
    OSScroll *sbar = NULL;
    uint32_t step = 0;
    uint32_t page = 0;
    uint32_t max = 0;

    cassert_no_null(scroll);
    cassert_no_null(scroll->control);

    switch (orient)
    {
    case ekGUI_HORIZONTAL:
        sbar = scroll->hscroll;
        step = scroll->line_width;
        page = scroll->view_width;
        max = scroll->content_width - scroll->view_width;
        break;
    case ekGUI_VERTICAL:
        sbar = scroll->vscroll;
        step = scroll->line_height;
        page = scroll->view_height;
        max = scroll->content_height - scroll->view_height;
        break;
        cassert_default();
    }

    if (sbar != NULL)
    {
        uint32_t curpos = osscroll_pos(sbar);
        uint32_t pos = curpos;

        switch (event)
        {
        case ekGUI_SCROLL_BEGIN:
            pos = 0;
            break;

        case ekGUI_SCROLL_END:
            pos = max;
            break;

        case ekGUI_SCROLL_STEP_LEFT:
            if (pos > step)
                pos -= step;
            else
                pos = 0;
            break;

        case ekGUI_SCROLL_STEP_RIGHT:
            pos += step;
            if (pos > max)
                pos = max;
            break;

        case ekGUI_SCROLL_PAGE_LEFT:
            if (pos > page)
                pos -= page;
            else
                pos = 0;
            break;

        case ekGUI_SCROLL_PAGE_RIGHT:
            pos += page;
            if (pos > max)
                pos = max;
            break;

        case ekGUI_SCROLL_THUMB:
            pos = osscroll_trackpos(sbar);
            break;

            cassert_default();
        }

        if (scroll->OnScroll != NULL)
        {
            EvScroll p;
            real32_t r = (real32_t)pos;
            gui_type_t type = oscontrol_type(scroll->control);
            p.orient = orient;
            p.scroll = event;
            p.cpos = (real32_t)curpos;

            if (type == ekGUI_TYPE_PANEL)
            {
                listener_event(scroll->OnScroll, ekGUI_EVENT_SCROLL, OSPanelPtr(scroll->control), &p, &r, OSPanel, EvScroll, real32_t);
            }
            else
            {
                cassert(type == ekGUI_TYPE_CUSTOMVIEW);
                listener_event(scroll->OnScroll, ekGUI_EVENT_SCROLL, OSViewPtr(scroll->control), &p, &r, OSView, EvScroll, real32_t);
            }

            pos = (uint32_t)r;
        }

        if (curpos != pos)
        {
            osscroll_set_pos(sbar, pos);

            if (update_children == TRUE)
            {
                int32_t incr_x = 0;
                int32_t incr_y = 0;

                switch (orient)
                {
                case ekGUI_HORIZONTAL:
                    incr_x = (int32_t)curpos - (int32_t)pos;
                    break;
                case ekGUI_VERTICAL:
                    incr_y = (int32_t)curpos - (int32_t)pos;
                    break;
                    cassert_default();
                }

                osscroll_control_scroll(scroll->control, incr_x, incr_y);
            }

            return TRUE;
        }
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

void osscrolls_set(OSScrolls *scroll, const uint32_t x, const uint32_t y, const bool_t update_children)
{
    uint32_t px = x;
    uint32_t py = y;
    int32_t incr_x = 0;
    int32_t incr_y = 0;

    cassert_no_null(scroll);

    if (px != UINT32_MAX)
    {
        if (px > scroll->content_width - scroll->view_width)
            px = scroll->content_width - scroll->view_width;
    }

    if (py != UINT32_MAX)
    {
        if (py > scroll->content_height - scroll->view_height)
            py = scroll->content_height - scroll->view_height;
    }

    if (px != UINT32_MAX && scroll->hscroll != NULL)
    {
        uint32_t pos = osscroll_pos(scroll->hscroll);
        if (pos != px)
        {
            osscroll_set_pos(scroll->hscroll, px);
            incr_x = (int32_t)pos - (int32_t)px;
        }
    }

    if (py != UINT32_MAX && scroll->vscroll != NULL)
    {
        uint32_t pos = osscroll_pos(scroll->vscroll);
        if (pos != py)
        {
            osscroll_set_pos(scroll->vscroll, py);
            incr_y = (int32_t)pos - (int32_t)py;
        }
    }

    if (update_children == TRUE)
    {
        if (incr_x != 0 || incr_y != 0)
            osscroll_control_scroll(scroll->control, incr_x, incr_y);
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_limits(OSScroll *scroll, const bool_t visible, const uint32_t visible_size, const uint32_t total_size)
{
    if (visible == TRUE && visible_size > 0 && visible_size < total_size)
    {
        uint32_t max = total_size;
        uint32_t pos = osscroll_pos(scroll);
        uint32_t page = visible_size;
        uint32_t max_pos = total_size - visible_size;

        if (pos > max_pos)
            pos = max_pos;

        osscroll_config(scroll, pos, max, page);
        return TRUE;
    }
    /* Scrollbar is not necessary */
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static void i_update_bars(OSScrolls *scroll)
{
    bool_t with_hscroll = FALSE;
    bool_t with_vscroll = FALSE;
    uint32_t bw = 0;
    uint32_t bh = 0;

    cassert_no_null(scroll);

    if (scroll->hscroll != NULL)
    {
        with_hscroll = i_limits(scroll->hscroll, scroll->hvisible, scroll->view_width, scroll->content_width);
        bh = osscroll_bar_height(scroll->hscroll);
    }

    if (scroll->vscroll != NULL)
    {
        with_vscroll = i_limits(scroll->vscroll, scroll->vvisible, scroll->view_height, scroll->content_height);
        bw = osscroll_bar_width(scroll->vscroll);
    }

    if (with_hscroll == TRUE)
    {
        uint32_t x = 0;
        uint32_t y = scroll->view_height - bh;
        uint32_t width = scroll->view_width;
        uint32_t height = bh;

        if (with_vscroll == TRUE)
        {
            width -= bw;
            i_limits(scroll->hscroll, scroll->hvisible, width, scroll->content_width);
        }

        osscroll_frame(scroll->hscroll, x, y, width, height);
        osscroll_visible(scroll->hscroll, TRUE);
    }
    else
    {
        if (scroll->hscroll != NULL)
            osscroll_visible(scroll->hscroll, FALSE);
    }

    if (with_vscroll == TRUE)
    {
        uint32_t x = scroll->view_width - bw;
        uint32_t y = 0;
        uint32_t width = bw;
        uint32_t height = scroll->view_height;
        osscroll_frame(scroll->vscroll, x, y, width, height);
        osscroll_visible(scroll->vscroll, TRUE);
    }
    else
    {
        if (scroll->vscroll != NULL)
            osscroll_visible(scroll->vscroll, FALSE);
    }
}

/*---------------------------------------------------------------------------*/

void osscrolls_content_size(OSScrolls *scroll, const uint32_t width, const uint32_t height, const uint32_t line_width, const uint32_t line_height)
{
    cassert_no_null(scroll);
    scroll->content_width = width;
    scroll->content_height = height;
    scroll->line_width = line_width;
    scroll->line_height = line_height;
    i_update_bars(scroll);
}

/*---------------------------------------------------------------------------*/

void osscrolls_control_size(OSScrolls *scroll, const uint32_t width, const uint32_t height)
{
    cassert_no_null(scroll);
    scroll->view_width = width;
    scroll->view_height = height;
    i_update_bars(scroll);
}

/*---------------------------------------------------------------------------*/

void osscrolls_visible(OSScrolls *scroll, const bool_t horizontal, const bool_t vertical)
{
    cassert_no_null(scroll);
    scroll->hvisible = horizontal;
    scroll->vvisible = vertical;
    i_update_bars(scroll);
}
