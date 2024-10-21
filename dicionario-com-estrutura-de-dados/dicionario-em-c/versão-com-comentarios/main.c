#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Estruturas
typedef struct Nodo {
    char palavra[50];
    char traducao[50];
    char tipo[30];  // Ex: substantivo, adjetivo
    char fraseExemplo[100];
    struct Nodo *proximo;
} Nodo;

typedef struct NodoArvore {
    char palavra[50];
    char traducao[50];
    char tipo[30];
    char fraseExemplo[100];
    struct NodoArvore *esquerda;
    struct NodoArvore *direita;
} NodoArvore;

// Funcoes de Lista Encadeada
void cadastrarPalavra(Nodo **raiz, NodoArvore **arvore);
void listarPalavras(Nodo *raiz);
void excluirPalavra(Nodo **raiz, char *palavra);

// Funcoes de arvore Binaria
NodoArvore* buscarPalavra(NodoArvore *raiz, char *palavra);
void alterarPalavra(NodoArvore *raiz, char *palavra);
NodoArvore* inserirArvore(NodoArvore *raiz, Nodo *nova);

// Funcao para limpar a tela
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Funcao de Validacao de Entrada
int lerOpcao() {
    int opcao;
    while (1) {
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, insira um numero.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
        } else {
            break;
        }
    }
    return opcao;
}

// Funcao para ler strings com seguranca
void lerString(char *str, int tamanho) {
    fgets(str, tamanho, stdin);
    str[strcspn(str, "\n")] = '\0';  // Remove a quebra de linha do final
}

// Funcao de Comparacao de Strings (insensível a maiusculas)
int comparaStrings(const char *str1, const char *str2) {
    return strcasecmp(str1, str2);  // Comparacao sem diferenciar maiusculas de minusculas
}

