#include <stdio.h>
#include <stdlib.h>

typedef struct Node { //registro da lista
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL; //ponteiro auxiliar

void insertFront(int value) { //função para inserir um nó novo no inicio da lista
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void deleteNode(Node* node) { //função para excluir nó especifico
    if (node == head)
        head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    free(node); //libera a memoria alocada
}

void printList() { //função para exibir a lista
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//função para buscar um valor na lista
void buscarValor(int valor) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == valor) {
            printf("Valor %d encontrado!\n", valor);
            printf("Detalhes do nó:\n");
            printf("Valor: %d\n", temp->data);
            if (temp->prev != NULL) {
                printf("Anterior: %d\n", temp->prev->data);
            } else {
                printf("Anterior: Nenhum (primeiro nó)\n");
            }
            if (temp->next != NULL) {
                printf("Próximo: %d\n", temp->next->data);
            } else {
                printf("Próximo: Nenhum (último nó)\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("Valor %d não encontrado na lista.\n", valor);
}


int main() {  
    int valor;
    
    while (1) {  //enquanto o usuario nao digitar 0 esse loop continua 
        printf("Digite um valor para inserir na lista (0 para parar): ");
        scanf("%d", &valor);
        
        if (valor == 0) {
            break; //sai do loop se o usuário digitar 0
        }
        
        insertFront(valor); //chamando a função para inserção de nó
    }
    
    printf("Lista atual: ");
    printList();
    
    //busca de valor na lista
    printf("Digite um valor para buscar na lista: ");
    scanf("%d", &valor);
    buscarValor(valor);
    
    return 0;
}
