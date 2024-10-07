#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

const int GRID_SIZE = 25;
const int WORD_BANK_SIZE = 30;
const int MAX_ERRORS = 5;
const int MAX_WORD_LENGTH = 10;

void displayGameBoard(char letters[], int errorCount) {
    cout << "Welcome to the Anagram Game!" << endl;
    cout << "The goal is to form as many words as possible using the available letters." << endl;
    cout << "Proper names, slang, and conjugated verbs are not allowed." << endl;
    cout << "Type * at any time to exit the game." << endl;
    cout << "You are allowed " << MAX_ERRORS << " mistakes. Good luck!" << endl << endl;

    // Display the 5x5 letter grid
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << letters[i] << " ";
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    cout << endl;

    cout << "Number of mistakes: " << errorCount << endl;
}

bool isValidWord(const char word[]) {
    // Check if the word contains only alphabetic characters
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char letters[GRID_SIZE] = { 'O', 'E', 'T', 'A', 'O', 'S', 'P', 'C', 'R', 'M', 'A', 'Q', 'I', 'D', 'I', 'C', 'I', 'O', 'A', 'N', 'R', 'A', 'A', 'O', 'E' };

    const char* wordBank[WORD_BANK_SIZE] = {
        "river", "sea", "sun", "moon", "love", "earth", "house", "bush", "air", "city", "point", "boat",
        "car", "fish", "color", "sky", "paw", "wave", "sand", "breeze", "mountain", "forest",
        "wind", "flowers", "rain", "smile"
    };

    char inputWord[MAX_WORD_LENGTH];
    int errorCount = 0;

    srand(time(NULL));

    while (errorCount < MAX_ERRORS) {
        displayGameBoard(letters, errorCount);

        cout << "Enter a word (or '*' to exit): ";
        cin >> inputWord;

        if (inputWord[0] == '*') {
            cout << "You exited the game." << endl;
            break;
        }

        if (!isValidWord(inputWord)) {
            cout << "Invalid word. Please enter alphabetic characters only." << endl;
            errorCount++;
            continue;
        }

        bool wordFound = false;
        for (int i = 0; i < WORD_BANK_SIZE; i++) {
            if (strcmp(wordBank[i], inputWord) == 0) {
                wordFound = true;
                cout << "Congratulations! You found a word." << endl;
                break;
            }
        }

        if (!wordFound) {
            cout << "The word does not exist in the word bank. Try another." << endl;
            errorCount++;
        }
    }

    if (errorCount == MAX_ERRORS) {
        cout << "You made " << MAX_ERRORS << " mistakes. Game over." << endl;
    }

    return 0;
}
