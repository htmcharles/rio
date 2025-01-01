#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
public:
    FenwickTree(int n) {
        tree.resize(n + 1, 0);
    }

    void increment(int i, long long delta) {
        while (i < tree.size()) {
            tree[i] += delta;
            i += i & -i;
        }
    }

    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }

private:
    vector<long long> tree;
};

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C
    cin.tie(NULL); // Untie cin from cout for faster input

    int N, Q;
    cin >> N >> Q;

    FenwickTree fenwick(N);

    while (Q--) {
        char operation;
        int index;
        long long value;

        cin >> operation >> index;

        if (operation == '+') {
            cin >> value;
            fenwick.increment(index + 1, value);
        } else if (operation == '?') {
            cout << fenwick.query(index) << '\n';
        }
    }

    return 0;
}

