#include <stdio.h>

/*1 
Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval. Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. Inicialize todas as posições do tabuleiro com o valor 0, representando água.
*/
/*2
Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.
*/
/*3
Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console. Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios. A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios. 
Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização.
*/

int main() {
    //criando a matriz qeu representa o tabuleiro
    //10 10 significa 10x10, 0 é o valor inicial q é agua
    int tabuleiro[10][10] = {0};
    int i, j;

    // Posicionando os navios
    // Navio 1 (horizontal)
    // O navio 1 ocupa 3 posições na linha 2, começando na coluna 3
    int navio1[3] = {0, 1, 2};
    int navio1_x = 2; // coordenada x
    int navio1_y = 3; // coordenada y
    //para o navio 1, o loop percorre as colunas (y) da linha 2 (x = 2)
    for (i = 0; i < 3; i++) {
        tabuleiro[navio1_x][navio1_y + i] = 3; // posicionando o navio 1 na matriz
    }
    // Navio 2 (vertical)
    // O navio 2 ocupa 3 posições na coluna 6, começando na linha 5
    int navio2[3] = {0, 1, 2}; 
    int navio2_x = 5; 
    int navio2_y = 6; 
    //o loop percorre as linhas (x) da coluna 6 (y = 6)
    for (i = 0; i < 3; i++) {
        tabuleiro[navio2_x + i][navio2_y] = 3; 
    }

    // Exibindo o tabuleiro
    printf("Tabuleiro:\n");
    //loop aninhado para percorrer a matriz e imprimir os valores
    //o loop externo percorre as linhas (x) e o interno percorre as colunas (y)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n"); // nova linha após cada linha do tabuleiro
    }


    return 0;
}
