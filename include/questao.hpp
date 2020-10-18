#ifndef EDB1_QUESTAO_H
#define EDB1_QUESTAO_H

#include "gabarito.hpp"

#include <string>


struct Questao {
  unsigned int id;
  int acertos;
  int erros_vazios;
  Questao();
  Questao(unsigned int _id, int _acertos, int _erros_vazios);
  void corrige_questao(std::string string_candidato, Gabarito gabarito);
};

#endif
