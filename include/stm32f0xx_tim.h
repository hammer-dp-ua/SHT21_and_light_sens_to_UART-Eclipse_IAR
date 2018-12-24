/**
  ******************************************************************************
  * @file    stm32f0xx_tim.h
  * @author  MCD Application Team
  * @version V1.5.0
  * @date    05-December-2014
  * @brief   This file contains all the functions prototypes for the TIM 
  *          firmware library. 
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
#ifndef __STM32F0XX_TIM_H
#define __STM32F0XX_TIM_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/** @addtogroup STM32F0xx_StdPeriph_Driver
  * @{
  */

/** @addtogroup TIM
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/

/** 
  * @brief  TIM Time Base Init structure definition
  * @note   This sturcture is used with all TIMx.
  */

typedef struct
{
  unsigned short TIM_Prescaler;         /*!< Specifies the prescaler value used to divide the TIM clock.
                                       This parameter can be a number between 0x0000 and 0xFFFF */

  unsigned short TIM_CounterMode;       /*!< Specifies the counter mode.
                                       This parameter can be a value of @ref TIM_Counter_Mode */

  unsigned int TIM_Period;            /*!< Specifies the period value to be loaded into the active
                                       Auto-Reload Register at the next update event.
                                       This parameter must be a number between 0x0000 and 0xFFFF.  */ 

  unsigned short TIM_ClockDivision;     /*!< Specifies the clock division.
                                      This parameter can be a value of @ref TIM_Clock_Division_CKD */

  unsigned char TIM_RepetitionCounter;  /*!< Specifies the repetition counter value. Each time the RCR downcounter
                                       reaches zero, an update event is generated and counting restarts
                                       from the RCR value (N).
                                       This means in PWM mode that (N+1) corresponds to:
                                          - the number of PWM periods in edge-aligned mode
                                          - the number of half PWM period in center-aligned mode
                                       This parameter must be a number between 0x00 and 0xFF. 
                                       @note This parameter is valid only for TIM1. */
} TIM_TimeBaseInitTypeDef;       

/** 
  * @brief  TIM Output Compare Init structure definition  
  */

typedef struct
{
  unsigned short TIM_OCMode;        /*!< Specifies the TIM mode.
                                   This parameter can be a value of @ref TIM_Output_Compare_and_PWM_modes */

  unsigned short TIM_OutputState;   /*!< Specifies the TIM Output Compare state.
                                   This parameter can be a value of @ref TIM_Output_Compare_state */

  unsigned short TIM_OutputNState;  /*!< Specifies the TIM complementary Output Compare state.
                                   This parameter can be a value of @ref TIM_Output_Compare_N_state
                                   @note This parameter is valid only for TIM1. */

  unsigned int TIM_Pulse;         /*!< Specifies the pulse value to be loaded into the Capture Compare Register.
                                   This parameter can be a number between 0x0000 and 0xFFFF ( or 0xFFFFFFFF
                                   for TIM2) */

  unsigned short TIM_OCPolarity;    /*!< Specifies the output polarity.
                                   This parameter can be a value of @ref TIM_Output_Compare_Polarity */

  unsigned short TIM_OCNPolarity;   /*!< Specifies the complementary output polarity.
                                   This parameter can be a value of @ref TIM_Output_Compare_N_Polarity
                                   @note This parameter is valid only for TIM1. */

  unsigned short TIM_OCIdleState;   /*!< Specifies the TIM Output Compare pin state during Idle state.
                                   This parameter can be a value of @ref TIM_Output_Compare_Idle_State
                                   @note This parameter is valid only for TIM1. */

  unsigned short TIM_OCNIdleState;  /*!< Specifies the TIM Output Compare pin state during Idle state.
                                   This parameter can be a value of @ref TIM_Output_Compare_N_Idle_State
                                   @note This parameter is valid only for TIM1. */
} TIM_OCInitTypeDef;

/** 
  * @brief  TIM Input Capture Init structure definition  
  */

typedef struct
{

  unsigned short TIM_Channel;      /*!< Specifies the TIM channel.
                                  This parameter can be a value of @ref TIM_Channel */

  unsigned short TIM_ICPolarity;   /*!< Specifies the active edge of the input signal.
                                  This parameter can be a value of @ref TIM_Input_Capture_Polarity */

  unsigned short TIM_ICSelection;  /*!< Specifies the input.
                                  This parameter can be a value of @ref TIM_Input_Capture_Selection */

  unsigned short TIM_ICPrescaler;  /*!< Specifies the Input Capture Prescaler.
                                  This parameter can be a value of @ref TIM_Input_Capture_Prescaler */

  unsigned short TIM_ICFilter;     /*!< Specifies the input capture filter.
                                  This parameter can be a number between 0x0 and 0xF */
} TIM_ICInitTypeDef;

/** 
  * @brief  TIM_BDTR structure definition 
  * @note   This sturcture is used only with TIM1.    
  */

typedef struct
{

  unsigned short TIM_OSSRState;        /*!< Specifies the Off-State selection used in Run mode.
                                      This parameter can be a value of @ref TIM_OSSR_Off_State_Selection_for_Run_mode_state */

  unsigned short TIM_OSSIState;        /*!< Specifies the Off-State used in Idle state.
                                      This parameter can be a value of @ref TIM_OSSI_Off_State_Selection_for_Idle_mode_state */

  unsigned short TIM_LOCKLevel;        /*!< Specifies the LOCK level parameters.
                                      This parameter can be a value of @ref TIM_Lock_level */ 

  unsigned short TIM_DeadTime;         /*!< Specifies the delay time between the switching-off and the
                                      switching-on of the outputs.
                                      This parameter can be a number between 0x00 and 0xFF  */

  unsigned short TIM_Break;            /*!< Specifies whether the TIM Break input is enabled or not.
                                      This parameter can be a value of @ref TIM_Break_Input_enable_disable */

  unsigned short TIM_BreakPolarity;    /*!< Specifies the TIM Break Input pin polarity.
                                      This parameter can be a value of @ref TIM_Break_Polarity */

  unsigned short TIM_AutomaticOutput;  /*!< Specifies whether the TIM Automatic Output feature is enabled or not.
                                      This parameter can be a value of @ref TIM_AOE_Bit_Set_Reset */
} TIM_BDTRInitTypeDef;

