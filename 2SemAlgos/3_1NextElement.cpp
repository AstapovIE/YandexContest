#include <iostream>
#include <vector>

using namespace std;
//Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1].
//Для каждого элемента массива B[i] найдите минимальный индекс k минимального элемента массива A,
//равного или превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n.
//Время работы поиска k для каждого элемента B[i]: O(log(k)). n, m ≤ 10000.
//В первой строчке записаны числа n и m. Во второй и третьей массивы A и B соответственно.
// input                output
//4 3¶                    1 3 0
//2 4 5 7¶
//4 6 1¶

size_t find_index(vector<long int>& mass, long x) {
    size_t index = mass.size()/2;
    size_t left = 0;
    size_t right = mass.size()-1;
    if (mass[mass.size() - 1] < x) { return mass.size(); }
    while (mass[index] != x && !(mass[index] > x && mass[index - 1] < x)) {
        if (mass[index] < x) {
            left = index;
            index = index + (right - left) / 2 + 1;
        }
        else {
            right = index;
            index = left + (right - left) / 2;
        }
    }

    return index;
}

int main()
{
    size_t n;
    size_t m;
    cin >> n;
    cin >> m;
    vector<long int> a;
    long int temp;
    for (int i = 0; i < n; i++){
        cin >> temp;
        a.push_back(temp);
    }
    
    for (size_t i = 0; i < m; i++) {
        cin >> temp;
        if (temp <= a[0]) {
            cout << 0 << " ";
        }
        else { 
            cout << find_index(a, temp) << " ";
        }
        
    }

}

