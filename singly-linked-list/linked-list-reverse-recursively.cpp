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

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

void print_recursive(Node* n)
{
    if(n == NULL) return;
    cout<<n->val<<" ";
    print_recursive(n->next);
}

void print_recursive_reverse(Node *n)
{
    if(n == NULL) return;
    print_recursive_reverse(n->next);
    cout<<n->val<<" ";
}

int main()
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

    // print_recursive(head);
    print_recursive_reverse(head);

    return 0;
}