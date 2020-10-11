#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../include/candidato.hpp"
#include "../include/catch.hpp"
#include "../include/config.hpp"
#include "../include/file_exception.hpp"


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
