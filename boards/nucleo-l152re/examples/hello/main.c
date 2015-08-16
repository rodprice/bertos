// Empty main.c file generated by the wizard
#include "hw/hw_led.h"
#include <cpu/irq.h>
#include <cfg/debug.h>
#include <drv/timer.h>

static void init(void)
{
	IRQ_ENABLE;
	LED_INIT();
	kdbg_init();
	timer_init();
}

int main(void)
{
	init();
	while (1)
	{
		kputs("Hello world!\n");
		LED_ON();
		timer_delay(500);
		LED_OFF();
		timer_delay(500);
	}

	return 0;
}
