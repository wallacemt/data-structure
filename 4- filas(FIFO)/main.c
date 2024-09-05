// Estrutura de FILA - FIFO( First In, First Out )

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} Node;

void insertNode(Node **fila, int num){
    system("clear");
    Node *aux, *new = malloc(sizeof(Node));
    if(new){
        new->value = num;
        new->next = NULL;
        if(*fila == NULL){
            *fila = new;
        }else{
            aux = *fila;
            while(aux->next != NULL){
                aux = aux->next;
            }
            aux->next = new;
        }
    }else{
        printf("\nErro ao alocar memoria.\n");
    }
}

Node* removeNode(Node **fila){
    system("clear");
    Node *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->next;
    }else{
        printf("\tFila vazia\n ");
    }
    return remover;


}

void printFila(Node *fila){
    system("clear");
    printf("-------- FILA ----------\n");
    int i = 1;
    while(fila) {
        printf("%d - %d \n",i, fila->value);
        fila = fila ->next;
        i++;
    }
    
    printf("-------- FIM FILA ----------\n");
    
}

int main()
{
    Node *r, *fila = NULL;
    int opcao, valor;
    
    do{
        
        printf("\n\t0 - Sair\n\t1 - Inserir Dado\n\t2 - Remover Dado\n\t3 - Imprimir FILA\n\tEscolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite um valor!:");
                scanf("%d", &valor);
                insertNode(&fila, valor);
                break;
            case 2:
                r = removeNode(&fila);
                if(r != NULL){
                    printf("Removido: %d\n", r->value);
                    free(r);
                }
                break;
            case 3:
                printFila(fila);
                break;
            default:
                if(opcao!= 0){
                    printf("Opção Invalida!");
                }
        }
    }while(opcao != 0);
    
    return 0;
}