/** 
  * @brief  TIM Input Capture Init structure definition  
  */

/* Exported constants --------------------------------------------------------*/

  
/** @defgroup TIM_Exported_constants 
  * @{
  */

#define IS_TIM_ALL_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
                                   ((PERIPH) == TIM2) || \
                                   ((PERIPH) == TIM3) || \
                                   ((PERIPH) == TIM6) || \
                                   ((PERIPH) == TIM7) || \
                                   ((PERIPH) == TIM14)|| \
                                   ((PERIPH) == TIM15)|| \
                                   ((PERIPH) == TIM16)|| \
                                   ((PERIPH) == TIM17))

/* LIST1: TIM 1 */
#define IS_TIM_LIST1_PERIPH(PERIPH)  ((PERIPH) == TIM1)

/* LIST2: TIM 1, 15, 16 and 17 */
#define IS_TIM_LIST2_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
                                     ((PERIPH) == TIM15)|| \
                                     ((PERIPH) == TIM16)|| \
                                     ((PERIPH) == TIM17)) 

/* LIST3: TIM 1, 2 and 3 */
#define IS_TIM_LIST3_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
                                     ((PERIPH) == TIM2) || \
                                     ((PERIPH) == TIM3)) 

/* LIST4: TIM 1, 2, 3, 14, 15, 16 and 17 */
#define IS_TIM_LIST4_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
                                     ((PERIPH) == TIM2) || \
                                     ((PERIPH) == TIM3) || \
                                     ((PERIPH) == TIM14) || \
                                     ((PERIPH) == TIM15)|| \
                                     ((PERIPH) == TIM16)|| \
                                     ((PERIPH) == TIM17))

/* LIST5: TIM 1, 2, 3, 15, 16 and 17 */
#define IS_TIM_LIST5_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
                                     ((PERIPH) == TIM2) || \
                                     ((PERIPH) == TIM3) || \
                                     ((PERIPH) == TIM15)|| \
                                     ((PERIPH) == TIM16)|| \
                                     ((PERIPH) == TIM17))

/* LIST6: TIM 1, 2, 3 and 15 */
#define IS_TIM_LIST6_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
                                     ((PERIPH) == TIM2) || \
                                     ((PERIPH) == TIM3) || \
                                     ((PERIPH) == TIM15)) 

/* LIST7: TIM 1, 2, 3, 6, 7 and 14 */
#define IS_TIM_LIST7_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
                                      ((PERIPH) == TIM2) || \
                                      ((PERIPH) == TIM3) || \
                                      ((PERIPH) == TIM6) || \
                                      ((PERIPH) == TIM7) || \
                                      ((PERIPH) == TIM14))
                                      
/* LIST8: TIM 1, 2, 3 and 14 */
#define IS_TIM_LIST8_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
                                      ((PERIPH) == TIM2) || \
                                      ((PERIPH) == TIM3) || \
                                      ((PERIPH) == TIM14))

/* LIST9: TIM 1, 2, 3, 6, 7 and 15 */
#define IS_TIM_LIST9_PERIPH(PERIPH)  (((PERIPH) == TIM1) || \
                                      ((PERIPH) == TIM2) || \
                                      ((PERIPH) == TIM3) || \
                                      ((PERIPH) == TIM6) || \
                                      ((PERIPH) == TIM7) || \
                                      ((PERIPH) == TIM15))

/* LIST10: TIM 1, 2, 3, 6, 7, 15, 16 and 17 */
#define IS_TIM_LIST10_PERIPH(PERIPH) (((PERIPH) == TIM1) || \
                                     ((PERIPH) == TIM2) || \
                                     ((PERIPH) == TIM3) || \
                                     ((PERIPH) == TIM6) || \
                                     ((PERIPH) == TIM7) || \
                                     ((PERIPH) == TIM15)|| \
                                     ((PERIPH) == TIM16)|| \
                                     ((PERIPH) == TIM17))

/* LIST1: TIM 11 */
#define IS_TIM_LIST11_PERIPH(PERIPH)  ((PERIPH) == TIM14)
                                     

/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_and_PWM_modes 
  * @{
  */

#define TIM_OCMode_Timing                  ((unsigned short)0x0000)
#define TIM_OCMode_Active                  ((unsigned short)0x0010)
#define TIM_OCMode_Inactive                ((unsigned short)0x0020)
#define TIM_OCMode_Toggle                  ((unsigned short)0x0030)
#define TIM_OCMode_PWM1                    ((unsigned short)0x0060)
#define TIM_OCMode_PWM2                    ((unsigned short)0x0070)
#define IS_TIM_OC_MODE(MODE) (((MODE) == TIM_OCMode_Timing) || \
                              ((MODE) == TIM_OCMode_Active) || \
                              ((MODE) == TIM_OCMode_Inactive) || \
                              ((MODE) == TIM_OCMode_Toggle)|| \
                              ((MODE) == TIM_OCMode_PWM1) || \
                              ((MODE) == TIM_OCMode_PWM2))
#define IS_TIM_OCM(MODE) (((MODE) == TIM_OCMode_Timing) || \
                          ((MODE) == TIM_OCMode_Active) || \
                          ((MODE) == TIM_OCMode_Inactive) || \
                          ((MODE) == TIM_OCMode_Toggle)|| \
                          ((MODE) == TIM_OCMode_PWM1) || \
                          ((MODE) == TIM_OCMode_PWM2) ||	\
                          ((MODE) == TIM_ForcedAction_Active) || \
                          ((MODE) == TIM_ForcedAction_InActive))
/**
  * @}
  */

/** @defgroup TIM_One_Pulse_Mode 
  * @{
  */

#define TIM_OPMode_Single                  ((unsigned short)0x0008)
#define TIM_OPMode_Repetitive              ((unsigned short)0x0000)
#define IS_TIM_OPM_MODE(MODE) (((MODE) == TIM_OPMode_Single) || \
                               ((MODE) == TIM_OPMode_Repetitive))
/**
  * @}
  */ 

/** @defgroup TIM_Channel 
  * @{
  */

