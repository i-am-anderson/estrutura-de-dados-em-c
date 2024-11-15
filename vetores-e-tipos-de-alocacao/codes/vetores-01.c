#include <stdio.h>

int main() {
  // Um vetor de inteiros dimensionado com 5 elementos
  // Aloca 5 endereços de INTEIROS (do v[0] ao v[4]), por exemplo, do 0x3a0 até
  // o 0x3b0 cada int ocupa 4 bytes, a declaração reserva um espaço de memória de 20 bytes
	// Vetor alocado estaticamente
  int v[5] = {1, 3, 5, 7, 11};

  for (int i = 0; i < 5; i++) {
    printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);	 // .................................
																																		// &v[0] = 0x7ffcb1cb53a0, v[0] = 1
																																		// &v[1] = 0x7ffcb1cb53a4, v[1] = 3
																																		// &v[2] = 0x7ffcb1cb53a8, v[2] = 5
																																		// &v[3] = 0x7ffcb1cb53ac, v[3] = 7
																																		// &v[4] = 0x7ffcb1cb53b0, v[4] = 11
  }

  printf("&v[6] = %p, v[6] = %d\n", &v[6], v[6]);	 // &v[6] = 0x7ffcb1cb53b8, v[6] = 1201912064 -> extrapola a dimensão do 
																													// vetor e retorna lixo de outra região de memória
																													
  return 0;
}