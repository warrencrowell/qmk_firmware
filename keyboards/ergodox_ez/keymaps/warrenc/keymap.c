#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,

};

/* Keymap X: Empty Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |  Bksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------| -    |           |  =   |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |Hyper |           |  `   |   N  |   M  |   ,  |   .  |   /  |Shft/Ent|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|      |      | LAlt | LGui |                                       |   [  |   ]  |      |      |  L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |MPrev |       |MNext |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LGui  |LAlt  |------|       |------| L1   |Space |
 *                                 |      |      |  L3  |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [0] = LAYOUT_ergodox(
    KC_ESCAPE      , KC_1           , KC_2           , KC_3           , KC_4           , KC_5           , KC_TRANSPARENT      ,
    KC_TAB         , KC_Q           , KC_W           , KC_E           , KC_R           , KC_T           , KC_MINUS            ,
    KC_LCTRL       , KC_A           , KC_S           , KC_D           , KC_F           , KC_G           ,
    KC_LSHIFT      , CTL_T(KC_Z)    , KC_X           , KC_C           , KC_V           , KC_B           , ALL_T(KC_NO)        ,
    KC_LCTRL       , KC_TRANSPARENT , KC_TRANSPARENT , KC_LALT        , KC_LGUI        ,
                                                                KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,
                                                                                     KC_TRANSPARENT,
                                                       KC_LGUI, KC_LALT       ,               MO(3),

    KC_TRANSPARENT , KC_6                , KC_7           , KC_8           , KC_9           , KC_0             , KC_BSPACE ,
    KC_EQUAL       , KC_Y                , KC_U           , KC_I           , KC_O           , KC_P             , KC_BSLASH ,
                     KC_H                , KC_J           , KC_K           , KC_L           , KC_SCOLON        , KC_QUOTE  ,
    KC_GRAVE       , KC_N                , KC_M           , KC_COMMA       , KC_DOT         , RCTL_T(KC_SLASH) , KC_SFTENT ,
    KC_LBRACKET    , KC_RBRACKET         , KC_TRANSPARENT , KC_TRANSPARENT , MO(2)          ,
    KC_MEDIA_NEXT_TRACK , KC_TRANSPARENT ,
    KC_TRANSPARENT ,
    KC_TRANSPARENT , MO(1)               , KC_SPACE
),
/* Keymap 1: Directional
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    | F1   | F2   | F3   | F4   | F5   |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  | DELETE |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | !    | @    | {    | }    | |    |      |           | PGUP |      | END  | PGUP |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | #    | $    | (    | )    | `    |------|           |------| Left | Down | Up   | Right|      | NOOP   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | %    | ^    | [    | ]    | ~    |      |           | PGDN |  &   | PGDN | HOME |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      | .    |  0   | =    |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */

  [1] = LAYOUT_ergodox(
    KC_ESCAPE      , KC_F1          , KC_F2          , KC_F3          , KC_F4          , KC_F5          , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_EXLM        , KC_AT          , KC_LCBR        , KC_RCBR        , KC_PIPE        , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_HASH        , KC_DLR         , KC_LPRN        , KC_RPRN        , KC_GRAVE       ,
    KC_TRANSPARENT , KC_PERC        , KC_CIRC        , KC_LBRACKET    , KC_RBRACKET    , KC_TILD        , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
                                                             KC_TRANSPARENT , KC_TRANSPARENT ,
                                                                              KC_TRANSPARENT ,
                                            KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT , KC_F6          , KC_F7          , KC_F8          , KC_F9          , KC_F10         , KC_DELETE        ,
    KC_PGUP        , KC_TRANSPARENT , KC_END         , KC_PGUP        , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT   ,
                     KC_LEFT        , KC_DOWN        , KC_UP          , KC_RIGHT       , KC_TRANSPARENT , KC_NO            ,
    KC_PGDOWN      , KC_AMPR        , KC_PGDOWN      , KC_HOME        , KC_TRANSPARENT , KC_TRANSPARENT , RSFT_T(KC_ENTER) ,
                     KC_TRANSPARENT , KC_DOT         , KC_0           , KC_EQUAL       , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT
),

/* Keymap 2: Media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | vol up |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      | pause  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |vol down|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */

  [2] = LAYOUT_ergodox(
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT      , KC_TRANSPARENT    ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT      , KC_TRANSPARENT    ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT      ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT      , KC_TRANSPARENT    ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
                                                             KC_TRANSPARENT , KC_TRANSPARENT ,
                                                                              KC_TRANSPARENT ,
                                            KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT      , KC_TRANSPARENT    ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT      , KC_AUDIO_VOL_UP   ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_MEDIA_PLAY_PAUSE ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT      , KC_AUDIO_VOL_DOWN ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT
),

/* Keymap 3: Empty Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  7   |  8   |  9   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|  4   |  5   |  6   |enter |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  1   |  2   |  3   |enter |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
  [3] = LAYOUT_ergodox(
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
                                                            KC_TRANSPARENT , KC_TRANSPARENT ,
                                                                             KC_TRANSPARENT ,
                                           KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_KP_7        , KC_KP_8        , KC_9           , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_KP_4        , KC_KP_5        , KC_KP_6        , KC_KP_ENTER    , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_KP_1        , KC_KP_2        , KC_KP_3        , KC_KP_ENTER    , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_KP_0        , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT
),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
