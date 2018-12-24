/**
  ******************************************************************************
  * @file    stm32f0xx_i2c.h
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    05-December-2014
  * @brief   This file contains all the functions prototypes for the I2C firmware
  *          library
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F0XX_I2C_H
#define __STM32F0XX_I2C_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/** @addtogroup STM32F0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/**
  * @brief  I2C Init structure definition
  */

typedef struct
{
  unsigned int I2C_Timing;              /*!< Specifies the I2C_TIMINGR_register value.
                                         This parameter must be set by referring to I2C_Timing_Config_Tool*/

  unsigned int I2C_AnalogFilter;        /*!< Enables or disables analog noise filter.
                                         This parameter can be a value of @ref I2C_Analog_Filter*/

  unsigned int I2C_DigitalFilter;       /*!< Configures the digital noise filter.
                                         This parameter can be a number between 0x00 and 0x0F*/

  unsigned int I2C_Mode;                /*!< Specifies the I2C mode.
                                         This parameter can be a value of @ref I2C_mode*/

  unsigned int I2C_OwnAddress1;         /*!< Specifies the device own address 1.
                                         This parameter can be a 7-bit or 10-bit address*/

  unsigned int I2C_Ack;                 /*!< Enables or disables the acknowledgement.
                                         This parameter can be a value of @ref I2C_acknowledgement*/

  unsigned int I2C_AcknowledgedAddress; /*!< Specifies if 7-bit or 10-bit address is acknowledged.
                                         This parameter can be a value of @ref I2C_acknowledged_address*/
}I2C_InitTypeDef;

/* Exported constants --------------------------------------------------------*/


/** @defgroup I2C_Exported_Constants
  * @{
  */

#define IS_I2C_ALL_PERIPH(PERIPH)       (((PERIPH) == I2C1) || \
                                         ((PERIPH) == I2C2))
                                         
#define IS_I2C_1_PERIPH(PERIPH)         ((PERIPH) == I2C1) 

/** @defgroup I2C_Analog_Filter 
  * @{
  */

#define I2C_AnalogFilter_Enable         ((unsigned int)0x00000000)
#define I2C_AnalogFilter_Disable        I2C_CR1_ANFOFF

#define IS_I2C_ANALOG_FILTER(FILTER)    (((FILTER) == I2C_AnalogFilter_Enable) || \
                                         ((FILTER) == I2C_AnalogFilter_Disable))
/**
  * @}
  */

/** @defgroup I2C_Digital_Filter
  * @{
  */

#define IS_I2C_DIGITAL_FILTER(FILTER)   ((FILTER) <= 0x0000000F)
/**
  * @}
  */

/** @defgroup I2C_mode 
  * @{
  */

#define I2C_Mode_I2C                    ((unsigned int)0x00000000)
#define I2C_Mode_SMBusDevice            I2C_CR1_SMBDEN
#define I2C_Mode_SMBusHost              I2C_CR1_SMBHEN

#define IS_I2C_MODE(MODE)               (((MODE) == I2C_Mode_I2C) || \
                                         ((MODE) == I2C_Mode_SMBusDevice) || \
                                         ((MODE) == I2C_Mode_SMBusHost))
/**
  * @}
  */

/** @defgroup I2C_acknowledgement
  * @{
  */

#define I2C_Ack_Enable                  ((unsigned int)0x00000000)
#define I2C_Ack_Disable                 I2C_CR2_NACK

#define IS_I2C_ACK(ACK)                 (((ACK) == I2C_Ack_Enable) || \
                                         ((ACK) == I2C_Ack_Disable))
/**
  * @}
  */

/** @defgroup I2C_acknowledged_address
  * @{
  */

#define I2C_AcknowledgedAddress_7bit    ((unsigned int)0x00000000)
#define I2C_AcknowledgedAddress_10bit   I2C_OAR1_OA1MODE

#define IS_I2C_ACKNOWLEDGE_ADDRESS(ADDRESS) (((ADDRESS) == I2C_AcknowledgedAddress_7bit) || \
                                             ((ADDRESS) == I2C_AcknowledgedAddress_10bit))
/**
  * @}
  */ 

/** @defgroup I2C_own_address1
  * @{
  */

#define IS_I2C_OWN_ADDRESS1(ADDRESS1)   ((ADDRESS1) <= (unsigned int)0x000003FF)
/**
  * @}
  */

/** @defgroup I2C_transfer_direction 
  * @{
  */

#define I2C_Direction_Transmitter       ((unsigned short)0x0000)
#define I2C_Direction_Receiver          ((unsigned short)0x0400)

