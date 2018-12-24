#include "stm32f0xx.h"
#include "main.h"

unsigned int general_flags_g;

void SysTick_Handler() {
}

void DMA1_Channel2_3_IRQHandler() {
   DMA_ClearITPendingBit(DMA1_IT_TC2);
   set_flag(&general_flags_g, USART_TRANSFER_COMPLETE_FLAG);
}

void DMA1_Channel1_IRQHandler() {
   if (DMA_GetITStatus(DMA1_IT_TC1)) {
      DMA_ClearITPendingBit(DMA1_IT_TC1);
   }
}

void TIM14_IRQHandler() {
   TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
}

void TIM3_IRQHandler() {
   TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
}

void I2C1_IRQHandler() {
   if (I2C_GetFlagStatus(I2C1, I2C_FLAG_TC)) {

   } else if (I2C_GetFlagStatus(I2C1, I2C_IT_RXI)) {

   }
}

int main() {
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_DBGMCU, ENABLE);
   iwdg_config();
   clock_config();
   pins_config();
   external_interrupt_config();
   dma_config();
   usart_config();
   timer3_confing();
   i2c_config();
   timer14_confing();

   IWDG_ReloadCounter();

   set_flag(&general_flags_g, USART_TRANSFER_COMPLETE_FLAG);

   while (1) {

      IWDG_ReloadCounter();
   }
}

void iwdg_config() {
   DBGMCU_APB1PeriphConfig(DBGMCU_IWDG_STOP, ENABLE);

   IWDG_Enable();
   IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
   IWDG_SetPrescaler(IWDG_Prescaler_256);
   IWDG_SetReload(156); // 1 second
   while (IWDG_GetFlagStatus(IWDG_FLAG_PVU) == SET);
   while (IWDG_GetFlagStatus(IWDG_FLAG_RVU) == SET);
}

void clock_config() {
   RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);
   RCC_PLLCmd(DISABLE);
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == SET);

   RCC_I2CCLKConfig(RCC_I2C1CLK_HSI);
}

void init_pin_as_output(GPIO_TypeDef* GPIOx, unsigned int pin) {
   GPIO_InitTypeDef GPIO_InitType;
   GPIO_InitType.GPIO_Pin = pin;
   GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_InitType.GPIO_Speed = GPIO_Speed_Level_1;
   GPIO_InitType.GPIO_PuPd = GPIO_PuPd_NOPULL;
   GPIO_InitType.GPIO_OType = GPIO_OType_PP;
   GPIO_Init(GPIOx, &GPIO_InitType);
}

void pins_config() {
   // Connect BOOT0 directly to ground, RESET to VDD with a resistor

   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB, ENABLE);

   GPIO_InitTypeDef ports_default_config;
   ports_default_config.GPIO_Pin = GPIO_Pin_All & ~(GPIO_Pin_13 | GPIO_Pin_14); // PA13, PA14 - Debugger pins
   ports_default_config.GPIO_Mode = GPIO_Mode_IN;
   ports_default_config.GPIO_Speed = GPIO_Speed_Level_1; // 2 MHz
   ports_default_config.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_Init(GPIOA, &ports_default_config);

   ports_default_config.GPIO_Pin = GPIO_Pin_All;
   GPIO_Init(GPIOB, &ports_default_config);

   GPIO_Init(GPIOF, &ports_default_config);
}

/**
 * USART frame time Tfr = (1 / USART_BAUD_RATE) * 10bits
 * Timer time to be sure the frame is ended Tt = Tfr + 0.5 * Tfr
 * Frequency = 16Mhz, USART_BAUD_RATE = 115200. Tt = 0.13ms
 */
void timer3_confing() {
   DBGMCU_APB1PeriphConfig(DBGMCU_TIM3_STOP, ENABLE);
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   TIM_TimeBaseStructure.TIM_Period = TIMER3_PERIOD_TICKS;
   TIM_TimeBaseStructure.TIM_Prescaler = 0;
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
   TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

   NVIC_EnableIRQ(TIM3_IRQn);
   TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

   TIM_Cmd(TIM3, ENABLE);
}

void timer14_confing() {
   DBGMCU_APB1PeriphConfig(DBGMCU_TIM14_STOP, ENABLE);
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);

   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   TIM_TimeBaseStructure.TIM_Period = TIMER14_PERIOD;
   TIM_TimeBaseStructure.TIM_Prescaler = TIMER14_PRESCALER;
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
   TIM_TimeBaseInit(TIM14, &TIM_TimeBaseStructure);

   TIM_ClearITPendingBit(TIM14, TIM_IT_Update);
   NVIC_EnableIRQ(TIM14_IRQn);
   TIM_ITConfig(TIM14, TIM_IT_Update, ENABLE);

   TIM_Cmd(TIM14, ENABLE);
}

void i2c_config() {
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);

   GPIO_InitTypeDef GPIO_InitStructure;
   GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_9 | GPIO_Pin_10;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
   GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
   GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
   GPIO_Init(GPIOA, &GPIO_InitStructure);

   GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_4);
   GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_4);

   I2C_InitTypeDef I2C_InitStructure;
   I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
   I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
   I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;
   I2C_InitStructure.I2C_DigitalFilter = 0;
   I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
   I2C_InitStructure.I2C_OwnAddress1 = 0x4;
   I2C_InitStructure.I2C_Timing = 0x00501D77;
   I2C_Init(I2C1, &I2C_InitStructure);

   I2C_ITConfig(I2C1, I2C_IT_RXI | I2C_IT_TCI, ENABLE);
}

