#include <LiquidCrystal.h>

#include "mode_one.h"
#include "mode_two.h"
#include "io.h"

LiquidCrystal lcd(8,9,4,5,6,7); //These are the pins used by the shield

short t[4]; //Seconds, Minutes, Hours
short mode;  //Stores the Mode of operation
short btn; //button press
bool  just_came; // Indicates if it just came
//short ind; //index

ModeOne m1(t,&lcd);
ModeTwo m2(&btn,&lcd,t,&mode);

//Initial Setup
void setup()
{
  //Just Some Welcome Message
  lcd.clear();
  lcd.print("Starting:");
  lcd.setCursor(0,1); //column,row
  lcd.print("Watch");
  
  //delay(3000); //wait 5 seconds
  lcd.clear();

  //Initialize Variables
  t[3] = 0; //Week
  t[2] = 0; //Seconds
  t[1] = 0; //Minutes
  t[0] = 0; //Hours 
  mode = 1; //Set to Watch
  
  just_came=false; //Just Another Flag
}

//Main Loop
void loop()
{
   btn = read_btn(); //read button from shield
   if(btn == btn_select && mode == 1){
	   mode = 2;
	   btn = btn_none;
   }
   
   delay(200);
   tone(2,262,8);
   //Display Mode	
   switch(mode){
     case 1:
       m1.loop();
       break;
     case 2:
       m2.loop();
   }
   noTone(2);
   
}
