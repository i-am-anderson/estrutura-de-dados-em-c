#include <stdlib.h>

// 1) Simule a memória, usando HEAP e STACK, para o seguinte trecho de código:

int main() {
  int i, n = 5;
  int *v;
  
  v = (int *)malloc(n * sizeof(int));

  for (i = 0; i < 5; i++) {
    v[i] = i;
  }

  return 0;
}

/*
.............................HEAP.................................................................................
0x720   [  ###  ]             <=> ...
0x716   [   4   ] -> v[4]     <=> inicialmente armazena lixo de memória, depois é armazenado os incrementos de 'i'  
0x712   [   3   ] -> v[3]     <=> inicialmente armazena lixo de memória, depois é armazenado os incrementos de 'i'  
0x708   [   2   ] -> v[2]     <=> inicialmente armazena lixo de memória, depois é armazenado os incrementos de 'i'  
0x704   [   1   ] -> v[1]     <=> inicialmente armazena lixo de memória, depois é armazenado os incrementos de 'i'  
0x700   [   0   ] -> v[0]     <=> inicialmente armazena lixo de memória, depois é armazenado os incrementos de 'i'  
.............................HEAP.................................................................................
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
.............................STACK................................................................................
0x516   [  ###  ]             <=> ...
0x508   [ 0x700 ] -> v        <=> 'v' inicialmente armazena lixo de memória, depois aponta para o vetor dinâmico  
0x504   [   5   ] -> n        <=> ...
0x500   [   5   ] -> i        <=> 'i' inicialmente armazena lixo de memória, depois varia de 0 até 5
.............................STACK................................................................................
*/
