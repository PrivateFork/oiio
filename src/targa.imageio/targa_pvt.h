/*
  Copyright 2009 Larry Gritz and the other authors and contributors.
  All Rights Reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are
  met:
  * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
  * Neither the name of the software's owners nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  (This is the Modified BSD License)
*/

#ifndef TGA_PVT_H
#define TGA_PVT_H

#include <boost/cstdint.hpp>   // for the int*_t types



namespace TGA_pvt {

// IneQuation was here

enum tga_image_type {
    TYPE_NODATA         = 0,    ///< image with no data (why even spec it?)
    TYPE_PALETTED       = 1,    ///< paletted RGB
    TYPE_RGB            = 2,    ///< can include alpha
    TYPE_GRAY           = 3,    ///< can include alpha
    TYPE_PALETTED_RLE   = 9,    ///< same as PALETTED but run-length encoded
    TYPE_RGB_RLE        = 10,   ///< same as RGB but run-length encoded
    TYPE_GRAY_RLE       = 11    ///< same as GRAY but run-length encoded
};

enum tga_flags {
    FLAG_X_FLIP   = 0x10,   ///< right-left image
    FLAG_Y_FLIP   = 0x20    ///< top-down image
};

/// Targa file header.
///
typedef struct {
    uint8_t idlen;              ///< image comment length
    uint8_t cmap_type;          ///< palette type
    uint8_t type;               ///< image type (see tga_image_type)
    uint16_t cmap_first;        ///< offset to first entry
    uint16_t cmap_length;       ///<
    uint8_t cmap_size;          ///< palette size
    uint16_t x_origin;          ///<
    uint16_t y_origin;          ///<
    uint16_t width;             ///< image width
    uint16_t height;            ///< image height
    uint8_t bpp;                ///< bits per pixel
    uint8_t attr;               ///< attribs (alpha bits and \ref tga_flags)
} tga_header;

};  // namespace TGA_pvt



#endif // TGA_PVT_H