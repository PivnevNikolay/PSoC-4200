/**---------------------------------------------
*\date  10.08.2023
*\brief
* Configure Pin:
* Type                 --> Digital output
* Initial drive state  --> High(1)
*
*  CY8C4245AXI-483 (44TQFP)
*   ------------
*  |            |
*  |            |
*  |            |
*  |        P0.2| --> LED_Green (Pin_Green)
*  |        P0.3| --> LED_Blue  (Pin_Blue )
*  |        P1.6| --> LED_Red   (Pin_Red  )
*  |            |
*
*  PSoC 101: Lesson 1 Software Output Pins
*  https://www.youtube.com/watch?v=wttaZVbmBI8&list=PLIOkqhZiy83F8KPvHejA4ujvAfwJYpAtP&index=1
*
*\authors ScuratovaAnna
*\brief
*/
#include "project.h"
uint8_t i;
uint8_t z = 0;
uint8_t status_LED[2]= {0x0,0x1};
int main(void)
{
 CyGlobalIntEnable; 
    for(;;)
    {
    switch(z){
     case 0:
     for (i=0;i<2;i++){
      Pin_Green_Write(*(status_LED + i));
      CyDelay(250);
    }
    z++;
    break;
     case 1:
     for (i=0;i<2;i++){
      Pin_Red_Write(*(status_LED + i));
      CyDelay(250);
    }
    z++;
    break;
     case 2:
     for (i=0;i<2;i++){
      Pin_Blue_Write(*(status_LED + i));
      CyDelay(250);
    }
    z=0;    
    break;
    }
  }
}