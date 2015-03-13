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
#ifndef _GD_CAVE_H
#define _GD_CAVE_H

#include <glib.h>

#include "config.h"
#include "colors.h"


/******************************************
 *
 * BIG STRUCT HANDLING
 *
 */
/* possible types handled */
typedef enum _gd_type {
	/* not real types, only used by editor to build ui */
	GD_TAB,
	GD_LABEL,
	
	/* gd types */
	GD_TYPE_STRING,		/* static string, fixed array of characters */
	GD_TYPE_LONGSTRING,	/* long string which has its own notebook page in the editor */
	GD_TYPE_INT,
	GD_TYPE_RATIO,
	GD_TYPE_ELEMENT,
	GD_TYPE_BOOLEAN,
	GD_TYPE_PROBABILITY,
	GD_TYPE_COLOR,
	GD_TYPE_EFFECT,
	GD_TYPE_DIRECTION,
	GD_TYPE_SCHEDULING,
} GdType;

enum _gd_property_flags {
	GD_ALWAYS_SAVE=1<<0,
	GD_DONT_SAVE=1<<1,
	GD_DONT_SHOW_IN_EDITOR=1<<2,
	GD_SHOW_LEVEL_LABEL=1<<3,
};

typedef struct {
	char *identifier;	/* bdcff identifier */
	GdType type;	/* data type */
	int flags;		/* flags for bdcff saving/loading */
	char *name;		/* name in editor */
	int offset;		/* byte offset in a Cave structure. use the CAVE_OFFSET macro */
	int count;		/* size of array; usually 1, for non-arrays. */
	char *tooltip;	/* tooltip text in editor */
	int min, max;	/* integers have minimum and maximum */
} GdStructDescriptor;

typedef struct _gd_property_default {
	int offset;	/* data offset (bytes) in a cave structure */
	int defval;	/* default value, converted to int. if type is a float, *1000000 */
	
	int property_index;	/* index in gd_cave_properties; created at runtime */
} GdPropertyDefault;



/* these define the number of the cells in the png file */
#define NUM_OF_CELLS_X 8
#define NUM_OF_CELLS_Y 38

/* +72: placeholder for cells which are rendered by the game; for example diamond+arrow = falling diamond */
#define NUM_OF_CELLS (NUM_OF_CELLS_X*NUM_OF_CELLS_Y+72)




extern const GdColor gd_flash_color;
extern const GdColor gd_select_color;










