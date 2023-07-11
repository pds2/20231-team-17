#include "aleatorio.hpp"

int contalinha(int num) {
    int contador = 0;
    std::string arq = get_arquivo(num);
    std::wifstream myfile (arq);
    std::wstring line;

    if (myfile.is_open()) {
        while (std::getline(myfile, line)) {
            contador++; }
        myfile.close(); }
    else { return 0; }
    return contador;
}

std::wstring palavra_adivinhada(int numm) {

    int ajuda = contalinha(numm);

    srand((unsigned) time(NULL));
    int random = 1 + (rand() % ajuda);

    std::string arq = get_arquivo(numm);

    std::wstring line;
    std::wifstream myfile (arq);
    if (myfile.is_open()) {
        int lines_read = 0U;
        while ((lines_read < ajuda) && (std::getline(myfile, line))) {
            if (lines_read == random) {
                //std::wcout << line << "\n";
                myfile.close();
                return line; }
            ++lines_read; } }

    else { 

        return L"ERROS"; } }
