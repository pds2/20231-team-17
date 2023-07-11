<h1 align="center">TERMO</h1>

### Jogo de adivinhação de palavras (inspirado no jogo Termo)


# Descrição:
Termo é um jogo de palavras no qual os jogadores devem tentar adivinhar a palavra criando uma sequência de palavras relacionadas, conectando uma palavra à outra, usando apenas uma letra em cada palavra.

## Mecânica do jogo: 
O jogo começa com uma palavra inicial (oculta) e o objetivo dos jogadores é adivinhá-la tentando uma cadeia de palavras, usando apenas palavras existentes na língua portuguesa. A cada tentativa o sistema mostrará se o jogador acertou a palavra, se acertou alguma letra ou se tentou enviar alguma palavra que não exista.

Nessa implementação acentos são considerados, portanto á e a são consideradas letras diferentes, e para acertar uma palavra com acento tenho q escreve-la com acento no meu palpite.

Outra particularidade é que como nosso banco de palavras não possui todas as plavras da língua portuguesa, caso o  usuário digite uma palavra que não consta no nosso banco, a tentativa é desconsiderada e é pedido para o jogador digitar uma nova palavra, fazendo assim que o número de tentativas do jogador não diminua caso ele digite uma palavra que não consta no nosso banco de palavras.


## Público-alvo: 
O Enigma destina-se a jogadores de todas as idades que gostam de jogos de palavras desafiadores e competitivos. O jogo é adequado para jogadores iniciantes e experientes que desejam testar suas habilidades, sendo uma maneira criativa de estimular o foco para resolver as questões e aumentar o vocabulário.


## Autores:

- [Leonardo Bhering](https://github.com/leobheringd)
- [Luiza Salgado](https://github.com/LuhSS)
- [Marcos Dhonatha](https://www.github.com/marcosdhonatha)
- [Messias Sabadini](https://github.com/Messiassaba08)

# :hammer: Funcionalidades do jogo:

- Possibilidade de jogar com palavras de 5, 6 ou 7 letras.
- `Diferentes modos de jogo`: Níveis de dificuldade ajustáveis.

# User Stories:
- Como jogador, eu quero adivinhar uma palavra de 5 letras em até 6 tentativas para concluir uma rodada do jogo.

- Como jogador, eu quero ter a opção de escolher a quantidade de letras que minha palavra a ser adivinhada terá.

- Como jogador, eu gostaria de saber a quantidade de tentativas restantes para a minha advinhação depois de cada palpite.

- Como jogador, eu quero que apareça cores para cada letra da palavra, verde quando a letra está na posição correta e vermelho quando não há a letra na palavra, para ajudar nas próximas tentativas.

- Como jogador, eu quero ter acesso a um histórico das minhas tentativas, funcionando como um placar.

- Como jogador, eu devo receber uma mensagem de erro caso eu tente colocar uma palavra com a quantidade de letras errada, para que eu possa realizar uma nova tentativa.

## Pré-requisitos:

Antes de começar, você vai precisar ter instalado em sua máquina as seguintes ferramentas:

- [Git](https://git-scm.com)
- Um compilador que suporte a versão c++20 e comando make, ou seja para Windows é recomendavel o uso de WSL.(Sistemas linux normalmente ja vem com o compilador instalado)

Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/)

### 🎲 Rodando o projeto localmente:

```bash
# Clone este repositório
$ git clone <https://github.com/pds2/20231-team-17>

# Acesse a pasta do projeto no terminal/cmd
$ cd 20231-team-17

# Compile o código utilizando o comando make

#Após compilado, utilize o seguinte comando no terminal
$ ./bin/main 


```

### 🛠 Linguagens, dependêcias e libs:

As seguintes ferramentas foram usadas na construção do projeto:

- [C++](https://cplusplus.com/)


