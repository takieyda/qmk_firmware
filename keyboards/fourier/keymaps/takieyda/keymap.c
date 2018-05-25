#include "fourier.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
/*#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3*/

enum fourier_layers {
	_BASE,
	_FN1,
	_FN2,
	_FN3
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FNC1,
  FNC2
};

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_FN1 FNC1 //MO(_FN1)
#define KC_FN2 FNC2 //MO(_FN2)
// #define KC_SPFN1 LT(_FN1, KC_SPACE)
// #define KC_SPFN2 LT(_FN2, KC_SPACE)
// #define KC_BSFN1 LT(_FN1, KC_BSPC)
// #define KC_BSFN2 LT(_FN2, KC_BSPC)
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
    ESC , Q  , W  , E  , R  , T  , Y  , U  , I  , O  , P  ,LBRC,RBRC,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    TAB  , A  , S  , D  , F  , G  , H  , J  , K  , L  ,SCLN, ENTER  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    LSFT   , Z  , X  , C  , V  , B  , N  , M  ,COMM,DOT ,SLSH, RSFT ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    LCTL ,LGUI,LALT ,FN1 ,  BSPC  ,   SPC  ,FN2  ,RALT , APP , RCTL 
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN1] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    GRV , 1  , 2  , 3  , 4  , 5  , 6  , 7  , 8  , 9  , 0  ,MINS,EQL ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    TRNS ,    ,VOLD,VOLU,MUTE,    ,LEFT,DOWN, UP ,RGHT,    , QUOT   ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    TRNS   ,    ,    ,    ,    ,    ,    ,    ,TRNS,TRNS,TRNS,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    TRNS ,TRNS,TRNS ,TRNS,  TRNS  ,  TRNS  ,FN2  ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),

  [_FN2] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
    TILD, F1 , F2 , F3 , F4 , F5 , F6 , F7 , F8 , F9 ,F10 ,F11 ,F12 ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
    TRNS ,RMOD,    ,    ,INS ,PGUP,HOME,    ,    ,    ,    ,  BSLS  ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    TRNS   ,RTOG,    ,    ,DEL ,PGDN,END ,    ,PSCR,SLCK,PAUS,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    TRNS ,TRNS,TRNS ,FN1 , DEL    ,  TRNS  ,TRNS ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  ),
  
  [_FN3] = LAYOUT_kc(
 //,----+----+----+----+----+----|----+----+----+----+----+----+----.
        ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,    ,
 //|----`----`----`----`----`----|----`----`----`----`----`----`----|
         ,    ,RHUI,RSAI,RVAI,    ,    ,    ,    ,    ,    ,        ,
 //|-----`----`----`----`----`----|----`----`----`----`----`--------|
    RMOD   ,    ,RHUD,RSAD,RVAD,    ,    ,    ,    ,    ,    ,      ,
 //|-------`----`----`----`----`----|----`----`----`----`----`------|
    RTOG ,    ,     ,TRNS, TRNS   ,  TRNS  ,TRNS ,     ,     ,      
 //`-----+----+-----+----+--------|--------+-----+-----+-----+------'
  )

  
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case FNC1:
			if (record->event.pressed) {
				layer_on(_FN1);
				update_tri_layer(_FN1, _FN2, _FN3);
			} else {
				layer_off(_FN1);
				update_tri_layer(_FN1, _FN2, _FN3);
			}
			return false;
			break;
		case FNC2:
			if (record->event.pressed) {
				layer_on(_FN2);
				update_tri_layer(_FN1, _FN2, _FN3);
			} else {
				layer_off(_FN2);
				update_tri_layer(_FN1, _FN2, _FN3);
			}
			return false;
			break;
	}
	return true;
}