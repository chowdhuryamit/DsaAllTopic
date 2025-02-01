#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     unordered_map<int,list<int>>adjList;

    void addEdge(int u,int v,bool isDirected){
      if(isDirected){
        adjList[u].push_back(v);
      }
      else{
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }
    } 

    void shortestPathBfs(int src,int dest){
       unordered_map<int,bool>visited;
       queue<int>q;
       unordered_map<int,int>parent;
       q.push(src);
       visited[src]=true;
       parent[src]=-1;

       while (!q.empty())
       {
         int node=q.front();
         q.pop();
         for(auto nbr:adjList[node]){
            if(!visited[nbr]){
                visited[nbr]=true;
                q.push(nbr);
                parent[nbr]=node;
            }
         }
       }

       vector<int>ans;
       int node=dest;
       while(node!=-1){
        ans.push_back(node);
        node=parent[node];
       }

       reverse(ans.begin(),ans.end());

       for(auto i:ans){
        cout<<i<<"->";
       }
       cout<<endl;
       
    }



};
int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,4,0);
    g.addEdge(2,5,0);
    g.addEdge(2,3,0);
    g.addEdge(4,6,0);
    g.addEdge(5,6,0);
    g.addEdge(3,6,0);
    g.addEdge(3,7,0);

    int src=0,dest=7;
    g.shortestPathBfs(src,dest);



    return 0;
}