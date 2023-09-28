#include <iostream>
using namespace std;

const int N = 10;
int arr[N];
int ant = 0; // Number of unique solutions found.

int createInt(int a[], int m, int n) {
    int number = 0;
    for (int i = m; i <= n; i++)
        number = number * 10 + a[i];
    return number;
}

void check(int a[]) {
    int b = createInt(a, 0, 2);
    int c = createInt(a, 3, 5);
    int d = createInt(a, 6, N - 1);

    if (b + c == d && b < c) {
        cout << ++ant << ": " << b << " + " << c << " = " << d << "\n";
    }
}

void swap(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

void rotateLeft(int a[], int i) {
    int x, k;
    x = a[i];

    for (k = i + 1; k < N; k++) {
        a[k - 1] = a[k];
    }
    a[N - 1] = x;
}

void perm(int i) {
    int t;
    if (i == N - 1)
        check(arr);
    else {
        if (arr[6] != 0) {
            perm(i + 1);
        }
        for (t = i + 1; t < N; t++) {
            swap(arr[i], arr[t]);
            if (arr[6] != 0)
                perm(i + 1);
            }
        rotateLeft(arr, i);
    }
}

int main() {
    for (int i = 0; i < N - 1; i++) {
        arr[i] = i + 1;
    }
    arr[N - 1] = 0;

    perm(0);

    cout << "\n\n";
    return 0;
}