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

void hapusToko(int idToko)
{
    Toko *p = firstToko, *prev = NULL;

    while (p != NULL && p->idToko != idToko)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Toko tidak ditemukan\n";
        return;
    }

    if (prev == NULL)
        firstToko = p->next;
    else
        prev->next = p->next;

    Relasi *r = firstRelasi, *pr = NULL;
    while (r != NULL)
    {
        if (r->toko == p)
        {
            if (pr == NULL)
                firstRelasi = r->next;
            else
                pr->next = r->next;

            Relasi *hapus = r;
            r = r->next;
            delete hapus;
        }
        else
        {
            pr = r;
            r = r->next;
        }
    }

    delete p;
    cout << "Toko dan relasinya berhasil dihapus\n";
}

void hapusBarang(int idBarang)
{
    Barang *p = firstBarang, *prev = NULL;

    while (p != NULL && p->idBarang != idBarang)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Barang tidak ditemukan\n";
        return;
    }

    if (prev == NULL)
        firstBarang = p->next;
    else
        prev->next = p->next;

    Relasi *r = firstRelasi, *pr = NULL;
    while (r != NULL)
    {
        if (r->barang == p)
        {
            if (pr == NULL)
                firstRelasi = r->next;
            else
                pr->next = r->next;

            Relasi *hapus = r;
            r = r->next;
            delete hapus;
        }
        else
        {
            pr = r;
            r = r->next;
        }
    }

    delete p;
    cout << "Barang dan relasinya berhasil dihapus\n";
}
