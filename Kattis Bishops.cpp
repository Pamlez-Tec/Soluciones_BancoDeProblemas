#include <iostream>

using namespace std;

void kattisBishops(int N) {
    if (N == 1) {
        cout << 1 << endl;
    } else {
        cout << 2 * (N -1) << endl;
    }
}

int main() {
    int N;
    while (cin >> N) {
        kattisBishops(N);
    }
    return 0;
}
