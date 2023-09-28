#include <iostream>
#include <cstring>
using namespace std;

const int N = 80; // Maximum length of the words.

// Function to check if 'word2' is an anagram of 'word1' based on the provided definition.
bool isAnagram(char* word1, char* word2) {
    char temp[N]; // Temporary string for word2
    char* tempPtr; // Pointer to iterate through the temporary string
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    if (len2 < 1) // Anagram is impossible if 'word2' is shorter.
        return false;

    strcpy(temp, word2); // Copy 'word2' to a temporary string.

    for (int i = 0; i < len1; i++) {
        // Iterate through each character of 'word1'.
        // Check if the current character in 'word1' exists in 'temp'.
        if ((tempPtr = strchr(temp, word1[i])) == NULL)
            return false; // If not found, it's not an anagram.

        // Remove the matched character from 'temp'.
        while (*tempPtr != '\0') {
            *tempPtr = *(tempPtr + 1);
            tempPtr++;
        }
    }

    return true; // If all characters in 'word1' were found and removed from 'temp', it's an anagram.
}

int main() {
    char word1[N], word2[N], response;

    do {
        cout << "Enter word #1: ";
        cin >> word1;
        cout << "\nEnter word #2: ";
        cin >> word2;

        cout << "\n" << (isAnagram(word1, word2) ? "NOT " : "") << "ANAGRAM!";
        cout << "\n\nDo you want to check more words (Y/N)? ";
        cin >> response;
        cout << "\n\n";

    } while (response == 'Y' || response == 'y');

    return 0;
}
