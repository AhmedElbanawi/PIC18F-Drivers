/***************************************************************************/
#ifndef LCD_H
#define LCD_H
#endif
/*************************************************************************/
#define D4_PIN_NUMBER Pin4
#define D5_PIN_NUMBER Pin5
#define D6_PIN_NUMBER Pin6
#define D7_PIN_NUMBER Pin7
#define E_PIN_NUMBER  Pin3
#define RW_PIN_NUMBER Pin2
#define RS_PIN_NUMBER Pin1

#define D4_PIN_ADDRESS D
#define D5_PIN_ADDRESS D
#define D6_PIN_ADDRESS D
#define D7_PIN_ADDRESS D
#define E_PIN_ADDRESS  D
#define RW_PIN_ADDRESS D
#define RS_PIN_ADDRESS D



void Lcd_Config(void);
void Lcd_Send_Command(const uint8_t Command);                    /* Used To Clear LCD When Send 0X00 */
void Lcd_Write_Data(const uint8_t* Data);
void Lcd_JumbToAndWrite(const uint8_t* Data, const uint8_t Row, const uint8_t Col);
void Lcd_WriteCharacter(const uint8_t Character);
void Lcd_JumbTo(const uint8_t Row, const uint8_t Col);
void Lcd_Write_Number(uint16_t Number);                        /* Use To Write 1, 2, 3, 4 and 5 Digits Max Number 65535 */