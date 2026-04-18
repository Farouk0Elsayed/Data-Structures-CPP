#pragma once

#include <iostream>
using namespace std;

template <typename data_type>
class CircularQueue
{
private:
    data_type *items;
    int frontIdx, rearIdx, capacity, elements;

public:
    CircularQueue(int size = 100);
    CircularQueue(const CircularQueue<data_type> &otherqueue);
    ~CircularQueue();

    bool IsEmpty() const;
    bool IsFull() const;

    void MakeEmpty();
    void Enqueue(data_type item);
    void Dequeue();
    void display() const;

    int getSize() const;
    data_type getBack() const;
    data_type getFront() const;
};

template <typename data_type>
CircularQueue<data_type>::CircularQueue(int size)
    : frontIdx(-1), rearIdx(-1), capacity(size), elements(0)
{
    items = new data_type[capacity];
}

template <typename data_type>
CircularQueue<data_type>::CircularQueue(const CircularQueue<data_type> &otherqueue)
    : capacity(otherqueue.capacity), elements(otherqueue.elements), frontIdx(otherqueue.frontIdx), rearIdx(otherqueue.rearIdx)
{
    items = new data_type[capacity];
    for (int i = 0; i < capacity; i++)
        items[i] = otherqueue.items[i];
}

template <typename data_type>
CircularQueue<data_type>::~CircularQueue()
{
    delete[] items;
}

template <typename data_type>
bool CircularQueue<data_type>::IsEmpty() const
{
    return elements == 0;
}

template <typename data_type>
bool CircularQueue<data_type>::IsFull() const
{
    return elements == capacity;
}

template <typename data_type>
void CircularQueue<data_type>::Enqueue(data_type item)
{
    if (IsFull())
        return void(cout << "Queue is Full!\n");
    if (IsEmpty())
        frontIdx = 0;

    rearIdx = (rearIdx + 1) % capacity;
    items[rearIdx] = item;
    elements++;
}

template <typename data_type>
void CircularQueue<data_type>::MakeEmpty()
{
    frontIdx = -1;
    rearIdx = -1;
    elements = 0;
}

template <typename data_type>
void CircularQueue<data_type>::Dequeue()
{
    if (IsEmpty())
        return void(cout << "Queue is Empty!\n");
    if (frontIdx == rearIdx)
        frontIdx = rearIdx = -1;
    else
        frontIdx = (frontIdx + 1) % capacity;
    elements--;
}

template <typename data_type>
void CircularQueue<data_type>::display() const
{
    if (IsEmpty())
        return void(cout << "Queue is Empty!\n");
    int count = 0, i = frontIdx;
    while (count < elements)
    {
        cout << items[i] << " ";
        i = (i + 1) % capacity;
        count++;
    }
    cout << "\n";
}

template <typename data_type>
int CircularQueue<data_type>::getSize() const
{
    return elements;
}

template <typename data_type>
data_type CircularQueue<data_type>::getFront() const
{
    return items[frontIdx];
}

template <typename data_type>
data_type CircularQueue<data_type>::getBack() const
{
    return items[rearIdx];
}
