#include <iostream>
#include <vector>

using namespace std;
//В круг выстроено N человек, пронумерованных числами от 1 до N. Будем исключать каждого k-ого до тех пор,
//пока не уцелеет только один человек.
//Например, если N = 10, k = 3, то сначала умрет 3 - й, потом 6 - й, затем 9 - й, затем 2 - й, затем 7 - й,
//потом 1 - й, потом 8 - й, за ним - 5 - й, и потом 10 - й.Таким образом, уцелеет 4 - й.
//Необходимо определить номер уцелевшего. N, k ≤ 10000.

vector<int> kick(vector<int> mass, int index) {
	int buff = 0;
	for (int i = index; i < mass.size()-1; i++) {
		buff = mass[i];
		mass[i] = mass[i + 1];
		mass[i + 1] = buff;
	}
	mass.pop_back();
	return mass;

}
	

int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> a;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	int counter = 0;
	while (a.size()!=1) {
		
		for (int i = 0; i < a.size(); i++) {
			counter++;
			if (counter % k == 0) {
				a = kick(a, i);
				i--;
			}
			if (a.size()==1) { break; }
		}

	}
	cout << a[0];
}
