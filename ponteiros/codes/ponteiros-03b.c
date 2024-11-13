#include <stdio.h>

int main() {
										//	Simulações ....................................
	float z	= 2.5;		//	<-	float		z  = 2.5			->		&z  = 0x5000
	float *fp;				//	<-	float*	fp = ...			->		&fp = 0x5004

	fp = &z;					// 	fp 		= &z 					= 0x5000
										//	*&z		=	*(0x5000)									=	z			=	2.5
										//	*fp		=	*(0x5000)									= z 		= 2.5
										//	**&fp = **(0x5004) 	= *(0x5000) 	= z 		= 2.5

	// => ...
	printf("*&z   = %f\n", *&z);			// *&z 	  = 2.500000
	printf("*fp   = %f\n", *fp);			// *fp  	= 2.500000
	printf("**&fp = %f\n", **&fp);		// **&fp	 = 2.500000

	return 0;
}
