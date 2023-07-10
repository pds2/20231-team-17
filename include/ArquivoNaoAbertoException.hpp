#ifndef ARQUIVO_NAO_ABERTO_EXCEPTION_H
#define ARQUIVO_NAO_ABERTO_EXCEPTION_H

#include <exception>
//exceção caso o aquivo não seja aberto  
class ArquivoNaoAbertoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "O arquivo não pôde ser aberto.";
    }
};

#endif
