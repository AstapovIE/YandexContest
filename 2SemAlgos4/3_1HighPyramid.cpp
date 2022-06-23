#include <iostream>
#include <vector>

using namespace std;
/*Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков пирамиду.
Каждый вышележащий слой пирамиды должен быть не больше нижележащего.*/

int main() {
	long long n = 0;
	cin >> n;

	vector<vector<long long>> arr(n + 1, vector<long long>(n + 1, 0));
	for (long long i = 0; i < (n + 1); i++) {
		arr[i][0] = 0;
		arr[i][1] = 1;
	}

	for (long long i = 2; i < (n + 1); i++) {
		for (long long j = 0; j < (n + 1); j++) {
			arr[j][i] = arr[j][i - 1];
			if (j - i + 1 > 0) {
				arr[j][i] += arr[j - i][i];
			}
		}
	}

	cout << arr[n][n];
}