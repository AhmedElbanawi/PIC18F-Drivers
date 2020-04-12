/*************************************/
#ifndef SYS_DATATYPES_H
#define SYS_DATATYPES_H
#endif
/*************************************/
typedef unsigned char  uint8_t;
typedef unsigned int   uint16_t;
typedef unsigned long int  uint32_t;
typedef uint8_t wordsize_t;
typedef volatile wordsize_t* const memoryaddress_t;
/*************************************/
typedef signed char  int8_t;
typedef signed int int16_t;
typedef signed long int  int32_t;
/*************************************/
typedef enum{ Low = 0, High = 1}Value_t;
typedef enum{ FallingEdge = 0, RisingEdge = 1}ClockPolarity_t;