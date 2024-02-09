#include QMK_KEYBOARD_H
#include "oneshot.h"

enum ferris_layers {
  _GALLIUM_V2,
  _ENGRAM,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _F_ROW
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

enum ferris_tap_dances {
  TD_Q_ESC
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GALLIUM_V2] = LAYOUT( 
    KC_B,    KC_L,    KC_D,    KC_W,    KC_V,            KC_J,    KC_F,  KC_O,    KC_U,   KC_COMM,
    KC_N,    KC_R,    KC_T,    KC_S,    KC_G,            KC_Y,    KC_H,  KC_A,    KC_E,   KC_I,
    KC_X,    KC_Q,    KC_M,    KC_C,    KC_Z,            KC_K,    KC_P,  KC_QUOT, KC_COLN,KC_DOT, 
                               OS_SHFT, LOWER,           RAISE,   KC_SPC
  ),

  [_ENGRAM] = LAYOUT( 
    KC_B,  KC_Y,    KC_O,    KC_U,    KC_QUOT,            KC_SCLN,  KC_L,    KC_D,    KC_W,    KC_V,
    KC_C,  KC_I,    KC_E,    KC_A,    KC_COMM,            KC_DOT,   KC_H,    KC_T,    KC_S,    KC_N,
    KC_G,  KC_X,    KC_J,    KC_K,    KC_Z,               KC_Q,     KC_R,    KC_M,    KC_F,    KC_P,
                             OS_SHFT, LOWER,              RAISE,    KC_SPC
  ),

  [_QWERTY] = LAYOUT(    
    KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,  KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, 
                             OS_SHFT, LOWER,       RAISE,   KC_SPC
  ),


  [_LOWER] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,   KC_9,    KC_0,
    OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, S(KC_V),      KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_ESC,
    KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,      KC_DEL,  KC_BSPC, KC_TAB, KC_ENT,  KC_SCLN,  
                               _______, _______,      _______, _______
  ),

  [_RAISE] = LAYOUT( 
    KC_EXLM,  KC_AT,     KC_HASH,    KC_DLR,    KC_TILD,     KC_CIRC, KC_AMPR, KC_QUES, KC_SLSH, KC_ASTR,
    KC_MINS,  KC_LBRC,   KC_LCBR,    KC_LPRN,   KC_PERC,     KC_PIPE, OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
    KC_UNDS,  KC_RBRC,   KC_RCBR,    KC_RPRN,   KC_GRV,      KC_BSLS, KC_EQL,  KC_RABK, KC_LABK, KC_PLUS,
                                     KC_SPC,    _______,     _______, _______
  ),
    
   [_ADJUST] = LAYOUT(
    KC_BTN2, KC_WH_L, KC_MS_U, KC_WH_R, KC_TAB,     G(KC_F), G(KC_L), G(KC_T), G(KC_W), G(KC_SPC),
    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_Q,       C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),
    KC_BTN4, KC_BTN5, KC_WH_U, KC_WH_D, _______,    KC_DEL,  KC_BSPC, KC_LGUI, KC_LALT, MO(_F_ROW),
                               _______, _______,    _______, _______
), 
  
 [_F_ROW] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   DF(_GALLIUM_V2),  NK_TOGG,   _______, _______, _______, QK_BOOT,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   DF(_QWERTY),      _______, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, 
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  DF(_ENGRAM),      _______, KC_BRMD, KC_BRMU, _______, _______,
                               _______, _______,          _______, _______
), 
};

// qwerty
const uint16_t PROGMEM comboQweEsc[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM comboQweEnt[] = { KC_COMM, KC_M, COMBO_END};

// gallite
const uint16_t PROGMEM comboGalEsc[] = { KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM comboGalEnt[] = { KC_QUOT, KC_P, COMBO_END};
const uint16_t PROGMEM comboGalScln[] = { KC_QUOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalComm[] = { KC_DOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalCBspc[] = { KC_Q, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(comboQweEsc, KC_ESCAPE),
    COMBO(comboQweEnt, KC_ENTER),

    COMBO(comboGalEsc,  KC_ESCAPE),
    COMBO(comboGalEnt,  KC_ENTER),
    COMBO(comboGalScln, KC_SCLN),
    COMBO(comboGalComm, KC_COMM),
    COMBO(comboGalCBspc, A(KC_BSPC)),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// one shot cancel
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LOWER:
    case RAISE:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}
// end of one shot cancel