#include <stdlib.h>

/*
Para medir o tempo, no BASH usamos: time ./build/matrizes-07b
*/

// ## CREATE INT MATRIZ
int **create_int_matrix(int rows, int cols) {
  int **m = (int **)calloc(rows, sizeof(int *));

  for (int i = 0; i < rows; i++) {
    m[i] = (int *)calloc(cols, sizeof(int));
  }

  return m;
}

// ## MAIN
int main() {
  /*
  COLUMN MAJOR (é mais lento)
  */
  int rows = 100000;
  int cols = 10000;
  int **m = create_int_matrix(rows, cols);

  // ./build/matrizes-07b  10.72s user 1.67s system 99% cpu 12.397 total
  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
      m[i][j] = (i + j) % 2;
    }
  }

  // Não estamos desalocando a memória

  return 0;
}