// Funcao do Menu
void menu(Nodo **lista, NodoArvore **arvore) {
    int opcao;
    char palavra[50];
    
    do {
        limparTela();  // Limpa a tela ao entrar no menu
        printf("\n--- MENU DICIONARIO ---\n");
        printf("1. Cadastrar Palavra\n");
        printf("2. Listar Palavras\n");
        printf("3. Buscar Palavra\n");
        printf("4. Alterar Palavra\n");
        printf("5. Excluir Palavra\n");
        printf("0. Sair\n");
        
        opcao = lerOpcao();
        
        switch (opcao) {
            case 1:
                cadastrarPalavra(lista, arvore);
                limparTela();  // Limpa a tela apos o cadastro
                break;
            case 2:
                listarPalavras(*lista);
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                getchar();  // Aguarda o usuario pressionar Enter
                limparTela();  // Limpa a tela ao retornar ao menu
                break;
            case 3:
                printf("Digite a palavra a ser buscada: ");
                getchar();  // Limpa o buffer de entrada
                lerString(palavra, 50);
                NodoArvore *encontrada = buscarPalavra(*arvore, palavra);
                if (encontrada != NULL) {
                    printf("\nPalavra encontrada!\n");
                    printf("Palavra: %s\n", encontrada->palavra);
                    printf("Traducao: %s\n", encontrada->traducao);
                    printf("Tipo gramatical: %s\n", encontrada->tipo);
                    printf("Frase de exemplo: %s\n", encontrada->fraseExemplo);
                } else {
                    printf("Palavra nao encontrada.\n");
                }
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                limparTela();  // Limpa a tela ao retornar
                break;
            case 4:
                printf("Digite a palavra a ser alterada: ");
                getchar();  // Limpa o buffer de entrada
                lerString(palavra, 50);
                alterarPalavra(*arvore, palavra);
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                limparTela();  // Limpa a tela ao retornar
                break;
            case 5:
                printf("Digite a palavra a ser excluída: ");
                getchar();  // Limpa o buffer de entrada
                lerString(palavra, 50);
                excluirPalavra(lista, palavra);
                printf("\nPressione Enter para voltar ao menu...");
                getchar();
                limparTela();  // Limpa a tela ao retornar
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Funcoes Implementadas
void cadastrarPalavra(Nodo **lista, NodoArvore **arvore) {
    Nodo *nova = (Nodo*)malloc(sizeof(Nodo));
    
    if (nova == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }

    getchar();  // Limpa o buffer de entrada

    printf("Digite a palavra: ");
    lerString(nova->palavra, 50);
    printf("Digite a traducao em ingles: ");
    lerString(nova->traducao, 50);
    printf("Digite o tipo gramatical (ex: substantivo, adjetivo): ");
    lerString(nova->tipo, 30);
    printf("Digite uma frase de exemplo: ");
    lerString(nova->fraseExemplo, 100);
    
    nova->proximo = *lista;  // Adiciona no início da lista
    *lista = nova;

    // Insere na arvore
    *arvore = inserirArvore(*arvore, nova);
    
    printf("Palavra cadastrada com sucesso!\n");
}

void listarPalavras(Nodo *raiz) {
    Nodo *atual = raiz;
    if (atual == NULL) {
        printf("Nenhuma palavra cadastrada.\n");
        return;
    }
    
    while (atual != NULL) {
        printf("\nPalavra: %s\n", atual->palavra);
        printf("Traducao: %s\n", atual->traducao);
        printf("Tipo gramatical: %s\n", atual->tipo);
        printf("Frase de exemplo: %s\n", atual->fraseExemplo);
        printf("------------------------\n");
        atual = atual->proximo;
    }
}

NodoArvore* buscarPalavra(NodoArvore *raiz, char *palavra) {
    if (raiz == NULL || comparaStrings(raiz->palavra, palavra) == 0)
        return raiz;
    
    if (comparaStrings(palavra, raiz->palavra) < 0)
        return buscarPalavra(raiz->esquerda, palavra);
    
    return buscarPalavra(raiz->direita, palavra);
}

void alterarPalavra(NodoArvore *raiz, char *palavra) {
    NodoArvore *encontrado = buscarPalavra(raiz, palavra);
    if (encontrado != NULL) {
        printf("Palavra encontrada: %s\n", encontrado->palavra);
        printf("Traducao atual: %s\n", encontrado->traducao);
        printf("Tipo Granamatical atual: %s\n", encontrado->tipo);
        printf("Frase de exemplo atual: %s\n", encontrado->fraseExemplo);
        
        int opcao;
        do {
            printf("\nO que voce deseja alterar?\n");
            printf("1. Alterar traducao\n");
            printf("2. Alterar tipo gramatical\n");
            printf("3. Alterar frase de exemplo\n");
            printf("0. Voltar\n");
            opcao = lerOpcao();

            getchar();
            switch (opcao) {
                case 1:
                    printf("Digite a nova traducao: ");
                    lerString(encontrado->traducao, 50);
                    printf("Traducao alterada com sucesso!\n");
                    break;
                case 2:
                    printf("Digite o novo tipo gramatical: ");
                    lerString(encontrado->tipo, 30);
                    printf("Tipo gramatical alterado com sucesso!\n");
                    break;
                case 3:
                    printf("Digite a nova frase de exemplo: ");
                    lerString(encontrado->fraseExemplo, 100);
                    printf("Frase de exemplo alterada com sucesso!\n");
                    break;
                case 0:
                    printf("Voltando ao menu.\n");
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
            }
        } while (opcao != 0);
    } else {
        printf("Palavra nao encontrada.\n");
    }
}

void excluirPalavra(Nodo **raiz, char *palavra) {
    Nodo *atual = *raiz;
    Nodo *anterior = NULL;
    
    while (atual != NULL && comparaStrings(atual->palavra, palavra) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    
    if (atual == NULL) {
        printf("Palavra nao encontrada.\n");
        return;
    }
    
    if (anterior == NULL) { // A palavra esta no primeiro no
        *raiz = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    free(atual);  // Libera a memoria
    printf("Palavra excluída com sucesso.\n");
}

// Funcao para inserir uma palavra na arvore binaria
NodoArvore* inserirArvore(NodoArvore *raiz, Nodo *nova) {
    if (raiz == NULL) {
        NodoArvore *novoNodo = (NodoArvore*)malloc(sizeof(NodoArvore));
        if (novoNodo == NULL) {
            printf("Erro de alocacao de memoria!\n");
            return NULL;
        }
        strcpy(novoNodo->palavra, nova->palavra);
        strcpy(novoNodo->traducao, nova->traducao);
        strcpy(novoNodo->tipo, nova->tipo);
        strcpy(novoNodo->fraseExemplo, nova->fraseExemplo);
        novoNodo->esquerda = novoNodo->direita = NULL;
        return novoNodo;
    }
    
    if (comparaStrings(nova->palavra, raiz->palavra) < 0) {
        raiz->esquerda = inserirArvore(raiz->esquerda, nova);
    } else {
        raiz->direita = inserirArvore(raiz->direita, nova);
    }
    return raiz;
}

// Funcao principal
int main() {
    Nodo *lista = NULL;      // Inicializa a lista encadeada
    NodoArvore *arvore = NULL; // Inicializa a arvore binaria

    menu(&lista, &arvore);

    return 0;
}
