#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10         
#define NAVIO 3            
#define HAB_SIZE 5        
#define AGUA 0
#define VALOR_NAVIO 3
#define VALOR_HABILIDADE 5

//essa funcao verifica se a posicao do navio eh valida
int verifPosicao(int tab[TAMANHO][TAMANHO], int x[], int y[]) {
    for (int i = 0; i < NAVIO; i++) {
        if (x[i] < 0 || x[i] >= TAMANHO || y[i] < 0 || y[i] >= TAMANHO)
            return 0;  
        if (tab[x[i]][y[i]] != AGUA)
            return 0;  
    }
    return 1;
}

//essa funcao coloca o navio na posicao correta
void posicao(int tab[TAMANHO][TAMANHO], int x[], int y[]) {
    for (int i = 0; i < NAVIO; i++) {
        tab[x[i]][y[i]] = VALOR_NAVIO;
    }
}

//----------------------HABILIDADES----------------------
void construirCone(int hab[HAB_SIZE][HAB_SIZE]) {
    int center = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
    
            if (i <= center && j >= center - i && j <= center + i)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

void construirCruz(int hab[HAB_SIZE][HAB_SIZE]) {
    int center = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
            if (i == center || j == center)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}

void construirOctaedro(int hab[HAB_SIZE][HAB_SIZE]) {
    int center = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++) {
        int dist = abs(center - i);
        for (int j = 0; j < HAB_SIZE; j++) {
            
            if (j >= dist && j < HAB_SIZE - dist)
                hab[i][j] = 1;
            else
                hab[i][j] = 0;
        }
    }
}
//-----------------------------------------------------------

//desenhando a habilidade no mapa
void aplicarHabilidade(int tab[TAMANHO][TAMANHO], int hab[HAB_SIZE][HAB_SIZE], int origemX, int origemY) {
    int offset = HAB_SIZE / 2;
    for (int i = 0; i < HAB_SIZE; i++) {
        for (int j = 0; j < HAB_SIZE; j++) {
            if (hab[i][j] == 1) {
                int x = origemX + i - offset;
                int y = origemY + j - offset;
          
                if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
                    tab[x][y] = VALOR_HABILIDADE;
                }
            }
        }
    }
}

//LOOP PRINCIPAL
int main() {
    int tabuleiro[TAMANHO][TAMANHO] = { {0} };
    int cone[HAB_SIZE][HAB_SIZE];
    int cruz[HAB_SIZE][HAB_SIZE];
    int octaedro[HAB_SIZE][HAB_SIZE];

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    int x1[] = {2, 2, 2}, y1[] = {3, 4, 5};
    int x2[] = {5, 6, 7}, y2[] = {6, 6, 6};
    int x3[] = {0, 1, 2}, y3[] = {0, 1, 2};
    int x4[] = {0, 1, 2}, y4[] = {9, 8, 7};

    if (verifPosicao(tabuleiro, x1, y1)) posicao(tabuleiro, x1, y1);
    if (verifPosicao(tabuleiro, x2, y2)) posicao(tabuleiro, x2, y2);
    if (verifPosicao(tabuleiro, x3, y3)) posicao(tabuleiro, x3, y3);
    if (verifPosicao(tabuleiro, x4, y4)) posicao(tabuleiro, x4, y4);

    int origConeX = 4, origConeY = 2;
    int origCruzX = 2, origCruzY = 7;
    int origOctX = 7, origOctY = 5;

    aplicarHabilidade(tabuleiro, cone, origConeX, origConeY);
    aplicarHabilidade(tabuleiro, cruz, origCruzX, origCruzY);
    aplicarHabilidade(tabuleiro, octaedro, origOctX, origOctY);

    printf("Tabuleiro (0=agua, 3=navio, 5=habilidade):\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
