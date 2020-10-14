#ifndef EDB1_APP_H
#define EDB1_APP_H

#include "candidato.hpp"


class App {
  private:
    Candidato* candidatos;
    size_t quantidade_candidatos;

  public:
    App(Candidato* _candidatos, size_t quantidade_candidatos);
    ~App();
    int run(std::string command, size_t quantity);
};

#endif
