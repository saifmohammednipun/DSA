#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node* leftchild;
    Node* rightchild;
};

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->leftchild = NULL;
    node->rightchild = NULL;
    return node;
}
int search (int arr[], int start, int end, int key)
{
    int i;
    for(i = start; i <= end; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

Node* buildTree(int inOrder[], int preOrder[], int inStart, int inEnd)
{
    static int preIndex = 0;
    if(inStart > inEnd)
        return NULL;
    
    Node* tNode = newNode(preOrder[preIndex++]);

    if(inStart == inEnd)
        return tNode;
    
    int inIndex = search(inOrder, inStart, inEnd, tNode->key);

    tNode->leftchild = buildTree(inOrder, preOrder, inStart, inIndex-1);
    tNode->rightchild = buildTree(inOrder, preOrder, inIndex+1, inEnd);

    return tNode;
}

void postOrder(Node* node)
{
    if(node == NULL)
        return;
    
    postOrder(node->leftchild);
    postOrder(node->rightchild);
    cout << node->key << " ";
}

int main()
{
    int inOrder[] = {4, 2, 5, 1, 3, 6};
    int preOrder[] = {1, 2, 4, 5, 3, 6};
    int len = sizeof(inOrder)/sizeof(inOrder[0]);
    Node* root = buildTree(inOrder, preOrder, 0, len-1);
    cout << "PostOrder Traversal of the constructed tree is: ";
    postOrder(root);
    cout << endl;
    return 0;
}