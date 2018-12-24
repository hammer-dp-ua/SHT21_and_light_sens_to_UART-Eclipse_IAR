/**
  ******************************************************************************
  * @file    stm32f0xx_syscfg.h
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    05-December-2014
  * @brief   This file contains all the functions prototypes for the SYSCFG firmware 
  *          library.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/*!< Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F0XX_SYSCFG_H
#define __STM32F0XX_SYSCFG_H

#ifdef __cplusplus
 extern "C" {
#endif

/*!< Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/** @addtogroup STM32F0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup SYSCFG
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup SYSCFG_Exported_Constants
  * @{
  */ 
  
/** @defgroup SYSCFG_EXTI_Port_Sources 
  * @{
  */ 
#define EXTI_PortSourceGPIOA       ((unsigned char)0x00)
#define EXTI_PortSourceGPIOB       ((unsigned char)0x01)
#define EXTI_PortSourceGPIOC       ((unsigned char)0x02)
#define EXTI_PortSourceGPIOD       ((unsigned char)0x03) /*!< not available for STM32F031 devices */
#define EXTI_PortSourceGPIOE       ((unsigned char)0x04) /*!< only available for STM32F072 devices */
#define EXTI_PortSourceGPIOF       ((unsigned char)0x05)

#define IS_EXTI_PORT_SOURCE(PORTSOURCE) (((PORTSOURCE) == EXTI_PortSourceGPIOA) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOB) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOC) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOD) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOE) || \
                                         ((PORTSOURCE) == EXTI_PortSourceGPIOF)) 
/**
  * @}
  */

/** @defgroup SYSCFG_EXTI_Pin_sources 
  * @{
  */ 
#define EXTI_PinSource0            ((unsigned char)0x00)
#define EXTI_PinSource1            ((unsigned char)0x01)
#define EXTI_PinSource2            ((unsigned char)0x02)
#define EXTI_PinSource3            ((unsigned char)0x03)
#define EXTI_PinSource4            ((unsigned char)0x04)
#define EXTI_PinSource5            ((unsigned char)0x05)
#define EXTI_PinSource6            ((unsigned char)0x06)
#define EXTI_PinSource7            ((unsigned char)0x07)
#define EXTI_PinSource8            ((unsigned char)0x08)
#define EXTI_PinSource9            ((unsigned char)0x09)
#define EXTI_PinSource10           ((unsigned char)0x0A)
#define EXTI_PinSource11           ((unsigned char)0x0B)
#define EXTI_PinSource12           ((unsigned char)0x0C)
#define EXTI_PinSource13           ((unsigned char)0x0D)
#define EXTI_PinSource14           ((unsigned char)0x0E)
#define EXTI_PinSource15           ((unsigned char)0x0F)

#define IS_EXTI_PIN_SOURCE(PINSOURCE) (((PINSOURCE) == EXTI_PinSource0) || \
                                       ((PINSOURCE) == EXTI_PinSource1) || \
                                       ((PINSOURCE) == EXTI_PinSource2) || \
                                       ((PINSOURCE) == EXTI_PinSource3) || \
                                       ((PINSOURCE) == EXTI_PinSource4) || \
                                       ((PINSOURCE) == EXTI_PinSource5) || \
                                       ((PINSOURCE) == EXTI_PinSource6) || \
                                       ((PINSOURCE) == EXTI_PinSource7) || \
                                       ((PINSOURCE) == EXTI_PinSource8) || \
                                       ((PINSOURCE) == EXTI_PinSource9) || \
                                       ((PINSOURCE) == EXTI_PinSource10) || \
                                       ((PINSOURCE) == EXTI_PinSource11) || \
                                       ((PINSOURCE) == EXTI_PinSource12) || \
                                       ((PINSOURCE) == EXTI_PinSource13) || \
                                       ((PINSOURCE) == EXTI_PinSource14) || \
                                       ((PINSOURCE) == EXTI_PinSource15))
/**
  * @}
  */

/** @defgroup SYSCFG_Memory_Remap_Config 
  * @{
  */ 
#define SYSCFG_MemoryRemap_Flash                ((unsigned char)0x00)
#define SYSCFG_MemoryRemap_SystemMemory         ((unsigned char)0x01)
#define SYSCFG_MemoryRemap_SRAM                 ((unsigned char)0x03)


#define IS_SYSCFG_MEMORY_REMAP(REMAP) (((REMAP) == SYSCFG_MemoryRemap_Flash) || \
                                       ((REMAP) == SYSCFG_MemoryRemap_SystemMemory) || \
                                       ((REMAP) == SYSCFG_MemoryRemap_SRAM))

