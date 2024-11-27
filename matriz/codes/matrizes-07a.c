#include <stdlib.h>

/*
Para medir o tempo, no BASH usamos: time ./build/matrizes-07a
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
  ROW MAJOR
  */
  int rows = 100000;
  int cols = 10000;
  int **m = create_int_matrix(rows, cols);

  // ./build/matrizes-07a  2.37s user 1.61s system 99% cpu 3.990 total
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m[i][j] = (i + j) % 2;
    }
  }

  // Não estamos desalocando a memória

  return 0;
}