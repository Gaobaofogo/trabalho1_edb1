#ifndef EDB1_FILE_EXCEPTION_H
#define EDB1_FILE_EXCEPTION_H

#include <exception>

/*
 * Local onde tirei como fazer uma exceção customizada:
 * http://peterforgacs.github.io/2017/06/25/Custom-C-Exceptions-For-Beginners/
 */
struct FileException : public std::exception {
  const char * what () const throw () {
    return "Erro na leitura de arquivo. Cheque se o nome e o caminho do arquivo estão corretos.";
  }
};

#endif
