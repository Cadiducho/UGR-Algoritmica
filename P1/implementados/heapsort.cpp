#include <iostream>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

void reajustar(int T[], int num_elem, int k) {
  int j;
  int v;
  v = T[k];
  bool esAPO = false;
  while ((k < num_elem/2) && !esAPO) {
    j = k + k + 1;
    if ((j < (num_elem - 1)) && (T[j] < T[j+1])) {
	     ++j;
    }
    if (v >= T[j]) {
	     esAPO = true;
       T[k] = T[j];
       k = j;
    }
  }
  T[k] = v;
}

void heapsort(int T[], int num_elem) {
  int i;
  for (i = num_elem/2; i >= 0; --i) {
    reajustar(T, num_elem, i);
  }
  for (i = num_elem - 1; i >= 1; --i) {
    int aux = T[0];
    T[0] = T[i];
    T[i] = aux;
    reajustar(T, i, 0);
  }
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

  heapsort(T, n);
  
  end = high_resolution_clock::now();
  tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  cout << n << "\t" <<tiempo_transcurrido.count() << endl;

  delete [] T;

  return 0;
}
