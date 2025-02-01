#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     unordered_map<int,list<int>>adjList;

    void addEdge(int u,int v,bool direction){
        if(direction){
          adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    } 

    void printGraph(int n){
        for(int i=0;i<n;i++){
            cout<<i<<"->{";
            for(auto j:adjList[i]){
                cout<<j<<" ";
            }
            cout<<"}";
            cout<<endl;
        }
    }
    
    void topoSort(int src,unordered_map<int,bool>& vis,stack<int>& topoOrder){
        vis[src]=true;
        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                topoSort(nbr,vis,topoOrder);
            }
        }
        topoOrder.push(src);
    }

    void dfs(int src,unordered_map<int,list<int>>& adjNew,unordered_map<int,bool>& visited){
        visited[src]=true;
        cout<<src<<"->";
        for(auto nbr:adjNew[src]){
            if(!visited[nbr]){
                dfs(nbr,adjNew,visited);
            }
        }
    }

    int findSCC(int n){
        stack<int>topoOrder;
        unordered_map<int,bool>vis;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                topoSort(i,vis,topoOrder);
            }
        }

        unordered_map<int,list<int>>adjNew;
        for(auto i:adjList){
            for(auto j:i.second){
                adjNew[j].push_back(i.first);
            }
        }

        unordered_map<int,bool>visited;
        int count=0;
        while (!topoOrder.empty())
        {
            int node=topoOrder.top();
            topoOrder.pop();
            if(!visited[node]){
                dfs(node,adjNew,visited);
                cout<<endl;
                count++;
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     if(!visited[i]){
        //          dfs(i,adjNew,visited);
        //          cout<<endl;
        //          count++;
        //      }
        // }
        
        return count;
    }

};
int main(){

    Graph g;
    g.addEdge(0,3,1);
    g.addEdge(3,2,1);
    g.addEdge(2,1,1);
    g.addEdge(1,0,1);
    g.addEdge(2,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    g.addEdge(6,4,1);

    //g.printGraph(8);

    int count=g.findSCC(7);
    cout<<"strongly connected component: "<<count<<endl;


    return 0;
}