
#ifndef _ENCODEROBJECT_H_
#define _ENCODEROBJECT_H_

class Encoder{
    private:
    int steps_c = 0; //step_c
    int steps_per_sec = 0; // step_per_sec
    int dir = 0;
    bool state = false;
    int out_pin;
    int total_steps; // total_steps
    int now = 0;
    int stop = 0;

    public:
    Encoder(int out_pin, int total_amount);
    void Setup();
    void lapCount();
    int getSteps();
    void setDir(int dir);
    void reset();
    void countPerMilliSecond(int time_amount = 1000);
    int getStepsPerMilliSecond();
};

#endif