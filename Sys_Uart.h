/******************************************************************************/
#ifndef SYS_UART_H
#define SYS_UART_H
#endif
/******************************************************************************/
#define READ_UARTRX_FLAG ( GIT_BIT(PIR1, 5) )
#define READ_UARTRX_BUFFER ( RCREG )
/******************************************************************************/
#define MAPPED_DATA_RATE 25
/******************************************************************************/

void ConfigureUartTx(void);
void ConfigureUartRx(void);                       /* RX is High Periority */
void UartSendMessage(const uint8_t* Message);

/* RX flag Cleared by HW */
   /***************************************************************************
   Baude_Rate(KHZ)     FOSC = 1 MHZ       Mapped_Data_Rate
          0.3                                 207
          1.2                                 51
          2.4                                 25


   Baude_Rate(KHZ)     FOSC = 2 MHZ       Mapped_Data_Rate
          1.2                                 103
          2.4                                 51
          9.6                                 12

   Baude_Rate(KHZ)     FOSC = 4 MHZ       Mapped_Data_Rate
          1.2                                 207
          2.4                                 103
          9.6                                 25
          19.2                                12
          57.6                                3
          115.2                               1

   Baude_Rate(KHZ)     FOSC = 8 MHZ       Mapped_Data_Rate
          2.4                                 207
          9.6                                 51
          19.2                                25
          57.6                                8

  Baude_Rate(KHZ)     FOSC = 10 MHZ       Mapped_Data_Rate
          2.4                                 255
          9.6                                 64
          19.2                                31
          57.6                                10
          115.2                               4

 Baude_Rate(KHZ)     FOSC = 20 MHZ       Mapped_Data_Rate
          9.6                                 129
          19.2                                64
          57.6                                21
          115.2                               10

 Baude_Rate(KHZ)     FOSC = 1 MHZ       Mapped_Data_Rate
          9.6                                 255
          19.2                                129
          57.6                                42
          115.2                               21

  ************************************************************************************/