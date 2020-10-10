#include "config.hpp"
#include "file_exception.hpp"

#include <fstream>
#include <iostream>

Config::Config(std::string _filename): filename(_filename) {
}

/*
 * Preciso ler o arquivo. Ler as linhas. Pegar os valores das linhas e
 * transformas em Candidatos. Adicionar esse candidato numa lista(que precisa
 * ser dinâmica). Depois de adicionar todo mundo, retornar essa lista.
 */
void Config::load_data() {
  std::ifstream resp_file(filename);

  if (resp_file.fail()) {
    throw FileException();
  }

  resp_file.close();
}
