#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*Напишите программу, печатающую набор строк в лексикографическом порядке.
Строки разделяются символом перевода строки ’∖n’. Если последний символ в потоке ввода ’∖n’, считать, что после него нет пустой строки.
Известно, что либо n<100, либо ≤ 1000, но при этом число инверсий в данном наборе строк меньше 100. Максимальная длина строки 255 символов.
Написать свою функцию сравнения строк. Сортировать вставками.*/

bool isless(string s1, string s2)
{
    int i{ 0 };

    while (s1[i] == s2[i] && i < s1.size() && i < s2.size() )
        i++;
    if (i == s1.size())
        return true;
    if (i == s2.size())
        return false;

    if (i == s1.size() && i == s2.size())
        return false;
    
    if (s1[i] < s2[i])
        return true;

    return false;
}

void insertSort(vector<string>& arr, int n) {

    for (int i = 1; i < n; ++i) {
        string tmp = arr[i];
        int j = i - 1;
        for (; j >= 0 && isless(tmp, arr[j]); --j) {
            swap(arr[j + 1], arr[j]);
        }
    }

}


int main()
{
    vector<string> arr;
    int n;
    cin >> n;

    string temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        arr.push_back(temp);
    }

    insertSort(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}
