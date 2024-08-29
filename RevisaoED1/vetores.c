#include <stdio.h>

int main() {
    int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //declaração do vetor 
    int i, temp, n=10; //declaração das variáveis

    for (i = 0; i < (n/2); i++) { //laço de repetição, n/2 para conseguir inverter as duas metades
        temp = vetor[i]; //temp é uma variavel auxiliar 
        vetor[i] = vetor[n-1 - i]; //invertendo o vetor 
        vetor[n-1 - i] = temp; 
    }

    printf("Vetor invertido:\n"); //impressão do vetor invertido 
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
