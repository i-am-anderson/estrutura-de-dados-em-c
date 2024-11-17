#include <stdlib.h>

// 2) Simule a memória, usando HEAP e STACK, para o seguinte trecho de código:

int main() {
  int v1[5] = {0, 1, 2, 3, 4};
  int *v2, *p;
  int i;

  p = v1;
  p[3] = p[4] = 10;

  v2 = (int *)malloc(5 * sizeof(int));

  for (i = 0; i < 5; i++) {
    v2[i] = v1[i];
  }

  free(v2);
  v2 = NULL;

  return 0;
}

/*
.............................HEAP.....................................................................................................................
0x720   [  ###  ]              <=> ...
0x716   [  10   ] -> v2[4]     <=> inicialmente armazena lixo de memória, depois é armazenado os valores do vetor estático (10); por fim é DESALOCADO!
0x712   [  10   ] -> v2[3]     <=> inicialmente armazena lixo de memória, depois é armazenado os valores do vetor estático (10); por fim é DESALOCADO!
0x708   [   2   ] -> v2[2]     <=> inicialmente armazena lixo de memória, depois é armazenado os valores do vetor estático (2);  por fim é DESALOCADO!
0x704   [   1   ] -> v2[1]     <=> inicialmente armazena lixo de memória, depois é armazenado os valores do vetor estático (1);  por fim é DESALOCADO!
0x700   [   0   ] -> v2[0]     <=> inicialmente armazena lixo de memória, depois é armazenado os valores do vetor estático (0);  por fim é DESALOCADO!
.............................HEAP.....................................................................................................................
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
.............................STACK....................................................................................................................
0x540   [  ###  ]              <=> ... 
0x536   [   5   ] -> i         <=> inicialmente armazena lixo de memória, depois é armazenado os incrementos de 'i' de 0 a 5
0x528   [ 0x500 ] -> p         <=> 'p' inicialmente armazena lixo de memória, depois aponta para o vetor estático (0x500)
0x520   [  NILL ] -> v2        <=> 'v2' inicialmente armazena lixo de memória, depois aponta para o vetor dinâmico (0x700); por fim é setado como NULL!
0x516   [  10   ] -> v1[4]     <=> inicialmente tem valor 4; o valor é alterado para 10, através do ponteiro 'p'
0x512   [  10   ] -> v1[3]     <=> inicialmente tem valor 3; o valor é alterado para 10, através do ponteiro 'p'
0x508   [   2   ] -> v1[2]     <=> inicialmente tem valor 2; 
0x504   [   1   ] -> v1[1]     <=> inicialmente tem valor 1; 
0x500   [   0   ] -> v1[0]     <=> inicialmente tem valor 0; 
.............................STACK....................................................................................................................
*/
