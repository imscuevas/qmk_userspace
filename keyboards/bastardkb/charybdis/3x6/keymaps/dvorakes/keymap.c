/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUMBERS,
    LAYER_SYMBOLS,
    LAYER_NAV,
    LAYER_MEDIA,
    LAYER_FUN,
    LAYER_POINTER,
};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define MEDIA LT(LAYER_MEDIA, KC_ESC)
#define NAV LT(LAYER_NAV, KC_SPC)
#define FUN LT(LAYER_FUN, KC_TAB)
#define NUMBERS LT(LAYER_NUMBERS, KC_ENT)
#define SYMBOLS LT(LAYER_SYMBOLS, KC_BSPC)
#define MT_A LGUI_T(KC_A)
#define MT_O LALT_T(KC_O)
#define MT_E LCTL_T(KC_E)
#define MT_U LSFT_T(KC_U)
#define MT_Q RALT_T(KC_Q)
#define MT_R RSFT_T(KC_R)
#define MT_T RCTL_T(KC_T)
#define MT_N LALT_T(KC_N)
#define MT_S RGUI_T(KC_S)
#define MT_V RALT_T(KC_V)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)
#define PT_Z LT(LAYER_POINTER, KC_Z)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
       XXXXXXX,    KC_DOT,    KC_COMM, KC_SCLN, KC_P,    KC_Y,       KC_F,    KC_G,    KC_C,    KC_H, KC_L, KC_MINS,
       KC_CAPS,    MT_A,      MT_O,    MT_E,    MT_U,    KC_I,       KC_D,    MT_R,    MT_T,    MT_N, MT_S, KC_QUOT,
       XXXXXXX,    PT_SLSH,   MT_Q,    KC_J,    KC_K,    KC_X,       KC_B,    KC_M,    KC_W,    MT_V, PT_Z, QK_BOOT,
                                       MEDIA,   NAV,     FUN,        SYMBOLS, NUMBERS
  ),

  [LAYER_NUMBERS] = LAYOUT(
    XXXXXXX, KC_QUOT, KC_7, KC_8,   KC_9, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT,  QK_BOOT,
    KC_CAPS, KC_LBRC, KC_4, KC_5,   KC_6, KC_RBRC, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
    XXXXXXX, KC_NUBS, KC_1, KC_2,   KC_3, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, KC_SLSH, XXXXXXX,
                            KC_EQL, KC_0, KC_MINS, XXXXXXX, _______
  ),

  [LAYER_SYMBOLS] = LAYOUT(
    XXXXXXX, KC_EQL,    S(KC_1),    ALGR(KC_LBRC), ALGR(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, S(KC_EQL), S(KC_MINS), S(KC_8),       S(KC_9),       XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
    XXXXXXX, KC_NUBS,   S(KC_NUBS), ALGR(KC_QUOT), ALGR(KC_BSLS), XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,
                                    XXXXXXX,       XXXXXXX,       XXXXXXX, _______, XXXXXXX
  ),

  [LAYER_NAV] = LAYOUT(
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(KC_Z), C(KC_V), C(KC_C), C(KC_X), C(KC_Y), XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  XXXXXXX,
                               XXXXXXX, _______, XXXXXXX, KC_DEL,  KC_ENT
  ),

  [LAYER_MEDIA] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, XXXXXXX, XXXXXXX, KC_MSTP, KC_MPLY
  ),

  [LAYER_FUN] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F10, XXXXXXX,
                               XXXXXXX, XXXXXXX, _______, KC_DEL,  KC_ENT
  ),

  [LAYER_POINTER] = LAYOUT(
       XXXXXXX, PZOOM,   PVOLUME, PTABS,   DPI_MOD, S_D_MOD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, PHIST,      XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
       XXXXXXX, _______, DRGSCRL, SNIPING, CURSOR,  PBRIGHT,    XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, _______, XXXXXXX,
                                  MS_BTN2, MS_BTN1, MS_BTN3,    XXXXXXX, XXXXXXX
  ),
};
