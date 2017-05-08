
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

//SI_SBIT(LED0, SFR_P1, 4);                  // P1.4 LED0
//SI_SBIT(LED1, SFR_P1, 5);                  // P1.5 LED1
//SI_SBIT(LED2, SFR_P1, 6);

volatile uint8_t outb[5][6];



volatile int C=-1;

extern void choose(int B);
void square(void);
bool pressed=false;
//int C=2;
//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{   enter_DefaultMode_from_RESET();
outb[0][0]=0; outb[0][1]=1; outb[0][2]=1; outb[0][3]=1; outb[0][4]=1; outb[0][5]=1;
outb[1][0]=0; outb[1][1]=0; outb[1][2]=0; outb[1][3]=0; outb[1][4]=0; outb[1][5]=0;
outb[2][0]=1; outb[2][1]=0; outb[2][2]=0; outb[2][3]=0; outb[2][4]=0; outb[2][5]=1;
outb[3][0]=0; outb[3][1]=1; outb[3][2]=0; outb[3][3]=0; outb[3][4]=0; outb[3][5]=1;
outb[4][0]=0; outb[4][1]=0; outb[4][2]=1; outb[4][3]=0; outb[4][4]=0; outb[4][5]=1;

   DISP_EN = DISP_BC_DRIVEN; // Display not driven by EFM8
   IE_EA = 0;
   //out();
   while(1){


   	   DISP_EN = DISP_BC_DRIVEN;           // EFM8 does not drive display
   	   while(1){
   		   if ((BSP_PB0 == BSP_PB_PRESSED)==false && (BSP_PB1 == BSP_PB_PRESSED)==false ){
   			   pressed=false;
   		   }

   		  if (BSP_PB0 == BSP_PB_PRESSED && !pressed ){
   			 	pressed=true;
   				C++;
   				if(C>4){
   					C=0;
   				}
   		   break;
   		   }
   		   if (BSP_PB1 == BSP_PB_PRESSED && !pressed ){
   			   pressed=true;
   			   C--;
   			   if(C<0){
   				   C=4;
   			   }
   			   break;
   		   }
   	   }


   	   square();
   	  /* switch(C){
   	   	   case 0:
   	   		   outb[0]=0; outb[1]=1; outb[2]=0; outb[3]=1; outb[4]=0; outb[5]=1; outb[6]=0;
   	   		   square();
   	   		   break;
   	   	   case 1:
   	   		   outb[0]=1; outb[1]=1; outb[2]=1; outb[3]=0; outb[4]=0; outb[5]=0; outb[6]=0;
   	   		   square();
   	   		   break;
   	   	   case 2:
   	   	   	    outb[0]=0; outb[1]=0; outb[2]=0; outb[3]=0; outb[4]=1; outb[5]=1; outb[6]=1;
   	   	   	    square();
   	   	   	    break;
   	   	   case 3:
   	   	   	    outb[0]=1; outb[1]=0; outb[2]=1; outb[3]=0; outb[4]=1; outb[5]=0; outb[6]=1;
   	   	   	    square();
   	   	   	   	 break;
   	   	   case 4:
   	     	    outb[0]=1; outb[1]=1; outb[2]=1; outb[3]=1; outb[4]=1; outb[5]=1; outb[6]=1;
   	   	   	    square();
   	   	   	    break;
   	   }
   	   */
   	   //square();
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


//
int CLKCOUNT = 0;
//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------
SI_SBIT(CLK, SFR_P1, 1);
SI_SBIT(BIT0, SFR_P1, 2);                  // P1.4 LED0
SI_SBIT(BIT1, SFR_P1, 3);
SI_SBIT(BIT2, SFR_P1, 4);                  // P1.4 LED0
SI_SBIT(BIT3, SFR_P1, 5);                  // P1.5 LED1
SI_SBIT(BIT4, SFR_P1, 6);					// P1.6 LED2
SI_SBIT(BIT5, SFR_P1, 7);

//-----------------------------------------------------------------------------
// TIMER2_ISR
//-----------------------------------------------------------------------------
//
// TIMER2 ISR Content goes here. Remember to clear flag bits:
// TMR2CN::TF2H (Timer # High Byte Overflow Flag)
// TMR2CN::TF2L (Timer # Low Byte Overflow Flag)
//
// This routine changes the state of the LED whenever Timer2 overflows.
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER2_ISR, TIMER2_IRQn)
{
	TMR2CN0_TF2H = 0;    // Clear Timer2 interrupt flag
	//int N=0;

	switch (CLKCOUNT)
	{
		case 0:

			BIT0=outb[C][0];
			BIT1=outb[C][1];
			BIT2=outb[C][2];
			BIT3=outb[C][3];
			BIT4=outb[C][4];
			BIT5=outb[C][5];
			/*for(n=0; n<=1000; n++){
				Nop();
			}
			CLK=1; */
		   break;
		case 1:
		   CLK=1;
		   break;
		case 2:
		   CLK=0;
		   IE_EA=0;
		   break;

	}
	if (CLKCOUNT <= 1) CLKCOUNT++;
	else CLKCOUNT = 0;
}
