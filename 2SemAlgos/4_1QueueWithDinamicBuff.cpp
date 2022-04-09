#include <iostream>

using namespace std;

class Queue 
{
public:
    Queue();
    ~Queue() { delete[] buffer; }

    void push_back(int a);
    int pop_front();

private:
    int* buffer;
    int  buffSize;
    int  head;
    int  tail;

    void resize();
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
        if (a == 3) {
            q.push_back(b);
        }
        else {
            int res = q.pop_front();
            if (res != b) {
                flag = false;
            }
        }
    }
    if (flag) { cout << "YES"; }
    else { cout << "NO"; }
}

Queue::Queue()
{
    buffSize = 2;
    buffer = new int[buffSize];
    head = 0;
    tail = 0;
}

void Queue::push_back(int a)
{
    if (tail + 1 == buffSize) { resize(); }

    buffer[tail] = a;
    tail++;
}

int Queue::pop_front()
{
    if (head == tail) { return -1; }

    int res = buffer[head];
    head++;
    return res;
}

void Queue::resize()
{
    int newsize = buffSize * 2;
    int* newbuff = new int[newsize];
    for (int i = 0; i < buffSize-1; i++) {
        newbuff[i] = buffer[i];
    }

    delete[] buffer;

    buffer = newbuff;
    buffSize = newsize;
    
}
