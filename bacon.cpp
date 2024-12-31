#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void process_orders() {
    string line;
    while (true) {
        getline(cin, line);
        int n = stoi(line);
        if (n == 0) break;

        map<string, set<string>> menu_orders;

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            istringstream iss(line);
            string name;
            iss >> name;

            string item;
            while (iss >> item) {
                menu_orders[item].insert(name);
            }
        }

        for (map<string, set<string>>::iterator it = menu_orders.begin(); it != menu_orders.end(); ++it) {
            cout << it->first;
            for (set<string>::iterator name_it = it->second.begin(); name_it != it->second.end(); ++name_it) {
                cout << " " << *name_it;
            }
            cout << endl;
        }
        cout << endl; // Blank line after each day
    }
}

int main() {
    process_orders();
    return 0;
}

