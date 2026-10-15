#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se esta vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se esta cheia
int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// PUSH - Insere no topo
int push(Pilha *p, int valor) {

    if (estaCheia(p)) {
        return 0;
    }

    p->topo++;
    p->dados[p->topo] = valor;

    return 1;
}

// POP - Remove do topo
int pop(Pilha *p, int *valor) {

    if (estaVazia(p)) {
        return 0;
    }

    *valor = p->dados[p->topo];
    p->topo--;

    return 1;
}

// PEEK - Consulta sem remover
int peek(Pilha *p, int *valor) {

    if (estaVazia(p)) {
        return 0;
    }

    *valor = p->dados[p->topo];

    return 1;
}

// Exibe do topo para a base
void exibir(Pilha *p) {

    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }

    printf("\nPilha (topo -> base):\n");

    for (int i = p->topo; i >= 0; i--) {
        printf("[%d]\n", p->dados[i]);
    }
}

int main() {

    Pilha p;
    int valor;

    inicializar(&p);

    // Inserindo elementos
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    exibir(&p);

    // Consultando o topo
    if (peek(&p, &valor)) {
        printf("\nTopo atual: %d\n", valor);
    }

    // Removendo o topo
    if (pop(&p, &valor)) {
        printf("Elemento removido: %d\n", valor);
    }

    exibir(&p);

    return 0;
}
