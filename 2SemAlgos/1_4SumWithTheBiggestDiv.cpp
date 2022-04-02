#include <iostream>

using namespace std;
//Дано натуральное число N. Представить N в виде A + B, так, что НОД(A, B) максимален, 1 ≤ A ≤ B.
//Вывести A и B. Если возможно несколько ответов - вывести ответ с минимальным A. 1 < n ≤ 10 000 000.
// input 35 output 7 28

int min_div(int number) { 
    int d = 2;
    while (d*d < number){
        if (number % d == 0) { return d; }
        d++;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    if (min_div(n) == 1) {cout << 1 << " " << n - 1;}
    else {
        int max_div = n / min_div(n); //  [min_div = 1 + (min_div-1)] * max_div  {5*7 = 1*7 + (5-1)*7}:
        cout << 1 * max_div << " " << (min_div(n) - 1) * max_div << endl;
    }
}

