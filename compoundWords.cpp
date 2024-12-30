#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string words[100];
    set<string> compoundWords;  // Use a set to automatically handle uniqueness
    int wordCount = 0;

    // Read words
    while (cin >> words[wordCount]) {
        wordCount++;
    }

    // Generate compound words, excluding invalid duplicates
    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < wordCount; j++) {
            if (i != j) {  // Avoid concatenating the same word with itself
                compoundWords.insert(words[i] + words[j]);
            }
        }
    }

    // Output the unique compound words in sorted order
    set<string>::iterator it = compoundWords.begin();
    while (it != compoundWords.end()) {
        cout << *it << endl;
        it++;
    }

    return 0;
}

