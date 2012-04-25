//-----------------------------------------------------------------------------------------------------
//	Author: Alex Youngs
//	Date: 2/3/2012  
//	Compiler Revision: HEW Version 4.05.01.001
//	Purpose: This file contains the function to initialize all ports on the QSK.
//-----------------------------------------------------------------------------------------------------

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

//This funcition initializes all ports on the board
void InitPorts(void){
	InitPorts_0();
	InitPorts_1();
	InitPorts_2();
	InitPorts_3();
	InitPorts_4();
	InitPorts_5();
	InitPorts_6();
	InitPorts_7();
	InitPorts_8();
	InitPorts_9();
	InitPorts_10();
}

//This function initializes all pins on port 0
void InitPorts_0(void){
	p0_0 = OFF;
	p0_1 = OFF;
	p0_2 = OFF;
	p0_3 = OFF;	
	p0_4 = OFF;
 	p0_5 = OFF;	
	p0_6 = OFF;	
	p0_7 = OFF;
	
	//analog inputs for ADC
/*	pd0_0 = INPUT;
	pd0_1 = INPUT;
	pd0_2 = INPUT;
	pd0_3 = INPUT;
	pd0_4 = INPUT;
	pd0_5 = INPUT;
	pd0_6 = INPUT;
	pd0_7 = INPUT;*/	
}

//This function initializes all pins on port 1
void InitPorts_1(void){
	p1_0 = OFF;
	p1_1 = OFF;
	p1_2 = OFF;
	p1_3 = OFF;	
	p1_4 = OFF;
 	p1_5 = OFF;	
	p1_6 = OFF;	
	p1_7 = OFF;
	
	pd1_0 = OUTPUT;
	pd1_1 = OUTPUT;
	pd1_2 = OUTPUT;
	pd1_3 = OUTPUT;
	pd1_4 = OUTPUT;
	pd1_5 = OUTPUT;
	pd1_6 = OUTPUT;
	pd1_7 = OUTPUT;	
}

//This function initializes all pins on port 2
void InitPorts_2(void){
/*	p2_0 = OFF;
	p2_1 = OFF;
	p2_2 = OFF;
	p2_3 = OFF;	
	p2_4 = OFF;
 	p2_5 = OFF;	
	p2_6 = OFF;	
	p2_7 = OFF; */
	
	//analog inputs for ADC
	pd2_0 = INPUT;
	pd2_1 = INPUT;
	pd2_2 = INPUT;
	pd2_3 = INPUT;
	pd2_4 = INPUT;
	pd2_5 = INPUT;
	pd2_6 = INPUT;
	pd2_7 = INPUT;	
}

//This function initializes all pins on port 3
void InitPorts_3(void){
	R_FORWARD = OFF;
	R_REVERSE = OFF;
	L_FORWARD = OFF;
	L_REVERSE = OFF;
	GPS_PWRCNTL = OFF;	
	GPS_RESET_IN = OFF;
 	GPS_PWR = OFF;	
	IR_LED = OFF;	
	
	pd3_0 = OUTPUT;
	pd3_1 = OUTPUT;
	pd3_2 = OUTPUT;
	pd3_3 = OUTPUT;
	pd3_4 = OUTPUT;
	pd3_5 = OUTPUT;
	pd3_6 = OUTPUT;
	pd3_7 = OUTPUT;	
}

//This function initializes all pins on port 4
void InitPorts_4(void){
	p4_0 = OFF;
	p4_1 = OFF;
	p4_2 = OFF;
	p4_3 = OFF;	
	p4_4 = OFF;
 	p4_5 = OFF;	
	p4_6 = OFF;	
	p4_7 = OFF;
	
	pd4_0 = OUTPUT;
	pd4_1 = OUTPUT;
	pd4_2 = OUTPUT;
	pd4_3 = OUTPUT;
	pd4_4 = OUTPUT;
	pd4_5 = OUTPUT;
	pd4_6 = OUTPUT;
	pd4_7 = OUTPUT;	
}

