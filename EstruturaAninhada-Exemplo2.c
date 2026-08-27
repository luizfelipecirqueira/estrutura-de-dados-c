#include <stdio.h>

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

    printf("--- CADASTRO DO ALUNO ---\n");

    printf("Matricula: ");
    scanf("%d", &aluno.matricula);

    printf("Nome: ");
    scanf(" %99[^\n]", aluno.nome);

    printf("\nData de nascimento\n");

    printf("Dia: ");
    scanf("%d", &aluno.nascimento.dia);

    printf("Mes: ");
    scanf("%d", &aluno.nascimento.mes);

    printf("Ano: ");
    scanf("%d", &aluno.nascimento.ano);

    printf("Nota: ");
    scanf("%f", &aluno.nota);

    printf("\n--- DADOS CADASTRADOS ---\n");

    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);

    printf("Nascimento: %02d/%02d/%d\n",
           aluno.nascimento.dia,
           aluno.nascimento.mes,
           aluno.nascimento.ano);

    printf("Nota: %.1f\n", aluno.nota);

    return 0;
}
