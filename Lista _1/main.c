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
#include <stdlib.h>
#include <time.h>

#define K0  !(GPIOE -> IDR & (1<<4))
#define K1  !(GPIOE -> IDR & (1<<3))

#define PA6_OFF GPIOA -> ODR |= (1 << 6)
#define PA6_ON GPIOA -> ODR &=  ~(1 << 6)

#define PA7_OFF GPIOA -> ODR |= (1 << 7)
#define PA7_ON GPIOA -> ODR &=  ~(1 << 7)

void atraso(int atraso);
void pisca_lento(void);
void pisca_PE5(void);
void pisca_2leds(void);
void pisca_igual(void);
void apita(void);
void ler_botao(void);
void dois_botoes(void);
void teste_botao(void);

void q1(void);
void q2(void);
void q3(void);
void q4(void);
void q5(void);

void q7(void);

void q9(void);
void q11(void);
void q12(void);
void q13(void);
void q14(void);
void q15(void);
void q17(void);
void q18(void);

void q23(void);
void q25(void);
void q26(void);
void q27(void);
void q30(void);




int main(void)
{
	pisca_lento();
}


void pisca_lento(void){
	Utility_Init();
	//habilita o clock do GPIOA
	RCC->AHB1ENR |= 0b0001;
	//fazer o pino PA6 ser uma saída
	GPIOA-> MODER |= 0b01 << 12;
	//fazer o pino PA7 ser uma saída
	GPIOA-> MODER |= 0b01 << 14;

	int ligado = 1;

	while(1){
		if(ligado){
			int j = 1000;
			for(int i=0; i<=1000; i++){
				GPIOA->ODR |= 1<<6;
				GPIOA->ODR |= 1<<7;
				Delay_us(i);

				GPIOA->ODR &= ~(1<<6);
				GPIOA->ODR &= ~(1<<7);
				Delay_us(j--);
			}
			ligado = 0;
		}
		else{
			int j = 0;
			for(int i=1000; i>=0; i--){
				GPIOA->ODR |= 1<<6;
				GPIOA->ODR |= 1<<7;
				Delay_us(i);

				GPIOA->ODR &= ~(1<<6);
				GPIOA->ODR &= ~(1<<7);
				Delay_us(j++);
			}
			ligado = 1;
		}
	}
}

void pisca_PE5(void){
	Utility_Init();

	//porta PE5
	RCC -> AHB1ENR |= (1 << 4) | 1;

	GPIOE -> MODER |= 0B01 << 10;

	GPIOA -> MODER |= 0b01 << 12;
	GPIOA -> MODER |= 0b01 << 14;

	while(1){
		GPIOE -> ODR |= 1 << 5;
		Delay_ms(1000);
		GPIOE -> ODR &= ~(1 << 5);
		Delay_ms(1000);

		GPIOA -> ODR &= ~(1 << 6);
		Delay_ms(500);
		GPIOA -> ODR |= 1 << 6;
		Delay_ms(500);

		GPIOA -> ODR &= ~(1 << 7);
		Delay_ms(500);
		GPIOA -> ODR |= 1 << 7;
		Delay_ms(500);
	}
}

void pisca_2leds(void){
	Utility_Init();
	//PE0, PE5
	//RCC -> AHB1ENR |= (1 << 4) | 1;
	RCC -> AHB1ENR |= 0b00011;

	GPIOA -> MODER |= 0B01 << 4; // 2
	GPIOB -> MODER |= 0B01 << 6; //3
	GPIOB -> MODER &= ~(0B1 << 7); //3

	while(1){

		GPIOA -> ODR &= ~ 1 << 2;
		GPIOB -> ODR |= 1 << 3;
		Delay_ms(500);

		GPIOA -> ODR |= 1 << 2;
		GPIOB -> ODR &= ~ (1 << 3);
		Delay_ms(500);

		GPIOA -> ODR &= ~ 1 << 2;
		Delay_ms(500);
		GPIOA -> ODR |= 1 << 2;
		GPIOB -> ODR |= 1 << 3;
		Delay_ms(500);




		//GPIOB -> ODR |= 1 << 3;
		//Delay_ms(500);
		//GPIOB -> ODR &= ~ (1 << 3);
		//Delay_ms(500);
	}
}

void pisca_igual(void){
	Utility_Init();
		//PE0, PE5
		//RCC -> AHB1ENR |= (1 << 4) | 1;
		RCC -> AHB1ENR |= 0b00011;

		GPIOA -> MODER |= 0B01 << 4; // 2
		GPIOB -> MODER |= 0B01 << 6; //3
		GPIOB -> MODER &= ~(0B1 << 7); //3

		while(1){
		Delay_ms(500);
		GPIOA -> ODR |= 1 << 2;
		GPIOB -> ODR |= 1 << 3;
		Delay_ms(500);

		Delay_ms(500);
		GPIOA -> ODR &= ~ 1 << 2;
		GPIOB -> ODR &= ~ (1 << 3);
		Delay_ms(500);
		}
}

