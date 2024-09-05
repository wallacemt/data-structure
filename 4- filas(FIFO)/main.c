#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó na fila
typedef struct node
{
    int value;         // Valor armazenado no nó
    struct node *next; // Ponteiro para o próximo nó na fila
} Node;

// Função para inserir um novo nó na fila
void insertNode(Node **fila, int num)
{
    system("cls"); // Limpa a tela (para sistemas Unix-like)

    // Aloca memória para o novo nó
    Node *aux, *new = malloc(sizeof(Node));
    if (new)
    {
        new->value = num; // Define o valor do novo nó
        new->next = NULL; // O próximo nó é NULL no início

        // Se a fila estiver vazia, o novo nó será o primeiro
        if (*fila == NULL)
        {
            *fila = new;
        }
        else
        {
            // Caso contrário, percorre a fila até o último nó
            aux = *fila;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            // Adiciona o novo nó no final da fila
            aux->next = new;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria.\n"); // Mensagem de erro caso falhe a alocação
    }
}

// Função para remover um nó da fila
Node *removeNode(Node **fila)
{
    system("cls"); // Limpa a tela (para sistemas Unix-like)

    Node *remover = NULL;

    // Se a fila não estiver vazia, remove o primeiro nó
    if (*fila)
    {
        remover = *fila;       // O nó a ser removido é o primeiro
        *fila = remover->next; // O próximo nó da fila passa a ser o novo primeiro
    }
    else
    {
        printf("\tFila vazia\n "); // Mensagem de erro caso a fila esteja vazia
    }

    return remover; // Retorna o nó removido
}

// Função para imprimir todos os nós na fila
void printFila(Node *fila)
{
    system("cls"); // Limpa a tela (para sistemas Unix-like)

    printf("-------- FILA ----------\n");
    int i = 1;

    // Percorre a fila e imprime os valores dos nós
    while (fila)
    {
        printf("%d - %d \n", i, fila->value);
        fila = fila->next; // Move para o próximo nó
        i++;
    }

    printf("-------- FIM FILA ----------\n");
}

int main()
{
    Node *r, *fila = NULL; // Inicializa a fila como NULL
    int opcao, valor;

    // Loop principal para interação com o usuário
    do
    {
        // Menu de opções
        printf("\n\t0 - Sair\n\t1 - Inserir Dado\n\t2 - Remover Dado\n\t3 - Imprimir FILA\n\tEscolha uma opcao: ");
        scanf("%d", &opcao); // Lê a opcao do usuário

        // Executa a ação correspondente à opcao escolhida
        switch (opcao)
        {
        case 1:
            printf("Digite um valor!:");
            scanf("%d", &valor);
            insertNode(&fila, valor); // Insere o valor na fila
            break;
        case 2:
            r = removeNode(&fila); // Remove o nó da fila
            if (r != NULL)
            {
                printf("Removido: %d\n", r->value); // Imprime o valor do nó removido
                free(r);                            // Libera a memória do nó removido
            }
            break;
        case 3:
            printFila(fila); // Imprime todos os nós na fila
            break;
        default:
            if (opcao != 0)
            {
                printf("opcao Invalida!"); // Mensagem para opções inválidas
            }
        }
    } while (opcao != 0); // Continua até que o usuário escolha sair

    return 0;
}
