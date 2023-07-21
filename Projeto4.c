#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct local {
  int x, y;

} local;

void labirintoSolucao(char **mapa, int nColunas, int nLinhas, local *robo,
                      local *destino) {

  local distancia;

  // CALCULANDO A DISTANCIA EM LINHAS(X) E COLUNAS(Y)
  distancia.x = robo->x - destino->x;
  distancia.y = robo->y - destino->y;

  float poss[4];

  for (unsigned i = 0; i < 4; i++) {
    poss[i] = -1;
  }

  // CALCULO DA DISTANCIA POS MOVIMENTAÇÃO, A MENOR SERÁ ELEGIDA.
  for (unsigned i = 0; i < 4; i++) {
    if ((i == 0) && (mapa[robo->x + 1][robo->y] != '#')) {
      float aux = (float)sqrt(pow(distancia.x + 1, 2) + pow(distancia.y, 2));
      poss[i] = aux;
    }
    if ((i == 1) && mapa[robo->x][robo->y + 1] != '#') {
      float aux = (float)sqrt(pow(distancia.x, 2) + pow(distancia.y + 1, 2));
      poss[i] = aux;
    }
    if ((i == 2) && (mapa[robo->x - 1][robo->y] != '#')) {
      float aux = (float)sqrt(pow(distancia.x - 1, 2) + pow(distancia.y, 2));
      poss[i] = aux;
    }
    if ((i == 3) && (mapa[robo->x][robo->y - 1] != '#')) {
      float aux = (float)sqrt(pow(distancia.x, 2) + pow(distancia.y - 1, 2));
      poss[i] = aux;
    }
  }

  // PEGAR A MENOR DISTANCIA, SE POSSIVEL
  float dMenor = FLT_MAX;
  for (size_t i = 0; i < 4; i++) {
    if ((poss[i] < dMenor) && (poss[i] > -1)) {
      dMenor = poss[i];
    }
  }

  // IMPRESSÃO DA MENOR DISTANCIA
  printf("Menor: %lf\n", dMenor);

  // IMPLEMENTAÇÃO DA MOVIMENTAÇÃO!!!
  for (unsigned i = 0; i < 4; i++) {

    // PARA CIMA
    if ((dMenor == poss[i]) && (i == 2)) {
      if ((mapa[robo->x - 1][robo->y] == ' ') ||
          (mapa[robo->x - 1][robo->y] == 'D')) {

        printf("PARA CIMA!!!!\n");

        if (mapa[robo->x - 1][robo->y] == 'D') {
          printf("ALVO ALANCADO!!\n");
        }

        mapa[robo->x - 1][robo->y] = mapa[robo->x][robo->y];
        mapa[robo->x][robo->y] = ' ';
        robo->x = robo->x - 1;

        /*IMPRIMINDO O MAPA POS MOVIMENTO*/
        for (unsigned i = 0; i < nLinhas; i++) {
          for (unsigned j = 0; j < nColunas; j++) {
            printf("%c", mapa[i][j]);
          }
          printf("\n");
        }
        //  VERIFICAR A POSIÇÃO DO ROBO E DO DESTINO
        printf("ROBO:Linha: %d, Coluna:%d\n", robo->x, robo->y);
        printf("DESTINO:Linha: %d, Coluna:%d\n", destino->x, destino->y);

        //########################VERIFICADO!!!!!########################
        break;
      }
    }
    // PARA BAIXO
    if ((dMenor == poss[i]) && (i == 0)) {

      if ((mapa[robo->x + 1][robo->y] == ' ') ||
          (mapa[robo->x + 1][robo->y] == 'D')) {

        if (mapa[robo->x + 1][robo->y] == 'D') {
          printf("ALVO ALANCADO!!\n");
        }

        mapa[robo->x + 1][robo->y] = mapa[robo->x][robo->y];
        mapa[robo->x][robo->y] = ' ';
        robo->x = robo->x + 1;
        printf("PARA BAIXO!!!!\n");

        /*IMPRIMINDO O MAPA POS MOVIMENTO*/
        for (unsigned i = 0; i < nLinhas; i++) {
          for (unsigned j = 0; j < nColunas; j++) {
            printf("%c", mapa[i][j]);
          }
          printf("\n");
        }
        //  VERIFICAR A POSIÇÃO DO ROBO E DO DESTINO
        printf("ROBO:Linha: %d, Coluna:%d\n", robo->x, robo->y);
        printf("DESTINO:Linha: %d, Coluna:%d\n", destino->x, destino->y);

        //########################VERIFICADO!!!!!########################
        break;
      }
    }

    // PARA ESQUERDA
    if ((dMenor == poss[i]) && (i == 3)) {
      if ((mapa[robo->x][robo->y - 1] == ' ') ||
          (mapa[robo->x][robo->y - 1] == 'D')) {

        printf("PARA ESQUERDA!!!!\n");

        if (mapa[robo->x][robo->y - 1] == 'D') {
          printf("ALVO ALANCADO!!\n");
        }

        mapa[robo->x][robo->y - 1] = mapa[robo->x][robo->y];
        mapa[robo->x][robo->y] = ' ';
        robo->y = robo->y - 1;

        /*IMPRIMINDO O MAPA POS MOVIMENTO*/
        for (unsigned i = 0; i < nLinhas; i++) {
          for (unsigned j = 0; j < nColunas; j++) {
            printf("%c", mapa[i][j]);
          }
          printf("\n");
        }
        //  VERIFICAR A POSIÇÃO DO ROBO E DO DESTINO
        printf("ROBO:Linha: %d, Coluna:%d\n", robo->x, robo->y);
        printf("DESTINO:Linha: %d, Coluna:%d\n", destino->x, destino->y);

        //########################VERIFICADO!!!!!########################
        break;
      }
    }

    // PARA DIREITA
    if ((dMenor == poss[i]) && (i == 1)) {
      if ((mapa[robo->x][robo->y + 1] == ' ') ||
          (mapa[robo->x][robo->y + 1] == 'D')) {

        printf("PARA DIREITA!!!!\n");

        if (mapa[robo->x][robo->y + 1] == 'D') {
          printf("ALVO ALANCADO!!\n");
        }

        mapa[robo->x][robo->y + 1] = mapa[robo->x][robo->y];
        mapa[robo->x][robo->y] = ' ';
        robo->y = robo->y + 1;

        /*IMPRIMINDO O MAPA POS MOVIMENTO*/
        for (unsigned i = 0; i < nLinhas; i++) {
          for (unsigned j = 0; j < nColunas; j++) {
            printf("%c", mapa[i][j]);
          }
          printf("\n");
        }
        //  VERIFICAR A POSIÇÃO DO ROBO E DO DESTINO
        printf("ROBO:Linha: %d, Coluna:%d\n", robo->x, robo->y);
        printf("DESTINO:Linha: %d, Coluna:%d\n", destino->x, destino->y);

        //########################VERIFICADO!!!!!########################
        break;
      }
    }
  }

  printf("ROBO:Linha: %d, Coluna:%d\n", robo->x, robo->y);

  scanf("%c");

  // ENQUANTO DMENOR != 0 AINDA HA MOVIMENTO A FAZER.
  if (dMenor != 0) {
    labirintoSolucao(mapa, nColunas, nLinhas, robo, destino);
  }
}