void apita(void){
	Utility_Init();

		RCC -> AHB1ENR |= 0b00001;

		GPIOA -> MODER |= 0B01 << 4; // 2


		while(1){
		GPIOA -> ODR |= 1 << 2;
		Delay_ms(50);
		GPIOA -> ODR &= ~ 1 << 2;
		Delay_ms(50);
		GPIOA -> ODR |= 1 << 2;
		Delay_ms(50);
		GPIOA -> ODR &= ~ 1 << 2;
		Delay_ms(50);
		GPIOA -> ODR |= 1 << 2;
		Delay_ms(50);
		GPIOA -> ODR &= ~ 1 << 2;
		Delay_ms(50);
		GPIOA -> ODR |= 1 << 2;
		Delay_ms(50);
		GPIOA -> ODR &= ~ 1 << 2;
		Delay_ms(500);
		}
}

void ler_botao(void){
	Utility_Init();


	//LIGA CLOCK DA PORTA E e A
	RCC -> AHB1ENR |= 0b10001;

	//configura pe4 como entrada
	GPIOE -> MODER &= ~(0b11 << 8);
	//Ligando o resistor de pull-up no pino pe4
	GPIOE -> PUPDR |= (0b01 << 8);

	//configura pe3 como entrada
	GPIOE -> MODER &= ~(0b11 << 6);
	//Ligando o resistor de pull-up no pino pe3
	GPIOE -> PUPDR |= (0b01 << 6);

    GPIOA->MODER &= ~(0b00 << 0);    //configurando o pino PA0 como entrada (botão k_up)
    GPIOA->PUPDR |= (0b10 << 0);     //liga o resistor de pull-down no pino PA0 (pra garantir nível alto quando a chave estiver solta)

	//configura pa6 como saida
	GPIOA -> MODER |= 0b01 << 12;
	//configura pa7 como saida
	GPIOA -> MODER |= 0b01 << 14;

	while(1){
	//FAZENDO A LEITURA DO REGISTRADOR IDR (A LEITURA DOS PINOS)
	int leitura = GPIOE -> IDR;

	//Testando se o pino tem nível alto ou baixo
	if (!(leitura &(1 << 4)))
		//Liga o led se nivel alto no pino
		GPIOA -> ODR &= ~(1<<6);
	else
		//Desliga o led se nível baixo
		GPIOA -> ODR |= (1<<6);

	//Testando se o pino tem nível alto ou baixo
	if (!(leitura &(1 << 3)))
		//Liga o led se nivel alto no pino
		GPIOA -> ODR &= ~(1<<7);
	else
		//Desliga o led se
		GPIOA -> ODR |= (1<<7);

	if(GPIOA->IDR & (1)){
		GPIOA -> ODR &= ~(1<<6);
		GPIOA -> ODR &= ~(1<<7);}
	else{
		GPIOA -> ODR |= (1<<6);
		GPIOA -> ODR |= (1<<7);
	}
	}
}

void dois_botoes(void){
	Utility_Init();

	//LIGA CLOCK DA PORTA E e A
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOEEN | RCC_AHB1ENR_GPIOAEN;

	//configura pa6 como saida
	GPIOA -> MODER |= 0b01 << 12;

	//configura pe4 como entrada
	GPIOE -> MODER &= ~(0b11 << 8);

	//Ligando o resistor de pull-up no pino pe4
	GPIOE -> PUPDR |= (0b01 << 8);

	//configura pe3 como entrada
	GPIOE -> MODER &= ~(0b11 << 6);
	//Ligando o resistor de pull-up no pino pe3
	GPIOE -> PUPDR |= (0b01 << 6);

	//configura pa7 como saida
	GPIOA -> MODER |= 0b01 << 14;

	while(1){
	//FAZENDO A LEITURA DO REGISTRADOR IDR (A LEITURA DOS PINOS)
	int leitura = GPIOE -> IDR;

	//Testando se o pino tem nível alto ou baixo
	if (!(leitura & (1 << 4)) && !(leitura & (1 << 3))){
		//Liga o led se nivel alto no pino
		GPIOA -> ODR &= ~(1<<6);
		GPIOA -> ODR &= ~(1<<7);}
	else{
		//Desliga o led se nível baixo
		GPIOA -> ODR |= (1<<6);
		GPIOA -> ODR |= (1<<7);}

	}
}

void teste_botao(void){
	Utility_Init();

	RCC -> AHB1ENR |= (1 | (1<<4)); //liga clock das portas A e E

	GPIOA -> MODER |= 0b01 << 12;  //Pino PA6 como saída
	GPIOE -> MODER &= ~(0b11 << 8); //Pino PE4 como entrada
	GPIOE -> MODER &= ~(0b11 << 6); //Pino PE3 como entrada
	GPIOE -> PUPDR |= 0b01 << 8; //Liga pull-up em PE4
	GPIOE -> PUPDR |= 0b01 << 6; //Liga pull-up em PE3

	while(1){

		while(K0 && !K1)
		{
			GPIOA -> ODR |= (1<<6);
			while(K0 && K1)
				GPIOA -> ODR &= ~(1<<6);
		}
		GPIOA -> ODR |= (1<<6);
	}
}

