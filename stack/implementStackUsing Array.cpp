#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int capacity;
    int top;
    Stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }
    void push(int x)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int size()
    {
        return top + 1;
    }
};

int main()
{
    Stack st(5);
    st.push(97);
    st.push(53);
    cout<<st.peek();
    st.pop();
    st.pop();
    st.pop();

    return 0;
}