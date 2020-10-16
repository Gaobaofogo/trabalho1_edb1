#ifndef EDB1_APP_H
#define EDB1_APP_H

#include "candidato.hpp"


class App {
  private:
    Candidato* candidatos;
    int quantidade_candidatos;

  public:
    App(Candidato* _candidatos);
    ~App();
    int run(std::string command, size_t quantity);
    int get_quantidade_candidatos();
    void set_quantidade_candidatos(int _quantidade_candidatos);
};

#endif
