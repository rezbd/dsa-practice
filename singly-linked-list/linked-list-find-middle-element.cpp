#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;

    Node (int val)
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
    Node *tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void print_linked_list(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int count_node(Node *head)
{
    int cnt=0;
    while(head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void middle_node(Node *head)
{
    int cnt = count_node(head);
    int midCnt=cnt/2;
    if(cnt%2 != 0)
    {
        for(int i=1; i<=midCnt; i++)
        {
            head=head->next;
        }
        cout<<head->val<<endl;
    }
    else
    {
      for(int i=1; i<=midCnt-1; i++)
      {
          head=head->next;
      }
      cout<<head->val<<" "<<head->next->val<<endl;
    }
}

int main()
{
    int val;
    Node *head = NULL;
    while(true)
    {
        cin>>val;
        if(val==-1) break;
        insert_at_tail(head, val);
    }
    // print_linked_list(head);
    middle_node(head);
    return 0;
}