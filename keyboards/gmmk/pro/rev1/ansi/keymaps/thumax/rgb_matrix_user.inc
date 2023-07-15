// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(RGB_THUMAX_MIAMI_SIDES)
RGB_MATRIX_EFFECT(RGB_THUMAX_AWAKEN_SIDES)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool RGB_THUMAX_MIAMI_SIDES(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, RGB_OFF);
    }
    // set left sidebar
    rgb_matrix_set_color(67, 255, 0, 255);
    rgb_matrix_set_color(70, 182, 0, 255);
    rgb_matrix_set_color(73, 109, 0, 255);
    rgb_matrix_set_color(76, 36, 0, 255);
    rgb_matrix_set_color(80, 0, 36, 255);
    rgb_matrix_set_color(83, 0, 109, 255);
    rgb_matrix_set_color(87, 0, 182, 255);
    rgb_matrix_set_color(91, 0, 255, 255);
    // set right sidebar
    rgb_matrix_set_color(68, 255, 0, 255);
    rgb_matrix_set_color(71, 182, 0, 255);
    rgb_matrix_set_color(74, 109, 0, 255);
    rgb_matrix_set_color(77, 36, 0, 255);
    rgb_matrix_set_color(81, 0, 36, 255);
    rgb_matrix_set_color(84, 0, 109, 255);
    rgb_matrix_set_color(88, 0, 182, 255);
    rgb_matrix_set_color(92, 0, 255, 255);
    return rgb_matrix_check_finished_leds(led_max);
}

static bool RGB_THUMAX_AWAKEN_SIDES(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, RGB_OFF);
    }
    // set left sidebar
    rgb_matrix_set_color(67, 244, 54, 76);
    rgb_matrix_set_color(70, 208, 108, 200);
    rgb_matrix_set_color(73, 158, 140, 231);
    rgb_matrix_set_color(76, 108, 163, 235);
    rgb_matrix_set_color(80, 0, 191, 224);
    rgb_matrix_set_color(83, 68, 210, 174);
    rgb_matrix_set_color(87, 127, 216, 133);
    rgb_matrix_set_color(91, 253, 207, 73);
    // set right sidebar
    rgb_matrix_set_color(68, 244, 54, 76);
    rgb_matrix_set_color(71, 208, 108, 200);
    rgb_matrix_set_color(74, 158, 140, 231);
    rgb_matrix_set_color(77, 108, 163, 235);
    rgb_matrix_set_color(81, 0, 191, 224);
    rgb_matrix_set_color(84, 68, 210, 174);
    rgb_matrix_set_color(88, 127, 216, 133);
    rgb_matrix_set_color(92, 253, 207, 73);
    return rgb_matrix_check_finished_leds(led_max);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

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