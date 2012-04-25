//-----------------------------------------------------------------------------------------------------
//	Author: Alex Youngs
//	Date: 3/15/2012  
//	Compiler Revision: HEW Version 4.05.01.001
//	Purpose: This file contains the functions to initialize all timers and start all timers
//-----------------------------------------------------------------------------------------------------
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

void TimerInit(void)

{ 
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Initializes Timers
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
   	TimerB0_Init();
	TimerB1_Init();
	TimerA4_Init();
}

void TimerB0_Init(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: To configure TimerB0 to cycle every 5ms
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//----------------------------------------------------------------------------------------------------
{
  	tb0mr = CLEAR_REGISTER;            // Clear Timer B0 Mode Register
	tb0mr |= TIMER_MODE;	             // Timer mode
	tb0mr |= SRC_F32;	             // Clock Source f32
	// (24MHz / 32 * [time in millisecond] / 1000 ms per second )-1
  	tb0 = (unsigned int) (((f1_CLK_SPEED/SOURCE_32)*DESIRED_TIME_MS/MILLISECONDS) - DECREMENT);
	
}

void TimerB0_Start(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: Starts TimerB0
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//----------------------------------------------------------------------------------------------------
{
	// disable irqs before setting irq registers - macro defined in skp_bsp.h
	DISABLE_IRQ		
  	tb0ic = PRIORITY_L_3; // Set the timer B0's IPL (interrupt priority level) to 3
  	ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
	// Start timer 
  	tb0s = ON;	    // Start timer B0
}

void TimerB1_Init(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: To configure TimerB1 to cycle every 500us
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//----------------------------------------------------------------------------------------------------
{
  	tb1mr = CLEAR_REGISTER;            // Clear Timer B1 Mode Register
	tb1mr |= TIMER_MODE;	             // Timer mode
	tb1mr |= SRC_F32;	             // Clock Source f32
	// (24MHz / 32 * [time in millisecond] / 1000 ms per second )-1
  	tb1 = (unsigned int) (((f1_CLK_SPEED/SOURCE_32)*DESIRED_TIME_US/MICROSECONDS) - DECREMENT);
	
}

void TimerB1_Start(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: Starts TimerB0
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//----------------------------------------------------------------------------------------------------
{
	// disable irqs before setting irq registers - macro defined in skp_bsp.h
	DISABLE_IRQ		
  	tb1ic = PRIORITY_L_3; // Set the timer B0's IPL (interrupt priority level) to 3
  	ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
	// Start timer 
  	tb1s = ON;	    // Start timer B0
}
	
void TimerA4_Init(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: Configures TimerA4 in event mode and sets Switch 3 to underflow the timer which interrupts
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//----------------------------------------------------------------------------------------------------
{
  	ta4mr = CLEAR_REGISTER;       	// Clear Timer Mode Register
	ta4mr |= EVENT_MODE;	       	// Event mode
	trgsr = CLEAR_REGISTER;			// Clear Trigger Select Register
	trgsr |= SELF_SELECT_AIN;		// TA4_in selected
  	ta4 = OFF;						// Every button press for SW3 triggers the interrupt;
	
}

void TimerA4_Start(void)
//-----------------------------------------------------------------------------------------------------
//	Purpose: Starts TimerA4.
// 	Rev: 1.0
//	Compiler: HEW Version 4.05.01.001
//	Author:	Alex Youngs
//	Date: 3/9/2012
//----------------------------------------------------------------------------------------------------
{
	// disable irqs before setting irq registers - macro defined in skp_bsp.h
	DISABLE_IRQ		
  	ta4ic = PRIORITY_L_3;    // Set the timer B0's IPL (interrupt priority level) to 3
  	ENABLE_IRQ    // enable interrupts macro defined in skp_bsp.h
	// Start timer 
  	ta4s = ON;	    // Start timer A4
}

