#include "candidato.hpp"
#include "config.hpp"
#include "file_exception.hpp"
#include "gabarito.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


Config::Config(std::string _filename): filename(_filename), quantidade_candidatos(0) {
}

Candidato* Config::load_data() {
  std::ifstream resp_file(filename);

  if (resp_file.fail()) {
    throw FileException();
  }
  Gabarito gabarito;
  gabarito.resultado[0] = 'A';
  gabarito.resultado[1] = 'B';
  gabarito.resultado[2] = 'C';
  gabarito.resultado[3] = 'D';
  gabarito.resultado[4] = 'E';
  gabarito.resultado[5] = 'E';
  gabarito.resultado[6] = 'D';
  gabarito.resultado[7] = 'C';
  gabarito.resultado[8] = 'B';
  gabarito.resultado[9] = 'A';

  std::string line;
  Candidato* candidatos = new Candidato[1];
  size_t limite = 1;

  while(std::getline(resp_file, line)) {
    Candidato novo_candidato(line, gabarito);

    if (this->quantidade_candidatos == limite) {
     Candidato* novo_array = new Candidato[limite * 2] ;

     for (size_t j = 0; j < limite; ++j) {
       novo_array[j] = candidatos[j];
     }

     delete[] candidatos;

     candidatos = novo_array;
     limite *= 2;
    }

    candidatos[this->quantidade_candidatos] = novo_candidato;
    this->quantidade_candidatos += 1;
  }

  resp_file.close();

  return candidatos;
}

size_t Config::get_quantidade_candidatos() {
  return this->quantidade_candidatos;
}
