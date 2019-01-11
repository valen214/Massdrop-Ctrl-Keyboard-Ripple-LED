#include QMK_KEYBOARD_H

#include <config_led.h>
#include <math.h>
#include <print.h>

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

    L_SP_PD,            //LED Splash wave rainbow pattern direction
    L_SP_TR,            //LEB Splash rainbow color preset toggle

};


#if ISSI3733_LED_COUNT == 119
#   define NUMBER_OF_KEYS 87
#elif ISSI3733_LED_COUNT == 105
#   define NUMBER_OF_KEYS 67
#endif


#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

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
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_MUTE, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPLY, KC_MSTP, KC_VOLU, \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   KC_TRNS, KC_TRNS, KC_TRNS, U_T_AUTO,U_T_AGCR,KC_TRNS, MO(2),   KC_TRNS, KC_TRNS, KC_TRNS,   KC_MPRV, KC_MNXT, KC_VOLD, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, L_T_MD,  L_T_ONF, KC_TRNS, KC_TRNS, MD_BOOT, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        L_SP_TR, L_SP_SL, L_SP_WD, L_SP_FA, KC_TRNS, KC_TRNS, L_SP_TR, L_SP_SL, L_SP_WD, L_SP_FA, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        L_SP_PD, L_SP_PR, L_SP_NW, L_SP_NE, KC_TRNS, KC_TRNS, L_SP_PD, L_SP_PR, L_SP_NW, L_SP_NE, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
    ),
    /*
    [X] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG_NKRO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS \
    ),
    */
};

#define LED_NUMBERS (NUMBER_OF_KEYS + 1)
#define PATTERN_COUNT 6
#define INDICATORS_LED 20
typedef unsigned char _ub;


#define COLOR_PATTERN_COUNT 18
_ub (*COLOR_PATTERN)[3];
_ub RAINBOW_LIGHT[COLOR_PATTERN_COUNT][3] = { // light color
    {248,  12,  18}, {238,  17,   0}, {255,  51,  17},
    {255,  68,  32}, {255, 102,  68}, {255, 153,  51},
    {254, 174,  45}, {204, 187,  51}, {208, 195,  16},
    {170, 204,  34}, {105, 208,  37}, { 34, 204, 170},
    { 18, 189, 185}, { 17, 170, 187}, { 68,  68, 221},
    { 51,  17, 187}, { 59,  12, 189}, { 68,  34, 153},
}; // 18
_ub RAINBOW_BRIGHT[COLOR_PATTERN_COUNT][3] = {
    {255,   0,   0}, {255,   0,   0}, {255, 127,   0},
    {255, 127,   0}, {255, 255,   0}, {255, 255,   0},
    {120, 255,   0}, {120, 255,   0}, {  0, 255,   0},
    {  0, 255,   0}, {  0, 255, 120}, {  0, 255, 120},
    {  0,   0, 255}, {  0,   0, 255}, { 75,   0, 130},
    { 75,   0, 130}, { 43,   0, 130}, { 43,   0, 130},
};
_ub WHITE_FADE[COLOR_PATTERN_COUNT][3] = { // cos curve
    { 255, 255, 255 }, { 255, 255, 255 }, { 252, 252, 252 },
    { 247, 247, 247 }, { 240, 240, 240 }, { 232, 232, 232 },
    { 221, 221, 221 }, { 209, 209, 209 }, { 196, 196, 196 },
    { 181, 181, 181 }, { 164, 164, 164 }, { 147, 147, 147 },
    { 128, 128, 128 }, { 108, 108, 108 }, {  88,  88,  88 },
    {  66,  66,  66 }, {  45,  45,  45 }, {  23,  23,  23 },
};

/*
configuration struct for splash effect

DRIPPLE_PATTERN: (0 | 1 | 2 | 3 | 4)
    - 0: None
    - 1: background off, wave on
    - 2: background on, wave off
    - 3: rainbow wave
    - 4: rainbow wave on rotation background
    - 5: activate on press then diminish

*/
struct{
    _ub DRIPPLE_PATTERN;
    _ub WAVE_FRONT_WIDTH;
    int WAVE_PERIOD;
    _ub RAINBOW_TYPE;
    _ub TRAVEL_DISTANCE;

} USER_CONFIG = { // this default setting is most appealing
    .DRIPPLE_PATTERN = 2,
    .WAVE_FRONT_WIDTH = 3,
    .WAVE_PERIOD = 50,
    .RAINBOW_TYPE = 0,
    .TRAVEL_DISTANCE = 20,
};

