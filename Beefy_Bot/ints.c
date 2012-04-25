//-----------------------------------------------------------------------------------------------------
//	Author: Alex Youngs
//	Date: 3/15/2012  
//	Compiler Revision: HEW Version 4.05.01.001
//	Purpose: This file contains the functions to initialize all non-timer interrupts in the code.
//-----------------------------------------------------------------------------------------------------
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

void init_ints(void) 


{
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Initializes interrupts for INT0 to INT2
//  Rev:    1.0     Initial Release
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
	// set interrupt priority level
	//   for int0 to 7  (binary 111)
	ilvl0_int0ic = ON;
	ilvl1_int0ic = ON;
	ilvl2_int0ic = ON;
	
	// set int0 to trigger on
	//   negative edge (1->0)
	pol_int0ic = FALLING_EDGE;
	
	// set interrupt priority level
	//   for int1 to 7  (binary 111)
	ilvl0_int1ic = ON;
	ilvl1_int1ic = ON;
	ilvl2_int1ic = ON;

	// set int1 to trigger on
	//   negative edge (1->0)
	pol_int1ic = FALLING_EDGE;
}