/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: gui.ixx
 *
 */

/* Graphics User Interface */

#ifndef __GUI_IXX__
#define __GUI_IXX__

#include "gui.hxx"
#include <core/coreh.hxx>

enum _gievent_t
{
    ekGUI_EVENT_ANIMATION
};

typedef struct _line_t Line;
typedef union _tag_t Tag;
typedef struct _gui_component_t GuiComponent;
typedef struct _scrollview_t ScrollView;
typedef struct _colitem_t ColItem;
typedef struct _evtransition_t EvTransition;
typedef struct _evbind_t EvBind;

typedef void (*FPtr_set_size)(void *component, const S2Df *size);
#define FUNC_CHECK_SET_SIZE(func, type) \
    (void)((void (*)(type *, const S2Df *))func == func)

typedef void (*FPtr_get_size)(void *component, S2Df *size);
#define FUNC_CHECK_GET_SIZE(func, type) \
    (void)((void (*)(type *, S2Df *))func == func)

typedef void (*FPtr_dimension)(void *component, const uint32_t di, real32_t *dim0, real32_t *dim1);
#define FUNC_CHECK_DIMENSION(func, type) \
    (void)((void (*)(type *, const uint32_t, real32_t *, real32_t *))func == func)

typedef void (*FPtr_expand)(void *component, const uint32_t di, const real32_t current_size, const real32_t required_size, real32_t *final_size);
#define FUNC_CHECK_EXPAND(func, type) \
    (void)((void (*)(type *, const uint32_t, const real32_t, const real32_t, real32_t *))func == func)

typedef void (*FPtr_panels)(const void *component, uint32_t *num_panels, Panel **panels);
#define FUNC_CHECK_PANELS(func, type) \
    (void)((void (*)(const type *, uint32_t *, Panel **))func == func)

typedef void (*FPtr_set_image)(void *item, const Image *image);

union _tag_t
{
    uint32_t tag_uint32;
};

struct _gui_component_t
{
    Object object;
    GuiCtx *context;
    gui_type_t type;
    Panel *panel;
    Tag tag;
    void *ositem;
};

ArrPt(Column);
DeclPt(Cell);
DeclPt(Layout);
DeclPt(GuiComponent);
DeclPt(MenuItem);

struct _colitem_t
{
    ctrl_op_t op;
    uint32_t index;
    const char_t *text;
    align_t align;
    real32_t width;
};

struct _evtransition_t
{
    real64_t prtime;
    real64_t crtime;
    uint32_t cframe;
    uint32_t empty;
};

struct _evbind_t
{
    void *obj_notify;
    void *obj_edit;
    const char_t *objtype_notif;
    const char_t *objtype_edit;
    uint16_t offset_edit;
    uint16_t size_edit;
};

#define GuiComponentPtr(ptr) ((GuiComponent *)(ptr))
#define ViewPtr(ptr) ((View *)(ptr))

#endif
