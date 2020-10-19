#include "app.hpp"
#include "quick_sorts.hpp"

#include <iomanip>
#include <iostream>


App::App(Candidato* _candidatos) {
  this->candidatos = _candidatos;
  this->quantidade_candidatos = 0;
}

App::~App() {
  delete[] this->candidatos;
  delete[] this->questoes;
}

int App::run(std::string command, size_t quantity) {
  if (command == "best") {
    this->best_command(quantity);

  } else if (command == "worst") {
    this->worst_command(quantity);

  } else if (command == "best-questions") {
    this->best_questions_command(quantity);

  } else if (command == "worst-questions") {
    this->worst_questions_command(quantity);

  } else if (command == "blank-questions") {
    this->blank_questions_command(quantity);

  } else {
    std::cerr << "Comando '" << command << "' não reconhecido." << std::endl;
    return 1;
  }

  return 0;
}

int App::get_quantidade_candidatos() {
  return this->quantidade_candidatos;
}

void App::set_quantidade_candidatos(int _quantidade_candidatos) {
  this->quantidade_candidatos = _quantidade_candidatos;
}

void App::set_questoes(Questao* _questoes) {
  this->questoes = _questoes;
}

void App::best_command(size_t quantity) {
  quick_sort_best(
      this->candidatos,
      0,
      this->get_quantidade_candidatos() - 1
      );

  std::cout << std::left << std::setw(13) << "Nome" << std::setw(2) << "Nota" << std::endl;

  for (size_t i = 0; i < quantity; ++i) {
    std::cout << std::left << std::setw(13) << this->candidatos[i].nome << std::setw(3) << this->candidatos[i].acertos << std::endl;
  }
}

void App::worst_command(size_t quantity) {
  quick_sort_worst(
      this->candidatos,
      0,
      this->get_quantidade_candidatos() - 1
      );

  std::cout << std::left << std::setw(13) << "Nome" << std::setw(2) << "Nota" << std::endl;

  for (size_t i = 0; i < quantity; ++i) {
    std::cout << std::left << std::setw(13) << this->candidatos[i].nome << std::setw(3) << this->candidatos[i].acertos << std::endl;
  }
}


void App::best_questions_command(size_t quantity) {
  quick_sort_best_questions(
      this->questoes,
      0,
      9);

  int i = 0;
  int j = 1;

  while (i < 9 && j <= 9) {
    if (this->questoes[i].acertos == this->questoes[j].acertos) {
      ++j;
    } else if (i < j){
      quick_sort_id(this->questoes, i, j - 1);
      i = j;
    } else {
      ++i;
      j = i;
    }
  }

  quick_sort_id(this->questoes, i, j - 1);

  std::cout << std::left << std::setw(5) << "ID" << std::setw(7) << "Acertos" << std::endl;

  for (size_t i = 0; i < quantity; ++i) {
    std::cout << std::left << std::setw(5) << this->questoes[i].id << std::setw(3) << this->questoes[i].acertos << std::endl;
  }
}


void App::worst_questions_command(size_t quantity) {
  quick_sort_worst_questions(
      this->questoes,
      0,
      9);

  int i = 0;
  int j = 1;

  while (i < 9 && j <= 9) {
    if (this->questoes[i].acertos == this->questoes[j].acertos) {
      ++j;
    } else if (i < j){
      quick_sort_id(this->questoes, i, j - 1);
      i = j;
    } else {
      ++i;
      j = i;
    }
  }

  quick_sort_id(this->questoes, i, j - 1);

  std::cout << std::left << std::setw(5) << "ID" << std::setw(7) << "Acertos" << std::endl;

  for (size_t i = 0; i < quantity; ++i) {
    std::cout << std::left << std::setw(5) << this->questoes[i].id << std::setw(3) << this->questoes[i].acertos << std::endl;
  }
}


void App::blank_questions_command(size_t quantity) {
  quick_sort_blank_questions(
      this->questoes,
      0,
      9);

  int i = 0;
  int j = 1;

  while (i < 9 && j <= 9) {
    if (this->questoes[i].erros_vazios == this->questoes[j].erros_vazios) {
      ++j;
    } else if (i < j){
      quick_sort_id(this->questoes, i, j - 1);
      i = j;
    } else {
      ++i;
      j = i;
    }
  }

  quick_sort_id(this->questoes, i, j - 1);

  std::cout << std::left << std::setw(5) << "ID" << std::setw(7) << "Erros" << std::endl;

  for (size_t i = 0; i < quantity; ++i) {
    std::cout << std::left << std::setw(5) << this->questoes[i].id << std::setw(3) << this->questoes[i].erros_vazios << std::endl;
  }
}
