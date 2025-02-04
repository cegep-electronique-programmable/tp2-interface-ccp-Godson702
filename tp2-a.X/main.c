/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F25K80
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
int trouver_CCPR(double dutyCycle);




/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    int ccpr_val;
    ccpr_val= trouver_CCPR(7.5);
    PWM2_LoadDutyValue(ccpr_val);
    while(1)
    {
        
        printf("\r\n voulez vous barrer (L) ou débarrer (U) la porte?");
        int caractere=EUSART1_Read();
        EUSART1_Write(caractere);
        
        switch(caractere)   //s'active lorsqu'on appuis sur les touches l et u
        {
            
            
           
            case 'L': //pour faire tourner le servomoteur a gauche
               
                ccpr_val= trouver_CCPR(3.5);
                PWM2_LoadDutyValue(ccpr_val);
                break;

            case 'U'://pour faire tourner le servomoteur a droite 
                
                ccpr_val= trouver_CCPR(11.5);
                PWM2_LoadDutyValue(ccpr_val);
                break;

            default:
                
                break;
                

        }
        
        
    }
   
        
       
    
        
        
    
    
    
     
   
}
int trouver_CCPR(double dutyCycle)//Permet de trouver le CCPR avec un PMW
{
    if(dutyCycle<3.5)
    {
        dutyCycle=3.5;
    }
    if(dutyCycle>11.5)
    {
        dutyCycle=11.5;
    }
    double ccpr=(((dutyCycle/100)*0.019968)/0.032768)*1023.0 ;
   
    return (int)ccpr;
}