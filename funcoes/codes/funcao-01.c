#include <stdio.h>

// Funções não podem ser declaradas dentro de outras funções
// Toda função deve ter um tipo. Esse tipo determina qual será o tipo de seu valor de retorno
// Não é possível fazer sobrecarga de função

// Passagens de Parâmetros (funções)

// 1. Passagem por Valor
// int sum(int x, int y) { z = x + y; return z; }  -> são armazenadas na memória quando a função é chamada (copias de 'a' e 'b'),
//                                                    'z' é armazenado na memória na execução da função e depois copiado para 'c'
//                                                    quando termina a função, as regiões de memória de 'x', 'y' e 'z' são liberadas
// int a = 1; int b = 2; c = sum(a, b);            -> são armazenados na memória na declaração das variáveis

// 2. Passagem por Referência
// ...

// Função **Sum**
int sum(int x, int y) {
  int z = x + y;

  puts("==> DENTRO DA FUNCAO <==");
  printf("&x = %p, x = %d\n", &x, x);
  printf("&y = %p, y = %d\n", &y, y);
  printf("&z = %p, z = %d\n\n", &z, z);

  // Uma função em C, retorna apenas um valor
  return z;
}

// Função **Hello**
void hello() {
    puts("Hello World!");
}

// Função **Main**
int main() {
  int a = 10;
  int b = 20;
  int c;

  puts("### ANTES DE CHAMAR A FUNCAO");
  printf("&a = %p, a = %d\n", &a, a);
  printf("&b = %p, b = %d\n", &b, b);
  printf("&c = %p, c = %d\n\n", &c, c);

  c = sum(a, b);

  puts("### DEPOIS DE CHAMAR A FUNCAO");
  printf("&a = %p, a = %d\n", &a, a);
  printf("&b = %p, b = %d\n", &b, b);
  printf("&c = %p, c = %d\n\n", &c, c);

  return 0;
}
