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

#define SPACE  LSFT_T(KC_SPC)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    KC_TAB,   KC_Q,     KC_D,     KC_R,     KC_W,      KC_B,               KC_J,     KC_F,     KC_U,     KC_P,     XXXXXXX,  KC_BSPC,
    KC_ESC,   KC_A,     KC_S,     KC_H,     KC_T,      KC_G,               KC_Y,     KC_N,     KC_E,     KC_O,     KC_I,     KC_ENT,
    KC_LALT,  KC_Z,     KC_X,     KC_M,     KC_C,      KC_V,               KC_K,     KC_L,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RALT,
                                            KC_RGUI,   SYMBOLS,  SPACE,    ARROWS,   KC_LCTL
  ),
  
  [_SYMBOLS] = LAYOUT_reviung41(
    KC_HASH,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,   KC_GRAVE,           KC_QUOT,  KC_7,     KC_8,     KC_9,     KC_PAST,  _______,
    KC_SCLN,  KC_AMPR,  KC_DLR,   KC_LPRN,  KC_RPRN,   KC_PIPE,            KC_COLN,  KC_4,     KC_5,     KC_6,     KC_PPLS,  KC_MINS,
    _______,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,   KC_TILD,            KC_DQUO,  KC_1,     KC_2,     KC_3,     _______,  KC_EQL,
                                            _______,   _______,  _______,  FN,       KC_0  
  ),
  
  [_ARROWS] = LAYOUT_reviung41(
    _______,  _______,  _______,  _______,  _______,   _______,            KC_HOME,  KC_PGUP,  KC_UP,    KC_PGDN,  KC_END,   KC_VOLU,
    _______,  _______,  _______,  _______,  _______,   _______,            KC_INS,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,   KC_VOLD,
    _______,  _______,  _______,  _______,  _______,   _______,            _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  _______,  KC_MUTE,
                                            _______,   FN,       _______,  _______,  _______
  ),
  
  [_FN] = LAYOUT_reviung41(
    XXXXXXX,   XXXXXXX, LEFT,     RIGHT,    XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, 
    XXXXXXX,   XXXXXXX, LPIZZA,   RPIZZA,   XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F12,   KC_F13, 
    XXXXXXX,   XXXXXXX, LBIND,    RBIND,    XXXXXXX,   XXXXXXX,            XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_BSLS,  XXXXXXX,
                                            _______,   _______,  _______,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMBOLS, _ARROWS, _FN);
}

