#include "io.h"

short read_btn()
{
	short btn;
        btn = analogRead(0);
	if(btn > 1000) return btn_none;
	if(btn < 50)   return btn_right;
	if(btn < 250)  return btn_up;
	if(btn < 450)  return btn_down;
	if(btn < 650)  return btn_left;
	if(btn < 850)  return btn_select;

	return btn_none;
}
