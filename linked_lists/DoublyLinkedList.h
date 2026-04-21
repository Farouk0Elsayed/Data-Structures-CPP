#pragma once

#include <iostream>
using namespace std;

template <typename data_type>
struct Node
{
public:
    data_type data;
    Node *next = nullptr, *prev = nullptr;
};

template <typename data_type>
class DoublyLinkedList
{
private:
    Node<data_type> *head;
    void createHead();

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool isEmpty() const;
    Node<data_type>* searchNode(const data_type& item) const;
    void insertNode(const data_type& item);
    void deleteNode(const data_type& item);
    void print() const;
    void printReversed() const;
    int countNodes() const;
};

template <typename data_type>
void DoublyLinkedList<data_type>::createHead()
{
    head = new Node<data_type>;
    head->next = head->prev = head;
}

template <typename data_type>
DoublyLinkedList<data_type>::DoublyLinkedList()
{
    createHead();
}

template <typename data_type>
DoublyLinkedList<data_type>::~DoublyLinkedList()
{
    Node<data_type> *current = head->next, *nextNode;
    while (current != head)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    delete head;
}

template <typename data_type>
bool DoublyLinkedList<data_type>::isEmpty() const
{
    return (head->next == head);
}

template <typename data_type>
Node<data_type> *DoublyLinkedList<data_type>::searchNode(const data_type& item) const
{
    Node<data_type> *curr = head->next;
    while (curr != head)
    {
        if (curr->data == item)
            return curr;
        if (curr->data > item)
            break;
        curr = curr->next;
    }
    return NULL;
}

template <typename data_type>
void DoublyLinkedList<data_type>::insertNode(const data_type& item)
{
    Node<data_type> *New = new Node<data_type>, *curr = head->next;
    New->data = item;
    while (curr != head)
    {
        if (curr->data < item)
            curr = curr->next;
        else
            break;
    }
    New->next = curr;
    New->prev = curr->prev;
    curr->prev->next = New;
    curr->prev = New;
}

template <typename data_type>
void DoublyLinkedList<data_type>::deleteNode(const data_type& item)
{
    Node<data_type> *curr = searchNode(item);
    if (curr != NULL)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }
    else
    {
        return void(cout << "Item not found, cannot delete.\n");
    }
}

template <typename data_type>
void DoublyLinkedList<data_type>::print() const
{
    if (isEmpty())
        return void(cout << "List is empty\n");

    Node<data_type> *curr = head->next;
    while (curr != head)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

template <typename data_type>
void DoublyLinkedList<data_type>::printReversed() const
{
    if (isEmpty())
        return void(cout << "List is empty\n");

    Node<data_type> *curr = head->prev;
    while (curr != head)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

template <typename data_type>
int DoublyLinkedList<data_type>::countNodes() const
{
    int count = 0;
    Node<data_type> *current = head->next;
    while (current != head)
    {
        count++;
        current = current->next;
    }
    return count;
}
