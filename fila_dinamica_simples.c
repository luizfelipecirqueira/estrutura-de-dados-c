#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

// ENQUEUE - Insere no final
int enfileirar(Fila *f, int valor) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (f->fim == NULL) {
        // Primeira insercao
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }

    return 1;
}

// DEQUEUE - Remove do inicio
int desenfileirar(Fila *f, int *valor) {
    if (f->inicio == NULL) {
        return 0;
    }

    No *removido = f->inicio;

    *valor = removido->valor;

    f->inicio = removido->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(removido);

    return 1;
}

// FRONT - Consulta o inicio
int consultarInicio(Fila *f, int *valor) {
    if (f->inicio == NULL) {
        return 0;
    }

    *valor = f->inicio->valor;

    return 1;
}

// Exibe a fila
void exibir(Fila *f) {
    No *atual = f->inicio;

    if (atual == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");

    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

// Libera toda a memoria
void liberar(Fila *f) {
    int valor;

    while (desenfileirar(f, &valor)) {
        // Cada remocao libera um no
    }
}

int main() {
    Fila fila;
    int valor;

    inicializar(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);

    exibir(&fila);

    if (consultarInicio(&fila, &valor)) {
        printf("Primeiro elemento: %d\n", valor);
    }

    if (desenfileirar(&fila, &valor)) {
        printf("Removido: %d\n", valor);
    }

    exibir(&fila);

    liberar(&fila);

    return 0;
}
