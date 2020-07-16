###   Nextion.  

[Nextion Enhanced 3,5” / 480×320 (NX4832K035_011).](https://amperka.ru/product/display-nextion-enhanced-nx4832k035) 
 
* Создаём проект для экрана.  

![alt-текст](https://github.com/PivnevNikolay/PSOC_CY8CKIT-049-41/blob/master/PSOC_CY8CKIT-049-42/002_UART_NEXTION/FOTO/n_01.jpg "")  

В проекте две кнопки LED_ON(b0) и LED_OFF(b1), Text(t0), Scroleng text(g0).  
Код для кнопки LED_ON(b0)...  
if(t0.txt=="STATUS_XXX"||t0.txt=="STATUS_OFF")  
{  
  t0.txt="STATUS_ON"  
  t0.pco=63488  
  print "onnstatus"  
}  
Код для кнопки LED_OFF(b1)...  
if(t0.txt=="STATUS_ON")  
{  
  t0.txt="STATUS_OFF"  
  t0.pco=31  
  print "statusoff"  
}  

Код для настройки скорости UART NEXTION  
page(0) bauds=115200  
 

