// This is the personal keymap of Jean-Christophe Petkovich (@jcpetkovich). It
// is based on the keymap by Ian Sterling (@xyverz), with the addition of
// persistent layers like the Planck and Preonic keyboards by Jack Humbert.

#include "atreus.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// CONFIGURATION
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define TAPPING_TERM 100

enum atreus_layers {
	_COLEMAK,
	_LOWER,
	_RAISE,
	_ADJUST,
	_NUMBERS,
	_SYMBOLS
};

enum planck_keycodes {
	COLEMAK = SAFE_RANGE,
	LOWER,
	RAISE,
	ADJUST,
	BACKLIT
};


// Layers
#define NUMBERS LT(_NUMBERS, KC_X)
#define SYMBOLS LT(_SYMBOLS, KC_DOT)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Adding macros to make the keymaps below much easier to read.
#define SFT_SCLN SFT_T(KC_SCLN)
#define SFT_SLS SFT_T(KC_SLSH)
#define SFT_BSL SFT_T(KC_BSLS)
#define SFT_ZED SFT_T(KC_Z)
#define ALT_ENT ALT_T(KC_ENT)
#define ALT_TAB ALT_T(KC_TAB)

// Top layer macros
#define GUI_MIN GUI_T(KC_MINS)
#define ALT_QUO ALT_T(KC_QUOT)

// Number layer macros
#define CTL_ZER CTL_T(KC_0)
#define GUI_DOT GUI_T(KC_DOT)
#define ALT_EQL ALT_T(KC_EQL)
#define SFT_MIN SFT_T(KC_MINS)
#define ALTTAB  LALT(KC_TAB)

// Navigation macros
#define BWORD LCTL(KC_LEFT)
#define FWORD LCTL(KC_RGHT)
#define DWORD LCTL(KC_BSPC)
#define DFWORD LCTL(KC_DEL)

// hyper window manager macros
#define GUI_NOR HYPR(KC_UP)
#define GUI_SOU HYPR(KC_DOWN)
#define GUI_EAS HYPR(KC_RGHT)
#define GUI_WES HYPR(KC_LEFT)
// colemak letter/arrows */
//   u
// n e i
#define GUI_NES HYPR(KC_U)
#define GUI_SES HYPR(KC_E)
#define GUI_NWE HYPR(KC_I)
#define GUI_SWE HYPR(KC_N)
// float/tile/pseudotile all
#define GUI_FLO HYPR(KC_F)
#define GUI_TIL HYPR(KC_T)

#define GUI_LFT LGUI(KC_H)
#define GUI_RGT LGUI(KC_L)
#define GUI_UP  LGUI(KC_K)
#define GUI_DWN LGUI(KC_J)

// desktops
#define GUI_D1  LGUI(KC_1)
#define GUI_D2  LGUI(KC_2)
#define GUI_D3  LGUI(KC_3)
#define GUI_D4  LGUI(KC_4)
#define GUI_D5  LGUI(KC_5)
#define GUI_D6  LGUI(KC_6)
#define GUI_D7  LGUI(KC_7)
#define GUI_D8  LGUI(KC_8)
#define GUI_D9  LGUI(KC_9)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak Layer
   ,----------------------------------.              ,----------------------------------.
   |   Q  |   W  |   F  |   P  |   G  |              |   J  |   L  |   U  |   Y  |   ;  |
   |------+------+------+------+------|              |------+------+------+------+------|
   |   A  |   R  |   S  |   T  |   D  |              |   H  |   N  |   E  |   I  |   O  |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |SFT/ Z|NUM/X |   C  |   V  |   B  | LOWER||RAISE |   K  |   M  |   ,  |SYM/. |SFT/ /|
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |  Esc | HYPR |  GUI | Alt  | SPC  |------'`------| BkSp | Ctrl | GUI/-|   '  | Enter|
   `----------------------------------'              `----------------------------------'*/
	[_COLEMAK] = {
		{KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN},
		{KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O   },
		{SFT_ZED, NUMBERS, KC_C,    KC_V,    KC_B,    LOWER,   KC_K,    KC_M,    KC_COMM, SYMBOLS, SFT_SLS},
		{KC_ESC,  KC_HYPR, KC_LGUI, ALT_TAB, KC_SPC,  RAISE,   KC_BSPC, KC_LCTL, GUI_MIN, KC_QUOT, KC_ENT }
	},

/* LOWER Layer (editing/desktop oriented)

   Thumb-triggered layers are great for single press keys and keys you don't
   press with modifiers, this includes macros that are frequently used (like
   switching desktops) that could be made significantly more efficient on small
   layouts like this by eliminating the need to press SUPER.

   This layer takes care of arrow keys and editing tricks, simple cursor
   navigation and desktop switching (for now). Does it make sense to kep desktop
   navigation here? It seems out of place somehow, but it's an open layer
   otherwise.

   ,----------------------------------.              ,----------------------------------.
   | DWORD| BWORD|  UP  | FWORD| Home |              |      | Dsk7 | Dsk8 | Dsk9 |      |
   |------+------+------+------+------|              |------+------+------+------+------|
   | DEL  | Left | Down | Right| End  |              | PgUp | Dsk4 | Dsk5 | Dsk6 |      |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |      |      | ALTTB|   ,  |      | ON   ||      | PgDn | Dsk1 | Dsk2 | Dsk3 |      |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      |      |      |      |      |------'`------| Ins  | Ctrl | GUI  | Alt  |      |
   `----------------------------------'              `----------------------------------'*/
	[_LOWER] = {
		{DWORD,   BWORD,   KC_UP,   FWORD,   KC_HOME, XXXXXXX, _______, GUI_D7,  GUI_D8,  GUI_D9,  _______},
		{KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, KC_PGUP, GUI_D4,  GUI_D5,  GUI_D6,  _______},
		{_______, _______, ALTTAB,  KC_COMM, _______, _______, KC_PGDN, GUI_D1,  GUI_D2,  GUI_D3,  _______},
		{_______, _______, _______, _______, _______, _______, KC_INS,  KC_LCTL, KC_LGUI, KC_LALT, _______}
	},

