#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>



//Constantes que serao utilizadas ao decorer da aplicação.
#define MAX_TENTATIVAS 5
#define PONTUACAO_INICIAL 1000
#define PENALIDADE_ERRO 10
#define NUM_PALAVRAS 30
#define MAX_JOGOS 10

char* palavras[NUM_PALAVRAS] = {
    "CAUE", "KAIQUE", "BEATRIZ", "WALLACE", "GUSTAVO",
    "PROGRAMACAO", "DESENVOLVIMENTO", "APRENDIZAGEM", "COMPUTADOR", "TECNOLOGIA",
    "INTELIGENCIA", "SABEDORIA", "EXPERIENCIA", "CONHECIMENTO", "APRENDER",
    "FELICIDADE", "SUCESSO", "REALIZACAO", "CRESCIMENTO", "INSPIRACAO",
    "MOTIVACAO", "DETERMINACAO", "PERSISTENCIA", "OTIMISMO", "ESPERANCA",
    "AMOR", "PAZ", "ALEGRIA", "LIBERDADE", "HARMONIA"
};

//funcao de limpar a tela
void limparTela() {
    system("cls");
}


//Funcao que lista os Jogos
//Estrutura para armazenar as informações de cada jogo

typedef struct {
    int pontos;
    char palavra[20];
    int tentativas;
}Jogo;

Jogo jogos[MAX_JOGOS]; //vetor que armazena os jogos

int numJogos = 0; //variavel para acompanhar o numero atual de jogos

// Função para adicionar um novo jogo à lista
void adicionarJogo(int pontos, char palavra[], int tentativas){
    if (numJogos < MAX_JOGOS) {
        jogos[numJogos].pontos = pontos;
        strcpy(jogos[numJogos].palavra, palavra);
        jogos[numJogos].tentativas = tentativas;
        numJogos++;
    } else {
        printf("Limite máximo de jogos atingido!\n");
    }
}

// Função para listar todos os jogos jogados
void listarJogos() {
    limparTela();
    int voltar = 0;

    // printf("\n---- Jogos Jogados ----\n");
    // for (int i = 0; i < numJogos; i++) {
    //     printf("Jogo %d: Pontos ao final: %d, Palavra secreta: %s, Chances Usadas: %d\n", i + 1, jogos[i].pontos, jogos[i].palavra, jogos[i].tentativas);
    // }
    // printf("\n\033[1;36m  ->[press 1]<- :\033[m ");
    // scanf("%d",&voltar);
    // if(voltar == 1){
    //      main();
    // }
    // printf("-----------------------\n");
    printf("\n\033[1;34m---- Jogos Jogados ----\n\033[m");
    for (int i = 0; i < numJogos; i++) {
        printf("\033[1;32mJogo %d:\033[m \033[1;33mPontos ao final: %d\033[m, \033[1;35mPalavra secreta: %s\033[m, \033[1;36mChances Usadas: %d\033[m\n", i + 1, jogos[i].pontos, jogos[i].palavra, jogos[i].tentativas);
    }

    printf("\033[1;36m  ->[press 1]<- :\033[m ");
    scanf("%d",&voltar);
    if(voltar == 1){
         main();
    }
    printf("\033[1;34m-----------------------\n\033[m");
}





void exibirForca(int tentativas_erradas) {
    printf("\033[1;32m ________\n");
    printf("|       |\n");

    if (tentativas_erradas > 0)
        printf("|       O\n");
    else
        printf("|        \n");
    

    if (tentativas_erradas > 2)
        printf("|      \\|/\n");
    else if (tentativas_erradas > 1)
        printf("|      \\| \n");
    else if (tentativas_erradas > 0)
        printf("|       | \n");
    else
        printf("|        \n");

    if (tentativas_erradas > 4)
        printf("|      / \\\n");
    else if (tentativas_erradas > 3)
        printf("|      /  \n");
    else
        printf("|        \n");

    printf("|\n");
    printf("|________\n\n\033[m");
}

