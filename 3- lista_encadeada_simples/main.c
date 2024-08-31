//Lista encadeada simples
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct Node
{
	int idade;
	struct Node *prox;
};
typedef struct Node node;

// Funções de manipulação da lista
void iniciaLista(node *LISTA);
int vazia(node *LISTA);
void insereInicio(node *LISTA);
void insereFim(node *LISTA);
void insereMeio(node *LISTA);
void imprimeLista(node *LISTA);
void removeNode(node *LISTA);


// Funções auxiliares
int menu(void);
void opcaoMenu(node *LISTA, int op);

int main()
{
	node *LISTA = (node *)malloc(sizeof(node));
	if (LISTA == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória.\n");
		return 1;
	}
	iniciaLista(LISTA);

	int opcao;
	do
	{
		opcao = menu();
		opcaoMenu(LISTA, opcao);
	} while (opcao != 0);

	free(LISTA);
	return 0;
}

// Inicializa a lista
void iniciaLista(node *LISTA)
{
	LISTA->prox = NULL;
}

// Verifica se a lista está vazia
int vazia(node *LISTA)
{
	return LISTA->prox == NULL;
}

// Insere um nó no início da lista
void insereInicio(node *LISTA)
{
	node *novo = (node *)malloc(sizeof(node));
	if (novo == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória.\n");
		return;
	}
	printf("Idade por favor: ");
	scanf("%d", &novo->idade);

	novo->prox = LISTA->prox;
	LISTA->prox = novo;
}


// Insere um nó no final da lista
void insereFim(node *LISTA)
{
	node *novo = (node *)malloc(sizeof(node));
	if (novo == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória.\n");
		return;
	}
	printf("Idade por favor: ");
	scanf("%d", &novo->idade);
	novo->prox = NULL;

	if (vazia(LISTA))
	{
		LISTA->prox = novo;
	}
	else
	{
		node *temp = LISTA->prox;
		while (temp->prox != NULL)
		{
			temp = temp->prox;
		}
		temp->prox = novo;
	}
}


//remove elemento da lista
void removeNode(node *LISTA){
    int num;
    printf("Qual elemento deseja remover?: ");
    scanf("%d", &num);
    
    
    node *temp = LISTA;
    node *suc = NULL;
    node *ant = NULL;
    while(temp != NULL && temp->idade != num){
        ant = temp;
        temp = temp->prox;
    }
    
    if(temp!=NULL){
        suc = temp->prox;
        if(ant!=NULL){
            ant->prox = suc;    
        } else {
            LISTA = suc;
        }
        free(temp);
    }
    
}

// Insere um nó em uma posição específica na lista
void insereMeio(node *LISTA)
{
	int num;
	node *novo = (node *)malloc(sizeof(node));
    printf("Idade por favor: ");
    scanf("%d", &novo->idade);
    
	printf("Inserir depois de qual número: ");
	scanf("%d", &num);
	
	node *temp = LISTA;
	if(vazia){
	        printf("A lista esta vazia! ");
	}else{
	    while(temp != NULL && temp->prox !=NULL && temp->prox->idade != num){
	           temp = temp->prox;
	       }    
	}

	novo->prox = temp->prox;
	temp->prox = novo;
	
	free(temp);
}

// Imprime todos os elementos da lista
void imprimeLista(node *LISTA)
{
	node *temp = LISTA->prox;
	printf("Conteudo da lista:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->idade);
		temp = temp->prox;
	}
	printf("-----------------\n");
}


// Função para exibir o menu
int menu(void)
{
	int opcao;
	printf("Escolha uma das opcoes abaixo:\n");
	printf("0 - Sair\n");
	printf("1 - Inserir no inicio\n");
	printf("2 - Imprimir a lista\n");
	printf("3 - Inserir no fim\n");
	printf("4 - Inserir no meio\n");
	printf("5 - Remover Elemento\n");
	printf("Opcao: ");
	scanf("%d", &opcao);
	return opcao;
}


void opcaoMenu(node *LISTA, int op)
{
	switch (op)
	{
	case 1:
		system("clear");
		insereInicio(LISTA);
		break;
	case 2:
		system("clear");
		imprimeLista(LISTA);
		break;
	case 3:
		system("clear");
		insereFim(LISTA);
		break;
	case 4:
		system("clear");
		insereMeio(LISTA);
		break;
	case 5:
	    system("clear");
	    removeNode(LISTA);
	    break;
	case 0:
		// Caso para sair, não faz nada
		break;
	default:
		system("clear");
		printf("Opção inválida! Por favor, escolha uma opção do menu.\n\n");
		break;
	}
}
