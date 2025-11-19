#include <stddef.h>
#include <stdint.h>
#define UART0 0x10000000UL
uint16_t *fbp;
void uart_putc(char c) {
    *(volatile char*)UART0 = c;
}

void putstr(const char *s) {
    while (*s) uart_putc(*s++);
}

void _starts() {
    int n=0;
    int nn=1024*4;
    int nnn=30000;
    fbp=(uint16_t * )4096;
    
    for(n=0;n<nnn;n++)*((uint16_t *)(fbp + n)) = 0xffff;
    putstr("\033[43;30m\nready\n");
    while(1) {}
}