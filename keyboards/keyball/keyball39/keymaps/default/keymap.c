/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

#include "keymap_hungarian.h"

enum layers {
    _BASE = 0,
    _NAV,
	_FUN,
    _SYMB,
    _NUM,
    _HUN,
};

// Aliases for readability
#define BASE     DF(_BASE)
#define NAV      MO(_NAV)
#define FUN      MO(_FUN)
#define SYMB     MO(_SYMB)
#define NUM      MO(_NUM)
#define HUN      MO(_HUN)

// ******** BASE *************
// Left-hand home row mods
#define RALT_W  RALT_T(KC_W)
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define CTL_D   LCTL_T(KC_D)
#define SFT_F   LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J   RSFT_T(KC_J)
#define CTL_K   RCTL_T(KC_K)
#define ALT_L   LALT_T(KC_L)
#define GUI_P   RGUI_T(KC_P)
#define RALT_O  RALT_T(KC_O)

//********* NAV *************
// Left-hand home row mods
#define LA_BTN1    LALT(KC_BTN1)
#define SH_BTN1    S(KC_BTN1)

//********* FUNC *************
// Left-hand home row mods
#define GUI_F1   LGUI_T(KC_F1)
#define ALT_F2   LALT_T(KC_F2)
#define CTL_F3   LCTL_T(KC_F3)
#define SFT_F4   LSFT_T(KC_F4)

// Right-hand home row mods
#define SFT_F7   RSFT_T(KC_F7)
#define CTL_F8   RCTL_T(KC_F8)
#define ALT_F9   LALT_T(KC_F9)
#define GUI_F10   RGUI_T(KC_F10)

//********* SYMB *************
#define CT_LPRN LCTL_T(HU_LPRN)
#define CT_RCBR RCTL_T(HU_RCBR)

//******** NUMBERS **********
// Left-hand home row mods
#define GUI_1    LGUI_T(HU_1)
#define ALT_2    LALT_T(HU_2)
#define CTL_3    LCTL_T(HU_3)
#define SFT_4    LSFT_T(HU_4)

// Right-hand home row mods
#define SFT_7    RSFT_T(HU_7)
#define CTL_8    RCTL_T(HU_8)
#define ALT_9    LALT_T(HU_9)
#define GUI_0    RGUI_T(HU_0)

// Thumbcluster
#define TAB_FUN   LT(FUN, KC_TAB)
#define SPC_NAV   LT(NAV, KC_SPC)
#define SPC_HUN   LT(HUN, KC_SPC)
#define BSPC_SYMB LT(SYMB, KC_BACKSPACE)
#define ENT_NUM   LT(NUM, KC_ENT)

// Shortcuts
#define UC_COPY LCTL(KC_C)
#define UC_PSTE LCTL(KC_V)
#define UC_CUT  LCTL(KC_X)
#define UC_OSFT OSM(MOD_LSFT)

const key_override_t kcbkspc_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE,  KC_DEL);   // backspace
const key_override_t kcbkspc2_key_override = ko_make_basic(MOD_MASK_SHIFT, BSPC_SYMB,  KC_DEL);   // backspace

const key_override_t** key_overrides = (const key_override_t*[]){
	&kcbkspc_key_override,
	&kcbkspc2_key_override,
    NULL
};

enum custom_keycodes {
    DBLCLK = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DBLCLK:
        if (record->event.pressed) {
		    SEND_STRING(SS_TAP(X_BTN1) SS_DELAY(15) SS_TAP(X_BTN1));
        }
        break;
    }
    return true;
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
// /*
//  * Base Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   Q  |   W  |   E  |   R  |   T  |                                               |   Y  |   U  |   I  |   O  |   P  |      
//  *                 |      | RALT |      |      |      |                                               |      |      |      | RALT |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   A  |   S  |   D  |   F  |   G  |                                               |   H  |   J  |   K  |   L  |  P   |
//  *                 |  GUI | LALT | LCTL | LSFT |      |                                               |      | LSFT | LCTL |  ALT |  GUI |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   Z  |   X  |   C  |   V  |   B  |                                               |   N  |   M  |  , < |  . > |  Q   |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             | Space| TAB  |                                 |Enter |BckSpc|
//  *                                             | NAVR | FUN  |                                 | NUM  |SYMB  |
//  *                                             `-------------'                                 `-------------'
//  */
    [_BASE] = LAYOUT(
               KC_Q   , RALT_W , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , RALT_O , KC_P,
               GUI_A  , ALT_S  , CTL_D  , SFT_F  , KC_G   ,                                        KC_H   , SFT_J  , CTL_K  , ALT_L  , GUI_P,
               KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_Q,
               _______, _______, _______, SPC_HUN, SPC_NAV, TAB_FUN,                      ENT_NUM, BSPC_SYMB, QK_REBOOT
    ),

