#include <iostream>

int PanjangPesan(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char input[10000];
    std::cout << "masukkan pesan: ";
    std::cin >> input;

    int len = PanjangPesan(input);
    
    if (len > 0) {
        std::cout << "pesan terenkripsi: ";
        std::cout << input[0];
        for (int i = 1; i < len; ++i) {
            int HurufAsli = input[i] - 'A';
            int pergeseran = input[i - 1] - 'A' + 1;
            int HurufBaru = (HurufAsli + pergeseran) % 26;
            char KalimatBaru = 'A' + HurufBaru;
            std::cout << KalimatBaru;
        }
        std::cout << '\n';
    }

    return 0;
}