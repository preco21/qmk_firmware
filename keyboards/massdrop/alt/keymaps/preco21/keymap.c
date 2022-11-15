#include QMK_KEYBOARD_H

enum alt_keycodes {
    L_BRI = SAFE_RANGE, // LED Brightness Increase                                   //Working
    L_BRD,              // LED Brightness Decrease                                   //Working
    L_EDG_I,            // LED Edge Brightness Increase
    L_EDG_D,            // LED Edge Brightness Decrease
    L_EDG_M,            // LED Edge lighting mode
    L_PTN,              // LED Pattern Select Next                                   //Working
    L_PTP,              // LED Pattern Select Previous                               //Working
    L_PSI,              // LED Pattern Speed Increase                                //Working
    L_PSD,              // LED Pattern Speed Decrease                                //Working
    L_RATIOD,
    L_RATIOI,
    L_T_MD,             // LED Toggle Mode                                           //Working
    L_T_ONF,            // LED Toggle On / Off                                       //Broken
    L_ON,               // LED On                                                    //Broken
    L_OFF,              // LED Off                                                   //Broken
    L_T_BR,             // LED Toggle Breath Effect                                  //Working
    L_T_PTD,            // LED Toggle Scrolling Pattern Direction                    //Working
    U_T_AGCR,           // USB Toggle Automatic GCR control                          //Working
    DBG_TOG,            // DEBUG Toggle On / Off                                     //
    DBG_MTRX,           // DEBUG Toggle Matrix Prints                                //
    DBG_KBD,            // DEBUG Toggle Keyboard Prints                              //
    DBG_MOU,            // DEBUG Toggle Mouse Prints                                 //
    DBG_FAC,            // DEBUG Factory light testing (All on white)
    MD_BOOT,            // Restart into bootloader after hold timeout                //Working
    MD_RESET,           // Reset EEPROM settings
};

enum layers {
    LAYER_MAC = 0,
    LAYER_MAC_RAISED,
    LAYER_MAC_CONTROL,
    LAYER_WIN,
    LAYER_WIN_RAISED,
    LAYER_WIN_CONTROL,
};

#define MAC_DF   DF(LAYER_MAC)
#define MAC_RAIS MO(LAYER_MAC_RAISED)
#define MAC_CTRL MO(LAYER_MAC_CONTROL)
#define WIN_DF   DF(LAYER_WIN)
#define WIN_RAIS MO(LAYER_WIN_RAISED)
#define WIN_CTRL MO(LAYER_WIN_CONTROL)

