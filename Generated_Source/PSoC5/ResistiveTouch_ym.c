/*******************************************************************************
* File Name: ResistiveTouch_ym.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ResistiveTouch_ym.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 ResistiveTouch_ym__PORT == 15 && ((ResistiveTouch_ym__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: ResistiveTouch_ym_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void ResistiveTouch_ym_Write(uint8 value) 
{
    uint8 staticBits = (ResistiveTouch_ym_DR & (uint8)(~ResistiveTouch_ym_MASK));
    ResistiveTouch_ym_DR = staticBits | ((uint8)(value << ResistiveTouch_ym_SHIFT) & ResistiveTouch_ym_MASK);
}


/*******************************************************************************
* Function Name: ResistiveTouch_ym_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  ResistiveTouch_ym_DM_STRONG     Strong Drive 
*  ResistiveTouch_ym_DM_OD_HI      Open Drain, Drives High 
*  ResistiveTouch_ym_DM_OD_LO      Open Drain, Drives Low 
*  ResistiveTouch_ym_DM_RES_UP     Resistive Pull Up 
*  ResistiveTouch_ym_DM_RES_DWN    Resistive Pull Down 
*  ResistiveTouch_ym_DM_RES_UPDWN  Resistive Pull Up/Down 
*  ResistiveTouch_ym_DM_DIG_HIZ    High Impedance Digital 
*  ResistiveTouch_ym_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void ResistiveTouch_ym_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(ResistiveTouch_ym_0, mode);
}


/*******************************************************************************
* Function Name: ResistiveTouch_ym_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro ResistiveTouch_ym_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 ResistiveTouch_ym_Read(void) 
{
    return (ResistiveTouch_ym_PS & ResistiveTouch_ym_MASK) >> ResistiveTouch_ym_SHIFT;
}


/*******************************************************************************
* Function Name: ResistiveTouch_ym_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 ResistiveTouch_ym_ReadDataReg(void) 
{
    return (ResistiveTouch_ym_DR & ResistiveTouch_ym_MASK) >> ResistiveTouch_ym_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(ResistiveTouch_ym_INTSTAT) 

    /*******************************************************************************
    * Function Name: ResistiveTouch_ym_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 ResistiveTouch_ym_ClearInterrupt(void) 
    {
        return (ResistiveTouch_ym_INTSTAT & ResistiveTouch_ym_MASK) >> ResistiveTouch_ym_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