#define IS_I2C_DIRECTION(DIRECTION)     (((DIRECTION) == I2C_Direction_Transmitter) || \
                                         ((DIRECTION) == I2C_Direction_Receiver))
/**
  * @}
  */

/** @defgroup I2C_DMA_transfer_requests 
  * @{
  */

#define I2C_DMAReq_Tx                   I2C_CR1_TXDMAEN
#define I2C_DMAReq_Rx                   I2C_CR1_RXDMAEN

#define IS_I2C_DMA_REQ(REQ)             ((((REQ) & (unsigned int)0xFFFF3FFF) == 0x00) && ((REQ) != 0x00))
/**
  * @}
  */

/** @defgroup I2C_slave_address
  * @{
  */

#define IS_I2C_SLAVE_ADDRESS(ADDRESS)   ((ADDRESS) <= (unsigned short)0x03FF)
/**
  * @}
  */


/** @defgroup I2C_own_address2
  * @{
  */

#define IS_I2C_OWN_ADDRESS2(ADDRESS2)   ((ADDRESS2) <= (unsigned short)0x00FF)

/**
  * @}
  */

/** @defgroup I2C_own_address2_mask
  * @{
  */

#define I2C_OA2_NoMask                  ((unsigned char)0x00)
#define I2C_OA2_Mask01                  ((unsigned char)0x01)
#define I2C_OA2_Mask02                  ((unsigned char)0x02)
#define I2C_OA2_Mask03                  ((unsigned char)0x03)
#define I2C_OA2_Mask04                  ((unsigned char)0x04)
#define I2C_OA2_Mask05                  ((unsigned char)0x05)
#define I2C_OA2_Mask06                  ((unsigned char)0x06)
#define I2C_OA2_Mask07                  ((unsigned char)0x07)

#define IS_I2C_OWN_ADDRESS2_MASK(MASK)  (((MASK) == I2C_OA2_NoMask) || \
                                         ((MASK) == I2C_OA2_Mask01) || \
                                         ((MASK) == I2C_OA2_Mask02) || \
                                         ((MASK) == I2C_OA2_Mask03) || \
                                         ((MASK) == I2C_OA2_Mask04) || \
                                         ((MASK) == I2C_OA2_Mask05) || \
                                         ((MASK) == I2C_OA2_Mask06) || \
                                         ((MASK) == I2C_OA2_Mask07))  

/**
  * @}
  */

/** @defgroup I2C_timeout
  * @{
  */

#define IS_I2C_TIMEOUT(TIMEOUT)   ((TIMEOUT) <= (unsigned short)0x0FFF)

/**
  * @}
  */

/** @defgroup I2C_registers 
  * @{
  */

#define I2C_Register_CR1                ((unsigned char)0x00)
#define I2C_Register_CR2                ((unsigned char)0x04)
#define I2C_Register_OAR1               ((unsigned char)0x08)
#define I2C_Register_OAR2               ((unsigned char)0x0C)
#define I2C_Register_TIMINGR            ((unsigned char)0x10)
#define I2C_Register_TIMEOUTR           ((unsigned char)0x14)
#define I2C_Register_ISR                ((unsigned char)0x18)
#define I2C_Register_ICR                ((unsigned char)0x1C)
#define I2C_Register_PECR               ((unsigned char)0x20)
#define I2C_Register_RXDR               ((unsigned char)0x24)
#define I2C_Register_TXDR               ((unsigned char)0x28)

#define IS_I2C_REGISTER(REGISTER)       (((REGISTER) == I2C_Register_CR1) || \
                                         ((REGISTER) == I2C_Register_CR2) || \
                                         ((REGISTER) == I2C_Register_OAR1) || \
                                         ((REGISTER) == I2C_Register_OAR2) || \
                                         ((REGISTER) == I2C_Register_TIMINGR) || \
                                         ((REGISTER) == I2C_Register_TIMEOUTR) || \
                                         ((REGISTER) == I2C_Register_ISR) || \
                                         ((REGISTER) == I2C_Register_ICR) || \
                                         ((REGISTER) == I2C_Register_PECR) || \
                                         ((REGISTER) == I2C_Register_RXDR) || \
                                         ((REGISTER) == I2C_Register_TXDR))
/**
  * @}
  */

/** @defgroup I2C_interrupts_definition 
  * @{
  */

