#ifndef JCMACROS_H
#define JCMACROS_H

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// 7char macros for the grid, mostly shift keys
#define SFT_SCLN SFT_T(KC_SCLN)
#define SFT_SLS SFT_T(KC_SLSH)
#define SFT_BSL SFT_T(KC_BSLS)
#define SFT_ZED SFT_T(KC_Z)
#define ALT_ENT ALT_T(KC_ENT)
#define ALT_TAB ALT_T(KC_TAB)
#define SFT_ENT MT(MOD_RSFT, KC_ENT)
#define CTL_LEF MT(MOD_CTRL, KC_LEFT)

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

// HYPER macros
#define GUI_NOR HYPR(KC_UP)
#define GUI_SOU HYPR(KC_DOWN)
#define GUI_EAS HYPR(KC_RGHT)
#define GUI_WES HYPR(KC_LEFT)
#define GUI_CEN HYPR(KC_N)

// corners using unei (colemak)
//   u
// n e i
#define GUI_NES HYPR(KC_U)
#define GUI_SES HYPR(KC_E)
#define GUI_NWE HYPR(KC_I)
#define GUI_SWE HYPR(KC_N)

// float/tile/pseudotile all
#define GUI_FLO HYPR(KC_F)
#define GUI_TIL HYPR(KC_T)

// window selection
#define GUI_LFT LGUI(KC_H)
#define GUI_RGT LGUI(KC_L)
#define GUI_UP  LGUI(KC_K)
#define GUI_DWN LGUI(KC_J)

// programs
#define EMACS LGUI(KC_E)
#define POPEN LGUI(KC_O)

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

// editing
#define COPY LCTL(KC_C)
#define PASTE LCTL(LGUI(KC_V))
#define CUT LCTL(KC_X)

// emacs keybindings
#define SHR_WSP LALT(KC_BSLS)

#endif /* JCMACROS_H */
