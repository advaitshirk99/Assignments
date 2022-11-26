#include"header.h"

int main(void)
{ pll_init();
	IO0DIR|=0XFF;
	int a=0XAA;
	while(1)
	{ IOSET0|=a;
		delay_ms(100);
		IOCLR0|=a;
		delay_ms(100);
		if(a==0xAA) a=a>>1;
		else a=a<<1;
	}
	return 0;
}