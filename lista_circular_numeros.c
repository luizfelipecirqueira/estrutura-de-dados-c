#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

// Insere no final
int inserirFinal(No **ultimo, int valor) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;

    if (*ultimo == NULL) {
        // Primeiro no aponta para si mesmo
        novo->proximo = novo;
        *ultimo = novo;
        return 1;
    }

    // Novo aponta para o primeiro
    novo->proximo = (*ultimo)->proximo;

    // Antigo ultimo aponta para o novo
    (*ultimo)->proximo = novo;

    // Atualiza o ultimo
    *ultimo = novo;

    return 1;
}

// Busca um valor
No *buscar(No *ultimo, int valor) {
    if (ultimo == NULL) {
        return NULL;
    }

    No *inicio = ultimo->proximo;
    No *atual = inicio;

    do {
        if (atual->valor == valor) {
            return atual;
        }

        atual = atual->proximo;

    } while (atual != inicio);

    return NULL;
}

// Remove a primeira ocorrencia
int remover(No **ultimo, int valor) {
    if (*ultimo == NULL) {
        return 0;
    }

    No *anterior = *ultimo;
    No *atual = (*ultimo)->proximo;
    No *inicio = atual;

    do {
        if (atual->valor == valor) {

            // Lista com apenas um no
            if (atual == anterior) {
                *ultimo = NULL;
            } else {
                anterior->proximo = atual->proximo;

                // Se removeu o ultimo
                if (atual == *ultimo) {
                    *ultimo = anterior;
                }
            }

            free(atual);
            return 1;
        }

        anterior = atual;
        atual = atual->proximo;

    } while (atual != inicio);

    return 0;
}

// Exibe a lista
void exibir(No *ultimo) {
    if (ultimo == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    No *inicio = ultimo->proximo;
    No *atual = inicio;

    printf("Lista circular: ");

    do {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;

    } while (atual != inicio);

    printf("(volta ao inicio)\n");
}

// Libera a memoria
void liberar(No **ultimo) {
    if (*ultimo == NULL) {
        return;
    }

    No *inicio = (*ultimo)->proximo;

    // Quebra a circularidade
    (*ultimo)->proximo = NULL;

    No *atual = inicio;

    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    *ultimo = NULL;
}

int main() {
    No *ultimo = NULL;

    inserirFinal(&ultimo, 10);
    inserirFinal(&ultimo, 20);
    inserirFinal(&ultimo, 30);

    exibir(ultimo);

    if (buscar(ultimo, 20) != NULL) {
        printf("Valor 20 encontrado!\n");
    }

    remover(&ultimo, 20);

    exibir(ultimo);

    liberar(&ultimo);

    return 0;
}
