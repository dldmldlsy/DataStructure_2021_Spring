#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* next;
    friend class Stack;
};

class Stack
{
private:
    Node *top;
public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int isEmpty();
    int stackTop();
};

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    Node *p = top;
    while (top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == nullptr)
    {
        cerr << "스택 오버 플로우" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    Node *p;
    int x = -1;
    if (top == nullptr)
    {
        cerr << "스택 언더 플로우" << endl;
    }
    else
    {
        p = top;
        x = top->data;
        top = top->next;
        delete p;
    }
    return x;
}
 
int Stack::isEmpty()
{
    if (top == nullptr)
    {
        cout << "1" << endl;
        return 1;
    }
    cout << "0" << endl;
    return 0;
}

int Stack::stackTop()
{
   if (top == nullptr)
   {
       cout << "-1" << endl;
       return -1;
   }
    cout << top->data << endl;
    return (top->data);
}

void interface(Stack* st, int cases)
{
    string m;
    int value;
    while (cases > 0)
    {
        cin >> m;
        if (m == "empty")
            st->isEmpty();
        else if (m == "top")
            st->stackTop();
        else if (m == "push")
        {
            cin >> value;
            st->push(value);
        }
        else if (m == "pop")
            st->pop();
        cin.ignore(256, '\n');
        cases--;
    }
}


int main()
{
    int cases = 0;
    cin >> cases;
    Stack stk;

    interface(&stk, cases);

    return 0;
}

