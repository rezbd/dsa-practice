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
            this->next = next;
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

void insert_at_head(Node* &head, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
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
    Node* newHead = NULL;
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, tail, val);
        insert_at_head(newHead, val);
    }
    // print_linked_list(head);
    // cout<<"reversed list:"<<endl;
    // print_linked_list(newHead);
    while(head != NULL)
    {
        if(head->val != newHead->val)
        {
            cout<<"Not palindrome"<<endl;
            return 0;
        }
        head = head->next;
        newHead = newHead->next;
    }
    cout<<"palindrome"<<endl;
    return 0;
}
