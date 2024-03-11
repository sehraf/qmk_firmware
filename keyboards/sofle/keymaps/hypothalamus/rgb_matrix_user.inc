// !!! DO NOT ADD #pragma once !!! //

RGB_MATRIX_EFFECT(static_overlay)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// static bool static_overlay(effect_params_t* params) {
//     RGB_MATRIX_USE_LIMITS(led_min, led_max);

//     const uint8_t OFFSET = 36;

//     for (uint8_t i = led_min; i < led_max; i++) {
//         RGB_MATRIX_TEST_LED_FLAGS();

//         switch (i) {
//             // number keys (row)
//             case 12:
//             case 21:
//             case 22:
//             case 31:
//             case 32:
//             case OFFSET + 12:
//             case OFFSET + 21:
//             case OFFSET + 22:
//             case OFFSET + 31:
//             case OFFSET + 32:
//                 rgb_matrix_set_color(i, numrow.r, numrow.g, numrow.b);
//                 break;
//             // arrow keys
//             case OFFSET + 25:
//             case OFFSET + 28:
//             case OFFSET + 29:
//             case OFFSET + 35:
//                 rgb_matrix_set_color(i, arrow.r, arrow.g, arrow.b);
//                 break;
//             default:
//                 rgb_matrix_set_color(i, baseline.r, baseline.g, baseline.b);
//         }
//     }
//     return rgb_matrix_check_finished_leds(led_max);
// }

static HSV static_overlay_math(HSV hsv, uint8_t i, uint8_t time) {
    const uint8_t OFFSET = 36;

    const HSV baseline = (HSV){HSV_BLACK};
    const HSV numrow   = (HSV){HSV_GOLDENROD};
    const HSV arrow    = (HSV){HSV_SPRINGGREEN};
    const HSV gnome    = (HSV){HSV_TEAL};

#    define MIRROR(a) \
        case (a):     \
        case OFFSET + (a):

    switch (i) {
        // number keys (row)
        MIRROR(12)
        MIRROR(21)
        MIRROR(22)
        MIRROR(31)
        MIRROR(32)
        case OFFSET + 10: // F11
        case OFFSET + 11: // F12
            hsv.h = numrow.h;
            break;
        // arrow keys
        case OFFSET + 8:
        case OFFSET + 14:
        case OFFSET + 15:
        case OFFSET + 18:
            hsv.h = arrow.h;
            break;
        // Gnome desktop
        case 23:
        case 30:
            hsv.h = gnome.h;
            break;
        default:
            hsv.h = baseline.h;
    }
#    undef MIRROR
    return hsv;
}

bool static_overlay(effect_params_t* params) {
    return effect_runner_i(params, &static_overlay_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
