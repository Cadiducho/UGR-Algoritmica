#include <iostream>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insercion_lims(int T[], int inicial, int end) {
  int i, j;
  int aux;
  for (i = inicial + 1; i < end; ++i) {
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

  insercion(T, n);
  
  end = high_resolution_clock::now();
  tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  cout << n << "\t" <<tiempo_transcurrido.count() << endl;

  delete [] T;

  return 0;
}
