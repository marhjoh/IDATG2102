#include <iostream>
using namespace std;

const int N = 4;           // Maximum number of steps.
const int TARGET = 91;       // Target value.
const int INITIAL = 99;    // Initial value.
const int FLERE = 53;      // Additional coins.

/**
 * Recursive function to find if it's possible to reach the target amount of coins.
 * @param numberOfCoins The current number of coins.
 * @param n The number of steps left.
 * @return True if it's possible, false otherwise.
 */
bool game(int numberOfCoins, int n) {
    bool finished = false;  // Helper variable to check if finished.

    // Found a solution!
    if (numberOfCoins == TARGET) { cout << TARGET; return true; }

    // No more steps left.
    else if (n == 0) return false;

    // Not finished, continue the game.
    else {
        finished = game(numberOfCoins + FLERE, n - 1); // Try receiving more coins.
        if (!finished && !(numberOfCoins % 2))
            finished = game(numberOfCoins / 2, n - 1); // Try delivering half of the coins.

        if (finished) { cout << numberOfCoins << " "; } // Solution found: print the number of coins involved.
        return finished;
    }
}

int main() {
    cout << "For " << INITIAL << " coins in " << N << " steps, the following solution was found: \n\n\t";
    if (!game(INITIAL, N)) // Try to find a solution.
        cout << "NO SOLUTION!";
    cout << "\n\n";
    return 0;
}
