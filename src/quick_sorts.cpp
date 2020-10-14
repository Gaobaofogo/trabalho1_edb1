#include "quick_sorts.hpp"


void quick_sort_best(Candidato* candidatos, int p, int r) {
  if (p < r) {
    int q = partition_best(candidatos, p, r);
    quick_sort_best(candidatos, p, q - 1);
    quick_sort_best(candidatos, q + 1, r);
  }
}


int partition_best(Candidato* candidatos, int p, int r) {
  Candidato x = candidatos[r];
  int i = p - 1;

  for (int j = p; j < r; ++j) {
    if (candidatos[j].acertos >= x.acertos) {
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
