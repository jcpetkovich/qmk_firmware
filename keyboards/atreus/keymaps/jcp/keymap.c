// This is the personal keymap of Jean-Christophe Petkovich (@jcpetkovich). It
// is based on the keymap by Ian Sterling (@xyverz), with the addition of
// persistent layers like the Planck and Preonic keyboards by Jack Humbert.

#include "atreus.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

/* #define PREVENT_STUCK_MODIFIERS */

enum atreus_layers {
	_COLEMAK,
	_LOWER,
	_RAISE,
	_ADJUST
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  DVORMAC,
  LOWER,
  RAISE,
  BACKLIT
};

// Adding macros to make the keymaps below much easier to read.
#define SFTSCLN SFT_T(KC_SCLN)
#define SFTSLSH SFT_T(KC_SLSH)
#define SFTZED SFT_T(KC_Z)
#define ALTENT ALT_T(KC_ENT)
#define ESCTRL CTL_T(KC_ESC)
#define TABALT ALT_T(KC_TAB)

// Navigation macros
#define BWORD LCTL(KC_LEFT)
#define FWORD LCTL(KC_RGHT)

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
	|  Esc | TAB  |  GUI | Alt  | BkSp |------'`------| BkSp | Ctrl |   -  |   '  | Enter|
	`----------------------------------'              `----------------------------------'*/
  [_COLEMAK] = {
    {KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN},
    {KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    XXXXXXX, KC_H,    KC_N,    KC_E,    KC_I,    KC_O   },
    {SFTZED,  KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   KC_K,    KC_M,    KC_COMM, KC_DOT,  SFTSLSH},
    {KC_ESC,  KC_TAB,  KC_LGUI, TABALT,  KC_SPC,  RAISE,   KC_BSPC, KC_LCTL, KC_MINS, KC_QUOT, KC_ENT }
  },

/* LOWER Layer
   ,----------------------------------.              ,----------------------------------.
   |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   /  |
   |------+------+------+------+------|              |------+------+------+------+------|
   | CAPS | BWORD|  UP  | FWORD| Home |              | PgDn |   4  |   5  |   6  |   *  |
   |------+------+------+------+------|------.,------|------+------+------+------+------|
   |      | Left | Down | Right| End  |      ||      | PgUp |   1  |   2  |   3  |   -  |
   |------+------+------+------+------|      ||      |------+------+------+------+------|
   |   `  |      |      |      | Del  |------'`------| Ins  |   0  |   .  |   =  |   +  |
   `----------------------------------'              `----------------------------------'*/
  [_LOWER] = {
	  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_SLSH},
	  {KC_CAPS, BWORD,   KC_UP,   FWORD,   KC_HOME, XXXXXXX, KC_PGUP, KC_4,    KC_5,    KC_6,    KC_ASTR},
	  {_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, KC_PGDN, KC_1,    KC_2,    KC_3,    KC_MINS},
	  {KC_GRV,  _______, _______, _______, KC_DEL,  _______, KC_INS,  KC_0,    KC_DOT,  KC_EQL,  KC_PLUS}
  },

/* RAISE Layer
        ,----------------------------------.              ,----------------------------------.
        |   !  |   @  |   #  |   $  |   %  |              |   ^  |   &  |   *  |   (  |   )  |
        |------+------+------+------+------|              |------+------+------+------+------|
        | CAPS | BWORD|  UP  | FWORD| Home |              | PgDn |      |   +  |   {  |   }  |
        |------+------+------+------+------|------.,------|------+------+------+------+------|
        |      | Left | Down | Right| End  |      ||      | PgUp | Mute | Vol- | Vol+ |      |
        |------+------+------+------+------|      ||      |------+------+------+------+------|
        |   ~  |      |      |      | Del  |------'`------| Ins  |      |      |      |      |
	`----------------------------------'              `----------------------------------'*/
  [_RAISE] = {
    {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
    {KC_CAPS, BWORD,   KC_UP,   FWORD,   KC_HOME, XXXXXXX, KC_PGUP, _______, KC_PLUS, KC_LCBR, KC_RCBR},
    {_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, KC_PGDN, KC_MUTE, KC_VOLD, KC_VOLU, _______},
    {KC_TILD, _______, _______, _______, KC_DEL,  _______, KC_INS,  _______, _______, _______, _______}
  },

/* ADJUST Layer
	,----------------------------------.              ,----------------------------------.
	|  F1  |  F2  |  F3  |  F4  |  F5  |              |  F6  |  F7  |  F8  |  F9  | F10  |
	|------+------+------+------+------|              |------+------+------+------+------|
	|  F11 |      |      |      |      |              |      | PrSc | ScLk | Paus | F12  |
	|------+------+------+------+------|------.,------|------+------+------+------+------|
	|      |QWERTY|COLEMK|DVORAK|DVORMC|      ||      |      |      |      |      |      |
	|------+------+------+------+------|      ||      |------+------+------+------+------|
	|      |      |      |      |      |------'`------|      |      |      |      | RESET|
	`----------------------------------'              `----------------------------------'*/
  [_ADJUST] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 },
    {KC_F11,  _______, _______, _______, _______, XXXXXXX, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_F12 },
    {_______, QWERTY,  COLEMAK, DVORAK,  DVORMAC, _______, _______, _______, _______, _______, _______},
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
