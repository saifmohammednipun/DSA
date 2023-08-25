#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node* next;
};

struct Node* createNode(int key)
{
    struct Node* firstNode = (struct Node*) malloc(sizeof(struct Node));
    firstNode->key = key;
    firstNode->next = NULL;

    return firstNode;
}

struct Node* head = NULL;


void pushFornt(int key)
{
    struct Node* newNode = createNode(key);
    newNode->next = head;
    head = newNode;
}

void pushBack(int key)
{
    struct Node* newNode = createNode(key);
    struct Node* cur = head;
    
    while(cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = newNode;
}

void popFront()
{
    struct Node* temp = head;
    
    if(head != NULL)
    {
        head = head->next;
        delete temp;
    }   
    else cout << "List is empty. Nothing to delete" << endl;
}

void print()
{
    struct Node* cur = head;

    while(cur != NULL)
    {
        cout<< cur->key << " ";
        cur = cur->next;
    }
    cout<<endl;
}

int main()
{
    head = createNode(10);
    Node* a = createNode(20);
    Node* b = createNode(30);
    Node* c = createNode(40);
    head->next = a;
    a->next = b;
    b->next = c;
    print();

    pushFornt(5); //Insert Node before Head
    pushBack(45); //Insert Node after Tail
    
    print();

    popFront(); // Remove Head Node

    print();

    return 0;

}