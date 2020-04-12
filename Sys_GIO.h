/*******************************************************************************/
#ifndef SYS_GIO_H
#define SYS_GIO_H
#endif
/*******************************************************************************/
#ifndef SYS_GIO_ADDRESSES_H
#include "Sys_GIO_Addresses.h"
#endif
/*******************************************************************************/
typedef enum{Output = 0, Input = 1}PinDirection_t;
typedef enum{Pin0 = 0, Pin1, Pin2, Pin3, Pin4, Pin5, Pin6, Pin7, All}PinNumber_t;
/*******************************************************************************/
void SetPinDirection(memoryaddress_t Address, const PinNumber_t PinNumber, const PinDirection_t PinDirection);
void SetPinValue(memoryaddress_t Address, const PinNumber_t PinNumber, const Value_t PinValue);
Value_t ReadPinValue(memoryaddress_t Address, const PinNumber_t PinNumber);