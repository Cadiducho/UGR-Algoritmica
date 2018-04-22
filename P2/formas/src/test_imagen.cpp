#include "imagen.h"
#include <fstream>

int contarFormas(Imagen & img, Imagen & forma, int inicioi, int inicioj, int tam_imagen, int tam_forma);
int barrido(Imagen & img, Imagen & forma, int inicioi, int j, int tam_imagen, int tam_forma);
inline int max(int a, int b) { return (a < b) ? b : a; }
bool comprobarIgual(Imagen & img, Imagen & forma);
void limpiar(Imagen & img);

int main(int argc, char * argv[]){
  if (argc!=3){
      cout<<"Los parametros son: ";
     cout<<"1.-Dime el nombre de una imagen"<<endl;
     cout<<"2.-Dime el nombre de una forma"<<endl;
     return 0;
  }

  Imagen I,forma;
  I.LeerImagen(argv[1]);
  forma.LeerImagen(argv[2]);

  //Vuestro codigo para implementar la funcion que busca la forma en I
  int tam_imagen = max(I.num_filas(), I.num_cols());
  int tam_forma = max(forma.num_filas(), forma.num_cols());
  cout << "En esta imagen hay " << contarFormas(I, forma, 0, 0, tam_imagen, tam_forma) << " formas encontradas" << endl;

}

int contarFormas(Imagen & img, Imagen & forma, int inicioi, int inicioj, int tam_imagen, int tam_forma) {
  if (tam_imagen < tam_forma) {
    return 0;
  } else if (tam_imagen == tam_forma) {
    if (comprobarIgual(img, forma)) {
      limpiar(img);
      return 1;
    }
    return 0;
  } else {
    int m1 = contarFormas(img, forma, inicioi, inicioj, tam_imagen/2, tam_forma);
    int m2 = contarFormas(img, forma, inicioi, inicioj+tam_imagen/2, tam_imagen/2, tam_forma);
    int m3 = contarFormas(img, forma, inicioi+tam_imagen/2, inicioj, tam_imagen/2, tam_forma);
    int m4 = contarFormas(img, forma, inicioi+tam_imagen/2, inicioj+tam_imagen/2, tam_imagen/2, tam_forma);

    int mitad = inicioj + tam_imagen / 2;
    int sum = 0, ext_izq = mitad - tam_forma - 1, ext_der = mitad + tam_forma - 1;

    if (ext_izq < inicioj)
      ext_izq = inicioj;
    if (ext_der > inicioj + tam_imagen)
      ext_der = inicioj + tam_imagen;

    for (int j = ext_izq; j <= ext_der; ++j) {
      sum += barrido(img, forma, inicioi, j, tam_imagen, tam_forma);
    }

    return sum + m1 + m2 + m3 + m4;
  }
}

bool comprobarIgual(Imagen & img, Imagen & forma) {
  bool igual = true;
  for (int i = 0; i < img.num_filas() && igual; ++i) {
    for (int j = 0; j < img.num_cols() && igual; ++j) {
      if (img(i,j) != forma(i,j)) {
        igual = false;
      }
    }
  }
  return igual;
}

void limpiar(Imagen & img) {
  for (int i = 0; i < img.num_filas(); ++i) {
    for (int j = 0; j < img.num_cols(); ++j) {
      img(i,j) = 0;
    }
  }
}

int barrido(Imagen & img, Imagen & forma, int inicioi, int j, int tam_imagen, int tam_forma) {
  return 0;
}
