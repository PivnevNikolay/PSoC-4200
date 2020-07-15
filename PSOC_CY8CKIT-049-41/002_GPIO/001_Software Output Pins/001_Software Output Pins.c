//01.05.2020
#include "project.h"
//int led[5]={0xF,0xE,0xC,0x8,0x0};
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

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
        LED_Write(0xF);//1111
        CyDelay(800);
        break;
    case 1:
        LED_Write(0xE);//1110
        CyDelay(800);
        break;
    case 2:
        LED_Write(0xC);//1100
        CyDelay(800);
        break;
    case 3:
        LED_Write(0x8);//1000
        CyDelay(800);
        break;
    case 4:
        LED_Write(0x0);//0000
        CyDelay(800);
        break;
        }
    }
//---------------------------------------------------//
}
}
/*------------ END OF FILE---------------------------*/