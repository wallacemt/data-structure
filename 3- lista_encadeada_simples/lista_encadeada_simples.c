#include <stdio.h>
#include <stdlib.h>

struct Node{
	int idade;
	struct Node *prox;
};
typedef struct Node node;


int menu(void);
void iniciaLista(node *LISTA);
void opcaoMenu(node *LISTA,int op);
node *criaNo();
void insereFim(node* LISTA);
void insereInicio(node* LISTA);
void imprimeLista(node* LISTA);
void libera(node* LISTA);
int vazia(node *LISTA);


int main(){
	node *LISTA = (node *)malloc(sizeof(node));
	iniciaLista(LISTA);
	
	int opcao;
	
	do{
		opcao=menu();
		opcaoMenu(LISTA,opcao);
	}while(opcao);
	
}

void insereFim(node* LISTA){
	node *novo=(node *)malloc(sizeof(node));
	printf("Idade por favor: ");
	scanf("%d",&novo->idade);
	novo->prox=NULL;
	
	if(vazia(LISTA)){
		LISTA->prox=novo;
	}else{
		node *temp=LISTA->prox;
		while(temp->prox!=NULL){
			temp=temp->prox;
		}
		temp->prox=novo;
	}
	
}

void imprimeLista(node* LISTA){
	node *temp;
	temp=LISTA->prox;
	while(temp!=NULL){
		printf("%d\n",temp->idade);
		temp=temp->prox;
	}
}

void opcaoMenu(node *LISTA,int op){
	switch(op){
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
		default:
			system("cls");
			printf("Olhe o menu direito!!!\n\n");
			break;
	}	
}

int menu(){
	int opcao=0;
	printf("Escolha uma das opcoes abaixo:\n");
	printf("0 - Sair\n");
	printf("1 - Inserir no inicio\n");
	printf("2 - Imprimir a lista\n");
	printf("3 - Inserir no fim\n");
	printf("Opcao: ");
	scanf("%d",&opcao);
	return opcao;	
}

void insereInicio(node* LISTA){
	node *novo=(node *)malloc(sizeof(node));
	printf("Idade por favor: ");
	scanf("%d",&novo->idade);
	
	node *temp=LISTA->prox;
	LISTA->prox=novo;
	novo->prox=temp;
}

int vazia(node* LISTA){
	if(LISTA->prox==NULL){
		return 1;
	}else{
		return 0;
	}
}

void iniciaLista(node *LISTA){
	LISTA->prox=NULL;
}


