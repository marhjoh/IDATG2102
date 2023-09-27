#include <iostream>
using namespace std;

const int N = 1000;

int main() {
    int i, j, sum;
    int n = N / 2; // Set N to the desired value, initialize variables, and total sum so far.

    for (i = 1; i <= n; i++) {
        sum = i;
        j = i;

        while (sum < N && j <= n) {
            sum += (++j); // Update the total sum with the next number.
        }

        if (sum == N) {
            // The integer series equals exactly to N:
            cout << '\n' << N << " = sum of integers from "
                 << i << " to " << j << '\n';
        }
    }

    cout << "\n\n";
    return 0;
}