/* These are the objects in caves. */
typedef enum _element {
	O_SPACE,
	O_DIRT,
	O_DIRT_SLOPED_UP_RIGHT,
	O_DIRT_SLOPED_UP_LEFT,
	O_DIRT_SLOPED_DOWN_LEFT,
	O_DIRT_SLOPED_DOWN_RIGHT,
	O_DIRT2,
	O_BRICK,
	O_BRICK_SLOPED_UP_RIGHT,
	O_BRICK_SLOPED_UP_LEFT,
	O_BRICK_SLOPED_DOWN_LEFT,
	O_BRICK_SLOPED_DOWN_RIGHT,
	O_BRICK_NON_SLOPED,
	O_MAGIC_WALL,
	O_PRE_OUTBOX,
	O_OUTBOX,
	O_PRE_INVIS_OUTBOX,
	O_INVIS_OUTBOX,
	O_STEEL,
	O_STEEL_SLOPED_UP_RIGHT,
	O_STEEL_SLOPED_UP_LEFT,
	O_STEEL_SLOPED_DOWN_LEFT,
	O_STEEL_SLOPED_DOWN_RIGHT,
	O_STEEL_EXPLODABLE,
	O_STEEL_EATABLE,
	O_BRICK_EATABLE,
	O_STONE,
	O_STONE_F,
	O_MEGA_STONE,
	O_MEGA_STONE_F,
	O_DIAMOND,
	O_DIAMOND_F,
	O_BLADDER_SPENDER,
	O_INBOX,
	O_H_EXPANDING_WALL,
	O_V_EXPANDING_WALL,
	O_EXPANDING_WALL,
	O_EXPANDING_WALL_SWITCH,
	O_CREATURE_SWITCH,
	O_BITER_SWITCH,
	O_ACID,
	O_FALLING_WALL,
	O_FALLING_WALL_F,
	O_BOX,
	O_TIME_PENALTY,
	O_GRAVESTONE,
	O_STONE_GLUED,
	O_DIAMOND_GLUED,
	O_DIAMOND_KEY,
	O_TRAPPED_DIAMOND,
	O_CLOCK,
	O_DIRT_GLUED,
	O_KEY_1,
	O_KEY_2,
	O_KEY_3,
	O_DOOR_1,
	O_DOOR_2,
	O_DOOR_3,
	
	O_POT,
	O_GRAVITY_SWITCH,
	O_PNEUMATIC_HAMMER,
	O_TELEPORTER,
	O_SKELETON,
	O_WATER,
	O_WATER_1,
	O_WATER_2,
	O_WATER_3,
	O_WATER_4,
	O_WATER_5,
	O_WATER_6,
	O_WATER_7,
	O_WATER_8,
	O_WATER_9,
	O_WATER_10,
	O_WATER_11,
	O_WATER_12,
	O_WATER_13,
	O_WATER_14,
	O_WATER_15,
	O_WATER_16,
	O_COW_1,
	O_COW_2,
	O_COW_3,
	O_COW_4,
	O_COW_ENCLOSED_1,
	O_COW_ENCLOSED_2,
	O_COW_ENCLOSED_3,
	O_COW_ENCLOSED_4,
	O_COW_ENCLOSED_5,
	O_COW_ENCLOSED_6,
	O_COW_ENCLOSED_7,
	O_WALLED_DIAMOND,
	O_WALLED_KEY_1,
	O_WALLED_KEY_2,
	O_WALLED_KEY_3,

	O_AMOEBA,
	O_AMOEBA_2,
	O_SWEET,
	O_VOODOO,
	O_SLIME,
	O_BLADDER,
	O_BLADDER_1,
	O_BLADDER_2,
	O_BLADDER_3,
	O_BLADDER_4,
	O_BLADDER_5,
	O_BLADDER_6,
	O_BLADDER_7,
	O_BLADDER_8,

	O_WAITING_STONE,
	O_CHASING_STONE,
	O_GHOST,
	O_GUARD_1,
	O_GUARD_2,
	O_GUARD_3,
	O_GUARD_4,
	O_ALT_GUARD_1,
	O_ALT_GUARD_2,
	O_ALT_GUARD_3,
	O_ALT_GUARD_4,
	O_BUTTER_1,
	O_BUTTER_2,
	O_BUTTER_3,
	O_BUTTER_4,
	O_ALT_BUTTER_1,
	O_ALT_BUTTER_2,
	O_ALT_BUTTER_3,
	O_ALT_BUTTER_4,
	O_STONEFLY_1,
	O_STONEFLY_2,
	O_STONEFLY_3,
	O_STONEFLY_4,
	O_BITER_1,
	O_BITER_2,
	O_BITER_3,
	O_BITER_4,

	O_PRE_PL_1,
	O_PRE_PL_2,
	O_PRE_PL_3,
	O_PLAYER,
	O_PLAYER_BOMB,
	O_PLAYER_GLUED,
	O_PLAYER_STIRRING,
	
	O_BOMB,
	O_BOMB_TICK_1,
	O_BOMB_TICK_2,
	O_BOMB_TICK_3,
	O_BOMB_TICK_4,
	O_BOMB_TICK_5,
	O_BOMB_TICK_6,
	O_BOMB_TICK_7,
	
	O_NITRO_PACK,
	O_NITRO_PACK_F,
	O_NITRO_PACK_EXPLODE,
	
	O_PRE_CLOCK_1,
	O_PRE_CLOCK_2,
	O_PRE_CLOCK_3,
	O_PRE_CLOCK_4,
	O_PRE_DIA_1,
	O_PRE_DIA_2,
	O_PRE_DIA_3,
	O_PRE_DIA_4,
	O_PRE_DIA_5,
	O_EXPLODE_1,
	O_EXPLODE_2,
	O_EXPLODE_3,
	O_EXPLODE_4,
	O_EXPLODE_5,
	O_PRE_STONE_1,
	O_PRE_STONE_2,
	O_PRE_STONE_3,
	O_PRE_STONE_4,
	O_PRE_STEEL_1,
	O_PRE_STEEL_2,
	O_PRE_STEEL_3,
	O_PRE_STEEL_4,
	O_GHOST_EXPL_1,
	O_GHOST_EXPL_2,
	O_GHOST_EXPL_3,
	O_GHOST_EXPL_4,
	O_BOMB_EXPL_1,
	O_BOMB_EXPL_2,
	O_BOMB_EXPL_3,
	O_BOMB_EXPL_4,
	O_NITRO_EXPL_1,
	O_NITRO_EXPL_2,
	O_NITRO_EXPL_3,
	O_NITRO_EXPL_4,
	O_AMOEBA_2_EXPL_1,
	O_AMOEBA_2_EXPL_2,
	O_AMOEBA_2_EXPL_3,
	O_AMOEBA_2_EXPL_4,

	/* these are used internally for the pneumatic hammer, and should not be used in the editor! */
	/* (not even as an effect destination or something like that) */
	O_PLAYER_PNEUMATIC_LEFT,
	O_PLAYER_PNEUMATIC_RIGHT,
	O_PNEUMATIC_ACTIVE_LEFT,
	O_PNEUMATIC_ACTIVE_RIGHT,
	
	O_UNKNOWN,	/* unknown element imported or read from bdcff */
	O_NONE,		/* do not draw this element when creating cave; can be used, for example, to skip drawing a maze's path */

	O_MAX,	/* remembering last index: this should get an integer value which is 1 more than the one above. */

	/* fake elements to help drawing */
	O_FAKE_BONUS,
	O_OUTBOX_CLOSED,
	O_OUTBOX_OPEN,
	O_COVERED,
	O_PLAYER_LEFT,
	O_PLAYER_RIGHT,
	O_PLAYER_TAP,
	O_PLAYER_BLINK,
	O_PLAYER_TAP_BLINK,
	O_CREATURE_SWITCH_ON,
	O_EXPANDING_WALL_SWITCH_HORIZ,
	O_EXPANDING_WALL_SWITCH_VERT,
	O_GRAVITY_SWITCH_ACTIVE,

	O_QUESTION_MARK,
	O_EATABLE,
	O_DOWN_ARROW,
	O_LEFTRIGHT_ARROW,
	O_EVERYDIR_ARROW,
	O_GLUED,
	O_OUT,
	O_EXCLAMATION_MARK,

	SCANNED=0x100,
	COVERED=0x200,

	/* binary AND this to elements to get rid of properties above. */
	O_MASK = ~(SCANNED | COVERED)
} GdElement;





