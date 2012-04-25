// ----------------------------------------------------------------------
// Author: Alex Youngs
// 2/10/12
// Purpose: This file contains all functions that control the motors
// ----------------------------------------------------------------------

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

void r_forward(){
	if(R_REVERSE == ON) r_off();
	R_FORWARD = ON;	

}

void r_reverse(){
	if(R_FORWARD == ON) r_off();
	R_REVERSE = ON;
}

void r_off(){
	R_FORWARD = OFF;
	R_REVERSE = OFF;

}

void l_forward(){
	if(L_REVERSE == ON) l_off();
	L_FORWARD = ON;

}

void l_reverse(){
	if(L_FORWARD == ON) l_off();
	L_REVERSE = ON;

}

void l_off(){
	L_FORWARD = OFF;
	L_REVERSE = OFF;

}

int calibrate(int side){
	int low = 1000;
	int high = 0;
	int threshold = 0;
	wait_time = 0;
	IR_LED = ON;
	while(wait_time <= 400){
		LED0 ^= ON;
		LED1 ^= ON;
		LED2 ^= ON;
		if(side == R_DETECTOR){
			BNSPrintf(LCD,"\trlo:%04u \nrhi:%04u",low,high);
			if(ad2 <= low) low = ad2;
			if(ad2 >= high) high = ad2;
		}
		if(side == L_DETECTOR){
			BNSPrintf(LCD,"\tllo:%04u \nlhi:%04u",low,high);
			if(ad3 <= low) low = ad3;
			if(ad3 >= high) high = ad3;
		}	
	}
	threshold = (high + low)/AVERAGE+200;
	return threshold;
}

int checkline(int side){
	int offset=0;
	if(ad2 > r_threshold){	 
		r_lines = OFF;
		r_first = FALSE;
	}
	if(ad3 > l_threshold){
		l_lines = OFF;
		l_first = FALSE;
	}
	if(ad3 < l_threshold) {
		if(r_first == FALSE){
			l_first = TRUE;
			l_lines = 1;
		}
		else l_lines = -1;
	}
	if(ad2 < r_threshold){
		if(l_first == FALSE){
			r_first = TRUE;
			r_lines = -1;
		}
		else r_lines = 1;
	}
	if(side == R_DETECTOR){
		if (r_lines <= 0) offset = -10;
		if (r_lines == 1) offset = 10;
	}
	if(side == L_DETECTOR){
		if (l_lines == -1) offset = 10;
		if (l_lines >= 0) offset = -10;
	}

	return offset;
}