#define I2C_IT_ERRI                     I2C_CR1_ERRIE
#define I2C_IT_TCI                      I2C_CR1_TCIE
#define I2C_IT_STOPI                    I2C_CR1_STOPIE
#define I2C_IT_NACKI                    I2C_CR1_NACKIE
#define I2C_IT_ADDRI                    I2C_CR1_ADDRIE
#define I2C_IT_RXI                      I2C_CR1_RXIE
#define I2C_IT_TXI                      I2C_CR1_TXIE

#define IS_I2C_CONFIG_IT(IT)            ((((IT) & (unsigned int)0xFFFFFF01) == 0x00) && ((IT) != 0x00))

/**
  * @}
  */

/** @defgroup I2C_flags_definition 
  * @{
  */

#define  I2C_FLAG_TXE                   I2C_ISR_TXE
#define  I2C_FLAG_TXIS                  I2C_ISR_TXIS
#define  I2C_FLAG_RXNE                  I2C_ISR_RXNE
#define  I2C_FLAG_ADDR                  I2C_ISR_ADDR
#define  I2C_FLAG_NACKF                 I2C_ISR_NACKF
#define  I2C_FLAG_STOPF                 I2C_ISR_STOPF
#define  I2C_FLAG_TC                    I2C_ISR_TC
#define  I2C_FLAG_TCR                   I2C_ISR_TCR
#define  I2C_FLAG_BERR                  I2C_ISR_BERR
#define  I2C_FLAG_ARLO                  I2C_ISR_ARLO
#define  I2C_FLAG_OVR                   I2C_ISR_OVR
#define  I2C_FLAG_PECERR                I2C_ISR_PECERR
#define  I2C_FLAG_TIMEOUT               I2C_ISR_TIMEOUT
#define  I2C_FLAG_ALERT                 I2C_ISR_ALERT
#define  I2C_FLAG_BUSY                  I2C_ISR_BUSY

#define IS_I2C_CLEAR_FLAG(FLAG)         ((((FLAG) & (unsigned int)0xFFFF4000) == 0x00) && ((FLAG) != 0x00))

#define IS_I2C_GET_FLAG(FLAG)           (((FLAG) == I2C_FLAG_TXE) || ((FLAG) == I2C_FLAG_TXIS) || \
                                         ((FLAG) == I2C_FLAG_RXNE) || ((FLAG) == I2C_FLAG_ADDR) || \
                                         ((FLAG) == I2C_FLAG_NACKF) || ((FLAG) == I2C_FLAG_STOPF) || \
                                         ((FLAG) == I2C_FLAG_TC) || ((FLAG) == I2C_FLAG_TCR) || \
                                         ((FLAG) == I2C_FLAG_BERR) || ((FLAG) == I2C_FLAG_ARLO) || \
                                         ((FLAG) == I2C_FLAG_OVR) || ((FLAG) == I2C_FLAG_PECERR) || \
                                         ((FLAG) == I2C_FLAG_TIMEOUT) || ((FLAG) == I2C_FLAG_ALERT) || \
                                         ((FLAG) == I2C_FLAG_BUSY))

/**
  * @}
  */


/** @defgroup I2C_interrupts_definition 
  * @{
  */

#define  I2C_IT_TXIS                    I2C_ISR_TXIS
#define  I2C_IT_RXNE                    I2C_ISR_RXNE
#define  I2C_IT_ADDR                    I2C_ISR_ADDR
#define  I2C_IT_NACKF                   I2C_ISR_NACKF
#define  I2C_IT_STOPF                   I2C_ISR_STOPF
#define  I2C_IT_TC                      I2C_ISR_TC
#define  I2C_IT_TCR                     I2C_ISR_TCR
#define  I2C_IT_BERR                    I2C_ISR_BERR
#define  I2C_IT_ARLO                    I2C_ISR_ARLO
#define  I2C_IT_OVR                     I2C_ISR_OVR
#define  I2C_IT_PECERR                  I2C_ISR_PECERR
#define  I2C_IT_TIMEOUT                 I2C_ISR_TIMEOUT
#define  I2C_IT_ALERT                   I2C_ISR_ALERT

#define IS_I2C_CLEAR_IT(IT)             ((((IT) & (unsigned int)0xFFFFC001) == 0x00) && ((IT) != 0x00))
                               
#define IS_I2C_GET_IT(IT)               (((IT) == I2C_IT_TXIS) || ((IT) == I2C_IT_RXNE) || \
                                         ((IT) == I2C_IT_ADDR) || ((IT) == I2C_IT_NACKF) || \
                                         ((IT) == I2C_IT_STOPF) || ((IT) == I2C_IT_TC) || \
                                         ((IT) == I2C_IT_TCR) || ((IT) == I2C_IT_BERR) || \
                                         ((IT) == I2C_IT_ARLO) || ((IT) == I2C_IT_OVR) || \
                                         ((IT) == I2C_IT_PECERR) || ((IT) == I2C_IT_TIMEOUT) || \
                                         ((IT) == I2C_IT_ALERT))
                               

