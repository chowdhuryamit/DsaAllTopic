#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
     map<int,list<pair<int,int>>>adjList;

    void addEdge(int u,int v,int weight){
        adjList[u].push_back({v,weight});
        adjList[v].push_back({u,weight});
    }

    bool cycleDetection(int src,map<int,bool>& visited){
        queue<int>q;
        map<int,int>parent;
        visited[src]=true;
        parent[src]=-1;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nbr:adjList[node]){
                if(!visited[nbr.first]){
                    visited[nbr.first]=true;
                    q.push(nbr.first);
                    parent[nbr.first]=node;
                }
                else if(visited[nbr.first] && nbr.first!=parent[node]){
                    return true;
                }
            }
        }
        return false;
    }

    bool cycleDetectionDfs(int src,map<int,bool>& visited,int parent){
      visited[src]=true;
      for(auto nbr:adjList[src]){
        if(!visited[nbr.first]){
            bool ans=cycleDetectionDfs(nbr.first,visited,src);
            if(ans==true){
                return ans;
            }
        }
        else if(visited[nbr.first]==true && nbr.first!=parent){
          return true;
        }
      }
      return false;
    }



};
int main(){

    Graph g;
    g.addEdge(0,1,2);
    g.addEdge(1,2,2);
    g.addEdge(2,0,2);
    g.addEdge(2,3,2);

    // bool ans=false;
    // map<int,bool>visited;
    // for(int i=0;i<4;i++){
    //    if(!visited[i]){
    //     ans=g.cycleDetection(i,visited);
    //     if(ans==true){
    //         break;
    //     }
    //   }
    // }
    // if(ans){
    //     cout<<"cycle detected"<<endl;
    // }
    // else{
    //     cout<<"no cycle detected"<<endl;
    // }

    bool ans=false;
    map<int,bool>visited;
    for(int i=0;i<4;i++){
       if(!visited[i]){
        ans=g.cycleDetectionDfs(i,visited,-1);
        if(ans==true){
            break;
        }
      }
    }
    if(ans){
        cout<<"cycle detected"<<endl;
    }
    else{
        cout<<"no cycle detected"<<endl;
    }

}