/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osimage.m
 *
 */

/* Apple OSX image support */

#include <sewer/nowarn.hxx>
#include <Cocoa/Cocoa.h>
#include <sewer/warn.hxx>
#include "draw2d_osx.ixx"

#include "image.inl"
#include "dctxh.h"
#include "pixbuf.h"
#include <core/buffer.h>
#include <core/heap.h>
#include <core/stream.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

#if defined(MAC_OS_VERSION_12_0) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_VERSION_12_0
#include <UniformTypeIdentifiers/UniformTypeIdentifiers.h>
#endif

/*---------------------------------------------------------------------------*/

void osimage_alloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

void osimage_dealloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_from_pixels(const uint32_t width, const uint32_t height, const pixformat_t format, const byte_t *pixel_data)
{
    BOOL has_alpha = NO;
    NSString *colour_space = NULL;
    NSInteger sampes_per_pixel = 0;
    NSInteger bits_per_pixel = 0;
    NSBitmapImageRep *irep = NULL;
    NSImage *image = NULL;

    switch (format)
    {
    case ekGRAY8:
        has_alpha = NO;
        colour_space = NSCalibratedWhiteColorSpace;
        sampes_per_pixel = 1;
        bits_per_pixel = 8;
        break;
    case ekRGB24:
        has_alpha = NO;
        colour_space = NSCalibratedRGBColorSpace;
        sampes_per_pixel = 3;
        bits_per_pixel = 24;
        break;
    case ekRGBA32:
        has_alpha = YES;
        colour_space = NSCalibratedRGBColorSpace;
        sampes_per_pixel = 4;
        bits_per_pixel = 32;
        break;
        cassert_default();
    }

    irep = [[NSBitmapImageRep alloc]
        /* Allocates memory for pixel data */
        initWithBitmapDataPlanes:nil
                      pixelsWide:(NSInteger)width
                      pixelsHigh:(NSInteger)height
                   bitsPerSample:8
                 samplesPerPixel:sampes_per_pixel
                        hasAlpha:has_alpha
                        isPlanar:NO
                  colorSpaceName:colour_space
                    bitmapFormat:(NSBitmapFormat)0
                     bytesPerRow:(NSInteger)width * (bits_per_pixel >> 3)
                    bitsPerPixel:bits_per_pixel];

    image = [[NSImage alloc] initWithSize:NSMakeSize((CGFloat)width, (CGFloat)height)];
    [image addRepresentation:irep];
    cassert([image retainCount] == 1);

    if (pixel_data != NULL)
    {
        unsigned char *planes[5];
        [irep getBitmapDataPlanes:planes];
        cassert_no_null(planes[0]);
        cassert(planes[1] == NULL);
        cassert(planes[2] == NULL);
        cassert(planes[3] == NULL);
        cassert(planes[4] == NULL);
        memcpy((void *)planes[0], (const void *)pixel_data, (size_t)(((NSUInteger)bits_per_pixel >> 3) * width * height));
    }

    [irep release];
    return (OSImage *)image;
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_from_data(const byte_t *data, const uint32_t size_in_bytes)
{
    NSData *ldata = NULL;
    NSImage *image = NULL;
    ldata = [NSData dataWithBytes /*NoCopy*/:(void *)data length:(NSUInteger)size_in_bytes];
    cassert_no_null(ldata);
    image = [[NSImage alloc] initWithData:ldata];
    cassert([[(NSImage *)image representations] count] == 1);
    cassert([[[(NSImage *)image representations] objectAtIndex:0] isKindOfClass:[NSBitmapImageRep class]]);

    /* NSImage size sometimes is not equal than bitmap size ¿? */
    {
        NSBitmapImageRep *irep = (NSBitmapImageRep *)[[(NSImage *)image representations] objectAtIndex:0];
        NSInteger pixels_wide = [irep pixelsWide];
        NSInteger pixels_high = [irep pixelsHigh];
        cassert([[image representations] count] == 1);
        [image setSize:NSMakeSize((CGFloat)pixels_wide, (CGFloat)pixels_high)];
    }

    return (OSImage *)image;
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_from_type(const char_t *file_type)
{
    NSString *nsfile_type = nil;
    NSImage *image = nil;
    cassert_no_null(file_type);

    if (strcmp(file_type, ".") == 0)
        nsfile_type = NSFileTypeForHFSTypeCode(kGenericFolderIcon);
    else
        nsfile_type = [NSString stringWithUTF8String:file_type];

        /* osimage_from_file 'NSIconRepImageRep' with 3 (more than 1) representations */
#if defined(MAC_OS_VERSION_12_0) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_VERSION_12_0
    {
        UTType *type = [UTType typeWithIdentifier:nsfile_type];
        if (type != nil)
            image = [[NSWorkspace sharedWorkspace] iconForContentType:type];
    }
#else
    image = [[NSWorkspace sharedWorkspace] iconForFileType:nsfile_type];
#endif

    if (image != nil)
        [image retain];

    return (OSImage *)image;
}

/*---------------------------------------------------------------------------*/

static NSBitmapImageRep *i_scale_bitmap(const NSBitmapImageRep *bitmap, const uint32_t width, const uint32_t height)
{
    NSBitmapImageRep *new_bitmap = NULL;
    CGImageRef dest_image = NULL;
    CGColorSpaceRef space = CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB);
    CGContextRef context = CGBitmapContextCreate(NULL, (size_t)width, (size_t)height, PARAM(bitsPerComponent, 8), PARAM(bytesPerRow, (size_t)(width * 4)), space, (CGBitmapInfo)kCGImageAlphaPremultipliedLast);
    CGImageRef src_image = [bitmap CGImage];
    CGRect rect = CGRectMake((CGFloat)0.f, (CGFloat)0.f, (CGFloat)width, (CGFloat)height);
    CGContextDrawImage(context, rect, src_image);
    dest_image = CGBitmapContextCreateImage(context);
    CGContextRelease(context);
    CGColorSpaceRelease(space);
    new_bitmap = [[NSBitmapImageRep alloc] initWithCGImage:dest_image];
    CGImageRelease(dest_image);
    return new_bitmap;
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_create_scaled(const OSImage *image, const uint32_t new_width, const uint32_t new_height)
{
    NSImage *src_image = (NSImage *)image;
    NSBitmapImageRep *src_bitmap, *dest_bitmap;
    NSImage *scaled_image = nil;
    cassert_no_null(src_image);
    cassert([[src_image representations] count] == 1);
    cassert([[[src_image representations] objectAtIndex:0] isKindOfClass:[NSBitmapImageRep class]]);
    src_bitmap = (NSBitmapImageRep *)[[(NSImage *)image representations] objectAtIndex:0];
    cassert_no_null(src_bitmap);
    dest_bitmap = i_scale_bitmap(src_bitmap, new_width, new_height);
    scaled_image = [[NSImage alloc] initWithSize:NSMakeSize((CGFloat)new_width, (CGFloat)new_height)];
    [scaled_image addRepresentation:dest_bitmap];
    cassert([scaled_image retainCount] == 1);
    [dest_bitmap release];
    return (OSImage *)scaled_image;
}

/*---------------------------------------------------------------------------*/

OSImage *osimage_from_context(DCtx **ctx)
{
    OSImage *image = nil;
    byte_t *pixdata = NULL;
    uint32_t width, height;
    cassert_no_null(ctx);
    cassert_no_null(*ctx);
    cassert_no_null((*ctx)->context);
    pixdata = (byte_t *)CGBitmapContextGetData((*ctx)->context);
    width = (uint32_t)CGBitmapContextGetWidth((*ctx)->context);
    height = (uint32_t)CGBitmapContextGetHeight((*ctx)->context);
    image = osimage_create_from_pixels(width, height, ekRGBA32, pixdata);
    heap_free(&pixdata, width * height * 4, "OSXBitmapContextData");
    dctx_destroy(ctx);
    return image;
}

/*---------------------------------------------------------------------------*/

void osimage_destroy(OSImage **image)
{
    cassert_no_null(image);
    cassert_no_null(*image);
    [(NSImage *)(*image) release];
    *image = NULL;
}

/*---------------------------------------------------------------------------*/

static bool_t i_gray_image(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp)
{
    uint32_t n = width * height, i = 0;
    for (i = 0; i < n; ++i)
    {
        if (data[0] != data[1] || data[0] != data[2])
            return FALSE;

        data += bpp;
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_has_alpha(const byte_t *data, const uint32_t width, const uint32_t height)
{
    uint32_t n = width * height, i = 0;
    for (i = 0; i < n; ++i)
    {
        if (data[3] != 255)
            return TRUE;

        data += 4;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static Pixbuf *i_bitmap_pixels(const byte_t *data, const uint32_t width, const uint32_t height, const uint32_t bpp, const pixformat_t format)
{
    Pixbuf *pixels = pixbuf_create(width, height, format);
    byte_t *pdata = pixbuf_data(pixels);
    register uint32_t n = width * height, i = 0;
    if (format == ekRGBA32)
    {
        cassert(bpp == 4);
        bmem_copy(pdata, data, n * 4);
    }
    else if (format == ekRGB24)
    {
        if (bpp == 3)
        {
            bmem_copy(pdata, data, n * 3);
        }
        else
        {
            cassert(bpp == 4);
            for (i = 0; i < n; ++i)
            {
                pdata[0] = data[0];
                pdata[1] = data[1];
                pdata[2] = data[2];
                pdata += 3;
                data += 4;
            }
        }
    }
    else
    {
        cassert(format == ekGRAY8);
        if (bpp == 1)
        {
            bmem_copy(pdata, data, n);
        }
        else
        {
            cassert(bpp == 4);
            for (i = 0; i < n; ++i)
            {
                pdata[0] = data[0];
                cassert(pdata[0] == data[1]);
                cassert(pdata[0] == data[2]);
                pdata += 1;
                data += bpp;
            }
        }
    }

    return pixels;
}

/*---------------------------------------------------------------------------*/

void osimage_info(const OSImage *image, uint32_t *width, uint32_t *height, pixformat_t *format, Pixbuf **pixels)
{
    NSBitmapImageRep *irep = nil;
    NSInteger pixels_wide = 0;
    NSInteger pixels_high = 0;
    NSInteger bits_per_pixel = 0;
    cassert_no_null(image);
    cassert([[(NSImage *)image representations] count] == 1);
    cassert([[[(NSImage *)image representations] objectAtIndex:0] isKindOfClass:[NSBitmapImageRep class]]);
    irep = (NSBitmapImageRep *)[[(NSImage *)image representations] objectAtIndex:0];
    cassert_no_null(irep);
    pixels_wide = [irep pixelsWide];
    pixels_high = [irep pixelsHigh];
    bits_per_pixel = [irep bitsPerPixel];
    ptr_assign(width, (uint32_t)pixels_wide);
    ptr_assign(height, (uint32_t)pixels_high);

    if (format != NULL || pixels != NULL)
    {
        pixformat_t lformat = ENUM_MAX(pixformat_t);
        unsigned char *pixel_data_planes[5] = {NULL, NULL, NULL, NULL, NULL};
        cassert([irep numberOfPlanes] == 1);

        [irep getBitmapDataPlanes:pixel_data_planes];

        if (bits_per_pixel == 8)
        {
            cassert([irep samplesPerPixel] == 1);
            lformat = ekGRAY8;
        }
        else if (bits_per_pixel == 24)
        {
            cassert([irep samplesPerPixel] == 3);
            if (i_gray_image((const byte_t *)pixel_data_planes[0], (uint32_t)pixels_wide, (uint32_t)pixels_high, 3) == TRUE)
                lformat = ekGRAY8;
            else
                lformat = ekRGB24;
        }
        else if (bits_per_pixel == 32)
        {
            cassert([irep samplesPerPixel] == 4 || [irep samplesPerPixel] == 3);
            if (i_has_alpha((const byte_t *)pixel_data_planes[0], (uint32_t)pixels_wide, (uint32_t)pixels_high) == TRUE)
                lformat = ekRGBA32;
            else if (i_gray_image((const byte_t *)pixel_data_planes[0], (uint32_t)pixels_wide, (uint32_t)pixels_high, 4) == TRUE)
                lformat = ekGRAY8;
            else
                lformat = ekRGB24;
        }

        ptr_assign(format, lformat);

        if (pixels != NULL)
        {
            if (lformat != ENUM_MAX(pixformat_t))
                *pixels = i_bitmap_pixels((const byte_t *)pixel_data_planes[0], (uint32_t)pixels_wide, (uint32_t)pixels_high, (uint32_t)(bits_per_pixel / 8), lformat);
            else
                *pixels = NULL;
        }
    }
}

/*---------------------------------------------------------------------------*/

static NSBitmapImageFileType i_codec(const codec_t codec)
{
#if defined(MAC_OS_X_VERSION_10_14) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_14
    switch (codec)
    {
    case ekJPG:
        return NSBitmapImageFileTypeJPEG;
    case ekPNG:
        return NSBitmapImageFileTypePNG;
    case ekBMP:
        return NSBitmapImageFileTypeBMP;
    case ekGIF:
        return NSBitmapImageFileTypeGIF;
        cassert_default();
    }
    return NSBitmapImageFileTypeJPEG;
#else
    switch (codec)
    {
    case ekJPG:
        return NSJPEGFileType;
    case ekPNG:
        return NSPNGFileType;
    case ekBMP:
        return NSBMPFileType;
    case ekGIF:
        return NSGIFFileType;
        cassert_default();
    }
    return NSJPEGFileType;
#endif
}

/*---------------------------------------------------------------------------*/

bool_t osimage_available_codec(const OSImage *image, const codec_t codec)
{
    /* macOS supports all codec_t formats */
    unref(image);
    unref(codec);
    return TRUE;
}

/*---------------------------------------------------------------------------*/

void osimage_write(const OSImage *image, const codec_t codec, Stream *stream)
{
    NSBitmapImageRep *irep = nil;
    NSBitmapImageFileType type = (NSBitmapImageFileType)1000;
    NSData *edata = NULL;
    cassert_no_null(image);
    cassert([[(NSImage *)image representations] count] == 1);
    cassert([[[(NSImage *)image representations] objectAtIndex:0] isKindOfClass:[NSBitmapImageRep class]]);
    irep = (NSBitmapImageRep *)[[(NSImage *)image representations] objectAtIndex:0];
    cassert_no_null(irep);
    type = i_codec(codec);
    edata = [irep representationUsingType:type properties:[NSDictionary dictionary]];
    cassert_no_null(edata);
    stm_write(stream, (const byte_t *)[edata bytes], (uint32_t)[edata length]);
    /*[edata release]; No release (NSApplication crash) */
}

/*---------------------------------------------------------------------------*/

void osimage_frames(const OSImage *image, uint32_t *num_frames, uint32_t *num_loops)
{
    NSBitmapImageRep *irep = nil;
    NSNumber *frames = nil;
    cassert_no_null(image);
    cassert_no_null(num_frames);
    unref(num_loops);
    cassert([[(NSImage *)image representations] count] == 1);
    irep = (NSBitmapImageRep *)[[(NSImage *)image representations] objectAtIndex:0];
    cassert_no_null(irep);
    frames = [irep valueForProperty:@"NSImageFrameCount"];
    if (frames != nil)
        *num_frames = (uint32_t)[frames intValue];
    else
        *num_frames = 1;
}

/*---------------------------------------------------------------------------*/

void osimage_frame(const OSImage *image, const uint32_t frame_index, real32_t *frame_length)
{
    NSBitmapImageRep *irep = nil;
    NSNumber *current_frame = nil;
    NSNumber *frame = nil;
    cassert_no_null(image);
    cassert_no_null(frame_length);
    cassert([[(NSImage *)image representations] count] == 1);
    irep = (NSBitmapImageRep *)[[(NSImage *)image representations] objectAtIndex:0];
    cassert_no_null(irep);
    current_frame = [irep valueForProperty:@"NSImageCurrentFrame"];
    [irep setProperty:NSImageCurrentFrame withValue:[NSNumber numberWithUnsignedInt:frame_index]];
    frame = [irep valueForProperty:@"NSImageCurrentFrameDuration"];

    if (current_frame != nil)
        [irep setProperty:NSImageCurrentFrame withValue:current_frame];

    if (frame != nil)
    {
        *frame_length = (real32_t)[frame floatValue];
    }
    else
    {
        cassert(FALSE);
        *frame_length = 1e8f;
    }
}

/*---------------------------------------------------------------------------*/

const void *osimage_native(const OSImage *image)
{
    return (const void *)image;
}

/*---------------------------------------------------------------------------*/

/*void osimage_set_frame(const OSImage *image, const uint32_t frame_index)
{
    NSBitmapImageRep *irep = nil;
    cassert_no_null(image);
    cassert([[(NSImage*)image representations] count] == 1);
    irep = (NSBitmapImageRep*)[[(NSImage*)image representations] objectAtIndex:0];
    cassert_no_null(irep);
    [irep setProperty:NSImageCurrentFrame withValue:[NSNumber numberWithUnsignedInt:frame_index]];
}*/

/*---------------------------------------------------------------------------*/

/*
void osimage_draw(const OSImage *image, void *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    NSRect rect = NSMakeRect((CGFloat)x, (CGFloat)y, (CGFloat)width, (CGFloat)height);
    unref(view);
#if defined (MAC_OS_X_VERSION_10_12) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_12
    [(NSImage*)image drawInRect:rect fromRect:NSZeroRect operation:NSCompositingOperationSourceOver fraction:1.0f];
#else
    [(NSImage*)image drawInRect:rect fromRect:NSZeroRect operation:NSCompositeSourceOver fraction:1.0f];
#endif
}
*/
