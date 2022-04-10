#include QMK_KEYBOARD_H

enum layers{
    BASE,
    META,
    UTIL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt               Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       =	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    [BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        MO(META),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(META),KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [META] = LAYOUT(
        XXXXXXX, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_INS,           XXXXXXX,
        XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PMNS, KC_PPLS, KC_DEL,           KC_NUM,
        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS, KC_CAPS,          KC_PSLS,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,  KC_DEL,           KC_KP_ENTER,      KC_PAST,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, KC_F14,  KC_PDOT,
        _______, KC_APP,  _______,                            KC_LCTL,                            MO(UTIL),_______, _______, KC_MPRV, KC_MPLY, KC_MNXT
    ),

    [UTIL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPI,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_SPD,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RGB_SAI,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          RESET,            RGB_SAD,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_VAI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            _______, _______, XXXXXXX, RGB_RMOD,RGB_VAD, RGB_MOD
    ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) == UTIL) {
        if (clockwise) {
            rgblight_increase_hue_noeeprom();
        } else {
            rgblight_decrease_hue_noeeprom();
        }
    } else {
        if (get_mods() & MOD_BIT(KC_LCTRL)) {
            if (clockwise) {
                tap_code16(KC_RGHT);
            } else {
                tap_code16(KC_LEFT);
            }
        } else if (get_mods() & MOD_BIT(KC_LALT)) {
            if (clockwise) {
                tap_code16(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
        } else {
            if (clockwise) {
                tap_code16(KC_VOLU);
            } else {
                tap_code16(KC_VOLD);
            }
        }
    }
    return false;
};

// led number, function of the key
//  0, ESC    6, F1     12, F2     18, F3     23, F4     28, F5     34, F6     39, F7     44, F8     50, F9     56, F10    61, F11    66, F12    69, Prt     Rotary(Mute)
//  1, ~      7, 1      13, 2      19, 3      24, 4      29, 5      35, 6      40, 7      45, 8      51, 9      57, 0      62, -_     78, (=+)   85, BackSpc 72, Del
//  2, Tab    8, Q      14, W      20. E      25, R      30, T      36, Y      41, U      46, I      52, O      58, P      63, [{     89, ]}     93, \|      75, PgUp
//  3, Caps   9, A      15, S      21, D      26, F      31, G      37, H      42, J      47, K      53, L      59, ;:     64, '"                96, Enter   86, PgDn
//  4, Sh_L   10, Z     16, X      22, C      27, V      32, B      38, N      43, M      48, ,<     54, .<     60, /?                90, Sh_R   94, Up      82, End
//  5, Ct_L   11,Win_L  17, Alt_L                        33, SPACE                        49, Alt_R  55, FN                65, Ct_R   95, Left   97, Down    79, Right
//
// 67, Side01 68, Side12
// 70, Side02 71, Side13
// 73, Side03 74, Side14
// 76, Side04 77, Side15
// 80, Side05 81, Side16
// 83, Side06 84, Side17
// 87, Side07 88, Side18
// 91, Side08 92, Side19

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // capslock warning
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        RGB_MATRIX_INDICATOR_SET_COLOR(3, 255, 0, 0);
    }
};

// turn off LEDs on USB suspend event
void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
};
// turn on LEDs on USB wake event
void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
};