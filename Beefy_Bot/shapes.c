// ----------------------------------------------------------------------
// Author: Alex Youngs
// 2/10/12
// Purpose: This file contains all functions that perform shapes
// ----------------------------------------------------------------------

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"

void circle(int times){
	unsigned int i, j;
	
	for(times; times>0; times--){
		r_forward();
		l_forward();
		for(i = 11200; i>0; i--){
			for(j=200; j>0; j--){}
			l_off();
			for(j=800; j>0; j--){
			}
			l_forward();
		}
	}
}

void line(void){
	unsigned long i;
		
	r_forward();
	l_forward();
	for(i = 800000; i>0; i--){}
	l_off();
	r_off();
}

void ninety_turn(void){
	unsigned long i;
	
	l_forward();
	for(i = 830000; i>0; i--){}
	l_off;	
}

void rectangle(int times){
	int i;
	
	for(times; times>0; times--){
		for(i=4; i>0; i--){
			line();
			ninety_turn();
		}
	}
}

void one_eighty_turn(int times){
	unsigned long i;
	
	for(times; times>0; times--){
		r_forward();
		l_reverse();
		for(i=1000000; i>0; i--){}
		r_off();
		l_off();
	}
}

void figure_eight(int times){
	unsigned long i;
	
	for(times; times>0; times--){
		one_eighty_turn(2);
		line();
		one_eighty_turn(3);
		line();
		one_eighty_turn(1);
	}	
}
	