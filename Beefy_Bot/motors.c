// ----------------------------------------------------------------------
// Author: Alex Youngs
// 2/10/12
// Purpose: This file contains all functions that control the motors
// ----------------------------------------------------------------------

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

void r_forward()
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Sets the right motor to forward
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	if(R_REVERSE == ON) r_off(); //only calls motors off if necessary
	R_FORWARD = ON;	

}

void r_reverse()
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Sets the right motor to reverse
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	if(R_FORWARD == ON) r_off(); //only calls motors off if necessary
	R_REVERSE = ON;
}

void r_off()
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Turns off right motor
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	R_FORWARD = OFF;
	R_REVERSE = OFF;

}

void l_forward()
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Sets the left motor to forward
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	if(L_REVERSE == ON) l_off(); //only calls motors off if necessary
	L_FORWARD = ON;

}

void l_reverse()
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Sets the left motor to reverse
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	if(L_FORWARD == ON) l_off(); //only calls motors off if necessary
	L_REVERSE = ON;

}

void l_off()
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Turns off left motors
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	L_FORWARD = OFF;
	L_REVERSE = OFF;

}

void one_eighty_turn(int times)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Spins the car around to go the other direction
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	unsigned long i;
	//a preset loop that has been calibrated to flip the car the other way by turning one motor forward and the other in reverse
	for(times; times> OFF; times--){
		r_forward();
		l_reverse();
		for(i=ONE_EIGHTY_COUNT; i>0; i--){}
		r_off();
		l_off();
	}
}

int* PWM(int r_high, int l_high)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Runs the motors at their specified speeds.
//  Rev:    1.0     Initial Release
//  Notes:          PWM period is 5ms (10 * .5ms timer = 5ms  
//-----------------------------------------------------------------------------------------------------
{
	int high_values[TWO_VALUES];
	if(r_high >= PWM_TICS) r_high = PWM_TICS; //sets max speed to 100%
	if(l_high >= PWM_TICS) l_high = PWM_TICS; //sets max speed to 100%
	if(l_high <= OFF) l_high = OFF; //sets max speed to 0%
	if(r_high <= OFF) r_high = OFF; //sets max speed to 0%
	if(delay_timer >= PWM_TICS) {
			delay_timer = OFF; //resets the timer to make PWM decisions (timer lasts 5ms)
	}
	if(delay_timer < r_high) r_forward(); //turn on motor while the timer is less than the high value
	else r_off(); //turn off motor while the timer is greater than the high value
	if(delay_timer < l_high) l_forward(); //turn on motor while the timer is less than the high value
	else l_off(); //turn off motor while the timer is greater than the high value
	high_values[RIGHT_VALUE] = r_high;
	high_values[LEFT_VALUE] = l_high;
	return &high_values[RIGHT_VALUE];  //return the array of ints giving main the values of right motor and left motor high times
}