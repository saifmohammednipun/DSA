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

void popBack()
{
    struct Node* cur = head;
    
    while(cur->next->next != NULL)
    {
        cur = cur->next;
    }

    struct Node* temp = cur->next;
    cur->next = NULL;
    
    delete temp;
}

//returning boolean value
bool find(int v)
{
    struct Node* cur = head;

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
    struct Node* cur = head;
    struct Node* newNode = createNode(key);

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
    struct Node* cur = head;
    struct Node* newNode = createNode(key);

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
    printLinkedList();

    pushFornt(5); //Insert Node before Head
    printLinkedList();

    pushBack(45); //Insert Node after Tail
    printLinkedList();

    popFront(); // Remove Head Node
    printLinkedList();

    popBack(); // Remove Tail Node 
    printLinkedList();

   bool f = find(0); //Finding an element in the linkedlist
   cout << f <<endl; 

   addBefore(60,30);
   printLinkedList();

//    addAfter(60,30);
//    printLinkedList();

}