//This function initializes all pins on port 5
void InitPorts_5(void){
	p5_0 = OFF;
	p5_1 = OFF;
	p5_2 = OFF;
	p5_3 = OFF;	
	p5_4 = OFF;
 	p5_5 = OFF;	
	p5_6 = OFF;	
	p5_7 = OFF;
	
	pd5_0 = OUTPUT;
	pd5_1 = OUTPUT;
	pd5_2 = OUTPUT;
	pd5_3 = OUTPUT;
	pd5_4 = OUTPUT;
	pd5_5 = OUTPUT;
	pd5_6 = OUTPUT;
	pd5_7 = OUTPUT;	
}

//This function initializes all pins on port 6
void InitPorts_6(void){
	p6_0 = OFF;
	p6_1 = OFF;
	p6_2 = OFF;
	p6_3 = OFF;	
	p6_4 = OFF;
 	p6_5 = OFF;	
	p6_6 = OFF;	
	p6_7 = OFF;
	
	pd6_0 = OUTPUT;
	pd6_1 = OUTPUT;
	pd6_2 = OUTPUT;
	pd6_3 = OUTPUT;
	pd6_4 = OUTPUT;
	pd6_5 = OUTPUT;
	pd6_6 = OUTPUT;
	pd6_7 = OUTPUT;
}		

//This function initializes all pins on port 7
void InitPorts_7(void){
	p7_0 = OFF;
	p7_1 = OFF;
	p7_2 = OFF;
	p7_3 = OFF;	
	p7_4 = OFF;
 	p7_5 = OFF;	
	p7_6 = OFF;	
	p7_7 = OFF;
	
	pd7_0 = OUTPUT;
	pd7_1 = OUTPUT;
	pd7_2 = OUTPUT;
	pd7_3 = OUTPUT;
	pd7_4 = OUTPUT;
	pd7_5 = OUTPUT;
	pd7_6 = OUTPUT;
	pd7_7 = OUTPUT;
}

//This function initializes all pins on port 8
void InitPorts_8(void){
	p8_0 = OFF;
	p8_1 = OFF;
	p8_2 = OFF;
	p8_3 = OFF;	
	p8_4 = OFF;
 	p8_5 = OFF;	
	p8_6 = OFF;	
	p8_7 = OFF;
	
	pd8_0 = OUTPUT;
	pd8_1 = OUTPUT;
	pd8_2 = OUTPUT;
	pd8_3 = OUTPUT;
	pd8_4 = OUTPUT;
	//pd8_5 = OUTPUT;
	pd8_6 = OUTPUT;
	pd8_7 = OUTPUT;
}

//This function initializes all pins on port 9
void InitPorts_9(void){
	p9_0 = OFF;
	p9_1 = OFF;
	p9_2 = OFF;
	p9_3 = OFF;	
	p9_4 = OFF;
/* 	p9_5 = OFF;	
	p9_6 = OFF;	
	p9_7 = OFF; */
	
	pd9_0 = OUTPUT;
	pd9_1 = OUTPUT;
	pd9_2 = OUTPUT;
	pd9_3 = OUTPUT;
	pd9_4 = OUTPUT;
	//analog inputs for ADC
	pd9_5 = INPUT;
	pd9_6 = INPUT;
	pd9_7 = INPUT;
}

//This function initializes all pins on port 10
void InitPorts_10(void){
/*	p10_0 = OFF;
	p10_1 = OFF;
	p10_2 = OFF;
	p10_3 = OFF;	
	p10_4 = OFF;
 	p10_5 = OFF;	
	p10_6 = OFF;	
	p10_7 = OFF; */
	
	//analog inputs for ADC
	pd10_0 = INPUT;
	pd10_1 = INPUT;
	pd10_2 = INPUT;
	pd10_3 = INPUT;
	pd10_4 = INPUT;
	pd10_5 = INPUT;
	pd10_6 = INPUT;
	pd10_7 = INPUT;
}