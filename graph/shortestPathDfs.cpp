#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     unordered_map<int,list<pair<int,int>>>adjList;

    void addEdge(int u,int v,int wt){
        adjList[u].push_back({v,wt});
    } 

    void topoSort(int src,stack<int>& topoSortOrder,unordered_map<int,int>& visited){
        visited[src]=1;
        for(auto nbr:adjList[src]){
           if(!visited[nbr.first]){
             topoSort(nbr.first,topoSortOrder,visited);
           }
        }
        topoSortOrder.push(src);
    }

    void sortestPath(int src){
        stack<int>topoSortOrder;
        unordered_map<int,int>visited;
        unordered_map<int,int>parent;
        topoSort(src,topoSortOrder,visited);

        vector<int>dist(topoSortOrder.size(),INT_MAX);
        dist[src]=0;
        parent[src]=-1;

        while (!topoSortOrder.empty())
        {
            int topNode=topoSortOrder.top();
            topoSortOrder.pop();
            for(auto nbr:adjList[topNode]){
                if(dist[topNode]+nbr.second<dist[nbr.first]){
                    dist[nbr.first]=dist[topNode]+nbr.second;
                    parent[nbr.first]=topNode;
                }
            }
        }

        for (int i = 0; i < dist.size(); i++)
        {
            cout<<dist[i]<<endl;
        }
        cout<<endl;

        int dest=3;
        while(dest!=-1){
            cout<<dest<<" ";
            dest=parent[dest];
        }

        
        
        
    }

};
int main(){

    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,4,3);
    g.addEdge(0,2,13);
    g.addEdge(1,2,7);
    g.addEdge(1,4,1);
    g.addEdge(4,3,6);
    g.addEdge(3,2,2);

    g.sortestPath(0);


    return 0;
}