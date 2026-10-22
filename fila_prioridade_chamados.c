#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    char descricao[80];
    int prioridade;
} Chamado;

typedef struct no {
    Chamado chamado;
    struct no *proximo;
} No;

// Insere chamado conforme a prioridade
int registrar(No **inicio, Chamado chamado) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->chamado = chamado;
    novo->proximo = NULL;

    if (*inicio == NULL ||
        chamado.prioridade <
        (*inicio)->chamado.prioridade) {

        novo->proximo = *inicio;
        *inicio = novo;

        return 1;
    }

    No *atual = *inicio;

    while (atual->proximo != NULL &&
           atual->proximo->chamado.prioridade
           <= chamado.prioridade) {

        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    return 1;
}

// Atende o chamado mais prioritario
int atender(No **inicio, Chamado *chamado) {
    if (*inicio == NULL) {
        return 0;
    }

    No *removido = *inicio;

    *chamado = removido->chamado;
    *inicio = removido->proximo;

    free(removido);

    return 1;
}

// Consulta o proximo chamado
void consultar(No *inicio) {
    if (inicio == NULL) {
        printf("Nenhum chamado aguardando.\n");
        return;
    }

    printf("\nProximo chamado: %d\n",
           inicio->chamado.numero);

    printf("Descricao: %s\n",
           inicio->chamado.descricao);

    printf("Prioridade: %d\n",
           inicio->chamado.prioridade);
}

// Lista os chamados
void listar(No *inicio) {
    No *atual = inicio;

    if (atual == NULL) {
        printf("Nenhum chamado aguardando.\n");
        return;
    }

    printf("\n=== FILA DE CHAMADOS ===\n");

    while (atual != NULL) {
        printf("\nChamado: %d\n",
               atual->chamado.numero);

        printf("Descricao: %s\n",
               atual->chamado.descricao);

        printf("Prioridade: %d\n",
               atual->chamado.prioridade);

        atual = atual->proximo;
    }
}

// Libera a memoria
void liberar(No **inicio) {
    Chamado chamado;

    while (atender(inicio, &chamado)) {
        // Libera cada no
    }
}

int main() {
    No *inicio = NULL;
    Chamado chamado;
    int opcao;
    int proximoNumero = 1;

    do {
        printf("\n=== SUPORTE TECNICO ===\n");
        printf("1 - Registrar chamado\n");
        printf("2 - Atender proximo\n");
        printf("3 - Consultar proximo\n");
        printf("4 - Listar chamados\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                chamado.numero = proximoNumero;

                printf("Descricao: ");

                if (scanf(" %79[^\n]",
                          chamado.descricao) != 1)
                    break;

                printf("Prioridade (1, 2 ou 3): ");

                if (scanf("%d",
                          &chamado.prioridade) != 1)
                    break;

                if (chamado.prioridade < 1 ||
                    chamado.prioridade > 3) {

                    printf("Prioridade invalida!\n");
                    break;
                }

                if (registrar(&inicio, chamado)) {
                    printf("Chamado registrado!\n");
                    proximoNumero++;
                } else {
                    printf("Erro de memoria!\n");
                }
                break;

            case 2:
                if (atender(&inicio, &chamado)) {
                    printf("Atendendo chamado %d\n",
                           chamado.numero);

                    printf("Descricao: %s\n",
                           chamado.descricao);
                } else {
                    printf("Fila vazia!\n");
                }
                break;

            case 3:
                consultar(inicio);
                break;

            case 4:
                listar(inicio);
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberar(&inicio);

    return 0;
}
