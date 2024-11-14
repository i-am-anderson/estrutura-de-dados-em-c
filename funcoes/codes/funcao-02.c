#include <stdio.h>

// Funções - Passagem por Referência
// É passado a referência do endereço de memória de uma variável (ponteiro) para a função, possibilitando alterar uma variável que é externa a uma função
// referência = endereço de memória = ponteiro

// Função **Soma**
int sum_and_multiply(int x, int y, int z, int *w)
{
  z = x * y;
  *w = x + y;   //                     <=> *w é um ponteiro para o endereço da variável que vai receber o valor da soma

  // &x = 0x000 -> x = 10              <=> Passagem de Parâmetro por Valor
  // &y = 0x004 -> y = 20              <=> Passagem de Parâmetro por Valor
  // &z = 0x008 -> z = 0x108           <=> Passagem de Parâmetro por Referência

  puts("==> DENTRO DA FUNÇÃO <==");
  printf("&x = %p, x = %d\n", &x, x);       // &x = 0x7fffce61e48c, x = 10
  printf("&y = %p, y = %d\n", &y, y);       // &y = 0x7fffce61e488, y = 20
  printf("&z = %p, z = %d\n", &z, z);       // &z = 0x7fffce61e484, z = 200
  printf("&w = %p, *w = %d\n\n", &w, *w);   // &w = 0x7fffce61e478, *w = 30

  return z;
}

// Função **Main**
int main()
{
                // Simulações
  int a = 10;   // &a = 0x100
  int b = 20;   // &b = 0x104
  int c;        // &c = 0x108
  int d;        // &d = 0x112

  puts("### ANTES DE CHAMAR A FUNÇÃO");
  printf("&a = %p, a = %d\n", &a, a);     // &a = 0x7fffce61e4a8, a = 10
  printf("&b = %p, b = %d\n", &b, b);     // &b = 0x7fffce61e4ac, b = 20
  printf("&c = %p, c = %d\n", &c, c);     // &c = 0x7fffce61e4b0, c = 4096
  printf("&d = %p, d = %d\n\n", &d, d);   // &d = 0x7fffce61e4b4, d = 0

  d = sum_and_multiply(a, b, c, &d);

  puts("### DEPOIS DE CHAMAR A FUNÇÃO");
  printf("&a = %p, a = %d\n", &a, a);     // &a = 0x7fffce61e4a8, a = 10
  printf("&b = %p, b = %d\n", &b, b);     // &b = 0x7fffce61e4ac, b = 20
  printf("&c = %p, c = %d\n", &c, c);     // &c = 0x7fffce61e4b0, c = 4096
  printf("&d = %p, d = %d\n\n", &d, d);   // &d = 0x7fffce61e4b4, d = 200

  return 0;
}