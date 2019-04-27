#include "fourier.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
/*#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3*/

enum fourier_layers {
	_BASE,
	_LOWER,
	_RAISE,
	_ADJUST,
	_NAV
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ESCNAV
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_LOWER LOWER //MO(_LOWER)
#define KC_RAISE RAISE //MO(_RAISE)
#define KC_ESCNAV LT(_NAV, KC_ESC)
// #define KC_SPLOWER LT(_LOWER, KC_SPACE)
// #define KC_SPRAISE LT(_RAISE, KC_SPACE)
// #define KC_BSLOWER LT(_LOWER, KC_BSPC)
// #define KC_BSRAISE LT(_RAISE, KC_BSPC)
#define KC_RST RESET
// #define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TAB , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
   ESCNAV, A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN, QUOT,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    LSFT   , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH, ENTER,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    LCTL ,LGUI,LALT ,LOWER,  BSPC ,   SPC  ,RAISE,RALT , APP , RCTL 
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_LOWER] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TILD,EXLM, AT ,HASH, DLR,PERC,CIRC,AMPR,ASTR,LPRN,RPRN,MINS,EQL ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    TRNS , F1 , F2 , F3 , F4 , F5 , F6 ,UNDS,PLUS,LCBR,RCBR, PIPE   ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    TRNS   , F7 , F8 , F9 , F10, F11, F12,    ,TRNS,TRNS,TRNS,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    TRNS ,TRNS,TRNS ,TRNS,  TRNS  ,  TRNS  ,RAISE,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_RAISE] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    GRV ,  1 ,  2 ,  3 ,  4 , 5  ,  6 , 7  ,  8 ,  9 ,  0 ,    ,    ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    TRNS ,    ,    ,    ,INS ,PGUP,HOME,MINS, EQL,LBRC,RBRC,  BSLS  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    TRNS   ,    ,    ,    ,DEL ,PGDN,END ,    ,TRNS,TRNS,TRNS,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    TRNS ,TRNS,TRNS ,LOWER, DEL   ,  TRNS  ,TRNS ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),
  
  [_ADJUST] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
        ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
         ,    ,RHUI,RSAI,RVAI,    ,    ,    ,    ,    ,    ,        ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    RMOD   ,    ,RHUD,RSAD,RVAD,    ,    ,    ,PSCR,SLCK,PAUS,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    RTOG ,    ,     ,TRNS, TRNS   ,  TRNS  ,TRNS ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),
  
  [_NAV] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
        ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
         ,    ,VOLD,VOLU,MUTE,    ,LEFT,DOWN, UP ,RGHT,    ,        ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
           ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
         ,    ,     ,    ,  DEL   ,        ,     ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  )
  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case LOWER:
			if (record->event.pressed) {
				layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
		case RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			return false;
			break;
	}
	return true;
}