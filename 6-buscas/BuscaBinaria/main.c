
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// void ordernarVetor(int valores[], int tamanho){
//     int vetorOrdenado[10];
//     vetorOrdenado[0] = valores[0];
    
//     for(int i = 0; i < tamanho; i++){
//         if(vetorOrdenado[i] < valores[i]){
//             vetorOrdenado[i] = valores[i];
//         }
//     }
    
    
//     for(int b = 0; b < tamanho; b++){
//         printf("%d\n", vetorOrdenado[b]);
//     }
// }

int buscaBinaria(int valores[], int tamanho){
    int pesquisa = 0;
    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d",&pesquisa);

    
    int index = 0;
    int inicio = 0;
    int fim = tamanho - 1;
    
    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        if(pesquisa==valores[meio]){
            return meio;
        }
        if(valores[meio]<pesquisa){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }
        
    }
    return -1;
    
    
    
}

int main()
{
    int numeros[] = {12, 33, 44, 49, 66, 76};
    int tamanho = sizeof(numeros)/sizeof(numeros[0]);
    
    int index = buscaBinaria(numeros, tamanho);
    
    if(index == -1){
        printf("Valor não encontrado");
    }else{
        printf("O index é %d",index);
    }
    
    return 0;
}














