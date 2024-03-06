#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;
    
    Node(int val)
    {
        this->val=val;
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
    Node *tmp=head;
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
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int get_list_length(Node *head)
{
    int cnt=0;
    while(head != NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}

int main()
{
    int val;
    Node *head=NULL;
    while(true)
    {
        cin>>val;
        if(val == -1) break;
        insert_at_tail(head, val);
    }

    print_linked_list(head);

    int q;
    cin>>q;
    cout<<q<<endl;
    while(q--)
    {
        int lnt = get_list_length(head);
        int ind, v;
        cin>>ind>>v;
        if(ind>lnt)
        {
            cout<<"Invalid"<<endl;
            continue;
        }
        cout<<ind<<" "<<v<<endl;
    }

    return 0;
}