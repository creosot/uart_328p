#ifndef _INIT_USART_H_
#define _INIT_USART_H_

#ifdef __cplusplus
extern "C" {
#endif

#define BAUD 9600

//! set the baud rate tolerance to 2%
#define BAUD_TOL 2

//! define what PORT the UART0 is connected to
#define UART_PORT_DDR DDRD

//! define what pins are used for UART0 TX and RX
#define UART_RX_PIN PIN0
#define UART_TX_PIN PIN1
	
#ifdef __cplusplus
}
#endif

#endif