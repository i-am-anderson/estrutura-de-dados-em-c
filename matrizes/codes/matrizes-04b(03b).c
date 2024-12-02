#include <stdio.h>
#include <stdlib.h>

#define DEP 2
#define ROW 2
#define COL 3

int main() {
  /* MATRIZ DINÂMICA 3D */

  // DO CÓDIGO 'matrizes-03b.c'

  /* **************** ALOCAÇÃO DINÂMICA ******************* */
  /* ****************************************************** */

  int ***m = (int ***)calloc(DEP, sizeof(int **));

  // FATIAS
  for (int k = 0; k < DEP; k++) {
    m[k] = (int **)calloc(ROW, sizeof(int *));

    // COLUNAS
    for (int i = 0; i < ROW; i++) {
      m[k][i] = (int *)calloc(COL, sizeof(int));
    }
  }

  /* ****************************************************** */
  /* ****************************************************** */

  int count = 0;

  printf("&m = %p, m = %p\n\n", &m, m);

  for (int k = 0; k < DEP; k++) {
    printf("&m[%d] = %p, m[%d] = %p\n", k, &m[k], k, m[k]);

    for (int i = 0; i < ROW; i++) {
      printf("&m[%d][%d] = %p, m[%d][%d] = %p\n", k, i, &m[k][i], k, i,
             m[k][i]);

      for (int j = 0; j < COL; j++) {
        m[k][i][j] = count++;

        printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k, i, j,
               &m[k][i][j], k, i, j, m[k][i][j]);
      }

      puts("");
    }

    puts("");
  }

  /* ********* DESALOCAÇÃO DA MATRIZ DINÂMICA 3D ********** */
  /* ****************************************************** */

  /*
  A desalocação é feita no caminho inverso (1º: p*, 2º: p**, 3º: p***, ...) para
  não ser perdidas as referências dos ponteiros
  */

  for (int k = 0; k < DEP; k++) {
    for (int i = 0; i < ROW; i++) {
      // Desalocação de 'm[0][0]', 'm[0][1]', 'm[1][0]', 'm[1][1]' => p*
      free(m[k][i]);
    }

    // Desalocação de 'm[0]' e 'm[1]' => p**
    free(m[k]);
  }

  // Desalocação de 'm' => p***
  free(m);
  m = NULL;

  /* ****************************************************** */
  /* ****************************************************** */

  return 0;
}
