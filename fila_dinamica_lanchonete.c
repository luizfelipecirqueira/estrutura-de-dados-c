#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero;
    char cliente[50];
    char produto[50];
} Pedido;

typedef struct no {
    Pedido pedido;
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

// Registra um pedido
int registrar(Fila *f, Pedido pedido) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    novo->pedido = pedido;
    novo->proximo = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }

    return 1;
}

// Retira o proximo pedido para preparo
int preparar(Fila *f, Pedido *pedido) {
    if (f->inicio == NULL) {
        return 0;
    }

    No *removido = f->inicio;

    *pedido = removido->pedido;

    f->inicio = removido->proximo;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(removido);

    return 1;
}

// Consulta o proximo pedido
void consultar(Fila *f) {
    if (f->inicio == NULL) {
        printf("Nenhum pedido aguardando.\n");
        return;
    }

    Pedido p = f->inicio->pedido;

    printf("Proximo pedido: %d\n", p.numero);
    printf("Cliente: %s\n", p.cliente);
    printf("Produto: %s\n", p.produto);
}

// Lista os pedidos
void listar(Fila *f) {
    No *atual = f->inicio;

    if (atual == NULL) {
        printf("Nenhum pedido aguardando.\n");
        return;
    }

    printf("\n=== PEDIDOS AGUARDANDO ===\n");

    while (atual != NULL) {
        printf("\nPedido: %d\n",
               atual->pedido.numero);

        printf("Cliente: %s\n",
               atual->pedido.cliente);

        printf("Produto: %s\n",
               atual->pedido.produto);

        atual = atual->proximo;
    }
}

// Libera os pedidos restantes
void liberar(Fila *f) {
    Pedido pedido;

    while (preparar(f, &pedido)) {
        // Libera cada no
    }
}

int main() {
    Fila fila;
    Pedido pedido;
    int opcao;
    int proximoNumero = 1;

    inicializar(&fila);

    do {
        printf("\n=== LANCHONETE ===\n");
        printf("1 - Registrar pedido\n");
        printf("2 - Preparar proximo pedido\n");
        printf("3 - Consultar proximo pedido\n");
        printf("4 - Listar pedidos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                pedido.numero = proximoNumero;

                printf("Cliente: ");
                if (scanf(" %49[^\n]",
                          pedido.cliente) != 1)
                    break;

                printf("Produto: ");
                if (scanf(" %49[^\n]",
                          pedido.produto) != 1)
                    break;

                if (registrar(&fila, pedido)) {
                    printf("Pedido registrado!\n");
                    proximoNumero++;
                } else {
                    printf("Erro de memoria!\n");
                }
                break;

            case 2:
                if (preparar(&fila, &pedido)) {
                    printf("Preparando pedido %d\n",
                           pedido.numero);
                    printf("Cliente: %s\n",
                           pedido.cliente);
                } else {
                    printf("Fila vazia!\n");
                }
                break;

            case 3:
                consultar(&fila);
                break;

            case 4:
                listar(&fila);
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberar(&fila);

    return 0;
}
