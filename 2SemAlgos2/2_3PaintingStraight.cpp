#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
/*На числовой прямой окрасили N отрезков.
Известны координаты левого и правого концов каждого отрезка [Li, Ri]. Найти длину окрашенной части числовой прямой.
N ≤ 10000. Li, Ri — целые числа в диапазоне [0, 10^9].*/

struct Point {
	int x;
	int y;

	Point(int a, int b) {
		x = a;
		y = b;
	}
};

int count_painted(vector<Point>& arr, int n, int k) {
	int i = 0;
	while (i + 1 < arr.size()) {
		if (arr[i].x == arr[i + 1].x) {
			arr.erase(arr.begin() + i);
			--i;
		}
		else if (arr[i].y < arr[i + 1].y) {
			arr[i + 1].x = max(arr[i + 1].x, arr[i].y);
		}
		else {
			arr.erase(arr.begin() + i + 1);
			--i;
		}
		++i;
	}

	for (int i = 0; i < arr.size(); ++i) {
		k += arr[i].y - arr[i].x;
	}
	return k;
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


	cout << count_painted(arr, n, 0);
}
