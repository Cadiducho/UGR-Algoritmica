#include <iostream>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

void fusion(int T[], int inicial, int final, int U[], int V[]) {
  int j = 0;
  int k = 0;
  for (int i = inicial; i < final; i++) {
    if (U[j] < V[k]) {
	     T[i] = U[j];
	     j++;
    } else {
	     T[i] = V[k];
	     k++;
    }
  }
}

void insercion_lims(int T[], int inicial, int final) {
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; ++i) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      --j;
    }
  }
}

inline void insercion(int T[], int num_elem) {
  insercion_lims(T, 0, num_elem);
}

const int UMBRAL_MS = 100;

void mergesort_lims(int T[], int inicial, int final) {
  if (final - inicial < UMBRAL_MS) {
    insercion_lims(T, inicial, final);
  } else {
    int k = (final - inicial)/2;

    int * U = new int [k - inicial + 1];
    assert(U);
    int l, l2;
    for (l = 0, l2 = inicial; l < k; l++, l2++) {
	     U[l] = T[l2];
    }
    U[l] = INT_MAX;

    int * V = new int [final - k + 1];
    assert(V);
    for (l = 0, l2 = k; l < final - k; l++, l2++) {
	     V[l] = T[l2];
    }
    V[l] = INT_MAX;

    mergesort_lims(U, 0, k);
    mergesort_lims(V, 0, final - k);
    fusion(T, inicial, final, U, V);
    delete [] U;
    delete [] V;
  }
}

void mergesort(int T[], int num_elem) {
  mergesort_lims(T, 0, num_elem);
}

int main(int argc, char * argv[]) {
  if (argc != 2) {
    cerr << "Formato " << argv[0] << " <num_elem>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

  srandom(time(0));

  for (int i = 0; i < n; i++) {
    T[i] = random();
  }

  const int TAM_GRANDE = 10000;
  const int NUM_VECES = 1000;

  if (n > TAM_GRANDE) {
    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    start = high_resolution_clock::now();

    mergesort(T, n);

    end = high_resolution_clock::now();
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    cout << n << "\t" <<tiempo_transcurrido.count() << endl;
  } else {
    int * U = new int[n];
    assert(U);

    for (int i = 0; i < n; i++) {
      U[i] = T[i];
    }

    high_resolution_clock::time_point start_vacio, end_vacio;
    duration<double> tiempo_transcurrido_vacio;
    start_vacio = high_resolution_clock::now();
    for (int veces = 0; veces < NUM_VECES; veces++) {
      for (int i = 0; i < n; i++) {
	       U[i] = T[i];
      }
    }

    end_vacio = high_resolution_clock::now();
    tiempo_transcurrido_vacio  = duration_cast<duration<double> >(end_vacio - start_vacio);

    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    start = high_resolution_clock::now();
    for (int veces = 0; veces < NUM_VECES; veces++) {
	     for (int i = 0; i < n; i++) {
	        U[i] = T[i];
        }
        mergesort(U, n);
	  }

    end = high_resolution_clock::now();
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    cout << n << "\t" <<tiempo_transcurrido.count() - tiempo_transcurrido_vacio.count() << endl;

    delete [] U;

    }
  delete [] T;

  return 0;
}
