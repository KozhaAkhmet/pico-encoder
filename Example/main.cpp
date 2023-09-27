#include <stdio.h>
#include <stdlib.h>

#include "hardware/gpio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"
#include "Encoder.h"

uint out_pin = 21;
Encoder my_encoder(out_pin, 20);

void setup(){
    stdio_init_all();
    my_encoder.Setup();
}

int main(){
    setup();
    my_encoder.setDir(-1);
    while(true){
        my_encoder.Count();
        printf("\n %d", my_encoder.getCounter());
        sleep_ms(10);
    }
}
