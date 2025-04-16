#include <stdio.h>

// definindo com constantes ao inves de variaveis
#define TAMANHO 10
#define NAVIO 3

// Função para verificar se a posição está livre e dentro dos limites
int verifPosicao(int tabuleiro[TAMANHO][TAMANHO], int x[], int y[]) {
    for (int i = 0; i < NAVIO; i++) {
        /*
         Verifica se cada parte do navio está dentro dos limites do tabuleiro
        (linha e coluna entre 0 e 9) e se a posição está livre (igual a 0).
        Se alguma parte estiver fora do tabuleiro ou já ocupada, retorna 0 (não pode posicionar).
        */
        if (x[i] < 0 || x[i] >= TAMANHO || y[i] < 0 || y[i] >= TAMANHO)
            return 0; 
        if (tabuleiro[x[i]][y[i]] != 0)
            return 0; 
    }
    return 1;
}


void posicao(int tabuleiro[TAMANHO][TAMANHO], int x[], int y[]) {
    for (int i = 0; i < NAVIO; i++) {
        tabuleiro[x[i]][y[i]] = 3;
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};
    int i, j;

    // NAVIO 1
    int x1[] = {2, 2, 2};
    int y1[] = {3, 4, 5};
    if (verifPosicao(tabuleiro, x1, y1)) {
        posicao(tabuleiro, x1, y1);
    }

    // NAVIO 2
    int x2[] = {5, 6, 7};
    int y2[] = {6, 6, 6};
    if (verifPosicao(tabuleiro, x2, y2)) {
        posicao(tabuleiro, x2, y2);
    }

    // NAVIO 3
    int x3[] = {0, 1, 2};
    int y3[] = {0, 1, 2};
    if (verifPosicao(tabuleiro, x3, y3)) {
        posicao(tabuleiro, x3, y3);
    }

    // NAVIO 4
    int x4[] = {0, 1, 2};
    int y4[] = {9, 8, 7};
    if (verifPosicao(tabuleiro, x4, y4)) {
        posicao(tabuleiro, x4, y4);
    }

    // EXIBINDO O TABULEIRO
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (i = 0; i < TAMANHO; i++) {
        for (j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
