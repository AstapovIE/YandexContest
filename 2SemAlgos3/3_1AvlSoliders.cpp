#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class AvlTree
{
private:
    struct Node
    {
        int key;
        int height;
        Node* left;
        Node* right;
        Node(int key, Node* left = nullptr, Node* right = nullptr, int height = 0) {
            this->key = key;
            this->left = left;
            this->right = right;
            this->height = height;
        }

    };

    Node* root;

    Node* insert(int x, Node* t) {
        if (t == nullptr) {
            t = new Node(x);
        }
        else if (x < t->key)
        {
            t->left = insert(x, t->left);
            //checking balance
            if (get_height(t->left) - get_height(t->right) == 2) {
                if (x < t->left->key)
                    t = smallRightRotate(t);
                else
                    t = bigRightRotate(t);

            }
        }
        else if (x > t->key)
        {
            t->right = insert(x, t->right);
            //checking balance
            if (get_height(t->right) - get_height(t->left) == 2) {
                if (x > t->right->key)
                    t = smallLeftRotate(t);
                else
                    t = bigLeftRotate(t);

            }
        }

        t->height = max(get_height(t->left), get_height(t->right)) + 1;
        return t;
    }

    Node* smallLeftRotate(Node* t) {
        if (t->right != nullptr) {
            Node* s = t->right;
            t->right = s->left;
            s->left = t;
            t->height = max(get_height(t->left), get_height(t->right)) + 1;
            s->height = max(get_height(t->right), t->height) + 1;
            return s;
        }
        return t;
    }

    Node* bigLeftRotate(Node* t) {
        t->right = smallRightRotate(t->right);
        return smallLeftRotate(t);
    }

    Node* smallRightRotate(Node* t) {
        if (t->left != nullptr) {
            Node* s = t->left;
            t->left = s->right;
            s->right = t;
            t->height = max(get_height(t->left), get_height(t->right)) + 1;
            s->height = max(get_height(s->left), t->height) + 1;
            return s;
        }
        return t;
    }

    Node* bigRightRotate(Node* t) {
        t->left = smallLeftRotate(t->left);
        return smallRightRotate(t);
    }

    int get_height(Node* t)
    {
        return (t == nullptr ? -1 : t->height);
    }

    void find(Node* t, vector<int> &arr) {
        if (t == nullptr) {
            return;
        }
        find(t->right, arr);
        arr.push_back(t->key);
        find(t->left, arr);
    }

    void print(Node* t) {
        if (t == nullptr) { return; }
        print(t->left);
        cout << t->key << " ";
        print(t->right);
    }

    Node* remove(int x, Node* t) {

        if (t == nullptr) return nullptr; //element not found
        if (x < t->key)
            t->left = remove(x, t->left);
        else if (x > t->key)
            t->right = remove(x, t->right);

        //if element found
        else if (t->left && t->right) //if 2 child
        {
            Node* temp = findMin(t->right);
            t->key = temp->key;
            t->right = remove(t->key, t->right);
        }

        //if 1 or 0 child
        else {
            Node* temp = t;
            if (t->left == nullptr)
                t = t->right;
            else if (t->right == nullptr)
                t = t->left;
            delete temp;
        }

        if (t == nullptr) return t;

        //checking balance
        if (get_height(t->left) - get_height(t->right) == 2)
        {

            if (get_height(t->left->left) - get_height(t->left->right) == 1)
                return smallLeftRotate(t);

            else
                return bigLeftRotate(t);
        }

        else if (get_height(t->right) - get_height(t->left) == -2)
        {

            if (get_height(t->right->right) - get_height(t->right->left) == 1)
                return smallRightRotate(t);

            else
                return bigRightRotate(t);
        }

        return t;
    }

    Node* findMax(Node* t) {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else return findMax(t->right);
    }

    Node* findMin(Node* t) {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else return findMin(t->left);
    }

    void clear(Node* t) {
        if (!(t == nullptr)) {
            clear(t->left);
            clear(t->right);
        }
        delete t;
    }

public:
    AvlTree();
    ~AvlTree();
    void insert(int key);
    void pfind(int key);
    void print();
    void remove(int key);
    int to_remove(int y);


};


AvlTree::AvlTree()
{
    root = nullptr;
}

AvlTree::~AvlTree()
{
    clear(root);
}

void AvlTree::insert(int key)
{
    root = insert(key, root);
}

void AvlTree::pfind(int key)
{
    vector<int> a;
    find(root, a);
    
    int k = a.size();
    for (int i = 0; i < k; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < k; i++) {
        if (a[i] == key) {
            cout << i << endl;;
            return;
        }
    }
    cout << endl;
}

void AvlTree::print()
{
    print(root);
    cout << endl;
}

void AvlTree::remove(int key)
{
    root = remove(key, root);
}

int AvlTree::to_remove(int y)
{
    vector<int> a;
    find(root, a);
    int k = a.size();
    for (int i = 0; i < k; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return a[y];
}



int main()
{
    AvlTree a;
    int n;
    cin >> n;
    int f;
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> f;
        cin >> temp;
        if (f == 1) {
            a.insert(temp);
            //a.print();
            a.pfind(temp);
        }
        else {
            a.remove(a.to_remove(temp));
            //a.print();
        }
        cout << "-----" << endl;
    }
}