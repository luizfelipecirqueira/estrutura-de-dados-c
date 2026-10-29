#include <stdio.h>
#include <stdlib.h>

void exibir(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Intercala duas partes ordenadas
void intercalar(int vetor[], int inicio,
                int meio, int fim, int auxiliar[]) {

    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    // Compara elementos das duas metades
    while (i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            auxiliar[k++] = vetor[i++];
        } else {
            auxiliar[k++] = vetor[j++];
        }
    }

    // Copia elementos restantes da esquerda
    while (i <= meio) {
        auxiliar[k++] = vetor[i++];
    }

    // Copia elementos restantes da direita
    while (j <= fim) {
        auxiliar[k++] = vetor[j++];
    }

    // Copia a parte ordenada ao vetor original
    for (int p = inicio; p <= fim; p++) {
        vetor[p] = auxiliar[p];
    }

    printf("Intercalando [%d..%d]: ",
           inicio, fim);

    for (int p = inicio; p <= fim; p++) {
        printf("%d ", vetor[p]);
    }

    printf("\n");
}

// Divide recursivamente o vetor
void mergeSortRecursivo(int vetor[], int inicio,
                        int fim, int auxiliar[]) {

    if (inicio >= fim) {
        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    mergeSortRecursivo(vetor, inicio, meio, auxiliar);
    mergeSortRecursivo(vetor, meio + 1, fim, auxiliar);

    intercalar(vetor, inicio, meio, fim, auxiliar);
}

// Funcao principal de ordenacao
int mergeSort(int vetor[], int n) {
    if (n <= 1) {
        return 1;
    }

    int *auxiliar = malloc(n * sizeof(int));

    if (auxiliar == NULL) {
        return 0;
    }

    mergeSortRecursivo(vetor, 0, n - 1, auxiliar);

    free(auxiliar);

    return 1;
}

int main() {
    int vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original: ");
    exibir(vetor, n);

    if (!mergeSort(vetor, n)) {
        printf("Erro de memoria!\n");
        return 1;
    }

    printf("\nVetor ordenado: ");
    exibir(vetor, n);

    return 0;
}
