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
#include "Utility.h"
#include <stdio.h>    //necessário para usar printf
#include "sounddata.h"

void aula1(void);
void aula2(void);
void Configure_ADC(void);
void aula3(void);

void q1(void);
void q2(void);
void q3(void);
void q4(void);
void q5(void);
void apitando(void);
void apitando2(void);
void led1(void);
void led2(void);
void apagled1(void);
void apagled2(void);

int main()
{
	q2();
}

void led1(void){
	Utility_Init();
		//habilita o clock do GPIOA
		RCC->AHB1ENR |=1;
		//fazer o pino PA6 ser uma saída
		GPIOA-> MODER |= 0b01 << 12;

					GPIOA->ODR |= 1<<6;
					GPIOA->ODR &= ~(1<<6);
					//Delay_ms(250);

	}

void apagled1(void){
	Utility_Init();
		//habilita o clock do GPIOA
		RCC->AHB1ENR |=1;
		//fazer o pino PA6 ser uma saída
		GPIOA-> MODER |= 0b01 << 12;

					GPIOA->ODR |= 1<<6;
					//Delay_ms(250);

	}

void led2(void){
	Utility_Init();
		//habilita o clock do GPIOA
		RCC->AHB1ENR |=1;
		//fazer o pino PA6 ser uma saída
		GPIOA -> MODER |= 0b01 << 14;

					GPIOA->ODR |= 1<<7;
					GPIOA->ODR &= ~(1<<7);
					//Delay_ms(250);

	}

void apagled2(void){
	Utility_Init();
		//habilita o clock do GPIOA
		RCC->AHB1ENR |=1;
		//fazer o pino PA6 ser uma saída
		GPIOA -> MODER |= 0b01 << 14;

					GPIOA->ODR |= 1<<7;
					//Delay_ms(250);

	}

void apitando(void){
	Utility_Init(); // Inicia a Biblioteca Utility
		//HABILITA O CLOCK DO GPIOA
		RCC->AHB1ENR |= 0b0011;

		//HABILITA O CLOCK DO GPIOE
		RCC->AHB1ENR |= 0b10000;

		//HABILITA O CLOCK DO GPIOD
		RCC->AHB1ENR |= 0b1000;

		// Fazer o Pino PA6 ser uma Saída
		//GPIOA-> MODER |= 0b01 << 12;
		//GPIOA-> MODER |= 0b01 << 14;

		// Fazer o Pino PE4 ser uma Saída
		GPIOE-> MODER |= 0b01 << 8;

		// Fazer o Pino PD3 ser uma Saída
		GPIOD-> MODER |= 0b01 << 6;


	GPIOD->ODR |= 1<<3;
	Delay_ms(50);
}

void apitando2(void){
	Utility_Init(); // Inicia a Biblioteca Utility
		//HABILITA O CLOCK DO GPIOA
		RCC->AHB1ENR |= 0b0011;

		//HABILITA O CLOCK DO GPIOE
		RCC->AHB1ENR |= 0b10000;

		//HABILITA O CLOCK DO GPIOD
		RCC->AHB1ENR |= 0b1000;

		// Fazer o Pino PA6 ser uma Saída
		//GPIOA-> MODER |= 0b01 << 12;
		//GPIOA-> MODER |= 0b01 << 14;

		// Fazer o Pino PE4 ser uma Saída
		GPIOE-> MODER |= 0b01 << 8;

		// Fazer o Pino PD3 ser uma Saída
		GPIOD-> MODER |= 0b01 << 6;


	GPIOD->ODR &= ~(1<<3);
	Delay_ms(50);
}