#define TIM_Channel_1                      ((unsigned short)0x0000)
#define TIM_Channel_2                      ((unsigned short)0x0004)
#define TIM_Channel_3                      ((unsigned short)0x0008)
#define TIM_Channel_4                      ((unsigned short)0x000C)

#define IS_TIM_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
                                 ((CHANNEL) == TIM_Channel_2) || \
                                 ((CHANNEL) == TIM_Channel_3) || \
                                 ((CHANNEL) == TIM_Channel_4))
#define IS_TIM_COMPLEMENTARY_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
                                               ((CHANNEL) == TIM_Channel_2) || \
                                               ((CHANNEL) == TIM_Channel_3))
#define IS_TIM_PWMI_CHANNEL(CHANNEL) (((CHANNEL) == TIM_Channel_1) || \
                                      ((CHANNEL) == TIM_Channel_2))

/**
  * @}
  */ 

/** @defgroup TIM_Clock_Division_CKD 
  * @{
  */

#define TIM_CKD_DIV1                       ((unsigned short)0x0000)
#define TIM_CKD_DIV2                       ((unsigned short)0x0100)
#define TIM_CKD_DIV4                       ((unsigned short)0x0200)
#define IS_TIM_CKD_DIV(DIV) (((DIV) == TIM_CKD_DIV1) || \
                             ((DIV) == TIM_CKD_DIV2) || \
                             ((DIV) == TIM_CKD_DIV4))
/**
  * @}
  */

/** @defgroup TIM_Counter_Mode 
  * @{
  */

#define TIM_CounterMode_Up                 ((unsigned short)0x0000)
#define TIM_CounterMode_Down               ((unsigned short)0x0010)
#define TIM_CounterMode_CenterAligned1     ((unsigned short)0x0020)
#define TIM_CounterMode_CenterAligned2     ((unsigned short)0x0040)
#define TIM_CounterMode_CenterAligned3     ((unsigned short)0x0060)
#define IS_TIM_COUNTER_MODE(MODE) (((MODE) == TIM_CounterMode_Up) ||  \
                                   ((MODE) == TIM_CounterMode_Down) || \
                                   ((MODE) == TIM_CounterMode_CenterAligned1) || \
                                   ((MODE) == TIM_CounterMode_CenterAligned2) || \
                                   ((MODE) == TIM_CounterMode_CenterAligned3))
/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_Polarity 
  * @{
  */

#define TIM_OCPolarity_High                ((unsigned short)0x0000)
#define TIM_OCPolarity_Low                 ((unsigned short)0x0002)
#define IS_TIM_OC_POLARITY(POLARITY) (((POLARITY) == TIM_OCPolarity_High) || \
                                      ((POLARITY) == TIM_OCPolarity_Low))
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Polarity 
  * @{
  */
  
#define TIM_OCNPolarity_High               ((unsigned short)0x0000)
#define TIM_OCNPolarity_Low                ((unsigned short)0x0008)
#define IS_TIM_OCN_POLARITY(POLARITY) (((POLARITY) == TIM_OCNPolarity_High) || \
                                       ((POLARITY) == TIM_OCNPolarity_Low))
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_state
  * @{
  */

#define TIM_OutputState_Disable            ((unsigned short)0x0000)
#define TIM_OutputState_Enable             ((unsigned short)0x0001)
#define IS_TIM_OUTPUT_STATE(STATE) (((STATE) == TIM_OutputState_Disable) || \
                                    ((STATE) == TIM_OutputState_Enable))
/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_N_state 
  * @{
  */

#define TIM_OutputNState_Disable           ((unsigned short)0x0000)
#define TIM_OutputNState_Enable            ((unsigned short)0x0004)
#define IS_TIM_OUTPUTN_STATE(STATE) (((STATE) == TIM_OutputNState_Disable) || \
                                     ((STATE) == TIM_OutputNState_Enable))
/**
  * @}
  */ 

/** @defgroup TIM_Capture_Compare_state 
  * @{
  */

#define TIM_CCx_Enable                      ((unsigned short)0x0001)
#define TIM_CCx_Disable                     ((unsigned short)0x0000)
#define IS_TIM_CCX(CCX) (((CCX) == TIM_CCx_Enable) || \
                         ((CCX) == TIM_CCx_Disable))
/**
  * @}
  */ 

/** @defgroup TIM_Capture_Compare_N_state 
  * @{
  */

#define TIM_CCxN_Enable                     ((unsigned short)0x0004)
#define TIM_CCxN_Disable                    ((unsigned short)0x0000)
#define IS_TIM_CCXN(CCXN) (((CCXN) == TIM_CCxN_Enable) || \
                           ((CCXN) == TIM_CCxN_Disable))
/**
  * @}
  */ 

/** @defgroup TIM_Break_Input_enable_disable 
  * @{
  */

#define TIM_Break_Enable                   ((unsigned short)0x1000)
#define TIM_Break_Disable                  ((unsigned short)0x0000)
#define IS_TIM_BREAK_STATE(STATE) (((STATE) == TIM_Break_Enable) || \
                                   ((STATE) == TIM_Break_Disable))
/**
  * @}
  */ 

/** @defgroup TIM_Break_Polarity 
  * @{
  */

#define TIM_BreakPolarity_Low              ((unsigned short)0x0000)
#define TIM_BreakPolarity_High             ((unsigned short)0x2000)
#define IS_TIM_BREAK_POLARITY(POLARITY) (((POLARITY) == TIM_BreakPolarity_Low) || \
                                         ((POLARITY) == TIM_BreakPolarity_High))
/**
  * @}
  */ 

/** @defgroup TIM_AOE_Bit_Set_Reset 
  * @{
  */

#define TIM_AutomaticOutput_Enable         ((unsigned short)0x4000)
#define TIM_AutomaticOutput_Disable        ((unsigned short)0x0000)
#define IS_TIM_AUTOMATIC_OUTPUT_STATE(STATE) (((STATE) == TIM_AutomaticOutput_Enable) || \
                                              ((STATE) == TIM_AutomaticOutput_Disable))
/**
  * @}
  */ 

/** @defgroup TIM_Lock_level 
  * @{
  */

