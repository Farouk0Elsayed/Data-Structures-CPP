#pragma once

#include <iostream>
using namespace std;

template <class data_type>
class Node
{
public:
    data_type data{};
    Node<data_type> *next = nullptr;
};

template <class data_type>
class QueueTypeLinked
{
private:
    Node<data_type> *qFront, *qRear;
    bool search(data_type item) const;
public:
    QueueTypeLinked();
    ~QueueTypeLinked();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(const data_type &);
    void Dequeue(data_type &);
    void Union(const QueueTypeLinked<data_type> &other_queue);
    int Length() const;
};

template <class data_type>
QueueTypeLinked<data_type>::QueueTypeLinked()
{
    qFront = qRear = nullptr;
}

template <class data_type>
void QueueTypeLinked<data_type>::MakeEmpty()
{
    Node<data_type> *tempPtr;
    while (qFront != nullptr)
    {
        tempPtr = qFront;
        qFront = qFront->next;
        delete tempPtr;
    }
    qRear = nullptr;
}

template <class data_type>
QueueTypeLinked<data_type>::~QueueTypeLinked()
{
    MakeEmpty();
}

template <class data_type>
bool QueueTypeLinked<data_type>::IsEmpty() const
{
    return (qFront == nullptr);
}

template <class data_type>
bool QueueTypeLinked<data_type>::IsFull() const
{
    try
    {
        Node<data_type> *New = new Node<data_type>;
        delete New;
        return false;
    }
    catch (const std::exception &e)
        return true;
}

template <class data_type>
void QueueTypeLinked<data_type>::Enqueue(const data_type &newItem)
{
    Node<data_type> *newNode = new Node<data_type>;
    newNode->data = newItem;
    newNode->next = nullptr;
    if (qRear == nullptr)
        qFront = newNode;
    else
        qRear->next = newNode;
    qRear = newNode;
}

template <class data_type>
void QueueTypeLinked<data_type>::Dequeue(data_type &item)
{
    if (IsEmpty())
        return;

    Node<data_type> *tempPtr = qFront;
    item = qFront->data;
    qFront = qFront->next;
    if (qFront == nullptr)
        qRear = nullptr;
    delete tempPtr;
}

template <class data_type>
int QueueTypeLinked<data_type>::Length() const
{
    int length = 0;
    Node<data_type> *cur = qFront;
    while (cur != nullptr)
    {
        length++;
        cur = cur->next;
    }
    return length;
}

template <class data_type>
bool QueueTypeLinked<data_type>::search(data_type item) const
{
    Node<data_type> *curr = qFront;
    while (curr != nullptr)
    {
        if (curr->data == item)
            return true;
        curr = curr->next;
    }
    return false;
}

template <class data_type>
void QueueTypeLinked<data_type>::Union(const QueueTypeLinked<data_type> &other_queue)
{
    Node<data_type> *curr = other_queue.qFront;
    while (curr != nullptr)
    {
        if (!search(curr->data))
            Enqueue(curr->data);
        curr = curr->next;
    }
}
