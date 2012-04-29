#include "sfr62p.h"
#include <ctype.h>
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include "LCD.h"


/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*																	   */
/*  DESCRIPTION :      All the defines for the projects are kept here. */
/* 	  																   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/


// These two defines are used to help keep track of which version of code we are running.
//  Major is incremented when a new feature or function is added.
//  Minor is incremented when there is a bug fix or attempted fix.

#define MAJOR_REV		1
#define MINOR_REV		1

// Shorthand stuff... 

#define BIT0			0x01
#define BIT1			0x02
#define BIT2			0x04
#define BIT3			0x08
#define BIT4			0x10
#define BIT5			0x20
#define BIT6			0x40
#define BIT7			0x80

#define ulong   unsigned long
#define uint	unsigned int
#define uchar 	unsigned char

#define TRUE	1
#define FALSE	0

#define PRESSED 0

#define PASSED  TRUE
#define FAILED  FALSE

#define YES		TRUE
#define NO		FALSE

#define ON		TRUE
#define OFF		FALSE

#define HIGH 1
#define LOW 0

#define AVERAGE	2
#define LIMIT	3

#define ENABLE_IRQ   	{_asm(" FSET I");}
#define DISABLE_IRQ		{_asm(" FCLR I");}

// Defines used to configure the Timer 
// This stuff sets up the timer to run a 1ms tick.


//#define f1_CLK_SPEED	(6000000L)
#define f1_CLK_SPEED	(24000000L)
#define MS_PER_TICK		1

#define TWO_FIFTY_MS			(250)		// ticks in 250 MS
#define ONE_HUNDRED_MS			(100)		// ticks in one hundred MS
#define ONE_SECOND				(10)		// one hundred MS ticks in a second


// Serial Port Defines
#define TX0_PRIORITY_LEVEL                      3
#define RX0_PRIORITY_LEVEL                      2

#define ENABLE_TX0_INTERRUPTS		           s0tic = TX0_PRIORITY_LEVEL;
#define DISABLE_TX0_INTERRUPTS		           s0tic = 0;
#define ENABLE_RX0_INTERRUPTS                  s0ric = RX0_PRIORITY_LEVEL;
#define DISABLE_RX0_INTERRUPTS                 s0ric = 0;

#define TX0_INTERRUPTS_ENABLED                 (s0tic != 0)
#define RX0_INTERRUPTS_ENABLED                 (s0ric != 0)

#define BAUD_RATE  9600
#define BAUD_RATE_2	4800

#define OUTPUT 1;
#define INPUT 0;

/* Switches */
#define	S1 						p8_3 
#define S2 						p8_1 
#define S3 						p8_2 
#define S1_DDR					pd8_3
#define S2_DDR					pd8_1
#define S3_DDR					pd8_2

/* LEDs */
#define	LED0					p8_0
#define	LED1						p7_4
#define	LED2					p7_2

#define	LED0_DDR 				pd8_0		// LED port direction register
#define	LED1_DDR 				pd7_4
#define	LED2_DDR 				pd7_2


#define LED_ON      			0
#define LED_OFF     			1

#define FALLING_EDGE			0

#define FORWARD					0
#define BACKWARD				1



// Use these macros for switch inputs. 
#define ENABLE_SWITCHES {S1_DDR = 0; S2_DDR = 0; S3_DDR = 0;}

// Use these macros to control the LEDs.  
#define LED(led, state) ((led) = !state)
#define ENABLE_LEDS {LED0 = LED_OFF; LED1 = LED_OFF; LED2 = LED_OFF; LED0_DDR = 1; LED1_DDR = 1; LED2_DDR = 1; }

// Defining QSK-Control Board Connector Pins
//port 0
//port 1
//port 2
//port 3
#define R_REVERSE				p3_0
#define	R_FORWARD				p3_1
#define L_FORWARD				p3_2
#define L_REVERSE				p3_3
#define GPS_PWRCNTL				p3_4
#define GPS_RESET_IN			p3_5
#define GPS_PWR					p3_6
#define IR_LED					p3_7

//port 4
//port 5
//port 6
//port 7
#define CPU_TXD2				p7_0
#define CPU_RXD2				p7_1

//port 8
//port 9
//port 10
#define BRIGHTNESS_R			p10_3
#define BRIGHTNESS_L			p10_2

//timers
#define CLEAR_REGISTER        	(0x00) // Clear Register
#define DESIRED_TIME_MS       	(0x05) //  5 millisecond timer
#define TIMER_MODE            	(0x00) //  Timer Mode
#define EVENT_MODE            	(0x01) //  Event Mode
#define PULSE_MODE            	(0x02) //  Pulse Period Mode
#define SRC_F1_F2_PCLK0       	(0x00) //  selected in PCLKR Register bit 0
#define SRC_F8                	(0x40) //  clock source f8
#define SRC_F32               	(0x80) //  clock source f32
#define SRC_FC32            	(0xC0) //  clock source fC32
#define SELF_SELECT_AIN			(0x00) //  Self Select A timer
#define DESIRED_TIME_US			(0x32) //  200 us

//ADC
//Control Register 0
#define ONE_SHOT				(0x00) //One Shot Mode
#define REPEAT					(0x08) //Repeat Mode
#define SINGLE_SWEEP			(0x10) //Single Sweep Mode
#define REPEAT_SWEEP			(0x18) //Repeat Sweep Mode
#define A2D_START				(0x40) //Start A2D Conversion
#define CKS0					(0x80) //Set CKS0 to 1

//Control Register 1
#define TEN_BIT					(0x08) //Ten bit
#define EIGHT_BIT				(0x00) //Eight bit
#define VREF_CONNECT			(0x20) //Connect VREF
#define VREF_DISCONNECT			(0x00) //Disconnect VREF
#define SWEEP_AN0_AN1			(0x00) //ANO to AN1 in Repeat Sweep mode
#define	SWEEP_AN0_AN3			(0x01) //ANO to AN3 in Repeat Sweep mode
#define SWEEP_AN0_AN5			(0x02) //AN0 to AN5 in Repeat Sweep mode
#define SWEEP_AN0_AN7			(0x03) //AN0 to AN7 in Repeat Sweep mode

//Clocks
#define CLOCK_LIMIT				40000
#define DIVIDE_RATIO			0
#define WAITTW0					1
#define PLL_2_ON				(0x92)
#define	SWITCH_TO_PLL			1
#define CM16_17_RATIO 			(0x20)
#define DECREMENT				1

//timers
#define SOURCE_32				32
#define MILLISECONDS 			1000
#define MICROSECONDS 			100000
#define PRIORITY_L_3			3
#define ONE_LAP_TIME			6000
#define TWO_LAP_TIME			2*ONE_LAP_TIME


//IR detectors
#define R_DETECTOR 				1
#define L_DETECTOR 				-1
#define RIGHT_VALUE				0
#define LEFT_VALUE				1
#define TWO_VALUES				2
#define OFF_RIGHT				-1
#define	OFF_LEFT				1
#define BLACK_LINE				0
#define OFFSET					1
#define LOW_VALUE				1000
#define TWO_SECS				400

//PWM Timer
#define PWM_TICS				10
#define SHORT_TIME				10

//Motors
#define ONE_EIGHTY_COUNT		1000000
#define ONCE					1