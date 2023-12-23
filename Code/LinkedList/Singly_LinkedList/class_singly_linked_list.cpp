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

void popBack()
{
    Node* cur = head;
    
    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }

    Node* temp = cur->next;
    cur->next = NULL;
    
    delete temp;
}

bool find(int v)
{
    Node* cur = head;

    while(cur != NULL)
    {
        if(cur->key == v)
        {
            return true;
        }
      cur = cur->next;
    }

    return false;
}

void addBefore(int key, int v)
{
     Node* cur = head;
     Node* newNode = new Node(key);

    // corner cases
    //if (head == NULL) {
    //     // If the list is empty, simply make the newNode the new head
    //     head = newNode;
    //     return;
    // }
    
    // if (head->key == v) {
    //     // If the key 'v' is in the head node, update head and link newNode
    //     newNode->next = head;
    //     head = newNode;
    //     return;
    // } 

    while (cur->next != NULL)
    {
        if (cur->next->key == v)
        {
            newNode->next = cur->next;
            cur->next = newNode;
            return; // Inserted the new node, so exit the loop
        }
        cur = cur->next;
    }

}


void addAfter(int key, int v)
{
     Node* cur = head;
     Node* newNode = new Node(key);

   while(cur != NULL)
    {
        if(cur->key == v)
        {
            newNode->next = cur->next;
            cur->next = newNode;
            return;
        }
      cur = cur->next;
    }
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
    printLinkedList();

    pushBack(45); //Insert Node at after Tail
    printLinkedList();

    popFront(); //Remove Head Node
    printLinkedList();

    popBack(); //Remove Tail Node
    printLinkedList();

    bool f = find(50);
    cout << f << endl;

    // addBefore(60,30);
    // printLinkedList();

   addAfter(60,30);
   printLinkedList();

}