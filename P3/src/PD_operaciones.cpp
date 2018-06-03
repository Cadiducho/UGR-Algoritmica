#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct elemento{
  char signo;
  int numero;
};

elemento maximo(elemento a, elemento b, elemento c, elemento d, elemento e){
  elemento max = a;
  if (max.numero < b.numero) {
    max = b;
  }
  if (max.numero < c.numero) {
    max = c;
  }
  if (max.numero < d.numero) {
    max = d;
  }
  if (max.numero < e.numero) {
    max = e;
  }
  return max;
}

vector<int> calculoDinamico(vector<int> valores, int M){
  int n = valores.size() + 1 ;
  elemento Matriz[n][M+1];

  vector<int> opciones;
  opciones.push_back(0);
  for (unsigned i = 0; i < valores.size(); i++){
    opciones.push_back(valores[i]);
  }

  //Inicializar la primera columna
  for (int i=0; i<n; i++){
    Matriz[i][0].numero = 0;
  }
  //Inicializar la primera fila
  for (int i=0; i<M+1; i++){
    Matriz[0][i].numero = 0;
  }

  elemento v1, v2, v3, v4, v5;
  //Calcular Valores
  for (int i=1; i<n; i++){
    for(int j=1; j<M+1; j++){
      if ( j < opciones[i] )
        Matriz[i][j] = Matriz[i-1][j];
      else{
        v1.numero = Matriz[i-1][j].numero;
        v1.signo = Matriz[i-1][j].signo;
        v2.numero = (Matriz[i-1][j-opciones[i]].numero)+opciones[i];
        v2.signo = '+';
        v3.numero = (Matriz[i-1][j+opciones[i]].numero)-opciones[i];
        v3.signo = '-';
        v4.numero = (Matriz[i-1][j/opciones[i]].numero)*opciones[i];
        v4.signo = '*';
        v5.numero = (Matriz[i-1][j*opciones[i]].numero)/opciones[i];
        v5.signo = '/';

        Matriz[i][j] = maximo(v1, v2, v3, v4, v5);
      }
    }
  }

  //Mostrar Matriz
  for (int i=0; i<n; i++){
    cout << opciones[i] <<"\t\t";
    for (int j=0; j<M+1; j++){
		    cout << Matriz[i][j].numero <<"\t";
    }
    cout << endl;
	}
	cout << endl << endl;

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

  vector<int> s = calculoDinamico(v, 8);
  printVector(s);
}
