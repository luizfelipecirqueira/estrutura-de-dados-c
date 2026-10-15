#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct no {
    Produto produto;
    struct no *proximo;
} No;

// Cadastra um produto no final
int cadastrar(No **inicio, Produto produto) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->produto = produto;
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        return 1;
    }

    No *atual = *inicio;

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo;
    return 1;
}

// Busca um produto pelo codigo
No *buscar(No *inicio, int codigo) {
    No *atual = inicio;

    while (atual != NULL) {
        if (atual->produto.codigo == codigo) {
            return atual;
        }

        atual = atual->proximo;
    }

    return NULL;
}

// Remove um produto pelo codigo
int remover(No **inicio, int codigo) {
    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL &&
           atual->produto.codigo != codigo) {

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

// Lista os produtos
void listar(No *inicio) {
    No *atual = inicio;

    if (atual == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    while (atual != NULL) {
        printf("\nCodigo: %d\n",
               atual->produto.codigo);

        printf("Nome: %s\n",
               atual->produto.nome);

        printf("Preco: R$ %.2f\n",
               atual->produto.preco);

        atual = atual->proximo;
    }
}

// Libera todos os nos
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
    Produto produto;
    int opcao;
    int codigo;

    do {
        printf("\n=== CADASTRO DE PRODUTOS ===\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar\n");
        printf("4 - Remover\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                printf("Codigo: ");
                if (scanf("%d", &produto.codigo) != 1)
                    break;

                if (buscar(inicio, produto.codigo) != NULL) {
                    printf("Codigo ja cadastrado!\n");
                    break;
                }

                printf("Nome: ");
                if (scanf(" %49[^\n]", produto.nome) != 1)
                    break;

                printf("Preco: ");
                if (scanf("%f", &produto.preco) != 1)
                    break;

                if (cadastrar(&inicio, produto)) {
                    printf("Produto cadastrado!\n");
                } else {
                    printf("Erro de memoria!\n");
                }
                break;

            case 2:
                listar(inicio);
                break;

            case 3:
                printf("Codigo: ");
                if (scanf("%d", &codigo) != 1)
                    break;

                {
                    No *encontrado = buscar(inicio, codigo);

                    if (encontrado != NULL) {
                        printf("Produto: %s\n",
                               encontrado->produto.nome);
                        printf("Preco: R$ %.2f\n",
                               encontrado->produto.preco);
                    } else {
                        printf("Produto nao encontrado.\n");
                    }
                }
                break;

            case 4:
                printf("Codigo: ");
                if (scanf("%d", &codigo) != 1)
                    break;

                if (remover(&inicio, codigo)) {
                    printf("Produto removido!\n");
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberar(&inicio);
    return 0;
}