#define KEY_STROKES_LENGTH 10
struct {
    _ub alive;
    _ub led_id;
    uint32_t time;
} KEY_STROKES[KEY_STROKES_LENGTH] = {{}};

/*

definitions of led_instruction is in /tmk_core/protocol/arm_atsam/led_matrix.h
definitions of value of KC_* is in /tmk_core/common/keycode.h

*/
led_instruction_t led_instructions[LED_NUMBERS + INDICATORS_LED] = {
    { .flags = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN,
            .id2 = 4286578688, .id3 = 1073741823}, // underglow
    // the flags and ids will be calculated in matrix_init_user()
};


const uint16_t PROGMEM fn_actions[] = {};

_ub KEYCODE_TO_LED_ID[256];
_ub DISTANCE_MAP[LED_NUMBERS][LED_NUMBERS];


_ub ktli(uint16_t keycode){

    if(keycode < 256){
        // the array is initialized in `matrix_init_user()`
        return KEYCODE_TO_LED_ID[keycode];
    }

    switch(keycode){
    case 20737: return 82;
    }

    return 0;
};





void add_led_instructions_id(uint16_t instruction_index, uint32_t id){
    uint16_t i = instruction_index;
    switch((id-1) / 32){
    case 0: led_instructions[i].id0 |= 1 << ((id-1) % 32); break;
    case 1: led_instructions[i].id1 |= 1 << ((id-1) % 32); break;
    case 2: led_instructions[i].id2 |= 1 << ((id-1) % 32); break;
    case 3: led_instructions[i].id3 |= 1 << ((id-1) % 32); break;
    }
}
void set_led_instructions_id(uint16_t instruction_index, uint32_t id){
    uint16_t i = instruction_index;
    led_instructions[i].id0 = 0;
    led_instructions[i].id1 = 0;
    led_instructions[i].id2 = 0;
    led_instructions[i].id3 = 0;
    add_led_instructions_id(i, id);
}