#define TIM_LOCKLevel_OFF                  ((unsigned short)0x0000)
#define TIM_LOCKLevel_1                    ((unsigned short)0x0100)
#define TIM_LOCKLevel_2                    ((unsigned short)0x0200)
#define TIM_LOCKLevel_3                    ((unsigned short)0x0300)
#define IS_TIM_LOCK_LEVEL(LEVEL) (((LEVEL) == TIM_LOCKLevel_OFF) || \
                                  ((LEVEL) == TIM_LOCKLevel_1) || \
                                  ((LEVEL) == TIM_LOCKLevel_2) || \
                                  ((LEVEL) == TIM_LOCKLevel_3))
/**
  * @}
  */ 

/** @defgroup TIM_OSSI_Off_State_Selection_for_Idle_mode_state 
  * @{
  */

#define TIM_OSSIState_Enable               ((unsigned short)0x0400)
#define TIM_OSSIState_Disable              ((unsigned short)0x0000)
#define IS_TIM_OSSI_STATE(STATE) (((STATE) == TIM_OSSIState_Enable) || \
                                  ((STATE) == TIM_OSSIState_Disable))
/**
  * @}
  */

/** @defgroup TIM_OSSR_Off_State_Selection_for_Run_mode_state 
  * @{
  */

#define TIM_OSSRState_Enable               ((unsigned short)0x0800)
#define TIM_OSSRState_Disable              ((unsigned short)0x0000)
#define IS_TIM_OSSR_STATE(STATE) (((STATE) == TIM_OSSRState_Enable) || \
                                  ((STATE) == TIM_OSSRState_Disable))
/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_Idle_State 
  * @{
  */

#define TIM_OCIdleState_Set                ((unsigned short)0x0100)
#define TIM_OCIdleState_Reset              ((unsigned short)0x0000)
#define IS_TIM_OCIDLE_STATE(STATE) (((STATE) == TIM_OCIdleState_Set) || \
                                    ((STATE) == TIM_OCIdleState_Reset))
/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_N_Idle_State 
  * @{
  */

#define TIM_OCNIdleState_Set               ((unsigned short)0x0200)
#define TIM_OCNIdleState_Reset             ((unsigned short)0x0000)
#define IS_TIM_OCNIDLE_STATE(STATE) (((STATE) == TIM_OCNIdleState_Set) || \
                                     ((STATE) == TIM_OCNIdleState_Reset))
/**
  * @}
  */ 

/** @defgroup TIM_Input_Capture_Polarity 
  * @{
  */

#define  TIM_ICPolarity_Rising             ((unsigned short)0x0000)
#define  TIM_ICPolarity_Falling            ((unsigned short)0x0002)
#define  TIM_ICPolarity_BothEdge           ((unsigned short)0x000A)
#define IS_TIM_IC_POLARITY(POLARITY) (((POLARITY) == TIM_ICPolarity_Rising) || \
                                      ((POLARITY) == TIM_ICPolarity_Falling)|| \
                                      ((POLARITY) == TIM_ICPolarity_BothEdge)) 
/**
  * @}
  */ 

/** @defgroup TIM_Input_Capture_Selection 
  * @{
  */

#define TIM_ICSelection_DirectTI           ((unsigned short)0x0001) /*!< TIM Input 1, 2, 3 or 4 is selected to be
                                                                   connected to IC1, IC2, IC3 or IC4, respectively */
#define TIM_ICSelection_IndirectTI         ((unsigned short)0x0002) /*!< TIM Input 1, 2, 3 or 4 is selected to be
                                                                   connected to IC2, IC1, IC4 or IC3, respectively. */
#define TIM_ICSelection_TRC                ((unsigned short)0x0003) /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to TRC. */
#define IS_TIM_IC_SELECTION(SELECTION) (((SELECTION) == TIM_ICSelection_DirectTI) || \
                                        ((SELECTION) == TIM_ICSelection_IndirectTI) || \
                                        ((SELECTION) == TIM_ICSelection_TRC))
/**
  * @}
  */ 

/** @defgroup TIM_Input_Capture_Prescaler 
  * @{
  */

#define TIM_ICPSC_DIV1                     ((unsigned short)0x0000) /*!< Capture performed each time an edge is detected on the capture input. */
#define TIM_ICPSC_DIV2                     ((unsigned short)0x0004) /*!< Capture performed once every 2 events. */
#define TIM_ICPSC_DIV4                     ((unsigned short)0x0008) /*!< Capture performed once every 4 events. */
#define TIM_ICPSC_DIV8                     ((unsigned short)0x000C) /*!< Capture performed once every 8 events. */
#define IS_TIM_IC_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ICPSC_DIV1) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV2) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV4) || \
                                        ((PRESCALER) == TIM_ICPSC_DIV8))
/**
  * @}
  */ 

/** @defgroup TIM_interrupt_sources 
  * @{
  */

#define TIM_IT_Update                      ((unsigned short)0x0001)
#define TIM_IT_CC1                         ((unsigned short)0x0002)
#define TIM_IT_CC2                         ((unsigned short)0x0004)
#define TIM_IT_CC3                         ((unsigned short)0x0008)
#define TIM_IT_CC4                         ((unsigned short)0x0010)
#define TIM_IT_COM                         ((unsigned short)0x0020)
#define TIM_IT_Trigger                     ((unsigned short)0x0040)
#define TIM_IT_Break                       ((unsigned short)0x0080)
#define IS_TIM_IT(IT) ((((IT) & (unsigned short)0xFF00) == 0x0000) && ((IT) != 0x0000))

#define IS_TIM_GET_IT(IT) (((IT) == TIM_IT_Update) || \
                           ((IT) == TIM_IT_CC1) || \
                           ((IT) == TIM_IT_CC2) || \
                           ((IT) == TIM_IT_CC3) || \
                           ((IT) == TIM_IT_CC4) || \
                           ((IT) == TIM_IT_COM) || \
                           ((IT) == TIM_IT_Trigger) || \
                           ((IT) == TIM_IT_Break))
/**
  * @}
  */ 

/** @defgroup TIM_DMA_Base_address 
  * @{
  */

