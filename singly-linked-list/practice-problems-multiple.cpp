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

int count_list(Node* head)
{
    int cnt = 0;
    while(head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void find_max(Node* head)
{
    int max = INT_MIN;
    while(head != NULL)
    {
        if(head->val > max) max = head->val;
        head = head->next;
    }
    cout<<max<<endl;
}

void mid_node(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    int count = count_list(head);
    if(count%2 == 0) cout<<slow->val<<" "<<slow->next->val<<endl;
    else cout<<slow->val<<endl;
}

void sort_descending_with_selection_sort(Node *head)
{
    for(Node* i=head; i->next!=NULL; i=i->next)
    {
        for(Node* j=i->next; j!=NULL; j=j->next)
        {
            if(i->val < j->val) swap(i->val, j->val);
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
        // insert_at_head(head);
    }

    // print_linked_list(head);
    // mid_node(head);
    // find_max(head);
    sort_descending_with_selection_sort(head);
    print_linked_list(head);

    return 0;
}