/**
  * @}
  */

/** @defgroup SYSCFG_DMA_Remap_Config 
  * @{
  */ 
#define SYSCFG_DMARemap_TIM3        SYSCFG_CFGR1_TIM3_DMA_RMP      /* Remap TIM3 DMA requests from channel4 to channel6, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_TIM2        SYSCFG_CFGR1_TIM2_DMA_RMP      /* Remap TIM2 DMA requests from channel3/4 to channel7, 
                                                                      available only for STM32F072 devices */ 
#define SYSCFG_DMARemap_TIM1        SYSCFG_CFGR1_TIM1_DMA_RMP      /* Remap TIM1 DMA requests from channel2/3/4 to channel6, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_I2C1        SYSCFG_CFGR1_I2C1_DMA_RMP      /* Remap I2C1 DMA requests from channel3/2 to channel7/6, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_USART3      SYSCFG_CFGR1_USART3_DMA_RMP    /* Remap USART3 DMA requests from channel6/7 to channel3/2, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_USART2      SYSCFG_CFGR1_USART2_DMA_RMP    /* Remap USART2 DMA requests from channel4/5 to channel6/7, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_SPI2        SYSCFG_CFGR1_SPI2_DMA_RMP      /* Remap SPI2 DMA requests from channel4/5 to channel6/7, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_TIM17_2     SYSCFG_CFGR1_TIM17_DMA_RMP2    /* Remap TIM17 DMA requests from channel1/2 to channel7, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_TIM16_2     SYSCFG_CFGR1_TIM16_DMA_RMP2    /* Remap TIM16 DMA requests from channel3/4 to channel6, 
                                                                      available only for STM32F072 devices */
#define SYSCFG_DMARemap_TIM17       SYSCFG_CFGR1_TIM17_DMA_RMP    /* Remap TIM17 DMA requests from channel1 to channel2 */
#define SYSCFG_DMARemap_TIM16       SYSCFG_CFGR1_TIM16_DMA_RMP    /* Remap TIM16 DMA requests from channel3 to channel4 */
#define SYSCFG_DMARemap_USART1Rx    SYSCFG_CFGR1_USART1RX_DMA_RMP /* Remap USART1 Rx DMA requests from channel3 to channel5 */
#define SYSCFG_DMARemap_USART1Tx    SYSCFG_CFGR1_USART1TX_DMA_RMP /* Remap USART1 Tx DMA requests from channel2 to channel4 */
#define SYSCFG_DMARemap_ADC1        SYSCFG_CFGR1_ADC_DMA_RMP      /* Remap ADC1 DMA requests from channel1 to channel2 */
  
#define IS_SYSCFG_DMA_REMAP(REMAP) (((REMAP) == SYSCFG_DMARemap_TIM17) || \
                                    ((REMAP) == SYSCFG_DMARemap_TIM16) || \
                                    ((REMAP) == SYSCFG_DMARemap_USART1Rx) || \
                                    ((REMAP) == SYSCFG_DMARemap_USART1Tx) || \
                                    ((REMAP) == SYSCFG_CFGR1_TIM3_DMA_RMP) || \
                                    ((REMAP) == SYSCFG_CFGR1_TIM2_DMA_RMP) || \
                                    ((REMAP) == SYSCFG_CFGR1_TIM1_DMA_RMP) || \
                                    ((REMAP) == SYSCFG_CFGR1_I2C1_DMA_RMP) || \
                                    ((REMAP) == SYSCFG_CFGR1_USART3_DMA_RMP) || \
                                    ((REMAP) == SYSCFG_CFGR1_USART2_DMA_RMP) || \
                                    ((REMAP) == SYSCFG_CFGR1_SPI2_DMA_RMP) || \
                                    ((REMAP) == SYSCFG_CFGR1_TIM17_DMA_RMP2) || \
                                    ((REMAP) == SYSCFG_CFGR1_TIM16_DMA_RMP2) || \
                                    ((REMAP) == SYSCFG_DMARemap_ADC1))

/**
  * @}
  */

/** @defgroup SYSCFG_I2C_FastModePlus_Config 
  * @{
  */ 
