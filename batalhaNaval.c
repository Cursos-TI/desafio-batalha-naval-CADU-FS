#include <stdio.h>

int main() {
  // Declaração da matriz do tabuleiro 10x10
  int tabuleiro[10][10];
  // Representação dos navios
  int navio1_h[3] = {3, 3, 3}, navio2_v[3] = {3, 3, 3}, navio3_dcd[3] = {3, 3, 3}, navio4_dce[3] = {3, 3, 3};
  // Coordenadas da ponta dos navios
  int coord_1[2] = {0, 7}, coord_2[2] = {6, 5}, coord_3[2] = {4, 1}, coord_4[2] = {3, 6};

  // Montagem do tabuleiro completo com 0s
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      tabuleiro[i][j] = 0;
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

  // Posicionamento do navio 1
  for(int i = 0; i < 3; i++) {
    tabuleiro[coord_1[0]][coord_1[1] + i] = navio1_h[i];
  }

  // Posicionamento do navio 2
  // A condição verifica se já há parte de outro navio na posição
  for(int i = 0; i < 3; i++) {
    if(tabuleiro[coord_2[0] + i][coord_2[1]] == 3) {
      printf("O navio 2 está colidindo com outro navio.\n");
      return 1;
    } else {
      tabuleiro[coord_2[0] + i][coord_2[1]] = navio2_v[i];
    }
  }

  // Posicionamento do navio 3
  // A condição verifica se já há parte de outro navio na posição
  for(int i = 0; i < 3; i ++) {
    if(tabuleiro[coord_3[0] - i][coord_3[1] + i] == 3) {
      printf("O navio 3 está colidindo com outro navio.\n");
      return 1;
    } else {
      tabuleiro[coord_3[0] - i][coord_3[1] + i] = navio3_dcd[i];
    }
  }

  // Posicionamento do navio 4
  // A condição verifica se já há parte de outro navio na posição
  for(int i = 0; i < 3; i ++) {
    if(tabuleiro[coord_4[0] + i][coord_4[1] + i] == 3) {
      printf("O navio 4 está colidindo com outro navio.\n");
      return 1;
    } else {
      tabuleiro[coord_4[0] + i][coord_4[1] + i] = navio4_dce[i];
    }
  }

  // Imprimir o tabuleiro junto com os navios
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(j != 9) {
        printf("%i ", tabuleiro[i][j]);
      } else {
        printf("%i\n", tabuleiro[i][j]);
      }
    }
  }
}