#include <stdio.h>

#define N 8

// Boble Sort
int main()
{
    int vetor[] = {10, 4, 5, 1, 9, 6, 2};
    
    int x, y = 0;
    int temp = 0;
    
    for (x = 0; x<N; x++ ){
        for(y=x + 1; y<N; y++){
            if(vetor[x] > vetor[y]){
                temp = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = temp;
            }
        }
    }
    printf("Imprimindo vetor Ordenado\n");
    for(x = 0; x < N; x++){
        printf("%d -> ", vetor[x]);
    }
    
    return 0;
}