#ifndef DHT11_H
#define DHT11_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"

#define DHT11_SUCCESS         1
#define DHT11_ERROR_CHECKSUM  2
#define DHT11_ERROR_TIMEOUT   3

typedef struct DHT11_Dev {
	uint8_t temparature;
	uint8_t humidity;
	GPIO_TypeDef* port;
	uint16_t pin;
} DHT11_Dev;

int DHT11_init(struct DHT11_Dev* dev, GPIO_TypeDef* port, uint16_t pin);
int DHT11_read(struct DHT11_Dev* dev);

#endif /* DHT11_H */

/*   Inicializa��o: Para iniciar a comunica��o com o sensor, � necess�rio enviar um sinal de inicializa��o (LOW) por pelo menos 18 ms,
  	 seguido por um sinal HIGH por aproximadamente 20-40 �s. Em resposta a isso, o sensor DHT11 enviar� um pulso de ACK.

     ACK do DHT11: Ap�s receber o sinal de inicializa��o, o DHT11 responde com um pulso LOW por 80 �s e ent�o um pulso HIGH por 80 �s.

     Transmiss�o de dados: Ap�s o ACK, o DHT11 come�ar� a transmitir os dados. Cada bit de dados come�a com um pulso LOW por 50 �s
     (isso � o sinal de in�cio do bit), seguido por um pulso HIGH. Se esse pulso HIGH durar aproximadamente 28 �s, o bit transmitido
     � considerado '0'. Se o pulso HIGH durar aproximadamente 70 �s, o bit transmitido � considerado '1'. Este � o padr�o para todos os
      40 bits de dados transmitidos pelo DHT11.

    Intervalo entre leituras: Ap�s uma leitura completa (40 bits de dados), � recomendado esperar pelo menos 1 segundo antes de iniciar
    a pr�xima leitura para garantir que o sensor esteja pronto para a pr�xima leitura.
*/
