/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osimglist.inl
 *
 */

/* OSImage-HIMAGELIST binding */

#include "osgui_win.ixx"
#include <sewer/nowarn.hxx>
#include <Commctrl.h>
#include <sewer/warn.hxx>

#define HIMAGELIST_CREATED 1
#define HIMAGELIST_DELETED 2
#define HIMAGELIST_REORDER 4

__EXTERN_C

OSImgList *_osimglist_create(const uint32_t height);

void _osimglist_destroy(OSImgList **imglist);

int _osimglist_find(OSImgList *imglist, const Image *image);

int _osimglist_add(OSImgList *imglist, const Image *image, uint8_t *result);

void _osimglist_replace(OSImgList *imglist, const int index, const Image *image);

void _osimglist_delete(OSImgList *imglist, const int index, uint8_t *result);

uint32_t _osimglist_num_elems(const OSImgList *imglist);

HIMAGELIST _osimglist_hlist(const OSImgList *imglist);

uint32_t _osimglist_width(const OSImgList *imglist);

uint32_t _osimglist_height(const OSImgList *imglist);

__END_C
