#include <stdio.h>
#include <stdlib.h> //necessário para malloc

#define INITIAL_SIZE 3

int* pilha; //ponteiro para o array da pilha
int topo = -1; //índice do topo da pilha
int maxSize = INITIAL_SIZE; //tamanho atual do array da pilha


//declaração da função isEmpty para nao ter aviso no compilador
int isEmpty();

//função para expandir dinamicamente o array da pilha
void expandStack() {
    maxSize *= 2; //dobra o tamanho da pilha
    pilha = (int*)realloc(pilha, maxSize * sizeof(int)); //aloca o novo tamanho
    if (pilha == NULL) {
        printf("Erro ao expandir a pilha.\n");
        exit(1); //encerra o programa se falhar
    }
}

//função para adicionar um elemento na pilha
void push(int elemento) {
    if (topo >= maxSize - 1) {
        expandStack(); //expande a pilha se necessário
    }
    pilha[++topo] = elemento;
}

//função para remover e retornar o elemento do topo da pilha
int pop() {
    if (isEmpty()) { //verifica se a pilha está vazia antes de tentar remover
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--];
    }
}

//função para obter o elemento no topo da pilha
int top() {
    if (isEmpty()) { //verifica se a pilha está vazia antes de acessar o topo
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo];
    }
}

//função para imprimir o conteúdo da pilha
void imprimir() {
    printf("Conteúdo da pilha:\n");
    if (isEmpty()) { //verifica se a pilha está vazia antes de tentar imprimir
        printf("A pilha está vazia\n");
        return;
    }
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

//função para verificar se a pilha está vazia
int isEmpty() {
    return topo == -1; //retorna 1 se o topo é -1 (pilha vazia), caso contrário retorna 0
}


int main() {
    //inicializa o array da pilha
    pilha = (int*)malloc(INITIAL_SIZE * sizeof(int));
    if (pilha == NULL) {
        printf("Erro ao inicializar pilha\n");
        return 1; //encerra o programa se a alocação falhar
    }

    push(10);
    push(20);
    push(30);
    push(40); 
    push(50); 

    imprimir(); //imprime o conteúdo da pilha

    //exibe e remove elementos do topo da pilha
    
    printf("Elemento no topo: %d\n", top());
    printf("Elemento removido: %d\n", pop());
    imprimir();  


    free(pilha);

    return 0;
}