/* RAISE Layer (WM oriented)

   The raise layer is for manual window management keys, particularly for
   floating window managers where you have a lot of control over where things
   go.

   ,----------------------------------.              ,----------------------------------.
   |      |      |  MWU |      |      |              |      |  WNW |  WN  |  WNE |      |
   |------+------+------+------+------|              |------+------+------+------+------|
   |      |  MWL |  MWD |  MWR |      |              |      |  WW  |  WC  |  WE  |      |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |      |      |      |      |      |      || ON   |      |  WSW |  WS  |  WSE |      |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      |      |      |      |      |------'`------|      |      |      |      |      |
   `----------------------------------'              `----------------------------------'*/
	[_RAISE] = {
		{_______, _______, GUI_UP,  _______, _______, XXXXXXX, _______, GUI_NWE, GUI_NOR, GUI_NES, _______},
		{_______, GUI_LFT, GUI_DWN, GUI_RGT, _______, XXXXXXX, _______, GUI_WES, _______, GUI_EAS, _______},
		{_______, _______, _______, _______, _______, _______, _______, GUI_SWE, GUI_SOU, GUI_SES, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
	},

/* ADJUST Layer
   ,----------------------------------.              ,----------------------------------.
   |  F1  |  F2  |  F3  |  F4  |  F5  |              |  F6  |  F7  |  F8  |  F9  | F10  |
   |------+------+------+------+------|              |------+------+------+------+------|
   |  F11 |      |      |      |      |              |      | PrSc | ScLk | Paus | F12  |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |      |      |      |      |      | ON   || ON   |      |      |      |      |      |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      |      |      |      |      |------'`------|      |      |      |      | RESET|
   `----------------------------------'              `----------------------------------'*/
	[_ADJUST] = {
		{KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 },
		{KC_F11,  _______, _______, _______, _______, XXXXXXX, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_F12 },
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  }
	},

/* NUMBERS Layer
   ,----------------------------------.              ,----------------------------------.
   |      |      |      |      |      |              |      |   7  |   8  |   9  |   /  |
   |------+------+------+------+------|              |------+------+------+------+------|
   |      |      |      |      |      |              |      |   4  |   5  |   6  |   *  |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |      | (ON) | ALTB |    , |      |      ||      |      |   1  |   2  |   3  |   -  |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      |      |      |      |      |------'`------|      | CTL/0| GUI/.| ALT/=|   +  |
   `----------------------------------'              `----------------------------------'*/
	[_NUMBERS] = {
		{_______, _______, _______, _______, _______, XXXXXXX, _______, KC_7,    KC_8,    KC_9,    KC_SLSH},
		{_______, _______, _______, _______, _______, XXXXXXX, _______, KC_4,    KC_5,    KC_6,    KC_ASTR},
		{_______, _______, ALTTAB,  KC_COMM, _______, _______, _______, KC_1,    KC_2,    KC_3,    SFT_MIN},
		{_______, _______, _______, _______, _______, _______, _______, CTL_ZER, GUI_DOT, ALT_EQL, KC_PLUS}
	},

/* SYMBOLS Layer
   ,----------------------------------.              ,----------------------------------.
   |   !  |   @  |   #  |   $  |   %  |              |   ^  |   &  |   *  |   (  |   )  |
   |------+------+------+------+------|              |------+------+------+------+------|
   |   ~  |   [  |   ]  |   {  |   }  |              |      |      |      |      |      |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |   `  |   (  |   )  |      |   |  |      ||      |      |   <  |   >  | (ON) |SFT/ \|
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      | CAPS |      |      |      |------'`------|      |      |      |      |      |
   `----------------------------------'              `----------------------------------'*/
	[_SYMBOLS] = {
		{KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
		{KC_TILD, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, _______, _______, _______, _______, _______},
		{KC_GRV,  KC_LPRN, KC_RPRN, _______, KC_PIPE, _______, _______, KC_LABK, KC_RABK, _______, SFT_BSL},
		{_______, KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______}
	}
};

const uint16_t PROGMEM fn_actions[] = {

};

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case COLEMAK:
		if (record->event.pressed) {
			persistent_default_layer_set(1UL<<_COLEMAK);
		}
		return false;
		break;
	case LOWER:
		if (record->event.pressed) {
			layer_on(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_LOWER);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
	case RAISE:
		if (record->event.pressed) {
			layer_on(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		} else {
			layer_off(_RAISE);
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
		}
		return false;
		break;
	}
	return true;
};
