/**
 20.08.2020.
*********************************************
настройки SPI...
Mode CPHA = 1, CPOL = 1
Data Lines: MOSI+MISO
Data Bits: 8
Shift Direction: MSB First
Bit Rate: 4 Mbps ...!!!
настройки Timer/Counter...
Prescaler: 16x ...!!!
Counter mode: UP
Interrupt: On terminal count
Period: 65535 ...!!!
Базовые настройки для Clock_1 и isr_1
*********************************************
ARDUINO MULTI-FUNCTION SHIELD -->
http://publicatorbar.ru/2017/12/21/arduino-multi-function-shield/
*********************************************
Arduino: Сдвиговый регистр 74НС595 или размножаем/экономим выходы платы -->
http://codius.ru/articles/Arduino_Сдвиговый_регистр_74НС595_или_размножаем_экономим_выходы_платы
*/
#include "project.h"
//#define HIGH  1u
//#define LOW   0u
/* Байт-карты для вращения "бублика" */
const uint8_t BUBLIC_MAP[] = {0x3E,0x3D,0x3B,0x37,0x2F,0x1F};
/* Байт-карты для выбора разряда дисплея от 1 до 4 */
const uint8_t SEGMENT_SELECT[] = {0xF7,0xFB,0xFD,0xFE};//
//-----------------константы_для _счетчика-------------------//
unsigned int i = 0;
//-----------------------------------------------------------//
void WriteNumberToSegment(uint8_t Segment, uint8_t Value);
//--------обработчик_прерывания_по_переполнению_таймера-------//
CY_ISR(Counter_Int_Handler){
    i++;
    if (i==6)i=0;
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);
    /*
     Values:
    - Timer_INTR_MASK_TC       - Terminal count mask
    - Timer_INTR_MASK_CC_MATCH - Compare count / capture mask
    */
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_Start();
    Timer_Start();
    isr_1_StartEx(Counter_Int_Handler);
//---------------------------for()-----------------------------//
    for(;;)
    {
        WriteNumberToSegment(0,  i);//первый разряд
        WriteNumberToSegment(1 , i);//второй разряд 
        WriteNumberToSegment(2 , i);//третий разряд
        WriteNumberToSegment(3 , i);//четвёртый разряд, счёт справа на лево...
    }
}
/* ------------------------- END_main ------------------------- */
/* ----------------------функция_отправки----------------------- */
void WriteNumberToSegment(uint8_t Segment, uint8_t Value)
{
    SPI_WriteTxData(BUBLIC_MAP[Value]);
    SPI_WriteTxData(SEGMENT_SELECT[Segment]);
    CyDelayUs(1);
}
/* --------------------------END-------------------------------- */
