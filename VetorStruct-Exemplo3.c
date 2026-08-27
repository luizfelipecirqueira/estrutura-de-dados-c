#include <stdio.h>

#define TAM 3

typedef struct {
    int matricula;
    char nome[100];
    float nota;
} Aluno;

int main() {

    Aluno alunos[TAM];

    for (int i = 0; i < TAM; i++) {

        printf("\n--- CADASTRO DO ALUNO %d ---\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Nome: ");
        scanf(" %99[^\n]", alunos[i].nome);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    printf("\n\n--- ALUNOS CADASTRADOS ---\n");

    for (int i = 0; i < TAM; i++) {

        printf("\nAluno %d\n", i + 1);

        printf("Matricula: %d\n",
               alunos[i].matricula);

        printf("Nome: %s\n",
               alunos[i].nome);

        printf("Nota: %.1f\n",
               alunos[i].nota);
    }

    return 0;
}
