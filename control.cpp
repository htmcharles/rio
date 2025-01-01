#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N; // Read the number of recipes

    vector<vector<int>> recipes(N);
    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M; // Read the number of ingredients for each recipe
        recipes[i].resize(M);
        for (int j = 0; j < M; ++j) {
            cin >> recipes[i][j]; // Read each ingredient
        }
    }

    set<int> usedIngredients; // To track used ingredients
    int concoctedCount = 0; // To count how many recipes can be concocted

    for (const auto& recipe : recipes) {
        bool canConcoct = true;
        for (int ingredient : recipe) {
            if (usedIngredients.count(ingredient) > 0) {
                canConcoct = false; // If any ingredient is already used
                break;
            }
        }
        if (canConcoct) {
            // If we can concoct this recipe, mark all its ingredients as used
            for (int ingredient : recipe) {
                usedIngredients.insert(ingredient);
            }
            concoctedCount++; // Increment the count of concocted recipes
        }
    }

    cout << concoctedCount << endl; // Output the result
    return 0;
}

