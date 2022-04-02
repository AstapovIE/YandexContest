#include <iostream>
#include <vector>

using namespace std;
//Дан массив целых чисел A[0..n). Не используя других массивов переставить элементы массива A в обратном порядке за O(n). n ≤ 10000.

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int temp = 0;
    for (int i=0; i<n ;i++){
        cin >> temp;
        arr.push_back(temp);
    }
    int j = n-1;
    int buff;
    for (int i = 0; i <= (n/2)-1; i++) {
        buff = arr[i];
        arr[i] = arr[j];
        arr[j] = buff;
        j--;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    

}

