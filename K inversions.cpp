#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // Initialize the result array
    vector<int> result(n, 0);

    // Array to count the number of 'B's before each position
    vector<int> prefixB(n + 1, 0);
    
    // Array to count the number of 'A's after each position
    vector<int> suffixA(n + 1, 0);

    // Compute prefix count of 'B's
    for (int i = 0; i < n; ++i) {
        prefixB[i + 1] = prefixB[i] + (s[i] == 'B');
    }

    // Compute suffix count of 'A's
    for (int i = n - 1; i >= 0; --i) {
        suffixA[i] = suffixA[i + 1] + (s[i] == 'A');
    }

    // Calculate the result for each k
    for (int k = 1; k < n; ++k) {
        int count = 0;
        for (int i = 0; i + k < n; ++i) {
            if (s[i] == 'B' && s[i + k] == 'A') {
                count++;
            }
        }
        result[k] = count;
    }

    // Output the results
    for (int k = 1; k < n; ++k) {
        cout << result[k] << endl;
    }

    return 0;
}

