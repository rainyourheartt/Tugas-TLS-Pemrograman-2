#include <iostream>
using namespace std;

// Fungsi untuk membalik bilangan bulat (matematis)
int reverseNumber(int x) {
    if (x == 0) return 0; // khusus untuk 0

    int sign = (x < 0) ? -1 : 1;
    x = (x < 0) ? -x : x; // ambil nilai mutlak

    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }

    return rev * sign;
}

int main() {
    int n;
    cin >> n; // panjang array

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += reverseNumber(arr[i]); // indeks genap → dibalik
        } else {
            sum += arr[i]; // indeks ganjil → tetap
        }
    }

    cout << sum << endl;
    return 0;
}