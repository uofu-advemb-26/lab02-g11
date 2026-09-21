#ifndef BLINK_H
#define BLINK_H

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"

#include "pico/cyw43_arch.h"
#include "pico/multicore.h"
#include "pico/stdlib.h"

bool blink_led_once(int *count);

#endif
