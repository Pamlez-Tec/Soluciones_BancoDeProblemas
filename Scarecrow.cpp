#include <iostream>
using namespace std;

void scarecrow() {
    int tamanoCampo;
    cin >> tamanoCampo;

    string campo;
    cin >> campo;

    int espantapajaros = 0, numCaso = 1;

    for (int i = 0; i < tamanoCampo; ) {
        if (campo[i] == '.') {
            espantapajaros++;
            i += 3; 
        } else {
            i++; 
        }
    }
    cout << "Caso " << numCaso++ << ": " << espantapajaros << endl;
}


int main() {

    int numCasos;
    cin >> numCasos;

    while (numCasos--) {
        scarecrow();
    }

    return 0;
}

