#include <stdio.h>
#include <string.h>

#define TAM 3

typedef struct {
    int matricula;
    char nome[100];
    float nota;
} Aluno;

int main() {

    Aluno alunos[TAM];

    alunos[0].matricula = 1001;
    strcpy(alunos[0].nome, "Maria");
    alunos[0].nota = 8.5;

    alunos[1].matricula = 1002;
    strcpy(alunos[1].nome, "Joao");
    alunos[1].nota = 7.0;

    alunos[2].matricula = 1003;
    strcpy(alunos[2].nome, "Ana");
    alunos[2].nota = 9.2;

    for (int i = 0; i < TAM; i++) {

        printf("\n--- ALUNO %d ---\n", i + 1);

        printf("Matricula: %d\n",
               alunos[i].matricula);

        printf("Nome: %s\n",
               alunos[i].nome);

        printf("Nota: %.1f\n",
               alunos[i].nota);
    }

    return 0;
}
