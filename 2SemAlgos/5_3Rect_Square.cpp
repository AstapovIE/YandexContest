#include <vector>
#include <map>
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


int main()
{
    map<int, int> m;
    map<int, int> res;
    int n;
    cin >> n;

    
    int w;
    int h;

    for (int i = 0; i < n; ++i) {
        cin >> w;
        cin >> h;
        bool flag = true;
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->first <= h) {
                m[it->first] += w * it->first;
                if (it->first == h) { m[it->first] -= w * it->first; }
            }
            else {
                if (m[h] == 0) {
                    m[h] += h * (it->second / it->first);
                    flag = false;
                }
                if (it->second > res[it->first]){
                    res[it->first] = it->second;
                }
                m[it->first] = 0;
            }
        }
        m[h] += h * w;
        
        //cout << "--m:--"<< endl;
        //for (auto it = m.begin(); it != m.end(); ++it) {
        //    cout << it->first << " : " << it->second << endl;
        //}
        //cout << "--res:--" << endl;
        //for (auto it = res.begin(); it != res.end(); ++it) {
        //    cout << it->first << " : " << it->second << endl;
        //}
    }
    
    for (auto it = m.begin(); it != m.end(); ++it){
        if (m[it->first] > res[it->first]) {
            res[it->first] = it->second;
        }
    }
    int M = 0;
    for (auto it = res.begin(); it != res.end(); ++it) {
        if (it->second > M) {
            M = it->second;
        }
    }
    cout << M << endl;
    //for (auto it = res.begin(); it != res.end(); ++it) {
    //    cout << it->first << " : " << it->second << endl;
    //}

}
