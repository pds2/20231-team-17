#include "partida.hpp"
#include "../include/ArquivoNaoAbertoException.hpp"
Partida::Partida(int nletras) {
    _Padivinha = palavra_adivinhada(nletras);
    if (nletras == 5 || nletras == 6) {
        _rodadas_restantes = 6; }
    else {
        _rodadas_restantes = 7; }
    
}

int Partida::get_rodada(){
    return _rodadas_restantes;
}

void Partida::jogo(int nletras) {
    for (int z = _rodadas_restantes; z >= 0; --z) {
        std::wstring pv;
         try {
        pv = getPalavra(nletras);
    } catch (const ArquivoNaoAbertoException &e) {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
        
        //Critério para vencer = acertou a palavra.
        if (_Padivinha.compare(0, nletras, pv) == 0) {
            _rodadas_restantes--;
            _partida.push_back(pv);
            imprimir_vetor();
            std::wcout << L"Você venceu! Ainda tinham " << _rodadas_restantes << L" rodadas restantes." << std::endl;
            result = true;
            break; }
        //Critério para perder = acabou as rodadas.
        if (_rodadas_restantes == 1) {
            _partida.push_back(pv);
            imprimir_vetor();
            //std::wcout << std::endl; 
            std::wcout << L"Você perdeu! Mais habilidade da próxima vez!" << std::endl; 
            std::wcout << L"A palavra era: " << _Padivinha << std::endl;
            result = false;
            break; }
        
        std::vector<wchar_t> a(pv.begin(), pv.end());
        std::vector<wchar_t> b(_Padivinha.begin(), _Padivinha.end());
        _partida.push_back(pv);
        imprimir_vetor();
        //std::wcout << std::endl; 
        std::wcout << L"Você possui " << (_rodadas_restantes - 1) << L" chances restantes." << std::endl; 
        _rodadas_restantes--;
    }
}

void Partida::cores(std::vector<wchar_t> a, std::vector<wchar_t> b) {
    std::map<wchar_t, int>  repeidasA = repitidas(a);
    std::map<wchar_t, int>  repeidasB = repitidas(b);
    for (long unsigned int i = 0; i < a.size(); i++) {
        //São iguais na posição certa -> verde.
        if (a[i] == b[i]) {
            std::wcout << "\033[32m" << a[i] << "\033[0m"; }
        else if (repeidasA[a[i]] > 1 && repeidasA[a[i]] != repeidasB[a[i]]) {
            //Tem 1 ou + repetidas na palavra que eu digitei que na original.
            if(repeidasA[a[i]] > repeidasB[a[i]]) {
                std::wcout << a[i];
                repeidasA[a[i]]--; } 
            else {
                std::wcout << "vc esqueceu um caso";
            } }
        else {
            int cont = 0;
            for (long unsigned int j = 0; j < a.size(); j++) {
                if (a[i] == b[j] && b[j] != a[j]) {
                    ++cont; } }
            if (cont == 0) { 
                std::wcout << a[i]; }
            else {
                std::wcout << "\033[31m" << a[i] << "\033[0m"; } }      
    }
}

void Partida::imprimir_vetor() {
    std::vector<wchar_t> b(_Padivinha.begin(), _Padivinha.end());
    for (long unsigned int i = 0; i < _partida.size(); i++) {
        std::vector<wchar_t> a(_partida[i].begin(), _partida[i].end());
        cores(a, b);
        std::wcout << std::endl; 
    }
}

bool Partida::get_result(){
    return result;
}