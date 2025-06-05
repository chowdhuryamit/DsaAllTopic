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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth=0;
        if(root==NULL){
            return maxWidth;
        }
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            unsigned long long qsize=q.size();
            unsigned long long leftIndex=q.front().second;
            unsigned long long rightIndex=q.back().second;
            maxWidth=max(maxWidth,(rightIndex-leftIndex+1));
            for(unsigned long long i=0;i<qsize;i++){
                auto front=q.front();
                q.pop();
                auto node=front.first;
                auto index=front.second;
                if(node->left){
                    q.push(make_pair(node->left,index*2));
                }
                if(node->right){
                    q.push(make_pair(node->right,2*index+1));
                }
            }
        }
      return maxWidth;
    }
};