#define SYSCFG_I2CFastModePlus_PB6       SYSCFG_CFGR1_I2C_FMP_PB6 /* Enable Fast Mode Plus on PB6 */
#define SYSCFG_I2CFastModePlus_PB7       SYSCFG_CFGR1_I2C_FMP_PB7 /* Enable Fast Mode Plus on PB7 */
#define SYSCFG_I2CFastModePlus_PB8       SYSCFG_CFGR1_I2C_FMP_PB8 /* Enable Fast Mode Plus on PB8 */
#define SYSCFG_I2CFastModePlus_PB9       SYSCFG_CFGR1_I2C_FMP_PB9 /* Enable Fast Mode Plus on PB9 */
#define SYSCFG_I2CFastModePlus_I2C1      SYSCFG_CFGR1_I2C_FMP_I2C1 /* Enable Fast Mode Plus on PB10, PB11, PF6 and PF7(only for STM32F0031 and STM32F030 devices) */
#define SYSCFG_I2CFastModePlus_I2C2      SYSCFG_CFGR1_I2C_FMP_I2C2 /* Enable Fast Mode Plus on I2C2 pins, available only for STM32F072 devices */
#define SYSCFG_I2CFastModePlus_PA9       SYSCFG_CFGR1_I2C_FMP_PA9 /* Enable Fast Mode Plus on PA9 (only for STM32F031 and STM32F030 devices) */
#define SYSCFG_I2CFastModePlus_PA10      SYSCFG_CFGR1_I2C_FMP_PA10/* Enable Fast Mode Plus on PA10(only for STM32F031 and STM32F030 devices) */

#define IS_SYSCFG_I2C_FMP(PIN) (((PIN) == SYSCFG_I2CFastModePlus_PB6)  || \
                                ((PIN) == SYSCFG_I2CFastModePlus_PB7)  || \
                                ((PIN) == SYSCFG_I2CFastModePlus_PB8)  || \
                                ((PIN) == SYSCFG_I2CFastModePlus_PB9)  || \
                                ((PIN) == SYSCFG_I2CFastModePlus_I2C1) || \
                                ((PIN) == SYSCFG_I2CFastModePlus_I2C2) || \
                                ((PIN) == SYSCFG_I2CFastModePlus_PA9)  || \
                                ((PIN) == SYSCFG_I2CFastModePlus_PA10))


/**
  * @}
  */

/** @defgroup SYSCFG_Lock_Config 
  * @{
  */ 
#define SYSCFG_Break_PVD                     SYSCFG_CFGR2_PVD_LOCK       /*!< Connects the PVD event to the Break Input of TIM1, not available for STM32F030 devices */
#define SYSCFG_Break_SRAMParity              SYSCFG_CFGR2_SRAM_PARITY_LOCK  /*!< Connects the SRAM_PARITY error signal to the Break Input of TIM1 */
#define SYSCFG_Break_Lockup                  SYSCFG_CFGR2_LOCKUP_LOCK       /*!< Connects Lockup output of CortexM0 to the break input of TIM1 */

#define IS_SYSCFG_LOCK_CONFIG(CONFIG) (((CONFIG) == SYSCFG_Break_PVD)        || \
                                       ((CONFIG) == SYSCFG_Break_SRAMParity) || \
                                       ((CONFIG) == SYSCFG_Break_Lockup))

/**
  * @}
  */

/** @defgroup SYSCFG_flags_definition 
  * @{
  */

#define SYSCFG_FLAG_PE               SYSCFG_CFGR2_SRAM_PE

#define IS_SYSCFG_FLAG(FLAG) (((FLAG) == SYSCFG_FLAG_PE))

/**
  * @}
  */

/** @defgroup SYSCFG_ISR_WRAPPER
  * @{
  */
