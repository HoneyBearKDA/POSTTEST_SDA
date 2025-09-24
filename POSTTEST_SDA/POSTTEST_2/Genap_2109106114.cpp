#include <bits/stdc++.h>
using namespace std;

struct Flight {
    string kodePenerbangan;
    string tujuan;
    string status;
    Flight* next;
    Flight(string k, string t, string s): kodePenerbangan(k), tujuan(t), status(s), next(nullptr) {}
};

Flight* head = nullptr;
int addedCount = 0; 
const string baseCode = "JT-114";
const int insertPosition = 4 + 1; 

void showHeader() {
    cout << "+------------------------------------------------------------+\n";
    cout << "|         FLIGHT SCHEDULE SYSTEM                              |\n";
    cout << "|      [ Gilbran Akmal - 114 ]                                |\n";
    cout << "+------------------------------------------------------------+\n";
}

string generateCode() {
    if (addedCount == 0) {
        addedCount++;
        return baseCode;
    } else {
        string code = baseCode + "-" + to_string(addedCount);
        addedCount++;
        return code;
    }
}

void addSchedule() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string tujuan, status;
    cout << "Masukkan tujuan: ";
    getline(cin, tujuan);
    cout << "Masukkan status (misal: Tepat Waktu / Terlambat / Naik Pesawat): ";
    getline(cin, status);

    string kode = generateCode();
    Flight* node = new Flight(kode, tujuan, status);

    
    if (!head) head = node;
    else {
        Flight* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
    cout << "Jadwal ditambahkan dengan kode: " << kode << "\n";
}

int lengthList() {
    int cnt = 0; Flight* cur = head;
    while (cur) { cnt++; cur = cur->next; }
    return cnt;
}

void insertAtSpecific() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "(Posisi sisip otomatis berdasarkan digit NIM) " << "Posisi yang digunakan: " << insertPosition << "\n";
    string tujuan, status;
    cout << "Masukkan tujuan: "; getline(cin, tujuan);
    cout << "Masukkan status: "; getline(cin, status);

    string kode = generateCode();
    Flight* node = new Flight(kode, tujuan, status);

    int pos = insertPosition;
    if (pos <= 1) {
        node->next = head;
        head = node;
        cout << "Disisipkan di posisi 1 dengan kode: " << kode << "\n";
        return;
    }

    int len = lengthList();
    if (pos > len + 1) {
        Flight* cur = head;
        if (!cur) head = node;
        else {
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
        cout << "Posisi melebihi panjang list. Jadwal ditambahkan di akhir dengan kode: " << kode << "\n";
        return;
    }

    Flight* cur = head;
    for (int i = 1; i < pos-1 && cur; ++i) cur = cur->next; 
    if (!cur) {
        node->next = head;
        head = node;
        cout << "Disisipkan di posisi awal (list kosong) dengan kode: " << kode << "\n";
    } else {
        node->next = cur->next;
        cur->next = node;
        cout << "Disisipkan di posisi " << pos << " dengan kode: " << kode << "\n";
    }
}

void deleteEarliest() {
    if (!head) {
        cout << "List kosong. Tidak ada jadwal untuk dihapus.\n";
        return;
    }
    Flight* toDel = head;
    head = head->next;
    cout << "Menghapus jadwal paling awal: " << toDel->kodePenerbangan << " (" << toDel->tujuan << ")\n";
    delete toDel;
}

void updateStatus() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (!head) {
        cout << "List kosong. Tidak ada jadwal untuk diupdate.\n";
        return;
    }
    string kode;
    cout << "Masukkan kode penerbangan yang ingin diupdate (misal: JT-114 atau JT-114-1): ";
    getline(cin, kode);

    Flight* cur = head;
    while (cur) {
        if (cur->kodePenerbangan == kode) break;
        cur = cur->next;
    }
    if (!cur) {
        cout << "Kode tidak ditemukan. Pastikan kode benar.\n";
        return;
    }
    string newStatus;
    cout << "Masukkan status baru: ";
    getline(cin, newStatus);
    cur->status = newStatus;
    cout << "Status untuk " << kode << " berhasil diupdate menjadi: " << newStatus << "\n";
}

void displayAll() {
    if (!head) {
        cout << "Tidak ada jadwal.\n";
        return;
    }
    cout << "+------------------------------------------------------------+\n";
    cout << "| Kode\t\t| Tujuan\t\t| Status\n";
    cout << "+------------------------------------------------------------+\n";
    Flight* cur = head;
    while (cur) {
        cout << cur->kodePenerbangan << "\t| " << cur->tujuan << "\t| " << cur->status << "\n";
        cur = cur->next;
    }
    cout << "+------------------------------------------------------------+\n";
}

int main() {
    int choice;
    do {
        showHeader();
        cout << "| 1. Tambah Jadwal Penerbangan            |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan          |\n";
        cout << "| 3. Hapus Jadwal Paling Awal             |\n";
        cout << "| 4. Update Status Penerbangan            |\n";
        cout << "| 5. Tampilkan Semua Jadwal               |\n";
        cout << "| 0. Keluar                               |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Silakan masukkan angka menu.\n";
            continue;
        }
        switch (choice) {
            case 1: addSchedule(); break;
            case 2: insertAtSpecific(); break;
            case 3: deleteEarliest(); break;
            case 4: updateStatus(); break;
            case 5: displayAll(); break;
            case 0: cout << "Keluar...\n"; break;
            default: cout << "Pilihan tidak tersedia.\n";
        }
        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    } while (choice != 0);

    while (head) {
        Flight* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}
