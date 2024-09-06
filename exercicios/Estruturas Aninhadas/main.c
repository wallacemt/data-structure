#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pilha de valores no cofre
typedef struct Pilha {
    float valor;
    struct Pilha *prox;
} Pilha;

// Definição da estrutura do cofre
typedef struct Cofre {
    int numero; // Número identificador do cofre
    Pilha *pilhaValores; // Ponteiro para a pilha de valores
    struct Cofre *prox;
} Cofre;

// Definição da estrutura da pessoa
typedef struct {
    char nome[50];
    Cofre *cofre; // Ponteiro para o cofre
} Pessoa;

// Definição da estrutura do nó da lista
typedef struct Node {
    Pessoa p;
    struct Node *prox;
} Node;

typedef Node node;

// Funções de manipulação da lista
void iniciaLista(node *LISTA);
int vazia(node *LISTA);
void insereInicio(node *LISTA);
void insereFim(node *LISTA);
void insereMeio(node *LISTA);
void imprimeLista(node *LISTA);
void removeNode(node *LISTA);

// Funções para manipular cofres e pilhas
void adicionaCofre(Pessoa *p);
void adicionaValorCofre(Cofre *c);
void imprimeCofres(Cofre *c);
void mostraValoresCofre(Cofre *c);

// Funções auxiliares
int menu(void);
void opcaoMenu(node *LISTA, int op);

int main() {
    node *LISTA = (node *)malloc(sizeof(node));
    if (LISTA == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }
    iniciaLista(LISTA);

    int opcao;
    do {
        opcao = menu();
        opcaoMenu(LISTA, opcao);
    } while (opcao != 0);

    free(LISTA);
    return 0;
}

// Inicializa a lista
void iniciaLista(node *LISTA) {
    LISTA->prox = NULL;
}

// Verifica se a lista está vazia
int vazia(node *LISTA) {
    return LISTA->prox == NULL;
}

