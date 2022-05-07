#include <iostream>
#include <stack>
#include <string>

using namespace std;
//Дан фрагмент последовательности скобок, состоящей из символов (){}[].
//Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную последовательность.
//Длина исходной последовательности ≤ 800000.

void print(stack<char>& s)
{
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        cout << s.top();
        s.pop();
    }
}

void fill(stack<char>& s)
{
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s.top() == '(') { cout << ')'; }
        if (s.top() == '{') { cout << '}'; }
        if (s.top() == '[') { cout << ']'; }
        s.pop();
    }
}

int main()
{
    stack<char> left;

    string buf;
    getline(cin, buf);
    int n = buf.size();

    stack<char> seq;
    bool is_pos = true;
    for (int i = 0; i != n; ++i)
    {
        char x = buf[i];
        bool flag = false;
        if (x == ')'){
            flag = true;
            if (seq.empty()) { left.push('('); }
            else {
                if (seq.top() == '(') { seq.pop(); }
                else {
                    is_pos = false;
                    cout << "IMPOSSIBLE";
                    break;
                }
            }
        }
        if (x == ']') {
            flag = true;
            if (seq.empty()) { left.push('['); }
            else {
                if (seq.top() == '[') { seq.pop(); }
                else {
                    is_pos = false;
                    cout << "IMPOSSIBLE";
                    break;
                }
            }
        }
        if (x == '}') {
            flag = true;
            if (seq.empty()) { left.push('{'); }
            else {
                if (seq.top() == '{') { seq.pop(); }
                else {
                    is_pos = false;
                    cout << "IMPOSSIBLE";
                    break;
                }
            }
        }
        if (!flag) {
            seq.push(x);
        }
    }
    if (is_pos) {
        print(left);
        cout << buf;
        fill(seq);
    }
    
}