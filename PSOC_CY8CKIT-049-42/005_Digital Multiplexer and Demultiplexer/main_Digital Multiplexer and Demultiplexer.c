//13.01.2021
#include "project.h"

uint8_t flag = 0;
uint8_t status = 0;
//-----обработчик первого прерывания-----//
CY_ISR(input_button_Handler){  
    flag ++; 
    if(flag>1){
        flag = 0;
    }
    Pin_1_ClearInterrupt();// данный момент важен используется не isr_ClearPending();
}
//---------------------------------------//
//-----Обработчик второго прерывания-----//
CY_ISR(input_button_1_Handler){  
    status ++; 
    if(status>3){
        status = 0;
    }
    Pin_2_ClearInterrupt();// данный момент важен используется не isr_1_ClearPending();
}
//---------------------------------------//
int main(void)
{
    CyGlobalIntEnable;
    TCPWM_1_Start();//Старт первого таймера 20kHz
    TCPWM_2_Start();//Старт второго таймера на 1MHz
    isr_StartEx(input_button_Handler);
    isr_1_StartEx(input_button_1_Handler);
    

    for(;;)
    {        
    switch(flag){      
    case 0:
        Control_Reg_1_Write(1);
        break;
    case 1:
        Control_Reg_1_Write(0);
        break;
    }
            
    switch(status){      
    case 0:
        Control_Reg_2_Write(0);//0000
        break;
    case 1:
        Control_Reg_2_Write(1);//0001
        break;
    case 2:
        Control_Reg_2_Write(2);//0010
        break;
    case 3:
        Control_Reg_2_Write(3);//0011
        break;
    }
}
}


