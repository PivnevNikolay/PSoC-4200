//03.04.2021
//MAX7219 - драйвер светодиодных индикаторов
//https://radiolaba.ru/microcotrollers/max7219-drayver-svetodiodnyih-indikatorov.html
#include "project.h"
//#include <stdbool.h>
//---------------------------------------------------------------------------//
/*Массив символов              0     1     2     3     4     5     6     7     8     9    */
const uint8_t massive[10] = { 0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
/*Массив символов                 0.    1.    2.    3.    4.    5.    6.    7.    8.    9. */
const uint8_t massive_point[10]={0xFE, 0xB0, 0xED, 0xF9, 0xB3, 0xDB, 0xDF, 0xF0, 0xFF, 0xFB};
//---------------------------------------------------------------------------//
uint8_t z;
uint8_t x;
//---------------------------------------------------------------------------//
void LCD_Initialization_Send_Data( uint8_t  address, uint8_t  data);
void LCD_Send_Data_Transmit( uint8_t  address, uint8_t  data);
void LCD_Init(void);
void LCD_Display_Clean(void);
void Led_Display_Test(uint8_t  data);
//---------------------------------------------------------------------------//
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    SPI_Start(); 
    LCD_Init();
    Led_Display_Test(0x01);//тест дисплея, подадим питание на все сегменты
    Led_Display_Test(0x00);//тест дисплея, снимим питание с сегментов
    LCD_Display_Clean();
    
    for(;;)
    {
        for ( z =1;z<9;z++){
    LCD_Send_Data_Transmit( z, massive[z-1]);
    CyDelay(1000);   
        }
        for ( z =8;z>0;z--){
    LCD_Send_Data_Transmit( z, 0x00);
    CyDelay(1000);   
        }
        for ( z =1;z<9;z++){
    LCD_Send_Data_Transmit( z, massive_point[z-1]);
    CyDelay(1000);   
        }
        for ( z =8;z>0;z--){
    LCD_Send_Data_Transmit( z, 0x00);
    CyDelay(1000);   
        }
    }
}
//---------------------------------------------------------------------------//
void LCD_Init(void){
    CyDelay(100);
    LCD_Initialization_Send_Data( 0x09, 0x00);//без режима декодирования
    LCD_Initialization_Send_Data( 0x0A, 0x0F);//значение яркости сегментов на максимум
    LCD_Initialization_Send_Data( 0x0B, 0x07);//задействуем все 8 разрядов дисплея
    LCD_Initialization_Send_Data( 0x0C, 0x01);//выводим дисплей из сна    
}
//---------------------------------------------------------------------------//
void LCD_Initialization_Send_Data( uint8_t  address, uint8_t  data){
     SPI_WriteTxData(address);
     SPI_WriteTxData(data);
     CyDelayUs(5);
    
}
//---------------------------------------------------------------------------//
void LCD_Send_Data_Transmit( uint8_t  address, uint8_t  data){
     SPI_WriteTxData(address);
     SPI_WriteTxData(data);    
}
//---------------------------------------------------------------------------//
void LCD_Display_Clean(void){
    LCD_Initialization_Send_Data( 0x01, 0x00);//обнулим первый сегмент дисплея
    CyDelay(10);
    LCD_Initialization_Send_Data( 0x02, 0x00);//обнулим второй сегмент дисплея
    CyDelay(10);
    LCD_Initialization_Send_Data( 0x03, 0x00);//обнулим третий сегмент дисплея
    CyDelay(10);
    LCD_Initialization_Send_Data( 0x04, 0x00);//обнулим четвертый сегмент дисплея
    CyDelay(10);
    LCD_Initialization_Send_Data( 0x05, 0x00);//обнулим пятый сегмент дисплея
    CyDelay(10);
    LCD_Initialization_Send_Data( 0x06, 0x00);//обнулим шестой сегмент дисплея
    CyDelay(10);
    LCD_Initialization_Send_Data( 0x07, 0x00);//обнулим седьмой сегмент дисплея
    CyDelay(10);
    LCD_Initialization_Send_Data( 0x08, 0x00);//обнулим восьмой сегмент дисплея
    CyDelay(10); 
       
}
//---------------------------------------------------------------------------//    
void Led_Display_Test(uint8_t  data){
	LCD_Initialization_Send_Data(0x0F, data);
    CyDelay(500);
}
/* [] END OF FILE */