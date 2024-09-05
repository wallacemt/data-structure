#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes,ano;
}Data;

typedef struct
{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no
{
    Pessoa p;
    struct no *proximo;
    
}No;


Pessoa ler_pessoa() {
    Pessoa p;
    printf("\n Digite o nome, data de nascimento dd mm aaaa: \n");
    scanf("%49[^\n]%d%d%d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p) {
    printf("\n Nome : %s\n Data: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);

}

// Operação para o push = empilhar
No* empilhar(No *topo){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->p = ler_pessoa();
        novo->proximo = topo;
        return novo;
    }else{
        printf("Erro ao alocar memória....\n");
    }
    return NULL;

}

//Operacao de Pop = desempilhar
No* desempilhar(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;

    }else{
        printf("\n Pilha vazia!\n");
    }
    return NULL;
}

int main() {

    No *remover, *topo = NULL;
    int opcao;

    do {
        printf("\n\t0 - Sair\n\t1 - Empilhar\n\t2 - Desempilhar\n\t3 - Imprimir PILHA\n\tEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
  
        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);
            break;
        case 2:
            remover = desempilhar(&topo);
            if(remover){
                printf("Elemento  removido com sucesso!\n");
                imprimir_pessoa(remover->p);
            }else{
                printf("\n Sem no a remover.\n");
            }
            break;
        case 3:

            break;
        default:
            if(opcao != 0){
                printf("\n opcao invalida\n");
            }
        
        }
    } while (opcao != 0);

    return 0;

}