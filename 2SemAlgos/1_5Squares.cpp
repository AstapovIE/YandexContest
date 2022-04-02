#include <iostream>

using namespace std;
//Вывести квадраты натуральных чисел от 1 до n, используя только O(n) операций сложения и вычитания (умножением пользоваться нельзя).
//n ≤ 1000.


int main()
{
    int n;
    cin >> n;
    int delta = 3;
    int number = 1;
    for (int i = 0; i < n; i++) {
        cout << number << " ";;
        number += delta;
        delta += 2;
    }
}

