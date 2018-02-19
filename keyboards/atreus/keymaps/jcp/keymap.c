// This is the personal keymap of Jean-Christophe Petkovich (@jcpetkovich). It
// is based on the keymap by Ian Sterling (@xyverz), with the addition of
// persistent layers like the Planck and Preonic keyboards by Jack Humbert.

#include "atreus.h"
#include "action_layer.h"
#include "eeconfig.h"
#include <jcmacros.h>

extern keymap_config_t keymap_config;

// CONFIGURATION
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define TAPPING_TERM 150

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
   | DWORD| BWORD|  UP  | FWORD| Home |              |      |      |      |      |      |
   |------+------+------+------+------|              |------+------+------+------+------|
   | DEL  | Left | Down | Right| End  |              | PgUp |      |      |      |      |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |      | CUT  | COPY | PASTE|      | ON   ||      | PgDn |      |      |      | SWSP |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      |      |      |      |      |------'`------| Ins  | Ctrl | GUI  | Alt  |      |
   `----------------------------------'              `----------------------------------'*/
	[_LOWER] = {
		{DWORD,   BWORD,   KC_UP,   FWORD,   KC_HOME, XXXXXXX, _______, _______, _______, _______, _______},
		{KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, KC_PGUP, _______, _______, _______, _______},
		{_______, CUT,     COPY,    PASTE,   _______, _______, KC_PGDN, _______, _______, _______, SHR_WSP},
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
   |      | FLOAT| TILE |      |      |      || ON   |      |  WSW |  WS  |  WSE |      |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      |      |      |      |      |------'`------|      |      |      |      |      |
   `----------------------------------'              `----------------------------------'*/
	[_RAISE] = {
		{_______, _______, GUI_UP,  _______, _______, XXXXXXX, _______, GUI_NWE, GUI_NOR, GUI_NES, _______},
		{_______, GUI_LFT, GUI_DWN, GUI_RGT, _______, XXXXXXX, _______, GUI_WES, GUI_CEN, GUI_EAS, _______},
		{_______, GUI_FLO, GUI_TIL, _______, _______, _______, _______, GUI_SWE, GUI_SOU, GUI_SES, _______},
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
		{_______, _______, _______, _______, _______, _______, _______, CTL_ZER, GUI_DOT, KC_EQL,  KC_PLUS}
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
