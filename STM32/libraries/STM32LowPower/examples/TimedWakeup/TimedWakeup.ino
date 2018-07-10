/*
  TimedWakeup

  This sketch demonstrates the usage of Internal Interrupts to wakeup a chip
  in deep sleep mode.

  In this sketch, the internal RTC will wake up the processor every second.

  This example code is in the public domain.
*/

#include "STM32LowPower.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // Configure low power
  LowPower.begin();
}

void loop() {
  digitalToggle(LED_BUILTIN);
  LowPower.deepSleep(1000);
}