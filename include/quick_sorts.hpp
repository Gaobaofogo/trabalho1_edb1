#ifndef EDB1_QUICK_SORTS_H
#define EDB1_QUICK_SORTS_H

/*
 * Tirei daí como usar funções anônimas e em chamadas de função
 * https://ncona.com/2019/05/passing-functions-as-arguments-in-cpp/
 *
 * O algoritmo de Quick sort foi retirado do livro:
 * Algoritmos - Teoria e prática
 * Autor: Thomas  H. Cormen
 * Capítulo 7 | Quicksort
 */

#include "candidato.hpp"
#include "questao.hpp"

typedef bool comparation_func(int, int);

void quick_sort_best(Candidato* candidatos, int p, int r);
void quick_sort_worst(Candidato* candidatos, int p, int r);

void quick_sort_best_questions(Questao *questoes, int p, int r);
void quick_sort_worst_questions(Questao *questoes, int p, int r);
void quick_sort_blank_questions(Questao *questoes, int p, int r);

void quick_sort_id(Questao *questoes, int p, int r);

template<class T>
int partition(T* arr, int p, int r, bool isTrue(T, T)) {
  T x = arr[r];
  int i = p - 1;

  for (int j = p; j < r; ++j) {
    if (isTrue(arr[j], x)) {
      ++i;

      T tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  }

  T tmp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = tmp;

  return i + 1;
}

#endif
