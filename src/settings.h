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
#ifndef _GD_SETTINGS_H
#define _GD_SETTINGS_H
#include <glib.h>

typedef enum _scaling_type {
	GD_SCALING_ORIGINAL,
	GD_SCALING_2X,
	GD_SCALING_2X_BILINEAR,	/* 2x with interpolation */
	GD_SCALING_2X_SCALE2X,	/* 2x with scale2x algorithm */
	GD_SCALING_3X,
	GD_SCALING_3X_BILINEAR,	/* 3x with interpolation */
	GD_SCALING_3X_SCALE3X,	/* 3x with scale3x */
	GD_SCALING_4X,
	GD_SCALING_4X_BILINEAR,	/* 4x with interpolation */
	GD_SCALING_4X_SCALE4X,	/* 4x with scale2x applied twice */
	GD_SCALING_MAX,
} GdScalingType;

extern const gchar *gd_scaling_name[];
extern const int gd_scaling_scale[];

extern const gchar *gd_languages_names[];

/* command line parameters */
extern int gd_param_cave, gd_param_level, gd_param_internal;
extern int gd_param_license;
extern char **gd_param_cavenames;

/* editor settings */
extern gboolean gd_game_view;	/* show animated cells instead of arrows & ... */
extern gboolean gd_colored_objects;	/* show objects with different color */
extern gboolean gd_show_object_list;	/* show object list in editor */
extern gboolean gd_show_test_label;	/* label with cave variables in tests */

extern int gd_editor_window_width;	/* window size */
extern int gd_editor_window_height;	/* window size */

extern int gd_language;

/* settings */
extern gboolean gd_easy_play;
extern gboolean gd_time_min_sec;
extern gboolean gd_all_caves_selectable;
extern gboolean gd_import_as_all_caves_selectable;
extern gboolean gd_mouse_play;
extern gboolean gd_random_colors;
extern gboolean gd_show_preview;
extern gboolean gd_allow_dirt_mod;
extern gboolean gd_use_bdcff_highscore;
extern gboolean gd_show_name_of_game;

extern char *gd_theme;

extern GdScalingType gd_cell_scale_game;
extern gboolean gd_pal_emulation_game;
extern GdScalingType gd_cell_scale_editor;
extern gboolean gd_pal_emulation_editor;

extern gboolean gd_sdl_fullscreen;
extern GdScalingType gd_sdl_scale;
extern char *gd_sdl_theme;
extern gboolean gd_sdl_pal_emulation;

extern gboolean gd_sdl_sound;
extern gboolean gd_sdl_16bit_mixing;
extern gboolean gd_sdl_44khz_mixing;
extern gboolean gd_classic_sound;

extern int gd_pal_emu_scanline_shade;		/* in percent */
extern gboolean gd_even_line_pal_emu_vertical_scroll;
extern gboolean gd_fine_scroll;
extern int gd_c64_palette;
extern int gd_atari_palette;


/* gdash directories */
extern char *gd_user_config_dir;
extern char *gd_system_data_dir;
extern char *gd_system_caves_dir;
extern char *gd_system_sound_dir;
extern char *gd_system_music_dir;

/* init settings (directories), and load language files */
void gd_settings_init_dirs();
void gd_settings_set_locale();
void gd_settings_init_translation();

/* settings loading and saving */
void gd_save_settings();
void gd_load_settings();

/* command line arguments parsing */
GOptionContext *gd_option_context_new();

#endif

