CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(projeto_edb)

SET(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(include/)

ADD_EXECUTABLE(
  prog
  src/app.cpp
  src/config.cpp
  src/main.cpp
)
