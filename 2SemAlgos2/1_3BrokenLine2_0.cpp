#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
/*Задано N точек на плоскости. Указать (N-1)-звенную несамопересекающуюся замкнутую ломаную, проходящую через все эти точки.
Предполагается, что никакие три точки не лежат на одной прямой.
Стройте ломаную от точки, имеющей наименьшую координату x. Если таких точек несколько, то используйте точку с наименьшей координатой y.
Точки на ломаной расположите в порядке убывания углов лучей от начальной точки до всех остальных точек.
Для сортировки точек реализуйте алгоритм сортировки вставками.*/

struct Point {
	int x;
	int y;

	Point(int a, int b) {
		x = a;
		y = b;
	}

	double calculate_tan(Point other) {
		if (other.x - this->x == 0) return 100000;
		return double( double(other.y - this->y) / double(other.x - this->x));
	}

	bool greater(Point a, Point b) {
		if (this->calculate_tan(a) < this->calculate_tan(b)) return false;
		return true;
	}
};

void insertSort(vector<Point>& arr, int n) {

	for (int i = 2; i < n; ++i) {
		Point tmp = arr[i];
		int j = i-1;
		for (; j >= 1 && arr[0].greater(tmp, arr[j]); --j) {
			swap(arr[j + 1], arr[j]);
		}
	}

}

int main()
{

	vector<Point> arr;
	int n;
	cin >> n;
	int a;
	int b;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		cin >> b;
		arr.push_back(Point(a, b));
	}


	sort(arr.begin(), arr.end(), [](Point a, Point b) {
		if (a.x > b.x) return false;
		if (a.x == b.x && a.y > b.y) return false;
		return true;
		}
	);

	insertSort(arr, n);

	for (int i = 0; i < n; ++i) {
		cout << arr[i].x << " " << arr[i].y << endl;

	}

}
