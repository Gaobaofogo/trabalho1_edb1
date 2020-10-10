#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../include/catch.hpp"
#include "../include/config.hpp"
#include "../include/file_exception.hpp"

TEST_CASE("Leitura do arquivo") {
  REQUIRE_NOTHROW([&]() {
    Config config("respostas_teste.txt");
    config.load_data();
  }());

  CHECK_THROWS([&]() {
    Config config("respostas_teste_inexistente.txt");
    config.load_data();
  }());
}
