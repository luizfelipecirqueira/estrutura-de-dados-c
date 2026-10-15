#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char musica[60];
    struct no *anterior;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    No *atual;
} Playlist;

void inicializar(Playlist *p) {
    p->inicio = NULL;
    p->fim = NULL;
    p->atual = NULL;
}

// Adiciona uma musica ao final
int adicionar(Playlist *p, const char *nome) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        return 0;
    }

    strcpy(novo->musica, nome);

    novo->anterior = p->fim;
    novo->proximo = NULL;

    if (p->fim != NULL) {
        p->fim->proximo = novo;
    } else {
        p->inicio = novo;
    }

    p->fim = novo;

    // Primeira musica adicionada
    if (p->atual == NULL) {
        p->atual = novo;
    }

    return 1;
}

// Mostra a musica atual
void reproduzir(Playlist *p) {
    if (p->atual == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    printf("Tocando: %s\n", p->atual->musica);
}

// Avanca para a proxima musica
void proxima(Playlist *p) {
    if (p->atual == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    if (p->atual->proximo == NULL) {
        printf("Ultima musica da playlist!\n");
        return;
    }

    p->atual = p->atual->proximo;
    reproduzir(p);
}

// Volta para a musica anterior
void anterior(Playlist *p) {
    if (p->atual == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    if (p->atual->anterior == NULL) {
        printf("Primeira musica da playlist!\n");
        return;
    }

    p->atual = p->atual->anterior;
    reproduzir(p);
}

// Exibe a playlist
void listar(Playlist *p) {
    No *aux = p->inicio;

    printf("\n=== PLAYLIST ===\n");

    while (aux != NULL) {
        if (aux == p->atual) {
            printf(">> %s [TOCANDO]\n", aux->musica);
        } else {
            printf("   %s\n", aux->musica);
        }

        aux = aux->proximo;
    }
}

// Libera todos os nos
void liberar(Playlist *p) {
    No *aux = p->inicio;

    while (aux != NULL) {
        No *proximo = aux->proximo;
        free(aux);
        aux = proximo;
    }

    inicializar(p);
}

int main() {
    Playlist playlist;
    int opcao;
    char nome[60];

    inicializar(&playlist);

    do {
        printf("\n=== PLAYER DE MUSICA ===\n");
        printf("1 - Adicionar musica\n");
        printf("2 - Reproduzir atual\n");
        printf("3 - Proxima musica\n");
        printf("4 - Musica anterior\n");
        printf("5 - Listar playlist\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        switch (opcao) {
            case 1:
                printf("Nome da musica: ");

                if (scanf(" %59[^\n]", nome) != 1) {
                    break;
                }

                if (adicionar(&playlist, nome)) {
                    printf("Musica adicionada!\n");
                } else {
                    printf("Erro de memoria!\n");
                }
                break;

            case 2:
                reproduzir(&playlist);
                break;

            case 3:
                proxima(&playlist);
                break;

            case 4:
                anterior(&playlist);
                break;

            case 5:
                listar(&playlist);
                break;

            case 0:
                printf("Encerrando player...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    liberar(&playlist);
    return 0;
}