int main() {

  FILE *fp;
  char ch, **mapa;
  int nLinhas = 0;
  int aux = 0;
  int nColunas = 0;

  // ABRINDO O ARQUIVO
  if ((fp = fopen("mapa.txt", "r")) == NULL) {

    fprintf(stderr, "ERRO!! O arquivo não pode ser aberto.\n");
    return 1;
  }

  // CONTABILIZAÇÃO DAS COLUNAS E LINHAS
  while ((ch = fgetc(fp)) != EOF) {

    aux++;

    if (ch == '\n') {

      nColunas = aux;
      aux = 0;
      nLinhas++;
    }
  }

  // DECRESCIMO DO NUMERO DE COLUCAS PARA O '\n'.
  nColunas--;

  mapa = (char **)malloc(nLinhas * sizeof(char *));

  // criação da matriz PARA O MAPA!!!
  for (unsigned i = 0; i < nLinhas; i++) {
    mapa[i] = (char *)calloc(nColunas, sizeof(char));
  }

  rewind(fp);

  /*Contruindo o mapa e o colocando em uma matriz*/
  for (unsigned i = 0; i < nLinhas; i++) {

    for (unsigned j = 0; j < nColunas; j++) {
      mapa[i][j] = fgetc(fp);
    }

    fgetc(fp);
  }
  //###############################################

  /*IMPRIMINDO O MAPA */
  for (unsigned i = 0; i < nLinhas; i++) {
    for (unsigned j = 0; j < nColunas; j++) {
      printf("%c", mapa[i][j]);
    }
    printf("\n");
  }
  //##############################################################

  /*BUSCNADO A POSIÇÃO DO ROBO E DO DESTINO!!!*/
  local robo, destino;

  for (unsigned i = 0; i < nLinhas; i++) {
    for (unsigned j = 0; j < nColunas; j++) {
      if (mapa[i][j] == '@') {
        robo.x = i;
        robo.y = j;
      }
    }
  }

  for (unsigned i = 0; i < nLinhas; i++) {
    for (unsigned j = 0; j < nColunas; j++) {
      if (mapa[i][j] == 'D') {
        destino.x = i;
        destino.y = j;
      }
    }
  }

  // FUNÇÃO RECURSIVA PARA LOCOMOVER O ROBO
  labirintoSolucao(mapa, nColunas, nLinhas, &robo, &destino);

  return 0;
}