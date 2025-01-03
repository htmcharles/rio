#include <iostream>
#include <bitset>  
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;
    
    int count = 0;
    
    for (int a = L+; a <= R; ++a) {
        for (int b = L+1; b < a; ++b) { 
            int sum = a + b;
            int diff = a - b;
            
            int or_result = sum | diff;

            if (or_result == sum) {
                count++;
            }
        }
    }
    
    cout << count+(R-L+2) << endl;
    
    return 0;
}

