#include <stdio.h>

void exibir(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void insertionSort(int vetor[], int n) {
    int comparacoes = 0;
    int deslocamentos = 0;

    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;

        // Desloca elementos maiores para a direita
        while (j >= 0) {
            comparacoes++;

            if (vetor[j] <= chave) {
                break;
            }

            vetor[j + 1] = vetor[j];
            deslocamentos++;

            j--;
        }

        // Insere a chave na posicao correta
        vetor[j + 1] = chave;

        printf("Passada %d: ", i);
        exibir(vetor, n);
    }

    printf("\nComparacoes: %d\n", comparacoes);
    printf("Deslocamentos: %d\n", deslocamentos);
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    exibir(vetor, n);

    insertionSort(vetor, n);

    printf("\nVetor ordenado: ");
    exibir(vetor, n);

    return 0;
}
