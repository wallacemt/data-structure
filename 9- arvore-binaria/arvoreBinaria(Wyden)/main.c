#include <stdio.h>
#include <stdlib.h>


struct Node {
    int dado;
    struct Node *esquerda;
    struct Node *direita;
};

struct Node *novoNo(int valor){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->dado = valor;
    node->esquerda = NULL;
    node->direita = NULL;
    return node;
}

struct Node* inserir(struct Node *node, int valor){
    if(node == NULL) {
        return novoNo(valor);
    }

    if(valor < node->dado){
        node->esquerda = inserir(node->esquerda, valor);

    }else if(valor > node->dado){
        node->direita = inserir(node->direita, valor);
    }

    return node;
}

void percorrerEmOrdem(struct Node *raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf(" <- %d -> ", raiz->dado);
        percorrerEmOrdem(raiz->direita);
    }
}

int tamanho(struct Node *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

int buscarValor(struct Node *raiz, int valor, int camada) {
    if (raiz == NULL) {
        return -1;
    } else {
        if (valor > raiz->dado) {
            return buscarValor(raiz->direita, valor, camada + 1);
        } else if (valor < raiz->dado) {
            return buscarValor(raiz->esquerda, valor, camada + 1);
        } else {
            return camada;
        }
    }
}

struct Node *remover(struct Node *raiz, int valor){
    if(raiz == NULL){
        printf("Valor nao encontrado!");
        return NULL;
    }else{
        if(raiz->dado == valor) {
            if(raiz->direita == NULL && raiz->esquerda == NULL){
                free(raiz);
                return NULL;
            }
        }else{
            if(valor > raiz->dado){
                raiz->direita = remover(raiz->direita, valor);
            }else{
                raiz->esquerda = remover(raiz->esquerda, valor);
            }
            return raiz;
        }
    }
}

int main(){
    struct Node *raiz = NULL;
    int op, valor;
    do {
        printf("\n===============================\n");
        printf("           ARVORE BINARIA        \n");
        printf("=================================\n");
        printf(" 0 - Sair\n");
        printf(" 1 - Inserir\n");
        printf(" 2 - Imprimir\n");
        printf(" 3 - Buscar na Arvore\n");
        printf(" 4 - Remover\n");
        printf("=================================\n");
        printf("\nInsira uma opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                system("cls");
                printf("Insira um valor: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                system("cls");
                printf("\nImpressao da arvore binaria: \n");
                percorrerEmOrdem(raiz);
                printf("\n O tamanho e -> %d", tamanho(raiz));
                break;
            case 3:
                system("cls");
                printf("Digite o valor que deseja buscar na Arvore: ");
                scanf("%d", &valor);
                int resultado = buscarValor(raiz, valor, 0);
                if(resultado == -1){
                    printf("Valor nao encontrado na arvore");
                }else{
                    printf("Valor encontrado na camada %d", resultado);
                }
                break;
            case 4:
                system("cls");
                printf("Digite o valor que deseja remover da Arvore: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;
            case 0:
                printf("\nSaindo...\n");
                break;
            default:
                printf("Opção Invalida");
        }
    } while(op != 0);
}
