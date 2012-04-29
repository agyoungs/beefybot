//-----------------------------------------------------------------------------------------------------
//	Author: Alex Youngs
//	Date: 3/17/2012  
//	Compiler Revision: HEW Version 4.05.01.001
//	Purpose: This file contains all the interrupt service routines updated from the vector table.
//-----------------------------------------------------------------------------------------------------
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

#pragma INTERRUPT A2DInterrupt

void A2DInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT UART0TransmitInterrupt
void UART0TransmitInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT DMA0Interrupt
void DMA0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT UART0ReceiveInterrupt
void UART0ReceiveInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release 
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	while(ri_u0c1 == OFF);	  // make sure receive is complete
	
    while(ti_u0c1 == OFF); 			//  puts it in the UART 0 transmit buffer 

	u0tb = (char) u0rb;      // read in received data
    
}

#pragma INTERRUPT TimerA1Interrupt
void TimerA1Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	This handles the interrupt for Timer A1. It will start an A2D every time in.
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT TimerA2Interrupt
void TimerA2Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release 
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT KeyBoardInterrupt
void KeyBoardInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT WakeUpInterrupt
void WakeUpInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release 
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT RTCInterrupt
void RTCInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release 
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT TimerB0Interrupt
void TimerB0Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: To increment the ints for lap time, end time, and checking the line 
//			(currently configured to 5 ms)
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//-----------------------------------------------------------------------------------------------------
{
	wait_time += ON;	//increments the calibration timer
	fn_sec += ON;		//increments the lap timer
	check = TRUE;  		//sets the flag for the car to check the line
}

#pragma INTERRUPT TimerB1Interrupt
void TimerB1Interrupt(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: To increment an int for use in PWM (currently configured to .5 ms)
// 	Rev: 1.1
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 4/23/2012
//-----------------------------------------------------------------------------------------------------
{
	delay_timer += ON;
}

#pragma INTERRUPT WatchDogInterrupt
void WatchDogInterrupt(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Unused in this program
//  Rev:    1.0     Initial Release 
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT switch1_isr
void switch1_isr(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: To toggle the corresponding LED for Switch 1.
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//-----------------------------------------------------------------------------------------------------
{
		LED0 ^= ON;
		switch_count += ON;
}

#pragma INTERRUPT switch2_isr
void switch2_isr(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: To toggle the corresponding LED for Switch 2.
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//-----------------------------------------------------------------------------------------------------
{
		LED2 ^= ON;
		switch_count += ON;
}

#pragma INTERRUPT switch3_isr
void switch3_isr(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: To toggle the corresponding LED for Switch 3.
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//-----------------------------------------------------------------------------------------------------
{
		LED1 ^= ON;
		switch_count += ON;
}

#pragma INTERRUPT uart2_receive_isr
void uart2_receive_isr(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: Not used for line follwoing
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//-----------------------------------------------------------------------------------------------------
{
}

#pragma INTERRUPT uart2_transmit_isr
void uart2_transmit_isr(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: Not used for line following
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//-----------------------------------------------------------------------------------------------------
{
}
