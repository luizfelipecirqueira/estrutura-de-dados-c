#include <stdio.h>

void exibir(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void bubbleSort(int vetor[], int n) {
    int comparacoes = 0;
    int trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int houveTroca = 0;

        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++;

            // Compara dois elementos vizinhos
            if (vetor[j] > vetor[j + 1]) {

                // Realiza a troca
                int auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;

                trocas++;
                houveTroca = 1;
            }
        }

        printf("Passada %d: ", i + 1);
        exibir(vetor, n);

        // Encerra se nenhuma troca foi necessaria
        if (!houveTroca) {
            break;
        }
    }

    printf("\nComparacoes: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    exibir(vetor, n);

    bubbleSort(vetor, n);

    printf("\nVetor ordenado: ");
    exibir(vetor, n);

    return 0;
}
