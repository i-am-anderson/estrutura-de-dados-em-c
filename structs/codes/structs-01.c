#include <string.h>
int main() {
  /*
    Struct (ou registro ou record) -> "pacote" de vaiáveis que podem ter tipos
    diferentes

    struct[nome do registro] {
      tipo campo1;
      tipo campo2;
      ...
      tipo campoN
    }[uma ou mais variáveis]
  */

  // Assim... (mais utilizado)
  struct People {
    char name[100];
    int age;
  };

  // declaração de uma variável
  struct People barney;

  // Copia a strung 'Barney' para o campo 'name'
  strcpy(barney.name, "Barney");
  barney.age = 42;

  // Ou ...
  struct PeopleSecond {
    char name[100];
    int age;
  } rachel, ted;

  // Ou... (struct anônima)
  struct {
    char name[100];
    int age;
  } robin, joe;

  // Copia a strung 'Robin' para o campo 'name'
  strcpy(robin.name, "Robin");
  robin.age = 37;

  // Ou... (mais elegante)
  typedef struct PeopleThirdy {
    char name[100];
    int age;
  } TypePeople; // TypePeople é como um alias

  // People é opcional, poderíamos omiti-lo deixando apenas o TypePeople para
  // representar o tipo da struct
  // posso declarar das duas formas:
  struct People ross; // 1
  TypePeople lily;    // 2

  // Vamos usar dessa forma:
  typedef struct _student {
    char name[100];
    int age;
  } Student;

  Student monica;

  return 0;
}