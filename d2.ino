#include<Stepper.h> 
#define   STEPS 100
Stepper stepper (STEPS,8,10,9,11);

void setup() {
  stepper.setSpeed(200);
  
  Serial.begin(9600);
}

void loop() {
  Serial.println("ni");
  stepper.step(4096);
  delay(100);

  Serial.println("ni");
  stepper.step(-2048);
  delay(100);
}
