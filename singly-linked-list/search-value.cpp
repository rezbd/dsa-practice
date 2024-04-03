#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        long long int val;
        Node* next;
        Node(long long int val)
        {
            this->val=val;
            this->next=NULL;
        }
};

void insert_at_tail(Node* &head, Node* &tail, long long int val)
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

void search_value(Node* head, long long int v)
{
    long long int ind=0;
    
    Node* tmp = head;
    while(tmp != NULL)
    {
        if(tmp->val == v) break;
        ind++;
        tmp=tmp->next;

        if(tmp == NULL)
        {
            cout<< -1 <<endl;
            return;
        }
    }
    
    cout<<ind<<endl;
}


int main()
{
    long long int x;
    cin>>x;
    while(x--)
    {
        long long int val;
        Node* head = NULL;
        Node* tail = NULL;

        while(true)
        {
            cin>>val;
            if(val == -1) break;
            insert_at_tail(head, tail, val);
        }
        long long int v;
        cin>>v;

        search_value(head, v);
    }

    return 0;
}