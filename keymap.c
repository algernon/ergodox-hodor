/*
 * HODOR
 */

#include "ergodox_ez.h"
#include "action_util.h"
#include "led.h"
#include "timer.h"

/* Layers */

#define HODOR 0

/* HODORs */
#define M_HODOR M(0)

static uint16_t hodor_t = 0;

/* The Keymap */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[HODOR] = KEYMAP(
 // left hand
 M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR

                                             ,M_HODOR ,M_HODOR
                                                      ,M_HODOR
                                    ,M_HODOR ,M_HODOR ,M_HODOR

                                                                // right hand
                                                               ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
                                                               ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
                                                                        ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
                                                               ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR
                                                                                 ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR ,M_HODOR

                                                               ,M_HODOR ,M_HODOR
                                                               ,M_HODOR
                                                               ,M_HODOR ,M_HODOR  ,M_HODOR
                  ),
};


const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  uint16_t hodor_e = timer_elapsed (hodor_t);

  if (id != 0)
    return MACRO_NONE;

  ergodox_led_all_off ();

  if (!record->event.pressed)
    return MACRO_NONE;

  if (hodor_e % 2 == 0)
    ergodox_right_led_1_on ();
  if (hodor_e % 3 == 0)
    ergodox_right_led_2_on ();
  if (hodor_e % 5 == 0)
    ergodox_right_led_3_on ();

  return MACRO (D(LSFT), T(H), U(LSFT), T(O), T(D), T(O), T(R), T(SPC), END);
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  hodor_t = timer_read ();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
}
