#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[50];
    struct no *proximo;
} No;

typedef struct {
    No *ultimo;
    No *proximoAtendente;
} Rodizio;

// Inicializa o rodizio
void inicializar(Rodizio *r) {
    r->ultimo = NULL;
    r->proximoAtendente = NULL;
}

// Adiciona um atendente
int adicionar(Rodizio *r, const char *nome) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    strcpy(novo->nome, nome);

    if (r->ultimo == NULL) {
        novo->proximo = novo;

        r->ultimo = novo;
        r->proximoAtendente = novo;

        return 1;
    }

    novo->proximo = r->ultimo->proximo;
    r->ultimo->proximo = novo;
    r->ultimo = novo;

    return 1;
}

// Atribui o chamado ao proximo atendente
void atenderChamado(Rodizio *r) {
    if (r->proximoAtendente == NULL) {
        printf("Nenhum atendente cadastrado!\n");
        return;
    }

    printf("Chamado atribuido a: %s\n",
           r->proximoAtendente->nome);

    // Avanca para o proximo atendente
    r->proximoAtendente =
        r->proximoAtendente->proximo;
}

// Lista todos os atendentes
void listar(Rodizio *r) {
    if (r->ultimo == NULL) {
        printf("Nenhum atendente cadastrado.\n");
        return;
    }

    No *inicio = r->ultimo->proximo;
    No *atual = inicio;

    printf("\n=== EQUIPE DE ATENDIMENTO ===\n");

    do {
        printf("- %s\n", atual->nome);
        atual = atual->proximo;

    } while (atual != inicio);
}

// Remove um atendente pelo nome
int remover(Rodizio *r, const char *nome) {
    if (r->ultimo == NULL) {
        return 0;
    }

    No *anterior = r->ultimo;
    No *atual = r->ultimo->proximo;
    No *inicio = atual;

    do {
        if (strcmp(atual->nome, nome) == 0) {

            // Se for o unico atendente
            if (atual == anterior) {
                r->ultimo = NULL;
                r->proximoAtendente = NULL;
            } else {
                anterior->proximo = atual->proximo;

                if (atual == r->ultimo) {
                    r->ultimo = anterior;
                }

                if (atual == r->proximoAtendente) {
                    r->proximoAtendente =
                        atual->proximo;
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

// Libera a memoria
void liberar(Rodizio *r) {
    if (r->ultimo == NULL) {
        return;
    }

    No *inicio = r->ultimo->proximo;

    // Transforma temporariamente
    // a lista circular em linear
    r->ultimo->proximo = NULL;

    No *atual = inicio;

    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    inicializar(r);
}

int main() {
    Rodizio rodizio;
    int opcao;
    char nome[50];

    inicializar(&rodizio);

    do {
        printf("\n=== RODIZIO DE ATENDENTES ===\n");
        printf("1 - Adicionar atendente\n");
        printf("2 - Atender proximo chamado\n");
        printf("3 - Listar atendentes\n");
        printf("4 - Remover atendente\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                printf("Nome: ");

                if (scanf(" %49[^\n]", nome) != 1)
                    break;

                if (adicionar(&rodizio, nome)) {
                    printf("Atendente adicionado!\n");
                } else {
                    printf("Erro de memoria!\n");
                }
                break;

            case 2:
                atenderChamado(&rodizio);
                break;

            case 3:
                listar(&rodizio);
                break;

            case 4:
                printf("Nome para remover: ");

                if (scanf(" %49[^\n]", nome) != 1)
                    break;

                if (remover(&rodizio, nome)) {
                    printf("Atendente removido!\n");
                } else {
                    printf("Atendente nao encontrado.\n");
                }
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberar(&rodizio);
    return 0;
}
