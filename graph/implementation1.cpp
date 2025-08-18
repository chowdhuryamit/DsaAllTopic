#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     unordered_map<int,list<pair<int,int>>>adjList;

    void addEdge(int u,int v,int weight,bool isDirected){
        if(isDirected==0){
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }
        else{
            adjList[u].push_back({v,weight});
        }
    }

    void printAdiList(int n){
        for (int i = 0; i < n; i++)
        {
           cout<<i<<"->";
           list<pair<int,int>>l=adjList[i];
           for(auto j:l){
            cout<<"("<<j.first<<","<<j.second<<"),";
           }
           cout<<endl;
        }
        
    }


    void bfsTraversal(int src){
        queue<int>q;
        map<int,bool>visited;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(auto i:adjList[node]){
                if(!visited[i.first]){
                    q.push(i.first);
                    visited[i.first]=true;
                }
            }
        }
        cout<<endl;
    }

    void dfsHelper(int src,map<int,bool>& visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto i:adjList[src]){
            if(!visited[i.first]){
                dfsHelper(i.first,visited);
            }
        }
    }

    void dfsTraversal(int n){
        map<int,bool>visited;
        //int src=0;
        for(int i=0;i<n;i++){//this loop take care of disconnected components
            if(!visited[i]){
              dfsHelper(i,visited);
            }
        }
    }
};
int main(){
   Graph g;
//    g.addEdge(0,1,1,1);
//    g.addEdge(0,2,4,1);
//    g.addEdge(1,2,5,1);
//    g.addEdge(2,3,11,1);
//    g.addEdge(3,1,6,1);
//    g.addEdge(3,4,2,1);

//    g.printAdiList(5);
    g.addEdge(0,2,2,1);
    g.addEdge(0,6,7,1);
    g.addEdge(0,4,1,1);
    g.addEdge(4,2,1,1);
    g.addEdge(2,1,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(1,5,6,1);
    g.addEdge(3,5,4,1);

   //g.bfsTraversal(0);
   g.dfsTraversal(7);

}