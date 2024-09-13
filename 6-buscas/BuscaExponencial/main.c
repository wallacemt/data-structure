
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int buscaBinaria(int valores[], int inicio, int fim, int pesquisa){

    
    int index = 0;
    // int inicio = 0;
    // int fim = tamanho - 1;
    
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

int buscaExponencial(int valores[], int tamanho, int pesquisa){
    
    int p = 1;
    
    while((p < tamanho) && valores[p] < pesquisa){
        p *= 2;
        printf("%d\n", p);
    }
    printf("%d\n", p);
    
    return buscaBinaria(valores, p / 2 ,(p < tamanho) ? p + 1: tamanho, pesquisa);
}

int main()
{
    int numeros[] = {12, 33, 44, 49, 66, 76};
    int tamanho = sizeof(numeros)/sizeof(numeros[0]);
    
    int pesquisa = 0;
    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d",&pesquisa);
    
    int index = buscaExponencial(numeros, tamanho, pesquisa);
    
    if(index == -1){
        printf("Valor não encontrado");
    }else{
        printf("O index é %d",index);
    }
    
    return 0;
}














