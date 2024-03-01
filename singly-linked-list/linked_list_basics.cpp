#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;

    Node (int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, int v)
{
    Node *newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;

}

void insert_at_position(Node *&head, int pos, int v)
{
    if(pos==0)
    {
        cout<<"invalid position"<<endl;
        return;
    }
    Node *newNode = new Node(v);
    Node *tmp = head;
    for(int i=1; i<=pos-1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void delete_head(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    Node *tmp = head;
    head = tmp->next;
    delete tmp;
}

void delete_at_position(Node *&head, int pos)
{
    if(pos==0)
    {
        cout<<"invalid position"<<endl;
        return;
    }
    
    Node *tmp = head;
    for(int i=1; i<=pos-1; i++)
    {
        tmp = tmp->next;
    }

    Node *delNode = tmp->next;
    tmp->next = tmp->next->next;
    delete delNode;
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next; 
    }
    cout<<endl;
}

int main()
{
    int val;
    Node *head = NULL; // dynamic varaible gives 0 at the tail
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, val);
    }
    
    // delete_head(head);
    
    // insert_at_position(head, 2, 25);

    print_linked_list(head);

    return 0;
}