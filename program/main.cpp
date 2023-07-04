#include <clocale>
#include <cstdio>

#include "ausiliares.hpp"
#include "aleatorio.hpp"
#include "partida.hpp"


int main() {
    std::locale::global(std::locale("pt_BR.utf8"));
    std::wcout.sync_with_stdio(false);
    std::wcout.imbue(std::locale("pt_BR.utf8"));

    std::cout << "Bem vindo ao jogo de adivinhação! Está pronto para adivinhar as palavras?" << std::endl;

    int x = getNumLetras();
    //std::wcout << x << std::endl;

    Partida partida(x);
    partida.jogo(x);

    return 0;
}