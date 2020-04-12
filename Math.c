/*************************************/
#ifndef SYS_DATATYPES_H
#include "Sys_DataTypes.h"
#endif
/**********************************************************/
uint16_t Reverse_Number(uint16_t Number){
         uint16_t Reversed_Number = 0;
         do{ Reversed_Number = Reversed_Number * 10 + Number % 10; }while(Number /= 10);   //ex : 101
         return Reversed_Number;
}
uint16_t Get_Number_Length(uint16_t Number){
         uint8_t Length = 0;
         do{ Length++; }while(Number /= 10);
         return Length;
}