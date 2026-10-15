#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

// Cria um novo no
No *criarNo(int valor) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->proximo = NULL;

    return novo;
}

// Insere no inicio
void inserirInicio(No **inicio, int valor) {
    No *novo = criarNo(valor);

    novo->proximo = *inicio;
    *inicio = novo;
}

// Insere no final
void inserirFinal(No **inicio, int valor) {
    No *novo = criarNo(valor);

    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }

    No *atual = *inicio;

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo;
}

// Busca um valor
No *buscar(No *inicio, int valor) {
    No *atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

// Remove a primeira ocorrencia do valor
int remover(No **inicio, int valor) {
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL &&
           atual->valor != valor) {

        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

// Exibe os elementos
void exibir(No *inicio) {
    No *atual = inicio;

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

// Libera a memoria
void liberar(No **inicio) {
    No *atual = *inicio;

    while (atual != NULL) {
        No *proximo = atual->proximo;

        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}

int main() {
    No *inicio = NULL;

    inserirFinal(&inicio, 10);
    inserirFinal(&inicio, 20);
    inserirFinal(&inicio, 30);
    inserirInicio(&inicio, 5);

    exibir(inicio);

    No *resultado = buscar(inicio, 20);

    if (resultado != NULL) {
        printf("Valor 20 encontrado!\n");
    }

    remover(&inicio, 20);

    exibir(inicio);

    liberar(&inicio);

    return 0;
}
