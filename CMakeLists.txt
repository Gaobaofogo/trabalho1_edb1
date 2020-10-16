CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(trabalho_1_edb1)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(include/)

ADD_EXECUTABLE(
  prog
  src/app.cpp
  src/candidato.cpp
  src/config.cpp
  src/quick_sorts.cpp
  src/main.cpp
)
