#include <stdlib.h>

// 3) Qual o problema do trecho de código abaixo?

int main() {
  int v1[5] = {0, 1, 2, 3, 4};
  int *v2;

  v2 = (int *)malloc(5 * sizeof(int));
  v2 = v1;

  free(v2);

  return 0;
}

/*
.............................HEAP.......................................................................................................................
0x720   [  ###  ]              <=> ...
0x716   [  ###  ] -> v2[4]     <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO nesse caso, já que nenhum ponteiro está apontando para a HEAP!
0x712   [  ###  ] -> v2[3]     <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO nesse caso, já que nenhum ponteiro está apontando para a HEAP!
0x708   [  ###  ] -> v2[2]     <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO nesse caso, já que nenhum ponteiro está apontando para a HEAP!
0x704   [  ###  ] -> v2[1]     <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO nesse caso, já que nenhum ponteiro está apontando para a HEAP!
0x700   [  ###  ] -> v2[0]     <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO nesse caso, já que nenhum ponteiro está apontando para a HEAP!
.............................HEAP.......................................................................................................................
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
.............................STACK......................................................................................................................
0x528   [  ###  ]              <=> ...
0x520   [  NILL ] -> v2        <=> 'v2' inicialmente armazena lixo de memória, depois aponta para o vetor dinâmico (0x700); 
                                    depois aponta para 0x500 (é apenas copiado o endereço base do vetor estático, NÃO O VETOR);
                                    por fim é setado como NULL! (&v1 = v1 = &v1[0])
0x516   [   4   ] -> v1[4]     <=> inicialmente tem valor 4; o valor é alterado para 10, através do ponteiro 'p'
0x512   [   3   ] -> v1[3]     <=> inicialmente tem valor 3; o valor é alterado para 10, através do ponteiro 'p'
0x508   [   2   ] -> v1[2]     <=> inicialmente tem valor 2; 
0x504   [   1   ] -> v1[1]     <=> inicialmente tem valor 1; 
0x500   [   0   ] -> v1[0]     <=> inicialmente tem valor 0; 
.............................STACK......................................................................................................................
*/
