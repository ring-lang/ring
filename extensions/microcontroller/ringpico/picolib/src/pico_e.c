#include "ring.h"

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "hardware/spi.h"

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


RING_FUNC(ring_adc_init)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	adc_init();
}


RING_FUNC(ring_adc_gpio_init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_gpio_init( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_adc_select_input)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_select_input( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_adc_get_selected_input)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(adc_get_selected_input());
}


RING_FUNC(ring_adc_set_round_robin)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_set_round_robin( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_adc_set_temp_sensor_enabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_set_temp_sensor_enabled( (bool ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_adc_read)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(adc_read());
}


RING_FUNC(ring_adc_run)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_run( (bool ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_adc_set_clkdiv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_set_clkdiv( (float ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_adc_fifo_setup)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_fifo_setup( (bool ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2), (uint16_t ) RING_API_GETNUMBER(3), (bool ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_adc_fifo_is_empty)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(adc_fifo_is_empty());
}


RING_FUNC(ring_adc_fifo_get_level)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(adc_fifo_get_level());
}


RING_FUNC(ring_adc_fifo_drain)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	adc_fifo_drain();
}


RING_FUNC(ring_adc_fifo_get)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(adc_fifo_get());
}


RING_FUNC(ring_adc_fifo_get_blocking)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(adc_fifo_get_blocking());
}


