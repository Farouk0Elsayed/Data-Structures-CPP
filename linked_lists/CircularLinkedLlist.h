#pragma once

#include <iostream>
using namespace std;

template <typename data_type>
struct Node
{
    data_type data;
    Node *next;
};

template <typename data_type>
class CircularLinkedList
{
private:
    Node<data_type> *rear;

public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insertNode(data_type value);
    void deleteNode(data_type value);
    bool IsEmpty() const;
    bool IsFull() const;
    void print();
    int countNodes();
};

template <typename data_type>
CircularLinkedList<data_type>::CircularLinkedList() : rear(NULL) {}

template <typename data_type>
CircularLinkedList<data_type>::~CircularLinkedList()
{
    if (rear == NULL)
        return;
    Node<data_type> *curr = rear->next;
    while (curr != rear)
    {
        Node<data_type> *temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete rear;
    rear = NULL;
}

template <typename data_type>
void CircularLinkedList<data_type>::insertNode(data_type value)
{
    Node<data_type> *New_node = new Node<data_type>;
    New_node->data = value;
    if (rear == NULL)
    {
        rear = New_node;
        rear->next = rear;
        return;
    }
    Node<data_type> *prev = rear, *curr = rear->next;
    do
    {
        if (value <= curr->data)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != rear->next);

    New_node->next = curr;
    prev->next = New_node;
    if (value >= rear->data)
        rear = New_node;
}

template <typename data_type>
void CircularLinkedList<data_type>::deleteNode(data_type value)
{
    if (rear == NULL)
        return void(cout << "The Circular is empty\n");

    Node<data_type> *curr = rear->next, *prev = rear;
    bool found = false;
    do
    {
        if (curr->data == value)
        {
            found = true;
            break;
        }
        if (curr->data > value)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != rear->next);

    if (!found)
        return void(cout << "Item not found\n");

    if (curr == prev)
    {
        rear = NULL;
    }
    else
    {
        prev->next = curr->next;
        if (curr == rear)
            rear = prev;
    }
    delete curr;
}

template <typename data_type>
bool CircularLinkedList<data_type>::IsEmpty() const
{
    return (rear == NULL);
}

template <typename data_type>
bool CircularLinkedList<data_type>::IsFull() const
{
    Node<data_type> *temp = new (nothrow) Node<data_type>;
    if (temp == NULL)
        return true;
    delete temp;
    return false;
}

template <typename data_type>
void CircularLinkedList<data_type>::print()
{
    if (IsEmpty())
        return void(cout << "The Circular is Empty\n");

    Node<data_type> *curr = rear->next;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != rear->next);
    cout << endl;
}

template <typename data_type>
int CircularLinkedList<data_type>::countNodes()
{
    if (IsEmpty())
    {
        cout << "The Circular is Empty\n";
        return 0;
    }
    int cnt = 0;
    Node<data_type> *curr = rear->next;
    do
    {
        cnt++;
        curr = curr->next;
    } while (curr != rear->next);

    return cnt;
}
