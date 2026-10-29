#include <stdio.h>

void exibir(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void selectionSort(int vetor[], int n) {
    int comparacoes = 0;
    int trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;

        // Procura o menor elemento
        for (int j = i + 1; j < n; j++) {
            comparacoes++;

            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }

        // Troca somente quando necessario
        if (indiceMenor != i) {
            int auxiliar = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = auxiliar;

            trocas++;
        }

        printf("Passada %d: ", i + 1);
        exibir(vetor, n);
    }

    printf("\nComparacoes: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    exibir(vetor, n);

    selectionSort(vetor, n);

    printf("\nVetor ordenado: ");
    exibir(vetor, n);

    return 0;
}
