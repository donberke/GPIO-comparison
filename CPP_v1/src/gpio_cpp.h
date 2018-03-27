
#ifndef GPIO_CPP
#define GPIO_CPP

#include "stm32f4xx.h"

// ------------------------------------------------------------ DEFINES ------------------------------------------------------------

// GPIOx memory adresses for the STM32F407VG device, but only uint32_t memory adresses, not casted to GPIO_TypeDef

#define myGPIOA               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x0000))
#define myGPIOB               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x0400))
#define myGPIOC               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x0800))
#define myGPIOD               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x0C00))
#define myGPIOE               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x1000))
#define myGPIOF               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x1400))
#define myGPIOG               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x1800))
#define myGPIOH               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x1C00))
#define myGPIOI               ( (myGPIO*) ((((uint32_t)0x40000000) + 0x00020000) + 0x2000))

// ------------------------------------------------------------ ENUM CLASSES ------------------------------------------------------------

/**
  * @brief  GPIO Configuration Mode enumeration
  */
enum class GPIO_Mode
{
  IN   = 0x00, /*!< GPIO Input Mode */
  OUT  = 0x01, /*!< GPIO Output Mode */
  AF   = 0x02, /*!< GPIO Alternate function Mode */
  AN   = 0x03  /*!< GPIO Analog Mode */
};

/**
  * @brief  GPIO Output type enumeration
  */
enum class GPIO_OType
{
  PP = 0x00,
  OD = 0x01
};

/**
  * @brief  GPIO Output Maximum frequency enumeration
  */
enum class GPIO_Speed
{
  S_2MHz   = 0x00, /*!< Low speed */
  S_25MHz  = 0x01, /*!< Medium speed */
  S_50MHz  = 0x02, /*!< Fast speed */
  S_100MHz = 0x03  /*!< High speed on 30 pF (80 MHz Output max speed on 15 pF) */
};

/**
  * @brief  GPIO Configuration PullUp PullDown enumeration
  */
enum class GPIO_PuPd
{
  NOPULL = 0x00,
  UP     = 0x01,
  DOWN   = 0x02
};

/**
  * @brief  GPIO Bit SET and Bit RESET enumeration
  */
enum class Bit_Action
{
  RESET = 0,
  SET
};


// ------------------------------------------------------------ GPIO CLASS ------------------------------------------------------------

class myGPIO {
	volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
	volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
	volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
	volatile uint16_t BSRRL;    /*!< GPIO port bit set/reset low register,  Address offset: 0x18      */
	volatile uint16_t BSRRH;    /*!< GPIO port bit set/reset high register, Address offset: 0x1A      */
	volatile uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	volatile uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */

public:

	void inline setBit(uint16_t pin) {
		BSRRL = pin;
	}

	void inline resetBit(uint16_t pin) {
		BSRRH = pin;
	}

	void inline toggleBit(uint16_t pin) {
		 ODR ^= pin;
	}

	void init(GPIO_Mode mode, GPIO_OType type, GPIO_PuPd pupd, GPIO_Speed speed, uint16_t pin);

};


#endif
