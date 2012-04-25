
/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*																	   */
/*  DESCRIPTION :  All external declarations shall be made in this file*/
/* 	  																   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

// Project Specific

extern int disp_count;				// LED control variable
extern uint A2DValue;
extern uint A2DValuePot;
extern uint A2DValueTherm;
extern uchar A2DProcessed;
extern volatile int switch_count;
extern uchar line_detect;
extern volatile long delay_timer;
extern volatile char r_array[8];
extern volatile int r_index;
extern volatile int offset;
extern volatile int beginning;
extern volatile int end;
extern volatile long wait_time;
extern volatile long fn_sec;
extern volatile int check;
extern volatile int r_threshold;
extern volatile int l_threshold;
extern volatile int r_lines;
extern volatile int l_lines;
extern volatile int r_first;
extern volatile int l_first;
extern volatile int fixed;
extern volatile int r_crossed;
extern volatile int l_crossed;