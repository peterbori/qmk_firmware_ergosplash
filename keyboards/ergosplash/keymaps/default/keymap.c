#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _NAVR,
	_HUN,
    //_SYMB,
    _NUMR,
    //_FUNL,
    //_ADJL
};

// Aliases for readability
#define BASE     DF(_BASE)
#define NAVR     MO(_NAVR)
#define HUN      MO(_HUN)
#define SYMB     MO(_SYMB)
#define NUMR     MO(_NUMR)
#define FUNL     MO(_FUNL)
#define ADJL     MO(_ADJL)

// Left-hand home row mods
#define RALT_X  RALT_T(KC_X)
#define GUI_A   LGUI_T(KC_A)
#define ALT_S   LALT_T(KC_S)
#define CTL_D   LCTL_T(KC_D)
#define SFT_F   LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J   RSFT_T(KC_J)
#define CTL_K   RCTL_T(KC_K)
#define ALT_L   LALT_T(KC_L)
#define GUI_SCL RGUI_T(KC_SCLN)
#define RALT_DT RALT_T(KC_DOT)

// Left-hand outer column
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define SFT_TAB  MT(MOD_LSFT, KC_TAB)

// Thumbcluster
#define TAB_NUM LT(NUMR, KC_TAB)
#define SPC_NAV LT(NAVR, KC_SPC)
#define BSPC_HUN LT(HUN, KC_BACKSPACE)

//#define UC_TR3 LT(FUNL, KC_BSPC)
//#define UC_TR2 LT(SYMB, KC_ENT)
#define UC_TR1 KC_BTN2

// Shortcuts
#define UC_COPY LCTL(KC_C)
#define UC_PSTE LCTL(KC_V)
#define UC_CUT  LCTL(KC_X)
#define UC_OSFT OSM(MOD_LSFT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// /*
//  * Base Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   Q  |   W  |   E  |   R  |   T  |                                               |   Y  |   U  |   I  |   O  |   P  |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   A  |   S  |   D  |   F  |   G  |                                               |   H  |   J  |   K  |   L  |  ; : |
//  *                 |  GUI | LALT | LCTL | LSFT |      |                                               |      | LSFT | LCTL |  ALT |  GUI |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   Z  |   X  |   C  |   F  |   B  |                                               |   N  |   M  |  , < |  . > |  / ? |
//  *                 |      | RALT |      |      |      |                                               |      |      |      | RALT |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             | Space| TAB  |                                 |Enter |BckSpc|
//  *                                             | NAVR | NUM  |                                 |      | HUN  |
//  *                                             `-------------'                                 `-------------'
//  */
    [_BASE] = LAYOUT(
               KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
               KC_A   , ALT_S  , CTL_D  , SFT_F  , KC_G   ,                                        KC_H   , SFT_J  , CTL_K  , ALT_L  , KC_SCLN,
               KC_Z   , RALT_X , KC_C   , KC_V   , KC_B   ,                                        KC_N   , KC_M   , KC_COMM, RALT_DT, KC_SLSH,
                                                   SPC_NAV, TAB_NUM,                      KC_ENT, BSPC_HUN
    ),

// /*
//  * Navigation Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |Insert| Cut  | PgUp | PgDn | ESC  |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               | Copy |   ←  |   ↑  |   ↓  |   →  |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               | Paste| Home | WH_U | WH_D | End  |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                          ,-------------+------+---------------------------'
//  *                                             |      |      |                          |  ESC |  Del |
//  *                                             |      |      |                          |      |      |
//  *                                             `-------------'                          `-------------'
//  */
    [_NAVR] = LAYOUT(
               _______, _______, _______, _______, _______,                                        KC_INS , UC_CUT , KC_PGUP, KC_PGDN, _______,
               _______, _______, _______, _______, _______,                                        UC_COPY, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT,
               _______, _______, _______, _______, _______,                                        UC_PSTE, KC_HOME, KC_WH_U, KC_WH_D, KC_END ,
                                                   _______, _______,                       KC_ESC, KC_DEL
    ),
// /*
//  * Layer HUN lower
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |   Ö  |   Í  |   Ü  |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |   Á  |   Ó  |   É  |   Ú  |      |                                               |      |      |      |      |      |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |   Ő  |      |   Ű  |      |                                               |      |      |      |      |      |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             |      |      |                                 |      |      |
//  *                                             |      |      |                                 |      |      |
//  *                                             `-------------'                                 `-------------'
//  */
     [_HUN] = LAYOUT(
                _______,    KC_0, KC_NUBS, KC_MINS, _______,                                        _______, _______, _______, _______, _______,
                KC_QUOT,  KC_EQL, KC_SCLN, KC_RBRC, _______,                                        _______, _______, _______, _______, _______,
                _______, KC_LBRC, _______, KC_NUHS, _______,                                        _______, _______, _______, _______, _______,
                                                    _______, _______,                      _______, _______
     ),


