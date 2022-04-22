#include <iostream>
#include <vector>

using namespace std;
//Дан отсортированный массив различных целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
//Для каждого элемента массива B[i] найдите минимальный индекс элемента массива A[k], ближайшего по значению к B[i].
//n ≤ 110000, m ≤ 1000. Время работы поиска для каждого элемента B[i]: O(log(k)).

int find_index(vector<int>& mass, int x) {
    int i = mass.size() / 2;
    int left = 0;
    int right = mass.size() - 1;
    if (mass[0] > x) { return 0; }
    if (mass[mass.size() - 1] < x) { return mass.size() - 1; }
    while (mass[i] != x && !(x > mass[i] && x < mass[i + 1])) {
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
    else
    {
        if (x - mass[i] <= mass[i + 1] - x) { return i; }
        else { return i + 1; }
    }
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
    int m;
    cin >> m;
    //vector<int> b;
    //for (int i = 0; i < m; i++) {
    //    cin >> temp;
    //    b.push_back(temp);
    // }

    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << find_index(a, temp) << " ";
    }

}
