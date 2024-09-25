#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar o paciente 
typedef struct {
    char nome[100];               // nome do paciente
    int gravidade;          // gravidade do paciente
    float horaChegada;       // horaChegada do paciente
    int historico;      // historico do paciente
} Paciente;

// Estrutura da Tabela Hash
typedef struct {
    Paciente *tabela[TAMANHO_HASH];  // Array de ponteiros para armazenar pacientes
} TabelaHash;

// Função Hash: Retorna o índice baseado no nome do paciente
int funcao_hash_string (char *str) {
    int soma =0;
    for (int i=0; str[i] != '\0'; i++){
        soma += str[i];
    }
    
    return soma % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função para inserir um paciente na tabela hash
void inserir(TabelaHash *tabela, Paciente *paciente) {
    int indice = funcao_hash_string(paciente->nome);  // Calcula o índice baseado no nome
    tabela->tabela[indice] = paciente;  // Insere o paciente na tabela
}

// Função para buscar um paciente na tabela hash pelo indice
Paciente *buscar(TabelaHash *tabela, char *nome) {
    int indice;
    
    indice = funcao_hash_string(nome);  // Calcula o índice para busca
    
    return tabela->tabela[indice];  // Retorna o paciente encontrado
}

void remover(TabelaHash *tabela, char *nome){
    int indice;
    indice = funcao_hash_string(nome);
    tabela -> tabela[indice] = NULL;
    printf("Paciente removido: %s", nome);
}

int main() {
   
    TabelaHash tabela = {NULL}; // Inicializa a tabela hash

    // Criação de pacientes
    Paciente paciente1 = {"Ana Clara", 1, 17.06, 3};
    Paciente paciente2 = {"Amanda", 5, 21.10, 1};
    Paciente paciente3 = {"Vinicius", 3, 18.30, 5};

    // Insere os pacientes na tabela hash
    inserir(&tabela, &paciente1);
    inserir(&tabela, &paciente2);
    inserir(&tabela, &paciente3);

    // Busca por um paciente específico
    Paciente *t = buscar(&tabela, "Vinicius");
    if (t != NULL) {
        printf("Paciente encontrado: nome: %s, gravidade: %d, horaChegada: %.2f, historico: %d\n",
               t->nome, t->gravidade, t->horaChegada, t->historico);
    } else {
        printf("Paciente não encontrado.\n");
    }
    
    remover(&tabela, "Amanda");
    return 0;
}
