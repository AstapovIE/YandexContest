#include <iostream>
#include <vector>

using namespace std;
/*Дано N кубиков. Требуется определить каким количеством способов можно выстроить из этих кубиков пирамиду. 
Каждый вышележащий слой пирамиды должен быть строго меньше нижележащего.*/

int main()
{
	int n;
	cin >> n;

	vector<vector<long long> > matrix(n + 1, vector<long long>(n + 1));

	for (int i = 0; i <= n; ++i)
		matrix[0][i] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
			matrix[i][j] = matrix[i][j - 1] + matrix[i - j][j - 1];
		for (int j = i + 1; j <= n; ++j)
			matrix[i][j] = matrix[i][i];
	}
	cout << matrix[n][n];
}