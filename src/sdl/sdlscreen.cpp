/*
 * Copyright (c) 2007-2013, Czirkos Zoltan http://code.google.com/p/gdash/
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:

 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "config.h"

#include <stdexcept>
#include <memory>
#include <SDL2/SDL_image.h>

#include "sdl/sdlscreen.hpp"
#include "sdl/sdlpixbuf.hpp"
#include "gfx/pixbuffactory.hpp"

#include "misc/logger.hpp"
#include "settings.hpp"


SDLScreen::SDLScreen(PixbufFactory &pixbuf_factory)
    : SDLAbstractScreen(pixbuf_factory)
    , window(NULL)
    , renderer(NULL)
    , texture(NULL) {
}


SDLScreen::~SDLScreen() {
    if (texture)
        SDL_DestroyTexture(texture);
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window)
        SDL_DestroyWindow(window);
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
}


/** @todo can this be called multiple times? if so, renderer, surface etc should be destroyed first */
void SDLScreen::configure_size() {
    /* close window, if already exists, to create a new one */
    if (SDL_WasInit(SDL_INIT_VIDEO))
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    /* init screen */
    SDL_InitSubSystem(SDL_INIT_VIDEO);

    /* create screen */
    surface = SDL_CreateRGBSurface(0, w, h, 32, Pixbuf::rmask, Pixbuf::gmask, Pixbuf::bmask, Pixbuf::amask);
    if (gd_fullscreen)
        window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
    else
        window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
    if (!window)
        throw ScreenConfigureException("cannot initialize sdl video");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderSetLogicalSize(renderer, w, h);
    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, w, h);
    
    /* do not show mouse cursor */
    SDL_ShowCursor(SDL_DISABLE);
    /* warp mouse pointer so cursor cannot be seen, if the above call did nothing for some reason */
    SDL_WarpMouseInWindow(window, w - 1, h - 1);

    /* icon & title */
    SDL_RWops *rwop = SDL_RWFromConstMem(Screen::gdash_icon_32_png, Screen::gdash_icon_32_size);
    SDL_Surface *icon = IMG_Load_RW(rwop, 1);  // 1 = automatically closes rwop
    SDL_SetWindowIcon(window, icon);
    SDL_FreeSurface(icon);
    set_title("GDash");
}


void SDLScreen::set_title(char const *title) {
    SDL_SetWindowTitle(window, title);
}


bool SDLScreen::must_redraw_all_before_flip() const {
    return false;
}


void SDLScreen::flip() {
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->w * sizeof (Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}


Pixmap *SDLScreen::create_pixmap_from_pixbuf(Pixbuf const &pb, bool keep_alpha) const {
    SDLPixbuf const &sdlpb = static_cast<SDLPixbuf const &>(pb);
    SDL_Surface *newsurface = SDL_ConvertSurface(sdlpb.get_surface(), surface->format, 0);
    return new SDLPixmap(newsurface);
}
