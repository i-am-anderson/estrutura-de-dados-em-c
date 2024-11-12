#include <stdio.h>
#include <stdlib.h>

int main()
{
  // ponteiro é um tipo de dados
  // ponteiro nada mais é do que uma variável que guarda o endereço de memória de uma outra variável (ou referencias de memória)
  // todo ponteiro (i.e., endereços de memória) ocupam 8 bytes de memória RAM
  // um ponteiro também tem endereço
  int a   = 10;   // Inteiro <=> 4 bytes
  int *p1 = NULL; // ponteiro de inteiro, esse ponteiro não aponta para lugar algum (é uma boa prática alocar ponteiro, no caso NULL), para não deixar lixo de memória interferir)
  int *p2;        // ponteiro de inteiro, esse ponteiro não aponta para lugar algum, nesse caso pode haver lixo de memória sendo apontado pelo ponteiro

  // a constante NULL está definida na <stdlib.h> e seu valor é ZERO na maioria dos SO's

  // %p imprime o endereço de memória do
  // %d imprime o dígito inteiro
  
  printf("&a  = %p, a  = %d\n",   &a,  a);    // &a  = 0x7ffd9a243cd4, a  = 10,    endereço da memória da variável e valor da variável
  printf("&p1 = %p, p1 = %p\n",   &p1, p1);   // &p1 = 0x7ffd9a243cd8, p1 = (nil),  endereço de memória do ponteiro e para qual endereço aponta (lugar algum)
  printf("&p2 = %p, p2 = %p\n\n", &p2, p2);   // &p2 = 0x7ffd9a243ce0, p2 = 0x1000, endereço de memória do ponteiro e para qual endereço aponta (lixo de memória)

  p1  = &a; // p1 (int*) <=> &a (int*),   se endereço de a ou &a = 0x5000, então p1 = 0x5000
  p2  = p1; // p2 (int*) <=> p1 (int*),   se endereço apontado pelo ponteiro p1 = 0x5000, então p2 = 0x5000
  *p2 = 4;  // *p2 (int) <=> 4 (int),     se o endereço apontado pelo ponteiro p2 = 0x5000, então o conteúdo do endereço *p2 = (0x5000) = 4 (alteração da variável)

  // *(ponteiro) = *(endereco_var) = var => o conteúdo do ponteiro é igual
  // o conteúdo do endereço de uma variável, que é o valor da variável

  // &p: endereço de memória do ponteiro
  // p: conteúdo de p ou endereço de memória da variável
  // *p: conteúdo do endereço que está sendo apontado ou a própria variável
  
  printf("&a  = %p,  a  = %d\n", &a, a);                     // &a  = 0x7ffd9a243cd4, a  = 4
  printf("&p1 = %p,  p1 = %p,  *p1 = %d\n", &p1, p1, *p1);   // &p1 = 0x7ffd9a243cd8, p1 = 0x7ffd9a243cd4,  *p1 = 4
  printf("&p2 = %p,  p2 = %p , *p2 = %d\n", &p2, p2, *p2);   // &p2 = 0x7ffd9a243ce0, p2 = 0x7ffd9a243cd4 , *p2 = 4

  // p1 = int*; &p1 = int** -> ponteiro e ponteiro de ponteiro

  return 0;
}
