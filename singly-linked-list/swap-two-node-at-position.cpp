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
    int val;
    Node* head = NULL;
    Node* tail = NULL;
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, tail, val);
    }
    int k;
    cin>>k;
    Node* first = head;
    for(int i=1; i<=k-1; i++)
    {
        first=first->next;
    }
    
    Node* slow = head;
    Node* fast = first;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    swap(first->val, slow->val);

    print_linked_list(head);

    return 0;
}