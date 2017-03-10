/*
 * uart_328p.c
 *
 * Created: 09.03.2017 15:40:12
 * Author : Zver
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>
#include <ASF/mega/drivers/usart/usart_mega.h>
#include <ASF/common/services/ioport/ioport.h>

#define MY_LED    IOPORT_CREATE_PIN(PORTB, 5)

static usart_rs232_options_t USART_OPTIONS = {
	.baudrate = USART_BAUD_9600,
	.charlength = USART_CHSIZE_8BIT_gc,
	.paritytype = USART_PMODE_DISABLED_gc,
	.stopbits = false,
};


int main(void)
{
	ioport_init();
	ioport_set_pin_dir(MY_LED, IOPORT_DIR_OUTPUT);
	ioport_set_pin_low(MY_LED);
	usart_init_rs232(&USART0, &USART_OPTIONS);
	
	_delay_ms(1000);
    while (1) 
    {
		ioport_set_pin_low(MY_LED);
		_delay_ms(1000);
		usart_put(&USART0, "a");
		ioport_set_pin_high(MY_LED);
		_delay_ms(1000);
		//usart_putchar(&USART0, 50);
    }
}

