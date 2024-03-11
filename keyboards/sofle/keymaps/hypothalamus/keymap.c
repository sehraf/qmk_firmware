
/* Copyright 2021 Dane Evans
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
// SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s, Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv, Override)

// clang-format off

#if 0
  // TEMPLATE
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     KC_LALT,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     KC_LSFT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       XXXXXXX,         XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   XXXXXXX,   KC_LGUI,  _______,        KC_SPC,           KC_ENT,            MO(4),   KC_RALT,   XXXXXXX,  XXXXXXX
    //

    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
#endif

enum sofle_layers {
    _DEFAULTS = 0,
    _BASE = 0,
    _LOWR,
    _RISE,
    _CONF,
    _ADJT
};

// clang-format on

static const char *get_layer_name(int layer) {
    switch (layer) {
        case _BASE:
            return PSTR("Base");
        case _LOWR:
            return PSTR("Lowr");
        case _RISE:
            return PSTR("Rise");
        case _CONF:
            return PSTR("Conf");
        case _ADJT:
            return PSTR("Adjt");
        default:
            return PSTR("Undef");
    }
};

/* ######################################
 * KEYMAP
 * #####################################*/
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/      KC_ESC,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,   KC_MINS,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,      KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                                             KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,    KC_EQL,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     KC_CAPS,      KC_A,      KC_S,      KC_D,      KC_F,      KC_G,                                             KC_H,      KC_J,      KC_K,      KC_L,   KC_SCLN,   KC_LBRC,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LSFT,      KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,       KC_MUTE,         KC_MPLY,             KC_N,      KC_M,   KC_COMM,    KC_DOT,   KC_SLSH,   KC_RBRC,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           KC_LCTL,   KC_LALT,   KC_LGUI, MO(_LOWR),       KC_SPC,           KC_SPC,       MO(_RISE),   KC_RALT,   KC_QUOT,   KC_BSPC
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_LOWR] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     XXXXXXX,     KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                                            KC_F6,     KC_F7,     KC_F8,     KC_F9,    KC_F10,    KC_F11,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     XXXXXXX,   XXXXXXX,XXXXXXX, LCA(KC_LEFT),LCA(KC_RIGHT),XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_F12,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                           KC_INS,   KC_HOME,   KC_PGUP,   KC_PSCR,     KC_UP,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     _______,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       KC_MUTE,         KC_MPLY,           KC_DEL,    KC_END,   KC_PGDN,   KC_LEFT,   KC_DOWN,  KC_RIGHT,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           _______,   KC_LALT,   KC_LGUI,   _______,       KC_ENT,           KC_ENT,         MO(_CONF),   KC_RALT,   XXXXXXX,  XXXXXXX
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_RISE] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     KC_LALT,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,   KC_EXLM,     KC_AT,   KC_HASH,    KC_DLR,   KC_PERC,                                          KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_BSPC,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     KC_LSFT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          KC_MINS,    KC_EQL,   KC_LBRC,   KC_RBRC,   KC_BSLS,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       KC_MUTE,         XXXXXXX,          KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   KC_PIPE,   KC_TILD,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   KC_LALT,   KC_LGUI, MO(_CONF),       KC_ENT,           KC_ENT,          XXXXXXX,   KC_RALT,   XXXXXXX,  XXXXXXX
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_CONF] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     KC_LALT,      KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,    KC_GRV,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     QK_BOOT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     RGB_TOG,   RGB_HUI,   RGB_SAI,   RGB_VAI,   RGB_SPI,   XXXXXXX,                                        DF(_ADJT),   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     RGB_MOD,   RGB_HUD,   RGB_SAD,   RGB_VAD,   RGB_SPD,   XXXXXXX,       KC_MUTE,         XXXXXXX,          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   XXXXXXX,   KC_LGUI,   XXXXXXX,       KC_SPC,           KC_ENT,          XXXXXXX,   KC_RALT,   XXXXXXX,  XXXXXXX
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),

  [_ADJT] = LAYOUT(
    //   ,-----------------------------------------------------------------.                                      .-----------------------------------------------------------------,
    /**/     XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX, DF(_BASE),
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/      KC_TAB,      KC_Q,      KC_W,      KC_E,   XXXXXXX,   XXXXXXX,                                          XXXXXXX,   XXXXXXX,     KC_UP,   XXXXXXX,      KC_P,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------|                                      |----------+----------+----------+----------+----------+----------|
    /**/     XXXXXXX,      KC_A,      KC_S,      KC_D,      KC_F,   XXXXXXX,                                          XXXXXXX,   KC_LEFT,   KC_DOWN,  KC_RIGHT,   XXXXXXX,   XXXXXXX,
    //   |----------+----------+----------+----------+----------+----------+--------------.        .--------------+----------+----------+----------+----------+----------+----------|
    /**/     KC_LCTL,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,       KC_MUTE,         XXXXXXX,          XXXXXXX,      KC_M,   XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_ESC,
    //   `----------+----------+----------+----------+----------+----------/--------------/        \--------------\----------+----------+----------+----------+----------+----------|
    /**/                           XXXXXXX,   XXXXXXX,   XXXXXXX,    KC_TAB,       KC_SPC,           KC_ENT,          XXXXXXX,   XXXXXXX,   XXXXXXX, DF(_BASE)
    //                            \-----------------------------------------------------/            \-----------------------------------------------------/
    ),
};
// clang-format on

/* ######################################
 * ENCODER
 * #####################################*/
#include "encoder.c"

/* ######################################
 * OLED
 * #####################################*/
#include "oled.c"

/* ######################################
 * RGB MATRIX
 * #####################################*/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == MO(_LOWR)) {
        if (record->event.pressed) {
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_static_overlay);

        } else {
            rgb_matrix_reload_from_eeprom();
        }
    }

    return true;
}
