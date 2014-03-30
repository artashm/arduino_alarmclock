#include "mode_one.h"

ModeOne::ModeOne(short *t_, LiquidCrystal *lcd_)
{
	t=t_;
	lcd=lcd_;
}

void ModeOne::displayTime(){
	char s_time[16]; //Text to display
	char week[3];

	switch(t[3]){
		case 0:
                        sprintf(s_time,"%02d:%02d:%02d SUN",t[0],t[1],t[2]);
			break;
		case 1:
                        sprintf(s_time,"%02d:%02d:%02d MON",t[0],t[1],t[2]);
			break;
		case 2:
                        sprintf(s_time,"%02d:%02d:%02d TUE",t[0],t[1],t[2]);
			break;
		case 3:
                        sprintf(s_time,"%02d:%02d:%02d WED",t[0],t[1],t[2]);
			break;
		case 4:
                        sprintf(s_time,"%02d:%02d:%02d THU",t[0],t[1],t[2]);
			break;
		case 5:
                        sprintf(s_time,"%02d:%02d:%02d FRI",t[0],t[1],t[2]);
			break;
		case 6:
                        sprintf(s_time,"%02d:%02d:%02d SAT",t[0],t[1],t[2]);
			break;
		default:
			sprintf(week,"Err");
			break;
	}	
	
	lcd->clear();
	lcd->setCursor(0,0);
	lcd->print(s_time);
}

void ModeOne::updateBuffers()
{
	if(t[2]>59){
	  t[1]++;
	  t[2]=0;
	  if(t[1]>59){
	    t[0]++;
	    t[1]=0;
	    if(t[0]>23){
	      t[0]=0;
	      t[3]++;
	      if(t[3]>6)
	    	t[3]=0;
	    }
	  }
	}
}

void ModeOne::loop()
{
	updateBuffers();
	t[2]++;
        displayTime();
	delay(1000);
	
};
