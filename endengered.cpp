#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    // Read in the initial Pokemon species in each zone
    vector<int> species(N);
    for (int i = 0; i < N; ++i) {
        cin >> species[i];
    }

    // Process M operations
    for (int i = 0; i < M; ++i) {
        int Qi;
        cin >> Qi;
        
        if (Qi == 1) {
            // Change operation: Update species in zone Ai
            int Ai, Bi;
            cin >> Ai >> Bi;
            --Ai;  // Convert to 0-based index
            species[Ai] = Bi;
        } else if (Qi == 2) {
            // Route operation: Count distinct species from zone Ai to zone Bi
            int Ai, Bi;
            cin >> Ai >> Bi;
            --Ai; --Bi;  // Convert to 0-based index

            // Use an unordered map to count occurrences of species
            unordered_map<int, int> count_map;
            unordered_map<int, bool> excluded_species;
            int distinct_count = 0;

            for (int j = Ai; j <= Bi; ++j) {
                count_map[species[j]]++;

                // If a species has not exceeded K occurrences and is not excluded
                if (count_map[species[j]] == 1) {
                    // First time we see this species in this route
                    distinct_count++;
                }

                // If count exceeds K, we mark this species as excluded
                if (count_map[species[j]] > K && excluded_species[species[j]] == false) {
                    excluded_species[species[j]] = true;
                    distinct_count--;
                }
            }

            // Output the result for this route query
            cout << distinct_count << endl;
        }
    }

    return 0;
}

