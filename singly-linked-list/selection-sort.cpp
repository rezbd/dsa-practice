#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};

void insert_at_tail(Node* &head, Node* &tail, int v)
{
    Node* newNode = new Node(v);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_linked_list(Node* head)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    // in progress
    int val;
    Node* head = NULL;
    Node* tail = NULL;
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, tail, val);
    }
    for(Node* i=head; i->next != NULL; i=i->next)
    {
        for(Node* j=i->next; j != NULL; j=j->next)
        {
            if(i->val > j->val) swap(i->val, j->val);
        }
    }

    print_linked_list(head);
}