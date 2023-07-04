#include "doctest.h"
#include "ausiliares.hpp"
#include "aleatorio.hpp"

#include <string>
#include <clocale>
#include <cstdio>


TEST_CASE("T1 - teste algumas funcoes auxiliares") {
    //tranformar palavra em maiscula
    std::wstring pal = L"amarelo";
    std::wstring palM = maiscula(pal);
    CHECK(palM.compare(L"AMARELO") == 0);


    //pegar o caminho certo dos arquivos da lista com palavras
    fs::path cdw = fs::current_path();
    fs::path cami = cdw / "listas" / "lista5letrasUTF8.txt";
    std::string arq = fs::absolute(cami); 
    CHECK(arq.compare(get_arquivo(5)) == 0);
}

TEST_CASE("T2 - testa se as palavras existem no arquivo") {
    std::locale::global(std::locale("pt_BR.utf8"));
    std::wcout.sync_with_stdio(false);
    std::wcout.imbue(std::locale("pt_BR.utf8"));

    std::wstring pal1 = L"amarelo";
    std::wstring pal2 = L"Lucas";
    std::wstring pal3 = L"Balão";
    std::wstring pal4 = L"COxinha";

    CHECK_EQ(true, existe(pal1, 7));
    CHECK_EQ(false, existe(pal2, 5));
    CHECK_EQ(true, existe(pal3, 5));
    CHECK_EQ(true, existe(pal4, 7));

    CHECK_EQ(1611, contalinha(5));

}