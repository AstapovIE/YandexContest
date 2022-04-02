#include <iostream>

using namespace std;
// нули факториала



int main()
{
    int n;
    cin >> n;
    int counter = 0;
    unsigned long long int result = 1;

    for (int i = 1; i <= n; i++) {
        result = result * i;
 
        while (result % 10 == 0) {
            counter++;
            result = result / 10;
        }
        result = result % 10000000000;
    }
    cout << counter;
}

