## CY8CKIT-049-41X Software Output Pins  
---
  ![alt-текст](https://github.com/PivnevNikolay/PSOC_CY8CKIT-049-41/blob/master/PSOC_CY8CKIT-049-41/002_GPIO/001_Software%20Output%20Pins/FOTO_Project/005.jpg "")  
### Создаём свой первый проект   
 1. File --> New --> Project  
 ![alt-текст](https://github.com/PivnevNikolay/PSOC_CY8CKIT-049-41/blob/master/PSOC_CY8CKIT-049-41/002_GPIO/001_Software%20Output%20Pins/FOTO_Project/001.jpg "")  
  ![alt-текст](https://github.com/PivnevNikolay/PSOC_CY8CKIT-049-41/blob/master/PSOC_CY8CKIT-049-41/002_GPIO/001_Software%20Output%20Pins/FOTO_Project/002.jpg "")  
 ![alt-текст](https://github.com/PivnevNikolay/PSOC_CY8CKIT-049-41/blob/master/PSOC_CY8CKIT-049-41/002_GPIO/001_Software%20Output%20Pins/FOTO_Project/003.jpg "")  
 2. В вкладке Component Catalog  в строке поиска набираем pin --> Выносим на поле компонент Digital Output Pin[v2.20]
 3. Дважды кликаем на сам компонент --> В поле Number of pins пишем 4 --> Убираем галку с HW connection
 4. В поле Initial drive state меняем значение с Low(0) на High(1) --> Жмём ОК
 5. Переходим на вкладку Design Wibe Resurs расширение .cydwr вкладка pins  
 ![alt-текст](https://github.com/PivnevNikolay/PSOC_CY8CKIT-049-41/blob/master/PSOC_CY8CKIT-049-41/002_GPIO/001_Software%20Output%20Pins/FOTO_Project/004.jpg)
 6. Вверху справа жмём на выподающий список port и указываем самое верхнее значение P0[3:0] рядом на вкладке Pin  увидем номера выводов с 24 по 27
 7. Собирём проект Shift+F6...
 8. Переходим в main.c и пишем код для нашего приложения...
 9. В моём примере я использую два подхода первый это 
 
 