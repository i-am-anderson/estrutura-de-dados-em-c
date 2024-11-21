#include <stdio.h>
#include <stdlib.h>

/*
Codifique uma função para:
1 - Alocar uma matriz dinâmica
2 - Imprimir os elementos de uma matriz e seus endereços de memória
3 - Adicionar um escalar a uma matriz (in place)
4 - Desalocar uma matriz, atribuindo valor NULL ao ponteiro
*/

// 1
int **create_int_matrix(int rows, int cols) {
  int **m = (int **)calloc(rows, sizeof(int *));

  for (int i = 0; i < rows; i++) {
    m[i] = (int *)calloc(cols, sizeof(int));
  }

  return m;
}

// 2
void print_int_matrix(const int **m, int rows, int cols) {
  printf("&m = %p, m = %p\n", &m, m);

  for (int i = 0; i < rows; i++) {
    printf("\n&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
    for (int j = 0; j < cols; j++) {

      printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", i, j, &m[i][j], i, j,
             m[i][j]);
    }
  }
}

// 3
void add_scalar_into_matrix(int **m, int rows, int cols, int scalar) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m[i][j] += scalar;
    }
  }
}

// 4
void destroy_into_matrix(int ***m, int rows) {
  int **aux = *m;

  for (int i = 0; i < rows; i++)
    free(aux[i]);

  free(aux);
  *m = NULL;
}

// Main
int main(int argc, char *argv[]) {
  /* ******************* VERIFICAÇÃO ********************** */
  /* ****************************************************** */
  if (argc != 4) {
    // Verificação se o número de argumentos passados está correta
    // ./build/matrizes-05 5 7 3
    printf("ERROR\n%s rows cols scalar\n", argv[0]);
    exit(-1);
  }

  /* ********************** DEBUG ************************* */
  /* ****************************************************** */
  printf("argc = %d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
  puts("");

  /* **************** ALOCAÇÃO DINÂMICA ******************* */
  /* ****************************************************** */
  int rows = atoi(argv[1]); // Converte uma string para um integer
  int cols = atoi(argv[2]); // Converte uma string para um integer
  int **m = create_int_matrix(rows, cols);

  /* ******** ATRIBUIÇÃO DE VALORES À MATRIZ ************** */
  /* ****************************************************** */
  int count = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
      m[i][j] = count++;

  /* ********************** IMPRIME *********************** */
  /* ****************************************************** */
  puts("..........................................");
  print_int_matrix((const int **)m, rows, cols);

  /* ***************** ADICIONA ESCALAR ******************* */
  /* ****************************************************** */
  int scalar = atoi(argv[3]); // Converte uma string para um integer
  add_scalar_into_matrix(m, rows, cols, scalar);

  /* ********************** IMPRIME *********************** */
  /* ****************************************************** */
  puts("..........................................");
  print_int_matrix((const int **)m, rows, cols);

  /* ********* DESALOCAÇÃO DA MATRIZ DINÂMICA 3D ********** */
  /* ****************************************************** */
  destroy_into_matrix(&m, rows);
  puts("..........................................");
  printf("&m = %p, m = %p\n", &m, m);

  return 0;
}