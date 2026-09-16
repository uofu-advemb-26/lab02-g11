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
 * @brief Blinks an LED once
 *
 * @param void
 */
void blink_led_once(__unused void *params) {
  // cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, on);
  // if (count++ % 11) // add to count and check if divisible by 11
  //   on = !on;
  while (true) {
  }
}
