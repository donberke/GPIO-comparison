
#ifndef GPIO_CPP
#define GPIO_CPP

#include "stm32f4xx.h"


class GPIO {
public:

	void inline setBit(uint16_t pin) {
		GPIOD->BSRRL = pin;
	}

	void inline resetBit(uint16_t pin) {
		GPIOD->BSRRH = pin;
	}

};



#endif
