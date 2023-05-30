#ifndef AUSILIARES_H
#define AUSILIARES_H

#include <iostream>
#include <limits>
#include <string>
#include <locale>
#include <fstream>
#include <map>
#include <vector>

//Ignora tudo até o próximo '\n' para evitar erros de output.
void ignoreLine();
void ignoreLinew();

//Pega o número de letras com que o jogador que jogar, considerando inputs inválidos.
int getNumLetras();

//Transforma uma string em maiscula.
std::wstring maiscula(std::wstring word);

//Determina se a palavra existe.
bool existe(std::wstring pal, int num);

//Pega uma palavra válida para certa instância do jogo.
std::wstring getPalavra(unsigned int numletras);

//Retorna quantas vezes cada letra aparece.
std::map<wchar_t, int> repitidas(std::vector<wchar_t> a);

#endif