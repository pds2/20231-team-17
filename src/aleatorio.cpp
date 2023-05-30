#include "../include/aleatorio.hpp"

std::wstring palavra_adivinhada(int numm) {
    srand((unsigned) time(NULL));
    int random = 1 + (rand() % 1557);

    std::string arq;
    if (numm == 5) {
        arq = "../listas/lista5letras1.txt"; }
    else if (numm == 6) {
        arq = "../listas/lista6letras.txt"; }
    else {
        arq = "../listas/lista7letras.txt"; }

    std::wstring line;
    std::wifstream myfile (arq);
    if (myfile.is_open()) {
        int lines_read = 0U;
        while ((lines_read < 1557) && (std::getline(myfile, line))) {
            if (lines_read == random) {
                //std::wcout << line << "\n";
                return line; }
            ++lines_read; }
            
        myfile.close(); }

    else std::cout << "Unable to open file"; }