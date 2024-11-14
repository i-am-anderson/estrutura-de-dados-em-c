#include <stdio.h>

// 1) Escreva os valores das variáveis para cada instrução
// do programa abaixo. Qual a saída do programa?

int main(int argc, char *argv[]) {
	int a, b, *p1, *p2;
	// &a  = 0x5000
	// &b  = 0x5004
	// &p1 = 0x5008
	// &p2 = 0x5016

	//							Simulações	.............................................................................................
	a = 4;					// a = 4
	b = 3;					// b = 3
	p1 = &a;				// p1 = &a					-> p1  = 0x5000
	p2 = p1;				// p2 = p1					-> p2  = 0x5000
	*p2 = *p1 + 3;	// *p2 = *p1 + 3		-> *p2 = *(0x5000) + 3		-> *p2 = 4 + 3													<=> *p2 = a = 7
	b = b * (*p1);	// b = b * (*p1)		-> b   = 3 * (*0x5000)		-> b   = 3 * 7				 									<=> b   		= 21
	(*p2)++;				// (*p2)++					-> (*0x5000)++						-> *p2 = 7++					 									<=> *p2 = a = 8
	p1 = &b;				// p1 = &b																																						<=> p1  		= 0x5004

	printf("%d 	%d\n", *p1, *p2); 		// *p1 = &b  = *(0x5004)	= 21;		*p2 = &a = *(0x5000) = 8	 <=> 21		8 
	printf("%d 	%d\n", a, b);		 			// a 	 = *p2 = 8;		b = 21																	 <=> 8		21

	return 0;
}

// Teste de Mesa ...........................|
// 		a 	-> 	0x5000												|
// 		b 	-> 	0x5004												|
// 		p1  -> 	0x5008												|
// 		p2	->	0x5016 												|
//		......................................|
//		a		b		  p1		 *p1		  p2		 *p2  |
//		#		#		  #				-			  #				-   |
//		4		#		  #				-			  #				-   |
//		4		3		  #				-			  #				-   |
//		4		3		0x5000		4			  #				-   |
//		4		3		0x5000		4			0x5000		4   |
//		7		3		0x5000		7			0x5000		7   |
//		7		21	0x5000		7			0x5000		7   |
//		8		21	0x5000		8			0x5000		8   |
//		8		21	0x5004		21		0x5000		8   |
//		......................................|