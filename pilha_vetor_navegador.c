#include <stdio.h>
#include <string.h>

#define MAX 10
#define TAM 50

typedef struct {
    char paginas[MAX][TAM];
    int topo;
} PilhaHistorico;

void inicializar(PilhaHistorico *p) {
    p->topo = -1;
}

// Armazena uma pagina no historico
int push(PilhaHistorico *p, const char *pagina) {

    if (p->topo == MAX - 1) {
        return 0;
    }

    p->topo++;

    strcpy(p->paginas[p->topo], pagina);

    return 1;
}

// Recupera a ultima pagina
int pop(PilhaHistorico *p, char *pagina) {

    if (p->topo == -1) {
        return 0;
    }

    strcpy(pagina, p->paginas[p->topo]);

    p->topo--;

    return 1;
}

// Consulta a ultima pagina do historico
int peek(PilhaHistorico *p, char *pagina) {

    if (p->topo == -1) {
        return 0;
    }

    strcpy(pagina, p->paginas[p->topo]);

    return 1;
}

void exibirHistorico(PilhaHistorico *p) {

    printf("\nHistorico de retorno:\n");

    if (p->topo == -1) {
        printf("Nenhuma pagina anterior.\n");
        return;
    }

    for (int i = p->topo; i >= 0; i--) {
        printf("- %s\n", p->paginas[i]);
    }
}

// Visita uma nova pagina
void visitar(PilhaHistorico *p,
             char *atual,
             const char *nova) {

    // Guarda a pagina atual antes de navegar
    if (!push(p, atual)) {
        printf("Historico cheio!\n");
        return;
    }

    strcpy(atual, nova);

    printf("Visitando: %s\n", atual);
}

// Volta para a pagina anterior
void voltar(PilhaHistorico *p, char *atual) {

    char anterior[TAM];

    if (pop(p, anterior)) {
        strcpy(atual, anterior);
        printf("Voltou para: %s\n", atual);
    } else {
        printf("Nao existem paginas anteriores.\n");
    }
}

int main() {

    PilhaHistorico historico;
    char atual[TAM] = "Inicial";
    char ultima[TAM];

    inicializar(&historico);

    visitar(&historico, atual, "Produtos");
    visitar(&historico, atual, "Carrinho");
    visitar(&historico, atual, "Pagamento");

    printf("\nPagina atual: %s\n", atual);

    exibirHistorico(&historico);

    if (peek(&historico, ultima)) {
        printf("\nProxima pagina ao voltar: %s\n",
               ultima);
    }

    voltar(&historico, atual);
    voltar(&historico, atual);

    printf("\nPagina atual: %s\n", atual);

    exibirHistorico(&historico);

    return 0;
}