void q1(void){
	Utility_Init();
		//habilita o clock do GPIOA
		RCC->AHB1ENR |=1;
		//fazer o pino PA6 ser uma saída
		GPIOA-> MODER |= 0b01 << 12;

		while(1){
					GPIOA->ODR |= 1<<6;
					Delay_ms(250);
					GPIOA->ODR &= ~(1<<6);
					Delay_ms(250);
		}
	}

void q2(void){
	Utility_Init();
		//habilita o clock do GPIOA
		RCC->AHB1ENR |=1;
		//fazer o pino PA6 ser uma saída
		GPIOA-> MODER |= 0b01 << 12;

		while(1){
					GPIOA->ODR |= 1<<6;
					Delay_ms(2000);
					GPIOA->ODR &= ~(1<<6);
					Delay_ms(150);
		}
	}

void q3(void){
	Utility_Init();
		//habilita o clock do GPIOA
		RCC->AHB1ENR |=1;
		//fazer o pino PA6 ser uma saída
		GPIOA-> MODER |= 0b01 << 12;

		while(1){
			GPIOA->ODR &= ~(1<<6);
			Delay_ms(50);
			GPIOA->ODR |= 1<<6;
			Delay_ms(2000);

			GPIOA->ODR &= ~(1<<6);
			Delay_ms(50);
			GPIOA->ODR |= 1<<6;
			Delay_ms(1000);
			GPIOA->ODR &= ~(1<<6);
			Delay_ms(50);
			GPIOA->ODR |= 1<<6;
			Delay_ms(50);

		}
}

void q4(void){
	   Utility_Init();
	    // Habilita o clock do GPIOA
	    RCC->AHB1ENR |= 1;
	    // Fazer o pino PA6 ser uma saída
	    GPIOA->MODER |= 0b01 << 12;

	    uint32_t delay_ms = 1000; // Inicializa o tempo de delay em 2 segundos

	    int c = 1;
	    while (1) {
	        GPIOA->ODR &= ~(1 << 6);
	        Delay_ms(50);
	        GPIOA->ODR |= 1 << 6;
	        Delay_ms(950 / c);
	        c++;
	    }
}

void q5(void){
	apita();
}

void q7(void){
	Utility_Init();
	//habilita o clock do GPIOA
	RCC->AHB1ENR |=1;
	//fazer o pino PA6 ser uma saída
	GPIOA-> MODER |= 0b01 << 12;
	//fazer o pino PA7 ser uma saída
	GPIOA-> MODER |= 0b01 << 14;


	while(1){
			int tempo = 0;
			while(tempo <=2000)
			{GPIOA->ODR |= 1<<6;		//APAGA O LED
			GPIOA->ODR |= 1<<7;		//APAGA O LED
			Delay_us(tempo);
			GPIOA->ODR &= ~(1<<6);	//ACENDE O LED
			GPIOA->ODR &= ~(1<<7);	//ACENDE O LED
			Delay_us(2000-tempo);
			++tempo;
			}
			tempo =2000;
			while(tempo >=0){
				GPIOA->ODR |= 1<<6;		//APAGA O LED
				GPIOA->ODR |= 1<<7;		//APAGA O LED
				Delay_us(tempo);
				GPIOA->ODR &= ~(1<<6);	//ACENDE O LED
				GPIOA->ODR &= ~(1<<7);	//ACENDE O LED
				Delay_us(2000-tempo);
				--tempo;
		}
	}
}

void q9(void){
	Utility_Init();
	//habilita o clock do GPIOA
	RCC->AHB1ENR |=1;
	//fazer o pino PA6 ser uma saída
	GPIOA-> MODER |= 0b01 << 12;
	//fazer o pino PA7 ser uma saída
	GPIOA-> MODER |= 0b01 << 14;

	while(1){
		GPIOA->ODR |= 1<<6;		//APAGA O LED
		GPIOA->ODR |= 1<<7;		//APAGA O LED
		Delay_ms(250);

		GPIOA->ODR &= ~(1<<6);	//ACENDE O LED
		GPIOA->ODR |= 1<<7;		//APAGA O LED
		Delay_ms(250);

		GPIOA->ODR |= 1<<6;		//APAGA O LED
		GPIOA->ODR &= ~(1<<7);	//ACENDE O LED
		Delay_ms(250);

		GPIOA->ODR &= ~(1<<6);	//ACENDE O LED
		GPIOA->ODR &= ~(1<<7);	//ACENDE O LED
		Delay_ms(250);

	}
}

