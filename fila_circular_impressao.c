#include <stdio.h>

#define MAX 5

typedef struct {
    int id;
    char nome[50];
    int paginas;
} Documento;

typedef struct {
    Documento documentos[MAX];
    int inicio;
    int fim;
    int quantidade;
} FilaImpressao;

void inicializar(FilaImpressao *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

// Adiciona um documento
int adicionar(FilaImpressao *f, Documento doc) {
    if (f->quantidade == MAX) {
        return 0;
    }

    f->documentos[f->fim] = doc;
    f->fim = (f->fim + 1) % MAX;
    f->quantidade++;

    return 1;
}

// Processa o proximo documento
int imprimir(FilaImpressao *f, Documento *doc) {
    if (f->quantidade == 0) {
        return 0;
    }

    *doc = f->documentos[f->inicio];

    f->inicio = (f->inicio + 1) % MAX;
    f->quantidade--;

    return 1;
}

// Consulta o proximo documento
void consultar(FilaImpressao *f) {
    if (f->quantidade == 0) {
        printf("Nenhum documento aguardando.\n");
        return;
    }

    Documento doc = f->documentos[f->inicio];

    printf("Proximo: %s (%d paginas)\n",
           doc.nome, doc.paginas);
}

// Exibe a fila
void listar(FilaImpressao *f) {
    if (f->quantidade == 0) {
        printf("Fila de impressao vazia!\n");
        return;
    }

    printf("\n=== DOCUMENTOS AGUARDANDO ===\n");

    for (int i = 0; i < f->quantidade; i++) {
        int pos = (f->inicio + i) % MAX;

        Documento doc = f->documentos[pos];

        printf("%d - %s (%d paginas)\n",
               doc.id, doc.nome, doc.paginas);
    }
}

int main() {
    FilaImpressao fila;
    Documento doc;
    int opcao;
    int proximoId = 1;

    inicializar(&fila);

    do {
        printf("\n=== FILA DE IMPRESSAO ===\n");
        printf("1 - Enviar documento\n");
        printf("2 - Imprimir proximo\n");
        printf("3 - Consultar proximo\n");
        printf("4 - Listar documentos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                doc.id = proximoId;

                printf("Nome do documento: ");
                if (scanf(" %49[^\n]", doc.nome) != 1)
                    break;

                printf("Quantidade de paginas: ");
                if (scanf("%d", &doc.paginas) != 1)
                    break;

                if (adicionar(&fila, doc)) {
                    printf("Documento enviado!\n");
                    proximoId++;
                } else {
                    printf("Fila cheia!\n");
                }
                break;

            case 2:
                if (imprimir(&fila, &doc)) {
                    printf("Imprimindo: %s\n", doc.nome);
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
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
