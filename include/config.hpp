#ifndef CONFIG_PROJECT_H
#define CONFIG_PROJECT_H

#include "candidato.hpp"

#include <string>


class Config {
  private:
    std::string filename;
    int quantidade_candidatos;
  public:
    Config(std::string _filename);
    Candidato* load_data();
    int get_quantidade_candidatos();
};

#endif
