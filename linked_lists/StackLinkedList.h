#pragma once
using namespace std;

template <class data_type>
struct Node
{
    data_type data{};
    Node *next = nullptr;
};

template <class data_type>
class StackTypeLinked
{
private:
    Node<data_type> *topPtr;

public:
    StackTypeLinked();
    StackTypeLinked(const StackTypeLinked<data_type> &other);
    StackTypeLinked<data_type> &operator=(const StackTypeLinked<data_type> &other);
    ~StackTypeLinked();

    bool operator==(const StackTypeLinked<data_type> &otherStack) const;
    bool IsEmpty() const;
    data_type top() const;

    void MakeEmpty();
    void push(const data_type &);
    void pop();
    void reverse();
    void reverseStack(StackTypeLinked<data_type> &otherStack);
    void print();
    void MergeStack(const StackTypeLinked<data_type> &other_stack);
};

template <class data_type>
StackTypeLinked<data_type>::StackTypeLinked()
{
    topPtr = nullptr;
}

template <class data_type>
StackTypeLinked<data_type>::StackTypeLinked(const StackTypeLinked<data_type> &other)
{
    topPtr = nullptr;
    if (other.topPtr == nullptr)
        return;

    Node<data_type> *curr = other.topPtr;
    StackTypeLinked<data_type> tempStack;
    while (curr != nullptr)
    {
        tempStack.push(curr->data);
        curr = curr->next;
    }
    while (!tempStack.IsEmpty())
    {
        this->push(tempStack.top());
        tempStack.pop();
    }
}

template <class data_type>
StackTypeLinked<data_type> &StackTypeLinked<data_type>::operator=(const StackTypeLinked<data_type> &other)
{
    if (this != &other)
    {
        MakeEmpty();
        if (other.topPtr != nullptr)
        {
            Node<data_type> *curr = other.topPtr;
            StackTypeLinked<data_type> tempStack;
            while (curr != nullptr)
            {
                tempStack.push(curr->data);
                curr = curr->next;
            }
            while (!tempStack.IsEmpty())
            {
                this->push(tempStack.top());
                tempStack.pop();
            }
        }
    }
    return *this;
}

template <class data_type>
bool StackTypeLinked<data_type>::operator==(const StackTypeLinked<data_type> &otherStack) const
{
    Node<data_type> *curr = this->topPtr, *other = otherStack.topPtr;
    while (curr != nullptr && other != nullptr)
    {
        if (curr->data != other->data)
            return false;
        curr = curr->next;
        other = other->next;
    }
    return (curr == nullptr && other == nullptr);
}

template <class data_type>
void StackTypeLinked<data_type>::MakeEmpty()
{
    Node<data_type> *tempPtr = nullptr;
    while (topPtr != nullptr)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    topPtr = nullptr;
}

template <class data_type>
StackTypeLinked<data_type>::~StackTypeLinked()
{
    MakeEmpty();
}

template <class data_type>
bool StackTypeLinked<data_type>::IsEmpty() const
{
    return (topPtr == nullptr);
}

template <class data_type>
void StackTypeLinked<data_type>::push(const data_type &newItem)
{
    Node<data_type> *location = new Node<data_type>;
    location->data = newItem;
    location->next = topPtr;
    topPtr = location;
}

template <class data_type>
void StackTypeLinked<data_type>::pop()
{
    if (IsEmpty())
        return;
    Node<data_type> *tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
}

template <class data_type>
data_type StackTypeLinked<data_type>::top() const
{
    if (IsEmpty())
        throw runtime_error("Stack is empty!");
    return topPtr->data;
}

template <class data_type>
void StackTypeLinked<data_type>::reverse()
{
    if (IsEmpty())
        return;
    Node<data_type> *prev = nullptr, *curr = topPtr, *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    topPtr = prev;
}

template <class data_type>
void StackTypeLinked<data_type>::reverseStack(StackTypeLinked<data_type> &otherStack)
{
    if (IsEmpty())
        return void(cout << "main stack is Empty\n");

    otherStack.MakeEmpty();
    Node<data_type> *curr = topPtr;
    while (curr != nullptr)
    {
        otherStack.push(curr->data);
        curr = curr->next;
    }
}

template <class data_type>
void StackTypeLinked<data_type>::MergeStack(const StackTypeLinked<data_type> &other_stack)
{
    if (other_stack.IsEmpty())
        return;

    Node<data_type> *curr = other_stack.topPtr;
    StackTypeLinked<data_type> tempStack;

    while (curr != nullptr)
    {
        tempStack.push(curr->data);
        curr = curr->next;
    }

    while (!tempStack.IsEmpty())
    {
        this->push(tempStack.top());
        tempStack.pop();
    }
}

template <class data_type>
void StackTypeLinked<data_type>::print()
{
    Node<data_type> *temp = topPtr;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
