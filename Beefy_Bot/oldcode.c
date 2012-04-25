	//	LED0 = LED_OFF;
		///LED1 = LED_OFF;
		//LED2 = LED_OFF;
//	//LEDDisplay();		// display current value of LED control variable */
/*		if(S1 == PRESSED){
			BNSPrintf(LCD,"\tLeft     \n        ");
			BNSPrintf(SERIAL,"\n\rButton1");			
			R_FORWARD ^= ON;
			/*for(debounce_count=60000;debounce_count>0;debounce_count--){
				for(j=2;j>0;j--){
					i+=1;
					}
				i+=1;
				}
			*/
/*			figure_eight(1);
		}
		else if (S2 == PRESSED){
			BNSPrintf(LCD,"\tOff      \n        ");
			BNSPrintf(SERIAL,"\n\rButton2");
			R_FORWARD = OFF;
			L_FORWARD = OFF;
			/*for(debounce_count=60000;debounce_count>0;debounce_count--){
				for(j=2;j>0;j--){
					i+=1;
					}
				i+=1;
				}
			*/
/*			rectangle(2);
		}
		else if (S3 == PRESSED){
			BNSPrintf(LCD,"\tRight     \n         ");
			BNSPrintf(SERIAL,"\n\rButton3");
			L_FORWARD ^= ON;
			/*for(debounce_count=60000;debounce_count>0;debounce_count--){
				for(j=2;j>0;j--){
					i+=1;
					}
				i+=1;
				}
			*/
		/*	circle(3);
		}
		/*else{
            if (A2DProcessed == TRUE) {         // only update the display when a new value is available
                A2DProcessed = FALSE;
                //BNSPrintf(LCD,"\tAD2:%04u \nAD3:%04u",ad4,ad3);
            }
		}*/
		
		
		
		
		   	/* Configure Timer A0 - 1ms (millisecond) counter */
   	/*ta0mr = 0x80;	// Timer mode, f32, no pulse output
   	ta0 = (unsigned int) (((f1_CLK_SPEED/32)*1e-3) - 1);	// (1ms x 12MHz/32)-1 = 374
 
   	/* Configure Timer A1 - Timer A0 used as clock */
   	/*ta1mr = 0x01;	// Event Counter mode, no pulse output
   	ta1 = 0x3FF;		// initial value - max value of ADC (0x3FF)
   	trgsr = 0x02;	// Timer A0 as event trigger

	/* The recommended procedure for writing an Interrupt Priority Level is shown
  	below (see M16C datasheets under 'Interrupts' for details). */

   	/*DISABLE_IRQ		// disable irqs before setting irq registers - macro defined in skp_bsp.h
   	ta1ic = 3;		// Set the timer A1's IPL (interrupt priority level) to 3
   	ENABLE_IRQ		// enable interrupts macro defined in skp_bsp.h

   	/* Start timers */
   	/*ta1s = 1;		// Start Timer A1
   	ta0s = 1;		// Start timer A0
	*/
	
	
	//detect line
	/*if (LED0 == LED_ON && LED2 == LED_ON && swap <= LIMIT)
		{
		if (direction_change == TRUE){
			direction_change = FALSE;
			if (direction == FORWARD){
				r_forward(ON);
				l_forward(ON);
			}
			
			if (direction == BACKWARD){
				r_reverse(ON);
				l_reverse(ON);
			}
		}
		if (line_detect == TRUE){
			LED1 = LED_ON;
			motor_switch = FALSE;
		}
		else
			LED1 = LED_OFF;
		if (line_detect == TRUE && (delay_timer <= OFF || delay_timer > ONE_SEC)){
				delay_timer = ONE_SEC;
				
				if (motor_switch == FALSE){
					motor_switch = TRUE;
					direction_change = TRUE;
					direction ^= BACKWARD;
					swap +=DECREMENT;
				}
					
		}
		}
		else{
			r_off();
			l_off();
		}
		if (LED0 == LED_OFF && LED2 == LED_OFF){
			swap = OFF;
		}
		*/
	/*
			BNSPrintf(LCD,"\tAD2:%04u \ntrs:%04u",ad2,threshold);
		if (LED0 == LED_ON && LED2 == LED_OFF){
			delay_timer = 0;
			calibrate();
		}
		*/
	
	//timer B0 interrupt	
		/*  	if (ad2 >= threshold)
		line_detect = TRUE;
	else 
		line_detect = FALSE;
	delay_timer += DECREMENT;*/
	
	/*HW 8
				u2tb = 0x004E;
			wait(2);
			u2tb = 0x0043;
			wait(2);
			u2tb = 0x0053;
			wait(2);
			u2tb = 0x0055;
			wait(2);
			u2tb = 0x0020;
			wait(2);
			u2tb = 0x0023;
		 	wait(2);
			u2tb = 0x0031;
			wait(2);
			for (i=0;i<=r_index;i++){
				p_buffer[p_index] = r_array[i];
				p_index++;
			}
			p_buffer[7] = 0;
			r_index = 0;
			p_index = 0;
			DisplayString(LCD_LINE1, p_buffer);
			LED0 = LED_OFF;
			r_array[0]=0;
			r_array[1]=0;
			r_array[2]=0;
			r_array[3]=0;
			r_array[4]=0;
			r_array[5]=0;
			r_array[6]=0;
			r_array[7]=0;
			p_buffer[0]=0;
			p_buffer[1]=0;
			p_buffer[2]=0;
			p_buffer[3]=0;
			p_buffer[4]=0;
			p_buffer[5]=0;
			p_buffer[6]=0;
			p_buffer[7]=0;
			*/