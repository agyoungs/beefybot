//-----------------------------------------------------------------------------------------------------
//	Author: Alex Youngs
//	Date: 2/3/2012  
//	Purpose: This file contains the functions necessary to operate the ADC as well as check ADC values.
//-----------------------------------------------------------------------------------------------------

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"


void ADInit(void)
{
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Initializes the ADC
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
	adcon0 = CLEAR_REGISTER;
	adcon1 = CLEAR_REGISTER;
	adcon2 = CLEAR_REGISTER;
	
	adcon0 |= REPEAT_SWEEP;
	adcon0 |= CKS0;
	
	adcon1 |= TEN_BIT;
	adcon1 |= VREF_CONNECT;
	adcon1 |= SWEEP_AN0_AN3;	
}   

int calibrate(int side){
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Calibrates the threshold values
//  Rev:    1.3     Added thresholds for right and left sensors instead of an average of the two
//  Notes:          This creates threshold values for the left and right sensors.   
//-----------------------------------------------------------------------------------------------------
	int low = LOW_VALUE;
	int high = OFF;
	int threshold = OFF;
	wait_time = OFF;
	IR_LED = ON;
	while(wait_time <= TWO_SECS){
		LED0 ^= ON;				//flicker LEDs to show calibration
		LED1 ^= ON;
		LED2 ^= ON;
		if(side == R_DETECTOR){
			BNSPrintf(LCD,"\trlo:%04u \nrhi:%04u",low,high); 	//display values to show you readings
			if(ad2 <= low) low = ad2;							//find the lowest reading to set as low
			if(ad2 >= high) high = ad2;							//find the highest reading to set as high
		}
		if(side == L_DETECTOR){									
			BNSPrintf(LCD,"\tllo:%04u \nlhi:%04u",low,high);	//display values to show you readings
			if(ad3 <= low) low = ad3;							//find the lowest reading to set as low
			if(ad3 >= high) high = ad3;							//find the highest reading to set as high
		}	
	}
	threshold = (high + low)/AVERAGE;		//take the average to create a threshold
	return threshold;
}

int* checkline(void){
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Checks to see where the car is relative to the line
//  Rev:    1.5     Changes to help find where the car is if both sensors are off the line
//  Notes:          Sends back an offset value to slow down or increase motor speeds depending on
//					the readings from the ADC.  
//-----------------------------------------------------------------------------------------------------
	int offset[TWO_VALUES]; //array of two for both offset values.
	int r_offset=OFF;
	int l_offset=OFF;
	if(ad2 > r_threshold){	 //if right detector is on the black line
		r_lines = BLACK_LINE;	//set the car's position to on the line
		r_first = FALSE;		//reset the right side off the line first value since it is back on the line
	}
	if(ad3 > l_threshold){   //if left detector is on the black line
		l_lines = BLACK_LINE;  	//set car's position to on the line
		l_first = FALSE;		//reset the left side off the line first value since it is back on the line
	}
	if(ad3 < l_threshold) {  	//if left detector is off the black line
		if(r_first == FALSE){	//if the right detector wasn't the first one off the line
			l_first = TRUE;  	//set the left detector as the first one off the line 
			l_lines = OFF_LEFT;	//set the car's position to off to the left
		}
		else l_lines = OFF_RIGHT;//if the right detector was first one off set the car's position to off to the right
	}
	if(ad2 < r_threshold){		//if right detector is off the line
		if(l_first == FALSE){	//if the left detector wasn't the first one off the line
			r_first = TRUE;		//set the right detector as the first one off the line
			r_lines = OFF_RIGHT;//set the car's position to off to the right
		}
		else r_lines = OFF_LEFT;//if the left detector was the first one off set the car's position to off to the left
	}
	if (r_lines == BLACK_LINE || r_lines == OFF_RIGHT) r_offset = OFFSET; 	//this offset will increase the ON time by 10% on the right side
	if (r_lines == OFF_LEFT) r_offset = -OFFSET;							//this offset will reduce the ON time 10% on the right side	
	if (l_lines == OFF_RIGHT) l_offset = -OFFSET;							//this offset will reduce the ON time by 10% on the left side
	if (l_lines == BLACK_LINE || l_lines == OFF_LEFT ) l_offset = OFFSET; 	//this offset will increase the ON time by 10% on the left side
	
	if (r_lines == BLACK_LINE && l_lines == BLACK_LINE){ //show middle led for on the black line
		LED0=LED_OFF;
		LED1=LED_ON;
		LED2=LED_OFF;
	}
	if (r_lines == OFF_RIGHT){	//show right led for off to the right
		LED0=LED_OFF;
		LED1=LED_OFF;
		LED2=LED_ON;
	} 
	if (l_lines == OFF_LEFT){	//show left led for off to the left 
		LED0=LED_ON;
		LED1=LED_OFF;
		LED2=LED_OFF;
	}		
	
	offset[RIGHT_VALUE] = r_offset;	//set the return array with the offset values
	offset[LEFT_VALUE] = l_offset;
	return &offset[RIGHT_VALUE];
}