#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename data_type>
struct Node
{
    data_type data{};
    Node *next = nullptr;
};

template <typename data_type>
class LinkedList
{
private:
    Node<data_type> *head;

public:
    LinkedList();
    ~LinkedList();

    Node<data_type> *InsertNode(int position, data_type x);
    int FindNode(data_type x) const;
    void DeleteNode(data_type x);
    virtual void DeleteAll(const data_type &X);

    data_type get_element_in_K(int k) const;
    void delete_in_pos_kth(const int k);
    void Delete_smallest();
    int Length() const;

    bool IsEmpty() const;
    void DisplayLinkedList() const;
    void Reverse();
    void MakeLinkedListEmpty();
};

template <typename data_type>
LinkedList<data_type>::LinkedList() : head(nullptr) {}

template <typename data_type>
LinkedList<data_type>::~LinkedList()
{
    Node<data_type> *current_node = head, *next_node = nullptr;
    while (current_node != nullptr)
    {
        next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }
}

template <typename data_type>
bool LinkedList<data_type>::IsEmpty() const
{
    return (head == nullptr);
}

template <typename data_type>
Node<data_type> *LinkedList<data_type>::InsertNode(int position, data_type x)
{
    if (position < 0)
        return nullptr;

    int currposition = 1;
    Node<data_type> *current_node = head;
    while (current_node && position > currposition)
    {
        current_node = current_node->next;
        currposition++;
    }

    if (position > 0 && current_node == nullptr)
        return nullptr;

    Node<data_type> *newNode = new Node<data_type>;
    newNode->data = x;
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        newNode->next = current_node->next;
        current_node->next = newNode;
    }
    return newNode;
}

template <typename data_type>
int LinkedList<data_type>::FindNode(data_type x) const
{
    if (IsEmpty())
        return 0;

    Node<data_type> *current_node = head;
    int currposition = 1;
    while (current_node && current_node->data != x)
    {
        current_node = current_node->next;
        currposition++;
    }

    return (current_node ? currposition : 0);
}

template <typename data_type>
void LinkedList<data_type>::DeleteNode(data_type x)
{
    Node<data_type> *prevNode = nullptr, *current_node = head;
    while (current_node && current_node->data != x)
    {
        prevNode = current_node;
        current_node = current_node->next;
    }

    if (!current_node)
        return (void)(cout << "The list not have a Value\n");

    if (prevNode)
        prevNode->next = current_node->next;
    else
        head = current_node->next;

    delete current_node;
}

template <typename data_type>
void LinkedList<data_type>::DeleteAll(const data_type &X)
{
    if (IsEmpty())
        return (void)(cout << "the LinkedList is empty\n");

    Node<data_type> *current = head, *prev = nullptr;
    while (current != nullptr)
    {
        if (current->data == X)
        {
            Node<data_type> *temp = current;
            if (!prev)
            {
                head = head->next;
                current = head;
            }
            else
            {
                prev->next = current->next;
                current = current->next;
            }
            delete temp;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

template <typename data_type>
data_type LinkedList<data_type>::get_element_in_K(int k) const
{
    if (k <= 0 || IsEmpty())
        throw out_of_range("Invalid position or empty LinkedList");

    Node<data_type> *current_node = head;
    for (int pos = 1; current_node != nullptr && pos < k; pos++)
        current_node = current_node->next;

    if (!current_node)
        throw out_of_range("Index is out of range");

    return current_node->data;
}

template <typename data_type>
void LinkedList<data_type>::delete_in_pos_kth(const int k)
{
    if (k <= 0 || IsEmpty())
        return (void)(cout << "Invalid position or empty LinkedList\n");

    Node<data_type> *prevNode = nullptr, *current_node = head;
    int pos = 1;
    while (current_node && pos < k)
    {
        prevNode = current_node;
        current_node = current_node->next;
        pos++;
    }

    if (!current_node)
        return (void)(cout << "Index is out of range\n");

    if (prevNode)
        prevNode->next = current_node->next;
    else
        head = current_node->next;

    delete current_node;
}

template <typename data_type>
void LinkedList<data_type>::Delete_smallest()
{
    if (IsEmpty())
        return;
    Node<data_type> *curr = head;
    data_type value = curr->data;
    while (curr != nullptr)
    {
        if (curr->data < value)
            value = curr->data;
        curr = curr->next;
    }

    curr = head;
    Node<data_type> *prev = nullptr;
    while (curr && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr)
    {
        if (prev)
            prev->next = curr->next;
        else
            head = curr->next;
        delete curr;
    }
    this->DisplayLinkedList();
}

template <typename data_type>
void LinkedList<data_type>::DisplayLinkedList() const
{
    if (IsEmpty())
        return;
    Node<data_type> *current_node = head;
    while (current_node != nullptr)
    {
        cout << current_node->data << " ";
        current_node = current_node->next;
    }
    cout << endl;
}

template <typename data_type>
int LinkedList<data_type>::Length() const
{
    int count = 0;
    Node<data_type> *current_node = head;
    while (current_node != nullptr)
    {
        current_node = current_node->next;
        count++;
    }
    return count;
}

template <typename data_type>
void LinkedList<data_type>::Reverse()
{
    if (head == nullptr)
        return;

    Node<data_type> *curr = head, *prev = nullptr, *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <typename data_type>
void LinkedList<data_type>::MakeLinkedListEmpty()
{
    Node<data_type> *current_node = head, *next_node = nullptr;
    while (current_node != nullptr)
    {
        next_node = current_node->next;
        delete current_node;
        current_node = next_node;
    }
    head = nullptr;
}
