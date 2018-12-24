#include "stm32f0xx_conf.h"
#include "stm32f0xx.h"

#define CLOCK_SPEED 8000000
#define USART_BAUD_RATE 115200
#define TIMER3_PERIOD_TICKS (unsigned int) (CLOCK_SPEED * 15 / USART_BAUD_RATE)
#define TIMER3_SEC_PER_PERIOD ((float) TIMER3_PERIOD_TICKS / CLOCK_SPEED)
#define TIMER3_MS_PER_PERIOD ((float) TIMER3_PERIOD_TICKS * 1000 / CLOCK_SPEED)
#define TIMER14_PERIOD 24
#define TIMER14_PRESCALER 0xFFFF
#define TIMER14_TACTS_PER_SECOND ((float) CLOCK_SPEED / TIMER14_PERIOD / TIMER14_PRESCALER)

#define USART1_TX_DMA_CHANNEL DMA1_Channel2
#define USART1_TDR_ADDRESS (unsigned int) (&(USART1->TDR))

// General flags
#define USART_TRANSFER_COMPLETE_FLAG 1

#define USART_DATA_RECEIVED_BUFFER_SIZE 50

#define TIMER3_10MS (unsigned short) (10 / TIMER3_MS_PER_PERIOD)
#define TIMER3_100MS (unsigned short) (100 / TIMER3_MS_PER_PERIOD)
#define TIMER3_500MS (unsigned short) (500 / TIMER3_MS_PER_PERIOD)
#define TIMER14_100MS 1
#define TIMER14_200MS 2
#define TIMER14_500MS 5
#define TIMER14_1S (unsigned short) (1 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_10S (unsigned short) (10 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_30S (unsigned short) (30 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_60S (unsigned short) (60 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_5MINS (unsigned short) (300 * TIMER14_TACTS_PER_SECOND)

#define USART_TX_PIN GPIO_Pin_9
#define USART_TX_PORT GPIOA

#define SHT21_TRIGGER_T_MEASUREMENT     0xF3 // no hold master
#define SHT21_TRIGGER_RH_MEASUREMENT    0xF5 // no hold master

void iwdg_config();
void clock_config();
void pins_config();
void timer3_confing();
void i2c_config();
void timer14_confing();
void init_pin_as_output(GPIO_TypeDef* GPIOx, unsigned int pin);
void dma_config();
void usart_config();
void external_interrupt_config();
void send_usard_data(char string[]);
void set_flag(unsigned int *flags, unsigned int flag_value);
void reset_flag(unsigned int *flags, unsigned int flag_value);
unsigned char read_flag(unsigned int flags, unsigned int flag_value);
unsigned short get_string_length(char string[]);
