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
int bublic[6]={0x3E,0x3D,0x3B,0x37,0x2F,0x1F};
int Count = 0;
int z = 0;

CY_ISR(IN_Pin_Handler)
{
    Count++;
    if (Count >10){
        Count = 0;
        z = ~z;
        }
IN_Pin_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

   IN_Pin_Int_StartEx(IN_Pin_Handler);

    for(;;)
    {
        if(Count == 0 && z == 0)
        {
            for (int i = 0; i<6; i++){
            Led_Write(bublic[i]); 
            CyDelay(120);
            if(Count!=0)
               break;                       
            }         
        }
       else if (Count == 0 && z != 0){
         for (int i = 5; i>=0; i--){
            Led_Write(bublic[i]); 
            CyDelay(120);
            if(Count!=0)
               break;                       
            }   
        }
          switch(Count){      
    case 1:
        Led_Write(0x3F);
        break;
    case 2:
        Led_Write(0X6);
        break;
    case 3:
        Led_Write(0x5B);
        break;
    case 4:
        Led_Write(0x4F);
        break;
    case 5:
        Led_Write(0x66);
        break;
    case 6:
        Led_Write(0x6D);
        break;
    case 7:
        Led_Write(0x7D);
        break;
    case 8:
        Led_Write(0x7);
        break;
    case 9:
        Led_Write(0x7F);
        break;
    case 10:
        Led_Write(0x67);
        break;
    }
}
}
/* [] END OF FILE */
