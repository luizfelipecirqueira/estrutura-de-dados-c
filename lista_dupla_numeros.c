#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *anterior;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Lista;

// Inicializa a lista
void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Cria um no
No *criarNo(int valor) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    return novo;
}

// Insere no inicio
void inserirInicio(Lista *lista, int valor) {
    No *novo = criarNo(valor);

    novo->proximo = lista->inicio;

    if (lista->inicio != NULL) {
        lista->inicio->anterior = novo;
    } else {
        lista->fim = novo;
    }

    lista->inicio = novo;
}

// Insere no final
void inserirFinal(Lista *lista, int valor) {
    No *novo = criarNo(valor);

    novo->anterior = lista->fim;

    if (lista->fim != NULL) {
        lista->fim->proximo = novo;
    } else {
        lista->inicio = novo;
    }

    lista->fim = novo;
}

// Busca um valor
No *buscar(Lista *lista, int valor) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

// Remove um valor
int remover(Lista *lista, int valor) {
    No *atual = buscar(lista, valor);

    if (atual == NULL) {
        return 0;
    }

    // Reconecta o no anterior
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->inicio = atual->proximo;
    }

    // Reconecta o proximo no
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        lista->fim = atual->anterior;
    }

    free(atual);
    return 1;
}

// Percorre do inicio ao fim
void exibirFrente(Lista *lista) {
    No *atual = lista->inicio;

    printf("Inicio -> ");

    while (atual != NULL) {
        printf("%d <-> ", atual->valor);
        atual = atual->proximo;
    }

    printf("NULL\n");
}

// Percorre do fim ao inicio
void exibirTras(Lista *lista) {
    No *atual = lista->fim;

    printf("Fim -> ");

    while (atual != NULL) {
        printf("%d <-> ", atual->valor);
        atual = atual->anterior;
    }

    printf("NULL\n");
}

// Libera a memoria
void liberar(Lista *lista) {
    No *atual = lista->inicio;

    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    inicializar(lista);
}

int main() {
    Lista lista;
    inicializar(&lista);

    inserirFinal(&lista, 10);
    inserirFinal(&lista, 20);
    inserirFinal(&lista, 30);
    inserirInicio(&lista, 5);

    exibirFrente(&lista);
    exibirTras(&lista);

    if (buscar(&lista, 20) != NULL) {
        printf("Valor 20 encontrado!\n");
    }

    remover(&lista, 20);

    exibirFrente(&lista);
    exibirTras(&lista);

    liberar(&lista);
    return 0;
}
