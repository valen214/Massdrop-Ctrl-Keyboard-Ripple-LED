

# retrieved from /tmk_core/common/keycode.h
# keycode
(
    KC_NO, KC_ROLL_OVER, KC_POST_FAIL, KC_UNDEFINED,
    KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G,
    KC_H, KC_I, KC_J, KC_K, KC_L, KC_M,
    KC_N, KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T,
    KC_U, KC_V, KC_W, KC_X, KC_Y, KC_Z,
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_ENTER, KC_ESCAPE, KC_BSPACE, KC_TAB, KC_SPACE, KC_MINUS, KC_EQUAL,
    KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_NONUS_HASH, KC_SCOLON, KC_QUOTE,
    KC_GRAVE, KC_COMMA, KC_DOT, KC_SLASH, KC_CAPSLOCK,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
    KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE,
    KC_INSERT, KC_HOME, KC_PGUP,
    KC_DELETE, KC_END, KC_PGDOWN,
    KC_RIGHT, KC_LEFT, KC_DOWN, KC_UP
) = list(range(0x53))
(
    KC_LCTRL, KC_LSHIFT, KC_LALT, KC_LGUI,
    KC_RCTRL, KC_RSHIFT, KC_RALT, KC_RGUI
) = list(range(0xE0, 0xE0 + 8))
(
    KC_FN, KC_APPLICATION # KC_FN doesn't exists in the header file
) = (20737, 0x65)
(
    KC_MS_WH_UP, KC_MS_WH_DOWN
) = (0xF9, 0xFA)

# alias, in keycode.h #define
KC_CLCK = KC_CAPSLOCK
KC_CAPS = KC_CAPSLOCK
KC_SLCK = KC_SCROLLLOCK

KC_PSCR = KC_PSCREEN
KC_PAUS = KC_PAUSE
KC_BRK  = KC_PAUSE
KC_INS  = KC_INSERT
KC_DEL  = KC_DELETE
KC_PGDN = KC_PGDOWN
KC_RGHT = KC_RIGHT
KC_APP  = KC_APPLICATION
# KC_EXEC = KC_EXECUTE
# KC_SLCT = KC_SELECT
# KC_AGIN = KC_AGAIN
# KC_PSTE = KC_PASTE
# KC_ERAS = KC_ALT_ERASE
# KC_CLR  = KC_CLEAR


KC_ENT  = KC_ENTER
KC_ESC  = KC_ESCAPE
KC_BSPC = KC_BSPACE
KC_SPC  = KC_SPACE
KC_MINS = KC_MINUS
KC_EQL  = KC_EQUAL
KC_LBRC = KC_LBRACKET
KC_RBRC = KC_RBRACKET
KC_BSLS = KC_BSLASH
KC_NUHS = KC_NONUS_HASH
KC_SCLN = KC_SCOLON
KC_QUOT = KC_QUOTE
KC_GRV  = KC_GRAVE
KC_COMM = KC_COMMA
KC_SLSH = KC_SLASH

KC_LCTL = KC_LCTRL
KC_LSFT = KC_LSHIFT
KC_LCMD = KC_LGUI
KC_LWIN = KC_LGUI
KC_RCTL = KC_RCTRL
KC_RSFT = KC_RSHIFT
KC_RCMD = KC_RGUI
KC_RWIN = KC_RGUI



# map keycode to led id
keycode_to_led_id = {
    KC_FN:         82, # KC_FN doesn't exists in the header file
    KC_APP:        83,

    KC_MS_WH_UP:   76,
    KC_MS_WH_DOWN: 86,

    KC_LCTRL:      77,
    KC_LSHIFT:     64,
    KC_LALT:       79,
    KC_LGUI:       78,
    KC_RCTRL:      84,
    KC_RSHIFT:     75,
    KC_RALT:       81,
    KC_RGUI:        0,
}
for keycode, led_id in enumerate([
        0, 0, 0, 0,
        52,69,67,54,37,55,56,57,42,58,59,60,71,
        70,43,44,35,38,53,39,41,68,36,66,40,65,
        18,19,20,21,22,23,24,25,26,27,
        63, 1,30,34,80,28,29,45,46,47, 0,
        61,62,17,72,73,74,51,
        2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,
        14,15,16,31,32,33,48,49,50,
        87,85,86,76]):
    keycode_to_led_id[keycode] = led_id
# keycode_to_led_id.update({})


def ktli(keycode):
    """
    this function maps keycode to led id
    """
    return keycode_to_led_id.get(keycode, 0)


def keycode_name(keycode):
    """
    return keycode name from keycode
    """
    for n, v in globals().items():
        if ( v == keycode ) and n.startswith("KC_"):
            return n
    return "KC_NO"
distance_map = {}

