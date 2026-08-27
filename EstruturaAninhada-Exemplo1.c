#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[100];
    Data nascimento;
    float nota;
} Aluno;

int main() {

    Aluno aluno;

    aluno.matricula = 1001;
    strcpy(aluno.nome, "Maria Silva");

    aluno.nascimento.dia = 15;
    aluno.nascimento.mes = 8;
    aluno.nascimento.ano = 2005;

    aluno.nota = 8.5;

    printf("--- DADOS DO ALUNO ---\n");

    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);

    printf("Nascimento: %02d/%02d/%d\n",
           aluno.nascimento.dia,
           aluno.nascimento.mes,
           aluno.nascimento.ano);

    printf("Nota: %.1f\n", aluno.nota);

    return 0;
}
