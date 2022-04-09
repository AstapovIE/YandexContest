#include <iostream>

using namespace std;
//Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью динамического буфера.
//Обрабатывать команды push back и pop front.
/*Каждая команда задаётся как 2 целых числа: a b.
a = 2 - pop front
a = 3 - push back
Если дана команда pop front, то число b - ожидаемое значение.
Если команда pop front вызвана для пустой структуры данных, то ожидается “-1”.*/

class Queue{
public:
 

    class Stack
    {
    public:
        Stack();
        ~Stack() { delete[] buffer; }

        void push_back(int a);
        int pop_front();

    public:
        int* buffer;
        int  buffSize;
        int  head;
        int  tail;

        void resize();
    };

    int pop_front();
    void push_back(int value);
    void transfer();
    Stack left;
    Stack right;

};

int main()
{
    Queue q;
    int n;
    cin >> n;
    int a;
    int b;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        if (a == 3) { q.push_back(b); }
        else {
            if (b != q.pop_front()) { flag = false; }
        }
        
    }
    if (flag) { cout << "YES"; }
    else { cout << "NO"; }
}




int Queue::pop_front()
{
    if (right.tail != 0) { return right.pop_front(); }
    else {transfer(); }
    if (right.tail != 0) { return right.pop_front(); }
    else { return -1; }
}

void Queue::push_back(int value)
{
    left.push_back(value);
    if (left.buffSize > right.buffSize) { right.resize(); }
}

Queue::Stack::Stack()
{
    buffSize = 2;
    buffer = new int[buffSize];
    head = 0;
    tail = 0;
}

void Queue::Stack::push_back(int a)
{
    if (tail + 1 == buffSize) { resize(); }

    buffer[tail] = a;
    tail++;
}

int Queue::Stack::pop_front()
{
    int res = buffer[tail - 1];
    tail--;
    return res;
}

void Queue::transfer()
{
    int temp;
    if (left.tail != 0) {
        for (int i = left.tail -1; i >= left.head; i--) {
            temp = left.buffer[i];
            right.push_back(temp);
        }
        left.tail = 0;
    }

}



void Queue::Stack::resize()
{
    int newsize = buffSize * 2;
    int* newbuff = new int[newsize];
    for (int i = 0; i < buffSize - 1; i++) {
        newbuff[i] = buffer[i];
    }

    delete[] buffer;

    buffer = newbuff;
    buffSize = newsize;

}
