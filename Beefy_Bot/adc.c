//-----------------------------------------------------------------------------------------------------
//	Author: Alex Youngs
//	Date: 2/3/2012  
//	Purpose: "This file contains the functions necessary to operate the ADC." - Eric
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
/*
void calibrate(){
	int white_line = OFF;
	int black_line = OFF;
	int test = OFF;
	
	IR_LED = ON;
	white_line = (ad2)/AVERAGE;
	LED0 = LED_ON;
	LED1 = LED_OFF;
	LED2 = LED_ON;
	while (delay_timer <= 2000){
		test = ad2;
		if 	(delay_timer%20 == 0){
			LED0 ^= 1;
			LED1 ^= 1;
			LED2 ^= 1;
			BNSPrintf(LCD,"\ttop:%04u \nlow:%04u", black_line, test);
		}
		if (test <= white_line)
			white_line = test;
		if (test >= black_line)
			black_line = test;
	}
	threshold = (black_line + white_line)/AVERAGE;	
	BNSPrintf(LCD,"\ttop:%04u \nlow:%04u", threshold, white_line);
}*/