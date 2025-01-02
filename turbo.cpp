#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

template<class T>
using indexed_set = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    indexed_set<pair<int, int>> indexedData;
    set<pair<int, int>> orderedData;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int value;
        cin >> value;
        indexedData.insert({i, value});
        orderedData.insert({value, i});
    }

    int turn = 0;
    while (!orderedData.empty()) {
        pair<int, int> current;
        if (turn % 2 == 0) {
            current = *orderedData.begin();
            cout << indexedData.order_of_key({current.second, current.first}) << endl;
        } else {
            current = *prev(orderedData.end());
            cout << orderedData.size() - 1 - indexedData.order_of_key({current.second, current.first}) << endl;
        }

        orderedData.erase(current);
        indexedData.erase({current.second, current.first});
        turn++;
    }

    return 0;
}

