// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(zeibaleiste)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool zeibaleiste(effect_params_t* params) {
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
    return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS