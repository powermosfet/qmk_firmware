/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NOR,
    _MOD,
    _SYMBOLS,
    _NUMBERS,
    _FN
};

#define SYMBOLS  TT(_SYMBOLS)
#define NUMBERS  TT(_NUMBERS)
#define FN       MO(_FN)
#define NOR      MO(_NOR)

#define MC_S     LCTL_T(KC_S)
#define MM_H     LGUI_T(KC_H)
#define MA_T     LALT_T(KC_T)
#define MC_O     LCTL_T(KC_O)   
#define MM_E     LGUI_T(KC_E)   
#define MA_N     LALT_T(KC_N)
#define SYM_ESC  LT(_SYMBOLS, KC_ESCAPE)
#define NUM_ENT  LT(_NUMBERS, KC_ENTER)
#define MOD_SPC  LT(_MOD, KC_SPACE)
#define A_TAB    LALT_T(KC_TAB)
#define G_ESC    LGUI_T(KC_ESCAPE)
#define A_BSPC   RALT_T(KC_BSPACE)
#define G_ENT    RGUI_T(KC_ENTER)
#define NOR_AA   RALT(KC_W)
#define NOR_OE   RALT(KC_L)
#define NOR_AE   RALT(KC_Z)
#define SH_Z     LSFT_T(KC_Z)
#define SH_Q     LSFT_T(KC_Q)
#define SH_SLSH  LSFT_T(KC_SLSH)
#define AMETHYST LSFT(KC_LALT)
#define MLCTRL   LCTL_T(KC_S)
#define MLGUI    LGUI_T(KC_H)
#define MLALT    LALT_T(KC_T)
#define MRCTRL   RCTL_T(KC_O)
#define MRGUI    RGUI_T(KC_E)
#define MRALT    RALT_T(KC_N)
#define LOCK     LCTL(LGUI(KC_Q))
#define UNDRSCR  LSFT(KC_MINS)

enum custom_keycodes {
    LEFT = SAFE_RANGE,
    RIGHT,
    FATRGHT,
    FATLEFT,
    LPIZZA,
    RPIZZA,
    LBIND,
    RBIND,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case LEFT:
            SEND_STRING("<-");
            break;

        case RIGHT:
            SEND_STRING("->");
            break;

        case FATLEFT:
            SEND_STRING("<=");
            break;

        case FATRGHT:
            SEND_STRING("=>");
            break;

        case LPIZZA:
            SEND_STRING("<|");
            break;

        case RPIZZA:
            SEND_STRING("|>");
            break;

        case LBIND:
            SEND_STRING("=<<");
            break;

        case RBIND:
            SEND_STRING(">>=");
            break;
        }
    }

    return true;
};

const rgblight_segment_t PROGMEM rgb_base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, 0, 0, 50}
);
const rgblight_segment_t PROGMEM rgb_nor[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, 0, 0, 50}
);
const rgblight_segment_t PROGMEM rgb_mod[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM rgb_symbols[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM rgb_arrows[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM rgb_fn[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_base,
    rgb_nor,
    rgb_mod,
    rgb_symbols,
    rgb_arrows,
    rgb_fn
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_LALT,  SH_Q,     KC_D,     KC_R,     KC_W,      KC_B,               KC_J,     KC_F,     KC_U,     KC_P,     NOR,      KC_RALT,
    KC_LGUI,  KC_A,     KC_S,     KC_H,     KC_T,      KC_G,               KC_Y,     KC_N,     KC_E,     KC_O,     KC_I,     KC_RGUI,
    KC_LCTL,  SH_Z,     KC_X,     KC_M,     KC_C,      KC_V,               KC_K,     KC_L,     KC_COMM,  KC_DOT,   SH_SLSH,  KC_RCTL,

                                  XXXXXXX,        SYM_ESC,       MOD_SPC,       NUM_ENT,       XXXXXXX 
  ),
  
  [_NOR] = LAYOUT_reviung41(
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  NOR_OE,   NOR_AA,   NOR_AE,   _______,  XXXXXXX,
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  XXXXXXX,
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  XXXXXXX,

                                  XXXXXXX,       _______,        _______,       _______,       XXXXXXX
  ),
  
  [_MOD] = LAYOUT_reviung41(
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  XXXXXXX,
    XXXXXXX,  _______,  MC_S,     MM_H,     MA_T,      _______,            _______,  MA_N,     MM_E,     MC_O,     _______,  XXXXXXX,
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______,  _______,  XXXXXXX,

                                  XXXXXXX,       KC_SPACE,       _______,       _______,       XXXXXXX
  ),
  
  [_SYMBOLS] = LAYOUT_reviung41(
    XXXXXXX,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,   KC_GRAVE,           KC_QUOT,  FATLEFT,  LEFT,     RIGHT,    FATRGHT,  XXXXXXX,
    XXXXXXX,  KC_AMPR,  KC_DLR,   KC_LPRN,  KC_RPRN,   KC_PIPE,            KC_COLN,  KC_SCLN,  LPIZZA,   RPIZZA,   UNDRSCR,  XXXXXXX,
    XXXXXXX,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,   KC_TILD,            KC_DQUO,  KC_HASH,  LBIND,    RBIND,    KC_BSLS,  XXXXXXX,

                                  XXXXXXX,        _______,       KC_BSPC,       _______,       XXXXXXX
  ),
  
  [_NUMBERS] = LAYOUT_reviung41(
    XXXXXXX,  KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,   KC_END,             KC_EQL,   KC_7,     KC_8,     KC_9,     KC_PAST,  XXXXXXX,
    XXXXXXX,  KC_INS,   KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_DEL,             KC_MINS,  KC_4,     KC_5,     KC_6,     KC_PLUS,  XXXXXXX,
    XXXXXXX,  KC_VOLD,  KC_MPRV,  KC_MPLY,  KC_MNXT,   KC_VOLU,            KC_MUTE,  KC_1,     KC_2,     KC_3,     KC_0,     XXXXXXX,

                                  XXXXXXX,        _______,       KC_TAB,        _______,       XXXXXXX
  ),
  
  [_FN] = LAYOUT_reviung41(
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   XXXXXXX,
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  KC_F4,    KC_F5,    KC_F6,    KC_F11,   XXXXXXX,
    XXXXXXX,  _______,  _______,  _______,  _______,   _______,            _______,  KC_F1,    KC_F2,    KC_F3,    KC_F12,   XXXXXXX,

                                  XXXXXXX,       _______,        KC_PWR,        _______,       XXXXXXX
  ),
};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS, _NUMBERS, _FN);

    rgblight_set_layer_state(1, layer_state_cmp(state, _NOR));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOD));
    rgblight_set_layer_state(3, layer_state_cmp(state, _SYMBOLS));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUMBERS));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FN));

    return state;
}


