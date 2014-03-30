#ifndef MODE_ONE_H
#define MODE_ONE_H

#include "Arduino.h"
#include "LiquidCrystal.h"

//Display data in mode 1
class ModeOne 
{
  private:
        short *t;
        LiquidCrystal *lcd;
  public:
    //Constructior
    ModeOne(short *t_, LiquidCrystal *lcd_);
    
    //Display Time
    void displayTime();

    //Update the time 
    void updateBuffers();

    //Mode one iteration
    void loop();
};

#endif //MODE_ONE_H
