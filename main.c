#include <stm32f4xx.h>
#define led (1U<<4)
#define  GPIOAEN (1U<<0)

int main()
{
	RCC -> AHB1ENR |= GPIOAEN;

	GPIOA -> MODER |= (1<<8);
	GPIOA -> MODER &= ~(1<<9);

	while(1)
	{
		GPIOA -> ODR ^= led;
		for(int i=0;i<1000000;i++)
		{}
	}
	return 0;
}
