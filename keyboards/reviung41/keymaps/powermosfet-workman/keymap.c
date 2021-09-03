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
    _SYMBOLS,
    _ARROWS,
    _FN
};

#define SYMBOLS  MO(_SYMBOLS)
#define ARROWS  MO(_ARROWS)
#define FN MO(_FN)

#define SPACE  LSFT_T(KC_SPACE)
#define A_TAB  LALT_T(KC_TAB)
#define G_ESC  LGUI_T(KC_ESCAPE)
#define A_BSPC RALT_T(KC_BSPACE)
#define G_ENT  RGUI_T(KC_ENTER)

enum custom_keycodes {
    LEFT = SAFE_RANGE,
    RIGHT,
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

        case LPIZZA:
            SEND_STRING("<|");
            break;

        case RPIZZA:
            SEND_STRING("|>");
            break;

        case RBIND:
            SEND_STRING("=<<");
            break;

        case LBIND:
            SEND_STRING(">>=");
            break;
        }
    }

    return true;
};

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, 0, 0, 50}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {10, 1, HSV_YELLOW}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_layer4_layer
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    A_TAB,    KC_Q,     KC_D,     KC_R,     KC_W,      KC_B,               KC_J,     KC_F,     KC_U,     KC_P,     XXXXXXX,  A_BSPC,  
    G_ESC,    KC_A,     KC_S,     KC_H,     KC_T,      KC_G,               KC_Y,     KC_N,     KC_E,     KC_O,     KC_I,     G_ENT,  
    KC_LCTL,  KC_Z,     KC_X,     KC_M,     KC_C,      KC_V,               KC_K,     KC_L,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RCTL,

                                  KC_TAB,         SYMBOLS,       SPACE,         ARROWS,        XXXXXXX
  ),
  
  [_SYMBOLS] = LAYOUT_reviung41(
    KC_HASH,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,   KC_GRAVE,           KC_QUOT,  KC_7,     KC_8,     KC_9,     KC_PAST,  _______,
    KC_SCLN,  KC_AMPR,  KC_DLR,   KC_LPRN,  KC_RPRN,   KC_PIPE,            KC_COLN,  KC_4,     KC_5,     KC_6,     KC_PPLS,  KC_MINS,
    _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,   KC_TILD,            KC_DQUO,  KC_1,     KC_2,     KC_3,     _______,  KC_EQL,

                                  _______,        _______,       _______,       _______,       KC_0  
  ),
  
  [_ARROWS] = LAYOUT_reviung41(
    _______,  _______,  _______,  LEFT,     RIGHT,     _______,            KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_END,   KC_VOLU,
    _______,  _______,  _______,  LPIZZA,   RPIZZA,    _______,            KC_INS,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,   KC_VOLD,
    _______,  _______,  _______,  LBIND,    RBIND,     _______,            _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,  KC_MUTE,

                                  _______,        _______,       _______,       _______,       _______
  ),
  
  [_FN] = LAYOUT_reviung41(
    KC_PWR,   _______,  _______,  _______,  _______,   _______,            _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, 
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  KC_F4,    KC_F5,    KC_F6,    KC_F12,   KC_F13, 
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  KC_F1,    KC_F2,    KC_F3,    KC_BSLS,  _______,

                                  _______,       _______,        _______,       _______,       _______
  ),
};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOLS, _ARROWS, _FN);

    rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOLS));
    rgblight_set_layer_state(2, layer_state_cmp(state, _ARROWS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN));

    return state;
}


