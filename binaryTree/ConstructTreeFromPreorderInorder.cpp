#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int getIndex(vector<int>& inorder,int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int &preorderIndex,int inorderStart,int inorderEnd,int size,unordered_map<int,int>&m){
       if(preorderIndex>=size){
        return NULL;
       }
       if(inorderStart>inorderEnd){
        return NULL;
       }
       TreeNode* root=new TreeNode(preorder[preorderIndex]);
       //int currEleIndex=getIndex(inorder,preorder[preorderIndex]);
       int currEleIndex=m[preorder[preorderIndex]];
       preorderIndex++;
       root->left=solve(preorder,inorder,preorderIndex,inorderStart,currEleIndex-1,size,m);
       root->right=solve(preorder,inorder,preorderIndex,currEleIndex+1,inorderEnd,size,m);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex=0;
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        int size=preorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=solve(preorder,inorder,preorderIndex,inorderStart,inorderEnd,size,m);
        return root;
    }
};