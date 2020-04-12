/*************************************/
#ifndef SYS_DATATYPES_H
#include "Sys_DataTypes.h"
#endif
/**********************************************************/
#ifndef SYS_GIO_H
#include "Sys_GIO.h"
#endif
/********************************************************/
#ifndef SYS_ADC_H
#include "Sys_ADC.h"
#endif
/*********************************************************/
#ifndef BIT_MANIPULATION_H
#include "Bit_Manipulation.h"
#endif
/******************************************************/
void void ConfigureADCPort(ADCChannel_t Channel){
     SetPinDirection(A, Pin0, Input);            /************** *********** ******/
     SetPinDirection(A, Pin1, Input);            /*********************************/
     SetPinDirection(A, Pin2, Input);            /*********************************/
     SetPinDirection(A, Pin3, Input);            /*********************************/
     SetPinDirection(A, Pin5, Input);           /**********************************/
    
     SetPinDirection(B, Pin0, Input);           /*********************************/
     SetPinDirection(B, Pin1, Input);           /* Channels From 0 to 12 are Input*/
     SetPinDirection(B, Pin2, Input);           /*                                */
     SetPinDirection(B, Pin3, Input);           /**********************************/

     SetPinDirection(E, Pin0, Input);           /**********************************/
     SetPinDirection(E, Pin1, Input);           /**********************************/
     SetPinDirection(E, Pin2, Input);          /***********************************/
     
     if(Ch12 == Channel){ ADCON1 = 0X00; }                    /* Channels from 12 To 0 are Analog */
     else if(Ch11 == Channel){ ADCON1 = 0X03; }               /* Channels from 11 To 0 are Analog */
     else if(Ch10 == Channel){ ADCON1 = 0X04; }               /* Channels from 10 To 0 are Analog */
     else if(Ch9 == Channel){ ADCON1 = 0X05; }                /* Channels from 9 To 0 are Analog */
     else if(Ch8 == Channel){ ADCON1 = 0X06; }                /* Channels from 8 To 0 are Analog */
     else if(Ch7 == Channel){ ADCON1 = 0X07; }                /* Channels from 7 To 0 are Analog */
     else if(Ch6 == Channel){ ADCON1 = 0X08; }                /* Channels from 6 To 0 are Analog */
     else if(Ch5 == Channel){ ADCON1 = 0X09; }                /* Channels from 5 To 0 are Analog */
     else if(Ch4 == Channel){ ADCON1 = 0X0A; }                /* Channels from 4 To 0 are Analog */
     else if(Ch3 == Channel){ ADCON1 = 0X0B; }                /* Channels from 3 To 0 are Analog */
     else if(Ch2 == Channel){ ADCON1 = 0X0C; }                /* Channels from 2 To 0 are Analog */
     else if(Ch1 == Channel){ ADCON1 = 0X0D; }                /* Channels from 1 To 0 are Analog */
     else if(Ch0 == Channel){ ADCON1 = 0X0E; }                /* Channels from 0 To 0 are Analog */
     else{ ADCON1 = 0X0F; }                                   /* Channels from 12 To 0 are Digital */
     
     ADCON2 = 0X00;                                           /* Initalization */
     if(2 == XTAL){ ADCON2 = 0X00; }                          /* TAD = 2 TOSC */
     else if(4 == XTAL){ ADCON2 = 0X04; }                     /* TAD = 4 TOSC */
     else if(8 == XTAL){ ADCON2 = 0X01; }                     /* TAD = 8 TOSC */
     else if(16 == XTAL){ ADCON2 = 0X05; }                    /* TAD = 16 TOSC */
     else if(32 == XTAL){ ADCON2 = 0X02; }                    /* TAD = 32 TOSC */
     else if(64 == XTAL){ ADCON2 = 0X06; }                    /* TAD = 64 TOSC */
     ADCON2 |= 0XA8;                                          /* Sampling Time = 12 Tad, As min Sampling Time = 2,4 us,
                                                                 TAD = 1us, min TAD = 0.7us, Conversion Time of ADC = 11*TAD */
     
     CLEAR_BIT(PIR1, 6);                                      /* Clear ADC Flag */
     CLEAR_BIT(PIE1, 6);                                      /* Disable ADC Interrupt */
     CLEAR_BIT(IPR1, 6);                                      /* Low Periority */
     
     CLEAR_BIT(ADCON0, 0);                                   /* Disable ADC */
     CLEAR_BIT(ADCON0, 1);                                   /* ADC Idle */
     
}
void StartADC(const ADCChannel_t Channel){
     CLEAR_BIT(ADCON0, 0);                                    /* Disable ADC */
     CLEAR_BIT(ADCON0, 1);                                    /* ADC Idle */
     
     delay_us(30);                                            /* time delay between two reading as min = 2 TAD */
     ADCON0 = (Channel << 2);                                 /* Select required Channel */
     
     ADRESH = 0X00;                                           /* clear adc buffer */
     ADRESL = 0X00;                                           /* clear buffer */
     
     SET_BIT(ADCON0, 0);                                     /* Enable ADC */
     delay_us(30);                                           /* Sampling Time */
     SET_BIT(ADCON0, 1);                                     /* ADC Active */
     
}

uint16_t ReadADCBuffer(void){
         return ((((uint16_t)ADRESH) << 8) | ADRESL);
}
void DefineADCPeriority(const Value_t Periority){
     SET_BIT(PIE1, 6);                                       /* Enable ADC Interrupt */
     if(High == Periority){ SET_BIT(IPR1, 6); }
     else{ CLEAR_BIT(IPR1, 6); }
}