// /*
//  * Symbol Layer (Right)
//  
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |   `  |   ~  |   |  |   \  |      |                                               |      |   /  |   +  |   =  |   ?  |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |   !  |   @  |   #  |   $  |   %  |                                               |   ^  |   &  |   *  |   (  |   )  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |   :  |   ;  |   -  |   [  |   {  |                                               |   }  |   ]  |   _  |   ,  |   .  |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space| TAB  |                   | Bksp | Enter|      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  *
    /*[_SYMB] = LAYOUT(
               KC_GRV , KC_TILD, KC_PIPE, KC_BSLS, _______,                                        _______, KC_SLSH, KC_PLUS, KC_EQL , KC_QUES,
      _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
      _______, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR,                                        KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM, KC_DOT , _______,
                                                   _______, KC_SPC , KC_TAB  ,   KC_BSPC, KC_ENT , _______ 
    ),*/

// /*
//  * Number Layer (Right)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |   /  |   7  |   8  |   9  |  -   |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               |   *  |   4  |   5  |  6   |  +   |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               |   0  |   1  |   2  |  3   |  .   |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             |      |      |                                 | Enter|      |
//  *                                             |      |      |                                 |      |      |
//  *                                             `-------------'                                 `-------------'
//  */
    [_NUMR] = LAYOUT(
               _______, _______, _______, _______, _______,                                        KC_SLSH, KC_7   , KC_8   , KC_9   , KC_MINS,
               _______, _______, _______, _______, _______,                                        KC_ASTR, KC_4   , KC_5   , KC_6   , KC_PLUS,
               _______, _______, _______, _______, _______,                                        KC_0   , KC_1   , KC_2   , KC_3   , KC_DOT ,
                                                   _______, _______,                     _______ , _______ 
    ),

// /*
//  * Function Layer (Left)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |  F12 |  F7  |  F8  |  F9  | Pause|                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |  F11 |  F4  |  F5  |  F6  | PrScr|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |  F10 |  F1  |  F2  |  F3  | CapsL|                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space|  TAB |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    /*[_FUNL] = LAYOUT(
               KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PAUS,                                        _______, _______, _______, _______, _______,
      _______, KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_PSCR,                                        _______, _______, _______, _______, _______, _______,
      _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_CAPS,                                        _______, _______, _______, _______, _______, _______,
                                                   _______, KC_SPC , KC_TAB  ,    _______, _______, _______
    ),*/

// /*
//  * Adjustment Layer (Left)
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *          ,------+------+------+------+------+------|                                               |------+------+------+------+------+------.
//  *          |      |M Prev| VolDn| VolDn|M Next|      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          |------+------+------+------+------+------|                                               |------+------+------+------+------+------|
//  *          |      |      |      | Mute | Play |      |                                               |      |      |      |      |      |      |
//  *          |      |      |      |      |      |      |                                               |      |      |      |      |      |      |
//  *          `----------------------------------+------+-------------.                   ,-------------+------+----------------------------------'
//  *                                             |      | Space| TAB  |                   |      |      |      |
//  *                                             |      |      |      |                   |      |      |      |
//  *                                             `--------------------'                   `--------------------'
//  */
    /*[_ADJL] = LAYOUT(
               _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
      _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,                                        _______, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_MUTE, KC_MPLY, _______,                                        _______, _______, _______, _______, _______, _______,
                                                   _______, KC_SPC , KC_TAB  ,    _______, _______, _______
    ),*/

// -------------------------------------------------------- TEMPLATE -------------------------------------------------------------------------------------
// /*
//  * Layer
//  *
//  *                 ,----------------------------------.                                               ,----------------------------------.
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |      
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |------+------+------+------+------|                                               |------+------+------+------+------|
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 |      |      |      |      |      |                                               |      |      |      |      |      |
//  *                 `---------------------------+------+------.                                 ,------+------+---------------------------'
//  *                                             |      |      |                                 |      |      |
//  *                                             |      |      |                                 |      |      |
//  *                                             `-------------'                                 `-------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//                _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//                _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//                _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______,
//                                                    _______, _______,                      _______, _______
//     ),
// --------------------------------------------------------------------------------------------------------------------------------------------------------
};

// uncomment this and modify the timings if the home row mods are not working for you
/*
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
            return TAPPING_TERM + 150;
        case ALT_S:
            return TAPPING_TERM + 50;
        case ALT_L:
            return TAPPING_TERM + 50;
        case GUI_SCL:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
*/