void aula1(void){
    Utility_Init();
    USART1_Init();        //função que permite usar o printf no STM32

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;    //habilita o clock do GPIOA
    GPIOA->MODER |= 0b11;                    //pino PA0 como entrada analógica
    GPIOA->MODER |= 0b01 <<12;                //configura PA6 como saída
    GPIOA->MODER |= 0b01 <<14;

    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;        //liga o clock do ADC1
    ADC->CCR |= 0b01 << 16;                 //prescaler /4 (fADC=21MHz)
    ADC1->SQR1 &= ~(0xF << 20);             //conversão de apenas um canal
    ADC1->SQR3 &= ~(0x1F);                     //seleção do canal a ser convertido (IN_0)
    ADC1->CR2 |= 1;                         //liga o conversor AD

    while(1)
    {
        ADC1->CR2 |= 1 << 30;             //inicia a conversão
        while(!(ADC1->SR & 0x02));         //aguarda o fim da conversão
        uint16_t leitura = ADC1->DR;     //faz a leitura do valor convertido
        printf("Leitura = %d\n", leitura);


        if (leitura < 1808) {
        	GPIOA->ODR |= (1<<7);
        	GPIOA->ODR |= (1<<6);
            Delay_us(leitura);
            GPIOA->ODR &= ~(1<<6);
            Delay_us(2048-leitura);
        }
        else{
            GPIOA->ODR |= (1<<6);
        }


        if (leitura > 3000) {
        	leitura = leitura - 2048;
        	GPIOA->ODR |= (1<<6);
        	GPIOA->ODR &= ~(1<<7);
            Delay_us(leitura);
            GPIOA->ODR |= (1<<7);
            Delay_us(2048-leitura);
        }
        else{
            GPIOA->ODR |= (1<<7);
        }
    }
}

void aula2(void){
    Utility_Init();
    USART1_Init();        //função que permite usar o printf no STM32

    while(1){
    	printf("teste\n");
    	Delay_ms(500);
    }
}

/*
void Configure_ADC(void){
    Utility_Init();
    USART1_Init();        //função que permite usar o printf no STM32

	RCC->AHB1ENR |= 1; //habilita o clock do GPIOA
	GPIOA->MODER |= 0b11; //pino PA0 como entrada analógica
	RCC->APB2ENR |= 1 << 8; //liga o clock da interface digital do ADC1
	ADC->CCR |= 0b01 << 16; //prescaler /4 (fADC=21MHz)
	ADC1->SQR1 &= ~(0xF << 20); //conversão de apenas um canal
	ADC1->SQR3 &= ~(0x1F); //seleção do canal a ser convertido (IN_0)
	ADC1->CR2 |= 1; //liga o conversor AD

	while(1){
	ADC1->CR2 |= 1 << 30; //inicia a conversão
	while(!(ADC1->SR & 0x02)); //aguarda o fim da conversão
	uint16_t leitura = ADC1->DR; //faz a leitura do valor convertido
	printf("%.2f\n", ((float)leitura/4095)*3.3);
	Delay_ms(100);
	}
}*/

void aula3(void)
{
    Configure_Clock();            //configura o sistema de clock
    USART1_Init();                //inicializa a USART1
    Delay_Start();                //inicializa funções de Delay

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;    //habilita o clock do GPIOA
    GPIOA->MODER |= 0b11;                    //pino PA0 como entrada analógica
    GPIOA->MODER |= 0b11 << 2;                //pino PA1 como entrada analógica
    GPIOA->MODER |= 0b01 <<12;                //configura PA6 como saída
    GPIOA->MODER |= 0b01 <<14;

    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;        //liga o clock do ADC1

    ADC->CCR |= 0b01 << 16;            //prescaler /4
    ADC1->SQR1 = 1 << 20;            //conversão de dois canais
    ADC1->SQR3 = (0 << 0)|(1 << 5);    //canais IN_0 e IN_1 (PA0 e PA1)
    ADC1->CR1 = ADC_CR1_SCAN;        //habilita o modo scan
    ADC1->CR2 = ADC_CR2_EOCS;        //sinal EOC ao fim de cada conversão
    ADC1->CR2 |= ADC_CR2_ADON;    //liga o conversor AD

    while(1)
    {
        ADC1->CR2 |= ADC_CR2_SWSTART;        //inicia a conversão
        while(!(ADC1->SR & ADC_SR_EOC));    //aguarda o fim da primeira conversão
        uint16_t leitura1 = ADC1->DR;        //faz a leitura do valor convertido
        while(!(ADC1->SR & ADC_SR_EOC));    //aguarda o fim da segunda conversão
        uint16_t leitura2 = ADC1->DR;        //faz a leitura do valor convertido

        printf("Valor PA0 = %d\nValor PA1 = %d\n\n", leitura1, leitura2);            //imprime o valor convertido no monitor
        //Delay_ms(200);                        //aguarda 200ms para fazer a nova leitura


		GPIOA->ODR &= ~(1<<7);
		Delay_us(leitura1);
		GPIOA->ODR |= (1<<7);
		Delay_us(4095-leitura1);


		GPIOA->ODR &= ~(1<<6);
		Delay_us(leitura2);
		GPIOA->ODR |= (1<<6);
		Delay_us(4095-leitura2);
   }

}