typedef enum _element_property {
	/* properties */
	P_SLOPED_LEFT = 1<<0,	/* stones and diamonds roll down to left on this */
	P_SLOPED_RIGHT = 1<<1,	/* stones and diamonds roll down to right on this */
	P_SLOPED_UP = 1<<2,
	P_SLOPED_DOWN = 1<<3,
	P_SLOPED = P_SLOPED_LEFT|P_SLOPED_RIGHT|P_SLOPED_UP|P_SLOPED_DOWN,			/* flag to say "any direction" */
	P_BLADDER_SLOPED = 1<<4,	/* element act sloped also for the bladder */
	
	P_AMOEBA_CONSUMES = 1<<5,		/* amoeba can eat this */
	P_DIRT = 1<<6,					/* it is dirt, or something similar (dirt2 or sloped dirt) */
	P_BLOWS_UP_FLIES = 1<<7,		/* flies blow up, if they touch this */

	P_EXPLODES_TO_SPACE = 1<<8,			/* explodes if hit by a rock */
	P_EXPLODES_TO_DIAMONDS = 1<<9,		/* explodes to diamonds if hit by a rock */
	P_EXPLODES_TO_STONES = 1<<10,		/* explodes to rocks if hit by a rock */
	P_EXPLODES_AS_NITRO = 1<<11,		/* explodes as nitro pack */
	P_EXPLODES=P_EXPLODES_TO_SPACE|P_EXPLODES_TO_DIAMONDS|P_EXPLODES_TO_STONES|P_EXPLODES_AS_NITRO,	/* explodes to something if hit */

	P_NON_EXPLODABLE = 1<<12,		/* selfexplaining */
	P_CCW = 1<<13,					/* this creature has a default counterclockwise rotation (for example, o_fire_1) */
	P_CAN_BE_HAMMERED = 1<<14,		/* can be broken by pneumatic hammer */
	P_VISUAL_EFFECT = 1<<15,		/* if the element can use a visual effect. used to check consistency of the code */
} GdElementProperties;







/* These are states of the magic wall. */
typedef enum _magic_wall_state {
	GD_MW_DORMANT=0,					/* Starting with this. */
	GD_MW_ACTIVE,					/* Boulder or diamond dropped into. */
	GD_MW_EXPIRED					/* Turned off after magic_wall_milling_time. */
} GdMagicWallState;

/* These are states of Player. */
typedef enum _player_state {
	GD_PL_NOT_YET=0,				/* Not yet living. Beginning of cave time. */
	GD_PL_LIVING,				/* Ok. */
	GD_PL_TIMEOUT,				/* Time is up */
	GD_PL_DIED,				/* Died. */
	GD_PL_EXITED				/* Exited the cave, proceed to next one */
} GdPlayerState;

/* States of amoeba */
typedef enum _amoeba_state {
	GD_AM_SLEEPING=0,		/* sleeping - not yet let out. */
	GD_AM_AWAKE,		/* living, growing */
	GD_AM_TOO_BIG,	/* grown too big, will convert to stones */
	GD_AM_ENCLOSED,	/* enclosed, will convert to diamonds */
} GdAmoebaState;

