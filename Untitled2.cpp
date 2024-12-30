#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<string> words;
    set<string> compoundWords;
    string word;

    while (cin >> word) {
        words.push_back(word);
    }

    for (size_t i = 0; i < words.size(); i++) {
        for (size_t j = 0; j < words.size(); j++) {
            compoundWords.insert(words[i] + words[j]);
        }
    }

    set<string>::iterator it;
    for (it = compoundWords.begin(); it != compoundWords.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}

