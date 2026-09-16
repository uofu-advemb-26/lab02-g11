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
void blink_led_once(int *count, bool *on) {
  cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, *on);
  *count = *count + 1;
  if (*count % 11) // add to count and check if divisible by 11
    *on = !*on;
}
