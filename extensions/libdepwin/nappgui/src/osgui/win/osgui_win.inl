/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui_win.inl
 *
 */

/* Operating system native gui */

#include "osgui_win.ixx"

__EXTERN_C

HINSTANCE _osgui_instance(void);

BOOL _osgui_hit_test(HWND hwnd);

uint16_t _osgui_unique_child_id(void);

void _osgui_add_accelerator(BYTE fVirt, WORD key, WORD cmd, HWND hwnd);

void _osgui_remove_accelerator(WORD cmd);

void _osgui_change_accelerator(BYTE fVirt, WORD key, WORD cmd);

HACCEL _osgui_accel_table(void);

HWND _osgui_hwnd_accelerator(WORD cmd);

LRESULT _osgui_nccalcsize(HWND hwnd, WPARAM wParam, LPARAM lParam, bool_t expand, INT ypadding, RECT *border);

LRESULT _osgui_ncpaint(HWND hwnd, const bool_t focused, const RECT *border, HBRUSH padding_bgcolor);

void _osgui_frame_without_shadows(const HWND hwnd, RECT *rect);

vkey_t _osgui_vkey(const WORD key);

uint32_t _osgui_modifiers(void);

extern const WORD kVIRTUAL_KEY[];
extern uint32_t kNUM_VKEYS;
extern HWND kDEFAULT_PARENT_WINDOW;
extern HCURSOR kNORMAL_ARROW_CURSOR;
extern HCURSOR kSIZING_HORIZONTAL_CURSOR;
extern HCURSOR kSIZING_VERTICAL_CURSOR;
extern HBRUSH kCHESSBOARD_BRUSH;
extern const TCHAR *kWINDOW_CLASS;
extern const TCHAR *kVIEW_CLASS;
extern const TCHAR *kRICHEDIT_CLASS;
extern unicode_t kWINDOWS_UNICODE;
extern int kLOG_PIXY_GUI;
extern LONG kTWIPS_PER_PIXEL_GUI;

__END_C