void q11(){


Utility_Init();
//Ligar o Clock GPIOA
RCC-> AHB1ENR |= 0b1000;


//Acender pino PD0 até PD7
GPIOD -> MODER |= 0b01 << 0;
GPIOD -> MODER |= 0b01 << 2;
GPIOD -> MODER |= 0b01 << 4;
GPIOD -> MODER |= 0b01 << 6;
GPIOD -> MODER |= 0b01 << 8;
GPIOD -> MODER |= 0b01 << 10;
GPIOD -> MODER |= 0b01 << 12;
GPIOD -> MODER |= 0b01 << 14;


while(1){

for(int a = 0; a<2; a++){
	if(a==0){
		GPIOD -> ODR &= ~(1 << 0);
	}
	else{
		GPIOD -> ODR |= 1 << 0; //Acende o led
	}

	Delay_ms(100);

for(int b = 0; b<2; b++){
	if(b==0){
		GPIOD -> ODR &= ~(1 << 1);
	}
	else{
		GPIOD -> ODR |= 1 << 1; //Acende o led
	}
	Delay_ms(100);

for(int c = 0; c<2; c++){
	if(c==0){
		GPIOD -> ODR &= ~(1 << 2);
	}
	else{
		GPIOD -> ODR |= 1 << 2; //Acende o led
	}
	Delay_ms(100);

for(int d = 0; d<2; d++){
	if(d==0){
		GPIOD -> ODR &= ~(1 << 3);
	}
	else{
		GPIOD -> ODR |= 1 << 3; //Acende o led
	}
	Delay_ms(100);

for(int e = 0; e<2; e++){
	if(e==0){
		GPIOD -> ODR &= ~(1 << 4);
	}
	else{
		GPIOD -> ODR |= 1 << 4; //Acende o led
	}
	Delay_ms(100);

for(int f = 0; f<2; f++){
	if(f==0){
		GPIOD -> ODR &= ~(1 << 5);
	}
	else{
		GPIOD -> ODR |= 1 << 5; //Acende o led
	}
	Delay_ms(100);

for(int g = 0; g<2; g++){
	if(g==0){
		GPIOD -> ODR &= ~(1 << 6);
	}
	else{
		GPIOD -> ODR |= 1 << 6; //Acende o led
	}
	Delay_ms(100);

for(int h = 0; h<2; h++){
	if(h==0){
		GPIOD -> ODR &= ~(1 << 7);
	}
	else{
		GPIOD -> ODR |= 1 << 7; //Acende o led
	}
	Delay_ms(100);

}//h
GPIOD -> ODR &= ~(1 << 7);
}//g
GPIOD -> ODR &= ~(1 << 6);
}//f
GPIOD -> ODR &= ~(1 << 5);
}//e
GPIOD -> ODR &= ~(1 << 4);
}//d
GPIOD -> ODR &= ~(1 << 3);
}//c
GPIOD -> ODR &= ~(1 << 2);
}//b
GPIOD -> ODR &= ~(1 << 1);
}//a
GPIOD -> ODR &= ~(1 << 0);
}
}


void q13(){
Utility_Init();
//Ligar o Clock GPIOA
RCC-> AHB1ENR |= 0b1000;


//Acender pino PD0 até PD7
GPIOD -> MODER |= 0b01 << 0; //Vermelho 1
GPIOD -> MODER |= 0b01 << 2;//Amarelo 1
GPIOD -> MODER |= 0b01 << 4;//Verde 1

GPIOD -> MODER |= 0b01 << 8;//Vermelho 2
GPIOD -> MODER |= 0b01 << 10;//Amarelo 2
GPIOD -> MODER |= 0b01 << 12;//Verde 2

while(1){
//Semáforo 1
GPIOD -> ODR |= 1 << 0;
GPIOD -> ODR &= ~(1 << 1);
GPIOD -> ODR &= ~(1 << 2);

GPIOD -> ODR |= 1 << 6; //Acende o led
GPIOD -> ODR &= ~(1 << 5);
GPIOD -> ODR &= ~(1 << 4);
Delay_ms(1000);
//Semáforo 2
GPIOD -> ODR &= ~(1 << 4);
GPIOD -> ODR &= ~(1 << 5);
GPIOD -> ODR |= 1 << 6; //Acende o led
Delay_ms(1000);

GPIOD -> ODR &= ~(1 << 4);
GPIOD -> ODR &= ~(1 << 6);
GPIOD -> ODR |= 1 << 5; //Acende o led
Delay_ms(1000);

//Semáforo 1
GPIOD -> ODR &= ~(1 << 0);
GPIOD -> ODR &= ~(1 << 1);
GPIOD -> ODR |= 1 << 2; //Acende o led
GPIOD -> ODR |= 1 << 4; //Acende o led
GPIOD -> ODR &= ~(1 << 5);
Delay_ms(1000);

GPIOD -> ODR &= ~(1 << 0);
GPIOD -> ODR &= ~(1 << 2);
GPIOD -> ODR |= 1 << 1; //Acende o led
GPIOD -> ODR |= 1 << 4; //Acende o led
Delay_ms(1000);

}
}

