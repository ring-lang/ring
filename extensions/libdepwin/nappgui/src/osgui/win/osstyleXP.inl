/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osstyleXP.inl
 *
 */

/* Windows XP Styles */

#include <draw2d/win/draw2d_gdi.ixx>
#include <sewer/nowarn.hxx>
#include <uxtheme.h>
#if _MSC_VER > 1400
#include <vssym32.h>
#include <vsstyle.h>
#else
#include <tmschema.h>
#endif
#include <sewer/warn.hxx>

__EXTERN_C

void osstyleXP_init(void);

void osstyleXP_remove(void);

HTHEME osstyleXP_OpenTheme(HWND hwnd, LPCWSTR pszClassList);

BOOL osstyleXP_OpenThemeData(HWND hwnd, LPCWSTR pszClassList);

void osstyleXP_CloseTheme(HTHEME theme);

void osstyleXP_CloseThemeData(void);

void osstyleXP_GetThemeBackgroundContentRect(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pBoundingRect, RECT *pContentRect);

void osstyleXP_DrawThemeBackground2(HTHEME theme, int iPartId, int iStateId, HDC hdc, const RECT *rc);

void osstyleXP_DrawThemeBackground(HWND hwnd, HDC hdc, int iPartId, int iStateId, const BOOL draw_parent_bg, const RECT *rc, RECT *border);

void osstyleXP_DrawNonThemedButtonBackground(HWND hwnd, HDC hdc, BOOL has_focus, UINT state, const RECT *rc, RECT *border);

void osstyleXP_DrawThemeEdge(HDC hdc, int iPartId, int iStateId, const RECT *rc);

BOOL osstyleXP_HasThemeFont(HDC hdc, int iPartId, int iStateId, int iPropId);

void osstyleXP_DrawThemeText2(HTHEME theme, HDC hdc, int iPartId, int iStateId, const WCHAR *text, int num_chars, DWORD flags, const RECT *rc);

void osstyleXP_DrawThemeText(HDC hdc, int iPartId, int iStateId, const WCHAR *text, uint32_t num_chars, DWORD flags, const RECT *rc);

__END_C
