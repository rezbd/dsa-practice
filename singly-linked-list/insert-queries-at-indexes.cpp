#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;
    
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int v)
{
    Node *newNode = new Node(v);
    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_linked_list(Node *head)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int get_length(Node *head)
{
    int cnt=0;
    while(head != NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insert_at_position(Node *&head, int v, int p)
{
    Node *newNode = new Node(v);
    Node *tmp = head;
    for(int i=1; i<=p-1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

int main()
{
    int val;
    Node *head = NULL;
    Node *tail = NULL;
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, tail, val);
    }

    int q;
    cin>>q;
    cout<<q<<endl;
    while(q--)
    {
        int ind, v;
        cin>>ind>>v;
        if(ind > get_length(head))
        {
            cout<<"Invalid"<<endl;
            continue;
        }
        if(ind==0)
        {
            insert_at_head(head, v);
        }
        else if(ind == get_length(head))
        {
            insert_at_tail(head, tail, v);
        }
        else
        {
            insert_at_position(head, v, ind);
        }
        
        print_linked_list(head);
    }

    return 0;
}