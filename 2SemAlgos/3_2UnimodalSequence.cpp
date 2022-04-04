#include <iostream>
#include <vector>

using namespace std;
//Дан массив целых чисел А[0..n-1]. Известно, что на интервале [0, m] значения массива строго возрастают,
//а на интервале [m, n-1] строго убывают. Найти m за O( log m ).
//2 ≤ n ≤ 10000.
// input 10                   output
//1 2 3 4 5 6 7 6 5 4         6

int find_number(vector<int> mass) {
    int i = mass.size() / 2;
    int left = 0;
    int right = mass.size() - 1;
    while (!(mass[i - 1] < mass[i] &&  mass[i] > mass[i+1])) {
        if (mass[i] < mass[i+1]) {
            left = i;
            i = i + (right - left) / 2 + 1;
        }
        else {
            right = i;
            i = left + (right - left) / 2;
        }
        if (i == 0) {
            return mass[0];
        }
        if (i == mass.size() - 1) {
            return mass[mass.size() - 1];
        }
        
    }

    return mass[i];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    cout << find_number(a);
}

