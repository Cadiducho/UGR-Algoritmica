#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int maximo(int a, int b) {
  return (a < b ? b : a);
}

vector<int> sumaDinamica(vector<int> valores, int M) {
  int n = valores.size() + 1 ;
  int Matriz[n][M+1];

  vector<int> opciones;
  opciones.push_back(0);
  for (unsigned i = 0; i < valores.size(); i++) {
    opciones.push_back(valores[i]);
  }

  //Inicializar la primera columna
  for (int i=0; i<n; i++) {
    Matriz[i][0] = 0;
  }
  //Inicializar la primera fila
  for (int i=0; i<M+1; i++) {
    Matriz[0][i] = 0;
  }

  int v1, v2;
  //Calcular Valores
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < M + 1; j++) {
      if (j < opciones[i]) {
        Matriz[i][j] = Matriz[i - 1][j];
      } else {
        v1 = Matriz[i - 1][j];
        v2 = (Matriz[i - 1][j - opciones[i]]) + opciones[i];
        Matriz[i][j] = maximo(v1, v2);
      }
    }
  }
  vector<int> resultado;
  return resultado;
}

void printVector(vector<int> v) {
	for(unsigned i = 0; i < v.size(); i++){
		cout << v[i] <<" ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
  ifstream f(argv[1]);
  if (!f) {
    cout << "No se ha podido abrir el archivo" << endl;
    return -1;
  }

  vector<int> v;
  while (!f.eof()) {
    int i;
    f >> i;
    v.push_back(i);
  }

  vector<int> s = sumaDinamica(v, 8);
  printVector(s);
}
