/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

uint8_t count = 0;
uint8_t i = 100;

CY_ISR(Status_Reg_2_Handler)
{
//Out_Pin_2_Write(~ Out_Pin_2_Read());
    count++;
    if( count>=9)
    {
     count =9;   
    }
isr_2_ClearPending();
}


CY_ISR(Status_Reg_1_Handler)
{
//Out_Pin_1_Write(~ Out_Pin_1_Read());
    if( count==0)
    {
     count =1;   
    } 
    count--;
        
isr_1_ClearPending();
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(Status_Reg_1_Handler);
    isr_2_StartEx(Status_Reg_2_Handler);
 Status_Reg_1_InterruptEnable();
Status_Reg_2_InterruptEnable();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        switch(count){      
    case 0:
        Out_Pin_Write(0x3F);
        CyDelay(i);
        //Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 1:
        Out_Pin_Write(0x6);
       CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 2:
        Out_Pin_Write(0x5B);
        CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 3:
        Out_Pin_Write(0x4F);
        CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 4:
        Out_Pin_Write(0x66);
       CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 5:
        Out_Pin_Write(0x6D);
        CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 6:
        Out_Pin_Write(0x7D);
        CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 7:
        Out_Pin_Write(0x7);
        CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    case 8:
        Out_Pin_Write(0x7F);
       CyDelay(i);
      //  Out_Pin_Write(0x00);
      //  CyDelay(i);
        break;
    case 9:
        Out_Pin_Write(0x6F);
        CyDelay(i);
       // Out_Pin_Write(0x00);
       // CyDelay(i);
        break;
    }
}
}


/* [] END OF FILE */
