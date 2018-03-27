
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
	  GPIO->MODER  &= ~(GPIO_MODER_MODER0 << (pinpos * 2));
	  GPIO->MODER |= (((uint32_t)mode) << (pinpos * 2));

	  if ((mode == GPIO_Mode::OUT) || (mode == GPIO_Mode::AF))
	  {

		/* Speed mode configuration */
		GPIO->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (pinpos * 2));
		GPIO->OSPEEDR |= ((uint32_t)(speed) << (pinpos * 2));

		/* Output mode configuration*/
		GPIO->OTYPER  &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pinpos)) ;
		GPIO->OTYPER |= (uint16_t)(((uint16_t)type) << ((uint16_t)pinpos));
	  }

	  /* Pull-up Pull down resistor configuration*/
	  GPIO->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pinpos * 2));
	  GPIO->PUPDR |= (((uint32_t)pupd) << (pinpos * 2));
	}
  }
}










