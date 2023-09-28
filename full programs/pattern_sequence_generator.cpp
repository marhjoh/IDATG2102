#include <iostream>
using namespace std;

const int N = 10;
char pattern[N];
int pairDepth = 0;
int n;

// Function to display the generated pattern.
void display() {
    for (int i = 0; i < n; i++)
        cout << pattern[i];
    cout << '\n';
}

// Recursively generates all possible and legal patterns of '(' and ')'.
void generatePattern(int i) {
    // If enough space for ending ')' is available, add '*'.
    if (i == n)
        display();
    else {
        // If there's enough space for more '*', add '*'.
        if (pairDepth < n - i) {
            pattern[i] = '*';
            generatePattern(i + 1);
        }
        // If there are more '(' than ')', add ')'.
        if (pairDepth > 0) {
            pattern[i] = ')';
            pairDepth--;
            generatePattern(i + 1);
            pairDepth++;
        }
        // If there's enough space for more '(', add '('.
        if (pairDepth + 1 < n - i) {
            pattern[i] = '(';
            pairDepth++;
            generatePattern(i + 1);
            pairDepth--;
        }
    }
}

int main() {
    do {
        cout << "Pattern length (0-" << N << "): ";
        cin >> n;
    } while (n < 0 || n > N);

    generatePattern(0);
    cout << '\n';

    return 0;
}
