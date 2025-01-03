#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  // For std::abs()

// Function to calculate the minimum difference between adjacent elements in a vector
int calculateMinDifference(const std::vector<int>& vec) {
    int minDifference = std::numeric_limits<int>::max();
    for (int i = 0; i < vec.size() - 1; ++i) {  // Compare i and i+1
        int diff = std::abs(vec[i + 1] - vec[i]);  // Calculate difference between i and i+1
        if (diff < minDifference) {
            minDifference = diff;
        }
    }
    return minDifference;
}

int main() {
    int n;

    // Read the number of elements
    std::cin >> n;

    // Read the elements into a vector
    std::vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }

    // Generate all permutations of the elements
    std::vector<std::vector<int>> allPermutations;
    do {
        allPermutations.push_back(elements);
    } while (std::next_permutation(elements.begin(), elements.end()));

    // Variable to track the maximum of minimum differences
    int maxMinDifference = std::numeric_limits<int>::min();
    
    // Iterate over the permutations and calculate their minimum differences
    for (const auto& permutation : allPermutations) {
        int minDiff = calculateMinDifference(permutation);
        
        // Update the maxMinDifference
        if (minDiff > maxMinDifference) {
            maxMinDifference = minDiff;
        }
    }

    // Output only the maximum possible value of the minimum differences
    std::cout << maxMinDifference << std::endl;

    return 0;
}

