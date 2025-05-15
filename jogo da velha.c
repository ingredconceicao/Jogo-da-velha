#include <stdio.h>
#include <stdlib.h>


char posicoes[3][3];


void tabuleiroJogo(){
	int i, j;
	char fully = ' ';
	
	for(i=1; i<4; i++){
		for (j=1; j<4; j++){
			posicoes[i][j]=fully;
		}
	}
	
	printf(" %c | %c | %c \n", posicoes[1][1], posicoes[1][2], posicoes[1][3]);
	printf("----------- \n");
	printf(" %c | %c | %c \n",posicoes[2][1], posicoes[2][2], posicoes[2][3]);
	printf("----------- \n");
	printf(" %c | %c | %c \n",posicoes[3][1], posicoes[3][2], posicoes[3][3]);
	
}

void andamentoJogo(){
	
	printf(" %c | %c | %c \n", posicoes[1][1], posicoes[1][2], posicoes[1][3]);
	printf("----------- \n");
	printf(" %c | %c | %c \n",posicoes[2][1], posicoes[2][2], posicoes[2][3]);
	printf("----------- \n");
	printf(" %c | %c | %c \n",posicoes[3][1], posicoes[3][2], posicoes[3][3]);
}

void inserePlayer01(char p1){
	int linha, coluna=0;
	
	printf("Player 01, escolha a linha e a coluna\n");
	scanf("%i", &linha);
	scanf("%i", &coluna);
	posicoes[linha][coluna]=p1;
}

void inserePlayer02(char p2){
	int linha, coluna=0;
	
	printf("Player 02, escolha a linha e a coluna\n");
	scanf("%i", &linha);
	scanf("%i", &coluna);
	posicoes[linha][coluna]=p2;
}

int main(int argc, char *argv[]) {
	
	char player1, player2;
	
 		 printf("Player 01, escolha 'X' ou 'O'\n");
  		 scanf(" %c", &player1);
	 	 printf("Player 02, escolha 'X' ou 'O'\n");
  	 	 scanf(" %c", &player2);
	  	 tabuleiroJogo();
		 printf("Inicio de jogo\n");
		 				 
	do{
		
		inserePlayer01(player1);
		andamentoJogo();
		inserePlayer02(player2);
		andamentoJogo();
						
	}while(1);

}
