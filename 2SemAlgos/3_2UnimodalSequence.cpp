#include <iostream>
#include <vector>

using namespace std;
//Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива строго возрастают,
//а на интервале [m, n-1] строго убывают. Найти m за O( log m ).
//2 ≤ n ≤ 10000.
// input 10                   output
//1 2 3 4 5 6 7 6 5 4         6
//(ultra podgon) :D

long int find_number(vector<long int>& mass) {
    if (mass.size() == 2) {
        if (mass[0] > mass[1]) { return 0; }
        else { return 1; }
    }
    if (mass[mass.size() - 1] > mass[mass.size() - 2]) {return mass.size() - 1; }
    long int i = mass.size() / 2;
    long int left = 0;
    long int right = mass.size() - 1;
    while (!(mass[i - 1] < mass[i] &&  mass[i] > mass[i+1])) {
        if (mass[i] < mass[i+1]) {
            left = i;
            i = i + (right - left) / 2 + 1;
            i = i - 1;
        }
        else {
            right = i;
            i = left + (right - left) / 2;
        }
        if (i == 0) {
            return 0;
        }
        if (i == mass.size() - 1) {
            return mass.size() - 1;
        }
        
    }

    return i;
}

int main()
{
    long int n;
    cin >> n;
    vector<long int> a;
    long int temp;
    for (long int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    cout << find_number(a);
}

