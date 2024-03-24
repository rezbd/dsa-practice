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

void remove_duplicates(Node* head)
{
    Node* tmp = head;
    while(tmp->next != NULL)
    {
        if(tmp->val == tmp->next->val)
        {
            Node* delNode = tmp->next;
            tmp->next = delNode->next;
            delete delNode;
        }
        else
        {
          tmp = tmp->next;
        }
    }
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
    print_linked_list(head);
    remove_duplicates(head);
    cout<<"after duplicates are removed:"<<endl;
    print_linked_list(head);
    return 0;
}