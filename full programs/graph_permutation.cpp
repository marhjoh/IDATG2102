#include <iostream>
using namespace std;

const int NODES = 10;

int adjacencyMatrix[NODES][NODES] =
        {{0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
         {1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
         {1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
         {0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
         {0, 0, 1, 0, 0, 0, 1, 1, 0, 0},
         {0, 1, 1, 0, 1, 1, 0, 1, 1, 1},
         {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
         {1, 0, 0, 0, 1, 0, 1, 0, 0, 1},
         {0, 0, 0, 0, 1, 0, 1, 1, 1, 0} };

int sum[NODES] = {21, 33, 14, 27, 1, 14, 20, 12, 28, 20};
int arr[NODES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool check(int a[]) {
    // Check if a valid solution.
    int i, j, total;

    for (i = 0; i < NODES; i++) {
        // Iterate through all nodes:
        total = 0;

        // Reset the total sum.
        for (j = 0; j < NODES; j++)
            if (adjacencyMatrix[i][j]) total += a[j];

        // Iterate through the node's neighbors: Sum them up.
        if (total != sum[a[i]]) return false; // Incorrect total sum? Abort.
    }

    // Found a solution:
    for (i = 0; i < NODES; i++) cout << "\nIndex no." << i << ": " << a[i];
    cout << "\n\n";
    return true;
}

void swap(int & a1, int & a2) {
    int temp = a1;
    a1 = a2;
    a2 = temp;
}

void rotateLeft(int a[], int i) {
    int x, k;

    // Store the first element.
    x = a[i];

    for (k = i + 1; k < NODES; k++)
        a[k - 1] = a[k];

    // Iterate and shift elements to the left.
    a[NODES - 1] = x; // Place the first element at the end.
}

void permute(int i) {
    int t;

    if (i == NODES - 1)
        check(arr);
    else {
        permute(i + 1);

        for (t = i + 1; t < NODES; t++) {
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
