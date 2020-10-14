#include "app.hpp"
#include "quick_sorts.hpp"

#include <iostream>


App::App(Candidato* _candidatos, size_t quantidade_candidatos) {
  this->candidatos = _candidatos;
  this->quantidade_candidatos = quantidade_candidatos;
}

App::~App() {
  delete[] this->candidatos;
}

int App::run(std::string command, size_t quantity) {

  if (command == "best") {
    quick_sort_best(
        candidatos,
        0,
        this->quantidade_candidatos
        );
  } else {
    std::cerr << "Comando '" << command << "' não reconhecido." << std::endl;
    return 1;
  }
  return 0;
}
