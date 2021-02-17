#include "Steppers.cpp"

const int NEMA = 200;
const int speed = 1;
Steppers* motors;

void setup() {
  Serial.begin(9600);
  
  Stepper* arr[] = { 
    new Stepper(NEMA, 2, 3, 4, 5),
    new Stepper(NEMA, 6, 7, 8, 9),
    new Stepper(NEMA, 10, 11, 12, 13)
  };
  motors = new Steppers(arr, 3);
  motors->setSpeeds(speed);
}

void loop() {
  motors->steps(1);
}
