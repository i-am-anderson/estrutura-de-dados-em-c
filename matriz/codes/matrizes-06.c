
int main() {
  /*
  Row and Column Major Order

  ## Matriz
  ---             ---
  | a11   a12   a13 |
  | a21   a22   a23 |
  | a31   a32   a33 |
  ---             ---


  C/C++ === Row Major Order => percorre a11 a12 a13, depois a21 a22 a23, depois a31 a32 a33
  Fortran, Matlab, R === Column Major Order => percorre a11 a21 a31, depois a12 a22 a32, depois a13 a23 a33 


  ## RAM (Matriz Estática)

  int m[2][3]

  |--------------------------STACK-------------------------|  |-----------HEAP-----------|
  0x00000   0x00004   0x00008   0x00012   0x00016   0x00020   0x00100   0x00104   0x00108   <=>   Endereços de Memória
  [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   [ ### ]   <=>   Conteúdo
  m[0][0]   m[0][1]   m[0][2]   m[1][0]   m[1][1]   m[1][2]     *         *         *       <=>   Variáveis
  |--------LINHA 1----------|  |---------LINHA 2----------| 
  */

  return 0;
}