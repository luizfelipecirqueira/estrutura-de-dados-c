#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    int prioridade;
    struct no *proximo;
} No;

// Insere respeitando a prioridade
int inserir(No **inicio, int valor, int prioridade) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->prioridade = prioridade;
    novo->proximo = NULL;

    // Fila vazia ou prioridade maior
    if (*inicio == NULL ||
        prioridade < (*inicio)->prioridade) {

        novo->proximo = *inicio;
        *inicio = novo;

        return 1;
    }

    No *atual = *inicio;

    // Mantem FIFO entre prioridades iguais
    while (atual->proximo != NULL &&
           atual->proximo->prioridade <= prioridade) {

        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    return 1;
}

// Remove o elemento mais prioritario
int remover(No **inicio, int *valor) {
    if (*inicio == NULL) {
        return 0;
    }

    No *removido = *inicio;

    *valor = removido->valor;
    *inicio = removido->proximo;

    free(removido);

    return 1;
}

// Consulta o primeiro
int consultar(No *inicio, int *valor) {
    if (inicio == NULL) {
        return 0;
    }

    *valor = inicio->valor;
    return 1;
}

// Exibe a fila
void exibir(No *inicio) {
    No *atual = inicio;

    printf("\nFila de prioridade:\n");

    while (atual != NULL) {
        printf("Valor: %d | Prioridade: %d\n",
               atual->valor, atual->prioridade);

        atual = atual->proximo;
    }
}

// Libera a memoria
void liberar(No **inicio) {
    int valor;

    while (remover(inicio, &valor)) {
        // Libera cada no
    }
}

int main() {
    No *inicio = NULL;
    int valor;

    inserir(&inicio, 100, 3);
    inserir(&inicio, 200, 1);
    inserir(&inicio, 300, 2);
    inserir(&inicio, 400, 1);

    exibir(inicio);

    if (consultar(inicio, &valor)) {
        printf("\nProximo valor: %d\n", valor);
    }

    if (remover(&inicio, &valor)) {
        printf("Removido: %d\n", valor);
    }

    exibir(inicio);

    liberar(&inicio);

    return 0;
}
