#include <stdio.h>
#include <stdlib.h> // contém o NULL, CALLOC, MALLOC e FREE

int main() {
	// sizeof(stack) << sizeof(heap): a quantidade de memória Stack disponível é muito menor do
	// que a quantidade de memória Heap disponível

	// A. Alocação Estática:
	// • O espaço para as variáveis é reservado no início da execução;
	// • Cada variável tem seu endereço fixado e a área de memória ocupada por ela se mantém constante durante toda a execução;
	// • São alocadas na Stack da Memória Ram;
	// • Liberação de memória feita automaticamente pelo Sistema Operacional.

	// Toda a VARIÁVEL é alocada na memória STACK: 	int a, float b, char c, int a[10], float *p;

	// Alocação de um valor estático ( memória STACK)
	int v_stack[5] = {0, 10, 20, 30, 40};

	puts("### VETORES ESTÁTICOS");
	printf("&v_stack = %p, v_stack = %p\n\n", &v_stack, v_stack);	// &v_stack = 0x7ffe698c63f0, v_stack = 0x7ffe698c63f0

	for(int i = 0; i < 5; i++) {
		printf("&v_stack[%d] = %p, v_stack[%d] = %d\n", i, &v_stack[i], i, v_stack[i]);	 // .............................................
																																														// &v_stack[0] = 0x7ffe698c63f0, v_stack[0] = 0
																																														// &v_stack[1] = 0x7ffe698c63f4, v_stack[1] = 10
																																														// &v_stack[2] = 0x7ffe698c63f8, v_stack[2] = 20
																																														// &v_stack[3] = 0x7ffe698c63fc, v_stack[3] = 30
																																														// &v_stack[4] = 0x7ffe698c6400, v_stack[4] = 40
	}
	puts("\n");

	// B. Alocação Dinâmica:
	// • O espaço é alocado dinamicamente durante a execução do programa;
	// • Pode ser criada ou eliminada durante a execução do programa, ocupando espaço na memória apenas enquanto está sendo utilizada.
	// • São alocadas na Heap (também conhecida como FREE STORE) da Memória Ram;
	// • Liberação de memória feita manualmente pelo programador (PERIGO!) ou AUTOMATICAMENTE no fim do programa;

	// Alocação de Memória:
	// tipo *v = (tipo*) malloc(N * sizeof(tipo)) -> N é a quantidade do tipo de memória a ser alocada, ex.: N=5 e tipo = 'int' serão
	// alocados 5 x int ou 5 x 4 bytes, alocação e 20 bytes; o PONTEIRO 'v' é alocado na STACK, a região da memória que ele aponta é
	// alocada na HEAP (ou seja aponta para um bloco de memória na HEAP)

	// MALLOC -> Aloca um bloco de bytes consecutivos na memória heap e devolve o endereço base desse bloco.
	// Memory Allocation			->	int *a   = (int *) malloc(10 * sizeof(int));

	// CALLOC -> Aloca um bloco de bytes consecutivos na memória heap e inicializa todos os valores com 0 (NULL para ponteiros).
	// Contiguous Allocation	->	float *b = (float *) calloc(5, sizeof(float));
	
	// Liberação da Memória:
	// free(a);
	// free(b);

	// • A alocação dinâmica é o processo que aloca memória em tempo de execução.
	// • Ela é utilizada quando não se sabe ao certo quanto de memória será necessário para o armazenamento dos elementos;
	// • Assim, o tamanho de memória necessário é determinado conforme necessidade;
	// • Dessa forma evita-se o desperdício de memória;

	// Alocação de um vetor dinâmico usando MALLOC (memória HEAP)
	int *v_heap_malloc = (int *) malloc(5 * sizeof(int));	// todos os elementos possuem lixo de memória
	
	puts("### VETOR DINAMICO COM MALLOC");
	
	printf("&v_heap_malloc = %p, v_heap_malloc = %p\n\n", &v_heap_malloc, v_heap_malloc);		// &v_heap_malloc = 0x7ffe698c63e0, v_heap_malloc = 0x6405216f96b0

	for(int i = 0; i < 5; i++) {
		printf("&v_heap_malloc[%d] = %p, v_heap_malloc[%d] = %d\n", i, &v_heap_malloc[i], i, v_heap_malloc[i]);	// ................................................
																																																						// &v_heap_malloc[0] = 0x6405216f96b0, v_heap_malloc[0] = 0
																																																						// &v_heap_malloc[1] = 0x6405216f96b4, v_heap_malloc[1] = 0
																																																						// &v_heap_malloc[2] = 0x6405216f96b8, v_heap_malloc[2] = 0
																																																						// &v_heap_malloc[3] = 0x6405216f96bc, v_heap_malloc[3] = 0
																																																						// &v_heap_malloc[4] = 0x6405216f96c0, v_heap_malloc[4] = 0
	}
	puts("\n");


	// Alocação de um vetor dinâmico usando calloc (memória HEAP)
	int *v_heap_calloc = (int *) calloc(5, sizeof(int));	// todos os elementos são zerados
	
	puts("### VETOR DINAMICO COM CALLOC");
	
	printf("&v_heap_calloc = %p, v_heap_calloc = %p\n\n", &v_heap_calloc, v_heap_calloc);	// &v_heap_calloc = 0x7ffe698c63e8, v_heap_calloc = 0x6405216f96d0

	for(int i = 0; i < 5; i++) {
		printf("&v_heap_calloc[%d] = %p, v_heap_calloc[%d] = %d\n", i, &v_heap_calloc[i], i, v_heap_calloc[i]);	// ...............................................
																																																					// &v_heap_calloc[0] = 0x6405216f96d0, v_heap_calloc[0] = 0
																																																					// &v_heap_calloc[1] = 0x6405216f96d4, v_heap_calloc[1] = 0
																																																					// &v_heap_calloc[2] = 0x6405216f96d8, v_heap_calloc[2] = 0
																																																					// &v_heap_calloc[3] = 0x6405216f96dc, v_heap_calloc[3] = 0
																																																					// &v_heap_calloc[4] = 0x6405216f96e0, v_heap_calloc[4] = 0
	}
	puts("\n");

	// Não estamos desalocando os vetores dinâmicos (free)

	return 0;
}
