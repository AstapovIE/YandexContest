#include <iostream>
#include <vector>

using namespace std;

//Наибольшая сумма 2 элементов из 2ух списков(i>=j)

int main()
{
    int n;
    
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
        c.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    //с конца делаем текущий макс
    int max = c.back();
    for (int i = c.size() - 1; i >= 0; i--) {

        if (c[i] >= max) { max = c[i]; }
        else { c[i] = max; }
    }

    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    //ищем максимальную сумму
    max = std::numeric_limits<int>::min();
    int index = 0;

    for (int i = 0; i < n; i++) {
        c[i] = a[i]+ c[i];
        if (c[i] > max) { max = c[i]; index = i; }
    }

  

    
    for (int i = index; i < n; i++) {
        if (a[index] + b[i] == max) {
            cout << index << " " << i;
            break;
        }
    }
    


}

