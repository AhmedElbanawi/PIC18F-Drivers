/******************************************************/
#ifndef BIT_MANIPULATION_H
#include "Bit_Manipulation.h"
#endif
/******************************************************/
#ifndef SYS_DATATYPES_H
#include "Sys_DataTypes.h"
#endif
/******************************************************************************/
#ifndef SYS_INTERRUPT_H
#include "Sys_Interrupt.h"
#endif
/******************************************************************************/
#ifndef SYS_GIO_H
#include "Sys_GIO.h"
#endif
/******************************************************************************/
static uint8_t IsNotInited = 1;
void ConfigureInterrupt(void){
     CLEAR_BIT(INTCON, 7);                              /* Disable Global Interrupt */
     SET_BIT(INTCON, 6);                                /* Enable Peripherals */
     SET_BIT(RCON, 7);                                  /* Enable Periority */
}
void ExternalInterrupt(ExInt_t ExIntSrc, Value_t Periority, ClockPolarity_t ClkPolarity){
     if(ExInt0 == ExIntSrc){
                SET_BIT(INTCON, 4);                     /* INT0 IE And Always High Periority by HW */
                if(FallingEdge == ClkPolarity){ CLEAR_BIT(INTCON2, 6); }
                else{ SET_BIT(INTCON2, 6); }
     }
    else if(ExInt1 == ExIntSrc){
                SET_BIT(INTCON3, 3);                   /* INT1 IE*/
                if(High == Periority){ SET_BIT(INTCON3, 6); }
                else{ CLEAR_BIT(INTCON3, 6); }
                if(FallingEdge == ClkPolarity){ CLEAR_BIT(INTCON2, 5); }
                else{ SET_BIT(INTCON2, 5); }
     }
     else{
                SET_BIT(INTCON3, 4);                   /* INT2 IE*/
                if(High == Periority){ SET_BIT(INTCON3, 7); }
                else{ CLEAR_BIT(INTCON3, 7); }
                if(FallingEdge == ClkPolarity){ CLEAR_BIT(INTCON2, 4); }
                else{ SET_BIT(INTCON2, 4); }
     }
}
void LatchNewValueOnPortBExInterrupt(Value_t Periority){
     CLEAR_BIT(INTCON, 3);                           /* Disable RB External Interrupt */
     
     if(IsNotInited){
             SetPinDirection(B, Pin4, Input);
             SetPinDirection(B, Pin5, Input);
             SetPinDirection(B, Pin6, Input);
             SetPinDirection(B, Pin7, Input);
             IsNotInited = 0;
     }

     SetPinValue(B, Pin4, ReadPinValue(B, Pin4));
     SetPinValue(B, Pin5, ReadPinValue(B, Pin5));
     SetPinValue(B, Pin6, ReadPinValue(B, Pin6));
     SetPinValue(B, Pin7, ReadPinValue(B, Pin7));
     
     if(High == Periority){ SET_BIT(INTCON2, 0); }
     else{ CLEAR_BIT(INTCON2, 0); }
     
     CLEAR_BIT(INTCON, 0);                         /* Clear RB Falg */
     SET_BIT(INTCON, 3);                           /* Enable RB External Interrupt */
     
}

