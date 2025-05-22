#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jogadores {
    char nome[50];
    int vitorias;
    int derrotas;
    int empates;
};

char posicoes[3][3];
int win = 0;
char nomeP1[50];
char nomeP2[50];
int placarP1 = 0;
int placarP2 = 0;
int jogarNovamente = 1;
int numeroJogadores = 0;

void salvarRanking(struct Jogadores jogador[]) {
    FILE *arquivo = fopen("placar.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de ranking!\n");
        return;
    }

    fprintf(arquivo, "%s. V: %d D: %d E: %d\n", jogador[numeroJogadores].nome,
            jogador[numeroJogadores].vitorias,
            jogador[numeroJogadores].derrotas,
            jogador[numeroJogadores].empates);

    fprintf(arquivo, "%s. V: %d D: %d E: %d\n", jogador[numeroJogadores + 1].nome,
            jogador[numeroJogadores + 1].vitorias,
            jogador[numeroJogadores + 1].derrotas,
            jogador[numeroJogadores + 1].empates);

    fclose(arquivo);
    printf("Resultado salvo no ranking!\n");
}

void mostrarRanking() {
    FILE *arquivo = fopen("placar.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum ranking encontrado ainda!\n");
        return;
    }

    printf("\n=== RANKING COMPLETO ===\n");
    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

void nomeJog() {
    printf("Jogador 01 digite seu nome: ");
    scanf(" %[^\n]", nomeP1);

    printf("Jogador 02 digite seu nome: ");
    scanf(" %[^\n]", nomeP2);
}

void tabuleiroJogo() {
    int i, j;
    char fully = ' ';

    for (i = 1; i < 4; i++) {
        for (j = 1; j < 4; j++) {
            posicoes[i][j] = fully;
        }
    }

    printf("  1    2    3 \n");
    printf("1 %c | %c  | %c \n", posicoes[1][1], posicoes[1][2], posicoes[1][3]);
    printf("-------------- \n");
    printf("2 %c | %c  | %c \n", posicoes[2][1], posicoes[2][2], posicoes[2][3]);
    printf("-------------- \n");
    printf("3 %c | %c  | %c \n", posicoes[3][1], posicoes[3][2], posicoes[3][3]);
}

void andamentoJogo() {
    printf("  1    2    3 \n");
    printf("1 %c | %c  | %c \n", posicoes[1][1], posicoes[1][2], posicoes[1][3]);
    printf("-------------- \n");
    printf("2 %c | %c  | %c \n", posicoes[2][1], posicoes[2][2], posicoes[2][3]);
    printf("-------------- \n");
    printf("3 %c | %c  | %c \n", posicoes[3][1], posicoes[3][2], posicoes[3][3]);
}


void verificaVitoria(char p) {
    switch (p) {
        case 'x':
            if ((posicoes[1][1] == 'x' && posicoes[1][2] == 'x' && posicoes[1][3] == 'x') ||
                (posicoes[2][1] == 'x' && posicoes[2][2] == 'x' && posicoes[2][3] == 'x') ||
                (posicoes[3][1] == 'x' && posicoes[3][2] == 'x' && posicoes[3][3] == 'x') ||
                (posicoes[1][1] == 'x' && posicoes[2][1] == 'x' && posicoes[3][1] == 'x') ||
                (posicoes[1][2] == 'x' && posicoes[2][2] == 'x' && posicoes[3][2] == 'x') ||
                (posicoes[1][3] == 'x' && posicoes[2][3] == 'x' && posicoes[3][3] == 'x') ||
                (posicoes[1][1] == 'x' && posicoes[2][2] == 'x' && posicoes[3][3] == 'x') ||
                (posicoes[1][3] == 'x' && posicoes[2][2] == 'x' && posicoes[3][1] == 'x')) {
                win = 1;
                break;
            }
        case 'o':
            if ((posicoes[1][1] == 'o' && posicoes[1][2] == 'o' && posicoes[1][3] == 'o') ||
                (posicoes[2][1] == 'o' && posicoes[2][2] == 'o' && posicoes[2][3] == 'o') ||
                (posicoes[3][1] == 'o' && posicoes[3][2] == 'o' && posicoes[3][3] == 'o') ||
                (posicoes[1][1] == 'o' && posicoes[2][1] == 'o' && posicoes[3][1] == 'o') ||
                (posicoes[1][2] == 'o' && posicoes[2][2] == 'o' && posicoes[3][2] == 'o') ||
                (posicoes[1][3] == 'o' && posicoes[2][3] == 'o' && posicoes[3][3] == 'o') ||
                (posicoes[1][1] == 'o' && posicoes[2][2] == 'o' && posicoes[3][3] == 'o') ||
                (posicoes[1][3] == 'o' && posicoes[2][2] == 'o' && posicoes[3][1] == 'o')) {
                win = 1;
                break;
            }
    }
}

