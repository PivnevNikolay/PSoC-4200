//11.01.2021
#include "project.h"

uint8_t count = 0;
uint8_t i = 100;

CY_ISR(Status_Reg_2_Handler)
{
    count++;
    if( count>=9)
    {
     count =9;   
    }
isr_2_ClearPending();
}


CY_ISR(Status_Reg_1_Handler)
{
    if( count==0)
    {
     count =1;   
    } 
    count--;
        
isr_1_ClearPending();
}


int main(void)
{
 CyGlobalIntEnable;
 isr_1_StartEx(Status_Reg_1_Handler);
 isr_2_StartEx(Status_Reg_2_Handler);
 Status_Reg_1_InterruptEnable();
 Status_Reg_2_InterruptEnable();
    for(;;)
    {
        switch(count){      
    case 0:
        Out_Pin_Write(0x3F);
        CyDelay(i);
        break;
    case 1:
        Out_Pin_Write(0x6);
       CyDelay(i);
        break;
    case 2:
        Out_Pin_Write(0x5B);
        CyDelay(i);
        break;
    case 3:
        Out_Pin_Write(0x4F);
        CyDelay(i);
        break;
    case 4:
        Out_Pin_Write(0x66);
       CyDelay(i);
        break;
    case 5:
        Out_Pin_Write(0x6D);
        CyDelay(i);
        break;
    case 6:
        Out_Pin_Write(0x7D);
        CyDelay(i);
        break;
    case 7:
        Out_Pin_Write(0x7);
        CyDelay(i);
        break;
    case 8:
        Out_Pin_Write(0x7F);
       CyDelay(i);
        break;
    case 9:
        Out_Pin_Write(0x6F);
        CyDelay(i);
        break;
    }
}
}


