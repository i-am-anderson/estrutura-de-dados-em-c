#include <stdio.h>

int main()
{
	int v[5] = {0xa01, 0xb23, 0xc45, 0xd67, 0xe89};							// Hexadecimal.....Decimal
	// &v[0] = 0x7ffe5dc3f2a0		= 	(v+0)		-> 	*(v+0)	=		*(0x7ffe5dc3f2a0)	=	v[0] = 0xa01 ......... (2561)
	// &v[1] = 0x7ffe5dc3f2a4		= 	(v+1)		-> 	*(v+1)	=		*(0x7ffe5dc3f2a4)	=	v[1] = 0xb23 ......... (2851)
	// &v[2] = 0x7ffe5dc3f2a8		= 	(v+2)		-> 	*(v+2)	=		*(0x7ffe5dc3f2a8)	=	v[2] = 0xc45 ......... (3141)
	// &v[3] = 0x7ffe5dc3f2ac		= 	(v+3)		-> 	*(v+3)	=		*(0x7ffe5dc3f2ac)	=	v[3] = 0xd67 ......... (3431)
	// &v[4] = 0x7ffe5dc3f2b0		= 	(v+4)		-> 	*(v+4)	=		*(0x7ffe5dc3f2b0)	=	v[4] = 0xe89 ......... (3721)

	// para int v: (v + 3), significa que está deslocando 3 endereços de 'int' a partir do endereço base de 'v' (v[0])

	// &v = v = &v[0] -> 'v' sem indexação aponta para o primeiro elemento do vetor,
	// o 'v' representa o endereço inicial do vetor 			<=>				 &v = v = &v[0]

	printf("&v 	= %p\n", &v);					//&v     = 0x7ffe5dc3f2a0
	printf("v  	= %p\n", v);					// v     = 0x7ffe5dc3f2a0
	printf("&v[0]	= %p\n\n", &v[0]);	// &v[0] = 0x7ffe5dc3f2a0

	// Vetores e Aritmética de Ponteiros
	// Como v = v[0], então:
	// *(v + 2) = *(v[0] + 2) = *(v[2]) = 0xc45
	for (int i = 0; i < 5; i++)
		printf("(v+%d) = &v[%d] = %p,	*(v+%d) = v[%d] = %d\n", i, i, v + i, i, i, *(v + i));	 // ....................................................
																																																	// (v+0) = &v[0] = 0x7ffe5dc3f2a0, *(v+0) = v[0] = 2561   
																																																	// (v+1) = &v[1] = 0x7ffe5dc3f2a4, *(v+1) = v[1] = 2851    
																																																	// (v+2) = &v[2] = 0x7ffe5dc3f2a8, *(v+2) = v[2] = 3141 
																																																	// (v+3) = &v[3] = 0x7ffe5dc3f2ac, *(v+3) = v[3] = 3431
																																																	// (v+4) = &v[4] = 0x7ffe5dc3f2b0, *(v+4) = v[4] = 3721

	return 0;
}