typedef enum _direction {
	/* not moving */
	MV_STILL=0,
	MV_THIS=0,

	/* directions */
	MV_UP=1,
	MV_UP_RIGHT=2,
	MV_RIGHT=3,
	MV_DOWN_RIGHT=4,
	MV_DOWN=5,
	MV_DOWN_LEFT=6,
	MV_LEFT=7,
	MV_UP_LEFT=8,

	/* to be able to type MV_TWICE+MV_DOWN, for example */
	MV_TWICE=8,

	/* directions * 2 */
	MV_UP_2=9,
	MV_UP_RIGHT_2=10,
	MV_RIGHT_2=11,
	MV_DOWN_RIGHT_2=12,
	MV_DOWN_2=13,
	MV_DOWN_LEFT_2=14,
	MV_LEFT_2=15,
	MV_UP_LEFT_2=16,
	
	MV_MAX,
} GdDirection;

typedef enum _sound {
	GD_S_NONE,

	GD_S_STONE,
	GD_S_NITRO,
	GD_S_FALLING_WALL,
	GD_S_EXPANDING_WALL,
	GD_S_WALL_REAPPEAR,
	GD_S_DIAMOND_RANDOM,	/* randomly select a diamond sound */
	GD_S_DIAMOND_1,
	GD_S_DIAMOND_2,
	GD_S_DIAMOND_3,
	GD_S_DIAMOND_4,
	GD_S_DIAMOND_5,
	GD_S_DIAMOND_6,
	GD_S_DIAMOND_7,
	GD_S_DIAMOND_8,
	GD_S_DIAMOND_COLLECT,
	GD_S_SKELETON_COLLECT,
	GD_S_PNEUMATIC_COLLECT,
	GD_S_BOMB_COLLECT,
	GD_S_CLOCK_COLLECT,
	GD_S_SWEET_COLLECT,
	GD_S_KEY_COLLECT,
	GD_S_DIAMOND_KEY_COLLECT,
	GD_S_SLIME,
	GD_S_ACID_SPREAD,
	GD_S_BLADDER_MOVE,
	GD_S_BLADDER_CONVERT,
	GD_S_BLADDER_SPENDER,
	GD_S_BITER_EAT,

	GD_S_DOOR_OPEN,
	GD_S_WALK_EARTH,
	GD_S_WALK_EMPTY,
	GD_S_STIRRING,
	GD_S_BOX_PUSH,
	GD_S_TELEPORTER,
	GD_S_TIMEOUT_1,
	GD_S_TIMEOUT_2,
	GD_S_TIMEOUT_3,
	GD_S_TIMEOUT_4,
	GD_S_TIMEOUT_5,
	GD_S_TIMEOUT_6,
	GD_S_TIMEOUT_7,
	GD_S_TIMEOUT_8,
	GD_S_TIMEOUT_9,
	GD_S_TIMEOUT,
	GD_S_EXPLOSION,
	GD_S_BOMB_EXPLOSION,
	GD_S_GHOST_EXPLOSION,
	GD_S_VOODOO_EXPLOSION,
	GD_S_NITRO_EXPLOSION,
	GD_S_BOMB_PLACE,
	GD_S_FINISHED,
	GD_S_SWITCH_BITER,
	GD_S_SWITCH_CREATURES,
	GD_S_SWITCH_GRAVITY,
	GD_S_SWITCH_EXPANDING,

	GD_S_AMOEBA,			/* loop */
	GD_S_MAGIC_WALL,		/* loop */
	GD_S_COVER,				/* loop */
	GD_S_PNEUMATIC_HAMMER,	/* loop */
	GD_S_WATER,				/* loop */
	GD_S_CRACK,
	GD_S_GRAVITY_CHANGE,
	GD_S_BONUS_LIFE,

	GD_S_MAX,
} GdSound;


/* ELEMENTS DESCRIPTION */
typedef struct _elements {
	GdElement element;		/* element number. for example O_DIRT */
	char *name;				/* name in editor, for example "Dirt". some have different names than their real engine meaning! */
	unsigned int properties;/* engine properties, like P_SLOPED or P_EXPLODES */
	char *filename;			/* name in bdcff file, like "DIRT" */
	char character;			/* character representation in bdcff file, like '.' */
	int image;				/* image in editor (index in cells.png) */
	int image_simple;		/* image for simple view  in editor, and for combo box (index in cells.png) */
	int image_game;			/* image for game. negative if animated */
	int ckdelay;			/* ckdelay ratio - how much time required for a c64 to process this element - in microseconds. */

	char *lowercase_name;	/* lowercase of translated name. for editor; generated inside the game. */
	char character_new;		/* character given automatically for elements which don't have one defined in original bdcff description */
} GdElements;

typedef char GdString[128];

typedef struct _highscore {
	GdString name;
	int score;
} GdHighScore;

enum _gd_demo_bits {
	GD_DEMO_MOVEMENT_SHIFT=0,
	GD_DEMO_MOVEMENT_MASK=0x0f,
	GD_DEMO_FIRE_SHIFT=4,
	GD_DEMO_FIRE_MASK=0x10,
	GD_DEMO_SUICIDE_SHIFT=5,
	GD_DEMO_SUICIDE_MASK=0x20,	
};

