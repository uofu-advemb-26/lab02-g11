#include "blink.h"
#include "unity_config.h"
#include <pico/stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unity.h>

void setUp(void) {}

void tearDown(void) {}

void test_variable_assignment() {
  int x = 1;
  TEST_ASSERT_TRUE_MESSAGE(x == 1, "Variable assignment failed.");
}

void test_multiplication(void) {
  int x = 30;
  int y = 6;
  int z = x / y;
  TEST_ASSERT_TRUE_MESSAGE(
      z == 5, "Multiplication of two integers returned incorrect value.");
}

void test_blink(void) {
  int count = 10;

  TEST_ASSERT_TRUE_MESSAGE(blink_led_once(&count),
                           "Blinking once does not turn LED on");
}

void test_blink_iteration(void) {
  int count = 0;
  for (int i = 0; i < 10; i++) {
    TEST_ASSERT_FALSE_MESSAGE(blink_led_once(&count),
                              "Counting does not count correctly");
  }

  TEST_ASSERT_TRUE_MESSAGE(blink_led_once(&count),
                           "Blinking once does not turn LED on");
}

int main(void) {
  stdio_init_all();
  while (true) {
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_variable_assignment);
    RUN_TEST(test_multiplication);
    RUN_TEST(test_blink);
    RUN_TEST(test_blink_iteration);
    sleep_ms(5000);
    UNITY_END();
  }
}
