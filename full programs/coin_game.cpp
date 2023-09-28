#include <iostream>
using namespace std;

const int N = 4;           // Maximum number of steps.
const int MAAL = 91;       // Target value.
const int INITIAL = 99;    // Initial value.
const int FLERE = 53;      // Additional coins.

/**
 * Recursive function to find if it's possible to reach the target amount of coins.
 * @param antKroner The current number of coins.
 * @param n The number of steps left.
 * @return True if it's possible, false otherwise.
 */
bool game(int antKroner, int n) {
    bool finished = false;  // Helper variable to check if finished.

    // Found a solution!
    if (antKroner == MAAL) { cout << MAAL; return true; }

    // No more steps left.
    else if (n == 0) return false;

    // Not finished, continue the game.
    else {
        finished = game(antKroner + FLERE, n - 1); // Try receiving more coins.
        if (!finished && !(antKroner % 2))
            finished = game(antKroner / 2, n - 1); // Try delivering half of the coins.

        if (finished) { cout << antKroner << " "; } // Solution found: print the number of coins involved.
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
