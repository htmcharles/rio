#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T, a, b, c, to;
    cin >> N >> T >> a >> b >> c >> to;

    vector<int> times(N);
    times[0] = to;

    // Calculate all problem solving times
    for (int i = 1; i < N; i++) {
        times[i] = ((a * times[i - 1] + b) % c) + 1;
    }

    // Sort the times to solve problems in ascending order
    sort(times.begin(), times.end());

    int totalTime = 0, penalty = 0, count = 0;
    const int MOD = 1000000007;

    // Iterate through the sorted times and calculate the total time and penalty
    for (int i = 0; i < N; i++) {
        if (totalTime + times[i] > T) {
            break; // Stop if adding the current problem exceeds the contest time
        }
        totalTime += times[i];
        penalty = (penalty + totalTime) % MOD;
        count++;
    }

    cout << count << " " << penalty << endl;
    return 0;
}