#define TIM_DMABase_CR1                    ((unsigned short)0x0000)
#define TIM_DMABase_CR2                    ((unsigned short)0x0001)
#define TIM_DMABase_SMCR                   ((unsigned short)0x0002)
#define TIM_DMABase_DIER                   ((unsigned short)0x0003)
#define TIM_DMABase_SR                     ((unsigned short)0x0004)
#define TIM_DMABase_EGR                    ((unsigned short)0x0005)
#define TIM_DMABase_CCMR1                  ((unsigned short)0x0006)
#define TIM_DMABase_CCMR2                  ((unsigned short)0x0007)
#define TIM_DMABase_CCER                   ((unsigned short)0x0008)
#define TIM_DMABase_CNT                    ((unsigned short)0x0009)
#define TIM_DMABase_PSC                    ((unsigned short)0x000A)
#define TIM_DMABase_ARR                    ((unsigned short)0x000B)
#define TIM_DMABase_RCR                    ((unsigned short)0x000C)
#define TIM_DMABase_CCR1                   ((unsigned short)0x000D)
#define TIM_DMABase_CCR2                   ((unsigned short)0x000E)
#define TIM_DMABase_CCR3                   ((unsigned short)0x000F)
#define TIM_DMABase_CCR4                   ((unsigned short)0x0010)
#define TIM_DMABase_BDTR                   ((unsigned short)0x0011)
#define TIM_DMABase_DCR                    ((unsigned short)0x0012)
#define TIM_DMABase_OR                     ((unsigned short)0x0013)
#define IS_TIM_DMA_BASE(BASE) (((BASE) == TIM_DMABase_CR1) || \
                               ((BASE) == TIM_DMABase_CR2) || \
                               ((BASE) == TIM_DMABase_SMCR) || \
                               ((BASE) == TIM_DMABase_DIER) || \
                               ((BASE) == TIM_DMABase_SR) || \
                               ((BASE) == TIM_DMABase_EGR) || \
                               ((BASE) == TIM_DMABase_CCMR1) || \
                               ((BASE) == TIM_DMABase_CCMR2) || \
                               ((BASE) == TIM_DMABase_CCER) || \
                               ((BASE) == TIM_DMABase_CNT) || \
                               ((BASE) == TIM_DMABase_PSC) || \
                               ((BASE) == TIM_DMABase_ARR) || \
                               ((BASE) == TIM_DMABase_RCR) || \
                               ((BASE) == TIM_DMABase_CCR1) || \
                               ((BASE) == TIM_DMABase_CCR2) || \
                               ((BASE) == TIM_DMABase_CCR3) || \
                               ((BASE) == TIM_DMABase_CCR4) || \
                               ((BASE) == TIM_DMABase_BDTR) || \
							   ((BASE) == TIM_DMABase_DCR) || \
                               ((BASE) == TIM_DMABase_OR))
/**
  * @}
  */ 


/** @defgroup TIM_DMA_Burst_Length 
  * @{
  */

#define TIM_DMABurstLength_1Transfer           ((unsigned short)0x0000)
#define TIM_DMABurstLength_2Transfers          ((unsigned short)0x0100)
#define TIM_DMABurstLength_3Transfers          ((unsigned short)0x0200)
#define TIM_DMABurstLength_4Transfers          ((unsigned short)0x0300)
#define TIM_DMABurstLength_5Transfers          ((unsigned short)0x0400)
#define TIM_DMABurstLength_6Transfers          ((unsigned short)0x0500)
#define TIM_DMABurstLength_7Transfers          ((unsigned short)0x0600)
#define TIM_DMABurstLength_8Transfers          ((unsigned short)0x0700)
#define TIM_DMABurstLength_9Transfers          ((unsigned short)0x0800)
#define TIM_DMABurstLength_10Transfers         ((unsigned short)0x0900)
#define TIM_DMABurstLength_11Transfers         ((unsigned short)0x0A00)
#define TIM_DMABurstLength_12Transfers         ((unsigned short)0x0B00)
#define TIM_DMABurstLength_13Transfers         ((unsigned short)0x0C00)
#define TIM_DMABurstLength_14Transfers         ((unsigned short)0x0D00)
#define TIM_DMABurstLength_15Transfers         ((unsigned short)0x0E00)
#define TIM_DMABurstLength_16Transfers         ((unsigned short)0x0F00)
#define TIM_DMABurstLength_17Transfers         ((unsigned short)0x1000)
#define TIM_DMABurstLength_18Transfers         ((unsigned short)0x1100)
#define IS_TIM_DMA_LENGTH(LENGTH) (((LENGTH) == TIM_DMABurstLength_1Transfer) || \
                                   ((LENGTH) == TIM_DMABurstLength_2Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_3Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_4Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_5Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_6Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_7Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_8Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_9Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_10Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_11Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_12Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_13Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_14Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_15Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_16Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_17Transfers) || \
                                   ((LENGTH) == TIM_DMABurstLength_18Transfers))
/**
  * @}
  */ 

/** @defgroup TIM_DMA_sources 
  * @{
  */

#define TIM_DMA_Update                     ((unsigned short)0x0100)
#define TIM_DMA_CC1                        ((unsigned short)0x0200)
#define TIM_DMA_CC2                        ((unsigned short)0x0400)
#define TIM_DMA_CC3                        ((unsigned short)0x0800)
#define TIM_DMA_CC4                        ((unsigned short)0x1000)
#define TIM_DMA_COM                        ((unsigned short)0x2000)
#define TIM_DMA_Trigger                    ((unsigned short)0x4000)
#define IS_TIM_DMA_SOURCE(SOURCE) ((((SOURCE) & (unsigned short)0x80FF) == 0x0000) && ((SOURCE) != 0x0000))

/**
  * @}
  */ 

/** @defgroup TIM_External_Trigger_Prescaler 
  * @{
  */

#define TIM_ExtTRGPSC_OFF                  ((unsigned short)0x0000)
#define TIM_ExtTRGPSC_DIV2                 ((unsigned short)0x1000)
#define TIM_ExtTRGPSC_DIV4                 ((unsigned short)0x2000)
#define TIM_ExtTRGPSC_DIV8                 ((unsigned short)0x3000)
#define IS_TIM_EXT_PRESCALER(PRESCALER) (((PRESCALER) == TIM_ExtTRGPSC_OFF) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV2) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV4) || \
                                         ((PRESCALER) == TIM_ExtTRGPSC_DIV8))
