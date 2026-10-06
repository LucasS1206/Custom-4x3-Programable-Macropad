#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_7,    KC_8,    KC_9,    KC_VOLU,
        KC_4,    KC_5,    KC_6,    KC_VOLD,
        KC_1,    KC_2,    KC_3,    KC_MPLY
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK) }
};
#endif


void keyboard_post_init_user(void) {
    gpio_set_pin_input_high(GP11);
}


void matrix_scan_user(void) {
    static bool btn_pressed = false;
    static uint16_t btn_timer = 0;

    bool current_state = !gpio_read_pin(GP11);

    if (current_state != btn_pressed) {
        if (timer_elapsed(btn_timer) > 10) {
            btn_pressed = current_state;
            if (btn_pressed) {
                tap_code(KC_MUTE);
            }
            btn_timer = timer_read();
        }
    }
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("4x3 Macropad\n"), false);
    oled_write_P(PSTR("RP2040 Active\n"), false);
    oled_write_P(PSTR("--------------\n"), false);

    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
        case 0:
            oled_write_P(PSTR("Layer: Base\n"), false);
            break;
        default:
            oled_write_P(PSTR("Layer: Undef\n"), false);
            break;
    }
    return false;
}
#endif
