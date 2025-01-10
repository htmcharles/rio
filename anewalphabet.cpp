#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

string translate(const string& input) {
    unordered_map<char, string> mapping = {
        {'a', "@"}, {'b', "8"}, {'c', "("}, {'d', "|)"}, {'e', "3"},
        {'f', "#"}, {'g', "6"}, {'h', "[-]"}, {'i', "|"}, {'j', "_|_"},
        {'k', "\\"}, {'l', "1"}, {'m', "[]V[]"}, {'n', "[]"}, {'o', "0"},
        {'p', "ID"}, {'q', "(,)"}, {'r', "|Z"}, {'s', "$"}, {'t', "'[]'"},
        {'u', "_|_"}, {'v', "\\/"}, {'w', "VV"}, {'x', "H"}, {'y', "`/"},
        {'z', "2"}
    };

    string result = "";

    for (char c : input) {
        char lower_char = tolower(c);
        if (mapping.find(lower_char) != mapping.end()) {
            result += mapping[lower_char];
        }
        else {
            result += c;
        }
    }

    return result;
}

int main() {
    string input = "What's the Frequency, Kenneth?";
    string translated = translate(input);
    cout << "Translated string: " << translated << endl;
    return 0;
}

