#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node(int val)
        {
            this->val=val;
            this->next=NULL;
        }
};

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_list(Node* head, int v)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<v<<endl;
    cout<<endl;
}

void search_value(Node* head, int v)
{
    int ind=0;
    
    Node* tmp = head;
    while(tmp != NULL)
    {
        if(tmp->val == v) break;
        ind++;
        tmp=tmp->next;
    }
    cout<<"index: "<<ind<<endl;
    if(tmp->next == NULL)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<ind<<endl;
}


int main()
{
    int x;
    cin>>x;
    while(x--)
    {
        int val;
        Node* head = NULL;
        Node* tail = NULL;

        while(true)
        {
            cin>>val;
            if(val == -1) break;
            insert_at_tail(head, tail, val);
        }
        int v;
        cin>>v;

        search_value(head, v);
        // print_list(head, v);
    }

    return 0;
}

// IN PROGRESS