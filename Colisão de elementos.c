#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar uma paciente
typedef struct Paciente {
    char nome[100];               // nome único da paciente
    int gravidade;                // gravidade da paciente
    float horaChegada;            // horaChegada da paciente
    int historico;                // historico: "normal" ou "suspeita"
    struct Paciente *proximo;     // Ponteiro para a próxima paciente (lista ligada)
} Paciente;

// Estrutura da Tabela Hash
typedef struct {
    Paciente *tabela[TAMANHO_HASH];  // Array de ponteiros para o início da lista ligada
    int ocupada[TAMANHO_HASH];        // Array para indicar se a posição está ocupada
} TabelaHash;

// Função Hash: Retorna o índice baseado no nome do paciente
int funcao_hash(char *str) {
    int soma = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        soma += str[i];
    }
    
    return soma % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Sondagem linear
int sondagem_linear(TabelaHash *tabela, int indice) {
    int tentativas = 0;

    while (tabela->ocupada[indice] && tentativas < TAMANHO_HASH) {
        indice = (indice + 1) % TAMANHO_HASH;  // Avança linearmente
        tentativas++;
    }

    return (tentativas < TAMANHO_HASH) ? indice : -1;  // Retorna o índice ou -1 se a tabela estiver cheia
}

// Função para criar uma nova paciente
Paciente *criar_paciente(const char *nome, int gravidade, float horaChegada, int historico) {
    Paciente *novo_paciente = (Paciente *)malloc(sizeof(Paciente));
    if (novo_paciente == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(novo_paciente->nome, nome);
    novo_paciente->gravidade = gravidade;
    novo_paciente->horaChegada = horaChegada;
    novo_paciente->historico = historico;
    novo_paciente->proximo = NULL;
    return novo_paciente;
}

// Função para inserir uma paciente na tabela hash usando sondagem linear
void inserir_linear(TabelaHash *tabela, Paciente *paciente) {
    int indice = funcao_hash(paciente->nome);

    // Se não houver colisão, insere diretamente
    if (!tabela->ocupada[indice]) {
        tabela->tabela[indice] = paciente;
        tabela->ocupada[indice] = 1;
    } else {
        // Se houver colisão, chama a sondagem linear
        int novo_indice = sondagem_linear(tabela, indice);
        if (novo_indice != -1) {
            tabela->tabela[novo_indice] = paciente;
            tabela->ocupada[novo_indice] = 1;
        } else {
            printf("Erro: Tabela hash está cheia.\n");
            free(paciente);  // Libera memória se não conseguir inserir
        }
    }
}

// Função para exibir todas as pacientes
void exibir_todas(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        if (tabela->ocupada[i]) {
            Paciente *atual = tabela->tabela[i];
            while (atual != NULL) {
                printf("Paciente nome: %s, gravidade: %d, horaChegada: %.2f, historico: %d (Índice: %d)\n",
                       atual->nome, atual->gravidade, atual->horaChegada, atual->historico, i);
                atual = atual->proximo;  // Avança para a próxima paciente
            }
        }
    }
}

// Função para buscar uma paciente na tabela hash pelo nome
Paciente *buscar(TabelaHash *tabela, char *nome) {
    int indice = funcao_hash(nome);  // Calcula o índice para busca
    if (tabela->ocupada[indice]) {
        Paciente *atual = tabela->tabela[indice];
        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                return atual;  // Retorna a paciente se encontrada
            }
            atual = atual->proximo;  // Vai para a próxima paciente na lista ligada
        }
    }
    return NULL;  // Retorna NULL se não for encontrada
}

// Função para excluir uma paciente na tabela hash pelo nome
void excluir(TabelaHash *tabela, char *nome) {
    int indice = funcao_hash(nome);  // Calcula o índice para exclusão
    if (tabela->ocupada[indice]) {
        Paciente *atual = tabela->tabela[indice];
        Paciente *anterior = NULL;

        while (atual != NULL) {
            if (strcmp(atual->nome, nome) == 0) {
                // Se o elemento a ser removido for o primeiro da lista
                if (anterior == NULL) {
                    tabela->tabela[indice] = atual->proximo;  // Remove o primeiro elemento
                    if (tabela->tabela[indice] == NULL) {
                        tabela->ocupada[indice] = 0;  // Marca como não ocupado se a lista estiver vazia
                    }
                } else {
                    anterior->proximo = atual->proximo;  // Remove o elemento no meio ou fim
                }
                free(atual);  // Libera a memória da paciente
                printf("Paciente com nome %s foi excluída.\n", nome);
                return;
            }
            anterior = atual;
            atual = atual->proximo;
        }
    }
    printf("Paciente com nome %s não encontrada para exclusão.\n", nome);
}

// Função principal para demonstrar o uso da tabela hash com pacientes
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela = {0};  // Inicializa todas as posições como NULL e ocupada como 0

    printf("\nInserção com Sondagem Linear:\n");
    inserir_linear(&tabela, criar_paciente("Bruno", 3, 14.25, 2));
    inserir_linear(&tabela, criar_paciente("Carla", 1, 9.50, 4));
    inserir_linear(&tabela, criar_paciente("Diego", 5, 17.15, 1));
    inserir_linear(&tabela, criar_paciente("Amanda", 5, 21.10, 3));
    inserir_linear(&tabela, criar_paciente("Fernanda", 2, 12.40, 3));

    exibir_todas(&tabela);
    
    // Exemplo de busca
    Paciente *paciente = buscar(&tabela, "Diego");
    if (paciente != NULL) {
        printf("Paciente encontrado: %s\n", paciente->nome);
    } else {
        printf("Paciente não encontrado.\n");
    }

    // Exemplo de exclusão
    excluir(&tabela, "Carla");
    exibir_todas(&tabela);

    return 0;
}
