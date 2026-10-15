#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *proximo;
} No;

int push(No **topo, int valor) {

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->dado = valor;


    novo->proximo = *topo;

  
    *topo = novo;

    return 1;
}


int pop(No **topo, int *valor) {

    if (*topo == NULL) {
        return 0;
    }

    No *removido = *topo;

  
    *valor = removido->dado;


    *topo = removido->proximo;

    free(removido);

    return 1;
}


int peek(No *topo, int *valor) {

    if (topo == NULL) {
        return 0;
    }

    *valor = topo->dado;

    return 1;
}


void exibir(No *topo) {

    No *atual = topo;

    printf("\nPilha dinamica:\n");

    if (atual == NULL) {
        printf("Pilha vazia!\n");
        return;
    }

    while (atual != NULL) {
        printf("[%d]\n", atual->dado);
        atual = atual->proximo;
    }
}


void liberar(No **topo) {

    int valor;

    while (pop(topo, &valor)) {
        // Cada pop libera um no
    }
}

int main() {

    No *topo = NULL;
    int valor;

    push(&topo, 10);
    push(&topo, 20);
    push(&topo, 30);

    exibir(topo);

    if (peek(topo, &valor)) {
        printf("\nTopo atual: %d\n", valor);
    }

    if (pop(&topo, &valor)) {
        printf("Removido: %d\n", valor);
    }

    exibir(topo);

    liberar(&topo);

    return 0;
}
