#include <bits/stdc++.h>
using namespace std;

// Fast I/O techniques
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fast_io();
    
    int N;  // Number of recipes
    cin >> N;
    
    vector<vector<int>> recipes(N);
    set<int> used;  // Using a set to track originally used ingredients
    int result = 0;

    // Reading input and storing recipes
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        recipes[i].resize(M);
        for (int j = 0; j < M; j++) {
            cin >> recipes[i][j];
        }
    }

    // Process each recipe
    for (int i = 0; i < N; i++) {
        bool can_concoct = false;  // Assume the recipe cannot be concocted

        // Check if at least one ingredient is unused
        for (int ing : recipes[i]) {
            if (!used.count(ing)) {  // If any ingredient has not been used before
                can_concoct = true;
                break;  // No need to check further
            }
        }
        
        // If the recipe can be concocted, mark the ingredients as used
        if (can_concoct) {
            result++;  // This recipe can be concocted
            for (int ing : recipes[i]) {
                used.insert(ing);  // Insert into set
            }
        }
    }

    cout << result << "\n";  // Output the number of concoctable recipes
    return 0;
}

