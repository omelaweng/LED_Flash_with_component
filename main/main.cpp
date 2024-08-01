#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16);
LED led2(17);
LED led3(5);
LED led4(18);
LED led5(19);
LED led6(21);
LED led7(22);
LED led8(23);

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

void displayPattern(int pattern)
{
    for (int i = 0; i < 8; ++i)
    {
        if (pattern & (1 << i))
        {
            leds[i].ON();
        }
        else
        {
            leds[i].OFF();
        }
    }
}

extern "C" void app_main(void)
{
    const int patterns[] = {
        0b10000001, // *......*
        0b01000010, // .*....*.
        0b00100100, // ..*..*..
        0b00011000, // ...**...
        0b00011000, // ...**...
        0b00100100, // ..*..*..
        0b01000010, // .*....*.
        0b10000001  // *......*
    };

    int patternIndex = 0;
    while (1)
    {
        displayPattern(patterns[patternIndex]);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        if (++patternIndex >= 8)
            patternIndex = 0;
    }
}
