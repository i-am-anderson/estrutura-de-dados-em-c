#include <stdlib.h>

// 3) Qual o problema do trecho de código abaixo?

// CUIDADO COM A EXECUÇÃO DESSE PROGRAMA: PODE CRASHAR!
int main() {
  int i;
  char* v;

  for (i = 0; i < 9999999; i++) 
    v = (char *) malloc(5000 * sizeof(char));
  
  return 0;
}

/*
PROBLEMA: Vai gerar 9999999 vetores de 5000 posições de 1byte, gerando quase 50gGb de memória alocada na HEAP, causando estouro de memória!!!
          Ainda teriam 9999998 vetores sem referência, já que no loop, o 'v' está sendo referência da última iteração,
          só sendo desalocados essas regiões de memória no final do programa!!! ***VAZAMENTO DE MEMÓRIA***
.............................HEAP..........................................................
0xnnn   [  ###  ] -> v[nnn]     <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO!
0x...   [  ###  ] -> v[...]     <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO!
0x001   [  ###  ] -> v[0]       <=> inicialmente armazena lixo de memória;  NÃO DESALOCADO!
.............................HEAP..........................................................
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
.............................STACK.........................................................
0x512   [  ###    ]              <=> ...
0x504   [  0xnnn  ] -> v         <=> inicialmente armazena lixo de memória;
0x500   [ 9999999 ] -> i         <=> inicialmente armazena lixo de memória;
.............................STACK.........................................................
*/
