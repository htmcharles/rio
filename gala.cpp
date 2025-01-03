#include <iostream>
#include <vector>
#include <utility>  // for std::pair
using namespace std;

// Function to calculate the number of segments
int calculate_segments(const vector<int>& pokemon_positions) {
    int segments = 1;  // Start with one segment
    int n = pokemon_positions.size();
    for (int i = 1; i < n; ++i) {
        if (pokemon_positions[i-1] > pokemon_positions[i]) {
            segments++;  // A new segment begins here
        }
    }
    return segments;
}

// Function to process the swaps and calculate the results
void pokemon_sorting(int n, int m, vector<int>& pokemon_positions, const vector<pair<int, int>>& swaps) {
    // Calculate and output the initial number of segments
    cout << calculate_segments(pokemon_positions) << endl;
    
    // Process each swap and calculate the number of segments after each swap
    for (const auto& swap : swaps) {
        int i = swap.first - 1;  // Convert to zero-based index
        int j = swap.second - 1;  // Convert to zero-based index

        // Swap the positions in the pokemon_positions array
        swap(pokemon_positions[i], pokemon_positions[j]);
        
        // Output the number of segments after the swap
        cout << calculate_segments(pokemon_positions) << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of Pokemon and number of swaps
    
    vector<int> pokemon_positions(n);
    for (int i = 0; i < n; ++i) {
        cin >> pokemon_positions[i];  // The preferred positions
    }
    
    vector<pair<int, int>> swaps(m);
    for (int i = 0; i < m; ++i) {
        cin >> swaps[i].first >> swaps[i].second;  // Each swap operation
    }
    
    // Call the function to process the swaps and calculate the results
    pokemon_sorting(n, m, pokemon_positions, swaps);

    return 0;
}

