#include <utility>
#include <iostream>
#include <ctime>

using namespace std;

pair<int, int> max_min(int ** m, int inicioi, int inicioj, int size);

int main() {
    int ** matriz = new int*[16];
    for (int i = 0; i < 16; i++) {
        matriz[i] = new int[16];
    }

    srand (time(NULL));
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            matriz[i][j] = rand() % 10000 + 1;
        }
    }

    pair<int, int> paresM = max_min(matriz, 0, 0, 16);
    cout << "Max: " << paresM.second << endl;
    cout << "Min: " << paresM.first << endl;

    for (int i = 0; i < 10; i++) {
        delete[] matriz[i];
    }
    delete matriz;
}

pair<int, int> max_min(int ** m, int inicioi, int inicioj, int size) {
    if (size == 1) {
        pair<int, int> par;
        par.first = m[inicioi][inicioj];
        par.second = m[inicioi][inicioj];
        return par;
    } else {
        pair<int, int> m1 = max_min(m, inicioi, inicioj, size / 2);
        pair<int, int> m2 = max_min(m, inicioi + size / 2, inicioj, size / 2);
        pair<int, int> m3 = max_min(m, inicioi, inicioj + size / 2, size / 2);
        pair<int, int> m4 = max_min(m, inicioi + size / 2, inicioj + size / 2, size / 2);
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
