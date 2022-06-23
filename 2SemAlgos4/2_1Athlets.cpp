﻿#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
/*В город N приехал цирк с командой атлетов. Они хотят удивить горожан города N — выстроить из своих тел башню максимальной высоты.
Башня — это цепочка атлетов, первый стоит на земле, второй стоит у него на плечах, третий стоит на плечах у второго и т.д.
Каждый атлет характеризуется силой si (kg) и массой mi (kg). Сила — это максимальная масса, которую атлет способен держать у себя на плечах. 
К сожалению ни один из атлетов не умеет программировать, так как всю жизнь они занимались физической подготовкой,
и у них не было времени на изучение языков программирования. Помогите им, напишите программу, которая определит максимальную высоту башни, 
которую они могут составить. Известно, что если атлет тяжелее, то он и сильнее: если mi>mj, то si > sj. 
Атлеты равной массы могут иметь различную силу.*/

struct Athlet {
	int m;
	int s;

	Athlet(int a, int b) {
		m = a;
		s = b;
	}
};

int main()
{
	vector<Athlet> arr;

	int a;
	int b;


	/*while(cin >> a >> b){
		arr.push_back(Athlet(a, b));	
	}*/

	for (int i = 0; i < 4; ++i) {
		cin >> a >> b;
		arr.push_back(Athlet(a, b));
	}


	sort(arr.begin(), arr.end(), [](Athlet a, Athlet b) {
		if (a.m < b.m) return true;
		return false;
		}
	);

	int k = 0;
	int mass = arr[0].m;
	for (int i = 1; i < arr.size() - 1; ++i) {
		if (mass <= arr[i].s) {
			mass += arr[i].m;
			++k;
		}
	}
	cout << k + 1;
}