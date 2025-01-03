#include <iostream>
#include <string>

using namespace std;

int main() {
    string toilet;
    cin >> toilet;

    int n = toilet.length();
    char positions[1000];
    for (int i = 0; i < n; ++i) {
        positions[i] = toilet[i];
    }

    int case1 = 0, case2 = 0, case3 = 0;
    char initialpos = positions[0];
    char first = positions[1];

    for (int i = 2; i < n; ++i) {
        if (positions[i] != 'U') {
            case1 += 2;
        }
    }
    if (initialpos == 'D' && first == 'U') {
        case1++;
    }
    if (initialpos == 'D' && first == 'D') {
        case1++;
    }
    if (initialpos == 'U' && first == 'D') {
        case1 += 2;
    }

    for (int i = 2; i < n; ++i) {
        if (positions[i] != 'D') {
            case2 += 2;
        }
    }
    if (initialpos == 'U' && first == 'D') {
        case2++;
    }
    if (initialpos == 'U' && first == 'U') {
        case2++;
    }
    if (initialpos == 'D' && first == 'U') {
        case2 += 2;
    }

    char lastchar = first;
    for (int i = 2; i < n; ++i) {
        if (positions[i] != lastchar) {
            case3++;
        }
        lastchar = positions[i];
    }
    if (initialpos == 'D' && first == 'U') {
        case3++;
    }
    if (initialpos == 'U' && first == 'D') {
        case3++;
    }

    cout << case1 << endl;
    cout << case2 << endl;
    cout << case3 << endl;

    return 0;
}

