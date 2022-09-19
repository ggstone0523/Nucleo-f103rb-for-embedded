#define MY_GPIOA_CRL   (*(volatile unsigned int *)0x40010800)
#define MY_GPIOA_ODR   (*(volatile unsigned int *)0x4001080C)
#define MY_RCC_APB2ENR (*(volatile unsigned int *)0x40021018)

volatile unsigned int time = 100000;

int main(void)
{

  MY_RCC_APB2ENR |= (0x1 << 2);
  MY_GPIOA_CRL &= ~(0x7 << 21);
  MY_GPIOA_CRL |= (0x1 << 20);

  int i;
  while (1)
  {
	MY_GPIOA_ODR |= (0x1 << 5);
	for(i = 0; i < time; i++);
	MY_GPIOA_ODR &= ~(0x1 << 5);
	for(i = 0; i < time; i++);
  }
}
