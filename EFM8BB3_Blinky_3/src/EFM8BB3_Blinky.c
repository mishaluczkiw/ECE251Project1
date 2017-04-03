//-----------------------------------------------------------------------------
// EFM8BB3_Blinky.c
//-----------------------------------------------------------------------------
// Copyright 2014 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// This program flashes the red/green/blue LED on the EFM8BB3 STK board about
// five times a second using the interrupt handler for Timer2.
//
// Resources:
//   SYSCLK - 24.5 MHz HFOSC0 / 8
//   Timer2 - 5 Hz interrupt
//   P1.4   - LED green
//   P1.5   - LED blue
//   P1.6   - LED red
//   P3.4   - Display enable
//
//-----------------------------------------------------------------------------
// How To Test: EFM8BB3 STK
//-----------------------------------------------------------------------------
// 1) Place the switch in "AEM" mode.
// 2) Connect the EFM8BB3 STK board to a PC using a mini USB cable.
// 3) Compile and download code to the EFM8BB3 STK board.
//    In Simplicity Studio IDE, select Run -> Debug from the menu bar,
//    click the Debug button in the quick menu, or press F11.
// 4) Run the code.
//    In Simplicity Studio IDE, select Run -> Resume from the menu bar,
//    click the Resume button in the quick menu, or press F8.
// 5) The RGB LED should alternate colors at approximately 5 Hz.
//
// Target:         EFM8BB3
// Tool chain:     Generic
//
// Release 0.1 (ST)
//    - Initial Revision
//    - 20 MAY 2015
//

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>
#include <InitDevice.h>
#include "bsp.h"
#include "bsp_config.h"

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (DISP_EN, SFR_P3, 4);          // Display Enable
#define DISP_BC_DRIVEN   0             // 0 = Board Controller drives display
#define DISP_EFM8_DRIVEN 1             // 1 = EFM8 drives display

SI_SBIT(LED0, SFR_P1, 4);                  // P1.4 LED0
SI_SBIT(LED1, SFR_P1, 5);                  // P1.5 LED1
SI_SBIT(LED2, SFR_P1, 6);


extern void choose(int B);
void square(void);
void out(void);
bool pressed=false;
int C=5;
//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{
   enter_DefaultMode_from_RESET();

   DISP_EN = DISP_BC_DRIVEN; // Display not driven by EFM8
   IE_EA = 0;
   //out();
   while(1){
   	//	LED0=1;
   	//	LED1=0;
   	//	LED2=0;
   		choose(C);

   	   DISP_EN = DISP_BC_DRIVEN;           // EFM8 does not drive display
   	   while(1){
   		   if ((BSP_PB0 == BSP_PB_PRESSED)==false && (BSP_PB1 == BSP_PB_PRESSED)==false ){
   			   pressed=false;
   		   }


   		   if (BSP_PB0 == BSP_PB_PRESSED && !pressed ){
   			 	pressed=true;
   				C++;
   		//		LED0=0;
   		//		LED1=0;
   		//		LED2=0;
   				if(C>5){
   					C=0;
   				}
   		   break;
   		   }
   		   if (BSP_PB1 == BSP_PB_PRESSED && !pressed ){
   			   pressed=true;
   			   C--;
   		//	   LED0=0;
   		//	   LED1=0;
   		//	   LED2=0;
   			   if(C<0){
   				   C=5;
   			   }
   			   break;

   		   }

   	   }


   	   square();
   	   square();


   	}


}

extern void choose(int B){
	switch(B){
	case 0:
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
		break;
	case 1:
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_2;
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_2;
		break;
	case 2:
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_4;
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_4;
		break;
	case 3:
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_8;
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_8;
		break;
	case 4:
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_16;
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_16;
		break;
	case 5:
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_32;
		CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_32;
		break;
	}

	while (CLKSEL & CLKSEL_DIVRDY__BMASK == CLKSEL_DIVRDY__NOT_READY)
		;
}


void square(void){
	IE_EA=1;
	while(1){
		if(IE_EA==0){
			break;
		}
	}
}

void out(void){
	int LEDCOUNT=0;
	CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_64;
	/*while(1){
		if (LEDCOUNT<40){
			LED0=1;
		}
		else if(LEDCOUNT==80){
			LEDCOUNT=0;
		}
		else {
			LED0=0;
		}
		LEDCOUNT++;
	}
	*/

		switch (LEDCOUNT)
				{
					case 0:
					   LED0 = 1;
					   LED1 = 0;
					   LED2 = 0;
					   break;
					case 1:
					   LED0 = 1;
					   LED1 = 1;
					   LED2 = 0;
					   IE_EA=0;
					   break;
					case 2:
					   LED0 = 1;
					   LED1 = 0;
					   LED2 = 1;
					  break;
					case 3:
					   LED0 = 0;
					   LED1 = 1;
					   LED2 = 0;
					   break;
					case 4:
					   LED0 = 0;
					   LED1 = 1;
					   LED2 = 1;
					   break;
					case 5:
					   LED0 = 0;
					   LED1 = 0;
					   LED2 = 1;
					   break;
					case 6:
					   LED0 = 0;
					   LED1 = 1;
					   LED2 = 1;
					   break;
				}

				if (LEDCOUNT <= 5) LEDCOUNT++;
				else LEDCOUNT = 0;
	}