/**
  * @}
  */ 

/** @defgroup TIM_Internal_Trigger_Selection 
  * @{
  */

#define TIM_TS_ITR0                        ((unsigned short)0x0000)
#define TIM_TS_ITR1                        ((unsigned short)0x0010)
#define TIM_TS_ITR2                        ((unsigned short)0x0020)
#define TIM_TS_ITR3                        ((unsigned short)0x0030)
#define TIM_TS_TI1F_ED                     ((unsigned short)0x0040)
#define TIM_TS_TI1FP1                      ((unsigned short)0x0050)
#define TIM_TS_TI2FP2                      ((unsigned short)0x0060)
#define TIM_TS_ETRF                        ((unsigned short)0x0070)
#define IS_TIM_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
                                             ((SELECTION) == TIM_TS_ITR1) || \
                                             ((SELECTION) == TIM_TS_ITR2) || \
                                             ((SELECTION) == TIM_TS_ITR3) || \
                                             ((SELECTION) == TIM_TS_TI1F_ED) || \
                                             ((SELECTION) == TIM_TS_TI1FP1) || \
                                             ((SELECTION) == TIM_TS_TI2FP2) || \
                                             ((SELECTION) == TIM_TS_ETRF))
#define IS_TIM_INTERNAL_TRIGGER_SELECTION(SELECTION) (((SELECTION) == TIM_TS_ITR0) || \
                                                      ((SELECTION) == TIM_TS_ITR1) || \
                                                      ((SELECTION) == TIM_TS_ITR2) || \
                                                      ((SELECTION) == TIM_TS_ITR3))
/**
  * @}
  */ 

/** @defgroup TIM_TIx_External_Clock_Source 
  * @{
  */

#define TIM_TIxExternalCLK1Source_TI1      ((unsigned short)0x0050)
#define TIM_TIxExternalCLK1Source_TI2      ((unsigned short)0x0060)
#define TIM_TIxExternalCLK1Source_TI1ED    ((unsigned short)0x0040)

/**
  * @}
  */ 

/** @defgroup TIM_External_Trigger_Polarity 
  * @{
  */ 
#define TIM_ExtTRGPolarity_Inverted        ((unsigned short)0x8000)
#define TIM_ExtTRGPolarity_NonInverted     ((unsigned short)0x0000)
#define IS_TIM_EXT_POLARITY(POLARITY) (((POLARITY) == TIM_ExtTRGPolarity_Inverted) || \
                                       ((POLARITY) == TIM_ExtTRGPolarity_NonInverted))
/**
  * @}
  */

/** @defgroup TIM_Prescaler_Reload_Mode 
  * @{
  */

#define TIM_PSCReloadMode_Update           ((unsigned short)0x0000)
#define TIM_PSCReloadMode_Immediate        ((unsigned short)0x0001)
#define IS_TIM_PRESCALER_RELOAD(RELOAD) (((RELOAD) == TIM_PSCReloadMode_Update) || \
                                         ((RELOAD) == TIM_PSCReloadMode_Immediate))
/**
  * @}
  */ 

/** @defgroup TIM_Forced_Action 
  * @{
  */

#define TIM_ForcedAction_Active            ((unsigned short)0x0050)
#define TIM_ForcedAction_InActive          ((unsigned short)0x0040)
#define IS_TIM_FORCED_ACTION(ACTION) (((ACTION) == TIM_ForcedAction_Active) || \
                                      ((ACTION) == TIM_ForcedAction_InActive))
/**
  * @}
  */ 

/** @defgroup TIM_Encoder_Mode 
  * @{
  */

#define TIM_EncoderMode_TI1                ((unsigned short)0x0001)
#define TIM_EncoderMode_TI2                ((unsigned short)0x0002)
#define TIM_EncoderMode_TI12               ((unsigned short)0x0003)
#define IS_TIM_ENCODER_MODE(MODE) (((MODE) == TIM_EncoderMode_TI1) || \
                                   ((MODE) == TIM_EncoderMode_TI2) || \
                                   ((MODE) == TIM_EncoderMode_TI12))
/**
  * @}
  */ 


/** @defgroup TIM_Event_Source 
  * @{
  */

#define TIM_EventSource_Update             ((unsigned short)0x0001)
#define TIM_EventSource_CC1                ((unsigned short)0x0002)
#define TIM_EventSource_CC2                ((unsigned short)0x0004)
#define TIM_EventSource_CC3                ((unsigned short)0x0008)
#define TIM_EventSource_CC4                ((unsigned short)0x0010)
#define TIM_EventSource_COM                ((unsigned short)0x0020)
#define TIM_EventSource_Trigger            ((unsigned short)0x0040)
#define TIM_EventSource_Break              ((unsigned short)0x0080)
#define IS_TIM_EVENT_SOURCE(SOURCE) ((((SOURCE) & (unsigned short)0xFF00) == 0x0000) && ((SOURCE) != 0x0000))

/**
  * @}
  */ 

/** @defgroup TIM_Update_Source 
  * @{
  */

#define TIM_UpdateSource_Global            ((unsigned short)0x0000) /*!< Source of update is the counter overflow/underflow
                                                                   or the setting of UG bit, or an update generation
                                                                   through the slave mode controller. */
#define TIM_UpdateSource_Regular           ((unsigned short)0x0001) /*!< Source of update is counter overflow/underflow. */
#define IS_TIM_UPDATE_SOURCE(SOURCE) (((SOURCE) == TIM_UpdateSource_Global) || \
                                      ((SOURCE) == TIM_UpdateSource_Regular))
/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_Preload_State 
  * @{
  */

#define TIM_OCPreload_Enable               ((unsigned short)0x0008)
#define TIM_OCPreload_Disable              ((unsigned short)0x0000)
#define IS_TIM_OCPRELOAD_STATE(STATE) (((STATE) == TIM_OCPreload_Enable) || \
                                       ((STATE) == TIM_OCPreload_Disable))
/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_Fast_State 
  * @{
  */

#define TIM_OCFast_Enable                  ((unsigned short)0x0004)
#define TIM_OCFast_Disable                 ((unsigned short)0x0000)
#define IS_TIM_OCFAST_STATE(STATE) (((STATE) == TIM_OCFast_Enable) || \
                                    ((STATE) == TIM_OCFast_Disable))
                                     
