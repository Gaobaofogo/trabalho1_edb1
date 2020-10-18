#ifndef CONFIG_PROJECT_H
#define CONFIG_PROJECT_H

#include "candidato.hpp"
#include "questao.hpp"

#include <string>


class Config {
  private:
    std::string filename;
    int quantidade_candidatos;
    Questao* questoes;
    Candidato* candidatos;
  public:
    Config(std::string _filename);
    Candidato* load_data();

    int get_quantidade_candidatos();
    Candidato* alloc_candidatos(Candidato* candidatos, int limite);
    int add_candidato(Candidato novo_candidato, int limite);

    Questao* init_questions();
    void apura_questoes(std::string line, Gabarito gabarito);
    Questao* get_questoes();
};

#endif
