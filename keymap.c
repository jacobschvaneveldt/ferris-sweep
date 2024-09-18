#include QMK_KEYBOARD_H
#include "oneshot.h"

enum ferris_layers {
  _GALLIUM_V2,
  _RECURVA,
  _ENGRAM,
  _SEMIMAKJQ,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _F_ROW,
  _GAME,
  _GAME_NUM
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GALLIUM_V2] = LAYOUT(
    KC_B, KC_L, KC_D, KC_W, KC_V,    KC_J, KC_F, KC_O,    KC_U,    KC_COMM,
    KC_N, KC_R, KC_T, KC_S, KC_G,    KC_Y, KC_H, KC_A,    KC_E,    KC_I,
    KC_X, KC_Q, KC_M, KC_C, KC_Z,    KC_K, KC_P, KC_QUOT, KC_COLN, KC_DOT,
                  LOWER, OS_SHFT,    KC_SPC, RAISE
    ),
  
  [_RECURVA] = LAYOUT(
    KC_F, KC_R, KC_D, KC_P, KC_V,    KC_Q,   KC_M, KC_U,    KC_O,    KC_Y,
    KC_S, KC_N, KC_T, KC_C, KC_B,    KC_DOT, KC_H, KC_E,    KC_A,    KC_I,
    KC_Z, KC_X, KC_K, KC_G, KC_W,    KC_J,   KC_L, KC_COLN, KC_QUOT, KC_COMM, 
                  LOWER, OS_SHFT,    KC_SPC, RAISE
  ),

  [_ENGRAM] = LAYOUT(
    KC_B, KC_Y, KC_O, KC_U, KC_QUOT,  KC_SCLN, KC_L, KC_D, KC_W, KC_V,
    KC_C, KC_I, KC_E, KC_A, KC_COMM,  KC_DOT,  KC_H, KC_T, KC_S, KC_N,
    KC_G, KC_X, KC_J, KC_K, KC_Z,     KC_Q,    KC_R, KC_M, KC_F, KC_P,
                  LOWER, OS_SHFT,    KC_SPC, RAISE
  ),
  
  [_SEMIMAKJQ] = LAYOUT(
    KC_F, KC_L, KC_H, KC_V, KC_Z,    KC_QUOT, KC_W, KC_U,    KC_O,   KC_Y,
    KC_S, KC_R, KC_N, KC_T, KC_K,    KC_G,    KC_D, KC_E,    KC_A,   KC_I,
    KC_X, KC_J, KC_B, KC_M, KC_Q,    KC_P,    KC_C, KC_COMM, KC_DOT, KC_COLN,
                  LOWER, OS_SHFT,    KC_SPC, RAISE
  ),

  [_QWERTY] = LAYOUT(    
    KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, KC_QUOT, 
                  LOWER, OS_SHFT,    KC_SPC, RAISE
  ),

  [_LOWER] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,   KC_7,    KC_8,   KC_9,    KC_0,
    OS_CTRL, OS_ALT,  OS_CMD,  OS_SHFT, S(KC_V),    KC_ESC, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, 
    KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,    KC_DEL, KC_BSPC, KC_TAB, KC_ENT,  KC_SCLN,
                               _______, _______,    _______, _______
  ), 

  [_RAISE] = LAYOUT( 
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_TILD,    KC_CIRC, KC_AMPR, KC_QUES, KC_SLSH, KC_ASTR,
    KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PERC,    KC_PIPE, OS_SHFT, OS_CMD,  OS_ALT,  OS_CTRL,
    KC_LBRC, KC_RBRC, KC_UNDS, KC_MINS, KC_GRV,     KC_BSLS, KC_EQL,  KC_RABK, KC_LABK, KC_PLUS,
                               _______, KC_SPC,     _______, _______
  ),
  
   [_ADJUST] = LAYOUT(
    KC_BTN2, KC_WH_U, KC_MS_U, KC_WH_D, KC_TAB,     G(KC_N), G(KC_L), G(KC_T), G(KC_W), G(KC_SPC),
    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_Q,       C(KC_1), C(KC_2), C(KC_3), C(KC_4), C(KC_5),
    KC_BTN4, KC_BTN5, G(KC_C), G(KC_V), KC_ENT,     KC_DEL,  KC_BSPC, KC_LGUI, KC_LALT, MO(_F_ROW),
                               _______, _______,    _______, _______
  ), 
  
 [_F_ROW] = LAYOUT(
    KC_F1, KC_F2,  KC_F3,  KC_F4,  DF(_GALLIUM_V2),    TG(_GAME),      _______, _______, _______, QK_BOOT,
    KC_F5, KC_F6,  KC_F7,  KC_F8,  DF(_QWERTY),        DF(_SEMIMAKJQ), KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL, 
    KC_F9, KC_F10, KC_F11, KC_F12, DF(_RECURVA),       DF(_ENGRAM),    KC_BRMD, KC_BRMU, _______, _______,
                                  _______, _______,    _______, _______
  ), 

  [_GAME] = LAYOUT(    
    KC_LCTL, KC_Q, KC_W, KC_E, KC_R,     KC_Y, KC_U, KC_I,    KC_O,   TG(_GAME),
    KC_LSFT, KC_A, KC_S, KC_D, KC_F,     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    KC_ESC,  KC_Z, KC_X, KC_C, KC_V,     KC_N, KC_M, KC_COMM, KC_DOT, KC_QUOT, 
              MO(_GAME_NUM), KC_SPC,     KC_SPC, RAISE
  ),

  [_GAME_NUM] = LAYOUT(    
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      _______, KC_F1, KC_F2,  KC_F3,  KC_F4, 
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      _______, KC_F5, KC_F6,  KC_F7,  KC_F8, 
    KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,   _______, KC_F9, KC_F10, KC_F11, KC_F12,
                               _______, _______,   _______, _______
  ),
};

