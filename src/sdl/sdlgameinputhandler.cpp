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

#include <SDL2/SDL.h>

#include "sdl/sdlgameinputhandler.hpp"
#include "settings.hpp"

/* This should be in the same order as the enum, so that can be used
 * as an index */
GameInputHandler::KeyAssignment SDLGameInputHandler::keys_array[] = {
    { KeyUp, gd_sdl_key_up, &GameInputHandler::up_k },
    { KeyDown, gd_sdl_key_down, &GameInputHandler::down_k },
    { KeyLeft, gd_sdl_key_left, &GameInputHandler::left_k },
    { KeyRight, gd_sdl_key_right, &GameInputHandler::right_k },
    { KeyFire1, gd_sdl_key_fire_1, &GameInputHandler::fire1_k },
    { KeyFire2, gd_sdl_key_fire_2, &GameInputHandler::fire2_k },
    { KeySuicide, gd_sdl_key_suicide, &GameInputHandler::suicide },
    { KeyFastForward, gd_sdl_key_fast_forward, &GameInputHandler::fast_forward },
    { KeyStatusBar, gd_sdl_key_status_bar, &GameInputHandler::alternate_status },
    { KeyRestartLevel, gd_sdl_key_restart_level, &GameInputHandler::restart_k },
};


char const *SDLGameInputHandler::get_key_name_from_keycode(int gfxlib_keycode) {
    return SDL_GetKeyName(SDL_Keycode(gfxlib_keycode));
}


GameInputHandler::KeyAssignment const &SDLGameInputHandler::get_key(Keys keyindex) const {
    return keys_array[keyindex];
}
