/**
 * @file blink.c
 * @brief This library handles blinking the led
 */

#include <stdio.h>

#include "blink.h"

#include "pico/cyw43_arch.h"
#include "pico/multicore.h"
#include "pico/stdlib.h"

/**
 * @brief Blinks an LED once. WARNING: Ensure you have initialized the
 * peripheral before running this function.
 *
 * @param void
 */
bool blink_led_once(int *count) {
  int c = *count;
  c = c + 1;
  *count = c;
  if (c % 11) // add to count and check if divisible by 11
    return false;
  return true;
}
