#ifndef EDB1_APP_H
#define EDB1_APP_H

#include "candidato.hpp"


class App {
  private:
    Candidato* candidatos;

  public:
    App(Candidato* _candidatos);
    ~App();
    int run(std::string command, size_t quantity);
};

#endif