enum combos {
    C_MAC_CONTROL_LAYER,
    C_WIN_CONTROL_LAYER,
    COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM c_mac_ctrl_layer_combo[] = { KC_RGUI, MAC_RAIS, KC_RSFT, COMBO_END };
const uint16_t PROGMEM c_win_ctrl_layer_combo[] = { KC_RALT, WIN_RAIS, KC_RSFT, COMBO_END };
combo_t key_combos[] = {
    [C_MAC_CONTROL_LAYER] = COMBO(c_mac_ctrl_layer_combo, MAC_CTRL),
    [C_WIN_CONTROL_LAYER] = COMBO(c_win_ctrl_layer_combo, WIN_CTRL),
};

#define LSFT_GRV LSFT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_MAC] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           KC_UP,   KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MAC_RAIS, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [LAYER_MAC_RAISED] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_PSCR,  KC_SLCK, KC_PAUS, _______, KC_END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______,          _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, LSFT_GRV, KC_GRV,  _______,  _______,          KC_PGUP, KC_VOLD,
        _______, _______, _______,                            _______,                             _______,  _______, KC_HOME, KC_PGDN, KC_END
    ),
    [LAYER_MAC_CONTROL] = LAYOUT(
        _______, _______, _______, _______,  _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,    L_EDG_I, _______, _______,  _______, U_T_AGCR, _______, _______, _______, _______, _______, _______,
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,    L_EDG_D, _______, MD_RESET, _______, _______,  _______, _______, _______,          _______, _______,
        _______, L_T_MD,  L_T_ONF, WIN_DF,   L_EDG_M, MD_BOOT, NK_TOGG,  _______, _______,  _______, _______, _______,          _______, _______,
        _______, _______, _______,                             _______,                              _______, _______, _______, _______, _______
    ),
    [LAYER_WIN] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,  KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,           KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, WIN_RAIS, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [LAYER_WIN_RAISED] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_PSCR,  KC_SLCK, KC_PAUS, _______, KC_END,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______,          _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, LSFT_GRV, KC_GRV,  _______,  _______,          KC_PGUP, KC_VOLD,
        _______, _______, _______,                            _______,                             _______,  _______, KC_HOME, KC_PGDN, KC_END
    ),
    [LAYER_WIN_CONTROL] = LAYOUT(
        _______, _______, _______, _______,  _______, _______, _______,  _______, _______,  _______, _______, _______, _______, _______, _______,
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,    L_EDG_I, _______, _______,  _______, U_T_AGCR, _______, _______, _______, _______, _______, _______,
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,    L_EDG_D, _______, MD_RESET, _______, _______,  _______, _______, _______,          _______, _______,
        _______, L_T_MD,  L_T_ONF, MAC_DF,   L_EDG_M, MD_BOOT, NK_TOGG,  _______, _______,  _______, _______, _______,          _______, _______,
        _______, _______, _______,                             _______,                              _______, _______, _______, _______, _______
    ),
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT   (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
#define MODS_RGUI  (get_mods() & MOD_BIT(KC_RGUI))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static uint16_t last_active_md_key;
    static uint8_t scroll_effect = 0;

    static bool mac_fn_held;
    static bool alt_swap_active;
    switch (keycode) {
        // Adds R-ALT <-> R-GUI swapping feature on macOS
        case KC_RGUI: {
            if (record->event.pressed && mac_fn_held) {
                register_code(KC_RALT);
                alt_swap_active = true;
                return false;
            } else if (alt_swap_active) {
                unregister_code(KC_RALT);
                alt_swap_active = false;
                return false;
            }
            return true;
        }
        case MAC_RAIS: {
            mac_fn_held = record->event.pressed;
            if (record->event.pressed && MODS_RGUI) {
                unregister_code(KC_RGUI);
                send_keyboard_report();
                register_code(KC_RALT);
                alt_swap_active = true;
            } else if (alt_swap_active) {
                unregister_code(KC_RALT);
                send_keyboard_report();
                register_code(KC_RGUI);
                alt_swap_active = false;
            }
            return true;
        }
        case L_BRI: {
            if (record->event.pressed) {
                md_led_changed();
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        }
        case L_BRD: {
            if (record->event.pressed) {
                md_led_changed();
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        }
        case L_EDG_M: {
            if (record->event.pressed) {
                md_led_changed();
                led_edge_mode++;
                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            return false;
        }
        case L_EDG_I: {
            if (record->event.pressed) {
                md_led_changed();
                led_edge_brightness += 0.1;
                if (led_edge_brightness > 1) { led_edge_brightness = 1; }
            }
            return false;
        }
        case L_EDG_D: {
            if (record->event.pressed) {
                md_led_changed();
                led_edge_brightness -= 0.1;
                if (led_edge_brightness < 0) { led_edge_brightness = 0; }
            }
            return false;
        }
        case L_RATIOI: {
            if (record->event.pressed) {
                md_led_changed();
                led_ratio_brightness += 0.2;
                if (led_ratio_brightness > 2.0) { led_ratio_brightness = 2.0; }
            }
            return false;
        }
        case L_RATIOD: {
            if (record->event.pressed) {
                md_led_changed();
                led_ratio_brightness -= 0.2;
                if (led_ratio_brightness < 0.0) { led_ratio_brightness = 0.0; }
            }
            return false;
        }
        case L_PTN: {
            if (record->event.pressed) {
                md_led_changed();
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        }
        case L_PTP: {
            if (record->event.pressed) {
                md_led_changed();
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        }
        case L_PSI: {
            if (record->event.pressed) {
                md_led_changed();
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        }
        case L_PSD: {
            if (record->event.pressed) {
                md_led_changed();
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        }
        case L_T_MD: {
            if (record->event.pressed) {
                md_led_changed();
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        }
        case L_T_ONF: {
            if (record->event.pressed) {
                md_led_changed();
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        }
        case L_ON: {
            if (record->event.pressed) {
                md_led_changed();
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        }
        case L_OFF: {
            if (record->event.pressed) {
                md_led_changed();
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        }
        case L_T_BR: {
            if (record->event.pressed) {
                md_led_changed();
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        }
        case L_T_PTD: {
            if (record->event.pressed) {
                md_led_changed();
                scroll_effect++;
                switch (scroll_effect) {
                    case 1: {
                        // Patterns with scroll move horizontal (Right to left)
                        led_animation_direction = 1;
                        led_animation_orientation = 0;
                        led_animation_circular = 0;
                        break;
                    }
                    case 2: {
                        // Patterns with scroll move vertical (Top to bottom)
                        led_animation_direction = 1;
                        led_animation_orientation = 1;
                        led_animation_circular = 0;
                        break;
                    }
                    case 3: {
                        // Patterns with scroll move vertical (Bottom to top)
                        led_animation_direction = 0;
                        led_animation_orientation = 1;
                        led_animation_circular = 0;
                        break;
                    }
                    case 4: {
                        // Patterns with scroll explode from center
                        led_animation_direction = 0;
                        led_animation_orientation = 0;
                        led_animation_circular = 1;
                        break;
                    }
                    case 5: {
                        // Patterns with scroll implode on center
                        led_animation_direction = 1;
                        led_animation_orientation = 0;
                        led_animation_circular = 1;
                        break;
                    }
                    default: {
                        // Patterns with scroll move horizontal (Left to right)
                        scroll_effect = 0;
                        led_animation_direction = 0;
                        led_animation_orientation = 0;
                        led_animation_circular = 0;
                        break;
                    }
                }
            }
            return false;
        }
        case U_T_AGCR: {
            if (record->event.pressed) {
                md_led_changed();
                if (MODS_SHIFT && MODS_CTRL) {
                    TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
                }
            }
            return false;
        }
        case MD_BOOT: {
            if (record->event.pressed) {
                last_active_md_key = MD_BOOT;
                key_timer = timer_read32();
            } else {
                if (last_active_md_key == MD_BOOT && timer_elapsed32(key_timer) >= 1500) {
                    reset_keyboard();
                }
            }
            return false;
        }
        case MD_RESET: {
            if (record->event.pressed) {
                last_active_md_key = MD_RESET;
                key_timer = timer_read32();
            } else {
                if (last_active_md_key == MD_RESET && timer_elapsed32(key_timer) >= 1500) {
                    eeconfig_init();
                }
            }
            return false;
        }
        default: {
            return true;
        }
    }
}

led_instruction_t led_instructions[] = {
    // LEDs are normally inactive, no processing is performed on them
    // Flags are used in matching criteria for an LED to be active and indicate how to color it
    // Flags can be found in tmk_core/protocol/arm_atsam/md_rgb_matrix.h (prefixed with LED_FLAG_)
    // LED IDs can be found in config_led.h in the keyboard's directory
    // Examples are below

    // All LEDs use the user's selected pattern (this is the factory default)
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_RGB, .layer = LAYER_MAC, .r = 172, .g = 255, .b = 233 },
    { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_USE_RGB, .layer = LAYER_WIN, .r = 172, .g = 255, .b = 233 },

    // Specific LEDs use the user's selected pattern while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN, .id0 = 0xFFFFFFFF, .id1 = 0xAAAAAAAA, .id2 = 0x55555555, .id3 = 0x11111111 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0x7e00ffff, .id1 = 0xffb01c00, .id2 = 0xffffffff, .id3 = 0x1ff, .layer = LAYER_MAC_RAISED, .r = 172, .g = 255, .b = 233 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0x7e00ffff, .id1 = 0xffb01c00, .id2 = 0xffffffff, .id3 = 0x1ff, .layer = LAYER_WIN_RAISED, .r = 172, .g = 255, .b = 233 },

    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xc08f8000, .id1 = 0xc007e017, .id2 = 0xfffffff8, .id3 = 0x1ff, .layer = LAYER_MAC_CONTROL, .r = 172, .g = 255, .b = 233 },
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xc08f8000, .id1 = 0xc007e017, .id2 = 0xfffffff8, .id3 = 0x1ff, .layer = LAYER_WIN_CONTROL, .r = 172, .g = 255, .b = 233 },

    // Specific LEDs use specified RGB values while all others are off
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFF, .id1 = 0x00FF, .id2 = 0x0000FF00, .id3 = 0xFF000000, .r = 75, .g = 150, .b = 225 },

    // All LEDs use the user's selected pattern
    // On layer 1, all key LEDs (except the top row which keeps active pattern) are red while all edge LEDs are green
    // When layer 1 is active, key LEDs use red    (id0  32 -  16: 1111 1111 1111 1111 1000 0000 0000 0000 = 0xFFFF8000) (except top row 15 - 1)
    // When layer 1 is active, key LEDs use red    (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    // When layer 1 is active, key LEDs use red    (id2  67 -  65: 0000 0000 0000 0000 0000 0000 0000 0111 = 0x00000007)
    // When layer 1 is active, edge LEDs use green (id2  95 -  68: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    // When layer 1 is active, edge LEDs use green (id3 105 -  96: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)
    // { .flags = LED_FLAG_USE_ROTATE_PATTERN },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id0 = 0xFFFF8000, .id1 = 0xFFFFFFFF, .id2 = 0x00000007, .r = 255, .layer = 1 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB, .id2 = 0xFFFFFFF8, .id3 = 0x000003FF, .g = 127, .layer = 1 },

    // All key LEDs use red while edge LEDs use the active pattern
    // All key LEDs use red     (id0  32 -   1: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    // All key LEDs use red     (id1  64 -  33: 1111 1111 1111 1111 1111 1111 1111 1111 = 0xFFFFFFFF)
    // All key LEDs use red     (id2  67 -  65: 0000 0000 0000 0000 0000 0000 0000 0111 = 0x00000007)
    // Edge uses active pattern (id2  95 -  68: 1111 1111 1111 1111 1111 1111 1111 1000 = 0xFFFFFFF8)
    // Edge uses active pattern (id3 105 -  96: 0000 0000 0000 0000 0000 0011 1111 1111 = 0x000003FF)
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .id0 = 0xFFFFFFFF, .id1 = 0xFFFFFFFF, .id2 = 0x00000007, .r = 255 },
    // { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN , .id2 = 0xFFFFFFF8, .id3 = 0x000003FF },

    // `end` must be set to 1 to indicate end of instruction set
    { .end = 1 }
};
