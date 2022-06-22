#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
/*На числовой прямой окрасили N отрезков.
Известны координаты левого и правого концов каждого отрезка [Li, Ri]. Найти длину окрашенной части числовой прямой.
N ≤ 10000. Li, Ri — целые числа в диапазоне [0, 109].*/


int main()
{
	vector <pair <int, bool>> arr;
	int n;
	cin >> n;

	int a, b;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		cin >> b;
		arr.push_back(make_pair(a, true));
		arr.push_back(make_pair(b, false));
	}

	sort(arr.begin(), arr.end(), [](pair<int, bool> left, pair<int, bool> right)
		{
			return left.first < right.first;
		});


	int length = 0;
	int depth = 0;
	
	int last = arr[0].first;
	for (pair <int, bool> point : arr)
	{
		if (point.second)
		{
			if (depth == 1)
				length += point.first - last;
			depth += 1;
		}
		else
		{
			if (depth == 1)
				length += point.first - last;
			depth -= 1;
		}
		last = point.first;
	}
	cout << length;
}
