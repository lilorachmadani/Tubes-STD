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
