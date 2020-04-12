/********************************************************************/
#ifndef SYS_ADC_H
#define SYS_ADC_H
#endif
/*****************************************************************/
#define READ_ADC_FLAG() (GET_BIT(PIR1, 6))
#define CLEAR_ADC_FLAG() (CLEAR_BIT(PIR1, 6))
#define DISABLE_ADC_INTERRUPT() (CLEAR_BIT(PIE1, 6))
/*****************************************************************/
#define XTAL 4
/*****************************************************************/
           
typedef enum{ Ch0 = 0, Ch1, Ch2, Ch3, Ch4, Ch5, Ch6, Ch7, Ch8, Ch9, Ch10, Ch11, Ch12, AllDigital}ADCChannel_t;
void ConfigureADCPort(ADCChannel_t Channel);                   /* Select No of Channels are analog what remained by default are Digitals */
void StartADC(const ADCChannel_t Channel);                     /* Select Which Channel You Will Read From Your Data */
uint16_t ReadADCBuffer(void);                                  /* Read Digital Value Of ADC */
void DefineADCPeriority(const Value_t Periority);              /* Determine ADC Periority High OR Low */

/*****************************************************************************
 Approximate your Clock Frequency to one of these values
           Actual Clock                          Approximated Clock(XTAL)
            <= 2.86 MHZ    ================         2 MHZ
            <= 5.71 MHZ    ================         4 MHZ
            <= 11.43 MHZ   ================         8 MHZ
            <= 22.86 MHZ   ================         16 MHZ
            <= 40 MHZ      ================         32 MHZ OR 64 MHZ

  *****************************************************************************/