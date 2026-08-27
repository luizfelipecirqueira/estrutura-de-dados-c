#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char rua[100];
    int numero;
    char cidade[50];
    char estado[3];
} Endereco;

typedef struct {
    int matricula;
    char nome[100];

    Data nascimento;
    Endereco endereco;

    float nota;
} Aluno;

int main() {

    Aluno aluno;

    aluno.matricula = 1001;
    strcpy(aluno.nome, "Carlos Souza");

    aluno.nascimento.dia = 20;
    aluno.nascimento.mes = 3;
    aluno.nascimento.ano = 2004;

    strcpy(aluno.endereco.rua, "Rua 5");
    aluno.endereco.numero = 150;
    strcpy(aluno.endereco.cidade, "Aracaju");
    strcpy(aluno.endereco.estado, "SE");

    aluno.nota = 9.0;

    printf("--- ALUNO ---\n");

    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);

    printf("Nascimento: %02d/%02d/%d\n",
           aluno.nascimento.dia,
           aluno.nascimento.mes,
           aluno.nascimento.ano);

    printf("\nEndereco:\n");

    printf("%s, %d\n",
           aluno.endereco.rua,
           aluno.endereco.numero);

    printf("%s - %s\n",
           aluno.endereco.cidade,
           aluno.endereco.estado);

    printf("\nNota: %.1f\n", aluno.nota);

    return 0;
}
