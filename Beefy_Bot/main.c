//-----------------------------------------------------------------------------------------------------
//  Author: Alex
//	Date: 2/3/2012
//	Purpose: This file contains the main program that I want my board to run.
//-----------------------------------------------------------------------------------------------------
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

volatile int switch_count = OFF;		//switch control variable
long delay_timer = OFF;					//Increments every .5ms by Timer B1 and runs the PWM. 
long wait_time = OFF;					//Increments every 5ms by Timer B0 and runs the check line functions
long fn_sec = OFF;						//Increments every 5ms by Timer B0 and determines when to pull a U-turn
int check = FALSE;						//When true the line is checked
int r_threshold = OFF;					//Holds the average of black and white line values for the right detector
int l_threshold = OFF;					//Holds the average of black and white line values for the left detector
int r_lines = OFF;						//Determines if the right sensor is off the track or on the track and which side its off
int l_lines = OFF;						//Determines if the left sensor is off the track or on the track and which side its off
int r_first = FALSE;					//If the right sensor is first off the line this becomes true
int l_first = FALSE;					//If the left sensor is first off the line this becomes true
int end = FALSE;						//End is set to true when the time runs out for the track and stops the car

void main(void)
{
	int l_high;			//PWM value for left motor
	int r_high;			//PWM value for right motor
	int lap = FALSE;	//When true one lap has occurred
	int* high_values;
	int* offset_values;
	
	//initializations for the QSK boards
	InitPorts();
	init_ints();
	system_clock_init();
  	TimerInit();
	ADInit();	
	ENABLE_SWITCHES;
	InitDisplay(" ");
	
	/* LED initialization - macro defined in qsk_bsp.h */
 	ENABLE_LEDS	
	
	_asm("fset i"); // enable interrupts
	
	TimerB0_Start();
	TimerB1_Start();
	TimerA4_Start();
	DisplayString(LCD_LINE1, "agyoungs");
	DisplayString(LCD_LINE2, "Project4");
	IR_LED = ON;  //important for the emitter detector circuit to work
	adcon0 |= A2D_START;
	
	delay_timer = OFF; //sets the timer for the PWM to be low
	r_high = PWM_TICS; //initially sets right motor to full power
	l_high = PWM_TICS; //initially sets left motor to full power
	while(TRUE) {
		if(LED0 == LED_ON && LED2 == LED_ON){
			//Press left and right buttons to activate the calibrate section and leds should flicker to indicate calibration mode
			//Scroll Car over the black and white areas quickly to grab threshold values
			r_threshold = calibrate(R_DETECTOR); //gets white line and black line values for the Right Detector
			l_threshold = calibrate(L_DETECTOR); //gets white line and black line values for the Left Detector
			//When LEDs stop flickering you know calibration has finished
			LED0 = LED_OFF;
			LED1 = LED_OFF;
			LED2 = LED_OFF;
			DisplayString(LCD_LINE1, "Calibrat");
			DisplayString(LCD_LINE2, "Complete");
		}
		fn_sec = OFF; //reset timer 
		while(ad0 >= MILLISECONDS && end == FALSE){
			if(fn_sec<=SHORT_TIME){						//Display String takes a while so we only want 
				DisplayString(LCD_LINE1, " FOLLOW ");	//at the beginning so as to now waste time
				DisplayString(LCD_LINE2, "  LINE  ");	//the string will remain for the rest of the track
			}
			//after calibration mode is over turn the potentiometer all the way to the right to start car
			high_values = PWM(r_high,l_high);	//returns an array with the ON times for the motors 
			r_high = high_values[RIGHT_VALUE];	//sets the on time for the right motor
			l_high = high_values[LEFT_VALUE];	//sets the on time for the left motor
			
			if(check == TRUE){							//The Check flag is set by Timer B0 and fires every 5ms to see where the line is.
				check = FALSE; 							//reset the check flag to false
				offset_values = checkline();	  		//returns an array of the offset values
				r_high += offset_values[RIGHT_VALUE]; 	//sets the on time for the right motor to the previous value minus the offset
				l_high += offset_values[LEFT_VALUE]; 	//sets the on time for the right motor to the previous value minus the offset
			}
			//after one lap pull a U-turn and continue follwoing the line
			if(fn_sec >= ONE_LAP_TIME && lap == FALSE){
				one_eighty_turn(ONCE);
				lap = TRUE;
			}
			//after two laps set a flag to exit the loop
			if (fn_sec >= TWO_LAP_TIME){
				end = TRUE;
			}
		}
		//if it's not following the line, it's not moving
		r_off();
		l_off();
	}
}