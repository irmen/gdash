/*
 * Copyright (c) 2007, 2008 Czirkos Zoltan <cirix@fw.hu>
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
#ifndef _GD_CAVESOUND_H
#define _GD_CAVESOUND_H

#include <glib.h>
#include "config.h"
#include "cave.h"

#ifdef GD_SOUND
gboolean gd_sound_is_looped(GdSound sound);
gboolean gd_sound_is_fake(GdSound sound);
gboolean gd_sound_is_classic(GdSound sound);
gboolean gd_sound_force_start(GdSound sound);
int gd_sound_get_channel(GdSound sound);
int gd_sound_get_precedence(GdSound sound);
gboolean gd_sound_classic_equivalent(GdSound sound);
#endif

void gd_cave_sound_db_init();
void gd_sound_play(Cave *cave, GdSound sound);


#endif
