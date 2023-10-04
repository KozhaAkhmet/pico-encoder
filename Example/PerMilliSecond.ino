#include <Encoder.h>

uint out_pin = 2;
Encoder my_encoder(out_pin, 20);

void setup() {
    my_encoder.Setup();
    my_encoder.setDir(-1);
}

void loop() {
    my_encoder.countPerMilliSecond(200);
    Serial.print(" Steps per millisecond");
    Serial.print(my_encoder.getStepsPerMilliSecond());
    Serial.print(" current steps");
    Serial.print(my_encoder.getSteps());
    Serial.print("\n");
    delay(10);
}
