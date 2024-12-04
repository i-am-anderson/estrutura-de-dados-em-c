#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* CRUD de Structs

  Alocação Dinâmica:
• Considere que o Aluno possui um livro favorito, que, por simplificação, possui
um título, número de páginas e preço. • Codifique a struct de Livro e adapte a
struct de Aluno; • Crie as funções de Criação (C), Delete (D) e de Impressão
para a Struct Aluno e Livro • Na função de Delete, garanta que o ponteiro é
atribuído como NULL depois da desalocação
*/

// struct Book ...............................................................
typedef struct _book {
  char title[100];
  unsigned int num_pages;
  float price;
} Book;

// struct Student ............................................................
typedef struct _student {
  char name[100];
  unsigned int age;
  Book *prefer_book;
} Student;

// como se fosse um "constructor" ............................................
Book *create_book(const char *title, unsigned int num_pages, float price) {
  Book *book = (Book *)calloc(1, sizeof(Book));

  strcpy(book->title, title);
  book->num_pages = num_pages;
  book->price = price;

  return book;
}

// copia a variável 'book' para cada 'student' ...............................
Book *copy_book(Book *book) {
  return create_book(book->title, book->num_pages, book->price);
}

// como se fosse um "constructor" ............................................
Student *create_student(const char *name, unsigned int age, Book *prefer_book) {
  Student *student = (Student *)calloc(1, sizeof(Student));

  strcpy(student->name, name);
  student->age = age;
  student->prefer_book = copy_book(prefer_book);

  return student;
}

// desaloca da memória .......................................................
void destroy_book(Book **book_ref) {
  Book *book = *book_ref;

  free(book);
  *book_ref = NULL;
}

// desaloca da memória .......................................................
void destroy_student(Student **student_ref) {
  Student *student = *student_ref;

  // primeiro desaloca a cópia de 'book', para não perder a referência depois
  destroy_book(&student->prefer_book);

  free(student);
  *student_ref = NULL;
}

// Imprime ...................................................................
void print_book(const Book *book) {
  printf("Nome: %s\n", book->title);
  printf("Num Paginas: %u\n", book->num_pages);
  printf("Preco: R$ %.2f\n", book->price);
}

// Imprime ...................................................................
void print_student(const Student *student) {
  printf("Nome: %s\n", student->name);
  printf("Idade: %u\n", student->age);
  puts("Livro Preferido");
  puts(":.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:");
  print_book(student->prefer_book);
}

// Compara o título dos livros ...............................................
bool is_equal(const Book *book1, const Book *book2) {
  // strcmp retorna 0 para True
  if(strcmp(book1->title, book2->title) == 0) {
    return true;
  }

  return false;
}

// Main ......................................................................
int main() {
  Book *book1 = create_book("Harry Potter 1", 200, 25);
  print_book(book1);

  Book *book2 = create_book("A Revolta de Atlas", 652, 67);

  puts("");
  book1->price = 32;
  print_book(book1);

  puts("\n::::::::::::::::::::::::::::::::::::::::\n");

  Student *student1 = create_student("Hermione Granger", 19, book1);
  print_student(student1);

  puts("");
  student1->prefer_book = copy_book(book2);
  print_student(student1);

  /*
  student1->prefer_book != book1  =>  'prefer_book' é uma copia de 'book1', com
  outro endereço de memória
  */

  puts("\nLivros são iguais (títulos)?");
  if(is_equal(book2, student1->prefer_book)) puts("True");
  else puts("False");

  puts("\n::::::::::::::::::::::::::::::::::::::::\n");

  // Desalocação de memória
  destroy_book(&book1);
  printf("book1 === NULL? %d\n", book1 == NULL);

  destroy_student(&student1);
  printf("student1 === NULL? %d\n", student1 == NULL);

  return 0;
}

/*

|----STACK----| |----------HEAP-----------|
  s200    s208     h000     h...     h200
[h200]  [h200]  [ xxx ]   [...]   [ yyy ]
                  book             student

                                                                        ---
S200: book1     -> h000                 |   S208: student1  -> h200       |
STACK
                                                                        ---
h000: title     -> A Revolta de Atlas   |   h200: num_pages   -> John     |
h099: num_pages -> 525                  |   h299: age         -> 27       | HEAP
h103: price     -> 67                   |   h303: prefer_book -> h000     |
                                                                        ---
*/