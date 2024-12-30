#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void generateTree(int h, int root, int** tree, int level, int& index) {
    if (level == h) return;
    tree[level][index++] = root;
    int left = root - pow(2, h - level - 1);
    int right = left - pow(2, h - level - 1);
    generateTree(h, left, tree, level + 1, index);
    generateTree(h, right, tree, level + 1, index);
}

void printTree(int** tree, int h, int level, int index) {
    if (level == h) return;
    if (index >= pow(2, level)) {
        cout << endl;
        printTree(tree, h, level + 1, 0);
    } else {
        cout << tree[level][index] << " ";
        printTree(tree, h, level, index + 1);
    }
}

int calculateLabel(int h, const string& path, int index, int position) {
    if (index == path.size()) return position;
    int step = pow(2, h - (index + 1));
    return calculateLabel(h, path, index + 1, path[index] == 'L' ? position - step : position - step * 2);
}

int main() {
    int h;
    string path;
    cin >> h >> path;

    int root = pow(2, h) - 1;
    int** tree = new int*[h];
    for (int i = 0; i < h; ++i) tree[i] = new int[(int)pow(2, i)];

    int index = 0;
    generateTree(h, root, tree, 0, index);
    printTree(tree, h, 0, 0);

    for (int i = 0; i < h; ++i) delete[] tree[i];
    delete[] tree;

    cout << calculateLabel(h, path, 0, root) << endl;

    return 0;
}

