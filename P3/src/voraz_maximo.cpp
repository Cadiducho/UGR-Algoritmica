#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

/**
 * Calcular si una combinacion del vector s puede llegar a dar M
 */
bool factible(int x, vector<int> s, int M) {
  int sumaM=0;
  int n=s.size();
  for(int i=0; i<n; i++) {
    sumaM += s[i];
  }
  sumaM += x;
  if (sumaM == M) {
    return true;
  }
  return false;
}

/**
 * Selecciona el mayor del vector v
 */
int seleccion(vector<int> v) {
	int max = v[0];
	int n = v.size();
  for (int i=0; i < n; i++) {
		if (max < v[i]) max = v[i];
	}
	return max;
}

/**
 * Calcula el objetivo
 * S -> soluciones
 * c -> conjunto de numeros
 * M -> suma a lograr
 */
bool objetivo(vector<int> &S, vector<int> c, int M) {
  int cantidad_actual = 0;
  while (c.size() != 0 && cantidad_actual <= M) {
		int x = seleccion(c);
    cout << "Selecciono " << x << endl;
    c.erase(find(c.begin(), c.end(), x));
		if (factible(x, S, M)) {
      cout << "Factible " << x << endl;
      S.push_back(x);
      cantidad_actual += x;
		}

    if (cantidad_actual == M) {
      cout << "Objetivo Encontrado" << endl;
      return true;
    } else if(c.size() == 0) {
      cout << "No hay numero posible" << endl;
      return true;
    }
	}
  return false;
}

void mostrar(vector<int> v) {
  int n=v.size();
	for(int i=0; i<n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "Introduce archivo y número a buscar" << endl;
    exit(-1);
  }
	vector<int> v, s;

  ifstream f(argv[1]);
  if (!f) {
    cout << "No se ha podido abrir el archivo" << endl;
    return -1;
  }

  while (!f.eof()) {
    int i;
    f >> i;
    v.push_back(i);
  }

  int num = atoi(argv[2]);

  if (objetivo(s, v, num)) {
    mostrar(s);
  } else {
    cout << "Objetivo no encontrado" << endl;
  }
}
