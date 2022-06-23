#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Req {
	int x;
	int y;

	Req(int a, int b) {
		x = a;
		y = b;
	}
};


int main()
{
	vector<Req> arr;

	int a;
	int b;



	while (cin >> a >> b) {
		arr.push_back(Req(a, b));
	}


	sort(arr.begin(), arr.end(), [](Req a, Req b) {
		if (a.y < b.y) return true;
		return false;
		}
	);

	int j = 0;
	int k = 0;
	for (int i = 1; i < arr.size(); ++i) {
		if (arr[i].x >= arr[j].y) {
			++k;
			j = i;
		}
	}
	cout << k + 1;


}

