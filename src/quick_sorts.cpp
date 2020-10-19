#include "quick_sorts.hpp"

/*
 * Tirei daí como usar funções anônimas e em chamadas de função
 * https://ncona.com/2019/05/passing-functions-as-arguments-in-cpp/
 *
 * O algoritmo de Quick sort foi retirado do livro:
 * Algoritmos - Teoria e prática
 * Autor: Thomas  H. Cormen
 * Capítulo 7 | Quicksort
 */


void quick_sort_best(Candidato* candidatos, int p, int r) {
  if (p < r) {
    int q = partition<Candidato>(
        candidatos,
        p,
        r,
        [](Candidato candidato, Candidato pivot) {
          return candidato.acertos >= pivot.acertos;
        });
    quick_sort_best(candidatos, p, q - 1);
    quick_sort_best(candidatos, q + 1, r);
  }
}


void quick_sort_worst(Candidato* candidatos, int p, int r) {
  if (p < r) {
    int q = partition<Candidato>(
        candidatos,
        p,
        r,
        [](Candidato candidato, Candidato pivot) {
          return candidato.acertos <= pivot.acertos;
        });
    quick_sort_worst(candidatos, p, q - 1);
    quick_sort_worst(candidatos, q + 1, r);
  }
}


void quick_sort_best_questions(Questao *questoes, int p, int r) {
  if (p < r) {
    int q = partition<Questao>(
        questoes,
        p,
        r,
        [](Questao questao, Questao pivot) {
          return questao.acertos >= pivot.acertos;
        });
    quick_sort_best_questions(questoes, p, q - 1);
    quick_sort_best_questions(questoes, q + 1, r);
  }
}


void quick_sort_worst_questions(Questao *questoes, int p, int r) {
  if (p < r) {
    int q = partition<Questao>(
        questoes,
        p,
        r,
        [](Questao questao, Questao pivot) {
          return questao.acertos <= pivot.acertos;
        });
    quick_sort_worst_questions(questoes, p, q - 1);
    quick_sort_worst_questions(questoes, q + 1, r);
  }
}


void quick_sort_blank_questions(Questao *questoes, int p, int r) {
  if (p < r) {
    int q = partition<Questao>(
        questoes,
        p,
        r,
        [](Questao questao, Questao pivot) {
          return questao.erros_vazios <= pivot.erros_vazios;
        });
    quick_sort_blank_questions(questoes, p, q - 1);
    quick_sort_blank_questions(questoes, q + 1, r);
  }
}

void quick_sort_id(Questao *questoes, int p, int r) {
  if (p < r) {
    int q = partition<Questao>(
        questoes,
        p,
        r,
        [](Questao questao, Questao pivot) {
          return questao.id <= pivot.id;
        });
    quick_sort_id(questoes, p, q - 1);
    quick_sort_id(questoes, q + 1, r);
  }
}
