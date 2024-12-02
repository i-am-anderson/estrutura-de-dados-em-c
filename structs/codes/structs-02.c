#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  /*
    Struct: Alocação Estática e Alocação Dinâmica

    1. Alocação Estática

    typedef struct _student {
      char name[100];
      int age;
    } Student;

    Student ted;
    strcpy(ted.name, "Ted");
    ted.age = 15;


    |--------------------------STACK-------------------------|  |-----------HEAP-----------|
    0x00000   0x00001   0x00002   0x00003   0x.....   0x00100   0x05100   0x05104   0x05108   <=>   Endereços de Memória
    [ 'T' ]   [ 'e' ]   [ 'd' ]   [ '\0']   [ ### ]   [  15 ]   [ ### ]   [ ### ]   [ ### ]   <=>   Conteúdo
    .name      ....      ....      ....        -       .age        -         -         -      <=>   Variáveis


    ted (104 bytes):                                                         0x000   0x001   0x002   0x003
      .name => tem disponível do endereço 0x00000 ao 0x00099 (100 bytes)  => ['T']   ['e']   ['d']  ['\0']  => '\0' é como uma flag que marca o final da String
      .age  => atributo (4 bytes)                                         => [ 15 ]
                                                                             0x100
  */

  typedef struct _student {
    char name[100];
    int age;
  } Student;

  // Atribuição assim... (1)
  Student ted;
  strcpy(ted.name, "Ted");
  ted.age = 15;

  // ...ou assim  (2)
  Student barney = {.name = "Barney", .age = 47};

  printf("sizeof(Student) = %lu bytes\n", sizeof(Student)); // sizeof(Student) = 104 bytes

  /*
    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    
    1. Alocação Dinâmica (calloc ou malloc)

    typedef struct _people {
      char name[100];
      int age;
    } People;

    People *joe = (People*) calloc(1, sizeof(People));
    strcpy(joe->name, "Joe");
    joe->age = 28;


    |-----------STACK----------|  |--------------------------HEAP--------------------------|
    0x0000     0x0004    0x0008    0x5000    0x5001    0x5002    0x5003    0x5....   0x5100   <=>   Endereços de Memória
    [0x5001]  [ ### ]   [ ### ]   [ 'J' ]   [ 'o' ]   [ 'e' ]   [ '\0']   [ '\0']   [  28 ]   <=>   Conteúdo
      ted        -         -      .name      ....      ....      ....        -       .age     <=>   Variáveis

    ted é um ponteiro
  */

  typedef struct _people {
    char name[100];
    int age;
  } People;

  People *joe = (People*) calloc(1, sizeof(People));
  strcpy(joe->name, "Joe");
  joe->age = 28;

  return 0;
}