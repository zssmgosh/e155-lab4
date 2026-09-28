// TIM15.h
// Header for TIM15 functions

#ifndef TIM15_H
#define TIM15_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses
#define TIM15_BASE (0x40014000UL) // base address of TIM15

/**
  * @brief Reset and Clock Control
  */

typedef struct
{
  __IO uint32_t CR1;          /*!< TIM15 clock control register,                                            Address offset: 0x00 */
  __IO uint32_t CR2;          /*!< RCC internal clock sources calibration register,                         Address offset: 0x04 */
  __IO uint32_t SMCR;         /*!< RCC clock configuration register,                                        Address offset: 0x08 */
  __IO uint32_t DIER;         /*!< RCC system PLL configuration register,                                   Address offset: 0x0C */
  __IO uint32_t SR;           /*!< RCC PLL SAI1 configuration register,                                     Address offset: 0x10 */
  __IO uint32_t EGR;          /*!< Reserved,                                                                Address offset: 0x14 */
  __IO uint32_t CCMR1;        /*!< RCC clock interrupt enable register,                                     Address offset: 0x18 */
  uint32_t      RESERVED;     /*!< RCC clock interrupt flag register,                                       Address offset: 0x1C */
  __IO uint32_t CCER;         /*!< RCC clock interrupt clear register,                                      Address offset: 0x20 */
  __IO uint32_t CNT;          /*!< Reserved,                                                                Address offset: 0x24 */
  __IO uint32_t PSC;          /*!< RCC AHB1 peripheral reset register,                                      Address offset: 0x28 */
  __IO uint32_t ARR;          /*!< RCC AHB2 peripheral reset register,                                      Address offset: 0x2C */
  __IO uint32_t RCR;          /*!< RCC AHB3 peripheral reset register,                                      Address offset: 0x30 */
  __IO uint32_t CCR1;         /*!< Reserved,                                                                Address offset: 0x34 */
  __IO uint32_t CCR2;         /*!< RCC APB1 peripheral reset register 1,                                    Address offset: 0x38 */
  uint32_t      RESERVED0;    /*!< RCC APB1 peripheral reset register 2,                                    Address offset: 0x3C */
  uint32_t      RESERVED1;    /*!< RCC APB2 peripheral reset register,                                      Address offset: 0x40 */
  __IO uint32_t BDTR;         /*!< Reserved,                                                                Address offset: 0x44 */
  __IO uint32_t DCR;          /*!< RCC AHB1 peripheral clocks enable register,                              Address offset: 0x48 */
  __IO uint32_t DMAR;         /*!< RCC AHB2 peripheral clocks enable register,                              Address offset: 0x4C */
  __IO uint32_t OR1;          /*!< RCC AHB3 peripheral clocks enable register,                              Address offset: 0x50 */
  uint32_t      RESERVED2;    /*!< Reserved,                                                                Address offset: 0x54 */
  uint32_t      RESERVED3;    /*!< RCC APB1 peripheral clocks enable register 1,                            Address offset: 0x58 */
  uint32_t      RESERVED4;    /*!< RCC APB1 peripheral clocks enable register 2,                            Address offset: 0x5C */
  __IO uint32_t OR2;          /*!< RCC APB2 peripheral clocks enable register,                              Address offset: 0x60 */
} TIM15_TypeDef;

#define TIM15 ((TIM15_TypeDef *) TIM15_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void initTIM15(void);
int configureTIM15(int duration, int pitch);

#endif