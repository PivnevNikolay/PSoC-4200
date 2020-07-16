//12.07.2020
#include "project.h"
#define RX_BUF_SIZE 9
#define LED_ON  1u
#define LED_OFF 0u
//--------------------------------------------------------------------------------------------------------------//
volatile uint16_t rec_array[9]={0u,0u,0u,0u,0u,0u,0u,0u,0u};//массив куда принимаем данные которые пришли с UART
char start[9]={'o','n','n','s','t','a','t','u','s'};//массив для сравнения onnstatus
char stopp[9]={'s','t','a','t','u','s','o','f','f'};//массив для сравнения statusoff
//---------------------------------------------------------------------------------//
uint8_t start_count = 0;//переменная для подсчёта совпадений
uint8_t stopp_count = 0;//переменная для подсчёта совпадений
uint8_t count_rec=0;//переменная для приёма данных
uint8_t count_comparison=0 ;//увеличиваем значение переменной при приеме 
void clear_RXBuffer(void);
//-------------------обработчик_прерывания--------------------------// 
CY_ISR(RX_interrupt_Handler){//если данные пришли начинаем принимать
    rec_array[count_rec]= UART_ReadRxData();//в массив rec_array[]
    // rec_array[count_rec]= UART_GetChar();
    count_rec++;//счетчики увеличиваем
    count_comparison ++;   
    if( count_rec==9){count_rec=0;}//обнуляем счетчик по достижению 9 
    RX_Interrupt_ClearPending();//очищаем статус
}
//------------------------------------------------------// 
int main(void)
{
     CyGlobalIntEnable; /* Enable global interrupts. */
     RX_Interrupt_StartEx(RX_interrupt_Handler); 
     UART_Start(); /* Start UART */
     UART_PutString("t0.pco=65535\xFF\xFF\xFF");
     UART_PutString("t0.txt=\"STATUS_OFF\"\xFF\xFF\xFF");
    
    for(;;)
    {
        /*
        при отключении питания и последующем включении питания отладочной платы
        необходим данный участок кода ,
        как только счётчик приёма привысит значение 9 и не произойдёт его обнуление необходимо очистить все буферы 
		при запуске экрана в UART транслируется мусор(подтяжки в виде резисторов не помагают решить данную проблему )...
 		для коректной работы по приёму данных необходимо очистить буферы....		
        */
        if (count_comparison>9){
        UART_ClearRxBuffer();
        UART_ClearTxBuffer();
        clear_RXBuffer();
        count_rec=0;
        UART_PutString("g0.pco=65504\xFF\xFF\xFF");//меняем цвет текста g0.txt на жёлтый
        UART_PutString("g0.txt=\"CLEAR\"\xFF\xFF\xFF");//выводим на экран сообщение очистки буферов
    }
    if (count_comparison==9){//как только счётчик достиг 9 начинаем сравнивать массивы
      
        for(uint8_t z=0;z<9;z++){
        if (start[z]==rec_array[z])
        {
        start_count++;//если массивы совпадают увеличиваем счетчик start_count
        }
        else break;//если нет выходим 
        } 
        for(uint8_t v=0;v<9;v++){
        if (stopp[v]==rec_array[v])
        {
        stopp_count++;//если массивы совпадают увеличиваем счетчик stopp_count
        }
        else break;//если нет выходим 
     }
//------------------------------------------------------//    
        if( start_count==9){ //если счетчик start_count=9 то
        LED_Write(LED_ON);//зажигаем светодиод
        UART_PutString("g0.pco=63488\xFF\xFF\xFF");//меняем цвет текста g0.txt на красный
        UART_PutString("g0.txt=\"CY8CKIT_LED_ON\"\xFF\xFF\xFF");//выводим собщение которое отобразится на экране Nextion в g0.txt         
        clear_RXBuffer();//обнуляем буфер куда были приняты данные поступившие из UART, обнуляем счётчик приёма start_count
        }
        if( stopp_count==9){//после сравненния счетчик stopp_count=9 то
        LED_Write(LED_OFF);// светодиод гасим
        UART_PutString("g0.pco=31\xFF\xFF\xFF");//меняем цвет текста g0.txt на синий
        UART_PutString("g0.txt=\"CY8CKIT_LED_OFF\"\xFF\xFF\xFF");//выводим собщение которое отобразится на экране Nextion в g0.txt         
        clear_RXBuffer();//обнуляем буфер в который были приняты данные поступившие из UART, обнуляем счётчик приёма stopp_count
     }    
    }   
  }
}

//функция очистки буфера приёма
void clear_RXBuffer(void) {
    for (uint8_t RXi=0; RXi<RX_BUF_SIZE; RXi++){
    rec_array[RXi] = 0u;
    }
    count_comparison=0;//обнуляем счётчик приёма
    start_count = 0;//обнуляем счётчик приёма
    stopp_count = 0;//обнуляем счётчик приёма
    // UART_ClearRxBuffer();
    // UART_ClearTxBuffer();
}
/*-----------------END OF FILE-----------------------*/
