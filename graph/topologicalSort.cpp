#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void topoSortDFS(int src,vector<vector<int>>& adj,map<int,bool>& visited,vector<int>& ans){
        visited[src]=true;
        for(auto i:adj[src]){
            if(!visited[i]){
                topoSortDFS(i,adj,visited,ans);
            }
        }
        ans.push_back(src);
    }

    vector<int> topologicalSort(vector<vector<int>>& adj) {
       map<int,bool>visited;
       vector<int>ans;
       for(int i=0;i<adj.size();i++){
           if(!visited[i]){
               topoSortDFS(i,adj,visited,ans);
           }
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }


    void topoSortBFS(vector<vector<int>>& adj,vector<int>& ans){
        unordered_map<int,int>indegree;
        for(int i=0;i<adj.size();i++){
            for(auto nbr:adj[i]){
                indegree[nbr]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto nbr:adj[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
    }
};

int main(){


    return 0;
}