void q12(void){
	Utility_Init();
	//Ligar o Clock GPIOA
		RCC-> AHB1ENR |= 0b1000;


		//Acender pino PD0
		GPIOD -> MODER |= 0b01 ;
		//Acender pino PD1
		GPIOD -> MODER |= 0b01 << 2;
		//Acender pino PD2
		GPIOD -> MODER |= 0b01 << 4;
		//Acender pino PD3
		GPIOD -> MODER |= 0b01 << 6;
		//Acender pino PD4
		GPIOD -> MODER |= 0b01 << 8;
		//Acender pino PD5
		GPIOD -> MODER |= 0b01 << 10;
		//Acender pino PD6
		GPIOD -> MODER |= 0b01 << 12;
		//Acender pino PD7
		GPIOD -> MODER |= 0b01 << 14;


		while(1){
		GPIOD -> ODR |= 1 ; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		Delay_ms(100);
		GPIOD -> ODR |= 1 << 1; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		Delay_ms(100);

		GPIOD -> ODR |= 1 << 1; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		Delay_ms(100);

		GPIOD -> ODR |= 1 << 2; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 2); //Desliga o led
		Delay_ms(100);

		GPIOD -> ODR |= 1 << 3; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		Delay_ms(100);

		GPIOD -> ODR |= 1 << 4; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		Delay_ms(100);

		GPIOD -> ODR |= 1 << 5; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		Delay_ms(100);

		GPIOD -> ODR |= 1 << 6; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		Delay_ms(100);

		GPIOD -> ODR |= 1 << 7; //Acende o led
		Delay_ms(100);
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		}
}


void q23(void)
{
	Utility_Init();

    // Habilitar o clock para as portas E e A
    RCC->AHB1ENR |= (1 << 4);
    RCC->AHB1ENR |= 1;

    // Configurar os pinos PE4 e PA5 como entrada e os pinos PA6 e PA7 como saída
    GPIOE->MODER &= ~(0b11 << 8);
    GPIOE->PUPDR |= (0b01 << 8);
    GPIOA->MODER |= (0b01 << 12) | (0b01 << 10);
    GPIOA->MODER &= ~(0b11 << 14);

    // Loop infinito
    while (1) {
        // Verificar se o botão K0 foi pressionado
        if ((GPIOE->IDR & (1 << 4)) == 0) {
            // Esperar um curto intervalo para evitar debounce
            Delay_ms(50);
            // Verificar novamente se o botão K0 continua pressionado
            if ((GPIOE->IDR & (1 << 4)) == 0) {
                // Inverter o estado do LED D2
                GPIOA->ODR ^= (1 << 6);
                // Esperar até que o botão K0 seja liberado
                while ((GPIOE->IDR & (1 << 4)) == 0) {
                    Delay_ms(50);
                }
            }
        }
    }
}

void q25(void){

	Utility_Init();

	RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
		    RCC->AHB1ENR |= 1<<4;    //habilita o clock do GPIOE

		    //configurando PA6 como saída (o pino PA6 tem um LED conectado)
		    GPIOA->MODER |= (0b01 << 12);
		    //configurando PA7 como saída (o pino PA6 tem um LED conectado)
		    GPIOA->MODER |= (0b01 << 14);

		    //Configurando o pino PE3 como entrada
		    GPIOE->MODER &= ~(0b11 << 6);
		    GPIOE->PUPDR |= (0b01 << 6);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto
		    //Configurando o pino PE4 como entrada
		    GPIOE->MODER &= ~(0b11 << 8);
		    GPIOE->PUPDR |= (0b01 << 8);    //habilita o resistor de pull up para garantir nível lógico alto quando o botão estiver solto

		    while(1){
		    	(GPIOA->ODR |= (1 << 6));
		    		(GPIOA->ODR |= (1 << 7));

				if(K0 && !K1){
					uint32_t a = 0;
					while(K0){
						Delay_ms(500);
						if(K1){
							if(a<=1000){
								(GPIOA->ODR &= ~(1 << 6));
										(GPIOA->ODR &= ~(1 << 7));
							}

						}
						else{
							(GPIOA->ODR |= (1 << 6));
						}
						a += 100;
					}
				}
		    }
	}




void q14(void){
	Utility_Init();
	//Ligar o Clock GPIOD
		RCC-> AHB1ENR |= 0b1000;


		//Acender pino PD0
		GPIOD -> MODER |= 0b01 ;
		//Acender pino PD1
		GPIOD -> MODER |= 0b01 << 2;
		//Acender pino PD2
		GPIOD -> MODER |= 0b01 << 4;
		//Acender pino PD3
		GPIOD -> MODER |= 0b01 << 6;
		//Acender pino PD4
		GPIOD -> MODER |= 0b01 << 8;
		//Acender pino PD5
		GPIOD -> MODER |= 0b01 << 10;
		//Acender pino PD6
		GPIOD -> MODER |= 0b01 << 12;
		//Acender pino PD7
		GPIOD -> MODER |= 0b01 << 14;


		while(1){
		//ligando o 0
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o 1
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o 2
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o 3
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o 4
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o 5
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led


		//ligando o 6
		GPIOD -> ODR |= 1; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led


		//ligando o 7
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o 8
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o 9
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o A
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o B
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led


		//ligando o C
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led

		//ligando o D
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o E
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led


		//ligando o F

		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led

		//ligando o E
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led

		//ligando o D
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led


		//ligando o C
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led

		//ligando o B
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led

		//ligando o A
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 9
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 8
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 7
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 6
		GPIOD -> ODR |= 1; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led

		//ligando o 5
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led

		//ligando o 4
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 3
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 2
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 4; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 4); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 1
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led

		//ligando o 0
		GPIOD -> ODR |= 1 ; //Acende o led
		GPIOD -> ODR |= 1 << 1; //Acende o led
		GPIOD -> ODR |= 1 << 3; //Acende o led
		GPIOD -> ODR |= 1 << 5; //Acende o led
		GPIOD -> ODR |= 1 << 6; //Acende o led
		GPIOD -> ODR |= 1 << 7; //Acende o led

		Delay_ms(500);

		GPIOD -> ODR &= ~(1 << 0); //Desliga o led
		GPIOD -> ODR &= ~(1 << 1); //Desliga o led
		GPIOD -> ODR &= ~(1 << 3); //Desliga o led
		GPIOD -> ODR &= ~(1 << 5); //Desliga o led
		GPIOD -> ODR &= ~(1 << 6); //Desliga o led
		GPIOD -> ODR &= ~(1 << 7); //Desliga o led
}
}