#define SYSCFG_ITLINE0                           ((unsigned int) 0x00000000)
#define SYSCFG_ITLINE1                           ((unsigned int) 0x00000001)
#define SYSCFG_ITLINE2                           ((unsigned int) 0x00000002)
#define SYSCFG_ITLINE3                           ((unsigned int) 0x00000003)
#define SYSCFG_ITLINE4                           ((unsigned int) 0x00000004)
#define SYSCFG_ITLINE5                           ((unsigned int) 0x00000005)
#define SYSCFG_ITLINE6                           ((unsigned int) 0x00000006)
#define SYSCFG_ITLINE7                           ((unsigned int) 0x00000007)
#define SYSCFG_ITLINE8                           ((unsigned int) 0x00000008)
#define SYSCFG_ITLINE9                           ((unsigned int) 0x00000009)
#define SYSCFG_ITLINE10                          ((unsigned int) 0x0000000A)
#define SYSCFG_ITLINE11                          ((unsigned int) 0x0000000B)
#define SYSCFG_ITLINE12                          ((unsigned int) 0x0000000C)
#define SYSCFG_ITLINE13                          ((unsigned int) 0x0000000D)
#define SYSCFG_ITLINE14                          ((unsigned int) 0x0000000E)
#define SYSCFG_ITLINE15                          ((unsigned int) 0x0000000F)
#define SYSCFG_ITLINE16                          ((unsigned int) 0x00000010)
#define SYSCFG_ITLINE17                          ((unsigned int) 0x00000011)
#define SYSCFG_ITLINE18                          ((unsigned int) 0x00000012)
#define SYSCFG_ITLINE19                          ((unsigned int) 0x00000013)
#define SYSCFG_ITLINE20                          ((unsigned int) 0x00000014)
#define SYSCFG_ITLINE21                          ((unsigned int) 0x00000015)
#define SYSCFG_ITLINE22                          ((unsigned int) 0x00000016)
#define SYSCFG_ITLINE23                          ((unsigned int) 0x00000017)
#define SYSCFG_ITLINE24                          ((unsigned int) 0x00000018)
#define SYSCFG_ITLINE25                          ((unsigned int) 0x00000019)
#define SYSCFG_ITLINE26                          ((unsigned int) 0x0000001A)
#define SYSCFG_ITLINE27                          ((unsigned int) 0x0000001B)
#define SYSCFG_ITLINE28                          ((unsigned int) 0x0000001C)
#define SYSCFG_ITLINE29                          ((unsigned int) 0x0000001D)
#define SYSCFG_ITLINE30                          ((unsigned int) 0x0000001E)
#define SYSCFG_ITLINE31                          ((unsigned int) 0x0000001F)

