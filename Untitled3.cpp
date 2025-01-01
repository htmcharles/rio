#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_set<int> used_ingredients;
    int concocted_count = 0;

    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        int ingredients[M];
        bool can_concoct = true;

        for (int j = 0; j < M; ++j) {
            cin >> ingredients[j];
            if (used_ingredients.find(ingredients[j]) != used_ingredients.end()) {
                can_concoct = false;
            }
        }

        if (can_concoct) {
            concocted_count++;
            for (int j = 0; j < M; ++j) {
                used_ingredients.insert(ingredients[j]);
            }
        }
    }

    cout << concocted_count << endl;
    return 0;
}

