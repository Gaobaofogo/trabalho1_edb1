#ifndef CONFIG_PROJECT_H
#define CONFIG_PROJECT_H

#include "candidato.hpp"

#include <string>


class Config {
  private:
    std::string filename;
  public:
    Config(std::string _filename);
    Candidato* load_data();
};

#endif
