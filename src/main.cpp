#include <clocale>
#include <cstdio>

#include "../include/ausiliares.hpp"
#include "../include/aleatorio.hpp"
#include "../include/partida.hpp"


int main() {
    std::locale::global(std::locale("pt_BR.utf8"));
    std::wcout.sync_with_stdio(false);
    std::wcout.imbue(std::locale("pt_BR.utf8"));

    std::cout << "Bem vindo ao jogo de adivinação! Está pronto para adivinhar as palavras?" << std::endl;

    //std::wstring line = palavra_adivinhada();
    //std::wcout << line << std::endl;

    int x = getNumLetras();
    std::wcout << x << std::endl;

    Partida partida(x);
    partida.jogo(x);

    //std::wstring eu{ getPalavra(5) };
    //std::wcout << eu;

    return 0;
}