#include <stdio.h>

int main() {
	int a = 10;	// Variável Inteira => 4bytes
	int b, c;

	// %p imprime o endereço de memória
	// %d imprime o dígito inteiro
	printf("&a = %p, a = %d\n",   &a, a);		// &a = 0x7ffcb7f3c9ac, a = 10
	printf("&b = %p, b = %d\n",   &b, b);		// &b = 0x7ffcb7f3c9b0, b = 4096 (valor de 'b' é lixo de memória)
	printf("&c = %p, c = %d\n\n", &c, c);		// &c = 0x7ffcb7f3c9b4, c = 0		 (valor de 'c' é lixo de memória)

	b = 20;
	c = a + b;

	printf("&a = %p, a = %d\n",   &a, a);		// &a = 0x7ffcb7f3c9ac, a = 10
  printf("&b = %p, b = %d\n",   &b, b);		// &b = 0x7ffcb7f3c9b0, b = 20
  printf("&c = %p, c = %d\n\n", &c, c);		// &c = 0x7ffcb7f3c9b4, c = 30

	return 0;
}
