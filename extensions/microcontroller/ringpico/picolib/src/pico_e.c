#include "ring.h"

#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "hardware/spi.h"
#include "hardware/pwm.h"
#include "hardware/uart.h"
#include "hardware/claim.h"

RING_FUNC(ring_get_pico_default_led_pin)
{
	RING_API_RETNUMBER(PICO_DEFAULT_LED_PIN);
}

RING_FUNC(ring_get_gpio_out)
{
	RING_API_RETNUMBER(GPIO_OUT);
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


RING_FUNC(ring_pwm_gpio_to_slice_num)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pwm_gpio_to_slice_num( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_pwm_gpio_to_channel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pwm_gpio_to_channel( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_pwm_config_set_phase_correct)
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
	pwm_config_set_phase_correct((pwm_config *) RING_API_GETCPOINTER(1,"pwm_config"), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_config_set_clkdiv)
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
	pwm_config_set_clkdiv((pwm_config *) RING_API_GETCPOINTER(1,"pwm_config"), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_config_set_clkdiv_int_frac)
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
	pwm_config_set_clkdiv_int_frac((pwm_config *) RING_API_GETCPOINTER(1,"pwm_config"), (uint8_t ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_pwm_config_set_clkdiv_int)
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
	pwm_config_set_clkdiv_int((pwm_config *) RING_API_GETCPOINTER(1,"pwm_config"), (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_config_set_clkdiv_mode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pwm_config_set_clkdiv_mode((pwm_config *) RING_API_GETCPOINTER(1,"pwm_config"),* (enum pwm_clkdiv_mode  *) RING_API_GETCPOINTER(2,"enum pwm_clkdiv_mode"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"enum pwm_clkdiv_mode"));
}


RING_FUNC(ring_pwm_config_set_output_polarity)
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
	pwm_config_set_output_polarity((pwm_config *) RING_API_GETCPOINTER(1,"pwm_config"), (bool ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_pwm_config_set_wrap)
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
	pwm_config_set_wrap((pwm_config *) RING_API_GETCPOINTER(1,"pwm_config"), (uint16_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_init)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
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
	pwm_init( (uint ) RING_API_GETNUMBER(1),(pwm_config *) RING_API_GETCPOINTER(2,"pwm_config"), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_pwm_get_default_config)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		pwm_config *pValue ; 
		pValue = (pwm_config *) RING_API_MALLOC(sizeof(pwm_config)) ;
		*pValue = pwm_get_default_config();
		RING_API_RETMANAGEDCPOINTER(pValue,"pwm_config",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_pwm_set_wrap)
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
	pwm_set_wrap( (uint ) RING_API_GETNUMBER(1), (uint16_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_set_chan_level)
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
	pwm_set_chan_level( (uint ) RING_API_GETNUMBER(1), (uint ) RING_API_GETNUMBER(2), (uint16_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_pwm_set_both_levels)
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
	pwm_set_both_levels( (uint ) RING_API_GETNUMBER(1), (uint16_t ) RING_API_GETNUMBER(2), (uint16_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_pwm_set_gpio_level)
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
	pwm_set_gpio_level( (uint ) RING_API_GETNUMBER(1), (uint16_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_get_counter)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pwm_get_counter( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_pwm_set_counter)
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
	pwm_set_counter( (uint ) RING_API_GETNUMBER(1), (uint16_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_advance_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pwm_advance_count( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_pwm_retard_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pwm_retard_count( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_pwm_set_clkdiv_int_frac)
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
	pwm_set_clkdiv_int_frac( (uint ) RING_API_GETNUMBER(1), (uint8_t ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_pwm_set_clkdiv)
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
	pwm_set_clkdiv( (uint ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_set_output_polarity)
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
	pwm_set_output_polarity( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_pwm_set_clkdiv_mode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pwm_set_clkdiv_mode( (uint ) RING_API_GETNUMBER(1),* (enum pwm_clkdiv_mode  *) RING_API_GETCPOINTER(2,"enum pwm_clkdiv_mode"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"enum pwm_clkdiv_mode"));
}


RING_FUNC(ring_pwm_set_phase_correct)
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
	pwm_set_phase_correct( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_set_enabled)
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
	pwm_set_enabled( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_set_mask_enabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pwm_set_mask_enabled( (uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_pwm_set_irq_enabled)
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
	pwm_set_irq_enabled( (uint ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_set_irq_mask_enabled)
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
	pwm_set_irq_mask_enabled( (uint32_t ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_pwm_clear_irq)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pwm_clear_irq( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_pwm_get_irq_status_mask)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(pwm_get_irq_status_mask());
}


RING_FUNC(ring_pwm_force_irq)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pwm_force_irq( (uint ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_pwm_get_dreq)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(pwm_get_dreq( (uint ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_uart_get_index)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uart_get_index((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t")));
}


RING_FUNC(ring_uart_init)
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
	RING_API_RETNUMBER(uart_init((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uart_deinit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uart_deinit((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"));
}


RING_FUNC(ring_uart_set_baudrate)
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
	RING_API_RETNUMBER(uart_set_baudrate((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uart_set_hw_flow)
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
	uart_set_hw_flow((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (bool ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uart_set_format)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uart_set_format((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (uint ) RING_API_GETNUMBER(2), (uint ) RING_API_GETNUMBER(3),* (uart_parity_t  *) RING_API_GETCPOINTER(4,"uart_parity_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uart_parity_t"));
}


RING_FUNC(ring_uart_set_irq_enables)
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
	uart_set_irq_enables((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (bool ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uart_is_enabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uart_is_enabled((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t")));
}


RING_FUNC(ring_uart_set_fifo_enabled)
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
	uart_set_fifo_enabled((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uart_is_writable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uart_is_writable((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t")));
}


RING_FUNC(ring_uart_tx_wait_blocking)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uart_tx_wait_blocking((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"));
}


RING_FUNC(ring_uart_is_readable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uart_is_readable((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t")));
}


RING_FUNC(ring_uart_write_blocking)
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
	uart_write_blocking((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"), (size_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uart_read_blocking)
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
	uart_read_blocking((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"),(uint8_t *) RING_API_GETCPOINTER(2,"uint8_t"), (size_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uart_putc_raw)
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
	uart_putc_raw((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (char ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uart_putc)
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
	uart_putc((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (char ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uart_puts)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uart_puts((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uart_getc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uart_getc((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t")));
}


RING_FUNC(ring_uart_set_break)
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
	uart_set_break((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uart_set_translate_crlf)
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
	uart_set_translate_crlf((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uart_default_tx_wait_blocking)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	uart_default_tx_wait_blocking();
}


RING_FUNC(ring_uart_is_readable_within_us)
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
	RING_API_RETNUMBER(uart_is_readable_within_us((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uart_get_dreq)
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
	RING_API_RETNUMBER(uart_get_dreq((uart_inst_t *) RING_API_GETCPOINTER(1,"uart_inst_t"), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_hw_claim_or_assert)
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	hw_claim_or_assert((uint8_t *) RING_API_GETCPOINTER(1,"uint8_t"), (uint ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_hw_claim_unused_from_range)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(hw_claim_unused_from_range((uint8_t *) RING_API_GETCPOINTER(1,"uint8_t"), (bool ) RING_API_GETNUMBER(2), (uint ) RING_API_GETNUMBER(3), (uint ) RING_API_GETNUMBER(4),RING_API_GETSTRING(5)));
}


RING_FUNC(ring_hw_is_claimed)
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
	RING_API_RETNUMBER(hw_is_claimed((uint8_t *) RING_API_GETCPOINTER(1,"uint8_t"), (uint ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_hw_claim_clear)
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
	hw_claim_clear((uint8_t *) RING_API_GETCPOINTER(1,"uint8_t"), (uint ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_hw_claim_lock)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(hw_claim_lock());
}


RING_FUNC(ring_hw_claim_unlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	hw_claim_unlock( (uint32_t ) RING_API_GETNUMBER(1));
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


RING_FUNC(ring_ring_malloc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ring_malloc( (size_t ) RING_API_GETNUMBER(1)),"void");
}


RING_FUNC(ring_ring_free)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ring_free((void *) RING_API_GETCPOINTER(1,"void"));
}

RING_API void ring_vm_pico_loadfunctions(RingState *pRingState)
{
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
	RING_API_REGISTER("pwm_gpio_to_slice_num",ring_pwm_gpio_to_slice_num);
	RING_API_REGISTER("pwm_gpio_to_channel",ring_pwm_gpio_to_channel);
	RING_API_REGISTER("pwm_config_set_phase_correct",ring_pwm_config_set_phase_correct);
	RING_API_REGISTER("pwm_config_set_clkdiv",ring_pwm_config_set_clkdiv);
	RING_API_REGISTER("pwm_config_set_clkdiv_int_frac",ring_pwm_config_set_clkdiv_int_frac);
	RING_API_REGISTER("pwm_config_set_clkdiv_int",ring_pwm_config_set_clkdiv_int);
	RING_API_REGISTER("pwm_config_set_clkdiv_mode",ring_pwm_config_set_clkdiv_mode);
	RING_API_REGISTER("pwm_config_set_output_polarity",ring_pwm_config_set_output_polarity);
	RING_API_REGISTER("pwm_config_set_wrap",ring_pwm_config_set_wrap);
	RING_API_REGISTER("pwm_init",ring_pwm_init);
	RING_API_REGISTER("pwm_get_default_config",ring_pwm_get_default_config);
	RING_API_REGISTER("pwm_set_wrap",ring_pwm_set_wrap);
	RING_API_REGISTER("pwm_set_chan_level",ring_pwm_set_chan_level);
	RING_API_REGISTER("pwm_set_both_levels",ring_pwm_set_both_levels);
	RING_API_REGISTER("pwm_set_gpio_level",ring_pwm_set_gpio_level);
	RING_API_REGISTER("pwm_get_counter",ring_pwm_get_counter);
	RING_API_REGISTER("pwm_set_counter",ring_pwm_set_counter);
	RING_API_REGISTER("pwm_advance_count",ring_pwm_advance_count);
	RING_API_REGISTER("pwm_retard_count",ring_pwm_retard_count);
	RING_API_REGISTER("pwm_set_clkdiv_int_frac",ring_pwm_set_clkdiv_int_frac);
	RING_API_REGISTER("pwm_set_clkdiv",ring_pwm_set_clkdiv);
	RING_API_REGISTER("pwm_set_output_polarity",ring_pwm_set_output_polarity);
	RING_API_REGISTER("pwm_set_clkdiv_mode",ring_pwm_set_clkdiv_mode);
	RING_API_REGISTER("pwm_set_phase_correct",ring_pwm_set_phase_correct);
	RING_API_REGISTER("pwm_set_enabled",ring_pwm_set_enabled);
	RING_API_REGISTER("pwm_set_mask_enabled",ring_pwm_set_mask_enabled);
	RING_API_REGISTER("pwm_set_irq_enabled",ring_pwm_set_irq_enabled);
	RING_API_REGISTER("pwm_set_irq_mask_enabled",ring_pwm_set_irq_mask_enabled);
	RING_API_REGISTER("pwm_clear_irq",ring_pwm_clear_irq);
	RING_API_REGISTER("pwm_get_irq_status_mask",ring_pwm_get_irq_status_mask);
	RING_API_REGISTER("pwm_force_irq",ring_pwm_force_irq);
	RING_API_REGISTER("pwm_get_dreq",ring_pwm_get_dreq);
	RING_API_REGISTER("uart_get_index",ring_uart_get_index);
	RING_API_REGISTER("uart_init",ring_uart_init);
	RING_API_REGISTER("uart_deinit",ring_uart_deinit);
	RING_API_REGISTER("uart_set_baudrate",ring_uart_set_baudrate);
	RING_API_REGISTER("uart_set_hw_flow",ring_uart_set_hw_flow);
	RING_API_REGISTER("uart_set_format",ring_uart_set_format);
	RING_API_REGISTER("uart_set_irq_enables",ring_uart_set_irq_enables);
	RING_API_REGISTER("uart_is_enabled",ring_uart_is_enabled);
	RING_API_REGISTER("uart_set_fifo_enabled",ring_uart_set_fifo_enabled);
	RING_API_REGISTER("uart_is_writable",ring_uart_is_writable);
	RING_API_REGISTER("uart_tx_wait_blocking",ring_uart_tx_wait_blocking);
	RING_API_REGISTER("uart_is_readable",ring_uart_is_readable);
	RING_API_REGISTER("uart_write_blocking",ring_uart_write_blocking);
	RING_API_REGISTER("uart_read_blocking",ring_uart_read_blocking);
	RING_API_REGISTER("uart_putc_raw",ring_uart_putc_raw);
	RING_API_REGISTER("uart_putc",ring_uart_putc);
	RING_API_REGISTER("uart_puts",ring_uart_puts);
	RING_API_REGISTER("uart_getc",ring_uart_getc);
	RING_API_REGISTER("uart_set_break",ring_uart_set_break);
	RING_API_REGISTER("uart_set_translate_crlf",ring_uart_set_translate_crlf);
	RING_API_REGISTER("uart_default_tx_wait_blocking",ring_uart_default_tx_wait_blocking);
	RING_API_REGISTER("uart_is_readable_within_us",ring_uart_is_readable_within_us);
	RING_API_REGISTER("uart_get_dreq",ring_uart_get_dreq);
	RING_API_REGISTER("hw_claim_or_assert",ring_hw_claim_or_assert);
	RING_API_REGISTER("hw_claim_unused_from_range",ring_hw_claim_unused_from_range);
	RING_API_REGISTER("hw_is_claimed",ring_hw_is_claimed);
	RING_API_REGISTER("hw_claim_clear",ring_hw_claim_clear);
	RING_API_REGISTER("hw_claim_lock",ring_hw_claim_lock);
	RING_API_REGISTER("hw_claim_unlock",ring_hw_claim_unlock);
	RING_API_REGISTER("sleep_ms",ring_sleep_ms);
	RING_API_REGISTER("ring_malloc",ring_ring_malloc);
	RING_API_REGISTER("ring_free",ring_ring_free);
	RING_API_REGISTER("get_pico_default_led_pin",ring_get_pico_default_led_pin);
	RING_API_REGISTER("get_gpio_out",ring_get_gpio_out);
}
