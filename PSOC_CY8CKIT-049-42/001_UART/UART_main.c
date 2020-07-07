/*05.07.2020
Данный пример демонстрирует работу UART(прерывания по приёму...).
При вводе и отправке в терминале enabl светодиод на плате P1.6 загорится.
При вводе и отправке в терминале desab светодиод на плате P1.6 потухнет.
*/
#include "project.h"
#define RX_BUF_SIZE 5
#define LED_ON  1u
#define LED_OFF 0u
//------------------------------------------------------// 
uint16_t rec_array[5]={0u,0u,0u,0u,0u};
//массивы сравнения 100 % всегда должны быть разными иначе возникают коллизии
//в моём случае недолжно быть повторений  в  символах первого и второго массива
char start[5]={'e','n','a','b','l'};
char stopp[5]={'d','e','s','a','b'};
uint8_t RXi;
uint8_t start_count = 0;
uint8_t stopp_count = 0;
uint8_t count_rec=0;
uint8_t count_comparison = 0;
void clear_RXBuffer(void);
//------------------------------------------------------// 
CY_ISR(RX_interrupt_Handler){
rec_array[count_rec]= UART_ReadRxData();
count_rec++;
count_comparison ++;
if( count_rec==5){count_rec=0;}
 RX_Interrupt_ClearPending();
}
//------------------------------------------------------// 
int main(void)
{
    
 CyGlobalIntEnable; /* Enable global interrupts. */
 RX_Interrupt_StartEx(RX_interrupt_Handler);   
 UART_Start(); /* Start UART */
/* Send start message 
   для проверки работоспособности и правильного подключения..
*/
 UART_PutString("Half Duplex Test"); 
    for(;;)
    {
 /*LED_Write(~LED_Read());
   CyDelay(1200);
   нет влияния на код, задержка отрабатывает,
   программа выполняется дальше без проблем...
*/
    if (count_comparison==5){
      
        for(uint8_t z=0;z<5;z++){
        if (start[z]==rec_array[z])
        {
        start_count++;
        UART_PutChar(rec_array[z]);//смотрим что в буфере
        }
        else break;
        } 
        for(uint8_t v=0;v<5;v++){
        if (stopp[v]==rec_array[v])
        {
        stopp_count++;
        UART_PutChar(rec_array[v]);//смотрим что в буфере
        }
        else break;
        }
//------------------------------------------------------//    
        if( start_count==5){
        LED_Write(LED_ON);
        UART_PutString("LED HIGH\n\r");         
        start_count=0;
        clear_RXBuffer();
        }
        if( stopp_count==5){
        LED_Write(LED_OFF);
        UART_PutString("LED OFF\n\r");         
        stopp_count=0;
        clear_RXBuffer();
        }    
    }   
}
}

//------------------------------------------------------//
void clear_RXBuffer(void) {
    for (RXi=0; RXi<RX_BUF_SIZE; RXi++){
    rec_array[RXi] = 0u;
    }
    count_comparison=0;
}

/*----------------------- END OF FILE-------------------- */