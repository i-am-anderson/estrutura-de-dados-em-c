#include <stdlib.h>

/*
Para medir o tempo, no BASH usamos: time ./build/matrizes-07c
*/

// ## MAIN
int main() {
  /*
  ### Alocação dinâmica normal

  m = (int **)calloc(row, sizeof(int *));
  for (int i = 0; i < row; i++)
    m[i] = (int *)calloc(col, sizeof(int));

  |-----------STACK----------|  |-----------------------------------------HEAP-----------------------------------------|
  0x00000   0x00004   0x00008   0x05012   0x05016   0x05020   0x#####   0x#####   0x#####   0x05200   0x05204   0x05208   <=>   Endereços de Memória
  [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   <=>   Conteúdo
    *         *         *       m[0][0]   m[0][1]   m[0][2]   (trash)   (trash)   (trash)   m[1][0]   m[1][1]   m[1][2]   <=>   Variáveis
                                |--------LINHA 1----------|                                 |---------LINHA 2----------| 

  :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  ### Alocação dinâmica com elementos contíguos (Vetor como Matriz)
  * Serializar para não ter buracos na memória entre os elementos
  * Não é possível acessar os elementos pelos índices linha e coluna [i][j]

  int *m = (int*) calloc(rows * cols, sizeof(int));

  |-----------STACK----------|  |--------------------------HEAP--------------------------|
  0x00000   0x00004   0x00008   0x05012   0x05016   0x05020   0x05100   0x05104   0x05108   <=>   Endereços de Memória
  [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   <=>   Conteúdo
    *         *         *       m[0]      m[1]      m[2]      m[3]      m[4]      m[5]      <=>   Variáveis
                                |--------LINHA 1----------|  |---------LINHA 2----------| 

  #### Como acessar [i][j]?

  para matriz[2][3]...

  |-----------STACK----------|  |--------------------------HEAP--------------------------|
  0x00000   0x00004   0x00008   0x05012   0x05016   0x05020   0x05100   0x05104   0x05108   <=>   Endereços de Memória
  [ ### ]   [ ### ]   [ ### ]   [  0  ]   [  1  ]   [  2  ]   [  3  ]   [  4  ]   [  5  ]   <=>   Conteúdo
    *         *         *       m[0]      m[1]      m[2]      m[3]      m[4]      m[5]      <=>   Variáveis
                                |--------LINHA 1----------|  |---------LINHA 2----------| 

  ---                   ---         ---            ---
  | (0,0)   (0,1)   (0,2) |         | 0     1      2 |
  | (1,0)   (1,1)   (1,2) |   ===   | 3     4      5 |
  ---                   ---         ---            ---

  ...para acessar o elemento "[1][2]" === "5", nesse caso: 
      (i * cols) + j    =>  (1 * 3) + 2   =>  5 ou m[5]
      portanto "m[1][2]" === m[5]

      ROW MAJOR COMO VETOR:
  */
  int rows = 100000;
  int cols = 10000;
  int elements = rows * cols;

  int *m = (int *) calloc(elements, sizeof(int));

  // ./build/matrizes-07c  2.36s user 1.49s system 99% cpu 3.858 total
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int p = (i * cols) + j; 
      m[p] = (i + j) % 2;
    }
  }

  return 0;
}