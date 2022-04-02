#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_simple(int x) {
    int d = 2;
    while (d * d <= x) {
        if (x % d == 0) {
            return false;
        }
        d++;
    }
    return true;
}


int main()
{
    vector<int> divs;

    int number;
    cin >> number;

    int divider = 2;

    while (number>1) {
        if ((number % divider == 0) && (is_simple(divider))) {
            divs.push_back(divider);
            number = number / divider;
        }
        else { divider++; }
    }
    for (int i = 0; i < divs.size(); i++) {
        cout << divs[i] << " ";
    }
}
