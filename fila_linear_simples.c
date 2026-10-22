#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
} Fila;

// Inicializa a fila vazia
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
}

// Verifica se esta vazia
int estaVazia(Fila *f) {
    return f->inicio > f->fim;
}

// Verifica se chegou ao final do vetor
int estaCheia(Fila *f) {
    return f->fim == MAX - 1;
}

// ENQUEUE - Insere no final
int enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        return 0;
    }

    f->fim++;
    f->dados[f->fim] = valor;

    return 1;
}

// DEQUEUE - Remove do inicio
int desenfileirar(Fila *f, int *valor) {
    if (estaVazia(f)) {
        return 0;
    }

    *valor = f->dados[f->inicio];
    f->inicio++;

    return 1;
}

// FRONT - Consulta o primeiro elemento
int consultarInicio(Fila *f, int *valor) {
    if (estaVazia(f)) {
        return 0;
    }

    *valor = f->dados[f->inicio];

    return 1;
}

// Exibe a fila
void exibir(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");

    for (int i = f->inicio; i <= f->fim; i++) {
        printf("%d ", f->dados[i]);
    }

    printf("\n");
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

    return 0;
}
