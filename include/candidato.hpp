#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>

enum Notas {
  Branco,
  A,
  B,
  C,
  D,
  E
};

class Candidato {
  private:
    std::string nome;
    Notas* notas;

  public:
    ~Candidato();
};

#endif
