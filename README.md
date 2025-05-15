# Jogo da Velha em C
Objetivo:
Desenvolver um programa em linguagem C que implemente o clássico jogo da velha com todas as funcionalidades descritas abaixo.

# Requisitos Funcionais 

# 1. Tabuleiro do Jogo
• Implementar um tabuleiro 3x3 usando uma matriz bidimensional de caracteres
- Inicializar todas as posições do tabuleiro com espaços em branco
- Exibir o tabuleiro formatado com linhas divisórias entre as células

# 2. Mecânica do Jogo
• Alternar entre dois jogadores (Jogador 1 como 'X' e Jogador 2 como 'O')
- Permitir que cada jogador insira sua jogada informando linha e coluna (0 a 2)
- Validar se a posição escolhida está vazia e dentro dos limites do tabuleiro
- Contabilizar o número de jogadas realizadas

# 3. Verificação de Vitória
• Implementar lógica para verificar todas as possibilidades de vitória:
- Linhas horizontais completas
- Colunas verticais completas
- Diagonais completas
- Identificar o jogador vencedor quando houver três símbolos iguais em linha
- Encerrar o jogo imediatamente quando um vencedor for identificado

# 4. Tratamento de Empate
• Detectar quando todas as posições do tabuleiro estiverem preenchidas sem vencedor
- Contabilizar o empate no placar geral

# 5. Sitema de placar
• Manter registro permanente das estatísticas do jogo:
- Número de vitórias do jogador X
- Número de vitórias do jogador O
- Número de empates

# 6. Interface do Usuário
- Exibir mensagens claras indicando de qual jogador é a vez
- Informar quando ocorrer jogadas inválidas
- Mostrar mensagem de vitória ou empate ao final de cada partida
- Apresentar o tabuleiro após cada jogada válida
  