typedef struct _gd_cave_demo {
	int level;	/* demo for level n */
	guint32 seed;	/* seed the cave is to be rendered with */
	guint8 movements[4096];	/* movements. lower 4 bits: direction, bit 5: fire, bit 6: suicide. delimited with 0xff. */
	int movements_num;	/* number of movements so far */
} GdCaveDemo;

typedef enum _gd_scheduling {
	GD_SCHEDULING_MILLISECONDS,
	GD_SCHEDULING_BD1,
	GD_SCHEDULING_BD2,
	GD_SCHEDULING_PLCK,
	GD_SCHEDULING_CRDR,
	GD_SCHEDULING_BD1_ATARI,
	GD_SCHEDULING_BD2_PLCK_ATARI,
	GD_SCHEDULING_MAX
} GdScheduling;


typedef struct _gd_c64_random_generator {
	int rand_seed_1, rand_seed_2;
} GdC64RandomGenerator;

/*
	Structure holding all data belonging to a cave.
*/
#define GD_HIGHSCORE_NUM 20
typedef struct _cave {
	/* Defined by the editor. public data :) */
	GdString name;				/* Name of cave */
	GdString description;		/* Some words about the cave */
	GdString author;			/* Author */
	GdString difficulty;		/* difficulty of the game, for info purposes */
	GdString www;				/* link to author's webpage */
	GdString date;				/* date of creation */
	GdString remark;			/* some note */
	
	GString *notes;				/* a long description */

	GdString charset;			/* these are not used by gdash */
	GdString fontset;
	
	/* and this one the highscores */
	GdHighScore highscore[GD_HIGHSCORE_NUM];

	GHashTable *tags;			/* stores read-but-not-understood strings from bdcff, so we can save them later. */

	GdElement **map;			/* pointer to data for map, non-null if has a map */
	GList *objects;
	
	gboolean intermission;		/* is this cave an intermission? */
	gboolean intermission_instantlife;	/* one life extra, if the intermission is reached */
	gboolean intermission_rewardlife;	/* one life extra, if the intermission is successfully finished */
	gboolean selectable;			/* is this selectable as an initial cave for a game? */
	gboolean diagonal_movements;	/* are diagonal movements allowed? */
	GdElement snap_element;		/* snapping (press fire+move) usually leaves space behind, but can be other */
	gboolean short_explosions;		/* in >=1stb, diamond and creature explosions were of 5 stages */

	GdScheduling scheduling;	/* scheduling type; see above */
	gboolean pal_timing;		/* use faster seconds */

	gboolean active_is_first_found;	/* active player is the uppermost. */
	gboolean lineshift;				/* true is line shifting emulation, false is perfect borders emulation */
	gboolean border_scan_first_and_last;	/* if true, scans the first and last line of the border. false for plck */
	gboolean wraparound_objects;	/* if this is true, object drawing (cave rendering) will wraparound as well. */

	GdElement initial_fill;
	GdElement initial_border;
	GdElement random_fill[4];		/* Random fill elements. */
	int random_fill_probability[4];	/* Random fill, probability of each element. */

	int level_rand[5];			/* Random seed. */
	int level_diamonds[5];		/* Must collect diamonds, on level x */
	int level_speed[5];			/* Time between game cycles in ms */
	int level_ckdelay[5];		/* Timing in original game units */
	int level_time[5];			/* Available time, per level */
	int level_timevalue[5];		/* points for each second remaining, when exiting level */
	
	int max_time;			/* the maximum time in seconds. if above, it overflows */

	int w, h;				/* Sizes of cave, width and height. */
	int x1,y1,x2,y2;		/* Visible part of the cave */
	GdColor colorb;			/* border color */
	GdColor color0, color1, color2, color3, color4, color5;	/* c64-style colors; 4 and 5 are amoeba and slime. */

	int diamond_value;			/* Score for a diamond. */
	int extra_diamond_value;	/* Score for a diamond, when gate is open. */
	
	gboolean stone_sound;
	gboolean diamond_sound;
	gboolean nitro_sound;
	gboolean falling_wall_sound;
	gboolean expanding_wall_sound;
	gboolean bladder_spender_sound;
	gboolean bladder_convert_sound;

	int level_magic_wall_time[5];	/* magic wall 'on' state for each level (seconds) */
	gboolean magic_wall_stops_amoeba;	/* Turning on magic wall changes amoeba to diamonds. Original BD: yes, constkit: no */
	gboolean magic_timer_wait_for_hatching;	/* magic wall timer does not start before player's birth */
	gboolean magic_wall_sound;	/* magic wall has sound */
	
	int level_amoeba_time[5];		/* amoeba time for each level */
	double amoeba_growth_prob;		/* Amoeba slow growth probability */
	double amoeba_fast_growth_prob;	/* Amoeba fast growth probability */
	int level_amoeba_threshold[5];		/* amoeba turns to stones; if count is bigger than this (number of cells) */
	GdElement enclosed_amoeba_to;	/* an enclosed amoeba converts to this element */
	GdElement too_big_amoeba_to;	/* an amoeba grown too big converts to this element */

	int level_amoeba_2_time[5];		/* amoeba time for each level */
	double amoeba_2_growth_prob;		/* Amoeba slow growth probability */
	double amoeba_2_fast_growth_prob;	/* Amoeba fast growth probability */
	int level_amoeba_2_threshold[5];		/* amoeba turns to stones; if count is bigger than this (number of cells) */
	GdElement enclosed_amoeba_2_to;	/* an enclosed amoeba converts to this element */
	GdElement too_big_amoeba_2_to;	/* an amoeba grown too big converts to this element */
	gboolean amoeba_2_explodes_by_amoeba;	/* amoeba 2 will explode if touched by amoeba1 */
	GdElement amoeba_2_explodes_to;	/* amoeba 2 explodes to element, when touched by amoeba1 */
	GdElement amoeba_2_looks_like;	/* an amoeba 2 looks like this element */

	gboolean amoeba_timer_started_immediately;	/* FALSE: amoeba will start life at the first possibility of growing. */
	gboolean amoeba_timer_wait_for_hatching;	/* amoeba timer does not start before player's birth */
	gboolean amoeba_sound;			/* if the living amoeba has sound. */

	GdElement acid_eats_this;		/* acid eats this element */
	double acid_spread_ratio;		/* Probability of acid blowing up, each frame */
	gboolean acid_spread_sound;		/* acid has sound */
	GdElement acid_turns_to;		/* whether acid converts to explosion on spreading or other */

	double level_slime_permeability[5];		/* true random slime */
	int level_slime_permeability_c64[5];	/* Appearing in bd 2 */
	int level_slime_seed_c64[5];			/* predictable slime random seed */
	gboolean slime_predictable;				/* predictable random start for slime. yes for plck. */
	GdElement slime_eats_1, slime_converts_1;	/* slime eats element x and converts to element x; for example diamond -> falling diamond */
	GdElement slime_eats_2, slime_converts_2;
	gboolean slime_sound;			/* slime has sound */

	int level_hatching_delay_frame[5];		/* Scan frames before Player's birth. */
	int level_hatching_delay_time[5];		/* Scan frames before Player's birth. */
	
	int level_bonus_time[5];		/* bonus time for clock collected. */
	int level_penalty_time[5];				/* Time penalty when voodoo destroyed. */
	gboolean voodoo_collects_diamonds;	/* Voodoo can collect diamonds */
	gboolean voodoo_dies_by_stone;		/* Voodoo can be killed by a falling stone */
	gboolean voodoo_can_be_destroyed;	/* Voodoo can be destroyed by and explosion */
	
	gboolean water_does_not_flow_down;	/* if true, water will not grow downwards, only in other directions. */
	gboolean water_sound;			/* water has sound */
	
	gboolean bladder_sound;		/* bladder moving and pushing has sound */
	GdElement bladder_converts_by;	/* bladder converts to clock by touching this element */

	int biter_delay_frame;		/* frame count biters do move */
	GdElement biter_eat;		/* biters eat this */
	gboolean biter_sound;		/* biters have sound */	

	gboolean expanding_wall_changed;	/* expanding wall direction is changed */

	/* effects */
	GdElement explosion_to;			/* explosion converts to this element */
	GdElement diamond_birth_to;		/* a diamond birth converts to this element */
	GdElement falling_stone_to;		/* a falling stone converts to this element */
	GdElement falling_diamond_to;	/* a falling diamond converts to this element */
	GdElement bouncing_stone_to;	/* a bouncing stone converts to this element */
	GdElement bouncing_diamond_to;	/* a bouncing diamond converts to this element */

	GdElement expanding_wall_looks_like;	/* an expanding wall looks like this element */
	GdElement dirt_looks_like;			/* dirt looks like this element */

	GdElement magic_stone_to;		/* magic wall converts falling stone to */
	GdElement magic_diamond_to;		/* magic wall converts falling diamond to */

	GdElement bomb_explode_to;		/* bombs explode to this element */
	GdElement nitro_explode_to;		/* nitro packs explode to this element */

	double pushing_stone_prob;		/* probability of pushing stone */
	double pushing_stone_prob_sweet;	/* probability of pushing, after eating sweet */
	gboolean mega_stones_pushable_with_sweet;	/* mega stones may be pushed with sweet */

	gboolean creatures_backwards;	/* creatures changed direction */
	gboolean creatures_direction_auto_change_on_start;	/* the change occurs also at the start signal */
	int creatures_direction_auto_change_time;	/* creatures automatically change direction every x seconds */
	
	int skeletons_needed_for_pot;	/* how many skeletons to be collected, to use a pot */
	int skeletons_worth_diamonds;	/* for crazy dream 7 compatibility: collecting skeletons might open the cave door. */
	
	GdDirection gravity;
	int gravity_change_time;
	gboolean gravity_change_sound;
	gboolean gravity_affects_all;	/* if true, gravity also affects falling wall, bladder and waiting stones */
	gboolean gravity_switch_active;	/* true if gravity switch is activated, and can be used. */

	gboolean hammered_walls_reappear;
	int pneumatic_hammer_frame;
	int hammered_wall_reappear_frame;
	gboolean pneumatic_hammer_sound;
	
	/* internal variables, used during the game. private data :) */
	GdElement* (*getp) (const struct _cave*, int x, int y);	/* returns a pointer to the element at x, y. this points to a perfect border or a line shifting get function. */

	gboolean hatched;			/* hatching has happened. (timers may run, ...) */
	gboolean gate_open;			/* self-explaining */
	guint32 render_seed;		/* the seed value, which was used to render the cave, is saved here. will be used by record&playback */
	GRand *random;				/* random number generator of rendered cave */
	int rendered;				/* if not null, rendered at level x */
	int timing_factor;			/* number of "milliseconds" in each second :) 1000 for ntsc, 1200 for pal. */
	gpointer **objects_order;	/* two-dimensional map of cave; each cell is a pointer to the drawing object, which created this element. NULL if map or random. */
	int **hammered_reappear;	/* integer map of cave; if non-zero, a brick wall will appear there */

	int speed;					/* Time between game cycles in ms */
	int c64_timing;				/* a ckdelay value for the level this cave is rendered for */
	int ckdelay;				/* ckdelay value for the current iteration */
	int ckdelay_extra_for_animation;	/* bd1 and similar engines had animation bits in cave data, to set which elements to animate (firefly, butterfly, amoeba).
											animating an element also caused some delay each frame; according to my measurements, around 2.6 ms/element. */

	int hatching_delay_frame;
	int hatching_delay_time;
	int time_bonus;				/* bonus time for clock collected. */
	int time_penalty;			/* Time penalty when voodoo destroyed. */
	int time;					/* seconds remaining to finish cave */
	int timevalue;				/* points for remaining seconds - for current level */
	int diamonds_needed;		/* diamonds needed to open outbox */
	int diamonds_collected;		/* diamonds collected */
	int skeletons_collected;	/* number of skeletons collected */
	int gate_open_flash;		/* flashing of screen when gate opens */
	int score;					/* Score got this frame. */
	int amoeba_time;			/* Amoeba growing slow (low probability, default 3%) for seconds. After that, fast growth default (25%) */
	int amoeba_2_time;			/* Amoeba growing slow (low probability, default 3%) for seconds. After that, fast growth default (25%) */
	int amoeba_max_count;			/* selected amoeba 1 threshold for this level */
	int amoeba_2_max_count;			/* selected amoeba 2 threshold for this level */
	GdAmoebaState amoeba_state;		/* state of amoeba 1 */
	GdAmoebaState amoeba_2_state;	/* state of amoeba 2 */
	int magic_wall_time;			/* magic wall 'on' state for seconds */
	double slime_permeability;		/* true random slime */
	int slime_permeability_c64;		/* Appearing in bd 2 */
	GdMagicWallState magic_wall_state;		/* State of magic wall */
	GdPlayerState player_state;		/* Player state. not yet living, living, exited... */
	int player_seen_ago;			/* player was seen this number of scans ago */
	gboolean kill_player;			/* Voodoo died, or used pressed escape to restart level. */
	gboolean sweet_eaten;			/* player ate sweet, he's strong. prob_sweet applies, and also able to push chasing stones */
	int player_x, player_y;			/* Coordinates of player (for scrolling) */
	int px[16], py[16];				/* coordinates of player, for chasing stone */
	int key1, key2, key3;			/* The player is holding this number of keys of each color */
	gboolean diamond_key_collected;	/* Key collected, so trapped diamonds convert to diamonds */
	gboolean inbox_flash_toggle;	/* negated every scan. helps drawing inboxes, and making players be born at different times. */
	GdDirection last_direction;		/* last direction player moved. used by draw routines */
	GdDirection last_horizontal_direction;
	int biters_wait_frame;				/* number of frames to wait until biteres will move again */
	int creatures_direction_will_change;	/* creatures automatically change direction every x seconds */
	GdC64RandomGenerator c64_rand;	/* used for predictable random generator during the game. */

	int gravity_will_change;	/* gravity will change in this number of seconds */
	gboolean gravity_disabled;	/* when the player is stirring the pot, there is no gravity. */
	GdDirection gravity_next_direction;	/* next direction when the gravity changes. will be set by the player "getting" a gravity switch */
	gboolean got_pneumatic_hammer;	/* true if the player has a pneumatic hammer */
	int pneumatic_hammer_active_delay;	/* number of frames to wait, till pneumatic hammer will destroy the wall */
	GdSound sound1, sound2, sound3;	/* sound set for 3 channels after each iteration */
} Cave;


