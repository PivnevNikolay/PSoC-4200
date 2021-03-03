//03.03.2021

#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include "ssd1306.h"
//------------------------------------------------------------------------------------------------------//
#define DISPLAY_ADDRESS 0x3C 
//------------------------------------------------------------------------------------------------------//
#define ADC_CH_TEMP         (0x02u)
#define ADC_INJ_PERIOD      (5u)
#define DIETEMP_VREF_MV_VALUE   (1024)
#define UART_BUFFLEN        (100u)

 uint8_t massive[10] = {48,49,50,51,52,53,54,55,56,57};
 uint8_t Ta,Da,Sa,Ea;
 uint8_t Tb,Db,Sb,Eb;
 int16 adcResult[ADC_SAR_Seq_TOTAL_CHANNELS_NUM] = {0};
 int16 voltage[ADC_SAR_Seq_SEQUENCED_CHANNELS_NUM] = {0};
 uint16 i = 0;
 char  uartBuff[UART_BUFFLEN];
//---------------------------------------------------------------------//
CY_ISR(Isr_Timer_Handler)
{
    ADC_SAR_Seq_StartConvert();
    Timer_ClearInterrupt(Timer_INTR_MASK_TC);
}
//---------------------------------------------------------------------//
int main()
{
    /* Enable the global interrupts */
    CyGlobalIntEnable;     
    /* Start the components */
    UART_Start();
    ADC_SAR_Seq_Start();
    Timer_Start();
    Isr_Timer_StartEx(Isr_Timer_Handler);    
    I2C_Start();
    display_init(DISPLAY_ADDRESS);    
    UART_PutString("Starting measurements...\r\n\r\n");
//---------------------------------------------------------------------//    
    for(;;)
    {
        /* When conversion of sequencing channels has completed */
        if(0u != ADC_SAR_Seq_IsEndConversion(ADC_SAR_Seq_RETURN_STATUS))
        {
            
            for(i = 0; i < ADC_SAR_Seq_SEQUENCED_CHANNELS_NUM; i++)
            {
                /* Save and convert the ADC result value */
                adcResult[i] = ADC_SAR_Seq_GetResult16(i);
                voltage[i] = ADC_SAR_Seq_CountsTo_mVolts(i, adcResult[i]);
                
                /* Print the voltage value into the UART */
                (void)snprintf(uartBuff, UART_BUFFLEN, 
                               "ADC voltage CH%u = %imV \r\n", i,  voltage[i]);
                UART_PutString(uartBuff);
                Ta = voltage[0]/1000;
                Sa = (voltage[0]%1000)/100;
                Da = ((voltage[0]%1000)%100)/10;
                Ea = ((voltage[0]%1000)%100)%10;
                Tb = voltage[1]/1000;
                Sb = (voltage[1]%1000)/100;
                Db = ((voltage[1]%1000)%100)/10;
                Eb = ((voltage[1]%1000)%100)%10;
                display_clear();  
                gfx_setTextSize(1);
                gfx_setTextColor(WHITE);
                gfx_setCursor(0,0);
                gfx_println("Voitage canal 1 : ");
                gfx_drawChar(0, 10,massive[Ta],1,1,2);
                gfx_drawChar(15,10,massive[Sa],1,1,2);
                gfx_drawChar(30,10,massive[Da],1,1,2);
                gfx_drawChar(45,10,massive[Ea],1,1,2);
                gfx_setTextSize(2);
                gfx_setCursor(70,10);
                gfx_println("mV"); 
                gfx_setCursor(0,30);
                gfx_setTextSize(1);
                gfx_println("Voitage canal 2 : ");
                gfx_drawChar(0, 40,massive[Tb],1,1,2);
                gfx_drawChar(15,40,massive[Sb],1,1,2);
                gfx_drawChar(30,40,massive[Db],1,1,2);
                gfx_drawChar(45,40,massive[Eb],1,1,2);
                gfx_setTextSize(2);
                gfx_setCursor(70,40);
                gfx_println("mV");                
                display_update();
            }            
            UART_PutCRLF();
        }    
    }
}
//-------------------------------- END OF FILE -----------------//
