#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *head = new Node();
Node *tail = new Node();

void traverse(Node *ptr);
void traverseExtended(Node *ptr);
int search(Node *ptr, int t);
void append(Node *ptr, int t);

int main()
{
    Node n1;
    n1.val = 1;
    head = &n1;
    n1.prev = head;

    append(head, 2);
    append(head, 3);
    append(head, 4);
    traverse(head);
    cout << search(head, 22);
    return 0;
}

void traverse(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

void traverseExtended(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->val << " " << ptr->prev << " " << ptr << " " << ptr->next << endl;
        ptr = ptr->next;
    }
    cout << "\n";
}

void append(Node *ptr, int t)
{
    Node *temp;
    temp = new Node();
    temp->val = t;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void insert(Node *ptr, int t)
{
}

int search(Node *ptr, int t)
{
    int cnt = 0;
    while (ptr->next != NULL)
    {
        if (t == ptr->val)
        {
            return cnt;
        }
        ++cnt;
        ptr = ptr->next;
    }
    return -1;
}