#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*В супермаркете решили оптимизировать показ рекламы.
Известно расписание прихода и ухода покупателей (два целых числа).
Каждому покупателю необходимо показать минимум 2 рекламы. Рекламу можно транслировать только в целочисленные моменты времени.
Покупатель может видеть рекламу от момента прихода до момента ухода из магазина. В каждый момент времени может показываться только одна реклама.
Считается, что реклама показывается мгновенно. Если реклама показывается в момент ухода или прихода, то считается, что посетитель успел её посмотреть.
Требуется определить минимальное число показов рекламы.*/

struct Point {
    int x;
    int y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};

int count_add(vector<Point>& arr, int n, int k) {

    int in;
    int out;

    int left = arr[0].x;
    int right = arr[0].y;

    bool flag = false;

    for (int i = 1; i < n; i++){

        in = arr[i].x;
            out = arr[i].y;

            if (in >= right) {
                if (flag) { k++; }
                else { (k += 2); }

                if (in > right) { flag = false; }
                else { flag = true; }

                left = in;
                right = out;
            }
            else {
                if (flag) {

                    if (in <= left && out >= right) { continue; }
                    else {
                        left = right;
                        right = out;
                        k++;
                    }
                }
                else { left = max(in, left); }
            }
    }
    if (flag) { k++; }
    else { k += 2; }
    return k;

}

int main()
{
    vector <Point> arr;

    int n;
    cin >> n;

    int a;
    int b;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        cin >> b;
        arr.push_back(Point(a, b));
    }

    std::sort(arr.begin(), arr.end(), [](Point a, Point b) {
        if (a.y >= b.y) return false;
        return true;
        });

    cout << count_add(arr, n, 0);
}
