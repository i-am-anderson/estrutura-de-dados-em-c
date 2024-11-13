#include <stdio.h>
#include <stdbool.h>

int main() {
	int a;

	// int* 	-> int pointer -> ponteiro de inteiro
	// int**  -> ponteiro de ponteiro de inteiro

	// variável 'numero'
	// &numero = endereço_de_memoria_de_numero. Ex.: int a = 9, &a = 0x1000
	// numero  = 10

	// ponteiro 'ponteiro'
	// ponteiro    = &numero
	// &ponteiro   = endereço_de_memoria_do_ponteiro
	// ponteiro 	 = endereco_de_memoria_de_numero
	// *(ponteiro) = *(endereco_de_memoria_de_numero) = 10

	// ponteiroDePonteiro 		= &ponteiro;
	// &ponteiroDePonteiro 		= endereço_de_ponteiro_do_ponteiro
	// ponteiroDePonteiro 		= &ponteiro = endereço_de_memoria_de_ponteiro
	// *(ponteiroDePonteiro)  = *(endereço_de_memoria_de_ponteiro) = endereço_de_memoria_de_numero
	// **(ponteiroDePonteiro) = **(endereço_de_memoria_de_ponteiro) = *(endereço_de_memoria_de_numero) = 10

	// Tamanhos dos tipos
  printf("sizeof(bool)	= %ld byte\n",			sizeof(bool));						//	sizeof(bool)  	= 1 byte		=> um valor lógico true ou false (bool está incluso em <stdbool.h)
  printf("sizeof(char)	= %ld byte\n", 			sizeof(char));						//	sizeof(char)  	= 1 byte		=> um caracter simples na faixa de 0 a 255
  printf("sizeof(short)	= %ld bytes\n", 		sizeof(short));						//	sizeof(short)   = 2 bytes		=> 
	printf("sizeof(a)	= %ld bytes\n", 				sizeof(a));								//	sizeof(a)       = 4 bytes		=> 
  printf("sizeof(int)	= %ld bytes\n", 			sizeof(int));							//	sizeof(int)     = 4 bytes		=> um número na faixa de -2.147.483.468 a +2.147.483.467
  printf("sizeof(float)	= %ld bytes\n", 		sizeof(float));						//	sizeof(float)   = 4 bytes		=> um número em ponto flutuante na faixa de +-3,4x10^+-38
	printf("sizeof(long)	= %ld bytes\n", 		sizeof(long));						//	sizeof(long)    = 8 bytes		=> 
  printf("sizeof(ulong)	= %ld bytes\n", 		sizeof(unsigned long));		//	sizeof(ulong)   = 8 bytes		=> 
  printf("sizeof(double)	= %ld bytes\n\n", sizeof(double));					//	sizeof(double)  = 8 bytes		=> um número em ponto flutuante na faixa de +-1,7x10^+-308

	// Tamanhos do ponteiros
  printf("sizeof(void *) 	= %ld bytes\n",	sizeof(void *));						//	sizeof(void *)  = 8 bytes		=> 
  printf("sizeof(int *) 	= %ld bytes\n",	sizeof(int *));							//	sizeof(int *)   = 8 bytes		=> 
  printf("sizeof(int **) 	= %ld bytes\n",	sizeof(int **));						//	sizeof(int **)  = 8 bytes		=> 
  printf("sizeof(int ***) = %ld bytes\n",	sizeof(int ***));						//	sizeof(int ***) = 8 bytes		=> 
  printf("sizeof(float *) = %ld bytes\n",	sizeof(float *));						//	sizeof(float *) = 8 bytes		=> 

	return 0;
}
