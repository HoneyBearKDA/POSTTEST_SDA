#include <iostream>
using namespace std;

int main() {
    const int n = 3;
    int matriks[n][n] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    int jumlah = 0;
    for (int j = 0; j < n; j++) {
        jumlah += matriks[1][j]; 
    }

    cout << "Jumlah elemen baris genap (baris ke-2): " << jumlah << endl;

    return 0;
}

