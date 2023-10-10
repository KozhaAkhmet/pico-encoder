#include "Encoder.h"
#include "Arduino.h"

Encoder::Encoder(int out_pin, int total_steps) {
    this->out_pin = out_pin;
    this->total_steps = total_steps;
}
void Encoder::Setup() {
    pinMode(this->out_pin, INPUT);
}

// This function begins to count LOW to HIGH switches. Do not forget to call reset() or buffer overflow will happen.
// Use this function in loop.
void Encoder::lapCount() {
    if (digitalRead(this->out_pin) == 0) {
        state = true;
    } else if (digitalRead(this->out_pin) == 1 && state == true) {
        this->steps_c = this->steps_c + this->dir;
        state = false;
    }
}

// This function count steps in milliseconds. Per second by default.
// Use this in loop.
void Encoder::countPerMilliSecond(int time_amount) {
    now = millis();

    // printf(" time is :%d \n", to_ms_since_boot(get_absolute_time()));

    if (0 > (now - stop)) {
        // Counting the steps.
        lapCount();
    } else {
        // Updating the time step and assigning the steps_per_sec. Resetting the steps value.
        stop = now + time_amount;
        this->steps_per_sec = getSteps();
        reset();
    }
}

// You can set the direction, so the count value will be added or subtracted by given parameter, like passing 1 or -1.
void Encoder::setDir(int dir) {
    this->dir = dir;
}

// Get the steps value.
int Encoder::getSteps() {
    return this->steps_c;
}

// Get the value from Encoder::countPerSeconds.
int Encoder::getStepsPerMilliSecond() {
    return this->steps_per_sec;
}

// Resetting the steps to 0.
void Encoder::reset() {
    this->steps_c = 0;
}

