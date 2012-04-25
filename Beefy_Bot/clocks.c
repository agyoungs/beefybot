//-----------------------------------------------------------------------------------------------------
//  Author: Alex Youngs
//	Date: 2/3/2012
//	Purpose: This file contains functions that initialize and use the clocks.
//-----------------------------------------------------------------------------------------------------

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

void system_clock_init(void)

{
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Initializes System Clock
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
	 unsigned int count = CLOCK_LIMIT;
  
	/* configure clock for divide by 1 mode */
	prc0 =ON;					/* enable access to clock registers */
	cm1 = CM16_17_RATIO;		/* set CM16,CM17 divide ratio to 1, 
								main clock on in high drive no PLL*/
	cm06 = DIVIDE_RATIO;		/* set divide ratio to 1 */		
	
    /* configure and switch main clock to PLL at 24MHz - uncomment this section
		out if PLL operation is desired								*/
   
	prc1 = ON;					/* allow writing to processor mode register */
	pm20 = ON;					/* set SFR access to 2 wait which is required for
   									operation greater than 16 MHz */
	prc1 = OFF;					/* protect processor mode register */

	plc0= PLL_2_ON;					// enable PLL (2X) and turn on

	while(count > OFF) count--;   /* wait for PLL to stabilize (20mS maximum, 240,000 cycles @12Mhz)
                                   this decrement with no optimization is 12 cycles each */
    cm11 = SWITCH_TO_PLL;                   /* switch to PLL */
    prc0 = OFF;   				/* protect clock control register */
	
	prc1 = ON;
	pm10 = ON;		// enable data flash area
	prc1 = OFF;
	
}