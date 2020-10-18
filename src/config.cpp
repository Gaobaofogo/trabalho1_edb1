#include "candidato.hpp"
#include "config.hpp"
#include "file_exception.hpp"
#include "gabarito.hpp"
#include "questao.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


Config::Config(std::string _filename) {
  this->filename = _filename;
  this->quantidade_candidatos = 0;

  std::ifstream resp_file(filename);

  if (resp_file.fail()) {
    throw FileException();
  }

  this->questoes = this->init_questions();

  Gabarito gabarito;
  gabarito.resultado[0] = 'A';
  gabarito.resultado[1] = 'B';
  gabarito.resultado[2] = 'C';
  gabarito.resultado[3] = 'D';
  gabarito.resultado[4] = 'E';
  gabarito.resultado[5] = 'E';
  gabarito.resultado[6] = 'D';
  gabarito.resultado[7] = 'C';
  gabarito.resultado[8] = 'B';
  gabarito.resultado[9] = 'A';

  std::string line;
  this->candidatos = new Candidato[1];
  int limite = 1;

  while(std::getline(resp_file, line)) {
    this->apura_questoes(line, gabarito);

    Candidato novo_candidato(line, gabarito);
    limite = this->add_candidato(novo_candidato, limite);
  }

  resp_file.close();
}

void Config::apura_questoes(std::string line, Gabarito gabarito) {
  std::stringstream sstream(line);
  std::string lixo;
  char resposta;

  // Remove nome
  sstream >> lixo;

  // Olha as notas
  for (int i = 0; i < 10; ++i) {
    sstream >> resposta;
    
    if (resposta == gabarito.resultado[i]) {
      this->questoes[i].acertos += 1;
    } else if (resposta != 'A' && resposta != 'B' && resposta != 'C'
               && resposta != 'D' && resposta != 'E') {
      this->questoes[i].erros_vazios += 1;
    }
  }
}

int Config::add_candidato(Candidato novo_candidato, int limite) {
  if (this->quantidade_candidatos == limite) {
    candidatos = this->alloc_candidatos(candidatos, limite);
    limite *= 2;
  }

  candidatos[this->quantidade_candidatos] = novo_candidato;
  this->quantidade_candidatos += 1;

  return limite;
}

Candidato* Config::load_data() {
  return this->candidatos;
}


Candidato* Config::alloc_candidatos(Candidato *candidatos, int limite) {
  Candidato* novo_array = new Candidato[limite * 2] ;

  for (int j = 0; j < limite; ++j) {
    novo_array[j] = candidatos[j];
  }

  delete[] candidatos;
  candidatos = nullptr;

  return novo_array;
}


int Config::get_quantidade_candidatos() {
  return this->quantidade_candidatos;
}


Questao* Config::init_questions() {
  this->questoes = new Questao[10];

  for (int i = 0; i < 10; ++i) {
    Questao nova_questao(i + 1, 0, 0);
    this->questoes[i] = nova_questao;
  }

  return this->questoes;
}

Questao* Config::get_questoes() {
  return this->questoes;
}
