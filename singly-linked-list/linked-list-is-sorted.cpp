#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
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
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void print_linked_list(Node *head)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
    }
    cout<<endl;
}

void is_sorted_ascending(Node *head)
{
    while(head->next != NULL)
    {
        int preVal = head->val;
        int nextVal = head->next->val;
        if(preVal > nextVal)
        {
            cout<<"NO"<<endl;
            return;
        }
        head = head->next;
    }
    cout<<"YES"<<endl;
}

int main()
{
    int val;
    Node *head = NULL;
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, val);
    }
    // print_linked_list(head);
    is_sorted_ascending(head);

    return 0;
}