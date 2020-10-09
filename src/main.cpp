#include "config.hpp"

#include <iostream>


int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::exit(1);
  }

  Config config(argv[1]);


  return 0;
}