void matrix_init_user(void) {


    uint16_t LED_MAP[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
            1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,
            20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,
            36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,
            52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,
#if NUMBER_OF_KEYS >= 87
            68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87
#endif
    );

    uint16_t key = 0;
    for(_ub y = 0; y < MATRIX_ROWS; ++y){
        for(_ub x = 0; x < MATRIX_COLS; ++x){
            key = keymaps[0][y][x];
            if(key < 256){
                KEYCODE_TO_LED_ID[key] = LED_MAP[y][x];
            }
        }
    }








    led_animation_speed += ANIMATION_SPEED_STEP * 15;
    if(USER_CONFIG.RAINBOW_TYPE % 2){
        COLOR_PATTERN = &RAINBOW_LIGHT[0];
    } else{
        COLOR_PATTERN = &RAINBOW_BRIGHT[0];
    }

    const float unit_distance = 0.75; // unit distance
    float norm_dis = 0.0; // normalized distance

    // ./tmk_core/protocol/arm_atsam/led_matrix.c: line 53
    issi3733_led_t led_map[ISSI3733_LED_COUNT+1] = ISSI3733_LED_MAP;

    for(_ub i = 0; i < NUMBER_OF_KEYS; ++i){
        for(_ub j = i+1; j < NUMBER_OF_KEYS; ++j){
            norm_dis = sqrt(
                    (led_map[i].x - led_map[j].x) *
                    (led_map[i].x - led_map[j].x) +
                    (led_map[i].y - led_map[j].y) *
                    (led_map[i].y - led_map[j].y)
            ) / unit_distance;
                    
            DISTANCE_MAP[i+1][j+1] = (_ub)norm_dis;
            DISTANCE_MAP[j+1][i+1] = (_ub)norm_dis;
        }
    }







    /*
    suppose to iterate 87 times for a 87 keys keyboard
    as there are 87 led_structions with LED_FLAG_MATCH_ID
    which is suppose to be one key only

    so the led on each of the key can be modified by accessing the
    corresponding led_instruction[ktli(keycode)]:
    # see ktli(keycode) definition above
    */
    uint16_t flag = LED_FLAG_MATCH_ID;
    if(( USER_CONFIG.DRIPPLE_PATTERN == 2 ) || (
            USER_CONFIG.DRIPPLE_PATTERN == 4)){
        flag |= LED_FLAG_USE_ROTATE_PATTERN;
    } else{
        flag |= LED_FLAG_USE_RGB;
    }
    for(int i = 1; i < LED_NUMBERS; ++i){
        led_instructions[i].flags = flag;
        set_led_instructions_id(i, i);
    }





#define INDICATORS_NUMBER 30
    struct indicator_t {
        int instruction_index_offset;
        int layer;
        uint16_t key;
        _ub *rgb;
    } INDICATORS[INDICATORS_NUMBER] = {
        { 0,  2, KC_Q,    COLOR_PATTERN[0]  },
        { 0,  2, KC_U,    COLOR_PATTERN[0]  },
        { 1,  2, KC_W,    COLOR_PATTERN[2]  },
        { 1,  2, KC_I,    COLOR_PATTERN[2]  },
        { 2,  2, KC_E,    COLOR_PATTERN[4]  },
        { 2,  2, KC_O,    COLOR_PATTERN[4]  },
        { 3,  2, KC_A,    COLOR_PATTERN[6]  },
        { 3,  2, KC_J,    COLOR_PATTERN[6]  },
        { 4,  2, KC_S,    COLOR_PATTERN[8]  },
        { 4,  2, KC_K,    COLOR_PATTERN[8]  },
        { 5,  2, KC_D,    COLOR_PATTERN[10] },
        { 5,  2, KC_L,    COLOR_PATTERN[10] },
        { 6,  2, KC_TAB,  COLOR_PATTERN[12] },
        { 6,  2, KC_Y,    COLOR_PATTERN[12] },
        { 7,  2, KC_CAPS, COLOR_PATTERN[14] },
        { 7,  2, KC_H,    COLOR_PATTERN[14] },
#define PATTERN_INDICATOR_OFFSET 8
        { 8,  2, KC_GRV,  COLOR_PATTERN[17] }, // no pattern
        { 8,  2, KC_1,    COLOR_PATTERN[17] }, // pattern 1
        { 8,  2, KC_2,    COLOR_PATTERN[17] },
        { 8,  2, KC_3,    COLOR_PATTERN[17] },
        { 8,  2, KC_4,    COLOR_PATTERN[17] },
        { 8,  2, KC_5,    COLOR_PATTERN[17] },
#define ACTIVE_PATTERN_INDICATOR_OFFSET 9
        { 9,  2, KC_2,   COLOR_PATTERN[0]  }, // active pattern
        { 10, 1, KC_Q,    COLOR_PATTERN[0]  },
        { 10, 1, KC_W,    COLOR_PATTERN[0]  },
        { 10, 1, KC_E,    COLOR_PATTERN[0]  },
        { 10, 1, KC_P,    COLOR_PATTERN[0]  },
        { 10, 1, KC_S,    COLOR_PATTERN[0]  },
        { 10, 1, KC_A,    COLOR_PATTERN[0]  },
        { 10, 1, KC_D,    COLOR_PATTERN[0]  },
    };
    // make sure max offset is less than INDICATORS_LED

    flag = LED_FLAG_MATCH_ID | LED_FLAG_MATCH_LAYER | LED_FLAG_USE_RGB;
    for(int i = 0; i < INDICATORS_NUMBER; ++i){
        struct indicator_t __config = INDICATORS[i];
        
        int j = LED_NUMBERS + __config.instruction_index_offset;
        led_instructions[j].layer = __config.layer;
        led_instructions[j].flags = flag;
        led_instructions[j].r = __config.rgb[0];
        led_instructions[j].g = __config.rgb[1];
        led_instructions[j].b = __config.rgb[2];
        add_led_instructions_id(j, ktli(__config.key));
    }
    led_instructions[LED_NUMBERS + INDICATORS_LED - 1].end = 1;
}; // end of matrix_init_user(), initialization function


/*
length of the array should be a safe, large enough value
more typically:
longest wave time * fastest typing speed
= 22 * WAVE_PREIOD * typing speed
*/


