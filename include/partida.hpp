#ifndef PARTIDA_H
#define PARTIDA_H

#include "ausiliares.hpp"
#include "aleatorio.hpp"

class Partida{
    private: 
        std::vector<std::wstring> _partida;
        int _rodadas_restantes;
        std::wstring _Padivinha;
        bool result = true;

    public:
        //Gets
        bool get_result();
        //Construtormake
        Partida(int nletras);

        //pega a quantidade de rodadas restantes
        int get_rodada();

        //Determina que cor a letra deve ter
        void cores(std::vector<wchar_t> a, std::vector<wchar_t> b);

        //Imprime o vetor de palavras coloridas
        void imprimir_vetor();

        //Roda uma partida
        void jogo(int nletras);

};


#endif