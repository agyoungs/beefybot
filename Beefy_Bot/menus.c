//-----------------------------------------------------------------------------------------------------
//  Author: Alex
//	Date: 4/20/2012
//	Purpose: This file contains the scrolling menu functions and definitions for HW 9.
//-----------------------------------------------------------------------------------------------------
#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"


struct left_menu{
	_far char* value;
	_far char* color;
};

struct left_menu l_menu[] = {{"0       ", "Black   "},
							{"1       ", "Brown   "},
							{"2       ", "Red     "},
							{"3       ", "Orange  "},
							{"4       ", "Yellow  "},
							{"5       ", "Green   "},
							{"6       ", "Blue    "},
							{"7       ", "Violet  "},
							{"8       ", "Gray    "},
							{"9       ", "White   "}
};


_far char* m_menu[] = {	"Circle",
				"Square    ",
				"Triangle  ",
				"Octagon   ",
				"Pentagon  ",
				"Hexagon   ",
				"Cube      ",
				"Oval      ",
				"Sphere    ",
				"Cylinder  "
};

struct right_menu{
	_far char* lyric;
	_far char* color;
};

struct right_menu r_menu[] = {
								{"We're   ","Red     "},
								{"the     ","White   "},
								{"Red     ","Red     "},
								{"and     ","White   "},
								{"White   ","Red     "},
								{"from    ","White   "},
								{"State   ","Red     "},
								{"And     ","White   "},
								{"we      ","Red     "},
								{"know    ","White   "},
								{"we      ","Red     "},
								{"are     ","White   "},
								{"the     ","Red     "},
								{"best.   ","White   "},
								{"A       ","Red     "},
								{"hand    ","White   "},
								{"behind  ","Red     "},
								{"our     ","White   "},
								{"back,   ","Red     "},
								{"We      ","White   "},
								{"can     ","Red     "},
								{"take    ","White   "},
								{"on      ","Red     "},
								{"all     ","White   "},
								{"the     ","Red     "},
								{"rest.   ","White   "},
								{"Come    ","Red     "},
								{"over    ","White   "},
								{"the     ","Red     "},
								{"hill,   ","White   "},
								{"Carolina","Red     "},
								{"Devils  ","White   "},
								{"and     ","Red     "},
								{"Deacs   ","White   "},
								{"stand   ","Red     "},
								{"in      ","White   "},
								{"line.   ","Red     "},
								{"The     ","White   "},
								{"Red     ","Red     "},
								{"and     ","White   "},
								{"White   ","Red     "},
								{"from    ","White   "},
								{"N.C.    ","Red     "},
								{"State.  ","White   "},
								{"Go      ","Red     "},
								{"State!  ","White   "}
};

void s_left_menu(void){
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Display a scrolling menu for the left button
//  Rev:    1.0     Initial Release
//  Notes:          Currently displays Resistor Codes  
//-----------------------------------------------------------------------------------------------------
	int index = ad0/RESISTORS;
	DisplayString(LCD_LINE1, l_menu[index].value);
	DisplayString(LCD_LINE2, l_menu[index].color);
	beginning = OFF;
	end = OFF;
}

void s_mid_menu(void){
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Display a scrolling menu for the middle button
//  Rev:    1.0     Initial Release
//  Notes:          Currently displays Shapes
//-----------------------------------------------------------------------------------------------------	
	int index = ad0/SHAPES;
	DisplayString(LCD_LINE1, m_menu[index]);
	if (index+ABOVE == SIZE) DisplayString(LCD_LINE2, "STOP     ");
	else	DisplayString(LCD_LINE2, m_menu[index+ABOVE]);
	beginning = OFF;
	end = OFF;
}

void s_right_menu(void){
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Display a scrolling menu for the right button
//  Rev:    1.0     Initial Release
//  Notes:          Currently displays NC State Song 
//-----------------------------------------------------------------------------------------------------
	int index = ad0/SONG;
	if (index > UNDER) end = ON;

	if (index == SHIGH  && beginning == ON){
		//beginning = OFF; 
		end = OFF;
	}
	if (end == ON && index <= SHIGH){
		offset = SHIGH - index;
		index = SHIGH + offset;
	}
	if (index<ABOVE) beginning = OFF; 
	if (index == SHIGH  && beginning == ON){
		end = OFF;
	}
	if (end == ON && index >= LIMIT_A) beginning = ON;
	if (index+ABOVE == LENGTH) {
		DisplayString(LCD_LINE1, "STOP     ");
		DisplayString(LCD_LINE2, "STOP     ");
	}
	else {
		DisplayString(LCD_LINE1, r_menu[index].lyric);
		DisplayString(LCD_LINE2, r_menu[index].color);
	}
}