/**
  * @}
  */

/** @defgroup I2C_ReloadEndMode_definition 
  * @{
  */

#define  I2C_Reload_Mode                I2C_CR2_RELOAD
#define  I2C_AutoEnd_Mode               I2C_CR2_AUTOEND
#define  I2C_SoftEnd_Mode               ((unsigned int)0x00000000)

                              
#define IS_RELOAD_END_MODE(MODE)        (((MODE) == I2C_Reload_Mode) || \
                                         ((MODE) == I2C_AutoEnd_Mode) || \
                                         ((MODE) == I2C_SoftEnd_Mode))
                               

/**
  * @}
  */

/** @defgroup I2C_StartStopMode_definition 
  * @{
  */

#define  I2C_No_StartStop                 ((unsigned int)0x00000000)
#define  I2C_Generate_Stop                I2C_CR2_STOP
#define  I2C_Generate_Start_Read          (unsigned int)(I2C_CR2_START | I2C_CR2_RD_WRN)
#define  I2C_Generate_Start_Write         I2C_CR2_START

                              
#define IS_START_STOP_MODE(MODE)        (((MODE) == I2C_Generate_Stop) || \
                                         ((MODE) == I2C_Generate_Start_Read) || \
                                         ((MODE) == I2C_Generate_Start_Write) || \
                                         ((MODE) == I2C_No_StartStop))
                               

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */


/* Initialization and Configuration functions *********************************/
void I2C_DeInit(I2C_TypeDef* I2Cx);
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx);
void I2C_ITConfig(I2C_TypeDef* I2Cx, unsigned int I2C_IT, FunctionalState NewState);
void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_StopModeCmd(I2C_TypeDef* I2Cx, FunctionalState NewState); /*!< not applicable for STM32F030 devices */
void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, unsigned short Address, unsigned char Mask);
void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_SlaveByteControlCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_SlaveAddressConfig(I2C_TypeDef* I2Cx, unsigned short Address);
void I2C_10BitAddressingModeCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);

/* Communications handling functions ******************************************/
void I2C_AutoEndCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_ReloadCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_NumberOfBytesConfig(I2C_TypeDef* I2Cx, unsigned char Number_Bytes);
void I2C_MasterRequestConfig(I2C_TypeDef* I2Cx, unsigned short I2C_Direction);
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_10BitAddressHeaderCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);
unsigned char I2C_GetAddressMatched(I2C_TypeDef* I2Cx);
unsigned short I2C_GetTransferDirection(I2C_TypeDef* I2Cx);
void I2C_TransferHandling(I2C_TypeDef* I2Cx, unsigned short Address, unsigned char Number_Bytes, unsigned int ReloadEndMode, unsigned int StartStopMode);

/*  SMBUS management functions ************************************************/
void I2C_SMBusAlertCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_ClockTimeoutCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_ExtendedClockTimeoutCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_IdleClockTimeoutCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_TimeoutAConfig(I2C_TypeDef* I2Cx, unsigned short Timeout);
void I2C_TimeoutBConfig(I2C_TypeDef* I2Cx, unsigned short Timeout);
void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_PECRequestCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
unsigned char I2C_GetPEC(I2C_TypeDef* I2Cx);

/* I2C registers management functions *****************************************/
unsigned int I2C_ReadRegister(I2C_TypeDef* I2Cx, unsigned char I2C_Register);

/* Data transfers management functions ****************************************/
void I2C_SendData(I2C_TypeDef* I2Cx, unsigned char Data);
unsigned char I2C_ReceiveData(I2C_TypeDef* I2Cx);

/* DMA transfers management functions *****************************************/
void I2C_DMACmd(I2C_TypeDef* I2Cx, unsigned int I2C_DMAReq, FunctionalState NewState);

/* Interrupts and flags management functions **********************************/
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, unsigned int I2C_FLAG);
void I2C_ClearFlag(I2C_TypeDef* I2Cx, unsigned int I2C_FLAG);
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, unsigned int I2C_IT);
void I2C_ClearITPendingBit(I2C_TypeDef* I2Cx, unsigned int I2C_IT);


#ifdef __cplusplus
}
#endif

#endif /*__STM32F0XX_I2C_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
