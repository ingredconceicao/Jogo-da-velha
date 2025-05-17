# 🎮 Jogo da Velha em C

Jogo da velha desenvolvido em linguagem C. Dois jogadores alternam suas jogadas em um tabuleiro 3x3, com verificação automática de vitórias, empates e placar acumulado.

---

## 🧠 Objetivo

Implementar o clássico jogo da velha com todas as regras, validações e um sistema de placar. Ideal para treinar lógica, manipulação de matrizes e interação com o usuário via terminal.

---

## ✅ Funcionalidades

### 🎲 Tabuleiro

- Tabuleiro 3x3 representado por uma matriz bidimensional de caracteres.
- Inicialização com espaços em branco.
- Impressão formatada com divisórias entre as células.

### 👥 Mecânica do Jogo

- Dois jogadores:  
  - Jogador 1: `X`  
  - Jogador 2: `O`
- Entrada da jogada via linha e coluna (valores de 1 a 4).
- Validação de jogadas:
  - Apenas posições vazias.
  - Dentro dos limites do tabuleiro.
- Atualização do tabuleiro após cada jogada válida.

### 🏆 Verificação de Vitória

- Checagem automática das condições de vitória:
  - Três símbolos iguais em uma **linha**, **coluna** ou **diagonal**.
- Anúncio imediato do vencedor e encerramento da partida.

### 🤝 Empates

- Reconhecimento automático de empate caso todas as posições sejam preenchidas sem um vencedor.
- Empate contabilizado no placar geral.

### 📊 Placar

- Registro das estatísticas ao longo das partidas:
  - Vitórias do jogador `X`
  - Vitórias do jogador `O`
  - Total de empates

### 🧾 Interface do Usuário

- Mensagens claras e orientativas:
  - De quem é a vez
  - Quando uma jogada é inválida
  - Resultado da partida (vitória ou empate)
- Exibição do tabuleiro após cada jogada válida.

---

## 🖼️ Exemplo de Saída Esperada

```text
   1   2   3
1  X | O |  
  -----------
2    | X |  
  -----------
3   |   | O

Vez do jogador X