#define CAVE_OFFSET(property) (G_STRUCT_OFFSET(Cave, property))










/* arrays for movements */
/* also no1 and bd2 cave data import helpers; line direction coordinates */
extern const int gd_dx[], gd_dy[];

/* names of schedulings */
extern const char* gd_scheduling_name[];
extern const char* gd_scheduling_filename[];	/* identifiers in bdcff */

extern GdElement gd_char_to_element[];

void gd_create_char_to_element_table();
GdElement gd_get_element_from_character (guint8 character);
GdElement gd_get_element_from_string (const char *string);



void gd_struct_set_defaults_from_array(gpointer str, const GdStructDescriptor *properties, GdPropertyDefault *defaults);
char *gd_struct_explain_defaults_in_string(const GdStructDescriptor *properties, GdPropertyDefault *defaults);



/* init cave engine */
void gd_cave_init();

/* for cave tags hash table */
gboolean gd_str_case_equal(gconstpointer s1, gconstpointer s2);
guint gd_str_case_hash(gconstpointer v);

/* cave highscore functions */
int gd_highscore_compare(gconstpointer a, gconstpointer b);
gboolean gd_is_highscore(GdHighScore *scores, int score);
int gd_add_highscore(GdHighScore *highscores, const char *name, int score);
void gd_clear_highscore(GdHighScore *hs);
gboolean gd_has_highscore(GdHighScore *hs);

