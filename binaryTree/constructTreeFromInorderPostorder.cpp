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
    TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int &postIndex,int inorderStart,int inorderEnd,unordered_map<int,int>&m){
        if(postIndex<0){
            return NULL;
        }
        if(inorderStart>inorderEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postIndex]);
        int currEleIndex=m[postorder[postIndex]];
        postIndex--;
        root->right=solve(inorder,postorder,postIndex,currEleIndex+1,inorderEnd,m);
        root->left=solve(inorder,postorder,postIndex,inorderStart,currEleIndex-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex=postorder.size()-1;
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        TreeNode* root=solve(inorder,postorder,postIndex,inorderStart,inorderEnd,m);
        return root;
    }
};