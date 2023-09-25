#include <bits/stdc++.h>
using namespace std;

class Node
{
 public: 
    int key;
    Node* next;

    Node(int key)
    {
        this->key = key;
        this->next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void pushFornt(int key)
{
    Node* newNode = new Node(key);

    newNode->next = head;
    head = newNode;
}

//Time Complexity O(n)
// void pushBack(Node* head, int key)
// {
//     Node* newNode = new Node(key);

//     Node* cur = head;

//     while(cur->next != NULL)
//     {
//         cur = cur->next;
//     }

//     cur->next= newNode;


// }


//Complexity O(1)
void pushBack(Node* tail, int key)
{
    Node* newNode = new Node(key);

    tail->next = newNode;
    tail = newNode;
}


//O(1)
void popFront()
{
    Node* temp = head;

    if(head != NULL)
    {
        head = head->next;
        delete temp;
    }

}

// void popBack()
// {
//     Node* cur = head;

//     while(cur->next->next != NULL)
//     {
//         cur = cur->next;
//     }

//     Node* temp = cur->next();

//     cur->next = NULL;
//     delete temp;

// }


Node* findEven(Node* head) {
    Node* evenHead = nullptr; // Head of the new list containing even nodes
    Node* evenTail = nullptr; // Tail of the new list containing even nodes
    
    Node* current = head; // Pointer to traverse the original list
    
    while (current != nullptr) {
        if (current->key % 2 == 0) { // Check if the current node's key is even
            if (evenHead == nullptr) {
                evenHead = new Node(current->key);
                evenTail = evenHead;
            } else {
                evenTail->next = new Node(current->key);
                evenTail = evenTail->next;
            }
        }
        current = current->next;
    }
    
    return evenHead;
}




void printLinlkedList()
{
    Node* cur = head;

    while(cur != NULL)
    {
        cout<< cur->key << " ";
        cur= cur->next;
    }

    cout<<endl;
}

int main()
{

    head = new Node(1); 
    Node* a = new Node(2);
    Node* b = new Node(3);
    Node* c = new Node(4);
    Node* tail = new Node(5);

    head->next = a;
    a-> next = b; 
    b->next = c;
    c->next = tail;

    printLinlkedList();
    pushFornt(6);
    printLinlkedList();
    // pushBack(head, 6);
    // printLinlkedList();

    pushBack(tail, 6);
    printLinlkedList();

    popFront();
    printLinlkedList();

    Node * cur = findEven(head);
    while(cur != NULL)
    {
        cout<< cur->key << " ";
        cur= cur->next;
    }



    

    return 0;
}




#include <iostream> 
using namespace std;
int main ()
{

int num [5];
int* p;
p = num;
*p = 10;
* (p++) = 20.;
*p =30;
p = &num [2];
* (p++) = ++ (* (p-1) ) ;
* (p++) = * (p-2) + * (p-3) ;
*р = 50;
for (int i = 0; i < 5; i++)
cout << num[i] << ",";
return 0;
}