void q1(void){
	Configure_Clock();			//configura o sistema de clock
		Delay_Start();				//inicializa funções de Delay

		RCC->AHB1ENR |= 1;	//habilita o clock do GPIOA
		GPIOA->MODER |= 0b11 << 8;				//inicialização do pino PA4 no modo analógico

		RCC->APB1ENR |= RCC_APB1ENR_DACEN;		//habilita o clock da interface digital do DAC
		DAC->CR |= DAC_CR_EN1;		//habilita o canal 1 do DAC

		int contador = 0;
		while(1)
		{
			for(; contador<4095; contador++)
			{
				DAC->DHR12R1 = contador;	//escreve no DAC1
				Delay_ms(1);						//aguarda para a próxima amostra
			}
			for(; contador>0; contador--)
			{
				DAC->DHR12R1 = contador;	//escreve no DAC1
				Delay_ms(1);						//aguarda para a próxima amostra
			}
		}
}


void q2(void){
	Configure_Clock(); //configura o sistema de clock
		Delay_Start(); //inicializa funções de Delay

		RCC->AHB1ENR |= 1; //habilita o clock do GPIOA
		GPIOA->MODER |= 0b11 << 10; //inicialização do pino PA5 no modo analógico

		RCC->APB1ENR |= 1 << 29; //habilita o clock da interface digital do DAC
		DAC ->CR |= DAC_CR_BOFF2;
		DAC->CR |= DAC_CR_EN2; //habilita o canal 2 do DAC

	const uint16_t samples[200] = {2482, 2507, 2532, 2557, 2583, 2608, 2633, 2657, 2682, 2706, 2731, 2755, 2778, 2802, 2825, 2847, 2870, 2892, 2913, 2935, 2955, 2976, 2995,
	 3015, 3033, 3052, 3069, 3086, 3103, 3119, 3134, 3148, 3162, 3175, 3188, 3200, 3211, 3221, 3231, 3240, 3248, 3256, 3263, 3268, 3274, 3278, 3282, 3284, 3286, 3288, 3288,
	 3288, 3286, 3284, 3282, 3278, 3274, 3269, 3263, 3256, 3249, 3241, 3232, 3222, 3212, 3200, 3189, 3176, 3163, 3149, 3135, 3119, 3104, 3087, 3070, 3052, 3034, 3016, 2996,
	 2977, 2956, 2936, 2915, 2893, 2871, 2849, 2826, 2803, 2779, 2756, 2732, 2708, 2683, 2659, 2634, 2609, 2584, 2559, 2533, 2508, 2483, 2457, 2432, 2407, 2382, 2357, 2332,
	 2307, 2282, 2258, 2234, 2210, 2186, 2163, 2139, 2117, 2094, 2072, 2051, 2029, 2009, 1988, 1969, 1949, 1931, 1912, 1895, 1878, 1861, 1845, 1830, 1815, 1801, 1788, 1776,
	 1764, 1753, 1742, 1732, 1723, 1715, 1708, 1701, 1695, 1690, 1685, 1682, 1679, 1677, 1675, 1675, 1675, 1676, 1678, 1681, 1685, 1689, 1694, 1700, 1706, 1714, 1722, 1731,
	 1741, 1751, 1762, 1774, 1786, 1799, 1813, 1828, 1843, 1859, 1875, 1892, 1910, 1928, 1946, 1966, 1985, 2006, 2026, 2047, 2069, 2091, 2113, 2136, 2159, 2182, 2206, 2230,
	 2254, 2279, 2303, 2328, 2353, 2378, 2403, 2428, 2454};

	while(1){
			for(int i = 0; i < 200; i++){
				DAC -> DHR12R2 = samples[i]; //Escreve no DAC2
				Delay_us(7); //aguarda para a próxima amostra
			}
		}
	}


void q3(void){
	Configure_Clock();	//configura o sistema de clock
	Delay_Start();		//inicializa funções de Delay

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	//habilita o clock do GPIOA
	GPIOA->MODER |= 0b11 << 8;				//inicialização do pino PA4 no modo analógico

	RCC->APB1ENR |= RCC_APB1ENR_DACEN;	//habilita o clock da interface digital do DAC
	DAC->CR |= DAC_CR_EN1;				//habilita o canal 1 do DAC

	while(1)
	{
		for(uint32_t contador=0; contador<sizeof(sound); ++contador)
		{
			DAC->DHR8R1 = sound[contador];	//escreve no DAC1
			Delay_us(120);					//aguarda a próxima amostra
		}
	}
}

