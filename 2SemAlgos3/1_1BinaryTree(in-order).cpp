#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class BinaryTree
{
private:
    class Node
    {
    public:
        int key;
        Node* left;
        Node* right;
        Node* parent;

        Node(int key, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) {
            this->key = key;
            this->left = left;
            this->right = right;
            this->parent = parent;
        }
    };
    int size;
    Node* head;

    void print_elem(Node* current);
    void print_elements_in_order();
    void print_elements_pre_order();
    void print_elements_post_order();
    void print_elements_level_order();

public:
    BinaryTree();
    ~BinaryTree();

    void get_size();
    bool find(int key);
    void insert(int key);
    void print();
    void remove(int key);
};


void BinaryTree::print_elem(Node* current)
{
    if (current) {
        print_elem(current->left);
        cout << current->key << " ";
        print_elem(current->right);
    }

}

void BinaryTree::print_elements_in_order()
{
    if (head == nullptr) { return; }

    Node* current = head;
    stack<Node*> s;

    while ( (current != nullptr) || (!s.empty()) ) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->key << " ";

        current = current->right;
    }
}

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

BinaryTree::BinaryTree()
{
    head = nullptr;
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::get_size()
{
    cout << size << endl;;
}

bool BinaryTree::find(int key)
{
    Node* current = this->head;
    while (current) {
        if (current->key == key) { return true; }
        if (current->key > key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

void BinaryTree::insert(int key)
{
    if (head != nullptr)
    {
        Node* current = this->head;
        while (current) {
            if (current->key > key && current->left == nullptr) {
                current->left = new Node(key);
                size++;
                return;
            }
            if (current->key <= key && current->right == nullptr) {
                current->right = new Node(key);
                size++;
                return;
            }
            if (current->key > key) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

    }


    else { head = new Node(key); size++; }
}

void BinaryTree::print()
{
    print_elements_in_order();
    cout << endl;
}

void BinaryTree::remove(int key)
{

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

