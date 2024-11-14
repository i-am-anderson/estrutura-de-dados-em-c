#include <stdio.h>

// Mostre todos os passos (teste de mesa) do programa abaixo e identifique o que é impresso pelo programa.

void func(int *px, int *py)
{
  // Vamos considerar as estradas x = 10 e y = 20
  // &px = 0x000, &py = 0x008
  // px  = 0x500, py  = 0x504

  //                    Simulações..............................................................................
  px = py;              // py  = 0x504   logo    px = 0x504   <- Os dois ponteiro sapontam para o mesmo endereço
  *py = (*py) * (*px);  // *py = *(0x504) x *(0x504) => *py = (20) * (20) => *py = y = 400
  *px = *px + 2;        // *px = *(0x504) + 2        => *px = (400) + 2    => *px = x = 402

  // Assim:
  // '*px' alterou valor de 'x' para 10
  // '*py' alterou valor de 'y' para 402

  puts("==> DENTRO DA FUNÇÃO <==");
  printf("&px   = %p, *px  = %d\n",   &px, *px);    // &px   = 0x7ffefea89838, *px  = 402
  printf("&py   = %p, *py  = %d\n\n", &py, *py);    // &py   = 0x7ffefea89830, *py  = 402
}

int main()
{
  int x, y;
  // &x = 0x500
  // &y = 0x504

  // Inputs
  // poderia ser: scanf("%d %d", &x, &y)
  scanf("%d", &x);  // Entrada 1
  scanf("%d", &y);  // Entrada 2

  func(&x, &y);

  puts("### FORA DA FUNÇÃO");
  printf("&x = %p, x = %d\n", &x, x);     // &x = 0x7ffefea89850, x = 10
  printf("&y = %p, y = %d\n\n", &y, y);   // &y = 0x7ffefea89854, y = 402

  return 0;
}

// Teste de Mesa .............................|
// 		x 	-> 	0x500	  										  	|
// 		y 	-> 	0x504 											  	|
// 		px  -> 	0x000										  	  	|
// 		py	->	0x008 											  	|
//		........................................|
//		x		y		    px		 *px		  py		 *py  |
//		#		#		    #				-			  #				-   |
//		10	20	  	#			  -			  #			  -   |
//		10	20	  0x500		 10  	  0x504		 20   |
//		10	20	  0x504		 20  	  0x504		 20   |
//		10	400 	0x504		 400 	  0x504		 400  |
//		10	402 	0x504		 402  	0x504		 402  |
//		........................................|