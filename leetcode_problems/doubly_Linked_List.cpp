#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *lPtr = new Node();
Node *rPtr = new Node();

void traverse(Node *ptr);
void traverseExtended(Node *ptr);
Node *search(Node *ptr, int t);
void append(Node *ptr, int t);
void insert(Node *ptr, int t, int x);

int main()
{
    Node n1;
    n1.val = 1;
    lPtr = &n1;
    n1.prev = lPtr;

    append(lPtr, 2);
    append(lPtr, 3);
    append(lPtr, 4);
    traverse(lPtr);
    search(lPtr, 2);
    insert(lPtr, 3, 5);
    traverse(lPtr);
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

void insert(Node *ptr, int t, int x)
{
    ptr = search(ptr, t);
    Node *temp = new Node();
    temp->next = ptr->next;
    ptr->next = temp;
    temp->prev = ptr;
    temp->val = x;
}

Node *search(Node *ptr, int t)
{
    while (ptr->next != NULL)
    {
        if (t == ptr->val)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}