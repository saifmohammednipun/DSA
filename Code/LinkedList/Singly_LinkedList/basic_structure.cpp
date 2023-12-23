#include <bits/stdc++.h>
using namespace std;

//self-referencing strcture
struct Point
{
    int x;
    int y;
    struct Point* next;

};

struct Point* createNode(int p, int q)
{
    struct Point* node = (struct Point*) malloc(sizeof(struct Point));
    node->x = p;
    node->y = q;
    node->next = NULL;
    
    return node;

}
int main()
{
    struct Point* node1 = createNode(10,20);
    struct Point* node2 = createNode(100,200);

    cout<<"Node1 Values: "<<endl;
    cout<< node1->x <<endl;
    cout<< node1->y <<endl;
    cout<< node1 <<endl;

    cout<<"Node2 Values: "<<endl;
    cout<< node2->x <<endl;
    cout<< node2->y <<endl;
    cout<< node2 <<endl;

    node1->next = node1;

    cout<< "Node1 Next: " <<endl;
    cout<< node1->next <<endl;
    cout<< node2->next <<endl;

    return 0;
}