void q15(){
	Utility_Init();
	//Ligar o Clock GPIOA e GPIOD
	RCC-> AHB1ENR |= 0b1101;

	//Acender pino PC0 e PC1
	GPIOC -> MODER |= 0b01 << 0;
	GPIOC -> MODER |= 0b01 << 2;

	//Acender pino PD0 até PD7
	GPIOD -> MODER |= 0b01 << 0;
	GPIOD -> MODER |= 0b01 << 2;
	GPIOD -> MODER |= 0b01 << 4;
	GPIOD -> MODER |= 0b01 << 6;
	GPIOD -> MODER |= 0b01 << 8;
	GPIOD -> MODER |= 0b01 << 10;
	GPIOD -> MODER |= 0b01 << 12;

	const uint8_t lista[16]={
			0b01111110,
			0b00001100,
			0b01111001,
			0b01101101,
			0b00001111,
			0b01100111,
			0b01110111,
			0b01001100,
			0b01111111,
			0b01101111,
			0b01011111,
			0b00110111,
			0b01110010,
			0b00111101,
			0b01110011,
			0b01010011,
	};

	int time = 4;

	while(1)
	{
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){

				GPIOD -> ODR = lista[i] << 0; //Conta no display 1
				GPIOC -> ODR |= (1<<0); //Liga display 1
				GPIOC->ODR &= ~(1<<0);//Desliga display 1

				GPIOD -> ODR = lista[j] << 0;//conta no display 2
				GPIOC -> ODR |= (1<<1);//Liga o display 2
				GPIOD -> ODR &= ~(lista[j] << 0);//apaga o display 2
				GPIOC->ODR &= ~(1<<1);//Desliga o display2

				for(int k=0; k < 10; k++){
					GPIOD -> ODR = lista[i] << 0; //Conta no display 1
					GPIOC -> ODR |= (1<<0); //Liga display 1
					Delay_ms(time);
					GPIOC->ODR &= ~(1<<0);//Desliga display 1
					GPIOD -> ODR &= ~(lista[i] << 0);//apaga o display 2

					Delay_ms(time);
					GPIOD -> ODR = lista[j] << 0;//conta no display 2
					GPIOC -> ODR |= (1<<1);//Liga o display 2
					Delay_ms(time);
					GPIOC->ODR &= ~(1<<1);//Desliga display 1
					GPIOD -> ODR &= ~(lista[j] << 1);//apaga o display 2

				}
			}

			GPIOD-> ODR &= ~(lista[i]<<0);//Conta no display 1
			GPIOC-> ODR |= (1<<0);//Liga display 1
			Delay_ms(time);

			GPIOC-> ODR &= ~(1<<0);//Desliga display 1
		}

			for(int i = 15; i >= 0; i--){
				for(int j = 15; j >= 0; j--){

					GPIOD -> ODR = lista[i] << 0; //Conta no display 1
					GPIOC -> ODR |= (1<<0); //Liga display 1
					GPIOC->ODR &= ~(1<<0);//Desliga display 1

					GPIOD -> ODR = lista[j] << 0;//conta no display 2
					GPIOC -> ODR |= (1<<1);//Liga o display 2
					GPIOD -> ODR &= ~(lista[j] << 0);//apaga o display 2
					GPIOC->ODR &= ~(1<<1);//Desliga o display2

					for(int k=15; k >= 0; k--){
						GPIOD -> ODR = lista[i] << 0; //Conta no display 1
						GPIOC -> ODR |= (1<<0); //Liga display 1
						Delay_ms(time);
						GPIOC->ODR &= ~(1<<0);//Desliga display 1
						GPIOD -> ODR &= ~(lista[i] << 0);//apaga o display 2

						Delay_ms(time);
						GPIOD -> ODR = lista[j] << 0;//conta no display 2
						GPIOC -> ODR |= (1<<1);//Liga o display 2
						Delay_ms(time);
						GPIOC->ODR &= ~(1<<1);//Desliga display 1
						GPIOD -> ODR &= ~(lista[j] << 1);//apaga o display 2

					}
				}

				GPIOD-> ODR &= ~(lista[i]<<0);//Conta no display 1
				GPIOC-> ODR |= (1<<0);//Liga display 1
				Delay_ms(time);

				GPIOC-> ODR &= ~(1<<0);//Desliga display 1
			}
	}
}


