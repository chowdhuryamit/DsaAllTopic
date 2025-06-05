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
    int count=0;
    int solve(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int l=solve(root->left);
        int r=solve(root->right);
       if(l==0 || r==0){
        count++;
        return 2;
       }
       if(l==2 || r==2){
        return 1;
       }
        return 0;
       
    }
    int minCameraCover(TreeNode* root) {
        int ans= solve(root);
        if(ans==0){
            count++;
        }
        return count;
    }
};