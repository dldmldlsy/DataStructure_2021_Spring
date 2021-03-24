#include <iostream>
#include <string>
using namespace std;

class Node
{
    int elem;
    Node* next;
    
    friend class S_LinkedList;
};

class S_LinkedList
{
public:
    S_LinkedList();
    int List_size();
    bool Empty();
    void Print();
    void Append(int elem);
    int Delete(int idx);
    void Insert(int idx, int elem);
    void Min();
    
private:
    Node* head;
    Node* tail;
};

bool S_LinkedList::Empty()
{
    return (head == NULL && tail == NULL);
}

int S_LinkedList::List_size()
{
    int list_size = 0;
    if (Empty())
        return list_size;
    else
    {
        Node *cur_node = head;
        while(cur_node->next != NULL)
        {
            list_size++;
            cur_node = cur_node->next;
        }
        list_size++;
        return list_size;
    }
}

S_LinkedList::S_LinkedList()
{
    head = new Node;
    tail = new Node;
    
    head = NULL;
    tail = NULL;
}

void S_LinkedList::Print()
{
    if(Empty())
        cout << "empty" << endl;
    else
    {
        Node *cur_node = head;
        while (cur_node->next != NULL)
        {
            cout << cur_node->elem << ' ';
            cur_node = cur_node->next;
        }
        cout << cur_node->elem << endl;
    }
}

void S_LinkedList::Append(int elem)
{
    Node *new_node = new Node;
    new_node->elem = elem;
    new_node->next = NULL;
    
    if(Empty())
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

int S_LinkedList::Delete(int idx)
{
    int removeNum = 0;
    int cnt = 0;
    Node *cur_node;
    Node *pre_node;
    
    if (Empty() || List_size() <= idx)
    {
        cout << -1 << endl;
        return -1;
    }
    else if (idx == 0)
    {
        if (List_size() == 1)
        {
            removeNum = head->elem;
            tail = NULL;
            head = NULL;
        }
        else
        {
            cur_node = head;
            removeNum = cur_node->elem;
            head = cur_node->next;
        }
    }
    else
    {
        pre_node = cur_node = head;
        while (cnt != idx)
        {
            pre_node = cur_node;
            cur_node = cur_node->next;
            cnt++;
        }
        removeNum = cur_node->elem;
        pre_node->next = cur_node->next;
        
        if (cur_node == tail)
            tail = pre_node;
    }
    cout << removeNum << endl;
    return removeNum;
}

void    S_LinkedList::Insert(int idx, int elem)
{
    Node *new_node = new Node;
    new_node->elem = elem;
    
    Node *pre_node;
    Node *cur_node;
    int cur_idx = 0;
    
    if (idx == 0)
    {
        if (Empty())
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
    }
    else if (idx > List_size())
    {
        cout << "Index Error" << endl;
        return;
    }
    else
    {
        pre_node = cur_node = head;
        while (cur_idx != idx)
        {
            pre_node = cur_node;
            cur_node =cur_node->next;
            cur_idx++;
        }
        pre_node->next = new_node;
        new_node->next = cur_node;
    }
    this->Print();
}

void S_LinkedList::Min()
{
    int min = 2147483647;
    
    if (Empty())
    {
        cout << "empty" << endl;
        return;
    }
    else
    {
        for(Node* cur_node = head; cur_node != NULL; cur_node = cur_node->next)
        {
            if (cur_node->elem < min)
            {
                min = cur_node->elem;
            }
         }
    }
    cout << min << endl;
}

int operation_interface(S_LinkedList *_list)
{
    string command;
    int value = -1;
    int idx = -1;
    
    cin >> command;

    if (command == "Print")
        _list->Print();
    else if (command == "Min")
        _list->Min();
    else if (command == "Delete")
    {
        cin >> idx;
        _list->Delete(idx);
    }
    else if (command == "Insert")
    {
        cin >> idx;
        cin >> value;
        _list->Insert(idx, value);
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
    S_LinkedList list;
    while (cases > 0)
    {
        operation_interface(&list);
        cases--;
    }

    return 0;
}







