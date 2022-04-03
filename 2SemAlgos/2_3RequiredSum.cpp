#include <iostream>
#include<vector>

using namespace std;
//Даны два строго возрастающих массива целых чисел A[0..n) и B[0..m) и число k.
//Найти количество таких пар индексов (i, j), что A[i] + B[j] = k. Время работы O(n + m). n, m ≤ 100000.
//Указание.Обходите массив B от конца к началу.

//Формат ввода
//В первой и второй строке вводятся количество элементов и сами элементы массива A.
//В третьей и четвертой строке вводятся количество элементов и сами элементы массива B.
//В пятой строке — число k.

//Формат вывода
//Выведите требуемое количество пар.


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
    long int m;
    cin >> m;
    vector<long int> b;
    for (long int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }
    long int k;
    long int counter = 0;
    cin >> k;
    long int j = 0;
    long int i = m - 1;
    while (j < n && i >= 0) {
        if (b[i] + a[j] == k) {
            counter++;
            j++;
        }
        else {
            if (b[i] + a[j] < k) {
                j++;
            }
            else {
                i--;
            }
        }
    }
    cout << counter;
}
