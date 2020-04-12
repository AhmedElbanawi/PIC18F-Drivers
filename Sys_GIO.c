/********************************************************/
#ifndef SYS_DATATYPES_H
#include "Sys_DataTypes.h"
#endif
/**********************************************************/
#ifndef SYS_GIO_H
#include "Sys_GIO.h"
#endif
/*********************************************************/
#ifndef BIT_MANIPULATION_H
#include "Bit_Manipulation.h"
#endif
/********************************************************/
#define RELATION_BETWEEN +
/********************************************************/
#define ACCESS_MEMORY_CONTENT(X) (*((memoryaddress_t)(X)))
/*********************************************************/
void SetPinDirection(memoryaddress_t Address, const PinNumber_t PinNumber, const PinDirection_t PinDirection){
    const uint8_t Offset = 0X12;
        if(All == PinNumber){
                if(Input == PinDirection){ ACCESS_MEMORY_CONTENT(Offset RELATION_BETWEEN Address) = SET_WORD(); }
                else{ ACCESS_MEMORY_CONTENT(Offset RELATION_BETWEEN Address) = CLEAR_WORD(); }
        }
        else{
                if(Input == PinDirection){ SET_BIT(ACCESS_MEMORY_CONTENT(Offset RELATION_BETWEEN Address), PinNumber); }
                else{ CLEAR_BIT(ACCESS_MEMORY_CONTENT(Offset RELATION_BETWEEN Address), PinNumber); }
        }
}
void SetPinValue(memoryaddress_t Address, const PinNumber_t PinNumber, const Value_t PinValue){
    if(All == PinNumber){
                if(High == PinValue){ ACCESS_MEMORY_CONTENT(Address) = SET_WORD(); }
                else{ ACCESS_MEMORY_CONTENT(Address) = CLEAR_WORD(); }
        }
        else{
                if(High == PinValue){ SET_BIT(ACCESS_MEMORY_CONTENT(Address), PinNumber); }
                else{ CLEAR_BIT(ACCESS_MEMORY_CONTENT(Address), PinNumber); }
        }
}
Value_t ReadPinValue(memoryaddress_t Address, const PinNumber_t PinNumber){
    if(All == PinNumber){ return ACCESS_MEMORY_CONTENT(Address); }
                          return GET_BIT(ACCESS_MEMORY_CONTENT(Address), PinNumber);
}