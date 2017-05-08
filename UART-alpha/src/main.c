
#include "bsp.h"
#include "pwr.h"

#include "draw.h"
#include "tick.h"
#include "InitDevice.h"
#include <stdio.h>
#include <SI_EFM8BB3_Register_Enums.h>
#include "retargetserial.h"


//-----------------------------------------------------------------------------
// Local Definitions
//-----------------------------------------------------------------------------


SI_SBIT(LEDG, SFR_P1, 4);
SI_SBIT (BC_EN, SFR_P2, 2);            // Board Controller Enable
#define BC_DISCONNECTED 0              // 0 = Board Controller disconnected
                                       //     to EFM8 UART pins
#define BC_CONNECTED    1              // 1 = Board Controller connected
#define UART_BUFFERSIZE        32

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
volatile uint8_t UART_Buffer[UART_BUFFERSIZE];
volatile uint8_t UART_Buffer_Size = 0;
volatile uint8_t UART_Input_First = 0;
volatile uint8_t UART_Output_First = 0;
volatile uint8_t TX_Ready =1;
volatile uint8_t Byte = 0;

SI_INTERRUPT (UART0_ISR, UART0_IRQn)
{
	LEDG=1;
	   if (SCON0_RI == 1)
	   {
	      if( UART_Buffer_Size == 0)  {    // If new word is entered
	         UART_Input_First = 0;    }

	      SCON0_RI = 0;                          // Clear interrupt flag

	      Byte = SBUF0;                    // Read a character from UART

	      if (UART_Buffer_Size < UART_BUFFERSIZE)
	      {
	         UART_Buffer[UART_Input_First] = Byte; // Store in array

	         UART_Buffer_Size++;           // Update array's size

	         UART_Input_First++;           // Update counter
	      }
	   }
	   if (SCON0_TI == 1)                        // Check if transmit flag is set
	  	   {
	  	      SCON0_TI = 0;                          // Clear interrupt flag

	  	      if (UART_Buffer_Size != 1)       // If buffer not empty
	  	      {
	  	         // If a new word is being output
	  	         if ( UART_Buffer_Size == UART_Input_First ) {
	  	              UART_Output_First = 0;  }

	  	         // Store a character in the variable byte
	  	         Byte = UART_Buffer[UART_Output_First];

	  	         if ((Byte >= 0x61) && (Byte <= 0x7A)) { // If upper case letter
	  	            Byte -= 32; }

	  	         SBUF0 = Byte;                 // Transmit to Hyperterminal

	  	         UART_Output_First++;          // Update counter

	  	         UART_Buffer_Size--;           // Decrease array size

	  	      }
	  	      else
	  	      {
	  	         UART_Buffer_Size = 0;         // Set the array size to 0
	  	         TX_Ready = 1;                 // Indicate transmission complete
	  	      }
	  	   }
}

SI_INTERRUPT_USING (TIMER4_ISR, TIMER4_IRQn, 1)
{

	//TMR4CN0_TF4H = 0;


	    TMR4CN0_TF4H = 0;
		//TMR4CN0 &= ~TMR3CN0_TF3H__BMASK;

}
volatile int index = 0;
volatile bool pressed=false;
SI_INTERRUPT(PMATCH_ISR, PMATCH_IRQn)
{
  uint8_t SFRPAGE_save = SFRPAGE;
  	  pressed=true;


//  }
  //LEDG=0;
  SFRPAGE = PG2_PAGE;

  //EIE1 &= ~0x02;                     // Disable Port Match interrupts to
                                     // prevent multiple interrupts from
                                     // occurring while the button is
                                     // pressed
  SFRPAGE = SFRPAGE_save;
}

//-----------------------------------------------------------------------------
// Example main()
//-----------------------------------------------------------------------------

volatile char ar[15];

void main(void)
{


//	uint8_t modeSelected = 1;
	enter_DefaultMode_from_RESET();
	// Enable all interrupts
	DISP_Init();
	BC_EN = 0;               // Board controller connected to EFM8
	LEDG=0;
	IE_EA = 1;
	//UI_getPowerMode(0);
	// DrawScreenText(powerModeText[0], TEXT_ROW0_Y);

	// sprintf(ar,"LAP time %.2f sec",time);

	DrawScreenText("HELLO FRIEND", 10);

	while(true){
		sprintf(ar,"buffer size %d",UART_Buffer_Size);
		DrawScreenText(ar, 30);
		DrawScreenText(UART_Buffer, 70);
	 if((TX_Ready == 1) && (UART_Buffer_Size != 0) && ((Byte == '\r') || (Byte == '\n') || (Byte == '~')))
	      {
	         TX_Ready = 0;                 // Set the flag to zero
	         SCON0_TI = 1;                 // Set transmit flag to 1
	         DrawScreenText("ijij", 50);
	      }
	}


}



