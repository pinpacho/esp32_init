#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN 25
#define BIN_PIN 2

void app_main(void)
{
    int led_state = 0;
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(BIN_PIN,GPIO_MODE_INPUT);
    
    gpio_set_level(LED_PIN,led_state);

    while (1)
    {
        led_state = gpio_get_level(BIN_PIN);
        gpio_set_level(LED_PIN,led_state);
    }
    

}
