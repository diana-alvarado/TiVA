//**************************************************************************************************************
//Laboratorio 5
//Diana Alvarado
//20525

//**************************************************************************************************************
// Librerias para que funcione
//**************************************************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"


//**************************************************************************************************************
// Variables
//**************************************************************************************************************
uint32_t i = 0;
uint32_t b = 0;

//**************************************************************************************************************
// Prototipos de Funciones
//**************************************************************************************************************
void delayms(uint32_t msec);
void delay1ms(void);

//**************************************************************************************************************
// Loop Principal
//**************************************************************************************************************
int main(void)
{
    // Setear el oscilador externo de 16MHz
    SysCtlClockSet(
            SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN
                    | SYSCTL_XTAL_16MHZ);  //16MHz


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

//Salidas

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,
                          GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
//Entradas

    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);

    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
   //**********************************************************************************************************
   // Loop Principal

   while (1)
    {
       //Antirebote
       if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) == 0){
           b = 1;
       }

       if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) && anti == 1){

           b = 0;

           //Verde
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_3);
           delay(1000);

           //Parpadea
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
           delay(500);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_3);
           delay(500);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
           delay(500);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_3);
           delay(500);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
           delay(500);
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_3);
           delay(500);

           //Amarillo
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                        GPIO_PIN_3 | GPIO_PIN_1 );
           delay(1000);

            //Rojo
           GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                        GPIO_PIN_1 );
           delay(1000);


        }


    }
}

//Delay de milis

void delayms(uint32_t msec)
{
    for (i = 0; i < msec; i++) //Para que pueda funcionar los ms que se necesite
    {
        delay1ms();
    }

}

//Delay de un 1 mili

void delay1ms(void)
{
    SysTickDisable();
    SysTickPeriodSet(16000-1);
    SysTickEnable();

    while ((NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT) == 0); //Pg. 138

}


