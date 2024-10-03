#include <stdio.h>
#include <stdlib.h>

// Função para mesclar dois subarrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criando arrays temporários
    int L[n1], R[n2];

    // Copiando os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Mesclando os arrays temporários de volta no arr[]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = left; // Índice inicial do array mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva para dividir o array e chamar a função de mesclagem
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Encontrar o ponto médio
        int mid = left + (right - left) / 2;

        // Dividir o array nas duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Mesclar as duas metades
        merge(arr, left, mid, right);
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
	int i=0;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray ordenado: \n");
    printArray(arr, arr_size);
    return 0;
}
