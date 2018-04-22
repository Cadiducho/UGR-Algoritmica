#include <utility>
#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

pair<int, int> max_min(int * v, int size);

int main() {

  int * vector = new int[10];

  srand (time(NULL));
  for (int i = 0; i < 10; i++) {
    vector[i] = i + rand() % 100 + 1;
  }
  pair<int, int> pares = max_min(vector, 10);
  cout << "Max: " << pares.second << endl;
  cout << "Min: " << pares.first << endl;
  delete[] vector;
}

pair<int, int> max_min(int * v, int size) {
  if (size == 1) {
    pair<int, int> par;
    par.first = v[0];
    par.second = v[0];
    return par;
  } else {
    pair<int, int> v1 = max_min(v, size / 2);
    pair<int, int> v2 = max_min(v + size / 2, size - size / 2);
    pair<int, int> par;

    par.first = v1.first < v2.first ? v1.first : v2.first;
    par.second = v1.second > v2.second ? v1.second : v2.second;

    return par;
  }
}
