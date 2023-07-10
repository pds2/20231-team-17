#include <clocale>
#include <cstdio>

#include "ausiliares.hpp"
#include "aleatorio.hpp"
#include "partida.hpp"


int main() {
    std::locale::global(std::locale("pt_BR.utf8"));
    std::wcout.sync_with_stdio(false);
    std::wcout.imbue(std::locale("pt_BR.utf8"));
    int pontuacao = 0;
    bool result = true;
    
      std::cout << "********************************************" << std::endl;
    std::cout << "*       Bem vindo ao jogo de adivinhação!    *" << std::endl;
    std::cout << "*   Está pronto para adivinhar as palavras?  *" << std::endl;
    std::cout << "********************************************" << std::endl;

    int x = getNumLetras();
    //std::wcout << x << std::endl;

    while(result == true){
    std::cout << "Pontuação atual: " << pontuacao << " ponto(s)" << std::endl;
    Partida partida(x);
    pontuacao++;
    partida.jogo(x);  
    result = partida.get_result();
    }
    //caso erre, não dar um número a mais na pontuação;
    if(result == false){
        pontuacao --;
    }
    std::cout << "Pontuação total: " << pontuacao << " ponto(s)" << std::endl;   

    return 0;
}
