#include <stdio.h>

#define TAM 3

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

    Aluno alunos[TAM];

    int matriculaBusca;
    int encontrado = 0;

    /*
        CADASTRO
    */

    for (int i = 0; i < TAM; i++) {

        printf("\n--- CADASTRO DO ALUNO %d ---\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Nome: ");
        scanf(" %99[^\n]", alunos[i].nome);

        printf("Nascimento (dia mes ano): ");
        scanf("%d %d %d",
              &alunos[i].nascimento.dia,
              &alunos[i].nascimento.mes,
              &alunos[i].nascimento.ano);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);
    }

    /*
        LISTAGEM
    */

    printf("\n\n--- ALUNOS CADASTRADOS ---\n");

    for (int i = 0; i < TAM; i++) {

        printf("\nMatricula: %d\n",
               alunos[i].matricula);

        printf("Nome: %s\n",
               alunos[i].nome);

        printf("Nascimento: %02d/%02d/%d\n",
               alunos[i].nascimento.dia,
               alunos[i].nascimento.mes,
               alunos[i].nascimento.ano);

        printf("Nota: %.1f\n",
               alunos[i].nota);
    }

    /*
        BUSCA
    */

    printf("\n\nDigite a matricula que deseja buscar: ");
    scanf("%d", &matriculaBusca);

    for (int i = 0; i < TAM; i++) {

        if (alunos[i].matricula == matriculaBusca) {

            printf("\n--- ALUNO ENCONTRADO ---\n");

            printf("Nome: %s\n",
                   alunos[i].nome);

            printf("Nascimento: %02d/%02d/%d\n",
                   alunos[i].nascimento.dia,
                   alunos[i].nascimento.mes,
                   alunos[i].nascimento.ano);

            printf("Nota: %.1f\n",
                   alunos[i].nota);

            encontrado = 1;

            break;
        }
    }

    if (!encontrado) {

        printf("\nAluno nao encontrado.\n");
    }

    return 0;
}
