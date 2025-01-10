#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// Helper function to parse a class string into numeric rank
vector<int> parseClass(const string& classStr) {
    vector<int> rank;
    stringstream ss(classStr);
    string part;

    // Split the class string by '-'
    while (getline(ss, part, '-')) {
        if (part == "upper")
            rank.push_back(1); // Upper has the highest rank
        else if (part == "middle")
            rank.push_back(2); // Middle is medium rank
        else if (part == "lower")
            rank.push_back(3); // Lower is the lowest rank
    }

    return rank;
}

// Helper function to normalize class ranks to a fixed length
void normalizeClass(vector<int>& rank, size_t maxLength) {
    while (rank.size() < maxLength) {
        rank.push_back(2); // Default to "middle"
    }
}

// Comparator to sort people by class rank
bool compare(const pair<string, vector<int>>& a, const pair<string, vector<int>>& b) {
    const size_t maxLength = max(a.second.size(), b.second.size());
    vector<int> rankA = a.second, rankB = b.second;

    // Normalize both rank vectors to the same length
    normalizeClass(rankA, maxLength);
    normalizeClass(rankB, maxLength);

    // Compare lexicographically
    if (rankA != rankB)
        return rankA < rankB;
    return a.first < b.first; // Resolve ties with lexicographical order
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int numPeople;
        cin >> numPeople;

        map<string, vector<int>> people;

        // Read people's data
        for (int i = 0; i < numPeople; ++i) {
            string line, name, classStr;
            cin.ignore(); // Ignore leftover newline
            getline(cin, line);

            // Parse name and class
            size_t colonPos = line.find(':');
            name = line.substr(0, colonPos);
            classStr = line.substr(colonPos + 2, line.find(" class") - (colonPos + 2));

            // Parse and store class ranks
            people[name] = parseClass(classStr);
        }

        // Sort people by rank
        vector<pair<string, vector<int>>> sortedPeople(people.begin(), people.end());
        sort(sortedPeople.begin(), sortedPeople.end(), compare);

        // Output sorted names
        for (const auto& person : sortedPeople)
            cout << person.first << endl;

        // Separator
        cout << "==============================\n";
    }

    return 0;
}

