#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

void bubbleSort(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (mhs[j].ipk > mhs[j+1].ipk) {
                swap(mhs[j], mhs[j+1]);
            }
        }
    }
}

int main() {
    const int n = 4;
    Mahasiswa mhs[n];

    cout << "Input data 4 mahasiswa:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i+1 << endl;
        cout << "Nama : "; getline(cin, mhs[i].nama);
        cout << "NIM  : "; getline(cin, mhs[i].nim);
        cout << "IPK  : "; cin >> mhs[i].ipk;
        cin.ignore();
    }

    bubbleSort(mhs, n);

    cout << "\nData mahasiswa setelah diurutkan (ascending IPK):" << endl;
    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << " | " << mhs[i].nim << " | " << mhs[i].ipk << endl;
    }

    return 0;
}

