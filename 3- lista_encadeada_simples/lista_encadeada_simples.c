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
void libera(node *LISTA);

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

	libera(LISTA);
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

// Insere um nó em uma posição específica na lista
void insereMeio(node *LISTA)
{
	int pos;
	printf("Posicao para inserir (0 para inicio, 1 para posicao 1, etc.): ");
	scanf("%d", &pos);

	node *novo = (node *)malloc(sizeof(node));
	if (novo == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória.\n");
		return;
	}
	printf("Idade por favor: ");
	scanf("%d", &novo->idade);

	node *temp = LISTA;
	for (int i = 0; i < pos && temp->prox != NULL; i++)
	{
		temp = temp->prox;
	}

	novo->prox = temp->prox;
	temp->prox = novo;
}

// Imprime todos os elementos da lista
void imprimeLista(node *LISTA)
{
	node *temp = LISTA->prox;
	printf("Conteúdo da lista:\n");
	while (temp != NULL)
	{
		printf("%d\n", temp->idade);
		temp = temp->prox;
	}
	printf("-----------------\n");
}

// Libera a memória alocada para a lista
void libera(node *LISTA)
{
	node *temp;
	while (LISTA != NULL)
	{
		temp = LISTA;
		LISTA = LISTA->prox;
		free(temp);
	}
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
	printf("Opcao: ");
	scanf("%d", &opcao);
	return opcao;
}

// Executa a opção escolhida pelo usuário
void opcaoMenu(node *LISTA, int op)
{
	switch (op)
	{
	case 1:
		system("cls");
		insereInicio(LISTA);
		break;
	case 2:
		system("cls");
		imprimeLista(LISTA);
		break;
	case 3:
		system("cls");
		insereFim(LISTA);
		break;
	case 4:
		system("cls");
		insereMeio(LISTA);
		break;
	case 0:
		// Caso para sair, não faz nada
		break;
	default:
		system("cls");
		printf("Opção inválida! Por favor, escolha uma opção do menu.\n\n");
		break;
	}
}
