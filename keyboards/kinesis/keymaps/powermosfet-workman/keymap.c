#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NOR,
    _SYMBOLS,
    _NUMBERS
};

#define SYMBOLS  MO(_SYMBOLS)
#define NUMBERS  MO(_NUMBERS)
#define NOR      MO(_NOR)

#define C_ESC    LCTL_T(KC_ESCAPE)
#define SYM_BSP  LT(_SYMBOLS, KC_BSPACE)
#define NUM_SPC  LT(_SYMBOLS, KC_SPC)
#define KZ_LOCK  LCTL(LGUI(KC_Q))
#define NOR_AA   RALT(KC_W)
#define NOR_OE   RALT(KC_L)
#define NOR_AE   RALT(KC_Z)

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

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
           KC_ESC,  KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL,  KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_LALT, KC_Q   ,KC_D   ,KC_R   ,KC_W   ,KC_B   ,
           KC_LCTL, KC_A   ,KC_S   ,KC_H   ,KC_T   ,KC_G   ,
           KC_LGUI, KC_Z   ,KC_X   ,KC_M   ,KC_C   ,KC_V   ,
                    _______,_______,_______,_______,

			     KC_LCTL, KC_LALT,
                                      KC_HOME,
                    SYM_BSP, KC_DEL , KC_END ,

    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_NO, RESET,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   , KC_MINS,
	KC_J   ,KC_F   ,KC_U   ,KC_P   ,NOR    , KC_RALT,
	KC_Y   ,KC_N   ,KC_E   ,KC_O   ,KC_I   , KC_RCTL,
	KC_K   ,KC_L   ,KC_COMM,KC_DOT ,KC_SLSH, KC_RGUI,
		_______,_______,_______,_______,

           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,NUM_SPC
    ),
[_NOR] = LAYOUT(
           _______, _______,_______,_______,_______,_______,_______,_______,_______,
           _______, _______,_______,_______,_______,_______,
           _______, KZ_LOCK,_______,_______,_______,_______,
           _______, _______,_______,_______,_______,_______,
           _______, _______,_______,_______,_______,_______,
                    _______,_______,_______,_______,

			     _______, _______,
                                      _______,
                    _______, _______, _______,

        _______,_______,_______,_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,NOR_OE, NOR_AA, NOR_AE, _______,_______,
	_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
		_______,_______,_______,_______,

           _______,_______,
           _______,
           _______,_______, _______
    ),
[_SYMBOLS] = LAYOUT(
           _______, _______,_______,_______,_______,_______,_______,_______,_______,
           _______, _______,_______,_______,_______,_______,
           _______, KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_GRAVE,
           _______, KC_AMPR,KC_DLR, KC_LPRN,KC_RPRN,KC_PIPE,
           _______, KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,
                    _______,_______,_______,_______,

			     _______, _______,
                                      _______,
                    _______, _______, _______,

        _______,_______,_______,_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
	KC_QUOT,FATLEFT,LEFT,   RIGHT,  FATRGHT,_______,
	KC_COLN,KC_SCLN,LPIZZA, RPIZZA, KC_EQL, _______,
	KC_DQUO,KC_HASH,LBIND,  RBIND,  KC_BSLS,_______,
		_______,_______,_______,_______,

           _______,_______,
           _______,
           _______,_______, _______
    ),
[_NUMBERS] = LAYOUT(
           _______, _______,_______,_______,_______,_______,_______,_______,_______,
           _______, _______,_______,_______,_______,_______,
           _______, KC_HOME,KC_PGUP,KC_UP,  KC_PGDN,KC_END, 
           _______, KC_INS, KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL, 
           _______, KC_VOLD,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLU,
                    _______,_______,_______,_______,

			     _______, _______,
                                      _______,
                    _______, KC_TAB,  _______,

        _______,_______,_______,_______,_______,_______,_______,_______,_______,
	_______,_______,_______,_______,_______,_______,
	KC_EQL, KC_P7,  KC_P8,  KC_P9,  KC_PAST,_______,
	KC_MINS,KC_P4,  KC_P5,  KC_P6,  KC_PPLS,_______,
	KC_MUTE,KC_P1,  KC_P2,  KC_P3,  _______,_______,
		KC_P0,  KC_P0,  KC_PDOT,_______,

           _______,_______,
           _______,
           _______,_______, _______
    )
};
