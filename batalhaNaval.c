#include <stdio.h>

int main() {
  // Declaração da matriz do tabuleiro 10x10
  int tabuleiro[10][10];
  // Declaração das matrizes das habilidades
  int cone[3][5], cruz[5][5], octaedro[5][5];
  // Representação dos navios
  int navio[3] = {3, 3, 3};
  // Coordenadas da ponta dos navios
  int coord_1[2] = {0, 7}, coord_2[2] = {6, 5}, coord_3[2] = {4, 1}, coord_4[2] = {3, 6};
  // Coordenadas das habilidades. O cone possui origem na ponta superior, equanto a cruz e o octaedro possuem origem no centro
  int coord_cone[2] = {0, 3}, coord_cruz[2] = {5, 6}, coord_octaedro[2] = {7, 2};

  // Montagem do tabuleiro completo com 0s
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      tabuleiro[i][j] = 0;
    }
  }

  // Montagem da matriz da habilidade de CONE com 0s e 1s
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      if((i == 0 && j == 2) || (i == 1 && (j >= 1 && j <= 3)) || (i == 2)) {
        cone[i][j] = 1;
      } else {
        cone[i][j] = 0;
      }
    }
  }

  // Montagem da matriz da habilidade de CRUZ com 0s e 1s
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(j == 2 || i == 2) {
        cruz[i][j] = 1;
      } else {
        cruz[i][j] = 0;
      }
    }
  }

  // Montagem da matriz da habilidade de OCTAEDRO com 0s e 1s
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(((i == 0 || i == 4) && j == 2) || ((i == 1 || i == 3) && (j >= 1 && j <= 3)) || (i == 2)) {
        octaedro[i][j] = 1;
      } else {
        octaedro[i][j] = 0;
      }
    }
  }

  // Valida se o navio 1 está dentro dos limites do tabuleiro
  if(coord_1[0] < 0 || coord_1[0] > 9 || coord_1[1] < 0 || coord_1[1] + 2 > 9) {
    printf("O navio 1 passou dos limites do tabuleiro.\n");
    return 1;
  }

  // Valida se o navio 2 está dentro dos limites do tabuleiro
  if(coord_2[0] < 0 || coord_2[0] + 2 > 9 || coord_2[1] < 0 || coord_2[1] > 9) {
    printf("O navio 2 passou dos limites do tabuleiro.\n");
    return 1;
  }

  // Valida se o navio 3 está dentro dos limites do tabuleiro
  if(coord_3[0] - 2 < 0 || coord_3[0] > 9 || coord_3[1] < 0 || coord_3[1] + 2 > 9) {
    printf("O navio 3 passou dos limites do tabuleiro.\n");
    return 1;
  }

  // Valida se o navio 4 está dentro dos limites do tabuleiro
  if(coord_4[0] < 0 || coord_4[0] + 2 > 9 || coord_4[1] < 0 || coord_4[1] + 2 > 9) {
    printf("O navio 4 passou dos limites do tabuleiro.\n");
    return 1;
  }

  // Valida se a habilidade de CONE está dentro dos limites do tabuleiro
  if(coord_cone[0] < 0 || coord_cone[0] + 2 > 9 || coord_cone[1] - 2 < 0 || coord_cone[1] + 2 > 9) {
    printf("A habilidade de CONE passou dos limites do tabuleiro.\n");
    return 1;
  }

  // Valida se a habilidade de CRUZ está dentro dos limites do tabuleiro
  if(coord_cruz[0] - 2 < 0 || coord_cruz[0] + 2 > 9 || coord_cruz[1] - 2 < 0 || coord_cruz[1] + 2 > 9) {
    printf("A habilidade de CRUZ passou dos limites do tabuleiro.\n");
    return 1;
  }

  // Valida se a habilidade de OCTAEDRO está dentro dos limites do tabuleiro
  if(coord_octaedro[0] - 2 < 0 || coord_octaedro[0] + 2 > 9 || coord_octaedro[1] - 2 < 0 || coord_octaedro[1] + 2 > 9) {
    printf("A habilidade de OCTAEDRO passou dos limites do tabuleiro.\n");
    return 1;
  }

  // Posicionamento do navio 1
  for(int i = 0; i < 3; i++) {
    tabuleiro[coord_1[0]][coord_1[1] + i] = navio[i];
  }

  // Posicionamento do navio 2
  // A condição verifica se já há parte de outro navio na posição
  for(int i = 0; i < 3; i++) {
    if(tabuleiro[coord_2[0] + i][coord_2[1]] == 3) {
      printf("O navio 2 está colidindo com outro navio.\n");
      return 1;
    } else {
      tabuleiro[coord_2[0] + i][coord_2[1]] = navio[i];
    }
  }

  // Posicionamento do navio 3
  // A condição verifica se já há parte de outro navio na posição
  for(int i = 0; i < 3; i ++) {
    if(tabuleiro[coord_3[0] - i][coord_3[1] + i] == 3) {
      printf("O navio 3 está colidindo com outro navio.\n");
      return 1;
    } else {
      tabuleiro[coord_3[0] - i][coord_3[1] + i] = navio[i];
    }
  }

  // Posicionamento do navio 4
  // A condição verifica se já há parte de outro navio na posição
  for(int i = 0; i < 3; i ++) {
    if(tabuleiro[coord_4[0] + i][coord_4[1] + i] == 3) {
      printf("O navio 4 está colidindo com outro navio.\n");
      return 1;
    } else {
      tabuleiro[coord_4[0] + i][coord_4[1] + i] = navio[i];
    }
  }

  // Posicionamento da habilidade de CONE
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 5; j++) {
      if(tabuleiro[coord_cone[0] + i][coord_cone[1] + j - 2] == 3 && cone[i][j] == 1) { // Verifica se há uma parte de um navio nessa posição do tabuleiro e se o elemento da matriz da habilidade é 1, indicando que a habilidade acertou essa parte do navio
        tabuleiro[coord_cone[0] + i][coord_cone[1] + j - 2] = 5;
      } else if(tabuleiro[coord_cone[0] + i][coord_cone[1] + j - 2] == 3 && cone[i][j] == 0) { // Verifica se há uma parte de um navio nessa posição do tabuleiro e se o elemento da matriz da habilidade é 0, indicando que a habilidade NÃO acertou essa parte do navio
        continue;
      } else { // Posicionamento padrão da habilidade se houver água nessa posição do tabuleiro
        tabuleiro[coord_cone[0] + i][coord_cone[1] + j - 2] = cone[i][j];
      }
    }
  }

  // Posicionamento da habilidade de CRUZ
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(tabuleiro[coord_cruz[0] + i - 2][coord_cruz[1] + j - 2] == 3 && cruz[i][j] == 1) { // Verifica se há uma parte de um navio nessa posição do tabuleiro e se o elemento da matriz da habilidade é 1, indicando que a habilidade acertou essa parte do navio
        tabuleiro[coord_cruz[0] + i - 2][coord_cruz[1] + j - 2] = 5;
      } else if(tabuleiro[coord_cruz[0] + i - 2][coord_cruz[1] + j - 2] == 3 && cruz[i][j] == 0) { // Verifica se há uma parte de um navio nessa posição do tabuleiro e se o elemento da matriz da habilidade é 0, indicando que a habilidade NÃO acertou essa parte do navio
        continue;
      } else if(tabuleiro[coord_cruz[0] + i - 2][coord_cruz[1] + j - 2] == 1) { // Verifica se já há uma habilidade nessa posição do tabuleiro
        continue;
      } else if(tabuleiro[coord_cruz[0] + i - 2][coord_cruz[1] + j - 2] == 5) { // Verifica se já há uma habilidade que acertou uma parte de um navio nessa posição do tabuleiro
        continue;
      } else { // Posicionamento padrão da habilidade se houver água nessa posição do tabuleiro
        tabuleiro[coord_cruz[0] + i - 2][coord_cruz[1] + j - 2] = cruz[i][j];
      }
    }
  }

  // Posicionamento da habilidade de OCTAEDRO
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      if(tabuleiro[coord_octaedro[0] + i - 2][coord_octaedro[1] + j - 2] == 3 && octaedro[i][j] == 1) { // Verifica se há uma parte de um navio nessa posição do tabuleiro e se o elemento da matriz da habilidade é 1, indicando que a habilidade acertou essa parte do navio
        tabuleiro[coord_octaedro[0] + i - 2][coord_octaedro[1] + j - 2] = 5;
      } else if(tabuleiro[coord_octaedro[0] + i - 2][coord_octaedro[1] + j - 2] == 3 && octaedro[i][j] == 0) { // Verifica se há uma parte de um navio nessa posição do tabuleiro e se o elemento da matriz da habilidade é 0, indicando que a habilidade NÃO acertou essa parte do navio
        continue;
      } else if(tabuleiro[coord_octaedro[0] + i - 2][coord_octaedro[1] + j - 2] == 1) { // Verifica se já há uma habilidade nessa posição do tabuleiro
        continue;
      } else if(tabuleiro[coord_octaedro[0] + i - 2][coord_octaedro[1] + j - 2] == 5) { // Verifica se já há uma habilidade que acertou uma parte de um navio nessa posição do tabuleiro
        continue;
      } else { // Posicionamento padrão da habilidade se houver água nessa posição do tabuleiro
        tabuleiro[coord_octaedro[0] + i - 2][coord_octaedro[1] + j - 2] = octaedro[i][j];
      }
    }
  }

  // Imprimir o tabuleiro junto com os navios e as habilidades
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(j != 9) {
        printf("%i ", tabuleiro[i][j]);
      } else {
        printf("%i\n", tabuleiro[i][j]);
      }
    }
  }

  return 0;
}