/* cave creator and destructor functions */
Cave *gd_cave_new();
Cave *gd_cave_new_from_cave(const Cave *orig);
void gd_cave_copy(Cave *dest, const Cave *src);
void gd_cave_free(Cave *cave);

/* cave manipulation */
void gd_cave_set_gdash_defaults(Cave *cave);
void gd_cave_set_defaults_from_array(Cave* cave, GdPropertyDefault *defaults);
void gd_cave_correct_visible_size(Cave *cave);
void gd_cave_auto_shrink(Cave *cave);
void gd_cave_easy(Cave *cave);
void gd_cave_set_random_colors(Cave *cave);
void gd_cave_setup_for_game(Cave *cave);
void gd_cave_count_diamonds(Cave *cave);
unsigned int gd_c64_random(GdC64RandomGenerator *rand);
unsigned int gd_cave_c64_random(Cave *);
void gd_c64_random_set_seed(GdC64RandomGenerator *rand, int seed1, int seed2);

/* support */
gpointer gd_cave_map_new_for_cave(const Cave *cave, const int cell_size);
gpointer gd_cave_map_dup_size(const Cave * cave, const gpointer map, const int cell_size);
#define gd_cave_map_new(CAVE, TYPE) ((TYPE **)gd_cave_map_new_for_cave((CAVE), sizeof(TYPE)))
#define gd_cave_map_dup(CAVE, MAP) ((gpointer)gd_cave_map_dup_size((CAVE), (gpointer *)(CAVE)->MAP, sizeof((CAVE)->MAP[0][0])))
void gd_cave_map_free(gpointer map);