/**
  * @}
  */ 

/** @defgroup TIM_Output_Compare_Clear_State 
  * @{
  */

#define TIM_OCClear_Enable                 ((unsigned short)0x0080)
#define TIM_OCClear_Disable                ((unsigned short)0x0000)
#define IS_TIM_OCCLEAR_STATE(STATE) (((STATE) == TIM_OCClear_Enable) || \
                                     ((STATE) == TIM_OCClear_Disable))
/**
  * @}
  */ 

/** @defgroup TIM_Trigger_Output_Source 
  * @{
  */

#define TIM_TRGOSource_Reset               ((unsigned short)0x0000)
#define TIM_TRGOSource_Enable              ((unsigned short)0x0010)
#define TIM_TRGOSource_Update              ((unsigned short)0x0020)
#define TIM_TRGOSource_OC1                 ((unsigned short)0x0030)
#define TIM_TRGOSource_OC1Ref              ((unsigned short)0x0040)
#define TIM_TRGOSource_OC2Ref              ((unsigned short)0x0050)
#define TIM_TRGOSource_OC3Ref              ((unsigned short)0x0060)
#define TIM_TRGOSource_OC4Ref              ((unsigned short)0x0070)
#define IS_TIM_TRGO_SOURCE(SOURCE) (((SOURCE) == TIM_TRGOSource_Reset) || \
                                    ((SOURCE) == TIM_TRGOSource_Enable) || \
                                    ((SOURCE) == TIM_TRGOSource_Update) || \
                                    ((SOURCE) == TIM_TRGOSource_OC1) || \
                                    ((SOURCE) == TIM_TRGOSource_OC1Ref) || \
                                    ((SOURCE) == TIM_TRGOSource_OC2Ref) || \
                                    ((SOURCE) == TIM_TRGOSource_OC3Ref) || \
                                    ((SOURCE) == TIM_TRGOSource_OC4Ref))
/**
  * @}
  */ 

/** @defgroup TIM_Slave_Mode 
  * @{
  */

#define TIM_SlaveMode_Reset                ((unsigned short)0x0004)
#define TIM_SlaveMode_Gated                ((unsigned short)0x0005)
#define TIM_SlaveMode_Trigger              ((unsigned short)0x0006)
#define TIM_SlaveMode_External1            ((unsigned short)0x0007)
#define IS_TIM_SLAVE_MODE(MODE) (((MODE) == TIM_SlaveMode_Reset) || \
                                 ((MODE) == TIM_SlaveMode_Gated) || \
                                 ((MODE) == TIM_SlaveMode_Trigger) || \
                                 ((MODE) == TIM_SlaveMode_External1))
/**
  * @}
  */ 

/** @defgroup TIM_Master_Slave_Mode 
  * @{
  */

#define TIM_MasterSlaveMode_Enable         ((unsigned short)0x0080)
#define TIM_MasterSlaveMode_Disable        ((unsigned short)0x0000)
#define IS_TIM_MSM_STATE(STATE) (((STATE) == TIM_MasterSlaveMode_Enable) || \
                                 ((STATE) == TIM_MasterSlaveMode_Disable))
/**
  * @}
  */ 
  
/** @defgroup TIM_Flags 
  * @{
  */

#define TIM_FLAG_Update                    ((unsigned short)0x0001)
#define TIM_FLAG_CC1                       ((unsigned short)0x0002)
#define TIM_FLAG_CC2                       ((unsigned short)0x0004)
#define TIM_FLAG_CC3                       ((unsigned short)0x0008)
#define TIM_FLAG_CC4                       ((unsigned short)0x0010)
#define TIM_FLAG_COM                       ((unsigned short)0x0020)
#define TIM_FLAG_Trigger                   ((unsigned short)0x0040)
#define TIM_FLAG_Break                     ((unsigned short)0x0080)
#define TIM_FLAG_CC1OF                     ((unsigned short)0x0200)
#define TIM_FLAG_CC2OF                     ((unsigned short)0x0400)
#define TIM_FLAG_CC3OF                     ((unsigned short)0x0800)
#define TIM_FLAG_CC4OF                     ((unsigned short)0x1000)
#define IS_TIM_GET_FLAG(FLAG) (((FLAG) == TIM_FLAG_Update) || \
                               ((FLAG) == TIM_FLAG_CC1) || \
                               ((FLAG) == TIM_FLAG_CC2) || \
                               ((FLAG) == TIM_FLAG_CC3) || \
                               ((FLAG) == TIM_FLAG_CC4) || \
                               ((FLAG) == TIM_FLAG_COM) || \
                               ((FLAG) == TIM_FLAG_Trigger) || \
                               ((FLAG) == TIM_FLAG_Break) || \
                               ((FLAG) == TIM_FLAG_CC1OF) || \
                               ((FLAG) == TIM_FLAG_CC2OF) || \
                               ((FLAG) == TIM_FLAG_CC3OF) || \
                               ((FLAG) == TIM_FLAG_CC4OF))
                               
                               
#define IS_TIM_CLEAR_FLAG(TIM_FLAG) ((((TIM_FLAG) & (unsigned short)0xE100) == 0x0000) && ((TIM_FLAG) != 0x0000))
/**
  * @}
  */ 


/** @defgroup TIM_Input_Capture_Filer_Value 
  * @{
  */

#define IS_TIM_IC_FILTER(ICFILTER) ((ICFILTER) <= 0xF) 
/**
  * @}
  */ 

/** @defgroup TIM_External_Trigger_Filter 
  * @{
  */

#define IS_TIM_EXT_FILTER(EXTFILTER) ((EXTFILTER) <= 0xF)
/**
  * @}
  */

/** @defgroup TIM_OCReferenceClear 
  * @{
  */
#define TIM_OCReferenceClear_ETRF          ((unsigned short)0x0008)
#define TIM_OCReferenceClear_OCREFCLR      ((unsigned short)0x0000)
#define TIM_OCREFERENCECECLEAR_SOURCE(SOURCE) (((SOURCE) == TIM_OCReferenceClear_ETRF) || \
                                              ((SOURCE) == TIM_OCReferenceClear_OCREFCLR)) 

