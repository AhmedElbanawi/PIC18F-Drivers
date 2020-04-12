/*************************************/
#ifndef SYS_DATATYPES_H
#include "Sys_DataTypes.h"
#endif
/**********************************************************/
#ifndef SYS_GIO_H
#include "Sys_GIO.h"
#endif
/********************************************************/
#ifndef BIT_MANIPULATION_H
#include "Bit_Manipulation.h"
#endif
/********************************************************/
#define STILL 0
#define ENDED 1
/***************************************************************************/
#ifndef LCD_H
#include "LCD.h"
#endif
/*************************************************************************/
#ifndef MATH_H
#include "Math.h"
#endif
/******************************************************************/
static uint8_t Configuration_Process = STILL, Address_Counter;
void Lcd_Config(void){
     /* Inite MCU Pins Direction As Output For Lcd */
     SetPinDirection(E_PIN_ADDRESS,  E_PIN_NUMBER, Output);     // E
     SetPinDirection(RW_PIN_ADDRESS, RW_PIN_NUMBER, Output);   //  R/W
     SetPinDirection(RS_PIN_ADDRESS, RS_PIN_NUMBER, Output);   //  RS
     SetPinDirection(D4_PIN_ADDRESS, D4_PIN_NUMBER, Output);   //  D4
     SetPinDirection(D5_PIN_ADDRESS, D5_PIN_NUMBER, Output);   //  D5
     SetPinDirection(D6_PIN_ADDRESS, D6_PIN_NUMBER, Output);   //  D6
     SetPinDirection(D7_PIN_ADDRESS, D7_PIN_NUMBER, Output);   //  D7
     /* Inite MCU Pins vlaue as 0 for lcd */
     SetPinValue(E_PIN_ADDRESS,  E_PIN_NUMBER, Low);     // E
     SetPinValue(RW_PIN_ADDRESS, RW_PIN_NUMBER, Low);   //  R/W
     SetPinValue(RS_PIN_ADDRESS, RS_PIN_NUMBER, Low);   //  RS
     SetPinValue(D4_PIN_ADDRESS, D4_PIN_NUMBER, Low);   //  D4
     SetPinValue(D5_PIN_ADDRESS, D5_PIN_NUMBER, Low);   //  D5
     SetPinValue(D6_PIN_ADDRESS, D6_PIN_NUMBER, Low);   //  D6
     SetPinValue(D7_PIN_ADDRESS, D7_PIN_NUMBER, Low);   //  D7
     
     /* Lcd 4 Wires Interfacing */
     delay_ms(30); // Lcd Power Rises Delay
     /* Lcd Function Set */
     Lcd_Send_Command(0X20);
     Lcd_Send_Command(0X20);
     Lcd_Send_Command(0X80); // Lcd 2 Lines, 5 * 7 dot characters
     delay_ms(1);           // For Latching
     /* Display on/off Control */
     Lcd_Send_Command(0X00);
     Lcd_Send_Command(0XC0); // Display on / Crusor Off / Blinking off
     delay_ms(1); // For Latching
     /* Clear Dispaly */
     Lcd_Send_Command(0X00);
     Lcd_Send_Command(0X10);
     delay_ms(2); // For Latching
     Configuration_Process = ENDED;
}
void Lcd_Send_Command(const uint8_t Command){
     // Write operation
     SetPinValue(RW_PIN_ADDRESS, RW_PIN_NUMBER, Low);   //  R/W
     // Command Mode
     SetPinValue(RS_PIN_ADDRESS, RS_PIN_NUMBER, Low);   //  RS
     
     // SEND MSB
     SetPinValue(D4_PIN_ADDRESS, D4_PIN_NUMBER, GET_BIT(Command, 4));   //  D4
     SetPinValue(D5_PIN_ADDRESS, D5_PIN_NUMBER, GET_BIT(Command, 5));   //  D5
     SetPinValue(D6_PIN_ADDRESS, D6_PIN_NUMBER, GET_BIT(Command, 6));   //  D6
     SetPinValue(D7_PIN_ADDRESS, D7_PIN_NUMBER, GET_BIT(Command, 7));   //  D7
     
     /* Latch data */
     SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, High);   //  E
     delay_ms(1);
     SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, Low);   //  E
     
     if(Configuration_Process == ENDED){
         // SEND LSB
         SetPinValue(D4_PIN_ADDRESS, D4_PIN_NUMBER, GET_BIT(Command, 0));   //  D4
         SetPinValue(D5_PIN_ADDRESS, D5_PIN_NUMBER, GET_BIT(Command, 1));   //  D5
         SetPinValue(D6_PIN_ADDRESS, D6_PIN_NUMBER, GET_BIT(Command, 2));   //  D6
         SetPinValue(D7_PIN_ADDRESS, D7_PIN_NUMBER, GET_BIT(Command, 3));   //  D7

         SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, High);   //  E
         delay_ms(1);
         SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, Low);   //  E
     }
     // for latching
     delay_ms(2);
     
}
void Lcd_Write_Data(const uint8_t* Data){

     while(*Data != '\0'){ Lcd_WriteCharacter(*Data++); }

}
void Lcd_JumbToAndWrite(const uint8_t* Data, const uint8_t Row, const uint8_t Col){
     Lcd_JumbTo(Row, Col);
     Lcd_Write_Data(Data);
}
void Lcd_JumbTo(const uint8_t Row, const uint8_t Col){
      /*
        First Row Start from 0X00
        Second Row Start From 0X40
     */
     Address_Counter = ((0X40 * Row) + Col) | (1 << 7);   // To Write into DDRAM;
     Lcd_Send_Command(Address_Counter);
}
void Lcd_WriteCharacter(const uint8_t Character){

      // Write operation
     SetPinValue(RW_PIN_ADDRESS, RW_PIN_NUMBER, Low);     //  R/W
     // Data Mode
     SetPinValue(RS_PIN_ADDRESS, RS_PIN_NUMBER, High);   //   RS
     
      // SEND MSB
      SetPinValue(D4_PIN_ADDRESS, D4_PIN_NUMBER, GET_BIT(Character, 4));   //  D4
      SetPinValue(D5_PIN_ADDRESS, D5_PIN_NUMBER, GET_BIT(Character, 5));   //  D5
      SetPinValue(D6_PIN_ADDRESS, D6_PIN_NUMBER, GET_BIT(Character, 6));   //  D6
      SetPinValue(D7_PIN_ADDRESS, D7_PIN_NUMBER, GET_BIT(Character, 7));   //  D7
      /* Latch data */
      SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, High);   //  E
      delay_ms(1);
      SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, Low);   //  E
      // SEN LSB
      SetPinValue(D4_PIN_ADDRESS, D4_PIN_NUMBER, GET_BIT(Character, 0));   //  D4
      SetPinValue(D5_PIN_ADDRESS, D5_PIN_NUMBER, GET_BIT(Character, 1));   //  D5
      SetPinValue(D6_PIN_ADDRESS, D6_PIN_NUMBER, GET_BIT(Character, 2));   //  D6
      SetPinValue(D7_PIN_ADDRESS, D7_PIN_NUMBER, GET_BIT(Character, 3));   //  D7
      /* Latch data */
      SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, High);   //  E
      delay_ms(1);
      SetPinValue(E_PIN_ADDRESS, E_PIN_NUMBER, Low);   //  E

     // Break time Between 2 data
     delay_ms(2);
}
void Lcd_Write_Number(uint16_t Number){
     uint16_t Length = 0;
     Length = Get_Number_Length(Number);
     Number = Reverse_Number(Number);
     do{
        Length--;
        Lcd_WriteCharacter((uint8_t)(Number % 10) + '0'); //ex : 101
     }while(Number /= 10);
     while(Length){ Lcd_WriteCharacter('0');  Length--; }
}