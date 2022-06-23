#include <queue>
#include <iostream>

void BinaryTree::print_elements_level_order()
{
    if (head == nullptr) { return; }

    queue<Node*> q;
    q.push(head);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->key << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void BinaryTree::print()
{
    print_elements_in_order();
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