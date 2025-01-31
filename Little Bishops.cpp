#include <iostream>
#include <vector>
#include <functional> 

using namespace std;

void  littleBishops(int N, int K) {
    if (N == 0 && K == 0) {
        return;
    }

    vector<vector<bool>> tablero(N, vector<bool>(N, false));
    int totalSoluciones = 0;

    function<bool(int, int)> validarPosicion = [&](int fila, int col) {
        for (int i = 1; i < N; i++) {
            if (fila - i >= 0) {
                if (col - i >= 0 && tablero[fila - i][col - i]){
                    return false;
                }
                if (col + i < N && tablero[fila - i][col + i]){
                    return false;
                }
            }
            if (fila + i < N) {
                if (col - i >= 0 && tablero[fila + i][col - i]){
                    return false;
                }
                if (col + i < N && tablero[fila + i][col + i]){
                    return false;
                }
            }
        }
        return true;
    };

    function<void(int, int, int&)> backtracking;

    backtracking = [&](int index, int colocadas, int &total) {
        if (colocadas == K) {
            total++;
            return;
        }

        for (int pos = index; pos < N * N; pos++) {
            int fila = pos / N;
            int col = pos % N;

            if (tablero[fila][col]) {
                continue;
            }
            if (!validarPosicion(fila, col)) {
                continue;
            }

            tablero[fila][col] = true;
            backtracking(pos + 1, colocadas + 1, total);
            tablero[fila][col] = false;
        }
    };

    backtracking(0, 0, totalSoluciones);
    cout << totalSoluciones << endl;
}

int main() {

    while (true) {
        int N, K;
        cin >> N >> K;

        if (N == 0 && K == 0) {
            break;
        }

        littleBishops(N, K); 
    }
    return 0;
}
