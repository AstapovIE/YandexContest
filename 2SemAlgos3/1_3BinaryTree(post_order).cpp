#include <stack>
#include <iostream>

using namespace std;

//check algorithm repository
void BinaryTree::print_elements_post_order()
{
    if (head == nullptr) { return; }

    stack<Node*> s;
    s.push(head);

    stack<Node*> buf;

    while (s.size() != this->size) {
        while (s.top()->right != nullptr) {
            if (s.top()->left != nullptr) {
                buf.push(s.top()->left);
            }
            s.push(s.top()->right);
        }
        if (s.top()->left != nullptr) {
            s.push(s.top()->left);
        }
        if (s.top()->left == nullptr && s.top()->right == nullptr) {
            if (!buf.empty()) {
                s.push(buf.top());
                buf.pop();
            }
        }
    }

    while (!s.empty()) {
        cout << s.top()->key << " ";
        s.pop();
    }


}

void BinaryTree::print()
{
    print_elements_post_order();
    cout << endl;
}

int main()
{
    BinaryTree a;

    int n;
    cin >> n;

    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        a.insert(temp);
    }


    a.print();
}