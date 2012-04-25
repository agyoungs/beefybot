//-----------------------------------------------------------------------------------------------------
// 	Author: Alex Youngs 
//	Date: 2/3/2012
//	Purpose:  This file contains the functions necessary to set up my serial ports.
//-----------------------------------------------------------------------------------------------------

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

void InitUART(void)
{
	InitUART_0();
	InitUART_2();
}

void InitUART_0(void)
{
		int dummy;
	u0brg = (unsigned char)(((f1_CLK_SPEED/16)/BAUD_RATE)-1);	// set UART0 bit rate generator

		 /*
	  	  bit rate can be calculated by:
	  	  bit rate = ((BRG count source / 16)/baud rate) - 1

		  in this example: BRG count source = f1 (12MHz - Xin in SKP16C62P)
						   baud rate = 19200
						   bit rate = ((12MHz/16)/19200) - 1 = 38 

	  	  ** one has to remember that the value of BCLK does not affect BRG count source */

  	ucon = 0x00; 		// UART transmit/receive control register 2
		 /*
		  00000000; 	// transmit irq not used
		  ||||||||______UART0 transmit irq cause select bit, U0IRS
	   	  |||||||_______UART1 transmit irq cause select bit, U1IRS
	   	  ||||||________UART0 continuous receive mode enable bit, U0RRM - set to 0 in UART mode
	  	  |||||_________UART1 continuous receive mode enable bit, U1RRM	- set to 0 in UART mode
	   	  ||||__________CLK/CLKS select bit 0, CLKMD0 - set to 0 in UART mode
	   	  |||___________CLK/CLKS select bit 1, CLKMD1 - set to 0 in UART mode
	   	  ||____________Separate CTS/RTS bit, RCSP
	  	  |_____________Reserved, set to 0 */

  	u0c0 = 0x10; 		// UART0 transmit/receive control register 1
		 /*
		  00010000;		// f1 count source, CTS/RTS disabled, CMOS output  
		  ||||||||______BRG count source select bit, CLK0
	   	  |||||||_______BRG count source select bit, CLK1
	   	  ||||||________CTS/RTS function select bit, CRS
	  	  |||||_________Transmit register empty flag, TXEPT
	   	  ||||__________CTS/RTS disable bit, CRD
	   	  |||___________Data output select bit, NCH
	   	  ||____________CLK polarity select bit, CKPOL 		- set to 0 in UART mode
	  	  |_____________Transfer format select bit, UFORM 	- set to 0 in UART mode */

  	u0c1 = 0x00; 		// UART0 transmit/receive control register 1
		 /*
		  00000000;		// disable transmit and receive 
		  ||||||||______Transmit enable bit, TE
	   	  |||||||_______Transmit buffer empty flag, TI
	   	  ||||||________Receive enable bit, RE
	  	  |||||_________Receive complete flag, RI
	   	  ||||__________Reserved, set to 0
	   	  |||___________Reserved, set to 0
	   	  ||____________Data logic select bit, U0LCH
	  	  |_____________Error signal output enable bit, U0ERE */

  	u0mr = 0x05;		// UART0 transmit/receive mode register, not reversed
		 /*
		  00000101;		// 8-bit data, internal clock, 1 stop bit, no parity
		  ||||||||______Serial I/O Mode select bit, SMD0
	   	  |||||||_______Serial I/O Mode select bit, SMD1
	   	  ||||||________Serial I/O Mode select bit, SMD2
	  	  |||||_________Internal/External clock select bit, CKDIR
	   	  ||||__________Stop bit length select bit, STPS
	   	  |||___________Odd/even parity select bit, PRY
	   	  ||____________Parity enable bit, PRYE
	  	  |_____________TxD, RxD I/O polarity reverse bit */

  	//u0tb = u0rb;		// clear UART0 receive buffer by reading
  	//u0tb = 0;			// clear UART0 transmit buffer
	dummy = u0rb;
	
    DISABLE_IRQ			// disable irqs before setting irq registers
	s0ric = 0x04;		// Enable UART0 receive interrupt, priority level 4	
	ENABLE_IRQ			// Enable all interrupts

  	u0c1 = 0x05; 		// UART0 transmit/receive control register 1
		 /*
		  00000101;		// enable transmit and receive 
		  ||||||||______Transmit enable bit, TE
	   	  |||||||_______Transmit buffer empty flag, TI
	   	  ||||||________Receive enable bit, RE
	  	  |||||_________Receive complete flag, RI
	   	  ||||__________Reserved, set to 0
	   	  |||___________Reserved, set to 0
	   	  ||____________Data logic select bit, U0LCH
	  	  |_____________Error signal output enable bit, U0ERE */
}


void InitUART_2(void){
	int dummy;
	
	u2brg = (unsigned char)(((f1_CLK_SPEED/16)/4800)-1);
	ucon = 0x00;
	u2c0 = 0x10;
	u2c1 = 0x00; 
	u2mr = 0x05;
	
	dummy = u2rb;
	
    DISABLE_IRQ			
	s2ric = 0x04;			
	ENABLE_IRQ	
	
	u2c1 = 0x05; 
}