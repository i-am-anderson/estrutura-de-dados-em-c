#include <stdio.h>

// Funções com parâmetros por referência
void change(int *x, int *y)
{
  // &x   = 0x000   ->  x = &a  ->  x = 0x100   ->  *x = a = 10
  // &y   = 0x008   ->  y = &b  ->  y = 0x104   ->  *y = b = 20
  // &aux = 0x016   ->  aux = *x = 10

  //              Simulações.....................
  int aux = *x;   //  aux = 10
  *x = *y;        //  *x = a = 20   <- (b = 20)     <=> Alterou a variável 'a' para 20
  *y = aux;       //  *y = b = 10   <- (aux = 10)   <=> Alterou a variável 'b' para 10

  puts("==> DENTRO DA FUNÇÃO");
  printf("&x   = %p, *x  = %d\n", &x, *x);        // &x   = 0x7ffc34bdce78, *x  = 20
  printf("&y   = %p, *y  = %d\n", &y, *y);        // &y   = 0x7ffc34bdce70, *y  = 10
  printf("&aux = %p, aux = %d\n\n", &aux, aux);   // &aux = 0x7ffc34bdce84, aux = 10
}

int main()
{
  int a = 10; // &a = 0x100
  int b = 20; // &b = 0x104

  change(&a, &b);

  puts("### FORA DA FUNÇÃO");
  printf("&a   = %p, a  = %d\n", &a, a);    // &a   = 0x7ffc34bdcea0, a  = 20
  printf("&b   = %p, b  = %d\n", &b, b);    // &b   = 0x7ffc34bdcea4, b  = 10

  return 0;
}