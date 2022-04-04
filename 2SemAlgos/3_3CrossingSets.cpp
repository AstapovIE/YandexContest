#include <iostream>
#include <vector>

using namespace std;
//Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n-1] и B[0..m-1]. n » m. 
//Найдите их пересечение. Требуемое время работы: O(m * log k), где k - позиция элементта B[m-1] в массиве A.
//В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска элемента B[i-1]. n, k ≤ 10000.

int find_index(vector<int> mass, int x) {
    int i = mass.size() / 2;
    int left = 0;
    int right = mass.size() - 1;
    while (mass[i] != x && !(mass[i-1] < x && x < mass[i+1])){
        if (mass[i] < x) {
            left = i;
            i = i + (right - left) / 2 + 1;
        }
        else {
            right = i;
            i = (right - left) / 2;
        }
    }
    if (mass[i] == x) {
        return i;
    }
    return -1;
}

vector<int> kick(vector<int> mass, int index) {
    int buff = 0;
    for (int i = index; i < mass.size() - 1; i++) {
        buff = mass[i];
        mass[i] = mass[i + 1];
        mass[i + 1] = buff;
    }
    mass.pop_back();
    return mass;

}

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<int> a;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    vector<int> b;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        res = find_index(a, b[i]);
        if (res>=0) {
            cout << a[res] << " ";
        }
        
    }
}

