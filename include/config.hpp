#ifndef CONFIG_PROJECT_H
#define CONFIG_PROJECT_H

#include "candidato.hpp"

#include <string>


class Config {
  private:
    std::string filename;
    size_t quantidade_candidatos;
  public:
    Config(std::string _filename);
    Candidato* load_data();
    size_t get_quantidade_candidatos();
};

#endif
