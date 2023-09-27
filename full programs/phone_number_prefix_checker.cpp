#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 20;

int tlf[N] {12345675, 12345676, 12345677, 12345678, 12345679,
            12345550, 12345551, 12345552, 12345553, 12345554,
            12345555, 12345556, 12345557, 12345558, 12345559, 1234556, 1234557, 123456, 1234558, 1234559 };

// The third-to-last element is a prefix of (several) others.

// Method 1 - Algorithm:
// Remove one digit at a time from the end of each number.
// Check that, for each iteration, the "new" number is not among the others in the array.

bool check1() {
    for (int i = 0; i < N - 1; i++) {
        int num = tlf[i];
        while (num >= 100) {
            // Go through all the numbers (except the last one):
            // Get the original number.
            // While there are at least three digits left:
            for (int j = i + 1; j < N; j++) {
                // Go through ALL the subsequent numbers:
                if (num == tlf[j]) {
                    return false; // Are the numbers the same? Return false.
                }
                // Remove the last digit (i.e., divide by 10).
                num /= 10;
            }
        }
    }
    return true;
}

/* Everything went well (no prefixes), return true.

// Method 2 - Algorithm:
// Sort all the numbers (converted to strings) lexicographically.
// Then, check that no number is a prefix of ONLY the next number in the array.

bool check2() {
    // Convert integers to strings for sorting.
    string tlfStrings[N];
    for (int i = 0; i < N; i++) {
        tlfStrings[i] = to_string(tlf[i]);
    }

    // Sort the strings lexicographically.
    sort(tlfStrings, tlfStrings + N);

    for (int i = 0; i < N - 1; i++) {
        if (tlfStrings[i + 1].find(tlfStrings[i]) == 0) {
            return false; // If a number is a prefix of ONLY the next number, return false.
        }
    }

    return true;
}
*/

int main() {
    cout << (check1() ? "OK" : "NOT OK") << "\n\n";
    //cout << (check2() ? "OK" : "NOT OK") << "\n\n";
    return 0;
}

