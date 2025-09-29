#include <iostream>
using namespace std;

string warnaLampu(long long t) {
    int cycle = 103; // total durasi siklus
    int offset = 45; // mulai kuning pada detik ke-45
    int pos = (t - offset) % cycle;
    if (pos < 0) pos += cycle; // biar aman kalau t < offset

    if (pos < 3) return "Kuning";
    else if (pos < 83) return "Merah";
    else return "Hijau";
}

int main() {
    long long times[] = {80, 135, 150, 212};
    for (long long t : times) {
        cout << "Detik " << t << " -> " << warnaLampu(t) << endl;
    }
    return 0;
}