void game() {
    srand(time(NULL));

    char palavra_secreta[20];
    char palavra_descoberta[20];
    int tamanho_palavra, tentativas_restantes = MAX_TENTATIVAS;
    int letras_restantes;
    int letras_usadas[26] = {0}; // Inicializa todas as letras usadas como não usadas
    int pontuacao = PONTUACAO_INICIAL;

    // Seleciona uma palavra aleatória da lista
    strcpy(palavra_secreta, palavras[rand() % NUM_PALAVRAS]);
    tamanho_palavra = strlen(palavra_secreta);

    // Inicializa a palavra descoberta com underscores
    for (int i = 0; i < tamanho_palavra; i++)
        palavra_descoberta[i] = '_';
    palavra_descoberta[tamanho_palavra] = '\0';

    letras_restantes = tamanho_palavra; // Inicializa letras restantes

    limparTela(); // Limpa a tela no início do jogo

    // Loop principal do jogo
    while (tentativas_restantes > 0 && letras_restantes > 0) {
        limparTela(); // Limpa a tela a cada iteração do loop
        printf("\033[1;34mPalavra: %s\n", palavra_descoberta);
        printf("Tentativas restantes: %d\n", tentativas_restantes);
        printf("Pontuacao: %d\n", pontuacao);
        printf("Letras usadas:\033[m ");
        for (int i = 0; i < 26; i++) {
            if (letras_usadas[i]){
                printf("%c ", 'A' + i);
            }
        }
        printf("\n");

        exibirForca(MAX_TENTATIVAS - tentativas_restantes);

        char palpite;
        printf("Digite uma letra: ");
        scanf(" %c", &palpite);
        palpite = toupper(palpite); // Converte para maiúscula

        // Verifica se a letra já foi usada
        if (letras_usadas[palpite - 'A']) {
            printf("Você já usou essa letra. Tente outra.\n");
            continue;
        }

        letras_usadas[palpite - 'A'] = 1; // Marca a letra como usada

        int acertou = 0;
        // Verifica se a letra está na palavra secreta
        for (int i = 0; i < tamanho_palavra; i++) {
            if (palavra_secreta[i] == palpite) {
                if (palavra_descoberta[i] == '_') {
                    palavra_descoberta[i] = palpite;
                    acertou = 1;
                    letras_restantes--;
                }
            }
        }
        //condicao se o jogador venceu
        if (letras_restantes == 0) {
            limparTela(0);
            printf("\033[1;32mParabens! Voce venceu!\nA palavra era: \033[4m%s\n\033[m", palavra_secreta);
            printf("\033[1;33mSua pontuacao final: %d\n\033[m", pontuacao);

            adicionarJogo(pontuacao, palavra_secreta, MAX_TENTATIVAS - tentativas_restantes);

            break;
        }


        // Se o jogador errou, subtrai pontos
        if (!acertou) {
            tentativas_restantes--;
            pontuacao -= PENALIDADE_ERRO;
            printf("Letra errada! Você perdeu %d pontos.\n", PENALIDADE_ERRO);
            printf("Pontuação atual: %d\n", pontuacao);
        }
    }

    // Se o jogador perdeu
    if (tentativas_restantes == 0) {
        limparTela();
        printf("\033[1;31mVoce perdeu! A palavra era: \033[4m%s\n", palavra_secreta);
        printf("Sua pontuação final: %d\n/033[m", pontuacao);
        exibirForca(MAX_TENTATIVAS);
    }
    
    int escolha;
    printf("\033[1;32mDeseja voltar ao menu principal? \033[4m(1 - Sim, \033[91m0 - Nao):\033[m ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        main(); // Retorna ao menu principal
    } else {
        printf("\033[1;32m\nSee you later.....\033[m");
        exit(0); // Sai do jogo
    }

    
}

void imprimirCreditos(){
    limparTela();
    int voltar = 0;
    printf("====Creditos====\n\033[1;32mBeatriz de Abreu \nCaue Ramos \nKaique\nWallace \nGustavo \n\033[m");
    printf("\n\033[1;36m  ->[press 1]<- :\033[m ");
    scanf("%d",&voltar);
    if(voltar == 1){
         main();
    }

}

// menu
void exibirMenu(){
    limparTela(1);
    printf("\033[1;32;44m================================================\033[m\n");
    printf("\033[1;32;44m---------------Game da forca v2.0---------------\033[m\n");
    printf("\033[1;32;44m================================================\033[m\n");
    printf("\033[1;32m 1-> Jogar \033[m\n");
    printf("\033[1;33m 2-> Creditos \033[m\n");
    printf("\033[1;36m 3-> Listar Jogos \033[m\n");
    printf("\033[1;31m 0-> Sair \033[m\n");
}

int main(){
    int opcao;

    do{
        exibirMenu();
        printf("\033[1;97m Opcao desejada: \033[m");
        scanf("%d",&opcao);

        //procesando a escolha
        switch (opcao){
            case 1:
                game();
                break;
            case 2:
                imprimirCreditos();
                opcao = -1;
                break;
            case 3:
                listarJogos();
                break;
            case 0:
                break;
        }
    }while (opcao != 0);
    printf("\033[1;32m\nSee you later.....\033[m");

    return 0;
}
