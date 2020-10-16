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

typedef bool comparation_func(int, int);

void quick_sort_best(Candidato* candidatos, int p, int r);
void quick_sort_worst(Candidato* candidatos, int p, int r);

int partition(Candidato* candidatos, int p, int r, comparation_func isTrue);

#endif
