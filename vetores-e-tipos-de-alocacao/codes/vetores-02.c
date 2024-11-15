#include <stdio.h>

int main()
{
  int i;      // &i    = 0x7ffe36ccba4c -> i    = *(0x7ffe36ccba4c) = ###
  int v[5];   // &v[0] = 0x7ffe36ccba50 -> v[0] = *(0x7ffe36ccba50) = ###
              // &v[1] = 0x7ffe36ccba54 -> v[1] = *(0x7ffe36ccba54) = ###
              // &v[2] = 0x7ffe36ccba58 -> v[2] = *(0x7ffe36ccba58) = ###
              // &v[3] = 0x7ffe36ccba5c -> v[3] = *(0x7ffe36ccba5c) = ###
              // &v[4] = 0x7ffe36ccba60 -> v[4] = *(0x7ffe36ccba60) = ###
              // alocação de 20 bytes contíguos

  for (i = 0; i < 5; i++) {
    printf("Insira um valor para v[%d]: ", i);
    scanf("%d", &v[i]);                                       // Inputs: 13 17  19  23  29
  }                                                                   
                                                                      
  printf("\n&i    = %p,    i = %d\n", &i, i);                 // &i = 0x7ffe36ccba4c,    i = 5

  for (i = 0; i < 5; i++)                                             
    printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);   // .................................. 
                                                                      // &v[0] = 0x7ffe36ccba50, v[0] = 13
                                                                      // &v[1] = 0x7ffe36ccba54, v[1] = 17
                                                                      // &v[2] = 0x7ffe36ccba58, v[2] = 19
                                                                      // &v[3] = 0x7ffe36ccba5c, v[3] = 23
                                                                      // &v[4] = 0x7ffe36ccba60, v[4] = 29

  return 0;
}