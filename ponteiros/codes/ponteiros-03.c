#include <stdio.h>

int main() {
	// Ponteiros de Ponteiros (p**)
	// Apontam para endereços de memórias de outros ponteiros

	// Se &p2 =	0x0002; 	*p2 = variavel;		variavel = 10; 	&variavel = 0xaaa		e 	p1** = &p2*, 	i.e.: 

	// -> 	&p1** 		= 0x001																																<=> endereço do ponteiro de ponteiro
	// -> 	p1**			=	0x002																																<=> valor da variável
	// -> 	*(p1**)		= *(p2)	  = *(0x002	)	 	=	&variavel			= 0xaaa												<=> conteúdo de um endereço
	// -> 	**(p1**)	= **(p2)	= **(0x002)  	= *(&variavel) 	= *(0xaaa)	=	variavel = 10		<=> conteúdo de um endereço

	// variavel do tipo: int
	// p2 do tipo:			 int*		<=> guarda endereço de memoria de uma variavel do tipo inteiro
	// p1 do tipo:			 int**	<=> guarda endereço de memoria de um PONTEIRO que guarda uma variavel do tipo inteiro

										//	Simulações ...................................................................................
	int a 	 = 10;		//	<-	int:			a  = 10					->		&a  = 0x5000	=>	
	int *p1  = &a;		//	<-	int*:			p1 = 0x5000			->		&p1 = 0x5004	=>	*p1 	= *(0x5000) = 10
	int **p2 = &p1;		//	<-	int**:		p2 = 0x5004			->		&p2 = 0x5012	=>	**p2	=	**(0x5004)	=	*p1	=	*(0x5000)	=	a = 10

	// => ...
	printf("&a  = %p, a  = %d\n", &a, a);																				// &a  = 0x7ffdfd61e384, a  = 10
	printf("&p1 = %p, p1 = %p, *p1 =  %d\n", &p1, p1, *p1);											// &p1 = 0x7ffdfd61e388, p1 = 0x7ffdfd61e384, *p1 =  10
	printf("&p2 = %p, p2 = %p, *p2 =  %p, **p2 = %d\n\n", &p2, p2, *p2, **p2);	// &p2 = 0x7ffdfd61e390, p2 = 0x7ffdfd61e388, *p2 =  0x7ffdfd61e384, **p2 = 10

	**p2 = 99;																																					// Altera valor da variável 'a' através de um ponteiro de ponteiro

	// => ...
  printf("&a  = %p, a  = %d\n", &a, a);																				// &a  = 0x7ffdfd61e384, a  = 99
  printf("&p1 = %p, p1 = %p, *p1 =  %d\n", &p1, p1, *p1);											// &p1 = 0x7ffdfd61e388, p1 = 0x7ffdfd61e384, *p1 =  99
  printf("&p2 = %p, p2 = %p, *p2 =  %p, **p2 = %d\n\n", &p2, p2, *p2, **p2);	// &p2 = 0x7ffdfd61e390, p2 = 0x7ffdfd61e388, *p2 =  0x7ffdfd61e384, **p2 = 99

	return 0;
}
