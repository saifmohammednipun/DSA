#include <bits/stdc++.h>
using namespace std;

class Node
{
    public: 
        int key;
        Node* next;

    //Default Constructor
    Node()
    {
        this->key = 0;
        this->next = NULL;
    }

    //Parameterized Constructor
    Node(int key)
    {
        this->key = key;
        this->next = NULL;
    }
    
    ~Node(){}; //Destructor

};

Node* head = NULL;


void pushFornt(int key)
{
    Node* newNode = new Node(key);
    newNode->next = head;
    head = newNode;
}

void pushBack(int key)
{
    Node* newNode = new Node(key);
    Node* cur = head;
    
    while(cur->next != NULL)
    {
        cur = cur->next;
    }

    cur->next = newNode;
}

void popFront()
{
    Node* temp = head;
    
    if(head != NULL)
    {
        head = head->next;
        delete temp;
    } else cout << "List is empty. Nothing to delete" << endl;
}

void printLinkedList()
{
    Node* cur = head;

    while(cur != NULL)
    {
       cout << cur->key << " ";
       cur = cur->next;
    }
    cout<<endl;
}

int main()
{
    head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);

    head->next = a;
    a->next = b;
    b->next = c;

    printLinkedList();
    
    pushFornt(5); //Insert Node at berfor Head
    pushBack(45); //Insert Node at after Tail
    
    
    printLinkedList();

    popFront(); //Remove Head Node

    printLinkedList();
}