#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        queue<pair<Node*,int>>q;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        unordered_map<int,Node*>m;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int>frontPair=q.front();
            q.pop();
            int dist=frontPair.second;
            Node* node=frontPair.first;
            mini=min(mini,dist);
            maxi=max(maxi,dist);
            
            if(m.find(dist)==m.end()){
                m[dist]=node;
            }
            if(node->left!=NULL){
                q.push(make_pair(node->left,dist-1));
            }
            if(node->right!=NULL){
                q.push(make_pair(node->right,dist+1));
            }
        }
        for(int i=mini;i<=maxi;i++){
            Node* temp=m[i];
            ans.push_back(temp->data);
        }
        return ans;
    }

};