#define ITLINE_EWDG           ((unsigned int) ((SYSCFG_ITLINE0 << 0x18) | SYSCFG_ITLINE0_SR_EWDG)) /* EWDG Interrupt */
#define ITLINE_PVDOUT         ((unsigned int) ((SYSCFG_ITLINE1 << 0x18) | SYSCFG_ITLINE1_SR_PVDOUT)) /* Power voltage detection Interrupt */
#define ITLINE_VDDIO2         ((unsigned int) ((SYSCFG_ITLINE1 << 0x18) | SYSCFG_ITLINE1_SR_VDDIO2)) /* VDDIO2 Interrupt */
#define ITLINE_RTC_WAKEUP     ((unsigned int) ((SYSCFG_ITLINE2 << 0x18) | SYSCFG_ITLINE2_SR_RTC_WAKEUP)) /* RTC WAKEUP -> exti[20] Interrupt */
#define ITLINE_RTC_TSTAMP     ((unsigned int) ((SYSCFG_ITLINE2 << 0x18) | SYSCFG_ITLINE2_SR_RTC_TSTAMP)) /* RTC Time Stamp -> exti[19] interrupt */
#define ITLINE_RTC_ALRA       ((unsigned int) ((SYSCFG_ITLINE2 << 0x18) | SYSCFG_ITLINE2_SR_RTC_ALRA)) /* RTC Alarm -> exti[17] interrupt */
#define ITLINE_FLASH_ITF      ((unsigned int) ((SYSCFG_ITLINE3 << 0x18) | SYSCFG_ITLINE3_SR_FLASH_ITF)) /* Flash ITF Interrupt */
#define ITLINE_CRS            ((unsigned int) ((SYSCFG_ITLINE4 << 0x18) | SYSCFG_ITLINE4_SR_CRS)) /* CRS Interrupt */
#define ITLINE_CLK_CTRL       ((unsigned int) ((SYSCFG_ITLINE4 << 0x18) | SYSCFG_ITLINE4_SR_CLK_CTRL)) /* CLK Control Interrupt */
#define ITLINE_EXTI0          ((unsigned int) ((SYSCFG_ITLINE5 << 0x18) | SYSCFG_ITLINE5_SR_EXTI0)) /* External Interrupt 0 */
#define ITLINE_EXTI1          ((unsigned int) ((SYSCFG_ITLINE5 << 0x18) | SYSCFG_ITLINE5_SR_EXTI1)) /* External Interrupt 1 */
#define ITLINE_EXTI2          ((unsigned int) ((SYSCFG_ITLINE6 << 0x18) | SYSCFG_ITLINE6_SR_EXTI2)) /* External Interrupt 2 */
#define ITLINE_EXTI3          ((unsigned int) ((SYSCFG_ITLINE6 << 0x18) | SYSCFG_ITLINE6_SR_EXTI3)) /* External Interrupt 3 */
#define ITLINE_EXTI4          ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI4)) /* EXTI4 Interrupt */
#define ITLINE_EXTI5          ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI5)) /* EXTI5 Interrupt */
#define ITLINE_EXTI6          ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI6)) /* EXTI6 Interrupt */
#define ITLINE_EXTI7          ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI7)) /* EXTI7 Interrupt */
#define ITLINE_EXTI8          ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI8)) /* EXTI8 Interrupt */
#define ITLINE_EXTI9          ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI9)) /* EXTI9 Interrupt */
#define ITLINE_EXTI10         ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI10)) /* EXTI10 Interrupt */
#define ITLINE_EXTI11         ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI11)) /* EXTI11 Interrupt */
#define ITLINE_EXTI12         ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI12)) /* EXTI12 Interrupt */
#define ITLINE_EXTI13         ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI13)) /* EXTI13 Interrupt */
#define ITLINE_EXTI14         ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI14)) /* EXTI14 Interrupt */
#define ITLINE_EXTI15         ((unsigned int) ((SYSCFG_ITLINE7 << 0x18) | SYSCFG_ITLINE7_SR_EXTI15)) /* EXTI15 Interrupt */
#define ITLINE_TSC_EOA        ((unsigned int) ((SYSCFG_ITLINE8 << 0x18) | SYSCFG_ITLINE8_SR_TSC_EOA)) /* Touch control EOA Interrupt */
#define ITLINE_TSC_MCE        ((unsigned int) ((SYSCFG_ITLINE8 << 0x18) | SYSCFG_ITLINE8_SR_TSC_MCE)) /* Touch control MCE Interrupt */
#define ITLINE_DMA1_CH1       ((unsigned int) ((SYSCFG_ITLINE9 << 0x18) | SYSCFG_ITLINE9_SR_DMA1_CH1)) /* DMA1 Channel 1 Interrupt */
#define ITLINE_DMA1_CH2       ((unsigned int) ((SYSCFG_ITLINE10 << 0x18) | SYSCFG_ITLINE10_SR_DMA1_CH2)) /* DMA1 Channel 2 Interrupt */
#define ITLINE_DMA1_CH3       ((unsigned int) ((SYSCFG_ITLINE10 << 0x18) | SYSCFG_ITLINE10_SR_DMA1_CH3)) /* DMA1 Channel 3 Interrupt */
#define ITLINE_DMA2_CH1       ((unsigned int) ((SYSCFG_ITLINE10 << 0x18) | SYSCFG_ITLINE10_SR_DMA2_CH1)) /* DMA2 Channel 1 Interrupt */
#define ITLINE_DMA2_CH2       ((unsigned int) ((SYSCFG_ITLINE10 << 0x18) | SYSCFG_ITLINE10_SR_DMA2_CH2)) /* DMA2 Channel 2 Interrupt */
#define ITLINE_DMA1_CH4       ((unsigned int) ((SYSCFG_ITLINE11 << 0x18) | SYSCFG_ITLINE11_SR_DMA1_CH4)) /* DMA1 Channel 4 Interrupt */
#define ITLINE_DMA1_CH5       ((unsigned int) ((SYSCFG_ITLINE11 << 0x18) | SYSCFG_ITLINE11_SR_DMA1_CH5)) /* DMA1 Channel 5 Interrupt */
#define ITLINE_DMA1_CH6       ((unsigned int) ((SYSCFG_ITLINE11 << 0x18) | SYSCFG_ITLINE11_SR_DMA1_CH6)) /* DMA1 Channel 6 Interrupt */
#define ITLINE_DMA1_CH7       ((unsigned int) ((SYSCFG_ITLINE11 << 0x18) | SYSCFG_ITLINE11_SR_DMA1_CH7)) /* DMA1 Channel 7 Interrupt */
#define ITLINE_DMA2_CH3       ((unsigned int) ((SYSCFG_ITLINE11 << 0x18) | SYSCFG_ITLINE11_SR_DMA2_CH3)) /* DMA2 Channel 3 Interrupt */
#define ITLINE_DMA2_CH4       ((unsigned int) ((SYSCFG_ITLINE11 << 0x18) | SYSCFG_ITLINE11_SR_DMA2_CH4)) /* DMA2 Channel 4 Interrupt */
#define ITLINE_DMA2_CH5       ((unsigned int) ((SYSCFG_ITLINE11 << 0x18) | SYSCFG_ITLINE11_SR_DMA2_CH5)) /* DMA2 Channel 5 Interrupt */
#define ITLINE_ADC            ((unsigned int) ((SYSCFG_ITLINE12 << 0x18) | SYSCFG_ITLINE12_SR_ADC)) /* ADC Interrupt */
#define ITLINE_COMP1          ((unsigned int) ((SYSCFG_ITLINE12 << 0x18) | SYSCFG_ITLINE12_SR_COMP1)) /* COMP1 Interrupt -> exti[21] */
#define ITLINE_COMP2          ((unsigned int) ((SYSCFG_ITLINE12 << 0x18) | SYSCFG_ITLINE12_SR_COMP2)) /* COMP2 Interrupt -> exti[21] */
#define ITLINE_TIM1_BRK       ((unsigned int) ((SYSCFG_ITLINE13 << 0x18) | SYSCFG_ITLINE13_SR_TIM1_BRK)) /* TIM1 BRK Interrupt */
#define ITLINE_TIM1_UPD       ((unsigned int) ((SYSCFG_ITLINE13 << 0x18) | SYSCFG_ITLINE13_SR_TIM1_UPD)) /* TIM1 UPD Interrupt */
#define ITLINE_TIM1_TRG       ((unsigned int) ((SYSCFG_ITLINE13 << 0x18) | SYSCFG_ITLINE13_SR_TIM1_TRG)) /* TIM1 TRG Interrupt */
#define ITLINE_TIM1_CCU       ((unsigned int) ((SYSCFG_ITLINE13 << 0x18) | SYSCFG_ITLINE13_SR_TIM1_CCU)) /* TIM1 CCU Interrupt */
#define ITLINE_TIM1_CC        ((unsigned int) ((SYSCFG_ITLINE14 << 0x18) | SYSCFG_ITLINE14_SR_TIM1_CC)) /* TIM1 CC Interrupt */
#define ITLINE_TIM2           ((unsigned int) ((SYSCFG_ITLINE15 << 0x18) | SYSCFG_ITLINE15_SR_TIM2_GLB)) /* TIM2 Interrupt */
#define ITLINE_TIM3           ((unsigned int) ((SYSCFG_ITLINE16 << 0x18) | SYSCFG_ITLINE16_SR_TIM3_GLB)) /* TIM3 Interrupt */
#define ITLINE_DAC            ((unsigned int) ((SYSCFG_ITLINE17 << 0x18) | SYSCFG_ITLINE17_SR_DAC)) /* DAC Interrupt */
#define ITLINE_TIM6           ((unsigned int) ((SYSCFG_ITLINE17 << 0x18) | SYSCFG_ITLINE17_SR_TIM6_GLB)) /* TIM6 Interrupt */
#define ITLINE_TIM7           ((unsigned int) ((SYSCFG_ITLINE18 << 0x18) | SYSCFG_ITLINE18_SR_TIM7_GLB)) /* TIM7 Interrupt */
#define ITLINE_TIM14          ((unsigned int) ((SYSCFG_ITLINE19 << 0x18) | SYSCFG_ITLINE19_SR_TIM14_GLB)) /* TIM14 Interrupt */
#define ITLINE_TIM15          ((unsigned int) ((SYSCFG_ITLINE20 << 0x18) | SYSCFG_ITLINE20_SR_TIM15_GLB)) /* TIM15 Interrupt */
#define ITLINE_TIM16          ((unsigned int) ((SYSCFG_ITLINE21 << 0x18) | SYSCFG_ITLINE21_SR_TIM16_GLB)) /* TIM16 Interrupt */
#define ITLINE_TIM17          ((unsigned int) ((SYSCFG_ITLINE22 << 0x18) | SYSCFG_ITLINE22_SR_TIM17_GLB)) /* TIM17 Interrupt */
#define ITLINE_I2C1           ((unsigned int) ((SYSCFG_ITLINE23 << 0x18) | SYSCFG_ITLINE23_SR_I2C1_GLB)) /* I2C1 Interrupt -> exti[23] */
#define ITLINE_I2C2           ((unsigned int) ((SYSCFG_ITLINE24 << 0x18) | SYSCFG_ITLINE24_SR_I2C2_GLB)) /* I2C2 Interrupt */
#define ITLINE_SPI1           ((unsigned int) ((SYSCFG_ITLINE25 << 0x18) | SYSCFG_ITLINE25_SR_SPI1)) /* I2C1 Interrupt -> exti[23] */
#define ITLINE_SPI2           ((unsigned int) ((SYSCFG_ITLINE26 << 0x18) | SYSCFG_ITLINE26_SR_SPI2)) /* SPI1 Interrupt */
#define ITLINE_USART1         ((unsigned int) ((SYSCFG_ITLINE27 << 0x18) | SYSCFG_ITLINE27_SR_USART1_GLB)) /*!< USART1 GLB Interrupt -> exti[25] */
#define ITLINE_USART2         ((unsigned int) ((SYSCFG_ITLINE28 << 0x18) | SYSCFG_ITLINE28_SR_USART2_GLB)) /*!< USART2 GLB Interrupt -> exti[26] */
#define ITLINE_USART3         ((unsigned int) ((SYSCFG_ITLINE29 << 0x18) | SYSCFG_ITLINE29_SR_USART3_GLB)) /* USART3 Interrupt */
#define ITLINE_USART4         ((unsigned int) ((SYSCFG_ITLINE29 << 0x18) | SYSCFG_ITLINE29_SR_USART4_GLB)) /* USART4 Interrupt */
#define ITLINE_USART5         ((unsigned int) ((SYSCFG_ITLINE29 << 0x18) | SYSCFG_ITLINE29_SR_USART5_GLB)) /* USART5 Interrupt */
#define ITLINE_USART6         ((unsigned int) ((SYSCFG_ITLINE29 << 0x18) | SYSCFG_ITLINE29_SR_USART6_GLB)) /* USART6 Interrupt */
#define ITLINE_USART7         ((unsigned int) ((SYSCFG_ITLINE29 << 0x18) | SYSCFG_ITLINE29_SR_USART7_GLB)) /* USART7 Interrupt */
#define ITLINE_USART8         ((unsigned int) ((SYSCFG_ITLINE29 << 0x18) | SYSCFG_ITLINE29_SR_USART8_GLB)) /* USART8 Interrupt */
#define ITLINE_CAN            ((unsigned int) ((SYSCFG_ITLINE30 << 0x18) | SYSCFG_ITLINE30_SR_CAN)) /* CAN Interrupt */
#define ITLINE_CEC            ((unsigned int) ((SYSCFG_ITLINE30 << 0x18) | SYSCFG_ITLINE30_SR_CEC)) /* CEC Interrupt -> exti[27] */

