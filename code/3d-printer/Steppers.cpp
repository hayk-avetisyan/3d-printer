#include <Arduino.h>
#include <Stepper.h>

class Steppers {
  private:
    Stepper** steppers;
    
  public:
    Steppers(Stepper* steppers[]) {
      this->steppers = steppers;
    };

    void setSpeeds(int speed) {
      for(int i = 0; i < sizeof(this->steppers); i++) {
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
        for(int i = 0; i < sizeof(this->steppers); i++) {
          this->steppers[i]->step(dir);
        }
        steps_left--;
      }
    };

    void step(int steps, int index) {
      this->steppers[index]->step(steps);
    };
};
