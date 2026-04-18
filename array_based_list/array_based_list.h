#pragma once

#include <iostream>
using namespace std;

template <typename data_type>
class arrayListType
{
private:
    data_type *arr;
    int max_size, length;

public:
    bool isfull(), isempty(), isItemAtEqual(int loc, data_type item);

    int listLength(), maxSize(), search(data_type item);

    data_type atpos(int pos), elementback(), elementfront(), retrieve_at(int pos),

        min_element() const, max_element() const;

    void pushback(data_type item), popback(), insertat(int pos, data_type item),
        print(), clearlist(), replaceAt(int loc, data_type item), insertNoDuplicate(data_type item), removeat(int pos), removeAll(data_type item);

    arrayListType(int size = 100);
    arrayListType(const arrayListType &otherlist);
    ~arrayListType();
};

template <typename data_type>
arrayListType<data_type>::arrayListType(int size)
{
    while (size <= 0)
    {
        cout << "negative value or zero not allowed in size!\n";
        cout << "enter size of array: ";
        cin >> size;
    }
    max_size = size;
    length = 0;
    arr = new data_type[max_size];
}

template <typename data_type>
arrayListType<data_type>::arrayListType(const arrayListType &otherlist)
{
    max_size = otherlist.max_size;
    length = otherlist.length;
    arr = new data_type[max_size];
    for (int i = 0; i < length; i++)
        arr[i] = otherlist.arr[i];
}

template <typename data_type>
arrayListType<data_type>::~arrayListType()
{
    delete[] arr;
}

template <typename data_type>
bool arrayListType<data_type>::isfull()
{
    return length == max_size;
}

template <typename data_type>
bool arrayListType<data_type>::isempty()
{
    return length == 0;
}

template <typename data_type>
bool arrayListType<data_type>::isItemAtEqual(int loc, data_type item)
{
    if (loc < 0 || loc >= length)
    {
        cout << "location is out of range!\n";
        return false;
    }
    return (arr[loc] == item);
}

template <typename data_type>
int arrayListType<data_type>::maxSize()
{
    return max_size;
}

template <typename data_type>
int arrayListType<data_type>::listLength()
{
    return length;
}

template <typename data_type>
int arrayListType<data_type>::search(data_type item)
{
    for (int i = 0; i < length; i++)
        if (arr[i] == item) return i;
    return -1;
}

template <typename data_type>
data_type arrayListType<data_type>::elementback()
{
    if (isempty())
    {
        cout << "List is empty!\n";
        return data_type();
    }
    return arr[length - 1];
}

template <typename data_type>
data_type arrayListType<data_type>::elementfront()
{
    if (isempty())
    {
        cout << "List is empty!\n";
        return data_type();
    }
    return arr[0];
}

template <typename data_type>
data_type arrayListType<data_type>::atpos(int pos)
{
    if (pos < 0 || pos >= length)
    {
        cout << "position is out of range!\n";
        return data_type();
    }
    else
    {
        return arr[pos];
    }
}

template <typename data_type>
data_type arrayListType<data_type>::retrieve_at(int pos)
{
    if (pos < 0 || pos >= length)
    {
        cout << "position is out of range!\n";
        return data_type();
    }
    return arr[pos];
}

template <typename data_type>
void arrayListType<data_type>::pushback(data_type item)
{
    if (!isfull())
        arr[length++] = item;
    else
        return void(cout << "List is full!\n");
}

template <typename data_type>
void arrayListType<data_type>::popback()
{
    if (!isempty())
        length--;
    else
        return void(cout << "List is empty!\n");
}

template <typename data_type>
void arrayListType<data_type>::insertat(int pos, data_type item)
{
    if (isfull())
        return void(cout << "list is full!\n");
    else if (pos < 0 || pos > length)
        return void(cout << "out of range!\n");
    else
    {
        for (int i = length; i > pos; i--) arr[i] = arr[i - 1];

        arr[pos] = item;
        length++;
    }
}

template <typename data_type>
void arrayListType<data_type>::print()
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename data_type>
void arrayListType<data_type>::clearlist()
{
    length = 0;
}

template <typename data_type>
void arrayListType<data_type>::replaceAt(int loc, data_type item)
{
    if (loc < 0 || loc >= length)
        return void(cout << "location is invalid!\n");
    arr[loc] = item;
}

template <typename data_type>
void arrayListType<data_type>::insertNoDuplicate(data_type item)
{
    if (isfull())
        return void(cout << "array is full\n");
    int pos = search(item);
    if (pos == -1)
        pushback(item);
    else
    {
        cout << "Item already exists!\n";
    }
}

template <typename data_type>
data_type arrayListType<data_type>::min_element() const
{
    if (length == 0)
    {
        cout << "List is empty!\n";
        return data_type();
    }
    data_type mini = arr[0];
    for (int i = 1; i < length; i++)
        if (arr[i] < mini) mini = arr[i];
    return mini;
}

template <typename data_type>
data_type arrayListType<data_type>::max_element() const
{
    if (length == 0)
    {
        cout << "List is empty!\n";
        return data_type();
    }
    data_type maxi = arr[0];
    for (int i = 1; i < length; i++)
        if (arr[i] > maxi) maxi = arr[i];
    return maxi;
}

template <typename data_type>
void arrayListType<data_type>::removeat(int pos)
{
    if (pos < 0 || pos >= length)
        return void(cout << "out of range!\n");

    arr[pos] = arr[length--];
}

template <typename data_type>
void arrayListType<data_type>::removeAll(data_type item)
{
    int loc = 0;
    while (loc < length)
    {
        if (arr[loc] == item)
        {
            for (int i = loc; i < length - 1; i++) arr[i] = arr[i + 1];
            length--;
        }
        else
            loc++;
    }
}