// Insere um nó no início da lista
void insereInicio(node *LISTA) {
    node *novo = (node *)malloc(sizeof(node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return;
    }
    printf("Nome por favor: ");
    scanf("%s", novo->p.nome);

    // Inicializa o cofre da pessoa
    novo->p.cofre = NULL;
    adicionaCofre(&novo->p);

    novo->prox = LISTA->prox;
    LISTA->prox = novo;
}

// Insere um nó no final da lista
void insereFim(node *LISTA) {
    node *novo = (node *)malloc(sizeof(node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return;
    }
    printf("Nome por favor: ");
    scanf("%s", novo->p.nome);

    // Inicializa o cofre da pessoa
    novo->p.cofre = NULL;
    adicionaCofre(&novo->p);

    novo->prox = NULL;

    if (vazia(LISTA)) {
        LISTA->prox = novo;
    } else {
        node *temp = LISTA->prox;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

// Remove um nó da lista
void removeNode(node *LISTA) {
    char nome[50];
    printf("Qual elemento deseja remover (nome)?: ");
    scanf("%s", nome);

    node *temp = LISTA;
    node *suc = NULL;
    while (temp->prox != NULL && strcmp(temp->prox->p.nome, nome) != 0) {
        temp = temp->prox;
    }

    if (temp->prox != NULL) {
        node *remover = temp->prox;
        suc = remover->prox;
        temp->prox = suc;
        free(remover);
    } else {
        printf("Nome não encontrado.\n");
    }
}

void removerValorDoCofre(){
    char nome[50];
    printf("Qual nome deseja remover (nome)?: ");
    scanf("%s", nome);

    node *temp = LISTA;
    node *suc = NULL;
    while (temp->prox != NULL && strcmp(temp->prox->p.nome, nome) != 0) {
        temp = temp->prox;
    }

    if (temp->prox != NULL) {
        node *remover = temp->prox;
        suc = remover->prox;
        temp->prox = suc;
        free(remover);
    } else {
        printf("Nome não encontrado.\n");
    }  
}
// Adiciona um cofre à pessoa
void adicionaCofre(Pessoa *p) {
    Cofre *novoCofre = (Cofre *)malloc(sizeof(Cofre));
    if (novoCofre == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o cofre.\n");
        return;
    }
    printf("Número do cofre para %s: ", p->nome);
    scanf("%d", &novoCofre->numero);
    novoCofre->pilhaValores = NULL;
    novoCofre->prox = p->cofre;
    p->cofre = novoCofre;
}

// Adiciona um valor à pilha de um cofre
void adicionaValorCofre(Cofre *c) {
    Pilha *novoValor = (Pilha *)malloc(sizeof(Pilha));
    if (novoValor == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o valor.\n");
        return;
    }
    printf("Valor a adicionar ao cofre %d: ", c->numero);
    scanf("%f", &novoValor->valor);
    novoValor->prox = c->pilhaValores;
    c->pilhaValores = novoValor;
}

// Imprime todos os cofres de uma pessoa
void imprimeCofres(Cofre *c) {
    if (c == NULL) {
        printf("Nenhum cofre encontrado.\n");
        return;
    }
    while (c != NULL) {
        printf("Cofre número: %d\n", c->numero);
        mostraValoresCofre(c);
        c = c->prox;
    }
}

// Mostra todos os valores armazenados em um cofre
void mostraValoresCofre(Cofre *c) {
    Pilha *p = c->pilhaValores;
    if (p == NULL) {
        printf("Nenhum valor encontrado no cofre %d.\n", c->numero);
        return;
    }
    printf("Valores no cofre %d:\n", c->numero);
    while (p != NULL) {
        printf("Valor: %.2f\n", p->valor);
        p = p->prox;
    }
}

// Insere um nó em uma posição específica na lista
void insereMeio(node *LISTA) {
    char nome[50];
    printf("Nome por favor: ");
    scanf("%s", nome);

    node *novo = (node *)malloc(sizeof(node));
    if (novo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return;
    }
    strcpy(novo->p.nome, nome);

    // Inicializa o cofre da pessoa
    novo->p.cofre = NULL;
    adicionaCofre(&novo->p);

    printf("Inserir depois de qual nome: ");
    scanf("%s", nome);

    node *temp = LISTA;
    while (temp != NULL && temp->prox != NULL && strcmp(temp->prox->p.nome, nome) != 0) {
        temp = temp->prox;
    }

    if (temp != NULL) {
        novo->prox = temp->prox;
        temp->prox = novo;
    } else {
        printf("Nome não encontrado.\n");
        free(novo);
    }
}

// Imprime todos os elementos da lista
void imprimeLista(node *LISTA) {
    node *temp = LISTA->prox;
    printf("Conteudo da lista:\n");
    while (temp != NULL) {
        printf("Nome: %s\n", temp->p.nome);
        imprimeCofres(temp->p.cofre);
        temp = temp->prox;
    }
    printf("-----------------\n");
}

// Função para exibir o menu
int menu(void) {
    int opcao;
    printf("Escolha uma das opcoes abaixo:\n");
    printf("0 - Sair\n");
    printf("1 - Inserir no inicio\n");
    printf("2 - Imprimir a lista\n");
    printf("3 - Inserir no fim\n");
    printf("4 - Inserir no meio\n");
    printf("5 - Remover Elemento\n");
    printf("6 - Adicionar valor ao cofre\n");
    printf("7 - Mostrar valores de um cofre\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Executa a opção selecionada no menu
void opcaoMenu(node *LISTA, int op) {
    switch (op) {
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
    case 6: {
        system("clear");
        int numeroCofre;
        printf("Digite o número do cofre para adicionar valor: ");
        scanf("%d", &numeroCofre);

        node *temp = LISTA->prox;
        while (temp != NULL) {
            Cofre *c = temp->p.cofre;
            while (c != NULL) {
                if (c->numero == numeroCofre) {
                    adicionaValorCofre(c);
                    break;
                }
                c = c->prox;
            }
            temp = temp->prox;
        }
        break;
    }
    case 7: {
        system("clear");
        int numeroCofre;
        printf("Digite o número do cofre para mostrar valores: ");
        scanf("%d", &numeroCofre);

        node *temp = LISTA->prox;
        while (temp != NULL) {
            Cofre *c = temp->p.cofre;
            while (c != NULL) {
                if (c->numero == numeroCofre) {
                    mostraValoresCofre(c);
                    break;
                }
                c = c->prox;
            }
            temp = temp->prox;
        }
        break;
    }
    case 0:
        // Caso para sair, não faz nada
        break;
    default:
        system("clear");
        printf("Opção inválida! Por favor, escolha uma opção do menu.\n\n");
        break;
    }
}