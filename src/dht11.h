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

/*   Inicialização: Para iniciar a comunicação com o sensor, é necessário enviar um sinal de inicialização (LOW) por pelo menos 18 ms,
  	 seguido por um sinal HIGH por aproximadamente 20-40 µs. Em resposta a isso, o sensor DHT11 enviará um pulso de ACK.

     ACK do DHT11: Após receber o sinal de inicialização, o DHT11 responde com um pulso LOW por 80 µs e então um pulso HIGH por 80 µs.

     Transmissão de dados: Após o ACK, o DHT11 começará a transmitir os dados. Cada bit de dados começa com um pulso LOW por 50 µs
     (isso é o sinal de início do bit), seguido por um pulso HIGH. Se esse pulso HIGH durar aproximadamente 28 µs, o bit transmitido
     é considerado '0'. Se o pulso HIGH durar aproximadamente 70 µs, o bit transmitido é considerado '1'. Este é o padrão para todos os
      40 bits de dados transmitidos pelo DHT11.

    Intervalo entre leituras: Após uma leitura completa (40 bits de dados), é recomendado esperar pelo menos 1 segundo antes de iniciar
    a próxima leitura para garantir que o sensor esteja pronto para a próxima leitura.
*/
