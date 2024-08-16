#include <stdlib.h>
#include <stdio.h>

int main()
{
	int *vetor = NULL; //inicializa o vetor como nulo
	int tamanho = 0;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanho);//armazena o dado que o usuario digitou

	vetor = (int*)malloc(tamanho*sizeof(int)); //cria o espaço na memoria referente ao valor do tamanho
    int *head = vetor;//endereço do inicio do vetor
    
	for(int i = 0; i < tamanho; i++) {
		(*vetor) = i * 2; //armazeda dados no vetor
		vetor++;// avança para o proximo endereço de memoria
	}

    vetor = head;//retorna o vetor para posicao de memoria inicial
    
	for(int i = 0; i < tamanho; i++) {
		printf("vetor[%d]: %d\n", i, vetor[i]);//mostra os dados do vetor para o usuario
	}

	free(vetor);//limpa a memoria ao final do processo
	return 0;//retorno da funcao
}