/*
Runs constantly in the background, in a loop.
https://beta.docs.qmk.fm/detailed-guides/custom_quantum_functions#matrix-scanning-code
*/
// uint32_t perf_timer[100] = {1};
void matrix_scan_user(void) {
    // perf_timer[perf_timer[0]] = timer_read32();
    // keyboard_leds()
    _ub wave_front[LED_NUMBERS] = {};
    for(int i = 0; i < KEY_STROKES_LENGTH; ++i){
        if(KEY_STROKES[i].alive){
            uint32_t e = timer_elapsed32(KEY_STROKES[i].time);
            _ub alive = 0;
            _ub l = KEY_STROKES[i].led_id;
            int period_passed = e / USER_CONFIG.WAVE_PERIOD;

            // for(int start = period_passed - USER_CONFIG.WAVE_FRONT_WIDTH + 1,
            //         j = 0; j < USER_CONFIG.WAVE_FRONT_WIDTH; ++start, ++j){
            //     uprintf("start: %d\n", start);
            //     if(start < 0) continue;
            //     uprintf("DISTANCE_MAP[%d][0][0]: %d\n", l, DISTANCE_MAP[l][0][0]);
            //     if(start >= DISTANCE_MAP[l][0][0]) break;
            //     if(start == 0){
            //         if(( USER_CONFIG.DRIPPLE_PATTERN == 3 ) || (
            //                 USER_CONFIG.DRIPPLE_PATTERN == 4 )){
            //             wave_front[l] += 1;
            //         } else{
            //             wave_front[l] = 1;
            //         }
            //         alive = 1;
            //         continue;
            //     }
            //     for(_ub k = 1; k < DISTANCE_MAP[l][start][0]; ++k){
            //         uprintf("wave_front[DISTANCE_MAP[%d][%d][%d]] += 1\n", l, start, k);
            //         wave_front[DISTANCE_MAP[l][start][k]] += 1;
            //         alive = 1;
            //     }
            // }

            unsigned short dp;
            for(int j = 1 ; j < LED_NUMBERS; ++j){
                dp = period_passed - DISTANCE_MAP[l][j];
                // In virtue, dp should be larger than or equal to 0
                // but dp is unsigned so never mind......
                if(( dp < USER_CONFIG.WAVE_FRONT_WIDTH ) && (
                        DISTANCE_MAP[l][j] < USER_CONFIG.TRAVEL_DISTANCE)){
                    switch(USER_CONFIG.DRIPPLE_PATTERN){
                    case 3:
                    case 4:
                    case 5:
                        wave_front[j] += dp;
                        break;
                    default:
                        wave_front[j] = 1;
                        break;
                    }
                    alive = 1;
                }
            }
            
            // if it's never set in the loop, it would be zero
            KEY_STROKES[i].alive = alive;
        }
    }

    // print("onlist: ");
    uint16_t flag_rgb = LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB;
    uint16_t flag_pattern = LED_FLAG_MATCH_ID | LED_FLAG_USE_ROTATE_PATTERN;

    // enum failed
    #define USE_PATTERN 0
    #define BLACK_RGB 1
    #define COLOR_RGB 2
    for(int i = 1; i < LED_NUMBERS; ++i){
        _ub handle_type = USE_PATTERN, c = 0;
        // uprintf("%d ", wave_front[i]);
        switch(USER_CONFIG.DRIPPLE_PATTERN){
        case 0:
            handle_type = USE_PATTERN;
            break;
        case 1:
            if(wave_front[i]){
                handle_type = USE_PATTERN;
            } else{
                handle_type = BLACK_RGB;
            }
            break;
        case 2:
            if(wave_front[i]){
                handle_type = BLACK_RGB;
            } else{
                handle_type = USE_PATTERN;
            }
            break;
        case 3:
        case 4:
            if(wave_front[i]){
                handle_type = COLOR_RGB;
            } else if(USER_CONFIG.DRIPPLE_PATTERN == 4){
                handle_type = USE_PATTERN;
            } else{
                handle_type = BLACK_RGB;
            }
            break;
        case 5:
            if(wave_front[i]){
                handle_type = COLOR_RGB;
            } else{
                handle_type = USE_PATTERN;
            }
            break;
        }

        switch(handle_type){
        case USE_PATTERN:
            led_instructions[i].flags = flag_pattern;
            break;
        case BLACK_RGB:
            led_instructions[i].r = 0;
            led_instructions[i].g = 0;
            led_instructions[i].b = 0;
            led_instructions[i].flags = flag_rgb;
            break;
        case COLOR_RGB:
            c = (wave_front[i] * COLOR_PATTERN_COUNT /
                    USER_CONFIG.WAVE_FRONT_WIDTH) % COLOR_PATTERN_COUNT;
            led_instructions[i].r = COLOR_PATTERN[c][0];
            led_instructions[i].g = COLOR_PATTERN[c][1];
            led_instructions[i].b = COLOR_PATTERN[c][2];
            led_instructions[i].flags = flag_rgb;
            break;
        }
    }

/*
    if(perf_timer[0] == 99){
        perf_timer[99] = timer_elapsed32(perf_timer[99]);
        uint32_t sum = 0;
        for(int i = 1; i < 100; ++i){
            sum += perf_timer[i];
        }
        uprintf("matrix_scan_user() time used (sum of 99 invocation): %d\n", sum);
        perf_timer[0] = 1;
    } else{
        perf_timer[perf_timer[0]] = timer_elapsed32(perf_timer[perf_timer[0]]);
        perf_timer[0] += 1;
    }
*/
    // print("\n");
}; // end of matrix_scan_user (looping function)


