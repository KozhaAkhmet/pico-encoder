
#ifndef _ENCODEROBJECT_H_
#define _ENCODEROBJECT_H_

class Encoder{
    private:
    int counter = 0;
    int dir = 0;
    bool state = false;
    int out_pin;
    int total_amount;

    public:
    Encoder(int out_pin, int total_amount);
    void Setup();
    void Count();
    int getCounter();
    void setDir(int dir);
};

#endif