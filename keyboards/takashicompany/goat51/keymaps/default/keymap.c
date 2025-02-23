// Copyright 2022 takashicompany (@takashicompany)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    GOAT51 = SAFE_RANGE,
    WEB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // 0: JIS-Alphabet
    LAYOUT(
        KC_ESC, LT(7, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_LCTL, KC_A, KC_S, LT(6, KC_D), KC_F, KC_G, GOAT51, KC_H, KC_J, LT(6, KC_K), KC_L, KC_ENT, KC_ENT,
        KC_LSFT, LSFT_T(KC_Z), LGUI_T(KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, LCTL_T(KC_DOT), KC_BSPC, KC_DEL,
        TG(6), KC_PGUP, KC_PGDN, KC_LCTL, KC_LGUI, ALT_T(KC_LNG2), LSFT_T(KC_TAB), LT(2, KC_SPC), LT(1, KC_LNG1), KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        KC_PGDN, KC_PGUP
    ),

    // 1: JIS-Num
    LAYOUT(
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        KC_TRNS, LCTL_T(KC_EQL), KC_LBRC, KC_SLSH, KC_MINS, KC_INT1, GOAT51, KC_SCLN, KC_QUOT, KC_RBRC, KC_NUHS, KC_INT3, KC_TRNS,
        KC_TRNS, LSFT_T(KC_PLUS), KC_LCBR, KC_QUES, KC_UNDS, LSFT(KC_INT1), KC_COLN, KC_DQUO, KC_RCBR, LSFT(KC_NUHS), LSFT(KC_INT3), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    
    // 2: JIS-Shift-Num
    LAYOUT(
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, LGUI(KC_INT3), KC_TRNS,
        KC_TRNS, KC_PLUS, KC_LCBR, KC_QUES, KC_UNDS, LSFT(KC_INT1), GOAT51, KC_COLN, KC_DQUO, KC_RCBR, LSFT(KC_NUHS), LSFT(KC_INT3), KC_TRNS,
        KC_TRNS, KC_LSFT, KC_LGUI, KC_LALT, KC_LNG2, KC_LSFT, KC_SPC, KC_LNG1, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    
    // 3: US-Alphabet
    LAYOUT(
        KC_TRNS, LT(7, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_TRNS,
        KC_TRNS, KC_A, KC_S, LT(6, KC_D), KC_F, KC_G, GOAT51, KC_H, KC_J, LT(6, KC_K), KC_L, KC_ENT, KC_TRNS,
        KC_TRNS, LSFT_T(KC_Z), LGUI_T(KC_X), KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, LCTL_T(KC_DOT), KC_BSPC, KC_TRNS,
        TG(6), KC_PGUP, KC_PGDN, KC_LCTL, KC_LGUI, ALT_T(KC_LNG2), LSFT_T(KC_TAB), LT(5, KC_SPC), LT(4, KC_LNG1), KC_RALT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        KC_PGDN, KC_PGUP
    ),
    
    // 4: US-Num
    LAYOUT(
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        KC_TRNS, KC_CIRC, KC_AT, KC_SLSH, KC_MINS, KC_UNDS, GOAT51, KC_SCLN, KC_COLN, KC_LBRC, KC_RBRC, KC_INT3, KC_TRNS,
        KC_TRNS, LT(5, KC_TILD), KC_GRV, KC_QUES, KC_EQL, KC_UNDS, KC_PLUS, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    
    // 5: US-Shift-Num
    LAYOUT(
        KC_TRNS, KC_EXLM, KC_DQUO, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_QUOT, KC_LPRN, KC_RPRN, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_TILD, KC_GRV, KC_QUES, KC_EQL, KC_UNDS, GOAT51, KC_PLUS, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
        KC_TRNS, KC_LSFT, KC_LGUI, KC_LALT, KC_LNG2, KC_LSFT, KC_SPC, KC_LNG1, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    
    // 6: Cursor
    LAYOUT(
        KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PCMM, GOAT51, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, LSFT_T(KC_P1), KC_P2, KC_P3, KC_PMNS, KC_KP_EQUAL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TG(6), KC_P0, KC_PDOT, KC_PENT, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ), 
    
    // 7: Function
    LAYOUT(
        KC_TRNS, KC_TRNS, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GOAT51, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
        KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(8), MO(9), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    ),
    
    // 8: LED
    LAYOUT(
        KC_TRNS, UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, KC_TRNS, KC_TRNS, KC_TRNS, DF(0), DF(3), KC_TRNS,
        KC_TRNS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, GOAT51, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_M_K, RGB_M_X, RGB_M_G, KC_TRNS, KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GOAT51:
            if (record->event.pressed) {
                SEND_STRING("GOAT51");
                rgblight_toggle();
            }
            return false;

        case WEB:
            if (record->event.pressed) {
                SEND_STRING("github.com/takashicompany/goat51");
            }
            return false;
    }
    
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {

    if (clockwise) {
        tap_code(KC_MS_WH_DOWN);
    } else {
        tap_code(KC_MS_WH_UP);
    }

    return true;
}