#pragma once

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int value = 0) : left(nullptr), right(nullptr), data(value) {}
};

class Binary_Tree
{
private:
    Node *root;
    void clear(Node *r);

public:
    Binary_Tree();
    ~Binary_Tree();

    Node *insert(Node *r, int value);
    void insert(int value);
    Node *search(Node *r, int value);
    bool search(int value);

    Node *findMin(Node *r);
    int findMin();
    Node *findMax(Node *r);
    int findMax();

    bool no_child(Node *r);

    void display_inorder(Node *r);
    void display_preorder(Node *r);
    void display_postorder(Node *r);
    void display();

    Node *Delete_Node(Node *r, int value);
    bool Delete_Node(int value);
};

Binary_Tree::Binary_Tree() : root(nullptr) {}

void Binary_Tree::clear(Node *r)
{
    if (r == nullptr)
        return;
    clear(r->left);
    clear(r->right);
    delete r;
}

Binary_Tree::~Binary_Tree()
{
    clear(root);
}

Node *Binary_Tree::insert(Node *r, int value)
{
    if (r == nullptr)
        return new Node(value);
    if (value < r->data)
        r->left = insert(r->left, value);
    else
        r->right = insert(r->right, value);
    return r;
}

void Binary_Tree::insert(int value)
{
    root = insert(root, value);
}

Node *Binary_Tree::search(Node *r, int value)
{
    return (r == nullptr || r->data == value) ? r : (value < r->data) ? search(r->left, value): search(r->right, value);
}

bool Binary_Tree::search(int value)
{
    Node *flag = search(root, value);
    return (flag != nullptr);
}

Node *Binary_Tree::findMin(Node *r)
{
    return (r == nullptr || r->left == nullptr) ? r : findMin(r->left);
}

int Binary_Tree::findMin()
{
    return (root == nullptr) ? -1 : findMin(root)->data;
}

Node *Binary_Tree::findMax(Node *r)
{
    return (r == nullptr || r->right == nullptr) ? r : findMax(r->right);
}

int Binary_Tree::findMax()
{
    return (root == nullptr) ? -1 : findMax(root)->data;
}

bool Binary_Tree::no_child(Node *r)
{
    return (r != nullptr && r->left == nullptr && r->right == nullptr);
}

Node *Binary_Tree::Delete_Node(Node *r, int value)
{
    if (r == nullptr)
        return nullptr;
    if (value < r->data)
        r->left = Delete_Node(r->left, value);
    else if (value > r->data)
        r->right = Delete_Node(r->right, value);
    else
    {
        if (no_child(r))
        {
            delete r;
            return nullptr;
        }
        else if (r->left == nullptr)
        {
            Node *temp = r->right;
            delete r;
            return temp;
        }
        else if (r->right == nullptr)
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        else
        {
            Node *maxi = findMax(r->left);
            r->data = maxi->data;
            r->left = Delete_Node(r->left, maxi->data);
        }
    }
    return r;
}

bool Binary_Tree::Delete_Node(int value)
{
    if (!search(value))
        return false;
    root = Delete_Node(root, value);
    return true;
}

void Binary_Tree::display_inorder(Node *r)
{
    if (r == nullptr)
        return;
    display_inorder(r->left);
    cout << r->data << "\t";
    display_inorder(r->right);
}

void Binary_Tree::display_preorder(Node *r)
{
    if (r == nullptr)
        return;
    cout << r->data << "\t";
    display_preorder(r->left);
    display_preorder(r->right);
}

void Binary_Tree::display_postorder(Node *r)
{
    if (r == nullptr)
        return;
    display_postorder(r->left);
    display_postorder(r->right);
    cout << r->data << "\t";
}

void Binary_Tree::display()
{
    if (root == nullptr)
        return;
    int choice;
    cout << "\tWhich display you want\t\n";
    do
    {
        cout << "\n____________________________________________________\n";
        cout << "\n1. inorder\n2. preorder\n3. postorder\n0. exit\n";
        cout << "choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            display_inorder(root);
            break;
        case 2:
            display_preorder(root);
            break;
        case 3:
            display_postorder(root);
            break;
        default:
            break;
        }
    } while (choice != 0);
}
