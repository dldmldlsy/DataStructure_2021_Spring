
#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;
    
    friend class D_LinkedList;
};

class D_LinkedList
{
public:
    D_LinkedList();
    int List_size();
    bool isEmpty();
    void Print();
    void Append(int elem);
    int Delete(int idx);
    void Print_reverse();
    void Sum();

private:
    Node *head;
    Node *tail;
};

bool D_LinkedList::isEmpty()
{
    return (head == NULL && tail == NULL);
}

int D_LinkedList::List_size()
{
    int list_size = 0;
    if (isEmpty())
        return list_size;
    else
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        {
            list_size++;
            cur_node = cur_node->next;
        }
        list_size++;
        return list_size;
    }
}

D_LinkedList::D_LinkedList()
{
    head = new Node;
    tail = new Node;
    
    head = NULL;
    tail = NULL;
}

void  D_LinkedList::Print()
{
    if (isEmpty())
        cout << "empty" << endl;
    else
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        {
            cout << cur_node->data << ' ';
            cur_node = cur_node->next;
        }
        cout << cur_node->data << endl;
    }
}

int D_LinkedList::Delete(int idx)
{
    int temp = -1;
    int middle = List_size() / 2;
    int size = List_size();
    Node* cur;
    Node* pre;

    if (isEmpty() || List_size() <= idx)
    {
        cout << -1 << endl;
        return -1;
    }
    else if (idx == 0)
    {
        if (List_size() == 1)
        {
            cur = head;
            temp = cur->data;
            head = NULL;
            delete cur;
        }
        else
        {
            cur = head;
            temp = cur->data;
            head = head->next;
            delete cur;
        }
        size--;
    }
    else if (idx <= middle)
    {
        pre = cur = head;
        for (int i = 0; i < idx; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp = cur->data;
        pre->next = cur->next;
        if (cur == tail)
        {
            tail = pre;
        }
        else
        {
            (cur->next)->prev = pre;
        }
        delete cur;
        size--;
    }

    else if (idx > middle)
    {
        pre = cur = tail;
        for (int i = size; i > idx; i--)
        {
            cur = pre;
            pre = pre->prev;
        }
        temp = cur->data;
        pre->next = cur->next;
        if (cur == tail)
        {
            tail = pre;
        }
        else {
            (cur->next)->prev = pre;
        }
        delete cur;
        size--;
    }
    cout << temp << endl;
    return temp;
}

void  D_LinkedList::Print_reverse()
{
    if (isEmpty())
        cout << "empty" << endl;
    else
    {
        Node *cur_node = tail;
        while (cur_node->prev != NULL)
        {
            cout << cur_node->data << ' ';
            cur_node = cur_node->prev;
        }
        cout << cur_node->data << endl;
    }
}

void D_LinkedList::Append(int elem)
{
    Node *new_node = new Node;
    new_node->data = elem;
    new_node->next = NULL;
    new_node->prev = tail;
    
    if (isEmpty())
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = tail->next;
    }
    this->Print();
}

void D_LinkedList::Sum()
{
    int result = 0;
    
    if (!isEmpty())
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        {
            result += cur_node->data;
            cur_node = cur_node->next;
        }
        result += cur_node->data;
    }
    cout << result << endl;
}

int operation_interface(D_LinkedList *_list)
{
    string command;
    int value = -1;
    int idx = -1;
    
    cin >> command;

    if (command == "Print")
        _list->Print();
    else if (command == "Print_reverse")
        _list->Print_reverse();
    else if (command == "Sum")
        _list->Sum();
    else if (command == "Delete")
    {
        cin >> idx;
        _list->Delete(idx);
    }
    else if (command == "Append")
    {
        cin >> value;
        _list->Append(value);
    }
    return 1;
}

int main(int argc, const char * argv[])
{
    
    int cases;
    cin >> cases;
    D_LinkedList list;
    while (cases > 0)
    {
        operation_interface(&list);
        cases--;
    }

    return 0;
}