void inserePlayer01(char p1) {
    int linha, coluna = 0;
    int quit = 0;

    while (quit == 0) {
        printf("%s, escolha a linha e a coluna\n", nomeP1);
        scanf("%i", &linha);
        scanf("%i", &coluna);
        if (posicoes[linha][coluna] != ' ') {
            printf("Posicao preenchida. Escolha outra\n");
        } else {
            posicoes[linha][coluna] = p1;
            quit = 1;
        }
    }
    verificaVitoria(p1);
}

void inserePlayer02(char p2) {
    int linha, coluna = 0;
    int quit = 0;

    while (quit == 0) {
        printf("%s, escolha a linha e a coluna\n", nomeP2);
        scanf("%i", &linha);
        scanf("%i", &coluna);
        if (posicoes[linha][coluna] != ' ') {
            printf("Posicao preenchida. Escolha outra\n");
        } else {
            posicoes[linha][coluna] = p2;
            quit = 1;
        }
    }
    verificaVitoria(p2);
}


void mostrarPlacar() {
    printf("\n==== PLACAR ====\n");
    printf("%s: %d pontos\n", nomeP1, placarP1);
    printf("%s: %d pontos\n", nomeP2, placarP2);
    printf("================\n\n");
}

int main(int argc, char *argv[]) {
    char player1, player2;
    int saida = 0;
    int cont = 0;
    int escolha = 0;
    struct Jogadores jogador[100];

    printf("Bem vindo ao Jogo da Velha\n1 - Ver ranking\n2 - Iniciar o jogo\n");
    scanf("%i", &escolha);

while(escolha!=0){
	switch(escolha){
		case 1:
			 mostrarRanking();
        	printf("Digite 0 para continuar\n");
        	scanf("%i", &escolha);
        	system("cls");
			break;
		case 2:
			escolha=0;
			break;
		default:
			printf("Opcao invalida. Digite 1 ou 2\n");
			scanf("%i", &escolha);
	}
}
	system("cls");
    nomeJog();
    strcpy(jogador[numeroJogadores].nome, nomeP1);
    	jogador[numeroJogadores].vitorias = 0;
		jogador[numeroJogadores].derrotas = 0;
		jogador[numeroJogadores].empates = 0;	
    strcpy(jogador[numeroJogadores + 1].nome, nomeP2);
    	jogador[numeroJogadores + 1].vitorias = 0;
		jogador[numeroJogadores + 1].derrotas = 0;
		jogador[numeroJogadores + 1].empates = 0;

    while (saida == 0) {
        printf("%s, escolha 'X' ou 'O'\n", nomeP1);
        scanf(" %c", &player1);
        switch (player1) {
            case 'x':
                printf("%s jogara com 'o'\n", nomeP2);
                player2 = 'o';
                saida = 1;
                break;
            case 'o':
                printf("%s jogara com 'x'\n", nomeP2);
                player2 = 'x';
                saida = 1;
                break;
            default:
                printf("Caractere invalido. Escolha 'X' ou 'O'\n");
                break;
        }
    }
	system("cls");
    while (jogarNovamente != 0) {
        tabuleiroJogo();
        printf("Inicio de jogo\n");
        cont = 0;
        do {
            inserePlayer01(player1);
            andamentoJogo();
            cont++;
            if (win == 1) {
                printf("%s venceu!\n", nomeP1);
                placarP1++;
                jogador[numeroJogadores].vitorias++;
                jogador[numeroJogadores + 1].derrotas++;
                break;
            }
            if (cont == 9) {
                printf("Deu velha!\n");
                jogador[numeroJogadores].empates++;
                jogador[numeroJogadores + 1].empates++;
                break;
            }

            inserePlayer02(player2);
            andamentoJogo();
            cont++;
            if (win == 1) {
                printf("%s venceu!\n", nomeP2);
                placarP2++;
                jogador[numeroJogadores].derrotas++;
                jogador[numeroJogadores + 1].vitorias++;
                break;
            }

        } while (saida == 1);

        mostrarPlacar();

        printf("Deseja jogar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%i", &jogarNovamente);
        if (jogarNovamente == 2) {
            jogarNovamente = 0;
        }
		system("cls");
        win = 0;
    }
	salvarRanking(jogador);
    return 0;
}