/**
  * @}
  */
/** @defgroup TIM_Remap 
  * @{
  */
#define TIM14_GPIO                      ((unsigned short)0x0000)
#define TIM14_RTC_CLK                   ((unsigned short)0x0001)
#define TIM14_HSEDiv32                  ((unsigned short)0x0002)
#define TIM14_MCO                       ((unsigned short)0x0003)

#define IS_TIM_REMAP(TIM_REMAP)  (((TIM_REMAP) == TIM14_GPIO)|| \
                                  ((TIM_REMAP) == TIM14_RTC_CLK) || \
                                  ((TIM_REMAP) == TIM14_HSEDiv32) || \
                                  ((TIM_REMAP) == TIM14_MCO))
/**
  * @}
  */

/** @defgroup TIM_Legacy 
  * @{
  */

#define TIM_DMABurstLength_1Byte           TIM_DMABurstLength_1Transfer
#define TIM_DMABurstLength_2Bytes          TIM_DMABurstLength_2Transfers
#define TIM_DMABurstLength_3Bytes          TIM_DMABurstLength_3Transfers
#define TIM_DMABurstLength_4Bytes          TIM_DMABurstLength_4Transfers
#define TIM_DMABurstLength_5Bytes          TIM_DMABurstLength_5Transfers
#define TIM_DMABurstLength_6Bytes          TIM_DMABurstLength_6Transfers
#define TIM_DMABurstLength_7Bytes          TIM_DMABurstLength_7Transfers
#define TIM_DMABurstLength_8Bytes          TIM_DMABurstLength_8Transfers
#define TIM_DMABurstLength_9Bytes          TIM_DMABurstLength_9Transfers
#define TIM_DMABurstLength_10Bytes         TIM_DMABurstLength_10Transfers
#define TIM_DMABurstLength_11Bytes         TIM_DMABurstLength_11Transfers
#define TIM_DMABurstLength_12Bytes         TIM_DMABurstLength_12Transfers
#define TIM_DMABurstLength_13Bytes         TIM_DMABurstLength_13Transfers
#define TIM_DMABurstLength_14Bytes         TIM_DMABurstLength_14Transfers
#define TIM_DMABurstLength_15Bytes         TIM_DMABurstLength_15Transfers
#define TIM_DMABurstLength_16Bytes         TIM_DMABurstLength_16Transfers
#define TIM_DMABurstLength_17Bytes         TIM_DMABurstLength_17Transfers
#define TIM_DMABurstLength_18Bytes         TIM_DMABurstLength_18Transfers
/**
  * @}
  */

/**
  * @}
  */
  
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 

/* TimeBase management ********************************************************/
void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, unsigned short Prescaler, unsigned short TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, unsigned short TIM_CounterMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, unsigned int Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, unsigned int Autoreload);
unsigned int TIM_GetCounter(TIM_TypeDef* TIMx);
unsigned short TIM_GetPrescaler(TIM_TypeDef* TIMx);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, unsigned short TIM_UpdateSource);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, unsigned short TIM_OPMode);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, unsigned short TIM_CKD);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);

/* Advanced-control timers (TIM1) specific features*******************/
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);

/* Output Compare management **************************************************/
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, unsigned short TIM_Channel, unsigned short TIM_OCMode);
void TIM_SetCompare1(TIM_TypeDef* TIMx, unsigned int Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, unsigned int Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, unsigned int Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, unsigned int Compare4);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, unsigned short TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, unsigned short TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, unsigned short TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, unsigned short TIM_ForcedAction);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, unsigned short TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, unsigned short TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, unsigned short TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, unsigned short TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, unsigned short TIM_OCPolarity);
void TIM_SelectOCREFClear(TIM_TypeDef* TIMx, unsigned short TIM_OCReferenceClear);
void TIM_CCxCmd(TIM_TypeDef* TIMx, unsigned short TIM_Channel, unsigned short TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, unsigned short TIM_Channel, unsigned short TIM_CCxN);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);

/* Input Capture management ***************************************************/
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
unsigned int TIM_GetCapture1(TIM_TypeDef* TIMx);
unsigned int TIM_GetCapture2(TIM_TypeDef* TIMx);
unsigned int TIM_GetCapture3(TIM_TypeDef* TIMx);
unsigned int TIM_GetCapture4(TIM_TypeDef* TIMx);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, unsigned short TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, unsigned short TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, unsigned short TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, unsigned short TIM_ICPSC);

/* Interrupts, DMA and flags management ***************************************/
void TIM_ITConfig(TIM_TypeDef* TIMx, unsigned short TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, unsigned short TIM_EventSource);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, unsigned short TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, unsigned short TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, unsigned short TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, unsigned short TIM_IT);
void TIM_DMAConfig(TIM_TypeDef* TIMx, unsigned short TIM_DMABase, unsigned short TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, unsigned short TIM_DMASource, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);

/* Clocks management **********************************************************/
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, unsigned short TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, unsigned short TIM_TIxExternalCLKSource,
                                unsigned short TIM_ICPolarity, unsigned short ICFilter);
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, unsigned short TIM_ExtTRGPrescaler, unsigned short TIM_ExtTRGPolarity,
                             unsigned short ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, unsigned short TIM_ExtTRGPrescaler,
                             unsigned short TIM_ExtTRGPolarity, unsigned short ExtTRGFilter);


/* Synchronization management *************************************************/
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, unsigned short TIM_InputTriggerSource);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, unsigned short TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, unsigned short TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, unsigned short TIM_MasterSlaveMode);
void TIM_ETRConfig(TIM_TypeDef* TIMx, unsigned short TIM_ExtTRGPrescaler, unsigned short TIM_ExtTRGPolarity,
                   unsigned short ExtTRGFilter);

/* Specific interface management **********************************************/                   
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, unsigned short TIM_EncoderMode,
                                unsigned short TIM_IC1Polarity, unsigned short TIM_IC2Polarity);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);

/* Specific remapping management **********************************************/
void TIM_RemapConfig(TIM_TypeDef* TIMx, unsigned short TIM_Remap);


#ifdef __cplusplus
}
#endif

#endif /*__STM32F0XX_TIM_H */

/**
  * @}
  */ 

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
