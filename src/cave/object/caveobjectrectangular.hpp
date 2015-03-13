/*
 * Copyright (c) 2007-2013, Czirkos Zoltan http://code.google.com/p/gdash/
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef _GD_CAVEOBJECTRECTANGULAR
#define _GD_CAVEOBJECTRECTANGULAR

#include "config.h"

#include "cave/object/caveobject.hpp"

/** Rectangular base class for all rectangular cave objects */
class CaveRectangular : public CaveObject {
protected:
    Coordinate p1, p2;

public:
    CaveRectangular(CaveObject::Type type, Coordinate _p1, Coordinate _p2);
    CaveRectangular(CaveObject::Type type): CaveObject(type) {}

public:
    virtual void create_drag(Coordinate current, Coordinate displacement);
    virtual void move(Coordinate current, Coordinate displacement);
    virtual void move(Coordinate displacement);
    virtual std::string get_coordinates_text() const;
};


#endif
