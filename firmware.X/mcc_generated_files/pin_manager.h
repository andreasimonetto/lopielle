/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1788
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set CTL_A0 aliases
#define CTL_A0_TRIS                 TRISAbits.TRISA0
#define CTL_A0_LAT                  LATAbits.LATA0
#define CTL_A0_PORT                 PORTAbits.RA0
#define CTL_A0_WPU                  WPUAbits.WPUA0
#define CTL_A0_ANS                  ANSELAbits.ANSA0
#define CTL_A0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define CTL_A0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define CTL_A0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define CTL_A0_GetValue()           PORTAbits.RA0
#define CTL_A0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define CTL_A0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define CTL_A0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define CTL_A0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define CTL_A0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define CTL_A0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set CTL_A1 aliases
#define CTL_A1_TRIS                 TRISAbits.TRISA1
#define CTL_A1_LAT                  LATAbits.LATA1
#define CTL_A1_PORT                 PORTAbits.RA1
#define CTL_A1_WPU                  WPUAbits.WPUA1
#define CTL_A1_ANS                  ANSELAbits.ANSA1
#define CTL_A1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define CTL_A1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define CTL_A1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define CTL_A1_GetValue()           PORTAbits.RA1
#define CTL_A1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define CTL_A1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define CTL_A1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define CTL_A1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define CTL_A1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define CTL_A1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set CTL_A2 aliases
#define CTL_A2_TRIS                 TRISAbits.TRISA2
#define CTL_A2_LAT                  LATAbits.LATA2
#define CTL_A2_PORT                 PORTAbits.RA2
#define CTL_A2_WPU                  WPUAbits.WPUA2
#define CTL_A2_ANS                  ANSELAbits.ANSA2
#define CTL_A2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define CTL_A2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define CTL_A2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define CTL_A2_GetValue()           PORTAbits.RA2
#define CTL_A2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define CTL_A2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define CTL_A2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define CTL_A2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define CTL_A2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define CTL_A2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set AMP_PWR aliases
#define AMP_PWR_TRIS                 TRISAbits.TRISA3
#define AMP_PWR_LAT                  LATAbits.LATA3
#define AMP_PWR_PORT                 PORTAbits.RA3
#define AMP_PWR_WPU                  WPUAbits.WPUA3
#define AMP_PWR_ANS                  ANSELAbits.ANSA3
#define AMP_PWR_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define AMP_PWR_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define AMP_PWR_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define AMP_PWR_GetValue()           PORTAbits.RA3
#define AMP_PWR_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define AMP_PWR_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define AMP_PWR_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define AMP_PWR_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define AMP_PWR_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define AMP_PWR_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set AMP_OE aliases
#define AMP_OE_TRIS                 TRISAbits.TRISA4
#define AMP_OE_LAT                  LATAbits.LATA4
#define AMP_OE_PORT                 PORTAbits.RA4
#define AMP_OE_WPU                  WPUAbits.WPUA4
#define AMP_OE_ANS                  ANSELAbits.ANSA4
#define AMP_OE_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define AMP_OE_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define AMP_OE_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define AMP_OE_GetValue()           PORTAbits.RA4
#define AMP_OE_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define AMP_OE_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define AMP_OE_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define AMP_OE_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define AMP_OE_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define AMP_OE_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set D0 aliases
#define D0_TRIS                 TRISBbits.TRISB0
#define D0_LAT                  LATBbits.LATB0
#define D0_PORT                 PORTBbits.RB0
#define D0_WPU                  WPUBbits.WPUB0
#define D0_ANS                  ANSELBbits.ANSB0
#define D0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define D0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define D0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define D0_GetValue()           PORTBbits.RB0
#define D0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define D0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define D0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define D0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define D0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define D0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set D1 aliases
#define D1_TRIS                 TRISBbits.TRISB1
#define D1_LAT                  LATBbits.LATB1
#define D1_PORT                 PORTBbits.RB1
#define D1_WPU                  WPUBbits.WPUB1
#define D1_ANS                  ANSELBbits.ANSB1
#define D1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define D1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define D1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define D1_GetValue()           PORTBbits.RB1
#define D1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define D1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define D1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define D1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define D1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define D1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set D2 aliases
#define D2_TRIS                 TRISBbits.TRISB2
#define D2_LAT                  LATBbits.LATB2
#define D2_PORT                 PORTBbits.RB2
#define D2_WPU                  WPUBbits.WPUB2
#define D2_ANS                  ANSELBbits.ANSB2
#define D2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define D2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define D2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define D2_GetValue()           PORTBbits.RB2
#define D2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define D2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define D2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define D2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define D2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define D2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set D3 aliases
#define D3_TRIS                 TRISBbits.TRISB3
#define D3_LAT                  LATBbits.LATB3
#define D3_PORT                 PORTBbits.RB3
#define D3_WPU                  WPUBbits.WPUB3
#define D3_ANS                  ANSELBbits.ANSB3
#define D3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define D3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define D3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define D3_GetValue()           PORTBbits.RB3
#define D3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define D3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define D3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define D3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define D3_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define D3_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISBbits.TRISB4
#define D4_LAT                  LATBbits.LATB4
#define D4_PORT                 PORTBbits.RB4
#define D4_WPU                  WPUBbits.WPUB4
#define D4_ANS                  ANSELBbits.ANSB4
#define D4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define D4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define D4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define D4_GetValue()           PORTBbits.RB4
#define D4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define D4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define D4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define D4_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISBbits.TRISB5
#define D5_LAT                  LATBbits.LATB5
#define D5_PORT                 PORTBbits.RB5
#define D5_WPU                  WPUBbits.WPUB5
#define D5_ANS                  ANSELBbits.ANSB5
#define D5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define D5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define D5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define D5_GetValue()           PORTBbits.RB5
#define D5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define D5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define D5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define D5_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define D5_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISBbits.TRISB6
#define D6_LAT                  LATBbits.LATB6
#define D6_PORT                 PORTBbits.RB6
#define D6_WPU                  WPUBbits.WPUB6
#define D6_ANS                  ANSELBbits.ANSB6
#define D6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define D6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define D6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define D6_GetValue()           PORTBbits.RB6
#define D6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define D6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define D6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define D6_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISBbits.TRISB7
#define D7_LAT                  LATBbits.LATB7
#define D7_PORT                 PORTBbits.RB7
#define D7_WPU                  WPUBbits.WPUB7
#define D7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define D7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define D7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define D7_GetValue()           PORTBbits.RB7
#define D7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define D7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define D7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)

