/******************************************************************************/
#ifndef SYS_DATATYPES_H
#include "Sys_DataTypes.h"
#endif
/******************************************************************************/
#ifndef SYS_GIO_H
#include "Sys_GIO.h"
#endif
/******************************************************************************/
#ifndef BIT_MANIPULATION_H
#include "Bit_Manipulation.h"
#endif
/******************************************************************************/
#ifndef SYS_UART_H
#include "Sys_Uart.h"
#endif
/*******************************************************************************/
#define UART_MESSAGE_SEND() (TXSTA & (1 << 1))
/********************************************************/
void ConfigureUartTx(void){
    TXSTA = 0X26;
    SET_BIT(RCSTA, 7);
    BAUDCON = 0X00;
    SPBRG = MAPPED_DATA_RATE;
    SetPinDirection(C, Pin6, Output);
}
void ConfigureUartRx(void){
    RCSTA = 0X90;
    BAUDCON = 0X00;
    SPBRG = MAPPED_DATA_RATE;
    SetPinDirection(C, Pin7, Input);
    SET_BIT(PIE1, 5);
    SET_BIT(IPR1, 5);                           /* RX is High Periority */
}
void UartSendMessage(const uint8_t* Message){
    while(*Message != '\0'){
        TXREG = *Message++;
        while(!UART_MESSAGE_SEND());
    }
}