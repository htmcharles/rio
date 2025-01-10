#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to calculate combinations (n choose k)
long long comb(long long n, long long k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    long long result = 1;
    for (long long i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> keys(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> keys[i];
    }

    // Sort the keys in descending order to access the largest elements easily
    sort(keys.begin(), keys.end(), greater<int>());

    // Calculate the sum of the largest k elements
    long long sum = 0;
    for (int i = 0; i < k; ++i) {
        // keys[i] will be the largest in the combinations that include it
        sum += keys[i] * comb(n - i - 1, k - 1);
    }

    cout << sum << "\n";

    return 0;
}