#define IS_SYSCFG_ITLINE(LINE) (((LINE) == ITLINE_EWDG)       || \
                                ((LINE) == ITLINE_PVDOUT)     || \
                                ((LINE) == ITLINE_VDDIO2)     || \
                                ((LINE) == ITLINE_RTC_WAKEUP) || \
                                ((LINE) == ITLINE_RTC_TSTAMP) || \
                                ((LINE) == ITLINE_RTC_ALRA)   || \
                                ((LINE) == ITLINE_FLASH_ITF)  || \
                                ((LINE) == ITLINE_CRS)        || \
                                ((LINE) == ITLINE_CLK_CTRL)   || \
                                ((LINE) == ITLINE_EXTI0)      || \
                                ((LINE) == ITLINE_EXTI1)      || \
                                ((LINE) == ITLINE_EXTI2)      || \
                                ((LINE) == ITLINE_EXTI3)      || \
                                ((LINE) == ITLINE_EXTI4)      || \
                                ((LINE) == ITLINE_EXTI5)      || \
                                ((LINE) == ITLINE_EXTI6)      || \
                                ((LINE) == ITLINE_EXTI7)      || \
                                ((LINE) == ITLINE_EXTI8)      || \
                                ((LINE) == ITLINE_EXTI9)      || \
                                ((LINE) == ITLINE_EXTI10)     || \
                                ((LINE) == ITLINE_EXTI11)     || \
                                ((LINE) == ITLINE_EXTI12)     || \
                                ((LINE) == ITLINE_EXTI13)     || \
                                ((LINE) == ITLINE_EXTI14)     || \
                                ((LINE) == ITLINE_EXTI15)     || \
                                ((LINE) == ITLINE_TSC_EOA)    || \
                                ((LINE) == ITLINE_TSC_MCE)    || \
                                ((LINE) == ITLINE_DMA1_CH1)   || \
                                ((LINE) == ITLINE_DMA1_CH2)   || \
                                ((LINE) == ITLINE_DMA1_CH3)   || \
                                ((LINE) == ITLINE_DMA1_CH4)   || \
                                ((LINE) == ITLINE_DMA1_CH5)   || \
                                ((LINE) == ITLINE_DMA1_CH6)   || \
                                ((LINE) == ITLINE_DMA1_CH7)   || \
                                ((LINE) == ITLINE_DMA2_CH1)   || \
                                ((LINE) == ITLINE_DMA2_CH2)   || \
                                ((LINE) == ITLINE_DMA2_CH3)   || \
                                ((LINE) == ITLINE_DMA2_CH4)   || \
                                ((LINE) == ITLINE_DMA2_CH5)   || \
                                ((LINE) == ITLINE_ADC)        || \
                                ((LINE) == ITLINE_COMP1)      || \
                                ((LINE) == ITLINE_COMP2)      || \
                                ((LINE) == ITLINE_TIM1_BRK)   || \
                                ((LINE) == ITLINE_TIM1_UPD)   || \
                                ((LINE) == ITLINE_TIM1_TRG)   || \
                                ((LINE) == ITLINE_TIM1_CCU)   || \
                                ((LINE) == ITLINE_TIM1_CC)    || \
                                ((LINE) == ITLINE_TIM2)       || \
                                ((LINE) == ITLINE_TIM3)       || \
                                ((LINE) == ITLINE_DAC)        || \
                                ((LINE) == ITLINE_TIM6)       || \
                                ((LINE) == ITLINE_TIM7)       || \
                                ((LINE) == ITLINE_TIM14)      || \
                                ((LINE) == ITLINE_TIM15)      || \
                                ((LINE) == ITLINE_TIM16)      || \
                                ((LINE) == ITLINE_TIM17)      || \
                                ((LINE) == ITLINE_I2C1)       || \
                                ((LINE) == ITLINE_I2C2)       || \
                                ((LINE) == ITLINE_SPI1)       || \
                                ((LINE) == ITLINE_SPI2)       || \
                                ((LINE) == ITLINE_USART1)     || \
                                ((LINE) == ITLINE_USART2)     || \
                                ((LINE) == ITLINE_USART3)     || \
                                ((LINE) == ITLINE_USART4)     || \
                                ((LINE) == ITLINE_USART5)     || \
                                ((LINE) == ITLINE_USART6)     || \
                                ((LINE) == ITLINE_USART7)     || \
                                ((LINE) == ITLINE_USART8)     || \
                                ((LINE) == ITLINE_CAN)        || \
                                ((LINE) == ITLINE_CEC))

