#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 3

int main() {
  //** Alocação Dinâmica (Heap) ***

  // DO CÓDIGO 'matrizes-02.c'

  // MATRIZ DINÂMICA 2D

  int **m = NULL;

  m = (int **)calloc(ROW, sizeof(int *));

  for (int i = 0; i < ROW; i++)
    m[i] = (int *)calloc(COL, sizeof(int));

  int count = 0;

  printf("&m = %p, m = %p\n", &m, m);

  for (int i = 0; i < ROW; i++) {
    printf("\n&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
    for (int j = 0; j < COL; j++) {
      /* m[i][j] = count;
      count++;
      ou pode ser feito assim: */
      m[i][j] = count++;

      printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j,
             m[i][j]);
    }
  }

  /* ******** DESALOCAÇÃO DA MATRIZ DINÂMICA 2D *********** */
  /* ****************************************************** */

  /*
  A desalocação é feita no caminho inverso (1º: p*, 2º: p**, 3º: p***, ...) para
  não ser perdidas as referências dos ponteiros
  */

  // Desalocação do 'm[0]' e 'm[1]' => p*
  for (int i = 0; i < ROW; i++)
    free(m[i]);

  // Desalocação do 'm' => p**
  free(m);
  m = NULL;

  /* ****************************************************** */
  /* ****************************************************** */

  return 0;
}