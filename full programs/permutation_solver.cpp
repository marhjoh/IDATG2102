#include <iostream>
using namespace std;

const int N = 9;
int arr[N];

// Check if the sum of all values in a node's neighbors is evenly divisible by the value in the node itself.
bool OK(int a[], int n) {
    if (n == 2) {
        if ((a[1] + a[2]) % a[0] != 0)
            return false;
    } else if (n == 4) {
        if ((a[0] + a[2] + a[3] + a[4]) % a[1] != 0)
            return false;
    } else if (n == 5) {
        if ((a[0] + a[1] + a[4] + a[5]) % a[2] != 0)
            return false;
    } else if (n == 6) {
        if ((a[1] + a[4] + a[6]) % a[3] != 0)
            return false;
    } else if (n == 7) {
        if ((a[1] + a[2] + a[4] + a[7]) % a[5] != 0)
            return false;
    } else if (n == 8) {
        if ((a[2] + a[4] + a[5] + a[7]) % a[6] != 0)
            return false;
    } else if (n == 9) {
        if ((a[3] + a[4] + a[6] + a[8]) % a[7] != 0)
            return false;
        if ((a[4] + a[5] + a[6] + a[8]) % a[7] != 0)
            return false;
        if ((a[6] + a[7]) % a[8] != 0)
            return false;
    }
    return true;
}

// Display the contents of the array.
void display(int a[]) {
    cout << "\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << " ";
    cout << "\n";
}

// Swap two array elements.
void swap(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

// Rotate elements to the left.
void rotate_left(int a[], int i) {
    int x = a[i];
    for (int k = i + 1; k < N; k++)
        a[k - 1] = a[k];
    a[N - 1] = x;
}

// Generate permutations and find solutions.
void perm(int i) {
    int t;
    if (i == N - 1) {
        if (OK(arr, N - 1))
            display(arr);
    } else {
        if (OK(arr, i))
            perm(i + 1);
        for (t = i + 1; t < N; t++) {
            swap(arr[i], arr[t]);
            if (OK(arr, i))
                perm(i + 1);
        }
        rotate_left(arr, i);
    }
}

int main() {
    // Fill array with values 1 through 9.
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;

    // Generate permutations and display solutions.
    perm(0);

    cout << "\n\n";
    return 0;
}
