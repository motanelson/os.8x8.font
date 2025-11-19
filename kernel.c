#include <stddef.h>
#include <stdint.h>
long __stack_chk_guard;
long __stack_chk_fail;
#define UART0 0x10000000UL
uint16_t *fbp;
void uart_putc(char c) {
    *(volatile char*)UART0 = c;
}

void putstr(const char *s) {
    while (*s) uart_putc(*s++);
}
void uart_tputs(const char* str)
{
	for (size_t i = 0; str[i] != '\0'; i ++)
		uart_putc((unsigned char)str[i]);
}
void hexss(int i){
	char gg[]="0123456789ABCDEF0123456789ABCDEF";
        
        
	int pos=0;
	for(pos=28;pos>-1;pos=pos-4){
                
		uart_putc( gg[i >> pos & 0xf]);
	}
	uart_putc('\n');
	
} 


void _starts() {
    int n=0;
        
    for(n=0;n<16;n++){
         hexss(n);
         uart_putc('\n');
    }
    putstr("\033[43;30m\nready\n");
    while(1) {}
}