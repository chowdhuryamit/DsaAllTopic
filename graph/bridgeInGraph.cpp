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

    void findBridge(int src,int parent,int timer,vector<int>& tin,vector<int>& low,unordered_map<int,bool>& visited){
        timer++;
        visited[src]=true;
        tin[src]=timer;
        low[src]=timer;

        for(auto nbr:adjList[src]){
          if(nbr==parent){
            continue;
          }
          else if(!visited[nbr]){
            findBridge(nbr,src,timer,tin,low,visited);
            low[src]=min(low[src],low[nbr]);
            if(low[nbr]>tin[src]){
                cout<<"bridge found: ";
                cout<<src<<"-"<<nbr<<endl;
            }
          }
          else{
            low[src]=min(low[src],tin[nbr]);
          }
        }
    }
    
};
int main(){

    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(0,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);

    g.printGraph(5);

    int timer=0;
    unordered_map<int,bool>visited;
    vector<int>tin(5);
    vector<int>low(5);
    int src=0;
    int parent=-1;

    g.findBridge(src,parent,timer,tin,low,visited);



    return 0;
}