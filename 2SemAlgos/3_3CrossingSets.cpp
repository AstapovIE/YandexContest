#include <iostream>
#include <vector>

using namespace std;
//Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1]. n » m. 
//Найдите их пересечение. Требуемое время работы: O(m * log k), где k - позиция элементта B[m-1] в массиве A.
//В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска элемента B[i-1]. n, k ≤ 10000.
/*
6
4
1
4
7
8
11
15
1
-11
16
77
*/

long int find_index(vector<long int> mass, long int x) {
    long int i = mass.size() / 2;
    long int left = 0;
    long int right = mass.size() - 1;
    if (mass[0] > x) { return -1;  }
    if (mass[mass.size() - 1] < x) { return -1; }
    while (mass[i] != x && !(x > mass[i] && x < mass[i+1])){
        if (mass[i] < x) {
            left = i;
            i = i + (right - left) / 2 + 1;

        }
        else {
            right = i;
            i = left + (right - left) / 2;
        }
    }
    if (mass[i] == x) {
        return i;
    }
    return -1;
}


int main()
{
    long int n;
    long int m;
    cin >> n;
    cin >> m;
    vector<long int> a;
    long int temp;
    for (long int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    vector<long int> b;
    for (long int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }
    long int res = 0;
    for (long int i = 0; i < m; i++) {
        res = find_index(a, b[i]);
        if (res>=0) {
            cout << b[i] << " ";
        }
        
    }
}

