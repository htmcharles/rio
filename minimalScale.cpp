#include <iostream>
#include <algorithm>
using namespace std;

long long minimum_scalar_product(int v1[], int v2[], int n) {
    sort(v1, v1 + n);
    sort(v2, v2 + n, greater<int>());
    long long scalar_product = 0;
    for (int i = 0; i < n; ++i) {
        scalar_product += static_cast<long long>(v1[i]) * v2[i];
    }
    return scalar_product;
}

int main() {
    int t;
    cin >> t;
    for (int case_num = 1; case_num <= t; ++case_num) {
        int n;
        cin >> n;
        int v1[n], v2[n];
        for (int i = 0; i < n; ++i) cin >> v1[i];
        for (int i = 0; i < n; ++i) cin >> v2[i];
        cout << "Case #" << case_num << ": " << minimum_scalar_product(v1, v2, n) << endl;
    }
    return 0;
}

