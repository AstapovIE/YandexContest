#include <iostream>
#include <string>
#include <stack>

using namespace std;
/*Пара слов называется стековой анаграмой, если одно слово можно получить из другого,
проведя последовательность стековых операций с его буквами (взять очередную букву исходного слова и поместить ее в стек;
взять букву из стека и добавить ее в конец выходного слова). Для заданной пары слов требуется определить,
можно ли выполнить последовательность стековых операций, переводящую первое слово во второе. Все буквы в слове различные.
Длина анаграммы ≤ 10000.*/
// SLOT -> STOL YES
// ABC -> CAB NO

int main()
{
    string primary;
    cin >> primary;
    int n = primary.size();

    string final;
    cin >> final;
    
    stack<char> prim;
    int fin = 0;
    
    int k = 0;
    char to_find = final[k];
    int i = 0;
    while (i != n)
    {
        prim.push(primary[i]);
        
        while (!prim.empty() && prim.top() == to_find){
            prim.pop();
            ++fin;
            ++k;
            to_find = final[k];
        }

        ++i;
    }
    while (!prim.empty())
    {
        if (prim.top() == to_find) {
            prim.pop();
            ++fin;
            ++k;
            to_find = final[k];
        }
        else { break; }
    }
    if (prim.empty()) {
        cout << "YES";
    }
    else {
        if (fin == final.size()) {
            cout << "YES";
        }
        else { cout << "NO"; }
    }
}
