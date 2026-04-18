#pragma once
using namespace std;

template <typename data_type>
class QueueAdt {
private:
    data_type *items;
    int frontIdx, rearIdx, capacity, elements;

public:
    QueueAdt(int size = 100);
    QueueAdt(const QueueAdt<data_type> &otherqueue);
    ~QueueAdt();

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
QueueAdt<data_type>::QueueAdt(int size)
    : frontIdx(-1), rearIdx(-1), capacity(size), elements(0)
{
    items = new data_type[capacity];
}

template <typename data_type>
QueueAdt<data_type>::QueueAdt(const QueueAdt<data_type> &otherqueue)
{
    capacity = otherqueue.capacity;
    elements = otherqueue.elements;
    frontIdx = otherqueue.frontIdx;
    rearIdx = otherqueue.rearIdx;

    items = new data_type[capacity];
    for (int i = 0; i < capacity; i++)
        items[i] = otherqueue.items[i];
}

template <typename data_type>
QueueAdt<data_type>::~QueueAdt()
{
    delete[] items;
}

template <typename data_type>
bool QueueAdt<data_type>::IsEmpty() const
{
    return elements == 0;
}

template <typename data_type>
bool QueueAdt<data_type>::IsFull() const
{
    return elements == capacity;
}

template <typename data_type>
void QueueAdt<data_type>::Enqueue(data_type item)
{
    if (IsFull())
        return void(cout << "Queue Is Full!\n");
    if (IsEmpty())
        frontIdx = 0;

    rearIdx++;
    items[rearIdx] = item;
    elements++;
}

template <typename data_type>
void QueueAdt<data_type>::Dequeue()
{
    if (IsEmpty())
        return void(cout << "Queue is Empty!\n");
    if (frontIdx == rearIdx)
        frontIdx = rearIdx = -1;
    else
        frontIdx++;
    elements--;
}

template <typename data_type>
void QueueAdt<data_type>::display() const
{
    for (int i = frontIdx; i <= rearIdx; i++)
        cout << items[i] << " ";
    
}

template <typename data_type>
int QueueAdt<data_type>::getSize() const
{
    return elements;
}

template <typename data_type>
data_type QueueAdt<data_type>::getFront() const
{
    return items[frontIdx];
}

template <typename data_type>
data_type QueueAdt<data_type>::getBack() const
{
    return items[rearIdx];
}
