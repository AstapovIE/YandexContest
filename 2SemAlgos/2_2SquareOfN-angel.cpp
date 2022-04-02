#include <iostream>
#include <vector>

using namespace std;
//Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин. Вначале вводится количество вершин,
//затем последовательно целочисленные координаты всех вершин в порядке обхода по часовой стрелке.
//n < 1000, координаты < 10000.
//Указание.Для вычисления площади n - угольника можно посчитать сумму ориентированных площадей трапеций под каждой стороной многоугольника.

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    float find_square(Point other) {
        return (this->y + other.y) * (other.x - this->x) / 2.0;
    }
};



int main()
{
    vector<Point> mass;
    int x;
    int y;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cin >> y;
        mass.push_back(Point(x, y));
    }
    float S = 0.0;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            S += mass[i].find_square(mass[i + 1]);
        }
        else {
            S += mass[i].find_square(mass[0]);
        }
    }
    cout << S;
}

