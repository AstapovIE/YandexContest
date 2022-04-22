#include <string>
#include <iostream>

using namespace std;
//Дан фрагмент последовательности скобок, состоящей из символов (){}[].
//Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную последовательность.
//Длина исходной последовательности ≤ 800000.



/*bool is_possible(string& str)
{
    int open = 0;
    int close = 0;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            int j = i + 1;
            while (j < n && str[j] != ')')
            {
                if (str[j] == '(' | str[j] == '[' | str[j] == '{') {
                    open++;
                }
                else { close++; }
                if (close > open) { return false; }
                j++;
            }
        }
        if (str[i] == '{') {
            int j = i + 1;
            while (j < n && str[j] != '}')
            {
                if (str[j] == '(' | str[j] == '[' | str[j] == '{') {
                    open++;
                }
                else { close++; }
                if (close > open) { return false; }
                j++;
            }
        }
        if (str[i] == '[') {
            int j = i + 1;
            while (j < n && str[j] != ']')
            {
                if (str[j] == '(' | str[j] == '[' | str[j] == '{') {
                    open++;
                }
                else { close++; }
                if (close > open) { return false; }
                j++;
            }

        }
        //if (close > open) { return false; }
        open = 0;
        close = 0;
    }
    
    return true;
}*/

bool is_possible(string& str)
{
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

pair<int, int> find_near(string& str, char open, char close, int index) {
    pair<int, int> res;
    res.second = str.size() - 1;
    bool flag = false;
    res.first = index;
    int i = index + 1;
    while (i <= res.second)
    {
        if (str[i] == open) {
            res.first = i;
        }
        if (str[i] == close && !flag) {
            res.second = i;
            
            flag = true;
        }
        i++;
    }
    if (str[res.second] != close) {
        res.second = -1;
    }
    return res;
}

void clear(string& str)
{   
    bool flag = false;
    int x = 0;
    for (int i = 0; i < str.size(); i++) {
        if (flag) {
            i = i - 1;
            flag = false;
        }
        if (str[i] == '{') {
            pair<int, int> to_del = find_near(str, '{', '}', i);
            if (to_del.second > 0) {
                str.erase(to_del.first, 1);
                str.erase(to_del.second - 1, 1);
                flag = true;
            }
        }
        else {
            if (str[i] == '(') {
                pair<int, int> to_del = find_near(str, '(', ')', i);
                if (to_del.second > 0) {
                    str.erase(to_del.first, 1);
                    str.erase(to_del.second - 1, 1);
                    flag = true;
                }
            }
            else
            {
                if (str[i] == '[') {
                    pair<int, int> to_del = find_near(str, '[', ']', i);
                    if (to_del.second > 0) {
                        str.erase(to_del.first, 1);
                        str.erase(to_del.second - 1, 1);
                        flag = true;
                    }
                }
            }
        }

    }
    //return str;
 }

void fill(string& first, string& cleaned)
{
    int n = cleaned.size();
    for (int i = 0; i < n; i++) {
        if (cleaned[i] == ')') {
            first.insert(0, "(");
        }
        if (cleaned[i] == '}') {
            first.insert(0, "{");
        }
        if (cleaned[i] == ']') {
            first.insert(0, "[");
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (cleaned[i] == '(') {
            first.push_back(')');
        }
        if (cleaned[i] == '{') {
            first.push_back('}');
        }
        if (cleaned[i] == '[') {
            first.push_back(']');
        }
    }
    //return first;
        
}

int main()
{
    string seque;
    
    getline(cin, seque);
    string result = seque;
    clear(seque);
    if (is_possible(seque)) {
        //string cl_seque = clear(seque);
        fill(result, seque);
        cout << result;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    
}

/*#include <string>
#include <iostream>

using namespace std;

bool is_possible(string& str)
{
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

int find_near(string& str, char open, int index) {
    int max_i = 0;
    for(int i = 0; i < index; i++){
        if (str[i] == open) {
            max_i = i;
        }
    }
    return max_i;
}

void clear(string& str)
{   
    bool flag = false;
    int x = 0;
    for (int i = 0; i < str.size(); i++) {
        if (flag) {
            i = i - 1;
            flag = false;
        }
        if (str[i] == '{') {
            x = str.find('}', i);
            if (x > 0) {
                int to_del = find_near(str, '{', x);
                str.erase(to_del, 1);
                str.erase(x - 1, 1);
                flag = true;
                x = 0;
            }
        }
        else {
            if (str[i] == '(') {
                x = str.find(')', i);
                if (x > 0) {
                    int to_del = find_near(str, '(', x);
                    str.erase(to_del, 1);
                    str.erase(x - 1, 1);
                    flag = true;
                    x = 0;
                }
            }
            else
            {
                if (str[i] == '[') {
                    x = str.find(']', i);
                    if (x > 0) {
                        int to_del = find_near(str, '[', x);
                        str.erase(to_del, 1);
                        str.erase(x - 1, 1);
                        flag = true;
                        x = 0;
                    }
                }
            }
        }

    }
    //return str;
 }

void fill(string& first, string& cleaned)
{
    int n = cleaned.size();
    for (int i = 0; i < n; i++) {
        if (cleaned[i] == ')') {
            first.insert(0, "(");
        }
        if (cleaned[i] == '}') {
            first.insert(0, "{");
        }
        if (cleaned[i] == ']') {
            first.insert(0, "[");
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (cleaned[i] == '(') {
            first.push_back(')');
        }
        if (cleaned[i] == '{') {
            first.push_back('}');
        }
        if (cleaned[i] == '[') {
            first.push_back(']');
        }
    }
    //return first;
        
}

int main()
{
    string seque;
    
    getline(cin, seque);
    string result = seque;
    clear(seque);
    if (is_possible(seque)) {
        //string cl_seque = clear(seque);
        fill(result, seque);
        cout << result;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    
}

*/