void dma_config() {
   RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1 , ENABLE);

   // USART DMA config
   DMA_InitTypeDef usartDmaInitType;
   usartDmaInitType.DMA_PeripheralBaseAddr = USART1_TDR_ADDRESS;
   //dmaInitType.DMA_MemoryBaseAddr = (uint32_t)(&usartDataToBeTransmitted);
   usartDmaInitType.DMA_DIR = DMA_DIR_PeripheralDST; // Specifies if the peripheral is the source or destination
   usartDmaInitType.DMA_BufferSize = 0;
   usartDmaInitType.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
   usartDmaInitType.DMA_MemoryInc = DMA_MemoryInc_Enable; // DMA_MemoryInc_Enable if DMA_InitTypeDef.DMA_BufferSize > 1
   usartDmaInitType.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
   usartDmaInitType.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
   usartDmaInitType.DMA_Mode = DMA_Mode_Normal;
   usartDmaInitType.DMA_Priority = DMA_Priority_Low;
   usartDmaInitType.DMA_M2M = DMA_M2M_Disable;
   DMA_Init(USART1_TX_DMA_CHANNEL, &usartDmaInitType);

   DMA_ITConfig(USART1_TX_DMA_CHANNEL, DMA_IT_TC, ENABLE);
   NVIC_SetPriority(USART1_IRQn, 10);
   NVIC_EnableIRQ(USART1_IRQn);
   DMA_Cmd(USART1_TX_DMA_CHANNEL, ENABLE);
}

void usart_config() {
   // For USART1
   GPIO_InitTypeDef usart_pins_config;
   usart_pins_config.GPIO_Pin = USART_TX_PIN;
   usart_pins_config.GPIO_PuPd = GPIO_PuPd_NOPULL;
   usart_pins_config.GPIO_Mode = GPIO_Mode_AF;
   usart_pins_config.GPIO_OType = GPIO_OType_PP; // GPIO_OType_OD for USART RX
   GPIO_Init(USART_TX_PORT, &usart_pins_config);
   GPIO_PinAFConfig(USART_TX_PORT, GPIO_PinSource9, GPIO_AF_1);
   //GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_1);

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

   USART_OverSampling8Cmd(USART1, DISABLE);

   USART_InitTypeDef USART_InitStructure;
   USART_InitStructure.USART_BaudRate = USART_BAUD_RATE;
   USART_InitStructure.USART_WordLength = USART_WordLength_8b;
   USART_InitStructure.USART_StopBits = USART_StopBits_1;
   USART_InitStructure.USART_Parity = USART_Parity_No;
   USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
   USART_InitStructure.USART_Mode = USART_Mode_Tx;
   USART_Init(USART1, &USART_InitStructure);

   NVIC_SetPriority(DMA1_Channel2_3_IRQn, 11);
   NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);

   USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);

   USART_Cmd(USART1, ENABLE);
}

void external_interrupt_config() {
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

   NVIC_InitTypeDef nvic_init_type_structure;
   nvic_init_type_structure.NVIC_IRQChannelPriority = 3;
   nvic_init_type_structure.NVIC_IRQChannelCmd = ENABLE;
   nvic_init_type_structure.NVIC_IRQChannel = EXTI0_1_IRQn;
   NVIC_Init(&nvic_init_type_structure);
   nvic_init_type_structure.NVIC_IRQChannel = EXTI2_3_IRQn;
   NVIC_Init(&nvic_init_type_structure);
   nvic_init_type_structure.NVIC_IRQChannel = EXTI4_15_IRQn;
   NVIC_Init(&nvic_init_type_structure);
}

void send_usard_data(char *string) {
   reset_flag(&general_flags_g, USART_TRANSFER_COMPLETE_FLAG);
   DMA_Cmd(USART1_TX_DMA_CHANNEL, DISABLE);
   unsigned short bytes_to_send = get_string_length(string);

   if (bytes_to_send == 0) {
      return;
   }

   DMA_SetCurrDataCounter(USART1_TX_DMA_CHANNEL, bytes_to_send);
   USART1_TX_DMA_CHANNEL->CMAR = (unsigned int) string;
   USART_ClearFlag(USART1, USART_FLAG_TC);
   DMA_Cmd(USART1_TX_DMA_CHANNEL, ENABLE);
}

void set_flag(unsigned int *flags, unsigned int flag_value) {
   *flags |= flag_value;
}

void reset_flag(unsigned int *flags, unsigned int flag_value) {
   *flags &= ~(*flags & flag_value);
}

unsigned char read_flag(unsigned int flags, unsigned int flag_value) {
   return (flags & flag_value) > 0 ? 1 : 0;
}

unsigned short get_string_length(char string[]) {
   unsigned short length = 0;

   for (char *string_pointer = string; *string_pointer != '\0'; string_pointer++, length++) {
   }
   return length;
}
