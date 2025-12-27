#include "Rent.h"
#include <iostream>
using namespace std;

Toko *firstToko = NULL;
Barang *firstBarang = NULL;
Relasi *firstRelasi = NULL;

Toko *cariToko(int idToko)
{
    Toko *p = firstToko;
    while (p != NULL)
    {
        if (p->idToko == idToko)
            return p;
        p = p->next;
    }
    return NULL;
}

Barang *cariBarang(int idBarang)
{
    Barang *p = firstBarang;
    while (p != NULL)
    {
        if (p->idBarang == idBarang)
            return p;
        p = p->next;
    }
    return NULL;
}

void tambahToko(int idToko, string namaToko)
{
    Toko *baru = new Toko;
    baru->idToko = idToko;
    baru->namaToko = namaToko;
    baru->next = firstToko;
    firstToko = baru;

    cout << "Toko berhasil ditambahkan\n";
}

void tambahBarang(int idBarang, string namaBarang)
{
    Barang *baru = new Barang;
    baru->idBarang = idBarang;
    baru->namaBarang = namaBarang;
    baru->next = firstBarang;
    firstBarang = baru;

    cout << "Barang berhasil ditambahkan\n";
}

void tambahRelasi(int idToko, int idBarang)
{
    Toko *t = cariToko(idToko);
    Barang *b = cariBarang(idBarang);

    if (t == NULL || b == NULL)
    {
        cout << "Toko atau Barang tidak ditemukan\n";
        return;
    }

    Relasi *r = firstRelasi;
    while (r != NULL)
    {
        if (r->toko == t && r->barang == b)
        {
            cout << "Relasi sudah ada\n";
            return;
        }
        r = r->next;
    }

    Relasi *baru = new Relasi;
    baru->toko = t;
    baru->barang = b;
    baru->next = firstRelasi;
    firstRelasi = baru;

    cout << "Relasi berhasil ditambahkan\n";
}
