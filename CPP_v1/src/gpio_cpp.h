
#ifndef GPIO_CPP
#define GPIO_CPP

#include "stm32f4xx.h"

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
enum class GPIO_OTyoe
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
	GPIO_TypeDef * GPIO;

public:

	myGPIO(GPIO_TypeDef* GPIOx) : GPIO(GPIOx) {

	}

	void inline setBit(uint16_t pin) {
		GPIO->BSRRL = pin;
	}

	void inline resetBit(uint16_t pin) {
		GPIO->BSRRH = pin;
	}

	void inline toggleBit(uint16_t pin) {
		GPIO->ODR ^= pin;
	}

	void init(GPIO_Mode mode, GPIO_OTyoe type, GPIO_PuPd pupd, GPIO_Speed speed, uint16_t pin);

};


#endif
