/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "FreeRTOS.h"
#include "blink.h"
#include "task.h"

#include "pico/cyw43_arch.h"
#include "pico/multicore.h"
#include "pico/stdlib.h"

int count = 0;
bool on = false;

#define MAIN_TASK_PRIORITY (tskIDLE_PRIORITY + 1UL)
#define BLINK_TASK_PRIORITY (tskIDLE_PRIORITY + 2UL)
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define BLINK_TASK_STACK_SIZE configMINIMAL_STACK_SIZE

/**
 * @brief Blinking led once every 5500 ms.
 *
 * @param void
 */
void blink_task(__unused void *params) {
  hard_assert(cyw43_arch_init() == PICO_OK);
  while (true) {
    blink_led_once(&count, &on);
    vTaskDelay(500);
  }
}

/**
 * @brief Initialize blink task, and reverses stdin alphabet
 *
 * @param void
 */
void main_task(__unused void *params) {
  xTaskCreate(blink_task, "BlinkThread", BLINK_TASK_STACK_SIZE, NULL,
              BLINK_TASK_PRIORITY, NULL);
  char c;
  while (c = getchar()) {     // Get char from stdin
    if (c <= 'z' && c >= 'a') // If lower, return upper
      putchar(c - 32);
    else if (c >= 'A' && c <= 'Z') // If upper, return lower
      putchar(c + 32);
    else
      putchar(c);
  }
}

/**
 * @brief Init pico rtos, schedule main_task. See main_task func for more.
 *
 * @return
 */
int main(void) {
  stdio_init_all();
  const char *rtos_name;
  rtos_name = "FreeRTOS";
  TaskHandle_t task;
  xTaskCreate(main_task, "MainThread", MAIN_TASK_STACK_SIZE, NULL,
              MAIN_TASK_PRIORITY, &task);
  vTaskStartScheduler();
  return 0;
}
