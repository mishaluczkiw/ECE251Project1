
#include "bsp.h"
#include "pwr.h"

#include "draw.h"
#include "tick.h"
#include "InitDevice.h"
#include <stdio.h>


//-----------------------------------------------------------------------------
// Local Definitions
//-----------------------------------------------------------------------------



// Port Match ISR - Triggered on leading edge of UI_BTN_SELECT.
/*SI_INTERRUPT (PMATCH_ISR, PMATCH_IRQn)
{
  // Turn on LED whenever UI_BTN_SELECT is pressed
  BSP_LED_G = BSP_LED_ON;
}*/


SI_SBIT(LEDG, SFR_P1, 4);
volatile double time=0;
volatile double lap=0;
volatile double laps[5];

SI_INTERRUPT_USING (TIMER4_ISR, TIMER4_IRQn, 1)
{
	 TMR4CN0_TF4H = 0;		
	time+=0.0307692;
	lap+=0.0307692;

}
volatile int index = 0;
volatile bool pressed=false;
SI_INTERRUPT(PMATCH_ISR, PMATCH_IRQn)
{
  uint8_t SFRPAGE_save = SFRPAGE;

  	  pressed=true;

  SFRPAGE = PG2_PAGE;
                    
  SFRPAGE = SFRPAGE_save;
}

//-----------------------------------------------------------------------------
// Example main()
//-----------------------------------------------------------------------------

volatile char ar[22];

void main(void)
{


//	uint8_t modeSelected = 1;
	enter_DefaultMode_from_RESET();
	DISP_Init();
	IE_EA = 1;	
	 while(true){
		 sprintf(ar,"TOT time %.2f sec",time);
		 DrawScreenText(ar, 10);
		if(pressed==true){
			laps[index++]=lap;
			if(index>4){
					 index=0;
				}
			lap=0;
			sprintf(ar,"LAP 1 %.2f sec",laps[0]);
			DrawScreenText(ar, 25);
			sprintf(ar,"LAP 2 %.2f sec",laps[1]);
			DrawScreenText(ar, 40);
			sprintf(ar,"LAP 3 %.2f sec",laps[2]);
			DrawScreenText(ar, 55);
			sprintf(ar,"LAP 4 %.2f sec",laps[3]);
			DrawScreenText(ar, 70);
			sprintf(ar,"LAP 5 %.2f sec",laps[4]);
			DrawScreenText(ar, 85);
			pressed=false;
		}

	 }
}



