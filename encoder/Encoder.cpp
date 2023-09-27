#include "Encoder.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"

Encoder::Encoder(int out_pin, int total_amount) {
    this->out_pin = out_pin;
    this->total_amount = total_amount;
}

void Encoder::Setup() {
    gpio_init(this->out_pin);
    gpio_set_dir(this->out_pin, GPIO_IN);
}

// This function begins to count LOW to HIGH switches. Use this function in loop.
void Encoder::Count() {
    if (gpio_get(out_pin) == 0) {
        state = true;
    } else if (gpio_get(out_pin) == 1 && state == true) {
        this->counter = this->counter >= this->total_amount ||
                            this->counter <= -this->total_amount ?
                            (this->counter % this->total_amount) + this->dir :
                            this->counter + this->dir;
        state = false;
    }
}

void Encoder::setDir(int dir){
    this->dir = dir;
}

int Encoder::getCounter() {
    return this->counter;
}


// uint out_pin = 21;

// const int number_of_holes = 20;
// bool state = false;
// int hole_count = 0;
// int dir = 1;

// void count(){
//     hole_count =  hole_count >= number_of_holes ?
//                             (hole_count % number_of_holes) + dir :
//                             hole_count + dir;
// }

// void setup(){
//     stdio_init_all();
//     gpio_init(out_pin);
//     gpio_set_dir(out_pin, GPIO_IN);
// }

// int main(){
//     setup();
//     while(true){
//         if(gpio_get(out_pin) == 0 ){
//             state = true;
//         }else
//         if(gpio_get(out_pin) == 1 && state == true){
//             count();
//             state = false;
//         }
//         printf("\n %d", hole_count);
//         sleep_ms(10);
//     }
// }
