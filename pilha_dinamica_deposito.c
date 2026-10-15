#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[50];
} Caixa;

typedef struct no {
    Caixa caixa;
    struct no *proximo;
} No;

// PUSH - Empilha uma caixa
int empilhar(No **topo, Caixa caixa) {

    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->caixa = caixa;

    novo->proximo = *topo;

    *topo = novo;

    return 1;
}

// POP - Retira a caixa do topo
int desempilhar(No **topo, Caixa *caixa) {

    if (*topo == NULL) {
        return 0;
    }

    No *removido = *topo;

    *caixa = removido->caixa;

    *topo = removido->proximo;

    free(removido);

    return 1;
}

// PEEK - Consulta a caixa do topo
int consultarTopo(No *topo, Caixa *caixa) {

    if (topo == NULL) {
        return 0;
    }

    *caixa = topo->caixa;

    return 1;
}

// Exibe as caixas
void exibir(No *topo) {

    No *atual = topo;

    if (atual == NULL) {
        printf("\nNenhuma caixa empilhada.\n");
        return;
    }

    printf("\n=== CAIXAS NO DEPOSITO ===\n");
    printf("Ordem: topo para base\n\n");

    while (atual != NULL) {

        printf("Codigo: %d\n",
               atual->caixa.codigo);

        printf("Descricao: %s\n",
               atual->caixa.descricao);

        printf("-----------------------\n");

        atual = atual->proximo;
    }
}

// Libera todas as caixas
void liberar(No **topo) {

    Caixa caixa;

    while (desempilhar(topo, &caixa)) {
        // Remove e libera cada no
    }
}

int main() {

    No *topo = NULL;

    Caixa caixa;

    int opcao;

    do {

        printf("\n===== DEPOSITO DE CAIXAS =====\n");
        printf("1 - Empilhar caixa\n");
        printf("2 - Retirar caixa do topo\n");
        printf("3 - Consultar topo\n");
        printf("4 - Exibir caixas\n");
        printf("0 - Sair\n");

        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            break;
        }

        switch (opcao) {

            case 1:

                printf("Codigo da caixa: ");

                if (scanf("%d", &caixa.codigo) != 1) {
                    printf("Codigo invalido!\n");
                    liberar(&topo);
                    return 1;
                }

                printf("Descricao: ");

                // Espaco antes de % para ignorar
                // a quebra de linha anterior
                if (scanf(" %49[^\n]",
                          caixa.descricao) != 1) {
                    printf("Descricao invalida!\n");
                    liberar(&topo);
                    return 1;
                }

                if (empilhar(&topo, caixa)) {
                    printf("Caixa empilhada!\n");
                } else {
                    printf("Erro de memoria!\n");
                }

                break;

            case 2:

                if (desempilhar(&topo, &caixa)) {

                    printf("\nCaixa retirada:\n");
                    printf("Codigo: %d\n",
                           caixa.codigo);

                    printf("Descricao: %s\n",
                           caixa.descricao);

                } else {
                    printf("Pilha vazia!\n");
                }

                break;

            case 3:

                if (consultarTopo(topo, &caixa)) {

                    printf("\nCaixa no topo:\n");
                    printf("Codigo: %d\n",
                           caixa.codigo);

                    printf("Descricao: %s\n",
                           caixa.descricao);

                } else {
                    printf("Pilha vazia!\n");
                }

                break;

            case 4:

                exibir(topo);

                break;

            case 0:

                printf("Encerrando sistema...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberar(&topo);

    return 0;
}
