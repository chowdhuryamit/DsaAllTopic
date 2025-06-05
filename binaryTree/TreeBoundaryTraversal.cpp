#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
public:
    void leftKaAns(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        ans.push_back(root->data);
        if(root->left!=NULL){
            leftKaAns(root->left,ans);
        }
        else{
            leftKaAns(root->right,ans);
        }
    }
    void rightKaAns(Node* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            return;
        }
        if(root->right!=NULL){
            rightKaAns(root->right,ans);
        }
        else{
            rightKaAns(root->left,ans);
        }
        ans.push_back(root->data);
    }
    void leafNodes(Node* root,vector<int>& ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    vector <int> boundaryTraversal(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        leftKaAns(root->left,ans);
        
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
        rightKaAns(root->right,ans);
        return ans;
    }
};