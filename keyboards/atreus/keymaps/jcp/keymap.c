// This is the personal keymap of Jean-Christophe Petkovich (@jcpetkovich). It
// is based on the keymap by Ian Sterling (@xyverz), with the addition of
// persistent layers like the Planck and Preonic keyboards by Jack Humbert.

#include "atreus.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// CONFIGURATION
#define PREVENT_STUCK_MODIFIERS
#define TAPPING_TERM 150

enum atreus_layers {
	_COLEMAK,
	_LOWER,
	_RAISE,
	_ADJUST,
	_NAVIG
};

enum planck_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NAVIG,
  BACKLIT
};

// Adding macros to make the keymaps below much easier to read.
#define SFT_SCLN SFT_T(KC_SCLN)
#define SFT_SLS SFT_T(KC_SLSH)
#define SFT_BSL SFT_T(KC_BSLS)
#define SFT_ZED SFT_T(KC_Z)
#define ALT_ENT ALT_T(KC_ENT)
#define TAB_ALT ALT_T(KC_TAB)

// Top layer macros
#define GUI_MIN GUI_T(KC_MINS)
#define ALT_QUO ALT_T(KC_QUOT)

// Number layer macros
#define CTL_ZER CTL_T(KC_0)
#define GUI_DOT GUI_T(KC_DOT)
#define ALT_EQL ALT_T(KC_EQL)
#define SFT_MIN SFT_T(KC_MINS)

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

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak Layer
	,----------------------------------.              ,----------------------------------.
	|   Q  |   W  |   F  |   P  |   G  |              |   J  |   L  |   U  |   Y  |   L  |
	|------+------+------+------+------|              |------+------+------+------+------|
	|   A  |   R  |   S  |   T  |   D  |              |   H  |   N  |   E  |   I  |   O  |
	|------+------+------+------+------|------.,------|------+------+------+------+------|
	|SFT/ Z|   X  |   C  |   V  |   B  | LOWER||RAISE |   K  |   M  |   ,  |   .  |SFT/ /|
	|------+------+------+------+------|      ||      |------+------+------+------+------|
	|  Esc | HYPR |  GUI | Alt  | SPC  |------'`------| BkSp | Ctrl | GUI/-|   '  | Enter|
	`----------------------------------'              `----------------------------------'*/
  [_COLEMAK] = {
    {KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN},
    {KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O   },
    {SFT_ZED, KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   KC_K,    KC_M,    KC_COMM, KC_DOT,  SFT_SLS},
    {KC_ESC,  KC_HYPR, KC_LGUI, TAB_ALT, KC_SPC,  RAISE,   KC_BSPC, KC_LCTL, GUI_MIN, KC_QUOT, KC_ENT }
  },

/* LOWER Layer (number oriented)
   ,----------------------------------.              ,----------------------------------.
   | DWORD| BWORD|  UP  | FWORD| Home |              |      |   7  |   8  |   9  |   /  |
   |------+------+------+------+------|              |------+------+------+------+------|
   | DEL  | Left | Down | Right| End  |              |      |   4  |   5  |   6  |   *  |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |      |      |      |      |   ,  | ON   ||      |      |   1  |   2  |   3  |   -  |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |      |      |      |      |      |------'`------|      | CTL/0| GUI/.| CTL/=|   +  |
   `----------------------------------'              `----------------------------------'*/
  [_LOWER] = {
	  {DWORD,   BWORD,   KC_UP,   FWORD,   KC_HOME, XXXXXXX, _______, KC_7,    KC_8,    KC_9,    KC_SLSH},
	  {KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, _______, KC_4,    KC_5,    KC_6,    KC_ASTR},
	  {_______, _______, _______, _______, KC_COMM, _______, _______, KC_1,    KC_2,    KC_3,    SFT_MIN},
	  {_______, _______, _______, _______, _______, _______, _______, CTL_ZER, GUI_DOT, ALT_EQL, KC_PLUS}
  },

/* RAISE Layer (symbol oriented)
        ,----------------------------------.              ,----------------------------------.
        |   !  |   @  |   #  |   $  |   %  |              |   ^  |   &  |   *  |   (  |   )  |
        |------+------+------+------+------|              |------+------+------+------+------|
        |   ~  |   [  |   ]  |   {  |   }  |              | PgDn |   [  |   ]  |   {  |   }  |
        |------+------+------+------+------|------.,------|------+------+------+------+------|
        |   `  |   (  |   )  |      |   |  |      ||      | PgUp | Mute | Vol- | Vol+ |SFT/ \|
        |------+------+------+------+------|      ||      |------+------+------+------+------|
        |      | CAPS |      |      | Del  |------'`------| Ins  |      |      |      |      |
	`----------------------------------'              `----------------------------------'*/
  [_RAISE] = {
    {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
    {KC_TILD, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, KC_PGUP, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR},
    {KC_GRV,  KC_LPRN, KC_RPRN, _______, KC_PIPE, _______, KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU, SFTBSLS},
    {_______, KC_CAPS, _______, _______, KC_SPC,  _______, KC_INS,  _______, _______, _______, _______}
  },

/* ADJUST Layer
	,----------------------------------.              ,----------------------------------.
	|  F1  |  F2  |  F3  |  F4  |  F5  |              |  F6  |  F7  |  F8  |  F9  | F10  |
	|------+------+------+------+------|              |------+------+------+------+------|
	|  F11 |      |      |      |      |              |      | PrSc | ScLk | Paus | F12  |
	|------+------+------+------+------|------.,------|------+------+------+------+------|
	|      |      |      |      |      |      ||      |      |      |      |      |      |
	|------+------+------+------+------|      ||      |------+------+------+------+------|
	|      |      |      |      |      |------'`------|      |      |      |      | RESET|
	`----------------------------------'              `----------------------------------'*/
  [_ADJUST] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 },
    {KC_F11,  _______, _______, _______, _______, XXXXXXX, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_F12 },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  }
  },

/* NAVIG (navigation) Layer
	,----------------------------------.              ,----------------------------------.
	|      |      |      |      |      |              |      |      |      |      |      |
	|------+------+------+------+------|              |------+------+------+------+------|
	|      |      |      |      |      |              |      |      |      |      |      |
	|------+------+------+------+------|------.,------|------+------+------+------+------|
	|      |      |      |      |      |      ||      |      |      |      |      |      |
	|------+------+------+------+------|      ||      |------+------+------+------+------|
	|      |      |      |      |      |------'`------|      |      |      |      |      |
	`----------------------------------'              `----------------------------------'*/
  [_NAVIG] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 },
    {KC_F11,  _______, _______, _______, _______, XXXXXXX, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_F12 },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  }
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
