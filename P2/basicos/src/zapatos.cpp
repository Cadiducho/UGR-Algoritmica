#include <utility>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int Pivote (int *v, int primero, int ultimo);
void QuickSort (int * v,int inicio, int fin);

const int N = 16;

int main() {
  int * zapatos = new int[N];
  int * pies = new int[N];

  srand (time(NULL));
  for (int i = 0; i < N; i++) {
    zapatos[i] = rand() % 45;
    pies[i] = rand() % 45;
  }

  int pivote = rand() % N;
  QuickSort(zapatos, 0, pivote - 1);
  QuickSort(zapatos, pivote + 1, N);

  delete[] zapatos;
  delete[] pies;
}

void QuickSort (int * v, int inicio, int fin) {
  int pos_pivote;

  if (inicio < fin) {
    pos_pivote = Pivote(v, inicio, fin);

    //Ordena primera mitad
    QuickSort (v, inicio, pos_pivote-1);
    //Ordena segunda mitad
    QuickSort (v, pos_pivote + 1, fin);
  }
}

int Pivote (int *v, int primero, int ultimo) {
  int intercambia, izda, cha;
  int pivote = v[primero];

  int i = primero + 1; //avanza hacia delante
  int d = ultimo; //retrocede hacia atras

  while (i <= d) {
    while (i <= d && v[i] <= pivote)
      i++;

    while (i <= d && v[d] > pivote)
      d--;

    if (i < d) {
      intercambia = v[i];
      v[i] = v[d];
      v[d] = intercambia;
      d--;
      i++;
    }
  }
  intercambia = v[primero];
  v[primero] = v[d];
  v[d] = intercambia;

  return d;
}