void q17(void){
	Utility_Init();

	RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA

	//configurando PA0 como entrada
	GPIOA->MODER |= (0b01 << 0);

	while(1)
	{
		for(int x = 500; x <= 2500; x+=10){
			GPIOA->ODR |= (1 << 0);
			Delay_us(x);
			GPIOA->ODR &= ~(1 << 0);
			Delay_us(20000-x);
		}
		for(int x = 2500; x >= 500; x-=10){
			GPIOA->ODR |= (1 << 0);
			Delay_us(x);
			GPIOA->ODR &= ~(1 << 0);
			Delay_us(20000-x);
		}
	}
}

void q18(){
	Utility_Init();
	//Ligar o Clock GPIOA e GPIOD
	RCC-> AHB1ENR |= 0b1001;

	//Acender pino PA9 e PA10
	GPIOA -> MODER |= 0b01 << 18;
	GPIOA -> MODER |= 0b01 << 20;

	//Acender pino PD0 até PD7
	GPIOD -> MODER |= 0b01 << 0;

	while(1){
		GPIOA->ODR &= ~(1<<9);
		GPIOA->ODR |= 1<<10;

		int tempo = 0;
		while(tempo <= 2000){

			GPIOD->ODR |= 1<<0;
			Delay_us(tempo);

			GPIOD->ODR &= ~(1<<0);
			Delay_us(2000-tempo);
			++tempo;
		}

		tempo = 2000;
		while(tempo >=0){
			GPIOD->ODR |= 1<<0;
			Delay_us(tempo);

			GPIOD->ODR &= ~(1<<0);
			Delay_us(2000-tempo);
			--tempo;
		}

		GPIOA->ODR &= ~(1<<10);
		GPIOA->ODR |= 1<<9;

		tempo = 0;
		while(tempo <= 2000){
			GPIOD->ODR |= 1<<0;
			Delay_us(tempo);

			GPIOD->ODR &= ~(1<<0);
			Delay_us(2000-tempo);
			++tempo;
		}

		tempo = 2000;
		while(tempo >=0){
			GPIOD->ODR |= 1<<0;
			Delay_us(tempo);

			GPIOD->ODR &= ~(1<<0);
			Delay_us(2000-tempo);
			--tempo;
		}
	}
}

void q26(void){
	Utility_Init();

	RCC->AHB1ENR |= 1;         //habilita o clock do GPIOA
	RCC->AHB1ENR |= (1<<4);

	//configurando PA0 como entrada
	GPIOA->MODER |= (0b01 << 0);

	GPIOE->MODER &= ~(0b01 << 6);
	GPIOE->PUPDR |= (0b01 << 6);
	GPIOE->MODER &= ~(0b01 << 8);
	GPIOE->PUPDR |= (0b01 << 8);
	int x = 600;

	while(1)
	{
		if(K1 && (x > 600)){
			x-=10;
		}
		if(K0 && (x < 2400)){
			x+=10;
		}
		GPIOA->ODR |= (1 << 0);
		Delay_us(x);
		GPIOA->ODR &= ~(1 << 0);
		Delay_us(20000-x);
	}

}

void q27(void){
	Utility_Init();
		//Ligar o Clock GPIOA e GPIOD
		RCC-> AHB1ENR |= 0b11001;

		//Acender pino PD0 até PD7
		GPIOD -> MODER |= 0b01 << 0;
		GPIOD -> MODER |= 0b01 << 2;
		GPIOD -> MODER |= 0b01 << 4;
		GPIOD -> MODER |= 0b01 << 6;
		GPIOD -> MODER |= 0b01 << 8;
		GPIOD -> MODER |= 0b01 << 10;
		GPIOD -> MODER |= 0b01 << 12;

		//configura pa0 como entrada
		GPIOA -> MODER &= ~(0b11 << 0);
		//Ligando o resistor de pull-up no pino pa0
		GPIOA -> PUPDR |= (0b10 << 0);

		//configura pe3 como entrada
		GPIOE -> MODER &= ~(0b11 << 6);
		//Ligando o resistor de pull-up no pino pe3
		GPIOE -> PUPDR |= (0b01 << 6);

		//configura pe4 como entrada
		GPIOE -> MODER &= ~(0b11 << 8);
		//Ligando o resistor de pull-up no pino pe4
		GPIOE -> PUPDR |= (0b01 << 8);

		//GPIOD -> ODR &= ~(0b00001100 << 0);
		while(1){
			//FAZENDO A LEITURA DO REGISTRADOR IDR (A LEITURA DOS PINOS)
			int leitura = GPIOE -> IDR;
			int leitura_1 = GPIOA -> IDR;

			//Testando se o pino tem nível alto ou baixo
			if ((leitura & (1 << 3))){
				//Liga o led se nivel alto no pino
				GPIOD -> ODR &= ~(0b01011101 << 0);
			}
			else{
				//Desliga o led se nível baixo
				GPIOD -> ODR |= 0b01011101 << 0;
			}

			if ((leitura & (1 << 4))){
				//Liga o led se nivel alto no pino
				GPIOD -> ODR &= ~(0b00000110 << 0);
			}
			else{
				//Desliga o led se nível baixo
				GPIOD -> ODR |= 0b00000110 << 0;
			}

			if ((leitura_1 & (1 << 0))){
				//Liga o led se nivel alto no pino
				GPIOD -> ODR |= 0b00111111 << 0;

			}
			else{
				//Desliga o led se nível baixo
				GPIOD -> ODR &= ~(0b00111111 << 0);
			}
	}
}

