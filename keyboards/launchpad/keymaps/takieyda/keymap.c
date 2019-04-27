// Below layout is based upon /u/That-Canadian's planck layout
#include "launchpad.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0

#define _FUNC 15

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PSTE LCTL(KC_V)
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))
#define LOCK LGUI(KC_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------.  ,---------------------------.
 * |   1  |  2   |  | Undo |  Cut | Copy | Paste|
 * |------+------|  |------+------+------+------|
 * |   3  |  4   |  |      |      | Esc  | FUNC |
 * |------+------|  `---------------------------'
 * |   5  |  6   |
 * |------+------|
 * | FUNC |  8   |
 * `-------------'
 */
[_QWERTY] = LAYOUT( \
    KC_1,      UNDO, \
    KC_3,      CUT, \
    KC_ESC,    COPY, \
    MO(_FUNC), PSTE  \
),

/* Function
 * ,-------------.  ,---------------------------.
 * |   Q  |CALDEL|  |CALDEL|TSKMGR| LOCK |      |
 * |------+------|  |------+------+------+------|
 * |   A  |TSKMGR|  |      |      |      |      |
 * |------+------|  `---------------------------'
 * |   Z  |  X   |
 * |------+------|
 * |      |  C   |
 * `-------------'
 */
[_FUNC] = LAYOUT( \
    KC_Q,    CALTDEL, \
    KC_A,    TSKMGR, \
    KC_Z,    LOCK, \
    _______, KC_C \
)

};

void matrix_init_user(void) {
    
}
