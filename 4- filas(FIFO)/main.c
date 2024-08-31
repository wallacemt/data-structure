// Estrutura de FILA - FIFO( First In, First Out )

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next
} Node;

void insertNode(Node **fila, int num){
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
    Node *remove = NULL;

    if(*fila){
        remove = *fila;
        *fila = remove->next;
    }else{
        printf("\tFila vazia\n ");
    }
    return remove;


}

void printFila(Node *fila){
    printf("\t-------- FILA ----------\n");
    
    printf("\t-------- FIM FILA ----------\n");
    
}

int main()
{

    return 0;
}