#include "ausiliares.hpp"
#include "../include/ArquivoNaoAbertoException.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>




void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ignoreLinew() {
    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string get_arquivo(int num) {
    fs::path cdw = fs::current_path();
    fs::path caminho5 = cdw / "listas" / "palavras5.txt";
    fs::path caminho6 = cdw / "listas" / "palavras6.txt";
    fs::path caminho7 = cdw / "listas" / "palavras7.txt";

    std::string arq;
    if (num == 5) {
        arq = fs::absolute(caminho5); }
    else if (num == 6) {
        arq = fs::absolute(caminho6); }
    else {
        arq = fs::absolute(caminho7); }

    return arq;
}

int getNumLetras() {
    while(true) {
        std::cout << "Digite o número de letras (5, 6 ou 7): ";
        std::string auxi;
        std::cin >> auxi;
        int x;

        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            std::cout << "Entrada inválida! Tente novamente." << std::endl; }
        else if (auxi.compare("5") != 0 && auxi.compare("6") != 0 && auxi.compare("7") != 0) {
            ignoreLine();
            std::cout << "Dado inválido! Tente novamente." << std::endl; }
        else if (auxi.compare("5") == 0 || auxi.compare("6") == 0 || auxi.compare("7") == 0) {
            ignoreLine();
            x = stoi(auxi);
            return x; }
        else {
            ignoreLine();
            std::cout << "Algo de errado! Tente novamente." << std::endl; } 
    }
}


std::wstring maiscula(std::wstring word) {

    auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

    f.toupper(&word[0], &word[0] + word.size());
    return word;
}


bool existe(std::wstring pal, int num) {

    std::string arq = get_arquivo(num);
    std::wstring aux;
    aux = maiscula(pal);

    std::wstring line;
    std::wifstream myfile (arq);
    if (myfile.is_open()) {
        std::getline(myfile, line);
        while (!myfile.eof()) {
            std::getline(myfile, line);
            if (line.compare(0, num, aux) == 0) {
                myfile.close();
                return true; } } }

    else { 
        throw ArquivoNaoAbertoException();
        return false; } 
    return false;
}


std::wstring getPalavra(unsigned int numletras) {
    
    while(true) {
        std::wcout << L"Digite uma palavra de " << numletras << L" letras: ";
        std::wstring palavra;
        std::getline(std::wcin, palavra);
        //std::wcout << palavra << std::endl;

        if (!std::wcin) {
            std::wcin.clear();
            std::wcout << L"Entrada inválida! Tente novamente." << std::endl; }
        else if (palavra.size() != numletras) {
            std::wcout << L"Essa palavra não tem " << numletras << L" letras! Tente novamente." << std::endl;
            }
        else if (existe(palavra, numletras) == false) {
            std::wcout << L"Essa palavra não existe. Tente novamente." << std::endl;
            }
        else {
            palavra = maiscula(palavra);
            return palavra; } 
    }
}


std::map<wchar_t, int> repitidas(std::vector<wchar_t> a) {
    std::map<wchar_t, int> contarletras;
    for (long unsigned int x = 0; x < a.size(); x++) {
        contarletras[a[x]]++; }
    return contarletras;
}
