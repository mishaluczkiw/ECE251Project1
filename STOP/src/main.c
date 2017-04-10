
//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>
#include <InitDevice.h>
#include "bsp.h"
#include "bsp_config.h"
#include "disp.h"
#include "render.h"
#include <stdio.h>
//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (DISP_EN, SFR_P3, 4);          // Display Enable
#define DISP_BC_DRIVEN   0             // 0 = Board Controller drives display
#define DISP_EFM8_DRIVEN 1             // 1 = EFM8 drives display
#define RETARGET_SPRINTF        sprintf

SI_SEGMENT_VARIABLE(Line[DISP_BUF_SIZE], uint8_t, RENDER_LINE_SEG);

//SI_SBIT(LED0, SFR_P1, 4);                  // P1.4 LED0
//SI_SBIT(LED1, SFR_P1, 5);                  // P1.5 LED1
//SI_SBIT(LED2, SFR_P1, 6);

volatile double total[1]=1000;
volatile int lap[1];
double laptimes [5];

static void drawScreenFrequency(void);
static void drawScreenText(SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG), uint8_t rowNum);


volatile int C=-1;

bool pressed=false;
//int C=2;
//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{   enter_DefaultMode_from_RESET();
   DISP_Init();
   IE_EA = 0;

   while(1){


	   while(1){
	     		   if ((BSP_PB0 == BSP_PB_PRESSED)==false  ){
	     			   pressed=false;
	     		   }

	     		  if (BSP_PB0 == BSP_PB_PRESSED && !pressed ){
	     			 	pressed=true;
	     			 	break;
	     		   }

	     	   }
	   pressed=false;
	   IE_EA = 1;
   	   while(1){
   		 /*  if ((BSP_PB0 == BSP_PB_PRESSED)==false && (BSP_PB1 == BSP_PB_PRESSED)==false ){
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
   		   }  */
   		drawScreenFrequency();
   		   }




   	}

}


static void drawScreenText(SI_VARIABLE_SEGMENT_POINTER(str, char, RENDER_STR_SEG), uint8_t rowNum)
{
  uint8_t i;

  for (i = 0; i < FONT_HEIGHT; i++)
  {
    RENDER_ClrLine(Line);
    RENDER_StrLine(Line, 4, i, str);
    DISP_WriteLine(rowNum + i, Line);
  }
}

static void drawScreenFrequency(void)
{
  char freqStr[22];

  // display frequency on screen
  RETARGET_SPRINTF(freqStr, "  Current Time = %d sec", total[0]);

  drawScreenText(freqStr, 20);
}

//
int CLKCOUNT = 0;
//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------

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
	total[0]=total[0]+1;

}
