/*******************************************************************************
* File Name: Led.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Led_ALIASES_H) /* Pins Led_ALIASES_H */
#define CY_PINS_Led_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Led_0			(Led__0__PC)
#define Led_0_PS		(Led__0__PS)
#define Led_0_PC		(Led__0__PC)
#define Led_0_DR		(Led__0__DR)
#define Led_0_SHIFT	(Led__0__SHIFT)
#define Led_0_INTR	((uint16)((uint16)0x0003u << (Led__0__SHIFT*2u)))

#define Led_1			(Led__1__PC)
#define Led_1_PS		(Led__1__PS)
#define Led_1_PC		(Led__1__PC)
#define Led_1_DR		(Led__1__DR)
#define Led_1_SHIFT	(Led__1__SHIFT)
#define Led_1_INTR	((uint16)((uint16)0x0003u << (Led__1__SHIFT*2u)))

#define Led_2			(Led__2__PC)
#define Led_2_PS		(Led__2__PS)
#define Led_2_PC		(Led__2__PC)
#define Led_2_DR		(Led__2__DR)
#define Led_2_SHIFT	(Led__2__SHIFT)
#define Led_2_INTR	((uint16)((uint16)0x0003u << (Led__2__SHIFT*2u)))

#define Led_3			(Led__3__PC)
#define Led_3_PS		(Led__3__PS)
#define Led_3_PC		(Led__3__PC)
#define Led_3_DR		(Led__3__DR)
#define Led_3_SHIFT	(Led__3__SHIFT)
#define Led_3_INTR	((uint16)((uint16)0x0003u << (Led__3__SHIFT*2u)))

#define Led_4			(Led__4__PC)
#define Led_4_PS		(Led__4__PS)
#define Led_4_PC		(Led__4__PC)
#define Led_4_DR		(Led__4__DR)
#define Led_4_SHIFT	(Led__4__SHIFT)
#define Led_4_INTR	((uint16)((uint16)0x0003u << (Led__4__SHIFT*2u)))

#define Led_5			(Led__5__PC)
#define Led_5_PS		(Led__5__PS)
#define Led_5_PC		(Led__5__PC)
#define Led_5_DR		(Led__5__DR)
#define Led_5_SHIFT	(Led__5__SHIFT)
#define Led_5_INTR	((uint16)((uint16)0x0003u << (Led__5__SHIFT*2u)))

#define Led_6			(Led__6__PC)
#define Led_6_PS		(Led__6__PS)
#define Led_6_PC		(Led__6__PC)
#define Led_6_DR		(Led__6__DR)
#define Led_6_SHIFT	(Led__6__SHIFT)
#define Led_6_INTR	((uint16)((uint16)0x0003u << (Led__6__SHIFT*2u)))

#define Led_7			(Led__7__PC)
#define Led_7_PS		(Led__7__PS)
#define Led_7_PC		(Led__7__PC)
#define Led_7_DR		(Led__7__DR)
#define Led_7_SHIFT	(Led__7__SHIFT)
#define Led_7_INTR	((uint16)((uint16)0x0003u << (Led__7__SHIFT*2u)))

#define Led_INTR_ALL	 ((uint16)(Led_0_INTR| Led_1_INTR| Led_2_INTR| Led_3_INTR| Led_4_INTR| Led_5_INTR| Led_6_INTR| Led_7_INTR))


#endif /* End Pins Led_ALIASES_H */


/* [] END OF FILE */
