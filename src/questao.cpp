#include "questao.hpp"

#include <sstream>


Questao::Questao(): id(0), acertos(0), erros_vazios(0) {
}

Questao::Questao(unsigned int _id, int _acertos, int _erros_vazios):
  id(_id),
  acertos(_acertos),
  erros_vazios(_erros_vazios) {
}


void Questao::corrige_questao(std::string string_candidato, Gabarito gabarito) {
}
