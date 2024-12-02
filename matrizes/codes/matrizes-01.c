#include <stdio.h>

// A maneira mais comum é definir as dimensões do array como constantes ou
// macros, para que o compilador saiba o tamanho do array em tempo de
// compilação. Variáveis não funciona!
#define ROW 2
#define COL 3

int main() {
  //** Alocação Estática (Stack) ***
  int m[ROW][COL] = {{4, 5, 6}, {7, 8, 9}}; // <- Linhas e Colunas

  printf("&m = %p, m = %p\n\n", &m, m);                                           // &m = 0x7ffe84701c90, m = 0x7ffe84701c90

  for (int i = 0; i < ROW; i++)
    for (int j = 0; j < COL; j++)
      printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j, m[i][j]); /*...............................
                                                                                          &m[0][0] = 0x7ffe84701c90, m[0][0] = 4
                                                                                          &m[0][1] = 0x7ffe84701c94, m[0][1] = 5
                                                                                          &m[0][2] = 0x7ffe84701c98, m[0][2] = 6
                                                                                          &m[1][0] = 0x7ffe84701c9c, m[1][0] = 7
                                                                                          &m[1][1] = 0x7ffe84701ca0, m[1][1] = 8
                                                                                          &m[1][2] = 0x7ffe84701ca4, m[1][2] = 9

          0    1    2
  m = 0 [ 4 ][ 5 ][ 6 ]
      1 [ 7 ][ 8 ][ 9 ]

  &m = m = 0x000

    0x000   0x004   0x008   0x012   0x016   0x020
   [ 4 ]   [ 5 ]   [ 6 ]   [ 7 ]   [ 8 ]   [ 9 ]
  [0][0]  [0][1]  [0][2]  [1][0]  [1][1]  [1][2]
  */
  return 0;
}