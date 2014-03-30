#include "mode_two.h"

ModeTwo::ModeTwo(short *btn_, LiquidCrystal *lcd_, 
		 short *t_, short *mode_)
{
	ind  = 0;
	btn  = btn_;
	t    = t_;
	lcd  = lcd_;
	mode = mode_; 
}

void ModeTwo::processActions()
{
	switch(*btn)
	{
		case btn_select:
			*mode=1;
			*btn=btn_none;
			break;
		case btn_right:
			if(ind<3)
				ind++;
			else
				ind=0;
			*btn=btn_none;
			break;
		case btn_left:
			if(ind > 0)
				ind--;
			else
				ind=3;
			*btn=btn_none;
			break;
		case btn_up:
			if(checkUpperLimit())
				t[ind]++;
			*btn=btn_none;
			break;
		case btn_down:
			if(t[ind]>0)
				t[ind]--;
			*btn=btn_none;
			break;
	}
	
}

bool ModeTwo::checkUpperLimit()
{
	switch(ind)
	{
		case 0:
			if(t[ind]<23)
				return true;
			break;
		case 1:
			if(t[ind]<59)
				return true;
			break;
		case 2:
			if(t[ind]<59)
				return true;
			break;
		case 3:
			if(t[ind]<6)
				return true;
			break;
	}

	return false;
}

void ModeTwo::displayData()
{ 
	char sTxt[16];
	char sBTxt[16];
	
        //char week[5];

	/* switch(t[3]){
		case 0:
			//sprintf(week,"SUN");
			strcpy(week,"SUN");
			break;
		case 1:
			//sprintf(week,"MON");
			strcpy(week,"MON");
			break;
		case 2:
			//sprintf(week,"TUE");
                        strcpy(week,"TUE");
			break;
		case 3:
			//sprintf(week,"WED");
                        strcpy(week,"WED");
			break;
		case 4:
			//sprintf(week,"TUE");
                        strcpy(week,"TUE");
			break;
		case 5:
			//sprintf(week,"FRI");
                        strcpy(week,"FRI");
			break;
		case 6:
			//sprintf(week,"SAT");
                        strcpy(week,"SAT");
			break;
	}; */
	
	//sprintf(sTxt,"%02d:%02d:%02d %s",t[0],t[1],t[2],week);
	sprintf(sTxt,"%02d:%02d:%02d:%02d",t[0],t[1],t[2],t[3]);
	switch(ind){
		case 0:
			sprintf(sBTxt,"  :%02d:%02d:%02d",t[1],
					t[2],t[3]);
			break;
		case 1:
			sprintf(sBTxt,"%02d:  :%02d:%02d",t[0],
					t[2],t[3]);
			break;
		case 2:
			sprintf(sBTxt,"%02d:%02d:  :%02d",t[0],
					t[1],t[3]);
			break;
		case 3:
			sprintf(sBTxt,"%02d:%02d:%02d:  ",t[0],
					t[1],t[2]);
			break;
	};
	
	lcd->clear();
	lcd->print(sTxt);
	delay(300);
	lcd->clear();
	lcd->print(sBTxt);
        delay(100);
}

void ModeTwo::loop()
{
	lcd->clear();
        processActions();
        displayData();
        delay(200);
        *btn = btn_none;
}
