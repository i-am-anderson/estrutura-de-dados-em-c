#include <stdio.h>
#include <stdlib.h>

// Ex 5) Implemente e simule a memória para o que se pede abaixo:

// .................................
void deallocate_vector(double **v) {
  free(*v);
  *v = NULL;
}
// .................................
double *double_vector_allocation(int n) {
  return (double *)calloc(n, sizeof(double));
}
// .................................
void double_vector_allocation_by_ref(double **v, int n) {
  *v = (double *)calloc(n, sizeof(double));
}
// .................................
int *copy_vector_by_return(const int v[], int n) {
  int *v1 = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
    v1[i] = v[i];

  return v1;
}
// .................................
void copy_vector_by_ref(const int v1[], int **v2, int n) {
  *v2 = (int *)calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
    (*v2)[i] = v1[i];
}
// .................................
void min_max(const int v[], int n, int *min, int *max) {
  *min = v[0];
  *max = v[0];

  for (int i = 0; i < n; i++) {
    if (v[i] < *min)
      *min = v[i];
    if(v[i] > *max)
      *max = v[i];
  }
}
// .................................
int main() {
  /* 1. Crie uma função que aloque um vetor de double e o retorne; */
  double *v1;
  v1 = double_vector_allocation(5);
  for (int i = 0; i < 5; i++)
    printf("%f\n", v1[i]);
  puts(".................................");

  /* 2. Crie uma função que aloque um vetor de double retornando-o por referência; */
  double *v2;
  double_vector_allocation_by_ref(&v2, 5);
  for (int i = 0; i < 5; i++)
    printf("%f\n", v2[i]);
  puts(".................................");

  /* 3. Crie uma função que desaloque um dado vetor, “setando-o” como NULL após a desalocação’ */
  deallocate_vector(&v1);
  deallocate_vector(&v2);

  /* 4. Crie uma função que faça a cópia de um vetor: faça a versão com retorno da função e com retorno por referência; */
  int v3[5] = {1, 3, 5, 7, 11};
  int* v4;
  int* v5;
  v4 = copy_vector_by_return(v3, 5);
  for (int i = 0; i < 5; i++)
    printf("%d\n", v4[i]);
  puts(".................................");
  copy_vector_by_ref(v3, &v5, 5);
  for (int i = 0; i < 5; i++)
    printf("%d\n", v5[i]);
  puts(".................................");

  /* 5. Crie uma função que calcule o mínimo e o máximo de um vetor de inteiros e retorne os valores em duas variáveis diferentes. */
  int min, max;
  min_max(v3, 5, &min, &max);
  printf("Valor Mínimo: %d\nValor Máximo: %d\n", min, max);

  /* ... */
  free(v4);
  free(v5);
  v4 = NULL;
  v5 = NULL;

  return 0;
}
