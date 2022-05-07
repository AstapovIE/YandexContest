#include <iostream>
#include <vector>
#include <map>

using namespace std;



int main()
{
    map<int, int> m;
    m.emplace(4, 1);
    m.emplace(3, 1);
    m.emplace(5, 1);
    int max = 6;
    int k = 0;

    int n = 0;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            cout << iter->first << " " << iter->second << endl;
        }
        n = (max - k) / (it->first);
        cout << max - k << endl;
        cout << it->first << endl;
        cout << n << endl;

        for (int i = 0; i < n; i++) {
            
        }

        if (it->first + k <= max) {
            k += it->first;
            it->second -= 1;
            if (it->second == 0) {
                int temp = it->first;
                m.erase(temp);
            }
        }
        if (k == max) { break; }
    }
    cout << "haha" << endl;

    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        cout << iter->first << " "<< iter->second << endl;
    }
    
}
