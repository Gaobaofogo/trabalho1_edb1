#include "app.hpp"
#include "candidato.hpp"
#include "config.hpp"

#include <iostream>


int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cerr << "Quantidade de argumentos inferior ao esperado." << std::endl;
    std::cerr << "Execução esperada: " << argv[0] << " respostas.txt best 5";
    std::cerr << std::endl;
    std::exit(1);
  }

  Config config(argv[1]);
  App app(
      config.load_data()
  );
  app.set_quantidade_candidatos(
      config.get_quantidade_candidatos());
  app.set_questoes(
      config.get_questoes());

  return app.run(argv[2], std::stoi(argv[3]));
}
