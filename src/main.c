/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include <stdio.h>
#include "dht11.h"
#include "Utility.h"

struct DHT11_Dev dev;
/*struct __FILE { int handle; };
FILE __stdout;
FILE __stdin;*/
volatile uint32_t msTicks;                      /* counts 1ms timeTicks       */

/*----------------------------------------------------------------------------
SysTick_Handler
*----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
msTicks++;
}

/*----------------------------------------------------------------------------
delays number of tick Systicks (happens every 1 ms)
*----------------------------------------------------------------------------*/
void Delay (uint32_t dlyTicks) {
uint32_t curTicks;

curTicks = msTicks;
while ((msTicks - curTicks) < dlyTicks);
}


/*----------------------------------------------------------------------------
Main function
*----------------------------------------------------------------------------*/
int main (void) {

Configure_Clock();
Delay_Start();
USART1_Init();

SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
if (SysTick_Config(SystemCoreClock / 1000)) { /* SysTick 1 msec interrupts  */
	while (1);                                  /* Capture error              */
}

RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

//printf("startup...\n");
DHT11_init(&dev, GPIOB, GPIO_Pin_6);

while(1) {
	int res = DHT11_read(&dev);
	if(res == DHT11_ERROR_CHECKSUM) {
		printf("ERROR\n");
	}
	else if(res == DHT11_SUCCESS) {
		printf("dht11 success\n");
		printf("T %d - H %d\n", dev.temparature, dev.humidity);
	}
	else {
		printf("TIMEOUT\n");
	}

	Delay_ms(2000);
}
}
