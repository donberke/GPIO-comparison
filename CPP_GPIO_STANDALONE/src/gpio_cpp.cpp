
#include "gpio_cpp.h"

void myGPIO::init(GPIO_Mode mode, GPIO_OType type, GPIO_PuPd pupd, GPIO_Speed speed, uint16_t pin) {

  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

  /* ------------------------- Configure the port pins ---------------- */
  /*-- GPIO Mode Configuration --*/
  for (pinpos = 0x00; pinpos < 0x10; pinpos++)
  {
	pos = ((uint32_t)0x01) << pinpos;
	/* Get the port pins position */
	currentpin = (pin) & pos;

	if (currentpin == pos)
	{
	  MODER  &= ~(((uint32_t)0x00000003) << (pinpos * 2));
	  MODER |= (((uint32_t)mode) << (pinpos * 2));

	  if ((mode == GPIO_Mode::OUT) || (mode == GPIO_Mode::AF))
	  {

		/* Speed mode configuration */
		OSPEEDR &= ~(((uint32_t)0x00000003) << (pinpos * 2));
		OSPEEDR |= ((uint32_t)(speed) << (pinpos * 2));

		/* Output mode configuration*/
		OTYPER  &= ~((((uint32_t)0x00000001)) << ((uint16_t)pinpos)) ;
		OTYPER |= (uint16_t)(((uint16_t)type) << ((uint16_t)pinpos));
	  }

	  /* Pull-up Pull down resistor configuration*/
	  PUPDR &= ~(((uint32_t)0x00000003) << ((uint16_t)pinpos * 2));
	  PUPDR |= (((uint32_t)pupd) << (pinpos * 2));
	}
  }
}