#define K0 !(GPIOE->IDR & (1<<4)) //testando se o botão K0 tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define KUP (GPIOA->IDR & (1)) //testando se o botão K_UP tá pressionado fazendo um AND com o valor 1 na posição 4 (botão pressionado)
#define K1 !(GPIOE->IDR & (1<<3)) //testando o botão K1 á pressionado fazendo um AND com o valor 1 na posição 3 (botão pressionado)

#define LEDX_OFF   (GPIOC -> ODR &= ~(1 << 0))
#define LEDX_ON    (GPIOC -> ODR |= (1 << 0))
#define LEDY_OFF   (GPIOC -> ODR &= ~(1 << 1))
#define LEDY_ON    (GPIOC -> ODR |= (1 << 1))
#define LEDZ_OFF   (GPIOC -> ODR &= ~(1 << 2))
#define LEDZ_ON    (GPIOC -> ODR |= (1 << 2))

void atraso(int atraso){
    while(atraso) --atraso;
}

void q30(void){
	  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //habilita o clock do GPIOA
	    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; //habilita o clock do GPIOD
	    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; //habilita o clock do GPIOE

		int sequencia[1000] = {0};
		int num, topo = 0;

		RCC->AHB1ENR |= 1<<2;

		GPIOC -> MODER |= (1 << 0);
		GPIOC -> MODER |= (1 << 2);
		GPIOC -> MODER |= (1 << 4);

	    GPIOE->MODER &= ~(0b11 << 6);    //configurando o pino PE3 como entrada (botão k1)
	    GPIOE->PUPDR |= (0b01 << 6);     //liga o resistor de pull-up no pino PE3 (pra garantir nível alto quando a chave estiver solta)

	    GPIOE->MODER &= ~(0b11 << 8);    //configurando o pino PE4 como entrada (botão k0)
	    GPIOE->PUPDR |= (0b01 << 8);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

	    GPIOA->MODER &= ~(0b00 << 0);    //configurando o pino PA0 como entrada (botão k_up)
	    GPIOA->PUPDR |= (0b10 << 0);     //liga o resistor de pull-down no pino PA0 (pra garantir nível alto quando a chave estiver solta)


	    GPIOE->MODER &= ~(0b11 << 10);    //configurando o pino PE4 como entrada (botão k2)
	    GPIOE->PUPDR |= (0b01 << 10);     //liga o resistor de pull-up no pino PE4 (pra garantir nível alto quando a chave estiver solta)

		while(1){
			num = rand() % 3;
			sequencia[topo] = num;
			atraso(1000000);
			for(int i = 0; i < topo + 1; i++){
				if(sequencia[i] == 0){
					LEDX_ON;
					atraso(1000000);
					LEDX_OFF;
					atraso(1000000);
				}else if(sequencia[i] == 1){
					LEDY_ON;
					atraso(1000000);
					LEDY_OFF;
					atraso(100000);
				}else if(sequencia[i] == 2){
					LEDZ_ON;
					atraso(1000000);
					LEDZ_OFF;
					atraso(1000000);
				}
			}

			int indice = 0;
			while(1){
				if(indice > topo){
					break;
				}

				if(K0 && sequencia[indice] == 0){
					while(1){
						if(!K0){
							indice++;
							break;
						}
					}
				}else if(K0 && sequencia[indice] != 0){
					for(int i = 0; i < 3; i++){
						LEDX_ON;
						LEDY_ON;
						LEDZ_ON;
						atraso(1000000);
						LEDX_OFF;
						LEDY_OFF;
						LEDZ_OFF;
						atraso(1000000);
					}
					exit(0);
				}

				if(K1 && sequencia[indice] == 1){
					while(1){
						if(!K1){
							indice++;
							break;
						}
					}
				}else if(K1 && sequencia[indice] != 1){
					for(int i = 0; i < 3; i++){
						LEDX_ON;
						LEDY_ON;
						LEDZ_ON;
						atraso(1000000);
						LEDX_OFF;
						LEDY_OFF;
						LEDZ_OFF;
						atraso(1000000);
					}
					exit(0);
				}

				if(KUP && sequencia[indice] == 2){
					while(1){
						if(!KUP){
							indice++;
							break;
						}
					}
				}else if(KUP && sequencia[indice] != 2){
					for(int i = 0; i < 3; i++){
						LEDX_ON;
						LEDY_ON;
						LEDZ_ON;
						atraso(1000000);
						LEDX_OFF;
						LEDY_OFF;
						LEDZ_OFF;
						atraso(1000000);
					}
					exit(0);
				}
			}
		topo++;
		}
}




