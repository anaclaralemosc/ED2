#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

// Função para inserir um elemento novo na lista
void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

// Função para remover um elemento da lista pelo seu índice
void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

// Função para imprimir os elementos da lista
void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

// Função para buscar a posição de um elemento na lista
int buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) { //percorre todos os elementos e então encontra a posição do elemento que foi pedido
        if (lista[i] == elemento) {
            return i;
        }
    }
    return -1;  // Retorna -1 se o elemento não for encontrado
}

// Função para inverter a lista
void inverter() {
    int inicio = 0;      //ponteiro inicio e fim
    int fim = tamanho - 1; 
    while (inicio < fim) {
        int temp = lista[inicio]; 
        lista[inicio] = lista[fim];  //troca as posições dos ponteiros
        lista[fim] = temp;
        inicio++;
        fim--;
    }
}

// Função para encontrar o valor máximo da lista
int encontrar_maximo() {
    if (tamanho == 0) {
        printf("A lista está vazia!\n");
        return -1;  // Retorna -1 se a lista estiver vazia
    }
    int max = lista[0];  //assume que o primeiro elemento da lista é o máximo (max = lista[0]). Percorre o restante da lista, atualizando o valor máximo se encontrar um valor maior
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] > max) {
            max = lista[i];
        }
    }
    return max;
}

// Função para encontrar o valor mínimo da lista
int encontrar_minimo() {
    if (tamanho == 0) {
        printf("A lista está vazia!\n");
        return -1;  // Retorna -1 se a lista estiver vazia
    }
    int min = lista[0];
    for (int i = 1; i < tamanho; i++) { //mesma logica da função anterior
        if (lista[i] < min) {
            min = lista[i];
        }
    }
    return min;
}


// Função principal
int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(5);
    inserir(25);

   imprimir();

    printf("Buscar o índice do elemento 20: %d\n", buscar(20)); // Deve retornar o índice 1
    printf("Buscar o índice do elemento 15: %d\n", buscar(15)); // Deve retornar -1 (não encontrado)

    printf("Inverter a lista;\n");
    inverter();
    imprimir();

    printf("Valor máximo da lista: %d\n", encontrar_maximo());
    printf("Valor mínimo da lista: %d\n", encontrar_minimo());

    printf("Remover o elemento no índice 2;\n");
    remover(2);
    imprimir();

    return 0;
}
