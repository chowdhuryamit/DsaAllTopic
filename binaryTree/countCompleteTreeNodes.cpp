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
    int leftHeight(TreeNode* root){
        int count=0;
        while(root!=NULL){
            count++;
            root=root->left;
        }
        return count;
    }
    int rightHeight(TreeNode* root){
        int count=0;
        while(root!=NULL){
            count++;
            root=root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh){
            return pow(2,lh)-1;
        }
        else{
            int l=countNodes(root->left);
            int r=countNodes(root->right);
            return l+r+1;
        }
    }
};