void q4(void){
	Configure_Clock();			//configura o sistema de clock
	USART1_Init();				//inicializa a USART1
	Delay_Start();				//inicializa funções de Delay

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	//habilita o clock do GPIOA
	GPIOA->MODER |= 0b11;					//pino PA0 como entrada analógica
	GPIOA->MODER |= 0b11 << 2;				//pino PA1 como entrada analogica
	GPIOA->MODER |= 0b01 << 4;				//pino PA2 como saida
	GPIOA->MODER |= 0b01 << 6;				//pino PA3 como saida

	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;		//liga o clock do ADC1

	ADC->CCR |= 0b01 << 16;		//prescaler /4
	ADC1->SQR1 &= ~(0xF << 20);	//conversão de apenas um canal
	ADC1->SQR3 &= ~(0x1F);		//seleção do canal a ser convertido (IN_0)
	ADC1->CR2 |= ADC_CR2_ADON;	//liga o conversor AD

	while(1)
	{
		ADC1->SQR3 &= ~(0x1F);		//seleção do canal a ser convertido (IN_0)
		ADC1->CR2 |= ADC_CR2_SWSTART;		//inicia a conversão
		while(!(ADC1->SR & ADC_SR_EOC));	//aguarda o fim da conversão
		uint16_t leitura = ADC1->DR;		//faz a leitura do valor convertido

		uint16_t grau = (0.43 * leitura) + 600;
		GPIOA->ODR |= (1 << 2);
		Delay_us(grau);
		GPIOA->ODR &= ~ (1 << 2);
		Delay_us(20000 - grau);

		ADC1->SQR3 |= 0x1;
		ADC1->CR2 |= ADC_CR2_SWSTART;		//inicia a conversão
		while(!(ADC1->SR & ADC_SR_EOC));	//aguarda o fim da conversão
		uint16_t leitura1 = ADC1->DR;		//faz a leitura do valor convertido

		uint16_t grau1 = (0.43 * leitura1) + 600;
		GPIOA->ODR |= (1 << 3);
		Delay_us(grau1);
		GPIOA->ODR &= ~ (1 << 3);
		Delay_us(20000 - grau1);
	}
}

void q5(void){
	Configure_Clock();			//configura o sistema de clock
	USART1_Init();				//inicializa a USART1
	Delay_Start();				//inicializa funções de Delay

	RCC-> APB2ENR |= RCC_APB2ENR_ADC1EN;

	ADC->CCR |= 0b01 << 16;		//prescaler /4
	ADC1->SQR1 &= ~(0xF << 20);	//conversão de apenas um canal
	ADC1->SQR3 |= 16;           // Selecao canal a ser convertido (IN_16)
	ADC1->SMPR1 |= (7 << 18);   // Tempo de amostragem igual a 480 ciclos de ADC
	ADC->CCR |= ADC_CCR_TSVREFE; //Liga sensor de temperatura
	ADC1->CR2 |= ADC_CR2_ADON;   // Liga o conversor AD

	uint32_t *p = (uint32_t *) 0x1FFF7A2C; //Cria ponteiro para uma posicao
	uint32_t Word = p[0];                  //Ler o valor contido na memoria
	uint16_t TS_CAL1 = (Word & 0x0000FFFF); //Ler o valor de TS_CAL1
	uint16_t TS_CAL2 = (Word & 0xFFFF0000) >> 16; //Ler o valor de TS_CAL2

	while(1){
		uint32_t leitura = 0;
		for(int cont=0; cont<50; ++cont){
			ADC1-> CR2 |= ADC_CR2_SWSTART;
			while(!(ADC1-> SR & ADC_SR_EOC));
			leitura += ADC1->DR;
		}
		uint8_t temperatura = ((80*((leitura/50) - TS_CAL1))/(TS_CAL2-TS_CAL1)) + 30;
		printf("Temperatura = %d \n", temperatura);

		Delay_ms(500);

		 if (temperatura <= 45){
			 apagled1();
			 printf("\nTemperatura dentro da faixa de segura de operacao \n");
		 }
		 else if  (temperatura <= 55){
			 led1();
			 apitando2();
			 apagled2();
			 printf("\nTemperarura dentro da faixa de atenção \n");

		 }
		 else{
			 apitando();
			 led1();
			 led2();
			 printf("\nTemperatura dentro da faixa de superaquecimento \n");
		 }
	}
}


