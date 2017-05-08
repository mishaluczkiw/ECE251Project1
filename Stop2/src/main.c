//-----------------------------------------------------------------------------
// main.c
//-----------------------------------------------------------------------------
// Copyright 2015 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Program Description:
//
// Use scope to observe DAC outputs on P3.0 and P3.1.
// Move joystick left/right to change functions.
// Move joystick up/down to change frequency.
//
// Resources:
//   SYSCLK - 24.5 MHz HFOSC0 / 1
//   DAC0
//   DAC1
//   DAC2
//   DAC3
//   ADC0   - 10-bit, VREF = VDD (3.3 V)
//   SPI0   - 1 MHz
//   Timer2 - 2 MHz (SPI CS delay)
//   Timer3 - 1 kHz (1 ms tick)
//   Timer4 - 150 kHz interrupt (DAC update trigger)
//   P0.2   - Push button (kill splash screen)
//   P0.3   - Push button (kill splash screen)
//   P0.6   - SPI SCK
//   P1.0   - SPI MOSI
//   P1.7   - ADC input / Joystick (analog voltage divider)
//   P2.6   - SPI CS (Active High)
//   P3.0   - DAC0 output
//   P3.1   - DAC1 output
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
// 5) The Function Generator demo should start.
//    Press any button, move joystick, or wait 4 sec to kill splash screen
//    Use scope to observe DAC output on P3.0 and P3.1.
//    Move the joystick left/right to change functions.
//    Move the joystick up/down to increase/decrease the frequency.
//
// Target:         EFM8BB3
// Tool chain:     Generic
//
// Release 0.1 (ST)
//    - Initial Revision
//    - 15 JUL 2015
//

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "bsp.h"
#include "InitDevice.h"
#include "disp.h"
#include "function_generator.h"

SI_SBIT(LEDG, SFR_P1, 4);
SI_SBIT(LEDB, SFR_P1, 5);

//---------------------------------------------------------------------------
// main() Routine
// --------------------------------------------------------------------------

volatile double c=567.89;
volatile uint16_t tim;

int main(void)
{
  enter_DefaultMode_from_RESET();

  // Enable all interrupts
  IE_EA = 1;

  //LEDR = 0;
  //DISP_Init();
  //DISP_ClearAll();
 // drawSplash();

  TMR4RL = 65128;
  tim  = 0;

  while(1){
	  //FunctionGenerator_main(c);
	  //IE_EA = 1;
	  //LED0 = 1;
	  WDTCN = 0xA5;
	  //LED0 = 0;
  }


}

SI_INTERRUPT (TIMER4_ISR, TIMER4_IRQn)
{
  //TMR4CN0 &= ~TMR4CN0_TF4H__BMASK;
	TMR4CN0_TF4H = 0;
  //c=c+0.0000001;

	tim+=100;

	if (tim > 32768) {
  //switch(tim)
  //{
  //case 0:
	  //LEDG = 1;
	  LEDB = 0;
//	  break;
 // case 1:
//	  LED0=0;
//	  break;
 } else {
	 //LEDG = 0;
	 LEDB = 1;
 }

  //if(tim>=1){
//	  tim=0;
 // }
  //else{
//	  tim++;
 // }

}



