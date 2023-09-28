#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 9;
const int N = 8;

// Arrays used for testing prefixA, prefixB, and prefixC functions
char txte[N][LEN] = { "0403", "05043", "05047", "113", "1143", "11612345", "11812345", "62529903" };
char txt1[N][LEN] = { "0403", "05043", "05047", "113", "1134", "11612345", "11812345", "62529903" };
char txt2[N][LEN] = { "0403", "05043", "050437", "113", "1143", "11612345", "11812345", "62529903" };

int num[][N] = {
        { 113, 403, 1143, 5043, 5047, 11612345, 11812345, 62529903 },
        { 113, 403, 1134, 5043, 5047, 11612345, 11812345, 62529903 },
        { 113, 403, 1143, 5043, 50437, 11612345, 11812345, 62529903 }
};

// Arrays used for testing prefixC function
char txt3[N][LEN] = { "113", "0403", "1143", "05043", "05047", "11612345", "11812345", "62529903" };
char txt4[N][LEN] = { "113", "0403", "1134", "05043", "05047", "11612345", "11812345", "62529903" };
char txt5[N][LEN] = { "113", "0403", "1143", "05043", "050437", "11612345", "11812345", "62529903" };

// Function to check if 'i' is a prefix of 'i+1' in lexicographic order
bool prefixA(char t[N][LEN]) {
    for (int i = 0; i < N-1; i++) {
        if (!strncmp(t[i], t[i+1], strlen(t[i]))) {
            cout << "\t\t" << t[i] << " is a prefix of " << t[i+1] << '\n';
            return true;
        }
    }
    return false;
}

// Function to check if 'i' is a prefix of 'i+1' by comparing digits
bool prefixB(int n[N]) {
    int i, j, num1;

    for (i = N-1; i > 0; i--) {
        num1 = n[i]; // Current number to compare

        while (num1 > 0) {
            for (j = i - 1; j >= 0; j--) {
                if (num1 == n[j]) {
                    cout << "\t\t" << n[j] << " is a prefix of " << n[i] << '\n';
                    return true;
                }
            }
            num1 /= 10; // Remove the last digit
        }
    }
    return false;
}

// Function to check if 'i' is a prefix of 'i+1' in lexicographic order by comparing strings
bool prefixC(char t[N][LEN]) {
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j <= N-1; j++) {
            if (!strncmp(t[i], t[j], strlen(t[i]))) {
                cout << "\t\t" << t[i] << " is a prefix of " << t[j] << '\n';
                return true;
            }
        }
    }
    return false;
}

int main() {
    cout << "txte is " << ((prefixA(txte)) ? "NOT " : "") << "OK\n\n";
    cout << "txt1 is " << ((prefixA(txt1)) ? "NOT " : "") << "OK\n\n";
    cout << "txt2 is " << ((prefixA(txt2)) ? "NOT " : "") << "OK\n\n";

    cout << "num[0] is " << ((prefixB(num[0])) ? "NOT " : "") << "OK\n\n";
    cout << "num[1] is " << ((prefixB(num[1])) ? "NOT " : "") << "OK\n\n";
    cout << "num[2] is " << ((prefixB(num[2])) ? "NOT " : "") << "OK\n\n";

    cout << "txt3 is " << ((prefixC(txt3)) ? "NOT " : "") << "OK\n\n";
    cout << "txt4 is " << ((prefixC(txt4)) ? "NOT " : "") << "OK\n\n";
    cout << "txt5 is " << ((prefixC(txt5)) ? "NOT " : "") << "OK\n\n";

    return 0;
}
