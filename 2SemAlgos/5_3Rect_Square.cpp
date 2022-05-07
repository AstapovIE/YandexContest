#include <vector>
#include <iostream>

using namespace std;
/*Дана последовательность N прямоугольников различной ширины и высоты (wi, hi). Прямоугольники расположены, начиная с точки (0, 0), на оси ОХ вплотную друг за другом (вправо).
Требуется найти M - площадь максимального прямоугольника (параллельного осям координат), который можно вырезать из этой фигуры.

Время работы - O(n).
Формат ввода
В первой строке задано число N (1 ≤ N ≤ 10000).
Далее идет N строк. В каждой строке содержится два числа width и height: ширина и высота i-го прямоугольника.
(0 < width ≤ 10000, 0 ≤ height ≤ 10000)
3                        
1 1
1 3                         
3 2
M = 8
*/

int find_sq(vector<int>& v, int x)
{
    int max = 0;
    int n = v.size();
    int i = 0;
    while (i <= n) {
        int sum = 0;
        while (i != n && v[i] >= x) {
            ++sum;
            ++i;
        }
        if (sum > max) { max = sum; }
        ++i;
    }
    return max * x;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    int min = 10000;
    int max = 0;
    
    int w;
    int h;
    for (int i = 0; i < n; ++i) {
        cin >> w;
        cin >> h;
        if (h < min) { min = h; }
        if (h > max) { max = h; }
        for (int j = 0; j < w; ++j) {
            v.push_back(h);
        }
        
    }
    n = v.size();

    //for (int i = 0; i < n; ++i) {
    //    cout << v[i] << endl;
    //}


    int M = 0;
    int curr;
    while (min <= max)
    {
        curr = find_sq(v, min);
        if (curr > M) { M = curr; }
        ++min;
    }
    cout << M;
}
