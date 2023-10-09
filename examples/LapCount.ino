#include <Encoder.h>

uint out_pin = 2;
Encoder my_encoder(out_pin, 20);

void setup(){
    my_encoder.Setup();
    my_encoder.setDir(-1);
}

void loop(){
    my_encoder.lapCount();
    Serial.print("Steps ");
    Serial.print(my_encoder.getSteps());
    Serial.print("\n");
    delay(10);
}
