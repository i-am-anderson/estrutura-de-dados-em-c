#include <stdio.h>
#include <stdlib.h>

/*
  => Programa com vetores estáticos:
    A) Crie uma função que recebe o ponteiro de um vetor e seu tamanho e imprima
  os elementos do vetor
    B) Crie uma função que recebe o ponteiro de um vetor via colchetes [] e seu
  tamanho e imprima os elementos do vetor
    C) Imprima os endereços de memória e
  valores do vetor na main e dentro de cada função;

  => Programa com vetores dinâmicos:
    A) Crie uma função que recebe o ponteiro de um vetor e seu tamanho e imprima
  os elementos do vetor
    B) Crie uma função que recebe o ponteiro de um vetor via
  colchetes [] e seu tamanho e imprima os elementos do vetor
    C) Imprima os
  endereços de memória e valores do vetor na main e dentro de cada função;
*/

// ...
void sum_vector_with_scalar(int v[], int n, int scalar) {
  for (int i = 0; i < n; i++)
    v[i] += scalar;
}

// 'const' para tornar 'v' somente leitura
void print_vector(const int *v, int n) {
  for (int i = 0; i < n; i++)
    printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
  puts("\n");
}

int main() {
  // Vetor Estático .................................................
  int v_stack[5] = {0, 10, 20, 30, 40};

  puts("### VETORES ESTÁTICOS\n");
  print_vector(v_stack, 5); /* .................................
                                  &v[0] = 0x7ffea4296c40, v[0] = 0
                                  &v[1] = 0x7ffea4296c44, v[1] = 10
                                  &v[2] = 0x7ffea4296c48, v[2] = 20
                                  &v[3] = 0x7ffea4296c4c, v[3] = 30
                                  &v[4] = 0x7ffea4296c50, v[4] = 40 */
  sum_vector_with_scalar(v_stack, 5, 9);
  print_vector(v_stack, 5); /* .................................
                                  &v[0] = 0x7ffea4296c40, v[0] = 9
                                  &v[1] = 0x7ffea4296c44, v[1] = 19
                                  &v[2] = 0x7ffea4296c48, v[2] = 29
                                  &v[3] = 0x7ffea4296c4c, v[3] = 39
                                  &v[4] = 0x7ffea4296c50, v[4] = 49 */


  // Vetor Dinâmico ..................................................
  puts("### VETORES DINÂMICOS\n");
  int *v_heap = (int *)calloc(5, sizeof(int));
  for (int i = 0; i < 5; i++) {
    v_heap[i] = i * 11;
  }

  print_vector(v_heap, 5); /* ..............................
                                &v[0] = 0x5886118036b0, v[0] = 0
                                &v[1] = 0x5886118036b4, v[1] = 11
                                &v[2] = 0x5886118036b8, v[2] = 22
                                &v[3] = 0x5886118036bc, v[3] = 33
                                &v[4] = 0x5886118036c0, v[4] = 44 */
  sum_vector_with_scalar(v_heap, 5, 2);
  print_vector(v_heap, 5); /* ...............................
                                &v[0] = 0x5886118036b0, v[0] = 2
                                &v[1] = 0x5886118036b4, v[1] = 13
                                &v[2] = 0x5886118036b8, v[2] = 24
                                &v[3] = 0x5886118036bc, v[3] = 35
                                &v[4] = 0x5886118036c0, v[4] = 46 */

  // Desalocar vetor dinâmico
  free(v_heap);
  v_heap = NULL;

  return 0;
}
