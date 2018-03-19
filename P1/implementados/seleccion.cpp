#include <iostream>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

void seleccion_lims(int T[], int inicial, int final) {
  int i, j, indice_menor;
  int menor, aux;
  for (i = inicial; i < final - 1; i++) {
    indice_menor = i;
    menor = T[i];
    for (j = i; j < final; j++) {
      if (T[j] < menor) {
	       indice_menor = j;
	       menor = T[j];
      }
    }
    aux = T[i];
    T[i] = T[indice_menor];
    T[indice_menor] = aux;
  }
}

void seleccion(int T[], int num_elem) {
  seleccion_lims(T, 0, num_elem);
}

int main(int argc, char * argv[]){
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

  const int TAM_GRANDE = 2000;
  const int NUM_VECES = 100;

  if (n > TAM_GRANDE) {
    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    start = high_resolution_clock::now();

    seleccion(T, n);

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
	    seleccion(U, n);
	  }
    end = high_resolution_clock::now();
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    cout << n << "\t" <<tiempo_transcurrido.count() - tiempo_transcurrido_vacio.count() << endl;

    delete [] U;
  }

  delete [] T;

  return 0;
}
