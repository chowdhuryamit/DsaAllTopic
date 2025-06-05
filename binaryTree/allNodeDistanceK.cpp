#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void mapping(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m){
        if(root==NULL){
            return;
        }
        if(root->left){
            m[root->left]=root;
            mapping(root->left,m);
        }
        if(root->right){
            m[root->right]=root;
            mapping(root->right,m);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>m;
        m[root]=NULL;
        mapping(root,m);
        queue<TreeNode*>q;
        q.push(target);
        int level=0;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        while(!q.empty()){
            if(level==k){
                break;
            }
            level++;
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && visited.find(node->left)==visited.end()){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(m[node] && visited.find(m[node])==visited.end()){
                    q.push(m[node]);
                    visited[m[node]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};