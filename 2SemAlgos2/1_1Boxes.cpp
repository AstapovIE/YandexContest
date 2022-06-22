#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*На склад привезли много пустых ящиков. Все ящики пронумерованы по порядку поступления от 0.
Известно, что их все можно сложить один в один (то есть так, что каждый следующий помещается в предыдущий).
Один ящик можно вложить в другой, если его можно перевернуть так,
что размеры одного ящика по всем осям станут строго меньше размеров другого ящика по соответствующим осям.
Требуется определить, в какой последовательности они будут вложены друг в друга. Вывести номера ящиков.
Максимальное кол-во 10000.*/

struct Box
{
    int x;
    int y;
    int z;
    int k;

    Box(int a, int b, int c, int k) {
        x = a;
        y = b;
        z = c;
        if (y < z) { swap(y, z); }
        if (x < y) { swap(x, y); }
        if (y < z) { swap(y, z); }
        this->k = k;
    }
    void print() {
        //cout << this->x << " " << this->y << " " << this->z << endl;
        cout << this->k << " ";
    }
};


int main()
{
    vector<Box> arr;
    int n;
    cin >> n;
    int a;
    int b;
    int c;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        cin >> b;
        cin >> c;
        arr.push_back(Box(a, b, c, i));
    }
    


    /*for (int i = 0; i < n; ++i) {
        arr[i].print();
    }*/

    sort(arr.begin(), arr.end(), [](Box a, Box b) {
        if (a.x >= b.x) return false;
        if (a.y >= b.y) return false;
        if (a.z >= b.z) return false;
        return true;
        }
    );

    for (int i = 0; i < n; ++i) {
        arr[i].print();
    }

    
    
}

