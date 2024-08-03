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


RING_FUNC(ring_gpio_set_function)
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
	gpio_set_function( (uint ) RING_API_GETNUMBER(1), (enum gpio_function )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_get_function)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_get_function( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_set_pulls)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_pulls( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_gpio_pull_up)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_pull_up( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_is_pulled_up)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_is_pulled_up( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_pull_down)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_pull_down( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_is_pulled_down)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_is_pulled_down( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_disable_pulls)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_disable_pulls( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_set_irqover)
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
	gpio_set_irqover( (uint ) RING_API_GETNUMBER(1), (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_set_outover)
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
	gpio_set_outover( (uint ) RING_API_GETNUMBER(1), (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_set_inover)
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
	gpio_set_inover( (uint ) RING_API_GETNUMBER(1), (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_set_oeover)
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
	gpio_set_oeover( (uint ) RING_API_GETNUMBER(1), (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_set_input_enabled)
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
	gpio_set_input_enabled( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_set_input_hysteresis_enabled)
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
	gpio_set_input_hysteresis_enabled( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_is_input_hysteresis_enabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_is_input_hysteresis_enabled( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_set_slew_rate)
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
	gpio_set_slew_rate( (uint ) RING_API_GETNUMBER(1), (enum gpio_slew_rate )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_get_slew_rate)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_get_slew_rate( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_set_drive_strength)
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
	gpio_set_drive_strength( (uint ) RING_API_GETNUMBER(1), (enum gpio_drive_strength )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_get_drive_strength)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_get_drive_strength( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_set_irq_enabled)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_irq_enabled( (uint ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_gpio_set_irq_callback)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	gpio_set_irq_callback(* (gpio_irq_callback_t  *) RING_API_GETCPOINTER(1,"gpio_irq_callback_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"gpio_irq_callback_t"));
}


RING_FUNC(ring_gpio_set_irq_enabled_with_callback)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_irq_enabled_with_callback( (uint ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3),* (gpio_irq_callback_t  *) RING_API_GETCPOINTER(4,"gpio_irq_callback_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"gpio_irq_callback_t"));
}


RING_FUNC(ring_gpio_set_dormant_irq_enabled)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_dormant_irq_enabled( (uint ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_gpio_get_irq_event_mask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_get_irq_event_mask( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_acknowledge_irq)
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
	gpio_acknowledge_irq( (uint ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2));
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
	gpio_init( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_deinit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_deinit( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_init_mask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_init_mask( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_get)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_get( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_get_all)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(gpio_get_all());
}


RING_FUNC(ring_gpio_set_mask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_mask( (uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_clr_mask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_clr_mask( (uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_xor_mask)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_xor_mask( (uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_put_masked)
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
	gpio_put_masked( (uint32_t ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_put_all)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_put_all( (uint32_t ) RING_API_GETNUMBER(1));
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
	gpio_put( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_get_out_level)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_get_out_level( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_set_dir_out_masked)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_dir_out_masked( (uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_set_dir_in_masked)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_dir_in_masked( (uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_gpio_set_dir_masked)
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
	gpio_set_dir_masked( (uint32_t ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_set_dir_all_bits)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gpio_set_dir_all_bits( (uint32_t ) RING_API_GETNUMBER(1));
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
	gpio_set_dir( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_gpio_is_dir_out)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_is_dir_out( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_gpio_get_dir)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gpio_get_dir( (uint ) RING_API_GETNUMBER(1)));
}

RING_API void ring_vm_pico_loadfunctions(RingState *pRingState)
{
	RING_API_REGISTER("sleep_ms",ring_sleep_ms);
	RING_API_REGISTER("gpio_set_function",ring_gpio_set_function);
	RING_API_REGISTER("gpio_get_function",ring_gpio_get_function);
	RING_API_REGISTER("gpio_set_pulls",ring_gpio_set_pulls);
	RING_API_REGISTER("gpio_pull_up",ring_gpio_pull_up);
	RING_API_REGISTER("gpio_is_pulled_up",ring_gpio_is_pulled_up);
	RING_API_REGISTER("gpio_pull_down",ring_gpio_pull_down);
	RING_API_REGISTER("gpio_is_pulled_down",ring_gpio_is_pulled_down);
	RING_API_REGISTER("gpio_disable_pulls",ring_gpio_disable_pulls);
	RING_API_REGISTER("gpio_set_irqover",ring_gpio_set_irqover);
	RING_API_REGISTER("gpio_set_outover",ring_gpio_set_outover);
	RING_API_REGISTER("gpio_set_inover",ring_gpio_set_inover);
	RING_API_REGISTER("gpio_set_oeover",ring_gpio_set_oeover);
	RING_API_REGISTER("gpio_set_input_enabled",ring_gpio_set_input_enabled);
	RING_API_REGISTER("gpio_set_input_hysteresis_enabled",ring_gpio_set_input_hysteresis_enabled);
	RING_API_REGISTER("gpio_is_input_hysteresis_enabled",ring_gpio_is_input_hysteresis_enabled);
	RING_API_REGISTER("gpio_set_slew_rate",ring_gpio_set_slew_rate);
	RING_API_REGISTER("gpio_get_slew_rate",ring_gpio_get_slew_rate);
	RING_API_REGISTER("gpio_set_drive_strength",ring_gpio_set_drive_strength);
	RING_API_REGISTER("gpio_get_drive_strength",ring_gpio_get_drive_strength);
	RING_API_REGISTER("gpio_set_irq_enabled",ring_gpio_set_irq_enabled);
	RING_API_REGISTER("gpio_set_irq_callback",ring_gpio_set_irq_callback);
	RING_API_REGISTER("gpio_set_irq_enabled_with_callback",ring_gpio_set_irq_enabled_with_callback);
	RING_API_REGISTER("gpio_set_dormant_irq_enabled",ring_gpio_set_dormant_irq_enabled);
	RING_API_REGISTER("gpio_get_irq_event_mask",ring_gpio_get_irq_event_mask);
	RING_API_REGISTER("gpio_acknowledge_irq",ring_gpio_acknowledge_irq);
	RING_API_REGISTER("gpio_init",ring_gpio_init);
	RING_API_REGISTER("gpio_deinit",ring_gpio_deinit);
	RING_API_REGISTER("gpio_init_mask",ring_gpio_init_mask);
	RING_API_REGISTER("gpio_get",ring_gpio_get);
	RING_API_REGISTER("gpio_get_all",ring_gpio_get_all);
	RING_API_REGISTER("gpio_set_mask",ring_gpio_set_mask);
	RING_API_REGISTER("gpio_clr_mask",ring_gpio_clr_mask);
	RING_API_REGISTER("gpio_xor_mask",ring_gpio_xor_mask);
	RING_API_REGISTER("gpio_put_masked",ring_gpio_put_masked);
	RING_API_REGISTER("gpio_put_all",ring_gpio_put_all);
	RING_API_REGISTER("gpio_put",ring_gpio_put);
	RING_API_REGISTER("gpio_get_out_level",ring_gpio_get_out_level);
	RING_API_REGISTER("gpio_set_dir_out_masked",ring_gpio_set_dir_out_masked);
	RING_API_REGISTER("gpio_set_dir_in_masked",ring_gpio_set_dir_in_masked);
	RING_API_REGISTER("gpio_set_dir_masked",ring_gpio_set_dir_masked);
	RING_API_REGISTER("gpio_set_dir_all_bits",ring_gpio_set_dir_all_bits);
	RING_API_REGISTER("gpio_set_dir",ring_gpio_set_dir);
	RING_API_REGISTER("gpio_is_dir_out",ring_gpio_is_dir_out);
	RING_API_REGISTER("gpio_get_dir",ring_gpio_get_dir);
	RING_API_REGISTER("get_pico_default_led_pin",ring_get_pico_default_led_pin);
	RING_API_REGISTER("get_gpio_out",ring_get_gpio_out);
}
