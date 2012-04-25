//-----------------------------------------------------------------------------------------------------
//  Author: Alex
//	Date: 2/3/2012
//	Purpose: This file contains the main program that I want my board to run.
//-----------------------------------------------------------------------------------------------------
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

volatile int switch_count = OFF;		//switch control variable
uchar line_detect = FALSE;
long delay_timer = OFF;
long wait_time = OFF;
long fn_sec = OFF;
int threshold;
int beginning = OFF;
int start = OFF;
int offset = OFF;
int check = FALSE;
int r_threshold = 0;
int l_threshold = 0;
int r_lines = OFF;
int l_lines = OFF;
int fixed = TRUE;
int r_crossed = FALSE;
int l_crossed = FALSE;
int r_first = FALSE;
int l_first = FALSE;
int end = FALSE;

void main(void)
{
	uchar motor_switch = FALSE;
	uchar direction = FORWARD;
	uchar direction_change = TRUE;
	int swap = OFF;
	int l_high;
	int r_high;
	int lap = FALSE;
	
	InitPorts();
	init_ints();
	system_clock_init();
	InitDisplay("bot");
//  InitUART();
  	TimerInit();
	ADInit();	
	ENABLE_SWITCHES;
	
	/* LED initialization - macro defined in qsk_bsp.h */
 	ENABLE_LEDS	
	
	_asm("fset i"); // enable interrupts
	
	TimerB0_Start();
	TimerB1_Start();
	TimerA4_Start();
	DisplayString(LCD_LINE1, "agyoungs");
	DisplayString(LCD_LINE2, "HW9");
	IR_LED = ON;
	adcon0 |= A2D_START;
	delay_timer = 0;
	r_high = 50;
	l_high = 50;
	beginning = 0;
	while(TRUE) {
		BNSPrintf(LCD,"\trt: %04u \nlt: %04u",r_first,l_first);
		if(LED0 == LED_ON && LED2 == LED_ON){
			BNSPrintf(LCD,"\tAD2:%04u \nAD3:%04u",ad2,ad3);
			r_threshold = calibrate(R_DETECTOR);
			l_threshold = calibrate(L_DETECTOR);
			LED0 = LED_OFF;
			LED1 = LED_OFF;
			LED2 = LED_OFF;
		}
		fn_sec = 0;
		while(ad0 >= MILLISECONDS && end == FALSE){
			if(r_high >= 40) r_high = 40;
			if(l_high >= 40) l_high = 40;
			if(l_high <= 0) l_high = 0;
			if(r_high <= 0) r_high = 0;
			//l_high = 0;
			//r_high = 20;
			if(delay_timer >= HUNDRED) {
					check = TRUE;
					delay_timer = OFF;
			}
			if(delay_timer < r_high) r_forward();
			else r_off();
			if(delay_timer < l_high) l_forward();
			else l_off();
			if(check == TRUE){
				check = FALSE;
				r_high -= checkline(R_DETECTOR);
				l_high -= checkline(L_DETECTOR);
			}
			if(fn_sec >= 9000 && lap == FALSE){
				one_eighty_turn(1);
				lap = TRUE;
			}
			if (fn_sec >= 2*9000){
				end = TRUE;
			}
		}
		r_off();
		l_off();
	}
}