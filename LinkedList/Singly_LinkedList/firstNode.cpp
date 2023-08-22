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
    firstNode->key =15;
    firstNode->next = NULL;

    return firstNode;
}

void pushFront(int key, Node* head)
{
    struct Node* newNode = createNode(key);
    newNode->next = head;
    head = newNode;
}

void pushBack(int key, Node* head)
{
    struct Node* newNode = createNode(key);
    struct Node* curr = head;

    while(curr.next != NULL)
    {
        curr = curr->next;

    }
    curr->next = newNode;
}
int main()
{
    struct Node* head;


    cout<<head->key<<endl;
    cout<<head->next<<endl;

    return 0;

}