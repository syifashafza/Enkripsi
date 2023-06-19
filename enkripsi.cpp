#include <cstdlib>
#include <iostream>
#include <cstring>

#define maks 500

using namespace std;

class Enkripsi {
public:
    Enkripsi();
    void enkripsi();
    void deskripsi();
    void output();

private:
    char chiper[maks];
    int key;
    char plain[maks];
};

Enkripsi::Enkripsi() {
    cout << "Masukkan kata: ";
    cin.getline(chiper, sizeof(chiper));

    cout << "Masukkan key: ";
    cin >> key;

    cout << endl;
}

void Enkripsi::enkripsi() {
    for (int i = 0; i < strlen(chiper); i++) {
        cout << chiper[i] << "(" << int(chiper[i]) << ")";
        chiper[i] = (chiper[i] + key) % 128;
    }
}

void Enkripsi::deskripsi() {
    for (int i = 0; i < strlen(chiper); i++) {
        plain[i] = (chiper[i] - key) % 128;
        chiper[i] = plain[i];
    }
}

void Enkripsi::output() {
    for (int i = 0; i < strlen(chiper); i++) {
        cout << chiper[i];
    }
}

int main(int argc, char* argv[]) {
    Enkripsi deskripsi;
    deskripsi.enkripsi();

    cout << "\n\nSetelah diEnkripsi: ";
    deskripsi.output();

    deskripsi.deskripsi();
    cout << "\n\nKembali diDeskripsi: ";
    deskripsi.output();

    cout << endl << endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