/* command


make massdrop/ctrl:custom


./.build/mdloader_windows.exe --first --download massdrop_ctrl_custom.bin --restart


*/

#define MODS_SHIFT  (keyboard_report->mods & MOD_BIT(KC_LSHIFT) || keyboard_report->mods & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (keyboard_report->mods & MOD_BIT(KC_LCTL) || keyboard_report->mods & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;


    if(record->event.pressed){
        uprintf("%d pressed\n", keycode);
    }

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







        
        case L_SP_PR: // previous dripple pattern
        case L_SP_NE: // next dripple pattern
            if (record->event.pressed) {
                

                _ub incre = keycode == L_SP_PR ? PATTERN_COUNT-1 : 1;
                USER_CONFIG.DRIPPLE_PATTERN += incre;
                USER_CONFIG.DRIPPLE_PATTERN %= PATTERN_COUNT;

                if(USER_CONFIG.DRIPPLE_PATTERN <= 4){
                    USER_CONFIG.TRAVEL_DISTANCE = 20;
                    COLOR_PATTERN = &RAINBOW_BRIGHT[0];
                    USER_CONFIG.WAVE_PERIOD = 50;
                }

                _ub indicator_key = 0;
                switch(USER_CONFIG.DRIPPLE_PATTERN){
                case 0: // None
                    indicator_key = KC_GRV;
                    break;
                case 1: // background off, wave on
                    USER_CONFIG.WAVE_FRONT_WIDTH = 2;
                    indicator_key = KC_1;
                    break;
                case 2: // background on, wave off
                    USER_CONFIG.WAVE_FRONT_WIDTH = 5;
                    indicator_key = KC_2;
                    break;
                case 3: // background off, rainbow wave
                    USER_CONFIG.WAVE_FRONT_WIDTH = 10;
                    indicator_key = KC_3;
                    break;
                case 4: // background on, rainbow wave
                    USER_CONFIG.WAVE_FRONT_WIDTH = 10;
                    indicator_key = KC_4;
                    break;
                case 5:
                    COLOR_PATTERN = &WHITE_FADE[0];
                    USER_CONFIG.WAVE_FRONT_WIDTH = 10;
                    USER_CONFIG.TRAVEL_DISTANCE = 1;
                    USER_CONFIG.WAVE_PERIOD = 100;
                    indicator_key = KC_5;
                    break;
                }

                set_led_instructions_id(
                        LED_NUMBERS + ACTIVE_PATTERN_INDICATOR_OFFSET,
                        ktli(indicator_key));
                

                // remove effect after changing pattern
                for(int i = 0; i < KEY_STROKES_LENGTH; ++i){
                    KEY_STROKES[i].alive = 0;
                }

            }
            return false;
        case L_SP_WD:
        case L_SP_NW:
            if(record->event.pressed){
                short incre = keycode == L_SP_WD ? 1 : -1;
                USER_CONFIG.WAVE_FRONT_WIDTH += incre;
                if(USER_CONFIG.WAVE_FRONT_WIDTH < 1){
                    USER_CONFIG.WAVE_FRONT_WIDTH = 1;
                }
            }
            return false;
        case L_SP_FA:
        case L_SP_SL:
            if(record->event.pressed){
                short incre = keycode == L_SP_FA ? -1 : 1;
                
                USER_CONFIG.WAVE_PERIOD += 10 * incre;
                if(USER_CONFIG.WAVE_PERIOD < 10){
                    USER_CONFIG.WAVE_PERIOD = 10;
                }
            }
            return false;
        // these are the keys not in range 0x04 - 0x52
        case L_SP_TR:
            if(record->event.pressed){
                USER_CONFIG.RAINBOW_TYPE += 1;
                if(USER_CONFIG.RAINBOW_TYPE % 2){
                    COLOR_PATTERN = &RAINBOW_LIGHT[0];
                } else{
                    COLOR_PATTERN = &RAINBOW_BRIGHT[0];
                }
            }
            return false;
        case L_SP_PD:
        
            return false;
        default:
            /*
            for reference to key code value, see:
            /tmk_core/common/keycode.h(195): enum hid_keyboard_keypad_usage
            */

            if (record->event.pressed){
                _ub led_id = ktli(keycode);
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
