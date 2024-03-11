#ifdef ENCODER_ENABLE

#    ifdef MOUSEKEY_ENABLE
#        define SCROLL_U KC_MS_WH_UP
#        define SCROLL_D KC_MS_WH_DOWN
#    else
#        define SCROLL_U KC_PGUP
#        define SCROLL_D KC_PGDN
#    endif

// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_VOLU,     KC_VOLD), ENCODER_CCW_CW(SCROLL_D,     SCROLL_U     )},
    [_RISE] = { ENCODER_CCW_CW(_______,     _______), ENCODER_CCW_CW(_______,      _______      )},
    [_LOWR] = { ENCODER_CCW_CW(_______,     _______), ENCODER_CCW_CW(LCA(KC_RIGHT), LCA(KC_LEFT))},
    [_CONF] = { ENCODER_CCW_CW(_______,     _______), ENCODER_CCW_CW(_______,      _______      )},
    [_ADJT] = { ENCODER_CCW_CW(_______,     _______), ENCODER_CCW_CW(_______,      _______      )},
};
// clang-format on

#endif
