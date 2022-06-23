#include <vector>
#include <iostream>
#include <string>

using namespace std;
/*В базе данных хранится N записей, вида (Name, a1, a2, … , ak) — во всех записях одинаковое число параметров.
На вход задачи подаётся приоритет полей — перестановка на числах 1,...,k — записи
нужно вывести в соответствии с этим приоритетом. В случае, если приоритет полей таков: 3 4 2 1,
то это следует воспринимать так: надо читать как: приоритет значений из 3 колонки самый высокий,
приоритет значений из колонки 4 ниже, приоритет значений из колонки 2 ещё ниже,
а приоритет значений из колонки 1 самый низкий.*/

struct DataBase {
    string name;
    vector<int> vec;
	int k;

	DataBase(string s, vector<int> v, int k) {
		name = s;
		vec = v;
		this->k = k;
	}

	void print() {
		cout << this->name << " ";
		for (int i = 0; i < k; ++i) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}

	bool greater(DataBase other, int k) {
		if (this->vec[k] > other.vec[k]) return true;
		return false;
	}
};
string MySort(vector<DataBase>& a, int len, int k) {

	for (int i = 0; i < len - 1; ++i) {
		for (int j = 0; j < len - i - 1; ++j) {
			if (a[j].greater(a[j + 1], k)) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	
	return a[len-1].name;
}

int main()
{
	vector<DataBase> arr;
	

	int n;
	cin >> n;
	int k;
	cin >> k;
	int a;

	string s;
	vector<int> prior(k);
	vector<int> buff(k);

	for (int i = 0; i < k; ++i) {
		cin >> prior[i];
		prior[i]--;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = -1; j < k; ++j) {
			if (j == -1) {
				cin >> s;
			}
			else {
				cin >> buff[j];
			}
		}
		arr.push_back(DataBase(s, buff, k));
	}

	/*for (int i = 0; i < k; ++i) {
		cout << prior[i] << " ";
	}

	cout << "---" <<  endl;;
	
	for (int i = 0; i < n; ++i) {
		arr[i].print();
	}*/

	for (int i = 0; i < k; ++i) {
		if (arr.size() == 0) { break; }
		cout << MySort(arr, arr.size(), prior[i]) << endl;;

		arr.pop_back();

	}
	for (int i = arr.size() - 1; i >= 0 ; --i) {
		cout << arr[i].name << endl;
	}
}
