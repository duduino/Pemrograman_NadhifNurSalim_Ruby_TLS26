#include <iostream>

int main() {
    int N, K;
    
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai awal K: ";
    std::cin >> K;
    
    bool* aktif = new bool[N];
    for (int i = 0; i < N; ++i) {
        aktif[i] = true;
    }
    
    int sisa = N;
    int indeks = 0;
    
    std::cout << "Urutan eliminasi: ";
    
    while (sisa > 1) {
        int langkah = K - 1;
        
        while (langkah > 0) {
            indeks = (indeks + 1) % N;
            if (aktif[indeks]) {
                langkah--;
            }
        }
        
        int nomor_eliminasi = indeks + 1;
        aktif[indeks] = false;
        std::cout << nomor_eliminasi << " ";
        
        if (nomor_eliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }
        
        if (K < 2) {
            K = 2;
        }
        
        sisa--;
        
        if (sisa > 0) {
            while (!aktif[indeks]) {
                indeks = (indeks + 1) % N;
            }
        }
    }
    
    std::cout << "\n";
    
    for (int i = 0; i < N; ++i) {
        if (aktif[i]) {
            std::cout << "Astronot terakhir yang bertahan: " << i + 1 << "\n";
            break;
        }
    }
    
    delete[] aktif;
    return 0;
}