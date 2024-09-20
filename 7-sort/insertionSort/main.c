#include <stdio.h>

#define N 8


void insertionSort(int *vetor){
        int k, j, aux = 0;
        for(k=0; k<= N - 1;k++){
            aux = vetor[k];
            j = k - 1;
            while(j >= 0 && aux < vetor[j]){
                vetor[j + 1] = vetor[j];
                j--;
            }
            vetor[j + 1] = aux;
        }
        for(int i = 0; i < N; i++){
            printf("%d -> ", vetor[i]);
        }
        
}

// Insertion Sort
int main()
{
    int vetor[] = {10, 4, 5, 1, 9, 6, 2};

    
    printf("Imprimindo vetor Ordenado\n");
    insertionSort(vetor);
    
    return 0;
}