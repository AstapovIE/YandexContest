#include <iostream>


using namespace std;
/*Дана очень длинная последовательность целых чисел длины n.
Требуется вывести в отсортированном виде её наименьшие k элементов.
Последовательность может не помещаться в память. Время работы O(n * log(k)). 
Доп. память O(k). Использовать слияние.*/


void Mymerge_sort(int* arr, int n, int k=0)
{
    if (n <= 1) return;  

    int mid = n / 2;

    Mymerge_sort(arr, mid);
    Mymerge_sort(arr + mid, n - mid);

    // Merge
    int* buffer = new int[n];
    int left_i = 0;
    int right_i = 0;
    int buffer_i = 0;

    while (left_i < mid and right_i < n-mid) {
        if (arr[left_i] <= (arr+mid)[right_i]) {

            buffer[buffer_i] = arr[left_i];
            left_i += 1;
            buffer_i += 1;
        }
        else {
 
            buffer[buffer_i] = (arr + mid)[right_i];
            right_i += 1;
            buffer_i += 1;
        }
    }
    while (left_i < mid) {
        buffer[buffer_i] = arr[left_i];
        left_i += 1;
        buffer_i += 1;
    }
    while (right_i < n-mid) {
        buffer[buffer_i] = (arr + mid)[right_i];
        right_i += 1;
        buffer_i += 1;
    }
    
    if (k>0) {
        for (int i = 0; i < k; i++) {
            arr[i] = buffer[i];
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            arr[i] = buffer[i];
        }
    }
    delete[] buffer;
}



void print(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;
    
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Mymerge_sort(arr, n, k);
    print(arr, k);

}