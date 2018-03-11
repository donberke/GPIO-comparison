
#ifndef GPIO_CPP
#define GPIO_CPP

#include "stm32f4xx.h"


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

};



#endif
