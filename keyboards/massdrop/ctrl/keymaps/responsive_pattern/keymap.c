#include QMK_KEYBOARD_H

// uint8_t keyboard_leds(void)
// #include <tmk_core/protocol/arm_atsam/main_arm_atsam.h>


#if ISSI3733_LED_COUNT == 119
#   define KEY_LED_COUNT 87
#elif ISSI3733_LED_COUNT == 105
#   define KEY_LED_COUNT 67
#endif

#define min(x, y) (x < y ? x : y)


extern issi3733_led_t *lede;
extern issi3733_led_t led_map[];
extern led_disp_t disp;

enum ctrl_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction
    U_T_AUTO,           //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    MD_BOOT,            //Restart into bootloader after hold timeout
    
    L_SP_PR,            //LED Splash Pattern Select Previous
    L_SP_NE,            //LED Splash Pattern Select Next

    L_SP_WD,            //LED Splash Widen Wavefront width
    L_SP_NW,            //LED Splash Narrow Wavefront width

    L_SP_FA,            //LED Splash wave travel speed faster (shorter period)
    L_SP_SL,            //LED Splash wave travel speed slower (longer period)

    L_CP_PR,            //LED Color Pattern Select Previous
    L_CP_NX,            //LEB Color Pattern Select Next
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode
#define ______ KC_TRNS

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,             KC_PSCR, KC_SLCK, KC_PAUS, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                              KC_UP, \
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL,            KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            KC_MUTE, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MPLY, KC_MSTP, KC_VOLU, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   _______, _______, _______, U_T_AUTO,U_T_AGCR,_______, MO(2),   _______, _______, _______,   KC_MPRV, KC_MNXT, KC_VOLD, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, L_T_MD,  L_T_ONF, _______, _______, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        L_CP_NX, L_SP_SL, L_SP_WD, L_SP_FA, _______, _______, L_CP_NX, L_SP_SL, L_SP_WD, L_SP_FA, _______, _______, _______, _______,   _______, _______, _______, \
        L_CP_PR, L_SP_PR, L_SP_NW, L_SP_NE, _______, _______, L_CP_PR, L_SP_PR, L_SP_NW, L_SP_NE, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, TG_NKRO, _______, _______, _______, _______, _______,                              _______, \
        _______, _______, _______,                   _______,                            _______, _______, _______, _______,            _______, _______, _______ \
    ),
    */
};

// see: /tmk_core/common/keycode.h
uint8_t KEYCODE_TO_LED_ID[256];
uint8_t DISTANCE_MAP[KEY_LED_COUNT][KEY_LED_COUNT];

struct {
    uint8_t PATTERN_INDEX;
    uint8_t WAVE_FRONT_WIDTH;
    uint16_t WAVE_PERIOD;
    uint8_t COLOR_PATTERN_INDEX;
    uint8_t TRAVEL_DISTANCE;
} USER_CONFIG = {
    .PATTERN_INDEX = 1,
    .WAVE_FRONT_WIDTH = 3,
    .WAVE_PERIOD = 50,
    .COLOR_PATTERN_INDEX = 0,
    .TRAVEL_DISTANCE = 20,
};

uint8_t ktli(uint16_t keycode){
    if(keycode < 256){
        // the array is initialized in `matrix_init_user()`
        return KEYCODE_TO_LED_ID[keycode];
    } else if(IS_FN(keycode)){
        return 82;
    }
    return 0;
};

// Runs just one time when the keyboard initializes.
static void init_keycode_to_led_map(void){
    uint16_t LED_MAP[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
            0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,
            19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,
            35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,
            51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,
#if KEY_LED_COUNT >= 87
            67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86
#endif
    );

    uint16_t key = 0;
    for(uint8_t y = 0; y < MATRIX_ROWS; ++y){
        for(uint8_t x = 0; x < MATRIX_COLS; ++x){
            key = keymaps[0][y][x];
            if(key < 256){
                KEYCODE_TO_LED_ID[key] = LED_MAP[y][x];
            }
        }
    }
}
// https://docs.qmk.fm/#/feature_terminal
#define KEY_POSITION_MAP_ROWS 6
#define KEY_POSITION_MAP_COLUMNS 20
static void init_distance_map(void){
    uint16_t KEY_POSITION_MAP[KEY_POSITION_MAP_ROWS][KEY_POSITION_MAP_COLUMNS] = {
        { KC_NO,   KC_ESC,  KC_NO,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_NO,  KC_F5,  KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS,  },
        // { KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    },
        { KC_NO,   KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_BSPC, KC_NO,   KC_INS,  KC_HOME, KC_PGUP,  },
        { KC_NO,   KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_BSLS, KC_NO,   KC_DEL,  KC_END,  KC_PGDN,  },
        { KC_NO,   KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENT,  KC_ENT,  KC_ENT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    },
        { KC_NO,   KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  KC_RSFT, KC_RSFT, KC_RSFT, KC_NO,   KC_NO,   KC_UP,   KC_NO,    },
        { KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_NO,  20737,   KC_APP,   KC_RCTL, KC_RCTL, KC_RCTL, KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, },
    };
    uint8_t columns = KEY_POSITION_MAP_COLUMNS;
    uint8_t rows = KEY_POSITION_MAP_ROWS;

    for(uint8_t y = 0; y < rows; ++y){
        for(uint8_t x = 0; x < columns; ++x){
            uint8_t id1 = ktli(KEY_POSITION_MAP[y][x]);

            for(uint8_t j = y; j < rows; ++j){
                for(uint8_t i = 0; i < columns; ++i){
                    uint8_t id2 = ktli(KEY_POSITION_MAP[j][i]);

                    if(id1 == id2) continue;
                    
                    uint8_t dx = abs(i - x);
                    uint8_t dy = abs(j - y);
                    uint8_t dis = dx + dy;
                    if(i < x && j > y){
                        dis -= min(dx, dy);
                    }

                    uint8_t _dis = DISTANCE_MAP[id1][id2];
                    if(_dis && _dis <= dis) continue;
                    DISTANCE_MAP[id1][id2] = dis;
                    DISTANCE_MAP[id2][id1] = dis;
                }
            }
        }
    }
}
void matrix_init_user(void) {
    init_keycode_to_led_map();
    init_distance_map();
};

