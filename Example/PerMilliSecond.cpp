#include <stdio.h>
#include <stdlib.h>

#include "Encoder.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"

uint out_pin = 21;
Encoder my_encoder(out_pin, 20);

void setup() {
    stdio_init_all();
    my_encoder.Setup();
}

int main() {
    setup();
    my_encoder.setDir(1);
    while (true) {
        my_encoder.countPerMilliSecond(200);
        printf(" Steps per millisecond %d, current steps %d \n", my_encoder.getStepsPerMilliSecond(), my_encoder.getSteps());
        sleep_ms(10);
    }
}
