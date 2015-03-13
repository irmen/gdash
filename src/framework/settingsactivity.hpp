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

#ifndef _GD_SETTINGSACTIVITY
#define _GD_SETTINGSACTIVITY

#include <vector>
#include <string>

#include "framework/app.hpp"

class Command;
class Setting;

class SettingsActivity: public Activity {
public:
    SettingsActivity(App *app, Setting *settings_data);
    ~SettingsActivity();
    void load_themes();
    virtual void keypress_event(KeyCode keycode, int gfxlib_keycode);
    virtual void redraw_event();

private:
    Setting *settings;
    unsigned numsettings, numpages, current, yd;
    std::vector<int> y1;
    std::vector<std::string> themes;
    int themenum;
    bool restart;
};

#endif