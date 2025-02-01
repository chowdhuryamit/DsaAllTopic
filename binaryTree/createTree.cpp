#include <bits/stdc++.h>
using namespace std;
class root
{
public:
    int data;
    root *left;
    root *right;
    root(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

root* createNode()
{
    cout << "enter value" << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    else
    {
        root *node = new root(data);
        cout << "enter the value left node of node" << node->data << endl;
        node->left = createNode();
        cout << "enter the value right node of node" << node->data << endl;
        node->right = createNode();
        return node;
    }
}

void preOrderTraversal(root *node)
{
    if (node == NULL)
    {
        return;
    }
    // NLR
    cout << node->data << " ";
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void inOrderTraversal(root *node)
{
    if (node == NULL)
    {
        return;
    }
    // LNR
    inOrderTraversal(node->left);
    cout << node->data << " ";
    inOrderTraversal(node->right);
}

void postOrderTraversal(root *node)
{
    if (node == NULL)
    {
        return;
    }
    // LRN
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->data << " ";
}

void levelOrderTraversal(root *node)
{
    if (node == NULL)
    {
        return;
    }
    queue<root *> q;
    q.push(node);
    q.push(NULL);
    while (!q.empty())
    {
        root* front = q.front();
        q.pop();
        if (front==NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            
        }
        else
        {
            cout << front->data;
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{
    root *node = createNode();
    // preOrderTraversal(node);
    // cout<<endl;
    // inOrderTraversal(node);
    // cout<<endl;
    // postOrderTraversal(node);
    // cout<<endl;
    levelOrderTraversal(node);
    return 0;
}