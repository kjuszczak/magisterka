#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

#include <stdint.h>

void board_config();
uint8_t uart_transmit(char *pData);
void toggle_led();
void delay(uint32_t period);

/* Private */
void clock_config(void);
void gpio_config(void);
void uart_config(void);
void dma_config(void);

#endif // BOARD_CONFIG_H