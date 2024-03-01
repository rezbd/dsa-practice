#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp->next != NULL)
    {
        tmp=tmp->next;
    }
    tmp->next = newNode;
}

void print_linked_list(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void check_duplicate(Node *head)
{
    int count=0;
    while(head->next != NULL)
    {
        Node *subPtr = head->next;
        while(subPtr != NULL)
        {
            if(head->data == subPtr->data)
            {
                count++;
                break;
            }
            subPtr = subPtr->next;
        }
        head = head->next;
    }
    if(!count) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    int data;
    Node *head = NULL;
    while(true)
    {
        cin>>data;
        if(data == -1) break;
        insert_at_tail(head, data);
    }
    // print_linked_list(head);
    check_duplicate(head);

    return 0;
}