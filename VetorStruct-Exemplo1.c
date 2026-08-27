#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[100];
    float nota;
} Aluno;

int main() {

    Aluno alunos[3];

    alunos[0].matricula = 1001;
    strcpy(alunos[0].nome, "Maria");
    alunos[0].nota = 8.5;

    alunos[1].matricula = 1002;
    strcpy(alunos[1].nome, "Joao");
    alunos[1].nota = 7.0;

    alunos[2].matricula = 1003;
    strcpy(alunos[2].nome, "Ana");
    alunos[2].nota = 9.2;

    printf("Aluno 1: %s - %.1f\n",
           alunos[0].nome,
           alunos[0].nota);

    printf("Aluno 2: %s - %.1f\n",
           alunos[1].nome,
           alunos[1].nota);

    printf("Aluno 3: %s - %.1f\n",
           alunos[2].nome,
           alunos[2].nota);

    return 0;
}