RING_FUNC(ring_adc_irq_set_enabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	adc_irq_set_enabled( (bool ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_i2c_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_init((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_i2c_deinit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	i2c_deinit((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"));
}


RING_FUNC(ring_i2c_set_baudrate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_set_baudrate((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_i2c_set_slave_mode)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	i2c_set_slave_mode((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (bool ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_i2c_hw_index)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_hw_index((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t")));
}


RING_FUNC(ring_i2c_write_blocking_until)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_write_blocking_until((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint8_t ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5),* (absolute_time_t  *) RING_API_GETCPOINTER(6,"absolute_time_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"absolute_time_t"));
}


RING_FUNC(ring_i2c_read_blocking_until)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_read_blocking_until((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint8_t ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5),* (absolute_time_t  *) RING_API_GETCPOINTER(6,"absolute_time_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"absolute_time_t"));
}


RING_FUNC(ring_i2c_write_timeout_us)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_write_timeout_us((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint8_t ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5), (uint ) RING_API_GETNUMBER(6)));
}


RING_FUNC(ring_i2c_read_timeout_us)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_read_timeout_us((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint8_t ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5), (uint ) RING_API_GETNUMBER(6)));
}


RING_FUNC(ring_i2c_write_blocking)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_write_blocking((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint8_t ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_i2c_read_blocking)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_read_blocking((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint8_t ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4), (bool ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_i2c_get_write_available)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_get_write_available((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t")));
}


RING_FUNC(ring_i2c_get_read_available)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_get_read_available((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t")));
}


RING_FUNC(ring_i2c_write_raw_blocking)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	i2c_write_raw_blocking((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"), (size_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_i2c_read_raw_blocking)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	i2c_read_raw_blocking((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"), (size_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_i2c_read_byte_raw)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_read_byte_raw((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t")));
}


RING_FUNC(ring_i2c_write_byte_raw)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	i2c_write_byte_raw((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (uint8_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_i2c_get_dreq)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(i2c_get_dreq((i2c_inst_t *) RING_API_GETCPOINTER(1,"i2c_inst_t"), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_spi_init)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_init((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"), (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_spi_deinit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	spi_deinit((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"));
}


RING_FUNC(ring_spi_set_baudrate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_set_baudrate((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"), (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_spi_get_baudrate)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_get_baudrate((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t")));
}


RING_FUNC(ring_spi_get_index)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_get_index((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t")));
}


RING_FUNC(ring_spi_set_format)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	spi_set_format((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"), (uint ) RING_API_GETNUMBER(2),* (spi_cpol_t  *) RING_API_GETCPOINTER(3,"spi_cpol_t"),* (spi_cpha_t  *) RING_API_GETCPOINTER(4,"spi_cpha_t"),* (__unused spi_order_t  *) RING_API_GETCPOINTER(5,"__unused spi_order_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"spi_cpol_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"spi_cpha_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"__unused spi_order_t"));
}


RING_FUNC(ring_spi_set_slave)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	spi_set_slave((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_spi_is_writable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_is_writable((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t")));
}


RING_FUNC(ring_spi_is_readable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_is_readable((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t")));
}


RING_FUNC(ring_spi_is_busy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_is_busy((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t")));
}


RING_FUNC(ring_spi_write_read_blocking)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_write_read_blocking((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_spi_write_blocking)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_write_blocking((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_spi_read_blocking)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_read_blocking((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"), (uint8_t ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (size_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_spi_write16_read16_blocking)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_write16_read16_blocking((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"),(uint16_t *) RING_API_GETCPOINTER(2,"uint16_t"),(uint16_t *) RING_API_GETCPOINTER(3,"uint16_t"), (size_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_spi_write16_blocking)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_write16_blocking((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"),(uint16_t *) RING_API_GETCPOINTER(2,"uint16_t"), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_spi_read16_blocking)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_read16_blocking((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"), (uint16_t ) RING_API_GETNUMBER(2),(uint16_t *) RING_API_GETCPOINTER(3,"uint16_t"), (size_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_spi_get_dreq)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(spi_get_dreq((spi_inst_t *) RING_API_GETCPOINTER(1,"spi_inst_t"), (bool ) RING_API_GETNUMBER(2)));
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
	RING_API_REGISTER("adc_init",ring_adc_init);
	RING_API_REGISTER("adc_gpio_init",ring_adc_gpio_init);
	RING_API_REGISTER("adc_select_input",ring_adc_select_input);
	RING_API_REGISTER("adc_get_selected_input",ring_adc_get_selected_input);
	RING_API_REGISTER("adc_set_round_robin",ring_adc_set_round_robin);
	RING_API_REGISTER("adc_set_temp_sensor_enabled",ring_adc_set_temp_sensor_enabled);
	RING_API_REGISTER("adc_read",ring_adc_read);
	RING_API_REGISTER("adc_run",ring_adc_run);
	RING_API_REGISTER("adc_set_clkdiv",ring_adc_set_clkdiv);
	RING_API_REGISTER("adc_fifo_setup",ring_adc_fifo_setup);
	RING_API_REGISTER("adc_fifo_is_empty",ring_adc_fifo_is_empty);
	RING_API_REGISTER("adc_fifo_get_level",ring_adc_fifo_get_level);
	RING_API_REGISTER("adc_fifo_drain",ring_adc_fifo_drain);
	RING_API_REGISTER("adc_fifo_get",ring_adc_fifo_get);
	RING_API_REGISTER("adc_fifo_get_blocking",ring_adc_fifo_get_blocking);
	RING_API_REGISTER("adc_irq_set_enabled",ring_adc_irq_set_enabled);
	RING_API_REGISTER("i2c_init",ring_i2c_init);
	RING_API_REGISTER("i2c_deinit",ring_i2c_deinit);
	RING_API_REGISTER("i2c_set_baudrate",ring_i2c_set_baudrate);
	RING_API_REGISTER("i2c_set_slave_mode",ring_i2c_set_slave_mode);
	RING_API_REGISTER("i2c_hw_index",ring_i2c_hw_index);
	RING_API_REGISTER("i2c_write_blocking_until",ring_i2c_write_blocking_until);
	RING_API_REGISTER("i2c_read_blocking_until",ring_i2c_read_blocking_until);
	RING_API_REGISTER("i2c_write_timeout_us",ring_i2c_write_timeout_us);
	RING_API_REGISTER("i2c_read_timeout_us",ring_i2c_read_timeout_us);
	RING_API_REGISTER("i2c_write_blocking",ring_i2c_write_blocking);
	RING_API_REGISTER("i2c_read_blocking",ring_i2c_read_blocking);
	RING_API_REGISTER("i2c_get_write_available",ring_i2c_get_write_available);
	RING_API_REGISTER("i2c_get_read_available",ring_i2c_get_read_available);
	RING_API_REGISTER("i2c_write_raw_blocking",ring_i2c_write_raw_blocking);
	RING_API_REGISTER("i2c_read_raw_blocking",ring_i2c_read_raw_blocking);
	RING_API_REGISTER("i2c_read_byte_raw",ring_i2c_read_byte_raw);
	RING_API_REGISTER("i2c_write_byte_raw",ring_i2c_write_byte_raw);
	RING_API_REGISTER("i2c_get_dreq",ring_i2c_get_dreq);
	RING_API_REGISTER("spi_init",ring_spi_init);
	RING_API_REGISTER("spi_deinit",ring_spi_deinit);
	RING_API_REGISTER("spi_set_baudrate",ring_spi_set_baudrate);
	RING_API_REGISTER("spi_get_baudrate",ring_spi_get_baudrate);
	RING_API_REGISTER("spi_get_index",ring_spi_get_index);
	RING_API_REGISTER("spi_set_format",ring_spi_set_format);
	RING_API_REGISTER("spi_set_slave",ring_spi_set_slave);
	RING_API_REGISTER("spi_is_writable",ring_spi_is_writable);
	RING_API_REGISTER("spi_is_readable",ring_spi_is_readable);
	RING_API_REGISTER("spi_is_busy",ring_spi_is_busy);
	RING_API_REGISTER("spi_write_read_blocking",ring_spi_write_read_blocking);
	RING_API_REGISTER("spi_write_blocking",ring_spi_write_blocking);
	RING_API_REGISTER("spi_read_blocking",ring_spi_read_blocking);
	RING_API_REGISTER("spi_write16_read16_blocking",ring_spi_write16_read16_blocking);
	RING_API_REGISTER("spi_write16_blocking",ring_spi_write16_blocking);
	RING_API_REGISTER("spi_read16_blocking",ring_spi_read16_blocking);
	RING_API_REGISTER("spi_get_dreq",ring_spi_get_dreq);
	RING_API_REGISTER("get_pico_default_led_pin",ring_get_pico_default_led_pin);
	RING_API_REGISTER("get_gpio_out",ring_get_gpio_out);
}
