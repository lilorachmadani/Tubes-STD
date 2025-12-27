#include "Rent.h"
#include <limits>

int inputInt(const string& pesan) {
    int x;
    while (true) {
        cout << pesan;
        cin >> x;

        if (!cin.fail())
            return x;

        cout << "Input tidak valid. Harus berupa angka.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    int pilih;

    do {
        cout << "\n===== MENU RENTAL BARANG =====\n";
        cout << "1. Tambah Toko\n";
        cout << "2. Tambah Barang\n";
        cout << "3. Tambah Relasi Toko-Barang\n";
        cout << "4. Hapus Toko\n";
        cout << "5. Hapus Barang\n";
        cout << "6. Tampilkan Semua Toko\n";
        cout << "7. Tampilkan Barang dari Toko\n";
        cout << "8. Tampilkan Toko dari Barang\n";
        cout << "9. Toko Terbanyak & Tersedikit\n";
        cout << "0. Keluar\n";

        pilih = inputInt("Pilih: ");

        if (pilih == 1) {
            int id = inputInt("ID Toko: ");

            if (cariToko(id) != NULL) {
                cout << "ID Toko sudah terdaftar\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string nama;
            cout << "Nama Toko: ";
            getline(cin, nama);
            tambahToko(id, nama);
        }
        else if (pilih == 2) {
            int id = inputInt("ID Barang: ");

            if (cariBarang(id) != NULL) {
                cout << "ID Barang sudah terdaftar\n";
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string nama;
            cout << "Nama Barang: ";
            getline(cin, nama);
            tambahBarang(id, nama);
        }
        else if (pilih == 3) {
            int idT = inputInt("ID Toko: ");
            int idB = inputInt("ID Barang: ");
            tambahRelasi(idT, idB);
        }
        else if (pilih == 4) {
            int id = inputInt("ID Toko: ");
            hapusToko(id);
        }
        else if (pilih == 5) {
            int id = inputInt("ID Barang: ");
            hapusBarang(id);
        }
        else if (pilih == 6) {
            tampilSemuaToko();
        }
        else if (pilih == 7) {
            int id = inputInt("ID Toko: ");
            tampilBarangDariToko(id);
        }
        else if (pilih == 8) {
            int id = inputInt("ID Barang: ");
            tampilTokoDariBarang(id);
        }
        else if (pilih == 9) {
            tampilTokoTerbanyakTersedikit();
        }

    } while (pilih != 0);

    return 0;
}
