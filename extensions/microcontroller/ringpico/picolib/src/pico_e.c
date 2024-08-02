#include "ring.h"

#include "pico/stdlib.h"

RING_FUNC(ring_get_pico_default_led_pin)
{
	RING_API_RETNUMBER(PICO_DEFAULT_LED_PIN);
}

RING_FUNC(ring_get_gpio_out)
{
	RING_API_RETNUMBER(GPIO_OUT);
}


RING_FUNC(ring_gpio_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_init( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_set_dir)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_dir( (int) RING_API_GETNUMBER(1), (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_put)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_put( (int) RING_API_GETNUMBER(1), (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_sleep_ms)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	sleep_ms( (int) RING_API_GETNUMBER(1));
}

RING_API void ring_vm_pico_loadfunctions(RingState *pRingState)
{
	RING_API_REGISTER("gpio_init",ring_gpio_init);
	RING_API_REGISTER("gpio_set_dir",ring_gpio_set_dir);
	RING_API_REGISTER("gpio_put",ring_gpio_put);
	RING_API_REGISTER("sleep_ms",ring_sleep_ms);
	RING_API_REGISTER("get_pico_default_led_pin",ring_get_pico_default_led_pin);
	RING_API_REGISTER("get_gpio_out",ring_get_gpio_out);
}