// /tmk_core/protocol/arm_atsam/led_matrix.c: line 244
extern uint8_t led_per_run;

// overrided /tmk_core/protocol/arm_atsam/led_matrix.c: line 484
void rgb_matrix_init_user(void){
    led_animation_speed = ANIMATION_SPEED_STEP * 15;
    led_per_run = 1;
}

// overrided /tmk_core/protocol/arm_atsam/led_matrix.c: line 262

#define KEY_STROKES_LENGTH 20
struct {
    bool alive;
    uint8_t led_id;
    uint32_t time;
} KEY_STROKES[KEY_STROKES_LENGTH] = {{}};




void set_led_rgb(uint8_t led_id, uint8_t r, uint8_t g, uint8_t b){
    issi3733_led_t *target_led = (led_map + led_id);
    *target_led->rgb.r = r;
    *target_led->rgb.g = g;
    *target_led->rgb.b = b;
}


uint8_t DISTANCE_FROM_LAST_KEYSTROKE[KEY_LED_COUNT];
void calculate_keystroke_distance(void){
    bool alive;
    uint8_t led_id, period_passed;
    uint32_t t;


    for(uint8_t i = 0; i < KEY_LED_COUNT; ++i){
        DISTANCE_FROM_LAST_KEYSTROKE[i] = 0;
    }

    for(uint8_t i = 0; i < KEY_STROKES_LENGTH; ++i){
        if(KEY_STROKES[i].alive){
            t = timer_elapsed32(KEY_STROKES[i].time);
            alive = 0;
            led_id = KEY_STROKES[i].led_id;
            period_passed = t / USER_CONFIG.WAVE_PERIOD;

            uint8_t delta_period;
            for(uint8_t j = 0; j < KEY_LED_COUNT; ++j){
                delta_period = period_passed - DISTANCE_MAP[led_id][j];
                if(( delta_period < USER_CONFIG.WAVE_FRONT_WIDTH) && (
                    DISTANCE_MAP[led_id][j] <= USER_CONFIG.TRAVEL_DISTANCE
                )){
                    switch(USER_CONFIG.PATTERN_INDEX){
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                        DISTANCE_FROM_LAST_KEYSTROKE[j] += delta_period;
                        break;
                    default:
                        DISTANCE_FROM_LAST_KEYSTROKE[j] = 1;
                        break;
                    }
                    alive = 1;
                }
            }
            KEY_STROKES[i].alive = alive;
        }
    }
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    static uint32_t scan_timer = 0;

    uint8_t layer = 0;
    if(layer_state >= 0x04){
        layer = 2;
    } else if(layer_state >= 0x02){
        layer = 1;
    }

    calculate_keystroke_distance();
    for(uint8_t i = 0; i < KEY_LED_COUNT; ++i){
        if(DISTANCE_FROM_LAST_KEYSTROKE[i]){
            set_led_rgb(i, 255, 255, 255);
        }
    }

    switch(layer){
    case 0:
        if(timer_elapsed32(scan_timer) > 2000){
            scan_timer = timer_read32();
        } else if(timer_elapsed32(scan_timer) > 1000){
            set_led_rgb(ktli(KC_F5), 255, 255, 255);
        }
        set_led_rgb(ktli(KC_A), 255, 0, 0);
        break;
    case 1:
        set_led_rgb(ktli(KC_Q), 255, 0, 0);
        set_led_rgb(ktli(KC_W), 255, 0, 0);
        set_led_rgb(ktli(KC_E), 255, 0, 0);
        set_led_rgb(ktli(KC_A), 255, 0, 0);
        set_led_rgb(ktli(KC_S), 255, 0, 0);
        set_led_rgb(ktli(KC_D), 255, 0, 0);
        break;
    case 2:
        break;
    }

};

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                led_enabled = !led_enabled;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                led_enabled = 1;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                led_enabled = 0;
                I2C3733_Control_Set(led_enabled);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                led_animation_direction = !led_animation_direction;
            }
            return false;
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            if (record->event.pressed){
                uint8_t led_id = ktli(keycode);
                if(led_id){
                    for(int i = 0; i < KEY_STROKES_LENGTH; ++i){
                        if(!KEY_STROKES[i].alive){
                            KEY_STROKES[i].alive = 1;
                            KEY_STROKES[i].led_id = led_id;
                            KEY_STROKES[i].time = timer_read32();
                            break;
                        }
                    }
                }
            }
            return true; //Process all other keycodes normally
    }
}
