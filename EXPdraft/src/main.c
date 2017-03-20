
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>
#include "bsp.h"// SFR declarations
#include "bsp_config.h"


//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
//
// Note: the software watchdog timer is not disabled by default in this
// example, so a long-running program will reset periodically unless
// the timer is disabled or your program periodically writes to it.
//
// Review the "Watchdog Timer" section under the part family's datasheet
// for details. To find the datasheet, select your part in the
// Simplicity Launcher and click on "Data Sheet".
//
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>
#include "InitDevice.h"
#include "bsp.h"


//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (DISP_EN, SFR_P3, 4);   // Display Enable
SI_SBIT(LED0, SFR_P1, 4);                  // P1.4 LED0
SI_SBIT(LED1, SFR_P1, 5);                  // P1.5 LED1
SI_SBIT(LED2, SFR_P1, 6);                  // P1.6 LED2
#define DISP_BC_DRIVEN   0             // 0 = Board Controller drives display
#define DISP_EFM8_DRIVEN 1             // 1 = EFM8 drives display

//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
int C=0;
bool pressed=false;
void main (void)
{
	/*if (BSP_PB0 == BSP_PB_PRESSED){
		C++;
	}
	if(C>1){
		C=0;
	} */
	while(1){
		LED0=1;
		LED1=0;
		LED2=0;
		enter_DefaultMode_from_RESET(C);

	   DISP_EN = DISP_BC_DRIVEN;           // EFM8 does not drive display
	   while(1){
		   if ((BSP_PB0 == BSP_PB_PRESSED)==false && (BSP_PB1 == BSP_PB_PRESSED)==false ){
			   pressed=false;
		   }


		   if (BSP_PB0 == BSP_PB_PRESSED && !pressed ){
			 	pressed=true;
				C++;
				LED0=0;
				LED1=0;
				LED2=0;
				if(C>5){
					C=0;
				}
		   break;
		   }
		   if (BSP_PB1 == BSP_PB_PRESSED && !pressed ){
			   pressed=true;
			   C--;
			   LED0=0;
			   LED1=0;
			   LED2=0;
			   if(C<0){
				   C=5;
			   }
			   break;

		   }

	   }

	}
}
