#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int quantidade;
} FilaCircular;

void inicializar(FilaCircular *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int estaVazia(FilaCircular *f) {
    return f->quantidade == 0;
}

int estaCheia(FilaCircular *f) {
    return f->quantidade == MAX;
}

// Insere na proxima posicao disponivel
int enfileirar(FilaCircular *f, int valor) {
    if (estaCheia(f)) {
        return 0;
    }

    f->dados[f->fim] = valor;

    // Avanca circularmente
    f->fim = (f->fim + 1) % MAX;

    f->quantidade++;

    return 1;
}

// Remove o primeiro elemento
int desenfileirar(FilaCircular *f, int *valor) {
    if (estaVazia(f)) {
        return 0;
    }

    *valor = f->dados[f->inicio];

    // Avanca circularmente
    f->inicio = (f->inicio + 1) % MAX;

    f->quantidade--;

    return 1;
}

// Consulta o primeiro elemento
int consultarInicio(FilaCircular *f, int *valor) {
    if (estaVazia(f)) {
        return 0;
    }

    *valor = f->dados[f->inicio];

    return 1;
}

// Exibe os elementos em ordem FIFO
void exibir(FilaCircular *f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila circular: ");

    for (int i = 0; i < f->quantidade; i++) {
        int posicao = (f->inicio + i) % MAX;

        printf("%d ", f->dados[posicao]);
    }

    printf("\n");
}

int main() {
    FilaCircular fila;
    int valor;

    inicializar(&fila);

    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);

    exibir(&fila);

    desenfileirar(&fila, &valor);
    desenfileirar(&fila, &valor);

    exibir(&fila);

    // Reutiliza as posicoes liberadas
    enfileirar(&fila, 60);
    enfileirar(&fila, 70);

    exibir(&fila);

    if (consultarInicio(&fila, &valor)) {
        printf("Primeiro elemento: %d\n", valor);
    }

    return 0;
}
