#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        // Check for termination condition
        if (n == 0 && m == 0) break;

        unordered_set<int> jackCDs;
        int catalogNumber;

        // Read Jack's CDs
        for (int i = 0; i < n; ++i) {
            cin >> catalogNumber;
            jackCDs.insert(catalogNumber);
        }

        // Read Jill's CDs and count matches
        int commonCount = 0;
        for (int i = 0; i < m; ++i) {
            cin >> catalogNumber;
            if (jackCDs.find(catalogNumber) != jackCDs.end()) {
                ++commonCount;
            }
        }

        // Output the number of common CDs
        cout << commonCount << endl;
    }

    return 0;
}

