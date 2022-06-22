#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*Задано Nточек на плоскости. Указать (N−1) - звенную несамопересекающуюся незамкнутую ломаную, проходящую через все эти точки.
Указание: стройте ломаную в порядке возрастания x-координаты. Если имеются две точки с одинаковой x-координатой,
то расположите раньше ту точку, у которой y-координата меньше.*/

struct Point {
	int x;
	int y;

	Point(int a, int b) {
		x = a;
		y = b;
	}
};

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

	sort(arr.begin(), arr.end(), [](Point a, Point b){
			if (a.x > b.x) return false;
			if (a.x == b.x && a.y > b.y) return false;
			return true;
		}
	);

	for (int i = 0; i < n; ++i) {
		cout << arr[i].x << " " << arr[i].y << endl;

	}

}

