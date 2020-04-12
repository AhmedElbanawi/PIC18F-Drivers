/***************************************************/
#ifndef BIT_MANIPULATION_H
#define BIT_MANIPULATION_H
#endif
/*************************************************/
#define SET_BIT(REG, PIN) ( REG |= (1 << (PIN)) )
#define CLEAR_BIT(REG, PIN) ( REG &= ~(1 << (PIN)) )
#define SET_WORD() (0XFF)
#define CLEAR_WORD() (0X00)
#define SET_LOW_NIBBLE() (0X0F)
#define SET_HIGH_NIBBLE (0XF0)
#define GET_BIT(REG, PIN) ( ( (REG) & ( 1 << (PIN) ) ) >> (PIN) )
/*************************************************/