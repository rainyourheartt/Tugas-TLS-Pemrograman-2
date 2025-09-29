#include <bits/stdc++.h>
using namespace std;

bool isLetter(int x) {
    return (65 <= x && x <= 90) || (97 <= x && x <= 122);
}

// Fungsi reverse buatan sendiri
void reverseString(string &s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++; j--;
    }
}

int main() {
    string pwd;
    cin >> pwd;

    // Cari substring angka dalam sandi
    int n = pwd.size();
    int l=-1, r=-1;
    for (int i=0; i<n; i++) {
        if (isdigit(pwd[i])) {
            if (l==-1) l=i;
            r=i;
        }
    }
    if (l==-1) {
        cout << "Tidak ada angka ASCII dalam sandi\n";
        return 0;
    }
    r++; // karena index terakhir termasuk

    string numstr = pwd.substr(l, r-l);
    int asciiVal = stoi(numstr);

    if (!isLetter(asciiVal)) {
        cout << "Kode ASCII tidak valid untuk huruf\n";
        return 0;
    }

    char firstChar = (char)asciiVal;
    // Hapus substring angka
    string withoutDigits = pwd.substr(0,l) + pwd.substr(r);

    // Balik kembali konsonan
    reverseString(withoutDigits);

    cout << "Huruf pertama asli : " << firstChar << "\n";
    cout << "Urutan konsonan asli: " << withoutDigits << "\n";

    // Catatan: vokal sudah hilang → tidak bisa dipastikan kembali
    cout << "Kata asli kemungkinan: mulai dengan '" << firstChar 
         << "', sisanya cocok dengan konsonan di atas + sisipan vokal.\n";

    return 0;
}