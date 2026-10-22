#include <stdio.h>

#define MAX 10

typedef struct {
    int senhas[MAX];
    int inicio;
    int fim;
    int proximaSenha;
} Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->proximaSenha = 1;
}

// Reinicia os indices quando a fila fica vazia
void reiniciarSeVazia(Fila *f) {
    if (f->inicio > f->fim) {
        f->inicio = 0;
        f->fim = -1;
    }
}

// Gera uma senha e coloca na fila
int gerarSenha(Fila *f) {
    reiniciarSeVazia(f);

    if (f->fim == MAX - 1) {
        return 0;
    }

    f->fim++;
    f->senhas[f->fim] = f->proximaSenha;

    printf("Senha gerada: %d\n", f->proximaSenha);

    f->proximaSenha++;

    return 1;
}

// Chama a primeira senha
int chamarSenha(Fila *f) {
    if (f->inicio > f->fim) {
        return 0;
    }

    printf("Chamando senha: %d\n",
           f->senhas[f->inicio]);

    f->inicio++;

    reiniciarSeVazia(f);

    return 1;
}

// Consulta a proxima senha
void consultarProxima(Fila *f) {
    if (f->inicio > f->fim) {
        printf("Nenhuma senha aguardando.\n");
        return;
    }

    printf("Proxima senha: %d\n",
           f->senhas[f->inicio]);
}

// Exibe as senhas aguardando
void listar(Fila *f) {
    if (f->inicio > f->fim) {
        printf("Nenhuma senha aguardando.\n");
        return;
    }

    printf("Senhas aguardando: ");

    for (int i = f->inicio; i <= f->fim; i++) {
        printf("%d ", f->senhas[i]);
    }

    printf("\n");
}

int main() {
    Fila fila;
    int opcao;

    inicializar(&fila);

    do {
        printf("\n=== ATENDIMENTO POR SENHAS ===\n");
        printf("1 - Gerar senha\n");
        printf("2 - Chamar proxima senha\n");
        printf("3 - Consultar proxima senha\n");
        printf("4 - Listar fila\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                if (!gerarSenha(&fila)) {
                    printf("Capacidade esgotada!\n");
                }
                break;

            case 2:
                if (!chamarSenha(&fila)) {
                    printf("Fila vazia!\n");
                }
                break;

            case 3:
                consultarProxima(&fila);
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
