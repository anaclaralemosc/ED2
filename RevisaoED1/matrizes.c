#include <stdio.h>

int main() {
    int linhas = 3;
    int colunas = 3;
    int** matriz;
    int i, j, soma = 0;
    
    matriz = malloc(sizeof(int*) * linhas); //alocação de memória usando malloc
    
    for(int i = 0; i < linhas; i++) {
        matriz[i] = malloc(sizeof(int) * colunas);
    }
    printf("Insira os elementos da matriz 3x3:\n"); //inserção dos elementos da matriz
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]); //usuário atribuindo os valores da matriz
            if (i == j) {
                soma += matriz[i][j]; //soma dos elementos da diagonal principal
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma); //impressão da soma dos elementos
    
    free(matriz); //liberando a memória alocada

    return 0;
}
