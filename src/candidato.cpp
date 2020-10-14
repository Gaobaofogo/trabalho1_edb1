#include "candidato.hpp"

#include <sstream>


Candidato::Candidato() {
  this->nome = "";
  this->acertos = 0;
}


Candidato::Candidato(std::string string_candidato, Gabarito gabarito): acertos(0) {
  std::stringstream sstream(string_candidato);

  // Insere nome
  sstream >> this->nome;

  // Coloca as notas
  for (int i = 0; i < 10; ++i) {
    sstream >> this->notas[i];
    
    if (this->notas[i] == gabarito.resultado[i]) {
      this->acertos += 1;
    }
  }
}