// get/set CTL_DATA aliases
#define CTL_DATA_TRIS                 TRISCbits.TRISC0
#define CTL_DATA_LAT                  LATCbits.LATC0
#define CTL_DATA_PORT                 PORTCbits.RC0
#define CTL_DATA_WPU                  WPUCbits.WPUC0
#define CTL_DATA_ANS                  ANSELCbits.ANSC0
#define CTL_DATA_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define CTL_DATA_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define CTL_DATA_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define CTL_DATA_GetValue()           PORTCbits.RC0
#define CTL_DATA_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define CTL_DATA_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define CTL_DATA_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define CTL_DATA_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define CTL_DATA_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define CTL_DATA_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set DPY_CS aliases
#define DPY_CS_TRIS                 TRISCbits.TRISC1
#define DPY_CS_LAT                  LATCbits.LATC1
#define DPY_CS_PORT                 PORTCbits.RC1
#define DPY_CS_WPU                  WPUCbits.WPUC1
#define DPY_CS_ANS                  ANSELCbits.ANSC1
#define DPY_CS_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define DPY_CS_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define DPY_CS_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define DPY_CS_GetValue()           PORTCbits.RC1
#define DPY_CS_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define DPY_CS_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define DPY_CS_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define DPY_CS_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define DPY_CS_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define DPY_CS_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set OPLL_CS aliases
#define OPLL_CS_TRIS                 TRISCbits.TRISC2
#define OPLL_CS_LAT                  LATCbits.LATC2
#define OPLL_CS_PORT                 PORTCbits.RC2
#define OPLL_CS_WPU                  WPUCbits.WPUC2
#define OPLL_CS_ANS                  ANSELCbits.ANSC2
#define OPLL_CS_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define OPLL_CS_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define OPLL_CS_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define OPLL_CS_GetValue()           PORTCbits.RC2
#define OPLL_CS_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define OPLL_CS_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define OPLL_CS_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define OPLL_CS_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define OPLL_CS_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define OPLL_CS_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set OPLL_IC aliases
#define OPLL_IC_TRIS                 TRISCbits.TRISC3
#define OPLL_IC_LAT                  LATCbits.LATC3
#define OPLL_IC_PORT                 PORTCbits.RC3
#define OPLL_IC_WPU                  WPUCbits.WPUC3
#define OPLL_IC_ANS                  ANSELCbits.ANSC3
#define OPLL_IC_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define OPLL_IC_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define OPLL_IC_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define OPLL_IC_GetValue()           PORTCbits.RC3
#define OPLL_IC_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define OPLL_IC_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define OPLL_IC_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define OPLL_IC_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define OPLL_IC_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define OPLL_IC_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set OPLL_A0 aliases
#define OPLL_A0_TRIS                 TRISCbits.TRISC4
#define OPLL_A0_LAT                  LATCbits.LATC4
#define OPLL_A0_PORT                 PORTCbits.RC4
#define OPLL_A0_WPU                  WPUCbits.WPUC4
#define OPLL_A0_ANS                  ANSELCbits.ANSC4
#define OPLL_A0_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define OPLL_A0_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define OPLL_A0_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define OPLL_A0_GetValue()           PORTCbits.RC4
#define OPLL_A0_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define OPLL_A0_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define OPLL_A0_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define OPLL_A0_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define OPLL_A0_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define OPLL_A0_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set OPLL_WE aliases
#define OPLL_WE_TRIS                 TRISCbits.TRISC5
#define OPLL_WE_LAT                  LATCbits.LATC5
#define OPLL_WE_PORT                 PORTCbits.RC5
#define OPLL_WE_WPU                  WPUCbits.WPUC5
#define OPLL_WE_ANS                  ANSELCbits.ANSC5
#define OPLL_WE_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define OPLL_WE_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define OPLL_WE_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define OPLL_WE_GetValue()           PORTCbits.RC5
#define OPLL_WE_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define OPLL_WE_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define OPLL_WE_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define OPLL_WE_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define OPLL_WE_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define OPLL_WE_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()               do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()                do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()                do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()       do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()      do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()               do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()                do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()                do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()       do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()      do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/