#include <string>
#include <iostream>
#include <vector>

using namespace std;
//Дан фрагмент последовательности скобок, состоящей из символов (){}[].
//Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную последовательность.
//Длина исходной последовательности ≤ 800000.

bool is_possible(string str)
{
    string open("({[");
    string close(")}]");
    int n = str.size() - 1;
    for (int i = 0; i < n; i++) {
        if ((str[i] == '(' && str[i + 1] == '}') |
            (str[i] == '(' && str[i + 1] == ']') |
            (str[i] == '[' && str[i + 1] == ')') |
            (str[i] == '[' && str[i + 1] == '}') |
            (str[i] == '{' && str[i + 1] == ')') |
            (str[i] == '{' && str[i + 1] == ']'))
        {
            return false;
        }

    }
    
    return true;
}

int main()
{
    string seque;
    string close(")}]");
    getline(cin, seque);
    seque.push_back('}');
    seque.insert(0, ")");
    cout << seque[0] << endl;
    cout << seque.size() << endl;
    int x = seque.find("]");
    cout << x << endl;
    x = close.find("}");
    cout << x << endl;
    if (is_possible(seque)) {
        cout << "Dsd";
    }
}

