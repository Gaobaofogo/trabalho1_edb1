#ifndef EDB1_APP_H
#define EDB1_APP_H

#include "candidato.hpp"
#include "questao.hpp"


class App {
  private:
    Candidato* candidatos;
    int quantidade_candidatos;
    Questao* questoes;

  public:
    App(Candidato* _candidatos);
    ~App();
    int run(std::string command, size_t quantity);
    int get_quantidade_candidatos();
    void set_quantidade_candidatos(int _quantidade_candidatos);
    void set_questoes(Questao* _questoes);
};

#endif
