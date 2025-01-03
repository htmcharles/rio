#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n; // Read number of towns
    
    // Declare a 2D vector to store the min_path matrix
    vector<vector<int>> min_path(n, vector<int>(n));
    
    // Input the min_path matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> min_path[i][j];
        }
    }

    // We'll store the edges here
    vector<pair<int, int>> edges;

    // Find the edges by looking at the min_path matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) { // Only look at the upper triangle to avoid duplication
            if (min_path[i][j] == i + 1) {
                edges.push_back({i + 1, j + 1}); // Edge between i+1 and j+1
            } else if (min_path[i][j] == j + 1) {
                edges.push_back({j + 1, i + 1}); // Edge between j+1 and i+1
            }
        }
    }

    // Output the edges
    for (const auto& edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}

