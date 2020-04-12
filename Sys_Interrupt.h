/******************************************************************************/
#ifndef SYS_INTERRUPT_H
#define SYS_INTERRUPT_H
#endif
/******************************************************************************/
#ifndef SYS_ADC_H
#include "Sys_ADC.h"
#endif
/*****************************************************************/
#define ENABLE_GLOBAL_INTERRUPT() ( SET_BIT(INTCON, 7) )
#define DISABLE_GLOBAL_INTERRUPT() ( CLEAR_BIT(INTCON, 7) )
/******************************************************************************/
#define READ_EXINT0_FLAG() ( GET_BIT(INTCON, 1) )
#define CLEAR_EXINT0_FLAG() ( CLEAR_BIT(INTCON, 1) )
#define DISABLE_EXINT0() ( CLEAR_BIT(INTCON, 4) )

#define READ_EXINT1_FLAG() ( GET_BIT(INTCON3, 0) )
#define CLEAR_EXINT1_FLAG() ( CLEAR_BIT(INTCON3, 0) )
#define DISABLE_EXINT1() ( CLEAR_BIT(INTCON3, 3) )

#define READ_EXINT2_FLAG() ( GET_BIT(INTCON3, 1) )
#define CLEAR_EXINT2_FLAG() ( CLEAR_BIT(INTCON3, 1) )
#define DISABLE_EXINT2() ( CLEAR_BIT(INTCON3, 4) )

#define READ_EXRB_FLAG() ( GET_BIT(INTCON, 0) )
#define CLEAR_EXRB_FLAG() ( CLEAR_BIT(INTCON, 0) )
#define DISABLE_EXRB() ( CLEAR_BIT(INTCON, 3) )
#define ENABLE_EXRB() ( SET_BIT(INTCON, 3) )
/******************************************************************************/
typedef enum{ ExInt0 = 0, ExInt1, ExInt2}ExInt_t;
extern void ConfigureADCPort(ADCChannel_t Channel);      /* Select No of Channels are analog what remained by default are Digitals */
void ConfigureInterrupt(void);
void ExternalInterrupt(ExInt_t ExIntSrc, Value_t Periority, ClockPolarity_t ClkPolarity);  /* EXINT0 always high periority */
void LatchNewValueOnPortBExInterrupt(Value_t Periority);
                                     
/*                     INT0 ===== AN12
                       INT1 ===== AN10
                       INT2 ===== AN8
                       RB4 ====== AN11
   
*/