#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int conteudo;
    struct no *esquerda, *direita;
}No;

typedef struct {
    No *raiz;
}ArvB;

void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir(ArvB *arv, int valor);


void inserirEsquerda(No *no, int valor){
    if(no->esquerda == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda= NULL;
        novo->direita =  NULL;
        no->esquerda = novo;
    }else{
        if(valor < no->esquerda->conteudo){
            inserirEsquerda(no->esquerda, valor);
        }
        if(valor > no->esquerda->conteudo){
            inserirDireita(no->esquerda, valor);
        }
    }
}

void inserirDireita(No *no, int valor){
    if(no->direita == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }else{
        if(valor > no->direita->conteudo){
            inserirDireita(no->direita, valor);
        }
        if(valor < no->direita->conteudo){
            inserirEsquerda(no->direita, valor);
        }
    }
}

//inserir na arvore
// void inserir(ArvB *arv, int valor){
//     if(arv->raiz == NULL){
//         No *novo = (No*)malloc(sizeof(No));
//         novo->conteudo = valor;
//         novo->esquerda = NULL;
//         novo->direita = NULL;
//         arv->raiz = novo;
//     }else{
//         if(valor < arv->raiz->conteudo){
//             inserirEsquerda(arv->raiz, valor);
//         }
//         if(valor > arv->raiz->conteudo){
//             inserirDireita(arv->raiz, valor);
//         }
//     }
//}

//Maneira diferente de inserir valor na arvore
No* inserirNovaVersão(No *raiz, int valor) {
    if(raiz ==NULL){
        No *novo = (No*)(malloc(sizeof(No)));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo-> direita = NULL;
        return novo;
    }else{
        if(valor < raiz->conteudo){
            raiz->esquerda = inserirNovaVersão(raiz->esquerda, valor);
        }
        if(valor > raiz->conteudo){
            raiz->direita = inserirNovaVersão(raiz->direita, valor);
        }
        return raiz;
    }
}

int tamanho(No *raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

//imprime a arvore
void imprimir(No *raiz){
    if(raiz != NULL){
        imprimir(raiz-> esquerda);
        printf("%d | ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int buscar(No *raiz, int chave){
    if(raiz == NULL){
        return -1;
    }else{
        if(raiz->conteudo == chave){
            return raiz->conteudo;
        }else{
            if(chave < raiz->conteudo){
                return buscar(raiz->esquerda, chave);
            }else{
                return buscar(raiz->direita, chave);
            }
        }
    }
}


int main(){
    
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    do{ 
        printf("\n 0 - Sair \n 1 - Inserir \n 2 - Imprimir\n 3- Buscar na Arvore");
        printf("\nInsira uma opcao: ");
        scanf("%d", &op);

        switch (op){
            case 1:
                system("cls");
                printf("Insira um valor: ");
                scanf("%d", &valor);
                arv.raiz = inserirNovaVersão(arv.raiz, valor);
                break;
            case 2:
                system("cls");
                printf("\nImpressao da arvore binaria: \n");
                imprimir(arv.raiz);
                printf("\n O tamanho e -> %d", tamanho(arv.raiz));
                break;
            case 3:
                system("cls");
                printf("\n Digite o valor que deseja buscar na arvore: ");
                scanf("%d", &valor);
                printf("Resultado: %d", buscar(arv.raiz, valor));
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("Opção Invalida");
        }   
    }while(op != 0);

    return 0;
}