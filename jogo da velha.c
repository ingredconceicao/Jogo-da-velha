#include <stdio.h>
#include <stdlib.h>


char posicoes[3][3];
int win=0;


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
	int quit=0;
	
	while(quit==0){
		printf("Player 01, escolha a linha e a coluna\n");
		scanf("%i", &linha);
		scanf("%i", &coluna);
			if(posicoes[linha][coluna]!=' '){
				printf("Posicao preenchida. Escolha outra\n");
			}else{
				posicoes[linha][coluna]=p1;
				quit=1;
			}
	}
	verificaVitoria(p1);
	
}

void inserePlayer02(char p2){
	int linha, coluna=0;
	int quit=0;
	
	while(quit==0){
		printf("Player 02, escolha a linha e a coluna\n");
		scanf("%i", &linha);
		scanf("%i", &coluna);
			if(posicoes[linha][coluna]!=' '){
				printf("Posicao preenchida. Escolha outra\n");
			}else{
				posicoes[linha][coluna]=p2;
				quit=1;
			}
	}
	verificaVitoria(p2);
		
}

void verificaVitoria(char p){
	switch (p){
		case'x':
			if(posicoes[1][1]=='x'&&posicoes[1][2]=='x'&&posicoes[1][3]=='x'||posicoes[2][1]=='x'&&posicoes[2][2]=='x'&&posicoes[2][3]=='x'
			||posicoes[3][1]=='x'&&posicoes[3][2]=='x'&&posicoes[3][3]=='x'||posicoes[1][1]=='x'&&posicoes[2][1]=='x'&&posicoes[3][1]=='x'
			||posicoes[1][2]=='x'&&posicoes[2][2]=='x'&&posicoes[3][2]=='x'||posicoes[1][3]=='x'&&posicoes[2][3]=='x'&&posicoes[3][3]=='x'
			||posicoes[1][1]=='x'&&posicoes[2][2]=='x'&&posicoes[3][3]=='x'||posicoes[1][3]=='x'&&posicoes[2][2]=='x'&&posicoes[3][1]=='x'){
				win=1;
				break;
			}
			
		case'o':
			if(posicoes[1][1]=='o'&&posicoes[1][2]=='o'&&posicoes[1][3]=='o'||posicoes[2][1]=='o'&&posicoes[2][2]=='o'&&posicoes[2][3]=='o'
			||posicoes[3][1]=='o'&&posicoes[3][2]=='o'&&posicoes[3][3]=='o'||posicoes[1][1]=='o'&&posicoes[2][1]=='o'&&posicoes[3][1]=='o'
			||posicoes[1][2]=='o'&&posicoes[2][2]=='o'&&posicoes[3][2]=='o'||posicoes[1][3]=='o'&&posicoes[2][3]=='o'&&posicoes[3][3]=='o'
			||posicoes[1][1]=='o'&&posicoes[2][2]=='o'&&posicoes[3][3]=='o'||posicoes[1][3]=='o'&&posicoes[2][2]=='o'&&posicoes[3][1]=='o'){
				win=1;
				break;
			}
	}
  	
}


int main(int argc, char *argv[]) {
	char player1, player2;
	int saida=0;
	int cont=0;
	
	while(saida==0){
		printf("Player 01, escolha 'X' ou 'O'\n");
  		 scanf(" %c", &player1);
			switch(player1){
				case 'x':
					printf("Player 02 jogara com 'o'\n");
					player2='o';
					saida=1;
					break;
				case 'o':
					printf("Player 02 jogara com 'x'\n");
					player2='x';
					saida=1;
					break;
				default:
					printf("Caractere Invalido. Escolha 'X' ou 'O'\n");
					break;
			}
	}	
 		tabuleiroJogo();
		printf("Inicio de jogo\n");	
					 
	do{
		
		inserePlayer01(player1);
		andamentoJogo();
			cont++;
			if(win==1){
				printf("Player 01 Venceu\n");
				break;
			}
			if (cont==9){
			printf("Deu velha\n");
				break;
		}		
		inserePlayer02(player2);
		andamentoJogo();
			cont++;
			if(win==1){
				printf("Player 02 Venceu\n");
				break;
			}		
	}while(saida==1);

}
