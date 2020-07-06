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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
   PWM_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
                //PWM_WriteCompare( 120 );

	PWM_1_WriteCompare(100);
    CyDelay(1500);
   	PWM_1_WriteCompare(150);
    CyDelay(1500);
    
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
