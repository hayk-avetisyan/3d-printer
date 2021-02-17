#include <Arduino.h>
#include <Stepper.h>

class Steppers {
  private:
    Stepper** steppers;
    int count;
    
  public:
    Steppers(Stepper* steppers[], int count) {
      this->steppers = steppers;
      this->count = count;
      Serial.print(count);
    };

    void setSpeeds(int speed) {
      for(int i = 0; i < this->count; i++) {
        this->steppers[i]->setSpeed(speed);
      }
    };
    
    void setSpeed(int speed, int index) {
      this->steppers[index]->setSpeed(speed);
    };

    void steps(int steps) {
      int dir = (steps > 0) ? -1 : 1;
      int steps_left = abs(steps);
      
      while(steps_left > 0) { 
        for(int i = 0; i < this->count; i++) {
          this->steppers[i]->step(dir);
        }
        steps_left--;
      }
    };

    int size(){
      return count;
    };

    void step(int steps, int index) {
      this->steppers[index]->step(steps);
    };
};
