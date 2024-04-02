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

void difference_min_max(Node* head)
{
    int min = INT_MAX;
    int max = INT_MIN;
    int diff;
    
    Node* tmp = head;
    if(tmp->next == NULL)
    {
      cout<<0<<endl;
      return;
    }

    while(tmp != NULL)
    {
        if(tmp->val < min) min = tmp->val;
        if(tmp->val > max) max = tmp->val;
        tmp = tmp->next;
    }
    diff = max-min;
    cout<<diff<<endl;
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

    difference_min_max(head);
    return 0;
}