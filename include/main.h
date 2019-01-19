#include "stm32f0xx_conf.h"
#include "stm32f0xx.h"
#include <math.h>

#define CLOCK_SPEED 8000000
#define USART_BAUD_RATE 115200
#define TIMER3_PERIOD_TICKS (unsigned int) (CLOCK_SPEED * 15 / USART_BAUD_RATE)
#define TIMER3_SEC_PER_PERIOD ((float) TIMER3_PERIOD_TICKS / CLOCK_SPEED)
#define TIMER3_MS_PER_PERIOD ((float) TIMER3_PERIOD_TICKS * 1000 / CLOCK_SPEED)
#define TIMER14_PERIOD 24
#define TIMER14_PRESCALER 0xFFFF
#define TIMER14_TACTS_PER_SECOND ((float) CLOCK_SPEED / TIMER14_PERIOD / TIMER14_PRESCALER)

#define USART1_TX_DMA_CHANNEL   DMA1_Channel2
#define USART1_TDR_ADDRESS      (unsigned int) (&(USART1->TDR))

#define ADC1_DMA_CHANNEL DMA1_Channel1
#define ADC1_DR_ADDRESS (uint32_t) (&(ADC1->DR))

// LIGHT_SENSOR
#define LIGHT_SENSOR_ADC_CHANNEL ADC_Channel_4 // See ADC pin
#define LIGHT_SENSOR_PIN  GPIO_Pin_4
#define LIGHT_SENSOR_PORT GPIOA
// USART
#define USART_TX_PIN  GPIO_Pin_2
#define USART_TX_PORT GPIOA
#define USART_TX_AF_PIN_SOURCE GPIO_PinSource2
// I2C
#define I2C_PORT    GPIOA
#define I2C_SCL_PIN GPIO_Pin_9
#define I2C_SDA_PIN GPIO_Pin_10
#define I2C_SCL_AF_PIN_SOURCE GPIO_PinSource9
#define I2C_SDA_AF_PIN_SOURCE GPIO_PinSource10

// General flags
#define USART_TRANSFER_COMPLETE_FLAG            (unsigned int) 1
#define SHT21_MEASUREMENT_IS_IN_PROGRESS_FLAG   (unsigned int) 2

#define USART_DATA_TO_BE_TRANSMITTED_BUFFER_SIZE 50

#define TIMER3_10MS (unsigned short) (10 / TIMER3_MS_PER_PERIOD)
#define TIMER3_100MS (unsigned short) (100 / TIMER3_MS_PER_PERIOD)
#define TIMER3_500MS (unsigned short) (500 / TIMER3_MS_PER_PERIOD)
#define TIMER14_1S (unsigned short) (1 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_10S (unsigned short) (10 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_30S (unsigned short) (30 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_60S (unsigned short) (60 * TIMER14_TACTS_PER_SECOND)
#define TIMER14_5MINS (unsigned short) (300 * TIMER14_TACTS_PER_SECOND)

#define SHT21_ADDRESS                   (unsigned char) 0x40
#define SHT21_ADDRESS_READ              (unsigned char) ((SHT21_ADDRESS << 1) | 0x1)

#define SHT21_CRC8_POLYNOMIAL 0x13100   //CRC-8 polynomial for 16bit value -> x^8 + x^5 + x^4 + 1

#define SHT21_CRC_ERROR                         -100.0F
#define SHT21_NOT_TEMPERATURE_MEASUREMENT_ERROR -200.0F
#define SHT21_NOT_HUMIDITY_MEASUREMENT_ERROR    -300.0F

//typedef enum {I2C_WRITE = 0, I2C_READ = !I2C_WRITE} I2C_SDA_Direction_Bit;
typedef enum {
   TRIGGER_T_MEASUREMENT = 0xF3,
   TRIGGER_RH_MEASUREMENT = 0xF5
} SHT21_Commands;

typedef struct {
   unsigned char address;
   SHT21_Commands command;
   unsigned char status;
   unsigned short received_data;
   unsigned char received_data_checksum;
   unsigned char received_bytes;
   unsigned char received_stops;
} SHT21_Measurement_TypeDef;

typedef enum {
   SHT21_WRITE_SENT_FLAG =      1,
   SHT21_COMMAND_SENT_FLAG =    2,
   SHT21_READ_SENT_FLAG =       4,
   SHT21_DATA_READ_FLAG =       8,
   SHT21_NACK_RECEIVED_FLAG =   16,
   SHT21_DATA_WASNT_READ_FLAG = 32,
   SHT21_STOP_RECEIVED_FLAG =   64,
   SHT21_REREAD_FLAG        =   128
} SHT21_Measurement_Flags;

void iwdg_config();
void clock_config();
void pins_config();
void timer3_confing();
void i2c_config();
void timer14_confing();
void init_pin_as_output(GPIO_TypeDef* GPIOx, unsigned int pin);
void dma_config();
void usart_config();
void adc_config();
void send_usard_data(char string[]);
void set_flag(unsigned int *flags, unsigned int flag_value);
void reset_flag(unsigned int *flags, unsigned int flag_value);
unsigned char read_flag(unsigned int flags, unsigned int flag_value);
unsigned short get_string_length(char string[]);
void init_sht21_measurements_queue();
void send_I2C_command(unsigned char address);
void read_I2C(unsigned char address);
void sht21_measure_next_parameter();
float sht21_calculate_temperature(unsigned short data, unsigned char checksum);
float sht21_calculate_humidity(unsigned short data, unsigned char checksum);
unsigned char sht21_calculate_crc(unsigned short data);
