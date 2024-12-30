#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        
        string names[20];
        vector<string> orders[10];
        string menu_items[10];
        int item_count = 0;
        
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            names[i] = name;
            string item;
            while (cin >> item && item != "") {
                bool found = false;
                for (int j = 0; j < item_count; j++) {
                    if (menu_items[j] == item) {
                        orders[j].push_back(name);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    menu_items[item_count] = item;
                    orders[item_count].push_back(name);
                    item_count++;
                }
            }
        }
        
        for (int i = 0; i < item_count; i++) {
            sort(orders[i].begin(), orders[i].end());
            cout << menu_items[i] << " ";
            for (int j = 0; j < orders[i].size(); j++) {
                cout << orders[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

