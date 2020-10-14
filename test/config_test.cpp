#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../include/candidato.hpp"
#include "../include/catch.hpp"
#include "../include/config.hpp"
#include "../include/file_exception.hpp"
#include "../include/quick_sorts.hpp"

TEST_CASE("Leitura do arquivo") {
  REQUIRE_NOTHROW([&]() {
    Config config("respostas_teste.txt");
    Candidato* candidato = config.load_data();

    delete[] candidato;
  }());

  CHECK_THROWS([&]() {
    Config config("respostas_teste_inexistente.txt");
    Candidato* candidato = config.load_data();

    delete[] candidato;
  }());
}


TEST_CASE("Quick sort best") {
  Config config("respostas_teste.txt");
  Candidato* candidatos = config.load_data();

  for (int i = 0; i < 10; ++i) {
    std::cout << candidatos[i].nome << " - " << candidatos[i].acertos << std::endl;
  }

  std::cout << std::endl << std::endl;

  quick_sort_best(
      candidatos,
      0,
      9);

  for (int i = 0; i < 10; ++i) {
    std::cout << candidatos[i].nome << " - " << candidatos[i].acertos << std::endl;
  }
}
