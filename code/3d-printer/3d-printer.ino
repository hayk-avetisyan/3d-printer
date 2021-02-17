#include "Steppers.cpp"

const int NEMA = 200;
const int speed = 60;
Steppers* motors;

void setup() {
  Serial.begin(9600);
  DDRB = 0xFF;
  Stepper* arr[] = { 
    new Stepper(NEMA, 2, 3, 4, 5),
    new Stepper(NEMA, 6, 7, 8, 9),
    new Stepper(NEMA, 10, 11, 12, 13)
  };
  
  motors = new Steppers(arr);
  motors->setSpeeds(speed);
}

void loop() {
  motors->steps(20);
  Serial.println("Hi");
}