_____ = KC_NO
KEY_POSITION = [ # F1 to F12 are tricky
    [ _____,   KC_ESC,  _____,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  _____,  KC_F5,  KC_F6,   KC_F7,  KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  _____,   KC_PSCR, KC_SLCK, KC_PAUS,  ],
    # [ _____,   _____,   _____,   _____,  _____,  _____,  _____,  _____,  _____,  _____,   _____,  _____,   _____,    _____,   _____,   _____,   _____,   _____,   _____,   _____,    ],
    [ _____,   KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, KC_BSPC, _____,   KC_INS,  KC_HOME, KC_PGUP,  ],
    [ _____,   KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS, KC_BSLS, _____,   KC_DEL,  KC_END,  KC_PGDN,  ],
    [ _____,   KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,  KC_ENT,  KC_ENT,  KC_ENT,  _____,   _____,   _____,   _____,    ],
    [ _____,   KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,  KC_RSFT, KC_RSFT, KC_RSFT, _____,   _____,   KC_UP,   _____,    ],
    [ KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RALT, _____,  20737,   KC_APP,   KC_RCTL, KC_RCTL, KC_RCTL, _____,   KC_LEFT, KC_DOWN, KC_RIGHT, ],
]


KEY_POSITION_WIDTH = len(KEY_POSITION[0])
KEY_POSITION_HEIGHT = len(KEY_POSITION)
x, y = 0, 0
while x < KEY_POSITION_WIDTH and y < KEY_POSITION_HEIGHT:
    sk = KEY_POSITION[y][x]
    print(f"sk {sk} at ({x}, {y})")
    for i in range(0, KEY_POSITION_WIDTH):
        for j in range(0, KEY_POSITION_HEIGHT):
            tk = KEY_POSITION[j][i]
            if sk == tk or sk == None or tk == None: continue
            dis = abs(i - x) + abs(j - y)
            if i < x and j > y: dis -= min(abs(i-x), abs(j-y))
            if sk not in distance_map:
                distance_map[sk] = {}
            if tk not in distance_map:
                distance_map[tk] = {}
            if tk not in distance_map[sk]:
                distance_map[sk][tk] = None
            if sk not in distance_map[tk]:
                distance_map[tk][sk] = None
            
            _dis = distance_map[sk][tk]
            if _dis and (_dis < dis):
                continue
            distance_map[sk][tk] = dis
            distance_map[tk][sk] = dis
            
    if x < KEY_POSITION_WIDTH-1:
        x += 1
    else:
        x = 0
        y += 1
    
print("DISTANCE MAP:")
print("\n".join([f"{k}: [{len(v)}]{(v.items())}" for k, v in distance_map.items()]))

sorted_distance_map = {}
for sk, dis_dict in distance_map.items():
    if sk not in sorted_distance_map:
        sorted_distance_map[sk] = {}
    for tk, dis in dis_dict.items():
        if dis in sorted_distance_map[sk]:
            sorted_distance_map[sk][dis].append(tk)
        else:
            sorted_distance_map[sk][dis] = [tk]

print("#" * 80)
for sk, dis_dict in sorted(sorted_distance_map.items()):
    print(f"source key: {keycode_name(sk)}")
    for dis, key_list in sorted(dis_dict.items()):
        print(f"{' '*4}distance = {dis}: {[keycode_name(sk) for sk in key_list]}")
    

print("#" * 80)
input("press enter to proceed to C code...")
print("#" * 80)
key_list_max_length = 0
key_list_max_distance = 0
output = "{\n"
for sk, dis_dict in sorted(sorted_distance_map.items()):
    print(f"source key: {sk}")
    if sk == KC_NO: continue
    output += f"[{ktli(sk)}] = {{{{{len(dis_dict)}}},{chr(10)}"
    for dis, key_list in sorted(dis_dict.items()):
        output += f"{' '*4}[{dis}] = {{{len(key_list)}, "
        for tk in key_list[:-1]:
            output += f"{ktli(tk)}, "
        output += f"{key_list[-1]}}},{chr(10)}"
        key_list_max_length = max(key_list_max_length, len(key_list))
        key_list_max_distance = max(key_list_max_distance, dis)
    output += "},\n"


print(output)
print(f"#define KEY_LIST_MAX_DISTANCE {key_list_max_distance}")
print(f"#define KEY_LIST_MAX_LENGTH {key_list_max_length}")
print("_ub DISTANCE_MAP[LED_NUMBERS][KEY_LIST_MAX_DISTANCE+1][KEY_LIST_MAX_LENGTH+1];")


valid = True
for k1, v in distance_map.items():
    for k2, d in v.items():
        if distance_map[k1][k2] != distance_map[k2][k1]:
            valid = False

if valid:
    print("valid result")
else:
    print("invalid result")












print("\n" * 2 + "="*80)
print("white fade")
from math import *
a = [ceil(255 * cos(pi / 2 / 18 * i)) for i in range(18)]
print(", ".join([(f"{{ {i:3}, {i:3}, {i:3} }}") for i in a]))