/**
  * @}
  */
/** @defgroup IRDA_ENV_SEL
  * @{
  */
#define SYSCFG_IRDA_ENV_SEL_TIM16     (SYSCFG_CFGR1_IRDA_ENV_SEL_0&SYSCFG_CFGR1_IRDA_ENV_SEL_1)    /* Timer16 is selected as IRDA Modulation envelope source */
#define SYSCFG_IRDA_ENV_SEL_USART1    (SYSCFG_CFGR1_IRDA_ENV_SEL_0)  /* USART1 is selected as IRDA Modulation envelope source.*/
#define SYSCFG_IRDA_ENV_SEL_USART4    (SYSCFG_CFGR1_IRDA_ENV_SEL_1)  /* USART4 is selected as IRDA Modulation envelope source.*/

#define IS_SYSCFG_IRDA_ENV(ENV) (((ENV) == SYSCFG_IRDA_ENV_SEL_TIM16)      || \
                                 ((ENV) == SYSCFG_IRDA_ENV_SEL_USART1)     || \
                                 ((ENV) == SYSCFG_IRDA_ENV_SEL_USART4))
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/*  Function used to set the SYSCFG configuration to the default reset state **/
void SYSCFG_DeInit(void);

/* SYSCFG configuration functions *********************************************/ 
void SYSCFG_MemoryRemapConfig(unsigned int SYSCFG_MemoryRemap);
void SYSCFG_DMAChannelRemapConfig(unsigned int SYSCFG_DMARemap, FunctionalState NewState);
void SYSCFG_I2CFastModePlusConfig(unsigned int SYSCFG_I2CFastModePlus, FunctionalState NewState);
void SYSCFG_IRDAEnvSelection(unsigned int SYSCFG_IRDAEnv);
void SYSCFG_EXTILineConfig(unsigned char EXTI_PortSourceGPIOx, unsigned char EXTI_PinSourcex);
unsigned int SYSCFG_GetPendingIT(unsigned int ITSourceLine);
void SYSCFG_BreakConfig(unsigned int SYSCFG_Break);
FlagStatus SYSCFG_GetFlagStatus(unsigned int SYSCFG_Flag);
void SYSCFG_ClearFlag(unsigned int SYSCFG_Flag);

#ifdef __cplusplus
}
#endif

#endif /*__STM32F0XX_SYSCFG_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
