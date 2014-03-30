#ifndef MODE_TWO_H
#define MODE_TWO_H

#include "Arduino.h"
#include "LiquidCrystal.h"
#include "io.h"

class ModeTwo{
	private:
		short *btn;
		LiquidCrystal *lcd;
		short *t;
		short *mode;
		short ind;
		
		bool checkUpperLimit();
		void processActions();
		void displayData();
	public:
		ModeTwo( short*, LiquidCrystal*, short*, short*);
		void loop();
};

#endif //MODE_TWO_H
