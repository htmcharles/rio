#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;

typedef long long ll;

void calculateHailstoneSum(ll number, ll currentSum)
{
    if (number == 1)
    {
        cout << 1 + currentSum << "\n";
    }
    else if (number % 2 == 0)
    {
        calculateHailstoneSum(number / 2, currentSum + number);
    }
    else
    {
        calculateHailstoneSum(number * 3 + 1, currentSum + number);
    }
}

int main()
{
    ll initialValue;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> initialValue;
    cout << fixed;
    calculateHailstoneSum(initialValue, 0);
    return 0;
}


