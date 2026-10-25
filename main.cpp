#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    
    // ==================== SIMULASI SOAL 1 ====================
    // Data input tiruan yang disesuaikan dengan contoh output gambar 1
    infotype dataInput[4] = {
        {"D001", "hitam", 90},
        {"D003", "putih", 70},
        {"D001", "merah", 80}, // Ini akan memicu pesan "sudah terdaftar"
        {"D004", "kuning", 90}
    };

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan nomor polisi: " << dataInput[i].nopol << endl;
        cout << "Masukkan warna kendaraan: " << dataInput[i].warna << endl;
        cout << "Masukkan tahun kendaraan: " << dataInput[i].thnBuat << endl;
        
        if (isNopolExists(L, dataInput[i].nopol)) {
            cout << "nomor polisi sudah terdaftar\n" << endl;
        } else {
            address P = alokasi(dataInput[i]);
            if (P != nullptr) {
                insertLast(L, P);
            }
            cout << endl;
        }
    }
    
    // ==================== SIMULASI SOAL 2 ====================
    cout << "========================================" << endl;
    string cariNopol = "D001";
    cout << "Masukkan Nomor Polisi yang dicari : " << cariNopol << "\n" << endl;
    
    infotype kriteriaCari;
    kriteriaCari.nopol = cariNopol;
    address hasilCari = findElm(L, kriteriaCari);
    
    if (hasilCari != nullptr) {
        cout << "Nomor Polisi : " << hasilCari->info.nopol << endl;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan." << endl;
    }
    cout << "========================================\n" << endl;

    // ==================== SIMULASI SOAL 3 ====================
    string hapusNopol = "D003";
    cout << "Masukkan Nomor Polisi yang akan dihapus : " << hapusNopol << endl;
    
    infotype kriteriaHapus;
    kriteriaHapus.nopol = hapusNopol;
    address targetHapus = findElm(L, kriteriaHapus);
    
    if (targetHapus != nullptr) {
        address P_deleted = nullptr;
        
        // Memilih prosedur delete yang tepat berdasarkan lokasi data
        if (targetHapus == L.First) {
            deleteFirst(L, P_deleted);
        } else if (targetHapus == L.Last) {
            deleteLast(L, P_deleted);
        } else {
            deleteAfter(targetHapus->prev, P_deleted);
        }
        
        if (P_deleted != nullptr) {
            cout << "Data dengan nomor polisi " << hapusNopol << " berhasil dihapus.\n" << endl;
            dealokasi(P_deleted);
        }
    } else {
        cout << "Data yang akan dihapus tidak ditemukan.\n" << endl;
    }
    
    // Menampilkan isi list akhir setelah penghapusan
    cout << "DATA LIST 1" << endl;
    printInfo(L);
    
    return 0;
}
