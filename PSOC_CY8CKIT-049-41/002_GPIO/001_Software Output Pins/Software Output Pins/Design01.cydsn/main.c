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
//int led[5]={0xF,0xE,0xC,0x8,0x0};
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;){
//----------используем_массив_led[5]----------------//        
//    for (uint8_t z =0;z<5;z++){
//    LED_Write(led[z]);
//    CyDelay(800);
//    }
//---------------------------------------------------//  
//--------конструкция_switch_cace--------------------//
    for (uint8_t z =0;z<5;z++){    
         switch(z){      
    case 0:
        LED_Write(0xF);
        CyDelay(800);
        break;
    case 1:
        LED_Write(0xE);
        CyDelay(800);
        break;
    case 2:
        LED_Write(0xC);
        CyDelay(800);
        break;
    case 3:
        LED_Write(0x8);
        CyDelay(800);
        break;
    case 4:
        LED_Write(0x0);
        CyDelay(800);
        break;
        }
    }
//---------------------------------------------------//
}
}


/* [] END OF FILE */
