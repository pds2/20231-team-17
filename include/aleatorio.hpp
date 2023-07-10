#ifndef ALEATORIO_H
#define ALEATORIO_H

#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

#include "ausiliares.hpp"

//retorna qntd de linha no arquivo
int contalinha(int num);

//Retorna uma palavra aleatória
std::wstring palavra_adivinhada(int numm);

#endif