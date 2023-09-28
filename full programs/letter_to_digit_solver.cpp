#include <iostream>
using namespace std;

const int N = 9; // Total number of letters (A to I).
const int NUM_EQNS = 8; // Number of equations to solve.

int arr[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Array to store digit assignments to letters.
char oper[] = "+--++-++"; // Array to store operators of equations.
int eqn[NUM_EQNS][3] = {
        {8, 9, 8}, {1, 2, 1}, {5, 8, 1}, {3, 5, 14},
        {6, 1, 7}, {2, 4, 1}, {7, 6, 11}, {9, 3, 7}
}; // Array to store equations.

// Function to print the solution.
void printSolution(int a[]) {
    cout << "\nSolution: \n";
    for (int i = 0; i < N; i++)
        cout << '\t' << char(i + 'A') << " = " << a[i] << '\n';
}

// Function to check if the current assignments are valid.
bool check(int a[]) {
    for (int i = 0; i < NUM_EQNS; i++) {
        if (oper[i] == '+') {
            // Check if a valid addition solution.
            if (a[eqn[i][0] - 1] + a[eqn[i][1] - 1] != eqn[i][2])
                return false;
        }
        else if (oper[i] == '-') {
            // Check if a valid subtraction solution.
            if (a[eqn[i][0] - 1] - a[eqn[i][1] - 1] != eqn[i][2])
                return false;
        }
    }
    printSolution(a);
    return true;
}

// Function to swap two elements in the array.
void swap(int &a1, int &a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

// Function to rotate array elements to the left.
void rotateLeft(int a[], int i) {
    int x, k;
    x = a[i];
    for (k = i + 1; k < N; k++)
        a[k - 1] = a[k];
    a[k - 1] = x;
}

// Recursive permutation function.
void permute(int i) {
    int t;
    if (i == N - 1)
        check(arr);
    else {
        permute(i + 1);
        for (int t = i + 1; t < N; t++) {
            swap(arr[i], arr[t]);
            permute(i + 1);
        }
        rotateLeft(arr, i);
    }
}

int main() {
    permute(0);
    cout << "\n\n";
    return 0;
}
