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
    int q = partition_acertos(candidatos, p, r, [](int acerto_candidato, int acerto_pivot) {
        return acerto_candidato >= acerto_pivot;
        });
    quick_sort_best(candidatos, p, q - 1);
    quick_sort_best(candidatos, q + 1, r);
  }
}


void quick_sort_worst(Candidato* candidatos, int p, int r) {
  if (p < r) {
    int q = partition_acertos(candidatos, p, r, [](int acerto_candidato, int acerto_pivot) {
        return acerto_candidato <= acerto_pivot;
        });
    quick_sort_worst(candidatos, p, q - 1);
    quick_sort_worst(candidatos, q + 1, r);
  }
}


int partition_acertos(Candidato *candidatos, int p, int r, comparation_func isTrue) {
  Candidato x = candidatos[r];
  int i = p - 1;

  for (int j = p; j < r; ++j) {
    if (isTrue(candidatos[j].acertos, x.acertos)) {
      ++i;

      Candidato tmp = candidatos[i];
      candidatos[i] = candidatos[j];
      candidatos[j] = tmp;
    }
  }

  Candidato tmp = candidatos[i + 1];
  candidatos[i + 1] = candidatos[r];
  candidatos[r] = tmp;

  return i + 1;
}


void quick_sort_best_questions(Questao *questoes, int p, int r) {
  if (p < r) {
    int q = partition_questoes(questoes, p, r, [](int questao_acerto, int pivot_acerto) {
          return questao_acerto >= pivot_acerto;
        });
    quick_sort_best_questions(questoes, p, q - 1);
    quick_sort_best_questions(questoes, q + 1, r);
  }
}


void quick_sort_worst_questions(Questao *questoes, int p, int r) {
  if (p < r) {
    int q = partition_questoes(questoes, p, r, [](int questao_acerto, int pivot_acerto) {
          return questao_acerto <= pivot_acerto;
        });
    quick_sort_worst_questions(questoes, p, q - 1);
    quick_sort_worst_questions(questoes, q + 1, r);
  }
}


int partition_questoes(Questao *questoes, int p, int r, comparation_func isTrue) {
  Questao x = questoes[r];
  int i = p - 1;

  for (int j = p; j < r; ++j) {
    if (isTrue(questoes[j].acertos, x.acertos)) {
      ++i;

      Questao tmp = questoes[i];
      questoes[i] = questoes[j];
      questoes[j] = tmp;
    }
  }

  Questao tmp = questoes[i + 1];
  questoes[i + 1] = questoes[r];
  questoes[r] = tmp;

  return i + 1;
}
