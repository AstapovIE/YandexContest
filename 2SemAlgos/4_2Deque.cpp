#include <iostream>

using namespace std;
//Реализовать дек с динамическим зацикленным буфером.
//Обрабатывать команды push* и pop* .
//a = 1 - push front
//a = 2 - pop front
//a = 3 - push back
//a = 4 - pop back
//Если дана команда pop *, то число b - ожидаемое значение.
//Если команда pop * вызвана для пустой структуры данных, то ожидается “-1”.

class DeQueue
{
public:
    DeQueue();
    ~DeQueue() { delete[] buffer; }

    void push_back(int a);
    void push_front(int a);
    int pop_front();
    int pop_back();

private:
    int* buffer;
    int  buffSize;
    int  head;
    int  tail;
    int  size;

    void resizeHead(); 
    void resizeTail();
};

int main()
{
    DeQueue q;
    int n;
    cin >> n;
    int a;
    int b;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        if (a == 1) { q.push_front(b); }
        if (a == 3) { q.push_back(b); }
        if (a == 2) {
            if (b != q.pop_front()) { flag = false; }
        }
        if (a == 4) {
            if (b != q.pop_back()) { flag = false; }
        }
        
    }
    if (flag) { cout << "YES"; }
    else { cout << "NO"; }
}

DeQueue::DeQueue()
{
    buffSize = 4;
    buffer = new int[buffSize];
    head = 2;
    tail = 2;
    size = 0;
}

void DeQueue::push_back(int a)
{
    if (head == tail) {
        head--;
    }
    if (tail + 1 == buffSize) { resizeTail(); }

    buffer[tail] = a;
    size++;
    tail++;
}

void DeQueue::push_front(int a)
{
    if (head == tail) {
        tail++;
    }
    if (head == 0) { resizeHead(); }

    buffer[head] = a;
    size++;
    head--;
}

int DeQueue::pop_front()
{
    if (head == tail) { return -1; }
    if (head == tail - 1) { return -1; }

    int res = buffer[head+1];
    head++;
    size--;
    return res;
}

int DeQueue::pop_back()
{
    if (head == tail) { return -1; }
    if (head == tail - 1) { return -1; }

    int res = buffer[tail - 1];
    tail--;
    size--;
    return res;
}

void DeQueue::resizeHead()
{
    int newsize = buffSize * 2;
    int* newbuff = new int[newsize];
    for (int i = tail - 1; i > head; i--) {
        newbuff[buffSize + i] = buffer[i];
    }
    head = buffSize;
    tail = buffSize + size + 1;

    delete[] buffer;

    buffer = newbuff;
    buffSize = newsize;
}

void DeQueue::resizeTail()
{
    int newsize = buffSize * 2;
    int* newbuff = new int[newsize];
    for (int i = head; i < buffSize - 1; i++) {
        newbuff[i] = buffer[i];
    }

    delete[] buffer;

    buffer = newbuff;
    buffSize = newsize;

}
