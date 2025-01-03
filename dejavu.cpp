#include <iostream>
using namespace std;

int main() {
    int n, tot = 0;
    cin >> n;

    int x[100000] = {0};
    int y[100000] = {0};
    int p[2][n];

    for (int i = 0; i < n; i++) {
        cin >> p[0][i] >> p[1][i];
        x[p[0][i]]++;
        y[p[1][i]]++;
    }

    for (int i = 0; i < n; i++) {
        tot += (x[p[0][i]] - 1) * (y[p[1][i]] - 1);
    }

    cout << tot << endl;
    return 0;
}

