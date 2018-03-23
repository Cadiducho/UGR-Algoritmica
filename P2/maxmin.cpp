#include <utility>
#include <iostream>

using namespace std;

pair<int, int> max_min(int * v, int size);
pair<int, int> max_min(int ** m, int size);

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

  cout << " ========= " << endl;

  int ** matriz = new int*[10];
  for (int i = 0; i < 10; i++) {
    matriz[i] = new int[10];
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      matriz[i][j] = rand() % 100 + 1;
  }

  pair<int, int> paresM = max_min(matriz, 10);
  cout << "Max: " << paresM.second << endl;
  cout << "Min: " << paresM.first << endl;

  for (int i = 0; i < 10; i++) {
    delete[] matriz[i];
  }
  delete matriz;
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

pair<int, int> max_min(int ** m, int size) {
  if (size == 1) {
    pair<int, int> par;
    par.first = m[0][0];
    par.second = m[0][0];
    return par;
  } else {
    pair<int, int> m1 = max_min(m, size / 4);
    pair<int, int> m2 = max_min(m + size / 4, size - size / 4);
    pair<int, int> m3 = max_min(m + 2 * (size / 4), size - 2 * (size / 4));
    pair<int, int> m4 = max_min(m + 3 * (size / 4), size - 3 * (size / 4));
    pair<int, int> par;

    int primerMenor = m1.first < m2.first ? m1.first : m2.first;
    int segundoMenor = m3.first < m4.first ? m3.first : m4.first;
    par.first = primerMenor < segundoMenor ? primerMenor : segundoMenor;

    int primerMayor = m1.second > m2.second ? m1.second : m2.second;
    int segundoMayor = m3.second > m4.second ? m3.second : m4.second;
    par.second = primerMayor > segundoMayor ? primerMayor : segundoMayor;

    return par;
  }
}
