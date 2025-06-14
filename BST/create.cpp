#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
     int data;
     Node* left;
     Node* right;
    Node(int val){
        this->data=val;
        left=NULL;
        right=NULL;
    } 
};

Node* buildBST(int val,Node* root){
    if(root==NULL){
        root=new Node(val);
        return root;
    }
    else{
       if(val<root->data){
          root->left=buildBST(val,root->left);
       }
       else{
        root->right=buildBST(val,root->right);
       }
    }
    return root;
}

void createTree(Node* &root){
    cout<<"enter the value of node"<<endl;
    int val;
    cin>>val;
    while (val!=-1)
    {
        buildBST(val,root);
        cout<<"enter the value of node"<<endl;
        cin>>val;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int qSize=q.size();
        for (int i = 0; i < qSize; i++)
        {
            Node* temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        cout<<endl;
    }
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
}

void InOrder(Node* root){
    if(root==NULL){
        return;
    }
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

void getMin(Node* root,int &mini){
    if(root==NULL){
        return;
    }
    if(root->left!=NULL){
        mini=root->data;
        getMin(root->left,mini);
    }
}

void getMax(Node* root,int &maxi){
    if(root==NULL){
        return;
    }
    if(root->right!=NULL){
        maxi=root->data;
        getMax(root->right,maxi);
    }
}

bool searchInBST(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    else{
        if(target<root->data){
            return searchInBST(root->left,target);
        }
        else{
            return searchInBST(root->right,target);
        }
    }
}
int main(){
     Node* root=NULL;
     createTree(root);

      levelOrderTraversal(root);
    //  cout<<endl;
    //  preOrder(root);
    //  cout<<endl;
    //  postOrder(root);
    //  cout<<endl;
    //  InOrder(root);

    // int mini=root->data;
    // int maxi=root->data;
    // getMin(root,mini);
    // cout<<mini<<endl;
    // getMax(root,maxi);
    // cout<<maxi<<endl;
    //cout<<searchInBST(root,77)<<endl;
    return 0;
}