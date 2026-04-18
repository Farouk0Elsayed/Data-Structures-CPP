#pragma once
using namespace std;

template <typename data_type>
class StackAdt
{
private:
    data_type *stack;
    int top, size;

public:
    void initializeStack();
    void clear();
    void push(const data_type &item);
    void pop();
    void print();

    int getSize() const;

    data_type get_top() const;

    bool isEmpty() const;
    bool isFull() const;

    string infix_to_postfix(string s);
    string infix_to_prefix(string s);

    const StackAdt<data_type> &operator=(const StackAdt<data_type> &otherstack);

    StackAdt(int stackSize = 100);
    StackAdt(const StackAdt<data_type> &otherstack);
    ~StackAdt();
};

/*
    StackAdt();
    StackAdt(int stackSize);
    StackAdt(const StackAdt<data_type> &otherstack);
    ~StackAdt();
*/

template <typename data_type>
StackAdt<data_type>::StackAdt(int stackSize) : size(stackSize > 0 ? stackSize : 100), top(-1)
{
    stack = new data_type[size];
}

template <typename data_type>
StackAdt<data_type>::StackAdt(const StackAdt<data_type> &otherstack) : size(otherstack.size), top(otherstack.top)
{
    stack = new data_type[size];
    for (int i = 0; i <= top; i++)
    {
        stack[i] = otherstack.stack[i];
    }
}

template <typename data_type>
StackAdt<data_type>::~StackAdt()
{
    delete[] stack;
}

/*
    bool isEmpty() const;
    bool isFull() const;
*/

template <typename data_type>
bool StackAdt<data_type>::isEmpty() const
{
    return (top == -1);
}

template <typename data_type>
bool StackAdt<data_type>::isFull() const
{
    return (top == size - 1);
}

/*
    int getSize() const;
    data_type get_top() const;
*/

template <typename data_type>
int StackAdt<data_type>::getSize() const
{
    return top + 1;
}

template <typename data_type>
data_type StackAdt<data_type>::get_top() const
{
    if (!isEmpty())
        return stack[top];
    else
    {
        cout << "Stack is Empty!\n";
        return data_type{};
    }
}

/*
    void initializeStack();
    void clear();
    void push(const data_type &item);
    void pop();
*/

template <typename data_type>
void StackAdt<data_type>::initializeStack()
{
    top = -1;
}

template <typename data_type>
void StackAdt<data_type>::clear()
{
    top = -1;
}

template <typename data_type>
void StackAdt<data_type>::push(const data_type &item)
{
    if (isFull())
        return void(cout << "Stack Is Full\n");
    stack[++top] = item;
}

template <typename data_type>
void StackAdt<data_type>::pop()
{
    if (!isEmpty())
        top--;
    else
        return void (cout << "Stack is Empty!\n");
}

template <typename data_type>
void StackAdt<data_type>::print()
{
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

// const StackAdt<data_type> &operator=(const StackAdt<data_type> &otherstack);
template <typename data_type>
const StackAdt<data_type> &StackAdt<data_type>::operator=(const StackAdt<data_type> &otherstack)
{
    if (this != &otherstack)
    {
        StackAdt<data_type> temp(otherstack);
        swap(this->stack, temp.stack);
        swap(this->size, temp.size);
        swap(this->top, temp.top);
    }
    return *this;
}

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

template <typename data_type>
string StackAdt<data_type>::infix_to_postfix(string s)
{

    StackAdt<char> st(s.length());
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (isalpha(c))
            res += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (!st.isEmpty() && st.get_top() != '(')
            {
                res += st.get_top();
                st.pop();
            }
            st.pop(); // pop '('
        }
        else
        {
            while (!st.isEmpty() && precedence(c) <= precedence(st.get_top()))
            {
                res += st.get_top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty())
    {
        res += st.get_top();
        st.pop();
    }
    return res;
}

template <typename data_type>
string StackAdt<data_type>::infix_to_prefix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }
    StackAdt<char> st(s.length());
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (std::isalnum(static_cast<unsigned char>(c)))
            res += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (!st.isEmpty() && st.get_top() != '(')
            {
                res += st.get_top(), st.pop();
            }
            st.pop(); // pop '('
        }
        else
        {
            while (!st.isEmpty() && precedence(c) < precedence(st.get_top()))
            {
                res += st.get_top(), st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty())
        res += st.get_top(), st.pop();

    reverse(res.begin(), res.end());
    return res;
}