const uint16_t PROGMEM comboQweEsc[] = { KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM comboQweEnt[] = { KC_COMM, KC_M, COMBO_END};
const uint16_t PROGMEM comboQweCBspc[] = { KC_C, KC_X, COMBO_END};

const uint16_t PROGMEM comboRecurvaEsc[] = { KC_K, KC_G, COMBO_END};
const uint16_t PROGMEM comboRecurvaEnter[] = { KC_L, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboRecurvaCBspc[] = { KC_K, KC_X, COMBO_END};
const uint16_t PROGMEM comboRecurvaBspc[] = { KC_COLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM comboRecurvaGBspc[] = { KC_K, KC_X, KC_QUOT, KC_COLN, COMBO_END};

const uint16_t PROGMEM comboGalGBspc[] = { KC_Q, KC_M, KC_QUOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalEsc[] = { KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM comboGalEnt[] = { KC_QUOT, KC_P, COMBO_END};
const uint16_t PROGMEM comboGalScln[] = { KC_QUOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalComm[] = { KC_DOT, KC_COLN, COMBO_END};
const uint16_t PROGMEM comboGalCBspc[] = { KC_Q, KC_M, COMBO_END};

const uint16_t PROGMEM comboEngramEsc[] = { KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM comboEngramEnt[] = { KC_R, KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(comboQweEsc, KC_ESCAPE),
    COMBO(comboQweEnt, KC_ENTER),
    COMBO(comboQweCBspc, KC_ENTER),

    COMBO(comboRecurvaGBspc, G(KC_BSPC)),
    COMBO(comboRecurvaBspc, KC_BSPC),
    COMBO(comboRecurvaEsc, KC_ESCAPE),
    COMBO(comboRecurvaEnter, KC_ENTER),
    COMBO(comboRecurvaCBspc, A(KC_BSPC)),

    COMBO(comboGalGBspc, G(KC_BSPC)),
    COMBO(comboGalEsc,  KC_ESCAPE),
    COMBO(comboGalScln, KC_BSPC),
    COMBO(comboGalEnt,  KC_ENTER),
    COMBO(comboGalComm, KC_COMM),
    COMBO(comboGalCBspc, A(KC_BSPC)),

    COMBO(comboEngramEsc,  KC_ESCAPE),
    COMBO(comboEngramEnt,  KC_ENTER),
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