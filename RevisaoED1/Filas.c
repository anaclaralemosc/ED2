

#include <stdio.h>
#include <stdlib.h>

//estrutura do nó da fila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//estrutura da fila
typedef struct Queue {
    Node* front;
    Node* rear;
    int tamanho;
} Queue;

//função para criar uma fila nova 
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue)); //aloca memória para a fila
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
     q->tamanho = 0; //tamanho da fila começa em 0
    return q;
}

//função para adicionar elemento na fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value; //define os dados do prox nó
    newNode->next = NULL;
    if (q->rear == NULL) { 
        q->front = q->rear = newNode;
    } else { 
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->tamanho++; //aumenta o tamanho da fila
}

//função para remover um elemento da fila
int dequeue(Queue* q) {
    if (q->front == NULL) { 
        printf("Fila está vazia.\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->tamanho--; //diminui o tamanho da fila 
    return data; //retorna os dados do nó removido
}

//verifica se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL; //se estiver vazia retorna 1
}

//imprimir conteudo da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;
    printf("Elementos da fila: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next; //passa para o prox nó
    }
    printf("\n");
}

//função para contar o número de elementos na fila
int countElements(Queue* q) {
    return q->tamanho; //retorna o número de elementos na fila
}

//função para limpar todos os elementos da fila
void clearQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q); //remove e libera a memória dos nós
    }
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q);

    printf("Número de elementos na fila: %d\n", countElements(q)); //imprime o número de elementos
     
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Número de elementos na fila: %d\n", countElements(q)); 
     
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Número de elementos na fila: %d\n", countElements(q)); 
     
    printf("Desenfileirado: %d\n", dequeue(q));
    printQueue(q);
    printf("Número de elementos na fila: %d\n", countElements(q)); 

    clearQueue(q);
    printf("Número de elementos na fila após limpar: %d\n", countElements(q)); 
    
    //libera a memória alocada para a fila
    free(q);
    
    return 0;
}
