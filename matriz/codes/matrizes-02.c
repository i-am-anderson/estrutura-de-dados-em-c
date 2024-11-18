#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 3

int main() {
  //** Alocação Dinâmica (Heap) ***

  // MATRIZ DINÂMICA 2D

  int **m = NULL; // <- como são 2 dimensões (linhas + colunas), usamos ponteiros de ponteiros
                  // Boa Prática: Inicializar o ponteiros como NULL, para não apontar para lixo de memória

  m = (int **)calloc(ROW, sizeof(int *));

  for (int i = 0; i < ROW; i++)
    m[i] = (int *)calloc(COL, sizeof(int));

  /*
  Na alocação dinâmica é feita por partes, considera-se que tem um vetor de vetores ou 
  array de arrays.

          0    1    2
  m = 0 [ 0 ][ 0 ][ 0 ]   <- Aloca primeiro essa linha na memória Heap com calloc/malloc
      1 [ 0 ][ 0 ][ 0 ]   <- Aloca depois essa linha na memória Heap com calloc/malloc

  m = &m[0] <=> 'm' aponta para 'm[0]'
  m[0] e m[1] são ponteiros para inteiro
  m[0] aponta para m[0][0] em: m[0][0], m[0][1] e m[0][2]
  m[1] aponta para m[1][0] em: m[1][0], m[1][1] e m[1][2]

  |----STACK-----|  |-----------------------------------------HEAP------------------------------------------|
   0x700   0x704     0x500     0x508     0x...     0x520   0x524   0x528     0x...     0x540   0x544   0x548   <- Endereços de Memória
  [0x500]  [###]    [0x516]   [0x528]   [###]     [ 0 ]   [ 0 ]   [ 0 ]     [###]     [ 0 ]   [ 0 ]   [ 0 ]    <- Conteúdo
    m                m[0]      m[1]      ...     [0][0]  [0][1]  [0][2]      ...     [1][0]  [1][1]  [1][2]    <- Variáveis
  int**             int*       int*               int     int     int                 int     int     int      <- Tipos
                   |____CALLOC_____|     ...    |____CALLOC LOOP 1____|      ...    |____CALLOC LOOP 2____| 

  ATENÇÃO: Não há garantias de que os endereços dos vetores serão contíguos entre si!
  */
  int count = 0;

  printf("&m = %p, m = %p\n", &m, m);                                             // &m = 0x7ffdb222d7d0, m = 0x59e323c972a0  <=> PONTEIRO DE PONTEIRO DE INT

  for (int i = 0; i < ROW; i++) {
    printf("\n&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
    for (int j = 0; j < COL; j++) {
      /* m[i][j] = count;
      count++;
      ou pode ser feito assim: */
      m[i][j] = count++;

      printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]); /* ...........................................
                                                                                          &m[0] = 0x59e323c972a0, m[0] = 0x59e323c972c0 <=> PONTEIRO DE INT
                                                                                          &m[0][0] = 0x59e323c972c0, m[0][0] = 0
                                                                                          &m[0][1] = 0x59e323c972c4, m[0][1] = 1
                                                                                          &m[0][2] = 0x59e323c972c8, m[0][2] = 2

                                                                                          &m[1] = 0x59e323c972a8, m[1] = 0x59e323c972e0 <=> PONTEIRO DE INT
                                                                                          &m[1][0] = 0x59e323c972e0, m[1][0] = 3
                                                                                          &m[1][1] = 0x59e323c972e4, m[1][1] = 4
                                                                                          &m[1][2] = 0x59e323c972e8, m[1][2] = 5
      */      
    }
  }

  // Falta desalocar a Matriz Dinâmica!!!

  return 0; 
}