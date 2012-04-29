/***********************************************************************/
/*  																   */
/*  Author: Alex Youngs                                                */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*																	   */
/*  DESCRIPTION :  All functions that need prototyping should be       */
/* 	  				prototyped here. 								   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/


//LCD
void DisplayString(unsigned char position, _far const char * string);
void LCD_write(unsigned char data_or_ctrl, unsigned char value);
void DisplayDelay(unsigned long int units);
void BNSPutch(uint where, char c);
unsigned char BNSPrintf(uint where, char far * f, ...);
void InitDisplay(char far StartupString1[] );

//interrupts
void init_ints(void);

//ports
void InitPorts(void);
void InitPorts_0(void);
void InitPorts_1(void);
void InitPorts_2(void);
void InitPorts_3(void);
void InitPorts_4(void);
void InitPorts_5(void);
void InitPorts_6(void);
void InitPorts_7(void);
void InitPorts_8(void);
void InitPorts_9(void);
void InitPorts_10(void);

//timers
void TimerInit(void);

// motors
void r_off();
void r_forward(void);
void r_reverse(void);
void l_off();
void l_forward(void);
void l_reverse(void);
int* PWM(int r_high, int l_high);
void one_eighty_turn(int times);

//timers
void TimerB0_Init(void);
void TimerB0_Start(void);
void TimerB1_Init(void);
void TimerB1_Start(void);
void TimerA4_Init(void);
void TimerA4_Start(void);

//adc
int calibrate(int side);
void ADInit(void);
int* checkline(void);