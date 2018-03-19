#include <iostream>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

void dividir_qs(int T[], int inicial, int final, int & pp) {
  int pivote, aux;
  int k, l;

  pivote = T[inicial];
  k = inicial;
  l = final;
  do {
    k++;
  } while ((T[k] <= pivote) && (k < final-1));
  do {
    l--;
  } while (T[l] > pivote);
  while (k < l) {
    aux = T[k];
    T[k] = T[l];
    T[l] = aux;
    do k++; while (T[k] <= pivote);
    do l--; while (T[l] > pivote);
  }
  aux = T[inicial];
  T[inicial] = T[l];
  T[l] = aux;
  pp = l;
}

void insercion_lims(int T[], int inicial, int final) {
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      j--;
    }
  }
}

inline void insercion(int T[], int num_elem) {
  insercion_lims(T, 0, num_elem);
}


const int UMBRAL_QS = 50;

void quicksort_lims(int T[], int inicial, int final) {
  int k;
  if (final - inicial < UMBRAL_QS) {
    insercion_lims(T, inicial, final);
  } else {
    dividir_qs(T, inicial, final, k);
    quicksort_lims(T, inicial, k);
    quicksort_lims(T, k + 1, final);
  }
}

inline void quicksort(int T[], int num_elem) {
  quicksort_lims(T, 0, num_elem);
}

int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

  srandom(time(0));

  for (int i = 0; i < n; i++) {
      T[i] = random();
  }
  high_resolution_clock::time_point start, end;
  duration<double> tiempo_transcurrido;
  start = high_resolution_clock::now();
  quicksort(T, n);
  end = high_resolution_clock::now();
  tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  cout << n << "\t" <<tiempo_transcurrido.count() << endl;
  delete [] T;

  return 0;
}
