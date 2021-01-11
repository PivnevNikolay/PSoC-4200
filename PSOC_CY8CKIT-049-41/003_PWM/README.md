
## PWM   
 
после создания проекта на вкладке  TopDesign.cysch в строке поиска вводим PWM --> выбираем PWM(TCPWM mode)[v 2.10]  
В строке поиска вводим Clock --> выбираем  Clock [v2.20] 
В строке поиска вводим pin --> Digital Output Pin [v 2.20]  
Настраиваем блок PWM:
Prescaler --> 1;  
PWM align --> выравнивание по левому краю;  
PWM mode --> PWM;  
Clock = 12МГц надо получить 50кГц  
12 000 000 /50 000 - 1 = 239 данное значение вписываем в register --> period 
Compare value @50%DC = (1-0,5)*(239+1) = 120   
данное значение вписываем в register --> Compare  
 