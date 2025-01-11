#include "nile.h"
#include <tuple>
#include <vector>
#include <numeric>
#include <climits>
#include <algorithm>
#include <cassert>
using namespace std;

class DisjointSetUnion {
private:
    vector<int> parent, size, even, odd;
    long long cost = 0;

public:
    DisjointSetUnion(const vector<int>& A, const vector<int>& B) 
        : parent(A.size(), -1), size(A.size(), 1), even(A.size()), odd(A.size(), INT_MAX) {
        for (int i = 0; i < A.size(); ++i) {
            even[i] = A[i] - B[i];
            cost += even[i];
        }
    }

    int findParent(int x) {
        return parent[x] == -1 ? x : (parent[x] = findParent(parent[x]));
    }

    void merge(int v) {
        int u = findParent(v - 1);
        for (int x : {u, v}) {
            if (size[x] % 2 == 1) {
                cost -= even[x];
            }
        }

        if (size[u] % 2 == 1) {
            swap(even[v], odd[v]);
        }

        odd[u] = min(odd[u], odd[v]);
        even[u] = min(even[u], even[v]);
        parent[v] = u;
        size[u] += size[v];

        if (size[u] % 2 == 1) {
            cost += even[u];
        }
    }

    void updateCost(int v, int w) {
        int u = findParent(v);
        if ((v - u) % 2 == 1) {
            if (size[u] % 2 == 1) {
                cost -= even[u];
            }
            even[u] = min(even[u], w);
            if (size[u] % 2 == 1) {
                cost += even[u];
            }
        } else {
            odd[u] = min(odd[u], w);
        }
    }

    long long getCurrentCost() const {
        return cost;
    }
};

vector<long long> calculateCosts(vector<int> W, vector<int> A, vector<int> B, vector<int> E) {
    int n = W.size(), q = E.size();
    if (n == 1) {
        return vector<long long>(q, A[0]);
    }

    vector<tuple<int, int, int>> helper;
    for (int i = 0; i < n; ++i) {
        helper.emplace_back(W[i], A[i], B[i]);
    }
    sort(helper.begin(), helper.end());
    for (int i = 0; i < n; ++i) {
        tie(W[i], A[i], B[i]) = helper[i];
    }

    vector<int> singleDifferences(n - 1);
    iota(singleDifferences.begin(), singleDifferences.end(), 1);
    sort(singleDifferences.begin(), singleDifferences.end(), [&](int i, int j) {
        return W[i] - W[i - 1] < W[j] - W[j - 1];
    });

    vector<int> doubleDifferences(n - 2);
    iota(doubleDifferences.begin(), doubleDifferences.end(), 1);
    sort(doubleDifferences.begin(), doubleDifferences.end(), [&](int i, int j) {
        return W[i + 1] - W[i - 1] < W[j + 1] - W[j - 1];
    });

    vector<int> queryIndices(q);
    iota(queryIndices.begin(), queryIndices.end(), 0);
    sort(queryIndices.begin(), queryIndices.end(), [&](int i, int j) {
        return E[i] < E[j];
    });

    DisjointSetUnion dsu(A, B);
    vector<long long> costs(q);
    long long totalCost = accumulate(B.begin(), B.end(), 0LL);

    int p1 = 0, p2 = 0;
    for (int index : queryIndices) {
        while (p1 < n - 1 && W[singleDifferences[p1]] - W[singleDifferences[p1] - 1] <= E[index]) {
            int idx = singleDifferences[p1++];
            dsu.merge(idx);

            for (int neighbor : {idx, idx - 1}) {
                if (neighbor > 0 && neighbor < n - 1 && W[neighbor + 1] - W[neighbor - 1] <= E[index] && dsu.findParent(neighbor + 1) == dsu.findParent(neighbor - 1)) {
                    dsu.updateCost(neighbor, A[neighbor] - B[neighbor]);
                }
            }
        }

        while (p2 < n - 2 && W[doubleDifferences[p2] + 1] - W[doubleDifferences[p2] - 1] <= E[index]) {
            int idx = doubleDifferences[p2++];
            if (dsu.findParent(idx + 1) == dsu.findParent(idx - 1)) {
                dsu.updateCost(idx, A[idx] - B[idx]);
            }
        }

        costs[index] = totalCost + dsu.getCurrentCost();
    }

    return costs;
}

