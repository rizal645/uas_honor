#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// 1. Menggunakan struct untuk menyimpan data Pegawai
struct Pegawai {
    string nama;
    int jamKerja;
    int honorHarian = 25000;
    int honorLembur;
    int totalGaji;
};

// 2. Menggunakan class untuk menghitung gaji
class KalkulatorGaji {
public:
    void hitung(Pegawai *p) {
        // Aturan: Honor harian Rp 25.000 untuk 8 jam pertama
        // Lembur jika jam kerja > 8 jam
        if (p->jamKerja > 8) {
            int jamLembur = p->jamKerja - 8;
            p->honorLembur = jamLembur * 1500;
        } else {
            p->honorLembur = 0;
        }
        p->totalGaji = p->honorHarian + p->honorLembur;
    }
};

void tampilkanTabel(Pegawai* daftar, int jumlah) {
    int totalSeluruhnya = 0;
    cout << "\nPT. Meriang Gembira" << endl;
    cout << "Tanggal : 12 Januari 2026" << endl;
    cout << "======================================================================" << endl;
    cout << left << setw(4) << "No." << setw(15) << "Nama" << setw(12) << "Honor" 
         << setw(12) << "Jam Kerja" << setw(15) << "Honor Lembur" << "Total" << endl;
    cout << "======================================================================" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << left << setw(4) << (i + 1) 
             << setw(15) << daftar[i].nama 
             << setw(12) << daftar[i].honorHarian 
             << setw(12) << daftar[i].jamKerja 
             << setw(15) << daftar[i].honorLembur 
             << daftar[i].totalGaji << endl;
        totalSeluruhnya += daftar[i].totalGaji;
    }

    cout << "======================================================================" << endl;
    cout << "Total Honor Pegawai Sebesar : Rp " << totalSeluruhnya << endl;
}

int main() {
    int pilihan;
    int jumlahPegawai = 0;
    // 3. Menggunakan pointer untuk menyimpan data array dinamis
    Pegawai* daftarPegawai = nullptr;
    KalkulatorGaji kalkulator;

    do {
        cout << "\n--- MENU UTAMA ---" << endl;
        cout << "1. Input Data Pegawai" << endl;
        cout << "2. Tampilkan Laporan Gaji" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih fitur: ";
        cin >> pilihan;

        if (pilihan == 1) {
            cout << "Masukkan jumlah pegawai: ";
            cin >> jumlahPegawai;

            // Alokasi memori dinamis
            daftarPegawai = new Pegawai[jumlahPegawai];

            for (int i = 0; i < jumlahPegawai; i++) {
                cout << "\nData Pegawai ke-" << (i + 1) << endl;
                cout << "Nama: ";
                cin.ignore();
                getline(cin, daftarPegawai[i].nama);
                cout << "Total Jam Kerja: ";
                cin >> daftarPegawai[i].jamKerja;

                // Hitung menggunakan class
                kalkulator.hitung(&daftarPegawai[i]);
            }
            cout << "\nData berhasil disimpan!" << endl;

        } else if (pilihan == 2) {
            if (daftarPegawai != nullptr) {
                tampilkanTabel(daftarPegawai, jumlahPegawai);
            } else {
                cout << "Data kosong! Silakan pilih fitur 1 terlebih dahulu." << endl;
            }
        }

    } while (pilihan != 0);

    // Bebaskan memori
    delete[] daftarPegawai;
    
    return 0;
}