/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: scrollview.c
 *
 */

/* Scroll views common functionality */

#include "scrollview.inl"
#include "view.h"
#include <core/heap.h>
#include <geom2d/s2d.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

struct _scrollview_t
{
    View *view;
    uint32_t control_width;
    uint32_t control_height;
    uint32_t content_width;
    uint32_t content_height;
    uint32_t scrollbar_width;
    uint32_t scrollbar_height;
};

/*---------------------------------------------------------------------------*/

ScrollView *scrollview_create(View *view)
{
    ScrollView *sview = heap_new0(ScrollView);
    sview->view = view;
    return sview;
}

/*---------------------------------------------------------------------------*/

void scrollview_destroy(ScrollView **view)
{
    heap_delete(view, ScrollView);
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_content_width(const ScrollView *view)
{
    cassert_no_null(view);
    return view->content_width;
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_content_height(const ScrollView *view)
{
    cassert_no_null(view);
    return view->content_height;
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_control_width(const ScrollView *view)
{
    cassert_no_null(view);
    return view->control_width;
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_control_height(const ScrollView *view)
{
    cassert_no_null(view);
    return view->control_height;
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_scrollbar_width(const ScrollView *view)
{
    cassert_no_null(view);
    return view->scrollbar_width;
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_scrollbar_height(const ScrollView *view)
{
    cassert_no_null(view);
    return view->scrollbar_height;
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_xpos(const ScrollView *view)
{
    V2Df pos;
    cassert_no_null(view);
    view_viewport(view->view, &pos, NULL);
    return (uint32_t)pos.x;
}

/*---------------------------------------------------------------------------*/

uint32_t scrollview_ypos(const ScrollView *view)
{
    V2Df pos;
    cassert_no_null(view);
    view_viewport(view->view, &pos, NULL);
    return (uint32_t)pos.y;
}

/*---------------------------------------------------------------------------*/

void scrollview_control_size(ScrollView *view, const uint32_t control_width, const uint32_t control_height)
{
    cassert_no_null(view);
    view->control_width = control_width;
    view->control_height = control_height;
}

/*---------------------------------------------------------------------------*/

void scrollview_content_size(ScrollView *view, const uint32_t content_width, const uint32_t content_height, const uint32_t line_width, const uint32_t line_height)
{
    uint32_t twidth = content_width;
    uint32_t theight = content_height;
    real32_t bar_width, bar_height;

    cassert_no_null(view);

    /* First content dimension */
    view_content_size(view->view, s2df((real32_t)content_width, (real32_t)content_height), s2df((real32_t)line_width, (real32_t)line_height));

    /* Second content dimension taken into account scrollbars size and control size */
    view_scroll_size(view->view, &bar_width, &bar_height);
    view->scrollbar_width = (uint32_t)bar_width;
    view->scrollbar_height = (uint32_t)bar_height;

    if (twidth < view->control_width)
        twidth = view->control_width;

    if (theight < view->control_height)
        theight = view->control_height;

    view->content_width = twidth;
    view->content_height = theight;
    twidth += view->scrollbar_width;
    theight += view->scrollbar_height;

    if (twidth != content_width || theight != content_height)
        view_content_size(view->view, s2df((real32_t)twidth, (real32_t)theight), s2df((real32_t)line_width, (real32_t)line_height));
}

/*---------------------------------------------------------------------------*/

void scrollview_scroll_x(ScrollView *view, const uint32_t xpos, const bool_t redraw)
{
    cassert_no_null(view);
    view_scroll_x(view->view, (real32_t)xpos);

    if (redraw == TRUE)
        view_update(view->view);
}

/*---------------------------------------------------------------------------*/

void scrollview_scroll_x_incr(ScrollView *view, const int32_t incr_x, const bool_t redraw)
{
    uint32_t scroll_x;
    bool_t updated = FALSE;

    cassert_no_null(view);

    {
        V2Df pos;
        view_viewport(view->view, &pos, NULL);
        scroll_x = (uint32_t)pos.x;
    }

    /* Scroll to left */
    if (incr_x < 0)
    {
        if (scroll_x > 0)
        {
            int32_t npos = (int32_t)scroll_x + incr_x;
            if (npos < 0)
                npos = 0;
            view_scroll_x(view->view, (real32_t)npos);
            updated = TRUE;
        }
    }
    /* Scroll to right */
    else if (incr_x > 0)
    {
        if (view->content_width > view->control_width)
        {
            uint32_t npos = scroll_x + incr_x;
            if (npos > view->content_width)
                npos = view->content_width;
            view_scroll_x(view->view, (real32_t)npos);
            updated = TRUE;
        }
    }

    if (updated == TRUE && redraw == TRUE)
        view_update(view->view);
}

/*---------------------------------------------------------------------------*/

bool_t scrollview_scroll_y_visible(ScrollView *view, const uint32_t ypos, const bool_t redraw)
{
    uint32_t scroll_y;
    bool_t updated = FALSE;

    cassert_no_null(view);

    {
        V2Df pos;
        view_viewport(view->view, &pos, NULL);
        scroll_y = (uint32_t)pos.y;
    }

    /* The visible point is above */
    if (scroll_y > ypos)
    {
        view_scroll_y(view->view, (real32_t)ypos);
        updated = TRUE;
    }
    /* The visible point is below */
    else if (scroll_y + view->control_height - view->scrollbar_height < ypos)
    {
        real32_t nscroll_y = (real32_t)(ypos - view->control_height + view->scrollbar_height);
        view_scroll_y(view->view, nscroll_y);
        updated = TRUE;
    }

    if (updated == TRUE && redraw == TRUE)
        view_update(view->view);

    return updated;
}

/*---------------------------------------------------------------------------*/

void scrollview_update(ScrollView *view)
{
    cassert_no_null(view);
    view_update(view->view);
}
