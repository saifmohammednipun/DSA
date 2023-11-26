int leafNode(Node* root)
{
    if(root == NULL)
    return;

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        return root->key;
    }

    printLeafNodes(root->rightChild);
    printLeafNodes(root->leftChild);


}