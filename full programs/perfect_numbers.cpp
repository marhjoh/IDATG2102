#include <iostream>
using namespace std;

const int END = 33550336; // The 5th perfect number

// Function to check if 'n' is a perfect number
bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
        if (sum > n) {
            return false; // The sum has exceeded 'n', so it cannot be perfect
        }
    }
    return (sum == n);
}

int main() {
    cout << "The first five perfect numbers:\n";

    for (int number = 1; number <= END; number++) {
        if (isPerfect(number)) {
            cout << number << '\n'; // Perfect! - Print the number

            // Since we know that perfect numbers always end in 6 or 28,
            // we can optimize the last if statement considerably:
            // if (number % 10 == 6 || number % 100 == 28) {
            //    cout << number << '\n';
            //}
        }
    }

    return 0;
}
