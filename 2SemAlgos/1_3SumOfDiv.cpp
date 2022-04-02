#include <iostream>

using namespace std;
// Даны четыре неотрицательных числа a, b, c и d. Сложить две рациональные дроби a/b и c/d, а их результат представить в виде 
// несократимой дроби m/n. Вывести числа m и n. a, b, c, d ≤ 1000.

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int upper = a * d + c * b;
    int lower = b * d;

    if (upper <= lower) {
        for(int i = upper;i >= 2; i--){
            if (upper % i == 0 && lower % i == 0) {
                upper = upper / i;
                lower = lower / i;
            }
        }
    }
    else {
        for (int i = lower; i >= 2; i--) {
            if (upper % i == 0 && lower % i == 0) {
                upper = upper / i;
                lower = lower / i;
            }
        }
    }
    cout << upper << " " << lower << endl;
}

