#include "candidato.hpp"
#include "config.hpp"
#include "file_exception.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


Config::Config(std::string _filename): filename(_filename) {
}

Candidato* Config::load_data() {
  std::ifstream resp_file(filename);

  if (resp_file.fail()) {
    throw FileException();
  }

  std::string line;
  Candidato* candidatos = new Candidato[1];
  size_t qntd_candidatos = 0;
  size_t limite = 1;

  while(std::getline(resp_file, line)) {
    Candidato novo_candidato;
    std::stringstream sstream(line);

    // Insere nome
    sstream >> novo_candidato.nome;

    // Coloca as notas
    for (int i = 0; i < 10; ++i) {
      sstream >> novo_candidato.notas[i];
    }

    // Se a quantidade de candidatos chegar num patamar, precisa criar um novo
    // array maior para poder armazenar mais candidatos, lembrando de colocar
    // os valores antigos no novo array.
    if (qntd_candidatos == limite) {
     Candidato* novo_array = new Candidato[limite * 2] ;

     for (size_t j = 0; j < limite; ++j) {
       novo_array[j] = candidatos[j];
     }

     delete[] candidatos;

     candidatos = novo_array;
     limite *= 2;
    }

    candidatos[qntd_candidatos] = novo_candidato;
    ++qntd_candidatos;
  }

  resp_file.close();

  return candidatos;
}
