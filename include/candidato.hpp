#ifndef CANDIDATO_H
#define CANDIDATO_H

#include "gabarito.hpp"

#include <string>


struct Candidato {
  std::string nome;
  char notas[10];
  unsigned short int acertos;

  Candidato();
  Candidato(std::string string_candidato, Gabarito gabarito);
};

#endif
