#include "app.hpp"


App::App(Candidato* _candidatos): candidatos(_candidatos) {
}

App::~App() {
  delete[] this->candidatos;
}

int App::run(std::string command, size_t quantity) {
  return 0;
}
