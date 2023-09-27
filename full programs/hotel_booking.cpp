#include <iostream>
using namespace std;

// Constants
const int PARTICIPANTS = 50;    // Number of participants
const int BUDGET = 50000;       // Budget limit
const int HOTELS = 4;           // Number of hotels
const int WEEKS = 6;            // Number of weeks

// Arrays to store hotel prices and availability
int price[HOTELS + 1];
int available[HOTELS + 1][WEEKS + 1];

// Initialize hotel prices and availability
void initialize() {
    // Set hotel prices
    price[1] = 900;
    price[2] = 900;
    price[3] = 900;
    price[4] = 900;

    // Set hotel availability for each week
    available[1][1] = 60; available[1][2] = 48; available[1][3] = 52;
    available[1][4] = 18; available[1][5] = 72; available[1][6] = 62;
    available[2][1] = 60; available[2][2] = 48; available[2][3] = 52;
    available[2][4] = 18; available[2][5] = 72; available[2][6] = 62;
    available[3][1] = 60; available[3][2] = 48; available[3][3] = 52;
    available[3][4] = 18; available[3][5] = 72; available[3][6] = 62;
    available[4][1] = 60; available[4][2] = 48; available[4][3] = 52;
    available[4][4] = 18; available[4][5] = 72; available[4][6] = 62;
}

int main() {
    int i, j,
            min = BUDGET + 1,
            hotel, week;

    // Initialize hotel data
    initialize();

    // Find the cheapest hotel that can accommodate all participants
    for (i = 1; i <= HOTELS; i++) {
        if (PARTICIPANTS * price[i] < min) {
            for (j = 1; j <= WEEKS; j++) {
                if (available[i][j] >= PARTICIPANTS) {
                    min = PARTICIPANTS * price[i];
                    hotel = i; week = j;
                    break;
                }
            }
        }
    }

    // Check if a suitable hotel was found within the budget
    if (min <= BUDGET) {
        cout << "\nHotel: " << hotel << "\tin week number " << week << "\tTotal cost: " << min << "\n\n";
    } else {
        cout << "\nNowhere to stay (for now).\n\n";
    }

    return 0;
}