void gd_cave_store_rc (Cave * cave, int x, int y, const GdElement element, const void* order);
static inline GdElement
gd_cave_get_rc (const Cave *cave, const int x, const int y)
{
	g_assert(x >= 0 && x < cave->w && y >= 0 && y < cave->h);	/* check bounds */

	return cave->map[y][x];
}

/* direction */
const char *gd_direction_get_visible_name(GdDirection dir);
const char *gd_direction_get_filename(GdDirection dir);
GdDirection gd_direction_from_string(const char *str);

/* scheduling */
const char *gd_scheduling_get_filename(GdScheduling sched);
GdScheduling gd_scheduling_from_string(const char *str);

/* game playing helpers */
#define GD_REDRAW (1<<10)
void gd_drawcave_game(const Cave *cave, int **gfx_buffer, gboolean bonus_life_flash, gboolean paused, gboolean increment_animcycle);
gboolean gd_cave_scroll(int width, int visible, int center, gboolean exact, int start, int to, int *current, int *desired, int *speed, int divisor);

/* function to copy a GdString */
static inline int
gd_strcpy(GdString dest, const GdString src)
{
	return g_strlcpy(dest, src, sizeof(GdString));
}

int gd_cave_time_show(Cave *cave, int internal_time);


#endif							/* _CAVE_H */

