/************* t.c file of C2.5 **************/
int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // data array
int sum;

#include <string.h>  // contains strlen(), strcmp(), etc.

#include "uart.h"  // UART driver code file

int mane() {
  int i;
  sum = 10;
  char string[64];
  UART* up;
  up = &uart[0];  // test UART0
  uart_init();  // initialize UARTs
  sum = 100;
  uprints(up, "Enter lines from serial terminal 0\n\r");
  sum = 1000;
  uprints(up, "Compute sum of array:\n\r");
  sum = 0;
  for (i = 0; i < 10; i++) sum += v[i];
  uprints(up, "sum = ");
  uputc(up, (sum / 10) + '0');
  uputc(up, (sum % 10) + '0');
  uprints(up,"\n\r\n\r");

  for (i=0; i<4;i++){
    UART* curr = &uart[i];
    int baudRate = (7.38*1000*1000) / (*(curr->base+UARTIBRD) * 16);
    uprintf(up,"UART[%u] Baudrate: %u\n\r",i, baudRate);
    uprintf(up,"UART[%u] Line Control Register: 0x%x\n\r",i, *(curr->base+UARTLCR));
  }
  uprints(up, "\n\rEND OF RUN\n\r");
}