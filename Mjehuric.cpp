#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For transforming string to lowercase

using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<int> registerBits(32, -1); // -1 means unknown, 0 means 0, 1 means 1
        
        // Read the instructions and process them
        for (int i = 0; i < n; ++i) {
            string instruction;
            cin >> instruction;
            
            // Convert instruction to lowercase for case-insensitive comparison
            transform(instruction.begin(), instruction.end(), instruction.begin(), ::tolower);
            
            int bit1, bit2;
            
            if (instruction == "set") {
                cin >> bit1;
                registerBits[bit1] = 1;  // set bit
            } 
            else if (instruction == "clear") {
                cin >> bit1;
                registerBits[bit1] = 0;  // clear bit
            }
            else if (instruction == "or") {
                cin >> bit1 >> bit2;
                if (registerBits[bit1] == 1 || registerBits[bit2] == 1) {
                    registerBits[bit1] = 1;  // OR operation
                } else if (registerBits[bit1] == 0 && registerBits[bit2] == 0) {
                    registerBits[bit1] = 0;
                } else {
                    registerBits[bit1] = -1; // unknown result if either is unknown
                }
            }
            else if (instruction == "and") {
                cin >> bit1 >> bit2;
                if (registerBits[bit1] == 0 || registerBits[bit2] == 0) {
                    registerBits[bit1] = 0;  // AND operation
                } else if (registerBits[bit1] == 1 && registerBits[bit2] == 1) {
                    registerBits[bit1] = 1;
                } else {
                    registerBits[bit1] = -1; // unknown result if either is unknown
                }
            }
        }

        // Output the final state of the register
        for (int i = 31; i >= 0; --i) {
            if (registerBits[i] == -1) {
                cout << "?";  // Unknown bit
            } else {
                cout << registerBits[i];  // Known 0 or 1 bit
            }
        }
        cout << endl;
    }

    return 0;
}

