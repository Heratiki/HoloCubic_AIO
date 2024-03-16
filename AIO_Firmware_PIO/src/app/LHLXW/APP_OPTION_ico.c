/*******************************************************************************
 * Size: 30 px
 * Bpp: 4
 * Opts:
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef APP_OPTION_ICO
#define APP_OPTION_ICO 1
#endif

#if APP_OPTION_ICO

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E60D "" */
    0x0, 0x0, 0x2, 0x55, 0x20, 0x0, 0x0, 0x1,
    0x44, 0x20, 0x0, 0x0, 0x0, 0x3, 0xcf, 0xee,
    0xfc, 0x30, 0x3, 0xbf, 0xfe, 0xfc, 0x30, 0x0,
    0x0, 0x4f, 0x92, 0x0, 0x29, 0xf5, 0x5f, 0xa2,
    0x0, 0x29, 0xf4, 0x0, 0x1, 0xe7, 0x0, 0x0,
    0x0, 0x7f, 0xf7, 0x0, 0x0, 0x0, 0x7f, 0x20,
    0x9, 0xc0, 0x0, 0x0, 0x0, 0x4, 0x40, 0x0,
    0x0, 0x0, 0xc, 0x90, 0xf, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xf0,
    0x2f, 0x10, 0x0, 0x0, 0x9, 0xa0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xf2, 0x3f, 0x0, 0x0, 0x0,
    0x2f, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3,
    0x1f, 0x20, 0x0, 0x0, 0x9c, 0xe7, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xf2, 0xd, 0x70, 0x0, 0x2,
    0xf4, 0x8d, 0x0, 0x0, 0x0, 0x0, 0x7, 0xe0,
    0x6, 0xe, 0xff, 0xff, 0xc0, 0x2f, 0x30, 0x6f,
    0xff, 0xff, 0xe0, 0x50, 0x0, 0x96, 0x44, 0x44,
    0x10, 0xc, 0x90, 0xe8, 0x44, 0x44, 0x69, 0x0,
    0x0, 0x2e, 0xa0, 0x0, 0x0, 0x6, 0xe7, 0xe0,
    0x0, 0xa, 0xe2, 0x0, 0x0, 0x2, 0xe9, 0x0,
    0x0, 0x1, 0xff, 0x60, 0x0, 0xae, 0x20, 0x0,
    0x0, 0x0, 0x3f, 0x90, 0x0, 0x0, 0xae, 0x0,
    0x9, 0xe3, 0x0, 0x0, 0x0, 0x0, 0x3, 0xf9,
    0x0, 0x0, 0x12, 0x0, 0x9f, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4f, 0x90, 0x0, 0x0, 0x9,
    0xf3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xf9, 0x0, 0x0, 0x9f, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4f, 0x90, 0x9, 0xf3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xfa, 0xaf, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3e, 0xe3, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+E61D "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4e, 0xee, 0xee, 0xee,
    0xee, 0xee, 0xee, 0xee, 0xee, 0xe2, 0x0, 0x0,
    0xc4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5e, 0x20, 0x0, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x54, 0xe2, 0x0,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xc0, 0x4e, 0x20, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xd0, 0x5, 0xe2,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xee, 0xee, 0xea, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x0,
    0x10, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x6, 0xe0, 0x0, 0xc, 0x2d,
    0x60, 0x0, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x7d,
    0x20, 0x0, 0x6b, 0x1, 0xd7, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x9, 0xc1, 0x0, 0x1, 0xe2, 0x0,
    0x1c, 0x90, 0x0, 0x2c, 0xe1, 0x0, 0x9f, 0x20,
    0x0, 0x9, 0x90, 0x0, 0x2, 0xfa, 0x0, 0x2c,
    0xe1, 0x0, 0x7, 0xd2, 0x0, 0x2e, 0x10, 0x0,
    0x2d, 0x70, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x5e,
    0x30, 0xb6, 0x0, 0x2, 0xe5, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x4, 0xd4, 0xd0, 0x0, 0xd,
    0x40, 0x0, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x0,
    0x1, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2c, 0xe1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2c, 0xc5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6a,
    0x3c, 0xee, 0xee, 0xed, 0xa, 0xb, 0xee, 0xee,
    0xee, 0xee, 0xee, 0xb1,

    /* U+E62B "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xe9, 0xbd, 0x30, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xda,
    0x10, 0x5, 0xea, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x9d, 0x40, 0x0, 0x0,
    0x8, 0xe6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5e, 0x80, 0x0, 0x0, 0x0, 0x0, 0x2c,
    0xc3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2b, 0xc2,
    0x0, 0x15, 0x0, 0x0, 0x0, 0x0, 0x5e, 0x90,
    0x0, 0x0, 0x0, 0x8, 0xe6, 0x0, 0x0, 0x8f,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x9e, 0x50, 0x0,
    0x4, 0xda, 0x10, 0x0, 0x0, 0x28, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xcb, 0x20, 0x3f, 0xe1,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x40, 0x0,
    0x0, 0x0, 0x2f, 0xf0, 0x1f, 0x8e, 0x60, 0x0,
    0x0, 0x0, 0x0, 0xe, 0xf0, 0x0, 0x0, 0x8,
    0xe7, 0xe0, 0x1e, 0x2, 0xcb, 0x20, 0x0, 0x0,
    0x0, 0x4, 0x50, 0x0, 0x4, 0xda, 0x11, 0xe0,
    0x1e, 0x0, 0x6, 0xe7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xad, 0x40, 0x1, 0xe0, 0x1e, 0x0,
    0x0, 0x1b, 0xd3, 0x0, 0x0, 0x0, 0x0, 0x6e,
    0x80, 0x5, 0x1, 0xe0, 0x1e, 0x0, 0x0, 0x0,
    0x5e, 0x90, 0x0, 0x0, 0x2c, 0xc2, 0x0, 0x6f,
    0x71, 0xe0, 0x1e, 0x0, 0x0, 0x0, 0x1, 0x9e,
    0x40, 0x8, 0xe6, 0x0, 0x0, 0x17, 0x11, 0xe0,
    0x1e, 0x0, 0x0, 0x0, 0x0, 0x4, 0xdf, 0xea,
    0x10, 0x0, 0x0, 0x0, 0x1, 0xe0, 0x1e, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xe0, 0x1e, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0x30, 0x0, 0x1, 0x61, 0x0,
    0x1, 0xe0, 0x1e, 0x0, 0x0, 0x2e, 0x40, 0x0,
    0xd, 0x30, 0x0, 0x8, 0xf8, 0x0, 0x1, 0xe0,
    0x1e, 0x0, 0x0, 0x1e, 0x40, 0x0, 0xd, 0x30,
    0x0, 0x1, 0x71, 0x0, 0x1, 0xe0, 0x1f, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xd, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xf0, 0x1f, 0x70, 0x0, 0x0,
    0x0, 0x0, 0xd, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x1b, 0xf0, 0x1, 0xbc, 0x30, 0x0, 0x0, 0x0,
    0xd, 0x30, 0x17, 0x10, 0x0, 0x6, 0xe7, 0x0,
    0x0, 0x5, 0xe9, 0x0, 0x0, 0x0, 0xd, 0x30,
    0x7f, 0x60, 0x3, 0xcb, 0x20, 0x0, 0x0, 0x0,
    0x19, 0xe4, 0x0, 0x0, 0xd, 0x30, 0x15, 0x0,
    0x8e, 0x50, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3d,
    0xa1, 0x0, 0xd, 0x30, 0x0, 0x4e, 0x91, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7e, 0x60,
    0xd, 0x30, 0x1a, 0xd3, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xcc, 0x2d, 0x36,
    0xe7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xef, 0xfb, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xb0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+E630 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x59, 0xaa, 0xaa, 0xaa,
    0x95, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8b, 0x61, 0x0, 0x0, 0x0, 0x16,
    0xb8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6b, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xb6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8,
    0x90, 0x0, 0x0, 0x0, 0x0, 0xa5, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5a,
    0x0, 0x0, 0x0, 0x9, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x90,
    0x0, 0x0, 0x67, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x76, 0x0,
    0x0, 0xb0, 0x0, 0x7, 0xba, 0xa9, 0x10, 0x0,
    0x2, 0x9a, 0xab, 0x60, 0x0, 0xb, 0x0, 0x8,
    0x40, 0x0, 0xa4, 0x0, 0x2, 0xa0, 0x0, 0x2a,
    0x10, 0x0, 0x58, 0x0, 0x4, 0x80, 0xb, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xb0, 0x56, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x65, 0x91, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x19, 0xa0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xa, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xa0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0xa0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xa, 0x82, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x28, 0x37, 0x0, 0x0, 0x0,
    0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x0,
    0x0, 0x0, 0x73, 0xb, 0x0, 0x0, 0x0, 0x8,
    0x20, 0x0, 0x0, 0x0, 0x2, 0x90, 0x0, 0x0,
    0x0, 0xb0, 0x5, 0x60, 0x0, 0x0, 0x2, 0xa0,
    0x0, 0x0, 0x0, 0xa, 0x30, 0x0, 0x0, 0x6,
    0x50, 0x0, 0xb0, 0x0, 0x0, 0x0, 0x5a, 0x30,
    0x0, 0x3, 0xa5, 0x0, 0x0, 0x0, 0x1b, 0x0,
    0x0, 0x3a, 0x0, 0x0, 0x0, 0x1, 0x8b, 0xee,
    0xb8, 0x10, 0x0, 0x0, 0x0, 0xa3, 0x0, 0x0,
    0x5, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9, 0x50, 0x0, 0x0, 0x0,
    0x79, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x97, 0x0, 0x0, 0x0, 0x0, 0x4,
    0xb2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2b, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2a,
    0x91, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0xa2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3a,
    0xa6, 0x20, 0x0, 0x2, 0x6a, 0xa3, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x15,
    0x8a, 0xaa, 0xa8, 0x51, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+E661 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x8b, 0xcd,
    0xc9, 0x61, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x19, 0xff, 0xb9, 0x77, 0x9b,
    0xff, 0xa3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x8, 0xfd, 0x50, 0x0, 0x0, 0x0, 0x5,
    0xdf, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xce, 0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0xee, 0x30, 0x0, 0x0, 0x0, 0x0, 0x3e, 0xc1,
    0x0, 0x0, 0x6d, 0xff, 0xd6, 0x0, 0x0, 0x1c,
    0xf5, 0x0, 0x0, 0x0, 0x3, 0xf9, 0x0, 0x0,
    0xa, 0xfb, 0x77, 0xbf, 0x90, 0x0, 0x0, 0x9f,
    0x50, 0x0, 0x0, 0x2e, 0x80, 0x0, 0x0, 0x5f,
    0x70, 0x0, 0x7, 0xf5, 0x0, 0x0, 0x9, 0xf4,
    0x0, 0x0, 0xda, 0x0, 0x0, 0x0, 0xcc, 0x0,
    0x0, 0x0, 0xcc, 0x0, 0x0, 0x0, 0xaf, 0x20,
    0xa, 0xc0, 0x0, 0x0, 0x0, 0xe7, 0x0, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x0, 0xc, 0xd0, 0x2f,
    0x70, 0x0, 0x0, 0x0, 0xe7, 0x0, 0x0, 0x0,
    0x8e, 0x0, 0x0, 0x0, 0x7, 0xf5, 0x8, 0xf4,
    0x0, 0x0, 0x0, 0xac, 0x0, 0x0, 0x0, 0xda,
    0x0, 0x0, 0x0, 0x4f, 0xb0, 0x0, 0xaf, 0x40,
    0x0, 0x0, 0x3f, 0x80, 0x0, 0x9, 0xf3, 0x0,
    0x0, 0x4, 0xfd, 0x0, 0x0, 0xb, 0xf4, 0x0,
    0x0, 0x6, 0xfd, 0x88, 0xdf, 0x60, 0x0, 0x0,
    0x4f, 0xc1, 0x0, 0x0, 0x0, 0xaf, 0x70, 0x0,
    0x0, 0x29, 0xcc, 0x92, 0x0, 0x0, 0x8, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x8, 0xfb, 0x10, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xbf, 0xa0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4e, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x8f, 0xf5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x8f, 0xf9, 0x41, 0x0,
    0x15, 0xaf, 0xfa, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x7c, 0xff, 0xff, 0xff,
    0xe8, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x14, 0x56, 0x42, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 480, .box_w = 24, .box_h = 22, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 264, .adv_w = 480, .box_w = 24, .box_h = 31, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 636, .adv_w = 480, .box_w = 28, .box_h = 31, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1070, .adv_w = 480, .box_w = 30, .box_h = 31, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1535, .adv_w = 480, .box_w = 30, .box_h = 19, .ofs_x = 0, .ofs_y = 1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x10, 0x1e, 0x23, 0x54
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 58893, .range_length = 85, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR >= 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR >= 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t APP_OPTION_ico = {
#else
lv_font_t APP_OPTION_ico = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 31,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if APP_OPTION_ICO*/

