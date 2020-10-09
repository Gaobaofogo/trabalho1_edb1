#include "config.hpp"

#include <fstream>
#include <iostream>

Config::Config(std::string _filename): filename(_filename) {
}

void Config::load_data(std::string filename) {
  std::ifstream resp_file(filename);

  if (resp_file.fail()) {
    throw "Erro no arquivo.";
  }

  std::cout << "Leu com exito" << std::endl;

  resp_file.close();
}