// /*
//  * Navigation Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               | Home | PgDn | PgUp | End  |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      | Mouse| Mouse| Mouse|      |                                               |  ←   |   ↓  |   ↑  |   →  | ESC  |
//  *                 |      | Right|Middle| Left |      |                                               |      |      |      |      |      |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               |      | WH_D | WH_U |      |      |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                          ,-------------+------+---------------------------'
//  *                                             |      |      |                          |  ENT |BckSpc
//  *                                             |      |      |                          |      |      |
//  *                                             `-------------'                          `-------------'
//  */
    [_NAV] = LAYOUT(
               _______, KC_BTN2, KC_BTN3, DBLCLK , SH_BTN1,                                        KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______,
               _______, KC_BTN2, KC_BTN3, KC_BTN1, LA_BTN1,                                        KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ESC ,
               _______, KC_LALT, KC_LCTL, KC_LSFT, _______,                                        _______, KC_WH_D, KC_WH_U, _______, _______,
               _______, _______, _______, _______, _______, _______,                       KC_ENT , KC_BACKSPACE, _______
    ),
// /*
//  * Layer Function
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |Print |      |                                               | Mute |VolDn |VolUp |      |      |      
//  *                 |      |      |      |Screen|      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |  F1  |  F2  |  F3  |  F4  |  F5  |                                               |  F6  |  F7  |  F8  |  F9  |  F10 |
//  *                 |  GUI | LALT | LCTL | LSFT |      |                                               |      | LSFT | LCTL |  ALT |  GUI |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      | F11  | F12  |      |                                               | Play |M Prev|M Next|      |      |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             |      |      |                                 |      |      |
//  *                                             |      |      |                                 |      |      |
//  *                                             `-------------'                                 `-------------'
//  */
     [_FUN] = LAYOUT(
                _______, _______, _______, KC_PSCR, _______,                                        KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
                GUI_F1 , ALT_F2 , CTL_F3 , SFT_F4 , KC_F5  ,                                        KC_F6  , SFT_F7 , CTL_F8 , ALT_F9 , GUI_F10,
                _______, _______, KC_F11 , KC_F12 , _______,                                        KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
                _______, _______, _______, _______, _______, _______,                      _______, _______, _______
     ),


// /*
//  * Symbol layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   \  |   |  |  <   |   >  |      |                                               |      |  €   |  (   |  )   |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   \  |      |      |  [   |  ]   |                                               |      |      |      |  -   |  $   |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |   #  |   &  |   @  |   {  |                                               |   }  |      |  ;   |  _   |  *   |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             |      |      |                                 |      |      |
//  *                                             |      |      |                                 |      |      |
//  *                                             `-------------'                                 `-------------'
//  */

     [_SYMB] = LAYOUT(
                HU_BSLS, HU_PIPE, HU_LABK, HU_RABK, _______,                                        _______, HU_EURO, HU_LPRN, HU_RPRN, _______,
                HU_BSLS, _______, _______, HU_LBRC, HU_RBRC,                                        _______, _______, _______, HU_MINS, HU_DLR ,
                _______, HU_HASH, HU_AMPR, HU_AT  , HU_LCBR,                                        HU_RCBR, _______, HU_SCLN, HU_UNDS, HU_ASTR,
                _______, _______, _______, _______, KC_SPC , KC_TAB,                       KC_ENT , _______, _______
     ),
	 
// /*
//  * Number Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   ~  |   ˇ  |   ^  |   ˘  |  °   |                                               |   ˛  |   `  |  ˙   |  ´   |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   1  |   2  |   3  |   4  |   5  |                                               |   6  |   7  |   8  |  9   |  0   |
//  *                 | GUI  | LALT | LCTL | LSFT |      |                                               |      | LSFT | LCTL | ALT  | GUI  |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   '  |   "  |   +  |   !  |  %   |                                               |   /  |   =  |   (  |  )   |  §   |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             |      |      |                                 |      |      |
//  *                                             |      |      |                                 |      |      |
//  *                                             `-------------'                                 `-------------'
//  */
    [_NUM] = LAYOUT(
               HU_TILD, HU_CARN, HU_CIRC, HU_BREV, HU_RNGA,                                        HU_OGON, HU_GRV , HU_DOTA, HU_ACUT, _______,
               GUI_1  , ALT_2  , CTL_3  , SFT_4  , HU_5   ,                                        HU_6,    SFT_7  , CTL_8  , ALT_9  , GUI_0  ,
               HU_QUOT, HU_DQUO, HU_PLUS, HU_EXLM, HU_PERC,                                        HU_SLSH, HU_EQL , HU_LPRN, HU_RPRN, HU_SECT,
               _______, _______, _______, _______, KC_SPC , KC_TAB,                     _______ , KC_BACKSPACE, _______
    ),

// /*
//  * Number Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |  Ü   |  Í   |  Ö   |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               |      |  Ú   |  É   |  Ó   |  Á   |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               |      |  Ű   |      |  Ő   |      |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             |      |      |                                 | Enter|      |
//  *                                             |      |      |                                 |      |      |
//  *                                             `-------------'                                 `-------------'
//  */
    [_HUN] = LAYOUT(
               _______, _______, _______, _______, _______,                                        _______, HU_UDIA, HU_IACU, HU_ODIA, _______,
               _______, _______, _______, _______, _______,                                        _______, HU_UACU, HU_EACU, HU_OACU, HU_AACU,
               _______, _______, _______, _______, _______,                                        _______, HU_UDAC, _______, HU_ODAC, _______,
               _______, _______, _______, _______, _______, _______,                     _______ , _______, _______
    ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
        case GUI_P:
        case GUI_F1:
        case GUI_F10:
        case GUI_1:
        case GUI_0:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}

