
#ifndef _ENCODEROBJECT_H_
#define _ENCODEROBJECT_H_
#include "hardware/timer.h"

class Encoder{
    private:
    int steps_c = 0; //step_c
    int steps_per_sec = 0; // step_per_sec
    int dir = 0;
    bool state = false;
    int out_pin;
    int total_steps; // total_steps
    int32_t now = 0;
    int32_t stop = 0;

    public:
    Encoder(int out_pin, int total_amount);
    void Setup();
    void lapCount();
    int32_t getSteps();
    void setDir(int dir);
    void reset();
    void countPerMilliSecond(int32_t time_amount = 1000);
    int32_t getStepsPerMilliSecond();
};

#endif