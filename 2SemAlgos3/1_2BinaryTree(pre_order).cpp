#include <iostream>
#include <stack>

using namespace std;

//check algorithm repository
void BinaryTree::print_elements_pre_order()
{
    if (head == nullptr) { return; }
    stack<Node*> s;
    s.push(head);
    while (!s.empty()) {
        cout << s.top()->key << " ";
        Node* left = s.top()->left;
        Node* right = s.top()->right;
        s.pop();
        if (right != nullptr) { s.push(right); }
        if (left != nullptr) { s.push(left); }
    }

}

void BinaryTree::print()
{
    print_elements_pre_order();
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
    a.get_size();
}