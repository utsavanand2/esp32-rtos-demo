/**
 * Date: July 20, 2022
 * Author: Kumar Utsav Anand
 * License: MIT
 **/

#include <Arduino.h>

// Use only core 1 for demo purposes.
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

static const int led_pin = LED_BUILTIN;

void toggleLED50(void *prameter)
{
  while (1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
}

void toggleLED500(void *prameter)
{
  while (1)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);

  // Task to run forever
  xTaskCreatePinnedToCore(
      toggleLED50,   // Function to be called
      "toggle_led1", // Name of task
      1024,          // Stack size (bytes in ESP32, words in FreeRTOS)
      NULL,          // Parameter to pass to function
      1,             // Task priority (0 to configMAX_PRIORITIES - 1)
      NULL,          // Task handle
      app_cpu);      // Run on one core for demo purposes (ESP32 only)

  xTaskCreatePinnedToCore(
      toggleLED500,  // Function to be called
      "toggle_led2", // Name of task
      1024,          // Stack size (bytes in ESP32, words in FreeRTOS)
      NULL,          // Parameter to pass to function
      1,             // Task priority (0 to configMAX_PRIORITIES - 1)
      NULL,          // Task handle
      app_cpu);      // Run on one core for demo purposes (ESP32 only)

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in main
  // after settings up your tasks.
}

void loop()
{
  // put your main code here, to run repeatedly:
}
